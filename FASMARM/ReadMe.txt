
FASMARM v1.43

This package is an ARM assembler add-on for FASM.

FASMARM currently supports the full range of instructions for 32-bit and 64-bit
ARM processors and coprocessors up to and including v8.

Contents:

	 1. ARM assembly compatibility
	 2. UAL and pre-UAL syntaxes
	 3. IT block handling
	 4. Alternate encodings
	 5. Output formats
	 6. Control directives
	 7. Data definitions
	 8. Defining registers lists inside macros
	 9. Half-precision number formatting
	10. Variants supported
	11. Further information
	12. Version history

_______________________________________________________________________________
			1. ARM assembly compatibility

There are a few restrictions how the ARM instruction set is implemented. The
changes are minor and mostly have a minor impact. For the most part the basic
instruction outline is the same. Where possible the original style is used but
there are some differences:

Not everything matches the ARM ADS assembly style, where possible the original
style is used but there are some differences
1) label names cannot begin with a digit
2) CPSIE and CPSID formats are changed, use "iflags_aif" form instead of "aif"
   (eg. "CPSIE iflags_i" instead of "CPSID i")
3) SRS with writeback must have a separating space after the mode number and
   before "!" (eg. "SRSDB 16 !" instead of "SRSDB 16!")
4) macro, rept, irp, format, if, virtual etc. are all significant changes from
   the ARM ADS, so you will need to re-write those sections of existing code

	Original ARM Syntax   | fasmarm Syntax
	----------------------+----------------------
	cpsie a		      | cpsie iflags_a
			      |
	srsdb #29!	      | srsdb #29 !	 ;or,
			      | srsdb 29 !

_______________________________________________________________________________
			2. UAL and pre-UAL syntaxes

fasmarm supports the original pre-UAL syntax and the newer UAL syntax. These
two syntaxes only affect THUMB encodings.

UAL stands for: Universal Assembly Language.

pre-UAL syntax is selected with the directive CODE16.
UAL syntax is selected with the directive THUMB.

pre-UAL syntax does not specify the "s" (flag update) in the opcodes for
arithmetic operations involving the low set of registers (r0-r7). For example:

	pre-UAL Syntax	| UAL Syntax  ;Note
	----------------+------------------------------------------------------
	add r0,r1	| adds r0,r1  ;"s" was implicit with all registers <=r7
	adds r0,r1	| adds r0,r1
	<no opcode>	| add r0,r1   ;only available inside an IT block, or
			|	      ;as 32-bit T2 instruction
	add r8,r1	| add r8,r1   ;high register used, does not update PSR
	adds r8,r1	| adds r8,r1  ;only available as 32-bit T2 instruction
			|
	mov r0,r1	| movs r0,r1  ;"s" was implicit with all registers <=r7
	mov r8,r1	| mov r8,r1   ;high register used, does not update PSR
	movs r0,r1	| movs r0,r1
	movs r8,r1	| movs r8,r1  ;only available as 32-bit T2 instruction
			|
	cpy r0,r1	| cpy r0,r1   ;also: mov r0,r1 in UAL

Code written in UAL syntax can generally be assembled without modification in
both ARM and THUMB modes. It is recommended to use UAL syntax for all new code.
UAL syntax is get-what-you-write, whereas pre-UAL syntax has an implicit "s"
flag which can potentially be unclear about what you will get. This is
especially important in macros and structures where register numbers may be
unknown until instantiated.

Both syntaxes support triple and double register operands: "add r0,r0,r1" can
be shortened to "add r0,r1"

_______________________________________________________________________________
			3. IT block handling

In THUMB mode fasmarm can insert IT blocks automatically:

	thumb		;use UAL syntax
	;itet	eq	;fasmarm inserts an automatic "IT EQ" block
	subeq	r0,r1	;T(rue) = eq
	subsne	r2,r3	;E(lse) = ne
	subseq	r4,r5	;T(rue) = eq


fasmarm will check that manually placed IT blocks are consistent with
subsequent code:

	thumb		;use UAL syntax
	itet	eq	;manually placed IT block
	subeq	r0,r1	;T(rue) = eq, fasmarm checks the conditions are matched
	subsne	r2,r3	;E(lse) = ne, fasmarm checks the conditions are matched
	subseq	r4,r5	;T(rue) = eq, fasmarm checks the conditions are matched


IT blocks cannot span across labels:

	thumb		;use UAL syntax
	;it	eq	;fasmarm inserts an automatic "IT EQ" block
	subeq	r0,r1	;T(rue) = eq
lab1:	;ite	ne	;fasmarm inserts a new "IT NE" block
	subsne	r2,r3	;T(rue) = ne
	subseq	r4,r5	;E(lse) = eq


fasmarm will check that manually placed IT blocks do not span labels:

	ite	mi	;manually placed IT block
	submi	r0,r1	;T(rue) = mi, fasmarm checks the conditions are matched
lab2:	subspl	r2,r3	;Error: IT block would span across the label


IT blocks cannot span across changes to PC:

	thumb		;use UAL syntax
	;ite	eq	;fasmarm inserts an automatic "IT EQ" block
	subeq	r0,r1	;T(rue) = eq
	bne	lab2	;E(lse) = ne, branch will finish the IT block
	;it	eq	;fasmarm inserts a new "IT EQ" block
	subseq	r4,r5	;T(rue) = eq

_______________________________________________________________________________
			4. Alternate encodings

fasmarm follows this principle: Find a way to encode it, the smaller the better

What this means is that even though you may write a particular opcocde, fasmarm
may assemble another as a replacement. This can only happen where the
functionality is exactly the same. The reason for doing this is to increase the
likelihood of a successful assembly. This will only affect you if you want to
look at a disassembly listing and match it to the original source. Example:

	What you coded	   | What is assembled	;reason
	-------------------+---------------------------------------------------
			  ARM
	and r0,0xfffffff0  | bic r0,0x0000000f	;immediate could not be encoded
	add r1,-4	   | sub r1,4		;immediate could not be encoded
	cmp r2,0xffffe500  | cmn r2,0x00001b00	;immediate could not be encoded
	lsr r1,r2,r3	   | mov r1,r2,lsr r3	;ARM mode does not have LSR
	pop {r0-r3}	   | ldmfd r13!,{r0-r3} ;ARM mode does not have POP
	mul r4,r4,r11	   | mul r4,r11,r4	;encoding restriction for
			   |			;CPU versions before v6
			 THUMB
	ldmfd r13!,{r0-r3} | pop {r0-r3}	;THUMB mode uses pop
	ldmfd r10!,{r8}	   | ldr r8,[r10],4	;forbidden single register LDMs
	pop {r8}	   | ldr r8,[r13],4	;forbidden single register POP
	add r2,0x89a	   | addw r2,0x89a	;immediate could not be encoded
			 BOTH
	mov r1,0x4567	   | movw r1,0x4567	;immediate could not be encoded

Other instructions than just what is shown above are also affected.

The last part of the principles, the smaller the better, may impact THUMB code
where a particular alignment is required. If you need to ensure that a
particular instruction is always 32-bit, or always 16-bit, then you can use the
qualifiers ".W" and ".N" after the opcodes and conditions to force either wide
(32-bit) or narrow (16-bit) encodings. If the instruction cannot be encoded in
the desired width fasmarm will give an error. If the instruction does not have
both wide an narrow forms then the .W and .N suffixes are undefined. If you
give no width suffix fasmarm will select the narrow form if it is available and
encodable, and the wide form otherwise.

To see how this impacts code using IT blocks examine the following example:

	thumb		;use UAL syntax
	sub	r0,r1	;only encodable as 32-bit outside an IT block
	subs	r2,r3	;fasmarm chooses the 16-bit form
	subs.w	r4,r5	;32-bit encoding forced
	b	.next1
	;...
    .next1:
	;ittt	al	;fasmarm inserts an automatic "IT AL" block
	sub	r0,r1	;fasmarm chooses the 16-bit form inside an IT block
	sub	r2,r3	;fasmarm chooses the 16-bit form inside an IT block
	b	.next2	;IT block extends to here
	;...
    .next2:
	;itttt	al	;fasmarm inserts an automatic "IT AL" block
	sub	r0,r1	;fasmarm chooses the 16-bit form inside an IT block
	sub	r2,r3	;fasmarm chooses the 16-bit form inside an IT block
	sub	r9,r5	;high register used, only encodable as 32-bit
	sub	r6,r7	;fasmarm chooses the 16-bit form inside an IT block

The insertion of automatic "IT AL" blocks is only done when a reduction in code
size is possible. If you need to avoid the automatic "IT AL" block insertion
you can force affected instructions to use the wide encoding with a .W suffix.

	thumb		;use UAL syntax
	sub.w	r0,r1	;32-bit encoding forced
	sub.w	r2,r3	;32-bit encoding forced
	b	.next2

_______________________________________________________________________________
			5. Output formats

The "format" directive will produce ARM code in all the same formats as the X86
version plus one additional format: ELF DWARF. The ELF DWARF is compatible with
the ARM AXD debugger. The DWARF format produced includes all program labels,
line numbers and module names for full symbolic debugging. The ELF format has
been changed to set the FLAGS, code base and machine type compatible for
ARM-LINUX. The PE format has been changed to set the machine type, subsystem
and code base compatible with WinCE. For 664-bit code only the binary format is
currently supported. ELF64 and PE64 formats have not yet been updated.

Use format like this to get the dwarf output:

	format elf dwarf executable [at ?]

Line number and the symbol table generation are automatically enabled with this
format. Using "at" is optional and defaults to 0.

The "section" directive for DWARF output is like this:

	section "name" [executable | readable | writeable | at ?] align ?

The "name" is required. Align is required and must be a power of 2. All other
attributes are optional except that at least one of executable, readable or
writeable must be specified. Using "at" is optional and defaults to the next
aligned address. Attributes can be specified in any order except "name" which
must be first.

The "org" directive is not allowed in DWARF output mode, otherwise everything
is the same as for normal ELF output.

Relocations for ELF and PE are not supported at this time. Although, one user
has reported that relocations are working correctly with PE format, use at your
own risk, I have not tested them yet.

_______________________________________________________________________________
			6. Control directives

There are five directives to control the code generation state:

	CODE64	- Switches to ARM64 (64bit instructions) code generation (alias
		  USE64)
	CODE32	- Switches to ARM (32bit instructions) code generation (alias
		  USE32)
	CODE16	- Switches to THUMB pre-UAL (16bit instructions) code
		  generation (alias USE16)
	THUMB	- Switches to THUMB UAL (16bit instructions) code generation
	THUMBEE	- Switches to ThumbEE UAL (16bit instructions) code generation

At startup the default is CODE32.

There are two directives to control the instruction set classes assembled:

	PROCESSOR <selection>
	COPROCESSOR <selection>

Where <selection> is a list instruction classes to enable or disable. Use a
plus symbol (+) to enable, and a minus symbol (-) to disable. By default only
the CPU32_* and COPRO_* instructions are enabled.

To enable or disable one or more instruction classes without changing other
classes use a leading plus (+) or minus (-) to incrementally update the
settings. For example:

	processor cpu64_v8	;enable only 64-bit version 8 base instructions
				;all other instruction classes are disabled
	processor +cpu64_fp	;additionally enable the 64-bit floating point.
				;If they were already enabled then they remain
				;enabled. Other classes are unaffected.

	processor cpu64_v8 +cpu64_fp	;Both combined has the same effect as
					;above two examples.

	coprocessor -copro_vfp_v4	;disable only the VFP V4 instructions.
					;If they were already disabled then
					;they remain disabled. Other classes
					;are unaffected.

To query the selected instruction classes you can use the 'if' directive to do
logical tests. For example:

	if processor cpu32_v7 | processor cpu32_7m
		;do something
	end if

	if coprocessor copro_vfp_v4
		;do something
	else
		;do something else
	end if

The following is a list of processor instruction classes supported:
	CPU32_26BIT, CPU32_V1, CPU32_V2, CPU32_A, CPU32_V3, CPU32_M, CPU32_V4,
	CPU32_V4T, CPU32_V5, CPU32_V5T, CPU32_E, CPU32_P, PU32_J, CPU32_X,
	CPU32_V6, CPU32_V6T, CPU32_ALIGN, CPU32_K, CPU32_Z, CPU32_6M, CPU32_7M,
	CPU32_T2, CPU32_V7, CPU32_SYNC, CPU32_DIV, CPU32_T2EE, CPU32_MP,
	CPU32_VE, CPU32_V8, CPU32_CRC, CPU64_V8, CPU64_FP, CPU64_SIMD,
	CPU64_CRC, CPU64_CRYPTO

The following is a list of coprocessor instruction classes supported:
	COPRO_FPA_V1, COPRO_FPA_V2, COPRO_MAVERICK, COPRO_VFP_V1XD,
	COPRO_VFP_V1, COPRO_VFP_V2, COPRO_VFP_V3, COPRO_VFP_D32, COPRO_VFP_HP,
	COPRO_XSCALE, COPRO_IWMMXT_V1, COPRO_IWMMXT_V2, COPRO_SIMD_INT,
	COPRO_SIMD_FLOAT, COPRO_SIMD_HP, COPRO_VFP_V4, COPRO_SIMD_V2,
	COPRO_SIMD_V8, COPRO_SIMD_CRYPTO

There are three combination instruction classes that will either enable or
disable all instructions within the class:
	CPU32_ALL, CPU64_ALL, COPRO_ALL

For backward compatibility with previous versions a single numeric constant can
be specified instead of a list of classes. This is only supported for the
following values:

	PROCESSOR supported immediate values:
		CPU32_CAPABILITY_26BIT		= 1 shl 00
		CPU32_CAPABILITY_V1		= 1 shl 01
		CPU32_CAPABILITY_V2		= 1 shl 02
		CPU32_CAPABILITY_A		= 1 shl 03
		CPU32_CAPABILITY_V3		= 1 shl 04
		CPU32_CAPABILITY_M		= 1 shl 05
		CPU32_CAPABILITY_V4		= 1 shl 06
		CPU32_CAPABILITY_V4T		= 1 shl 07
		CPU32_CAPABILITY_V5		= 1 shl 08
		CPU32_CAPABILITY_V5T		= 1 shl 09
		CPU32_CAPABILITY_E		= 1 shl 10
		CPU32_CAPABILITY_P		= 1 shl 11
		CPU32_CAPABILITY_J		= 1 shl 12
		CPU32_CAPABILITY_X		= 1 shl 13
		CPU32_CAPABILITY_V6		= 1 shl 14
		CPU32_CAPABILITY_V6T		= 1 shl 15
		CPU32_CAPABILITY_ALIGN		= 1 shl 16
		CPU32_CAPABILITY_K		= 1 shl 17
		CPU32_CAPABILITY_Z		= 1 shl 18
		CPU32_CAPABILITY_6M		= 1 shl 19
		CPU32_CAPABILITY_7M		= 1 shl 20
		CPU32_CAPABILITY_T2		= 1 shl 21
		CPU32_CAPABILITY_V7		= 1 shl 22
		CPU32_CAPABILITY_SYNC		= 1 shl 23
		CPU32_CAPABILITY_DIV		= 1 shl 24
		CPU32_CAPABILITY_T2EE		= 1 shl 25
		CPU32_CAPABILITY_MP		= 1 shl 26
		CPU32_CAPABILITY_VE		= 1 shl 27
		CPU32_CAPABILITY_V8		= 1 shl 28
		CPU32_CAPABILITY_CRC		= 1 shl 29

	COPROCESSOR supported immediate values:
		COPRO_CAPABILITY_FPA_V1		= 1 shl 00
		COPRO_CAPABILITY_FPA_V2		= 1 shl 01
		COPRO_CAPABILITY_MAVERICK	= 1 shl 02
		COPRO_CAPABILITY_VFP_V1xD	= 1 shl 03
		COPRO_CAPABILITY_VFP_V1		= 1 shl 04
		COPRO_CAPABILITY_VFP_V2		= 1 shl 05
		COPRO_CAPABILITY_VFP_V3		= 1 shl 06
		COPRO_CAPABILITY_VFP_D32	= 1 shl 07
		COPRO_CAPABILITY_VFP_HP		= 1 shl 08
		COPRO_CAPABILITY_XSCALE		= 1 shl 09
		COPRO_CAPABILITY_IWMMXT_V1	= 1 shl 10
		COPRO_CAPABILITY_IWMMXT_V2	= 1 shl 11
		COPRO_CAPABILITY_SIMD_INT	= 1 shl 12
		COPRO_CAPABILITY_SIMD_FLOAT	= 1 shl 13
		COPRO_CAPABILITY_SIMD_HP	= 1 shl 14
		COPRO_CAPABILITY_VFP_V4		= 1 shl 15
		COPRO_CAPABILITY_SIMD_V2	= 1 shl 16
		COPRO_CAPABILITY_SIMD_V8	= 1 shl 17
		COPRO_CAPABILITY_SIMD_CRYPTO	= 1 shl 18

The above symbol names and values are not defined by fasmarm. You can add them
to your source file to use them, or you can use just the raw numbers.

There are two associated predefined symbols: %c and %p. %c is the bitmap value
of the current coprocessor set enabled. %p is the bitmap value of the current
processor set enabled. These predefined symbols only return values in the range
as shown above. That means you can't the %p value to determine if any of the
CPU64* instruction classes has been enabled. Instead use the 'if' form as
shown earlier.

Examples using a numeric constant:
	For ARM7TDMI CPUs:
		processor 0xfe
		coprocessor 0x0

	For PXA25x CPUs:
		processor 0x2ffe
		coprocessor 0x0200

	For PXA27x CPUs:
		processor 0x2ffe
		coprocessor 0x0600

	For Cortex-A8 CPUs:
		processor 0x2fffffe
		coprocessor 0x30f8

	For Cortex-A9 CPUs:
		processor 0x6fffffe
		coprocessor 0x30f8

At start-up the default is to enable the CPU32* instructions and all
coprocessors. It you want to use later instruction classes and any 64-bit
instructions these need to be specified with PROCESSOR before use.

See the files in the ARMDOC folder for details about which instructions are
enabled by each setting.

_______________________________________________________________________________
			7. Data definitions

Data definitions are different between ARM and X86. A "word" in ARM is 32 bits.

	X86  ARM  comment
	---+----+---------
	DB | DB | byte: 8 bits
	DW | DH | half word: 16 bits
	DU | DU | half word strings: 16 bits
	DD | DW | word: 32 bits
	DQ | DD | double word: 64 bits
	RB | RB | byte: 8 bits
	RW | RH | half word: 16 bits
	RD | RW | word: 32 bits
	RQ | RD | double word: 64 bits
	DF | -- |  not valid
	DP | -- |  not valid
	DT | -- |  not valid
	RF | -- |  not valid
	RP | -- |  not valid
	RT | -- |  not valid

Address sizes are always 64 bits in ARM64 state and 32 bits in ARM and THUMB
states, you can't use any address overrides.

Data sizes are different between ARM and X86. A "word" in ARM is 32 bits.

	  X86      ARM     comment
	--------+--------+---------------------
	 BYTE   | BYTE   | same: 8 bits
	 WORD   | HWORD  | half word: 16 bits
	 DWORD  | WORD   | word: 32 bits
	 QWORD  | DWORD  | double word: 64 bits
	 DQWORD | QWORD  | quad word: 128 bits
	 QQWORD | DQWORD | double quad word: 256 bits

You can still use all the pre-processor and assembly features of FASM including
macros, structures, repeats etc.

_______________________________________________________________________________
			8. Defining registers lists inside macros

The standard ARM syntax uses curly brackets, {}, to enclose registers lists.
The standard fasm syntax uses curly brackets to enclose macros. Both standards
are supported in fasmarm and you can mix them together. The way to state
registers lists within macros is to escape the closing curly bracket with a
leading backslash.

	macro block_copy destination, source, length {
		local	.loop
		mov	r0,source
		mov	r1,destination
		add	r2,r0,length
	    .loop:
		ldmia	r0!,{r3-r10\}	;we have to escape the closing bracket
		stmia	r1!,{r3-r10\}	;we have to escape the closing bracket
		cmp	r0,r2
		blo	.loop
	}

_______________________________________________________________________________
			9. Half-precision number formatting

The ARM specification allows extended range half-precision numbers. Care must
be taken when defining numbers that fall within the extended range. Numbers in
the range 65520.0 to 131039.0 inclusive can be defined using the DH directive
and do not give any error. Values within this range place the exponent field at
0x1f. If the CPU is not placed into alternative half-precision (AHP) mode then
these numbers fall within the NaN and infinity encoding space.

_______________________________________________________________________________
			10. Variants supported

Four standard variants of FASM binaries can been produced for FASMARM:

	FASMARM.EXE  - WIN32 console
	FASMWARM.EXE - WIN32 IDE
	FASMARM	     - LINUX
	FASMARM.O    - LIBC

_______________________________________________________________________________
			11. Further information

Visit http://www.arm.com for information on the ARM instruction sets and
processors.

Visit http://flatassembler.net for the FASM x86 assembler package and tools.

If you want to recompile the FASMARM code you will need the flatassembler
package from the above URL.

To see what others have said and to participate in the development of fasmarm
see the active thread on the fasm message board:
http://board.flatassembler.net/topic.php?t=4191

If you have a problem, question, suggestion, comment etc. you can contact me at
http://board.flatassembler.net - my handle is revolution.

_______________________________________________________________________________
			12. Version history

v1.43 2017-Dec-26 - Fix a code minimisation logic regression

v1.42 2017-Jul-23 - Fix a bug with unclosed curly and square bracket parsing

v1.41 2016-Nov-09 - Fix a bug with forward referencing of labels in thumb mode

v1.40 2016-May-14 - Fix a bug with unexpected size checks in 64-bit code for
		     immediate values not used for addressing
		  - Fix a bug with MOVK not respecting the shift amount when
		     the immediate is zero
		  - Change the IDE error summary dialog to show the full error
		     message

v1.39 2016-May-01 - Add 64-bit v8 instructions
		  - Add simple expression evaluation inside address fields,
		     e.g. "ldr x1,[x2-4]" and/or "ldr x1,[x2,-4]"
		  - Add processing for lists of instruction classes to
		     PROCESSOR and COPROCESSOR directives
		  - Add 64-bit SemiHosting example program

v1.38 2016-Apr-11 - Fixed more bugs with elf dwarf format file corruption
		  - Fixed a bug with "section ... at 0" not updating PC to 0
		  - Fixed an encoding bug with VMULL.P8
		  - Add 32-bit v8 instructions

v1.37 2015-Nov-16 - Added code and data generation from macro lines to the line
		     number information table
		  - Fixed a bug with elf dwarf format symbol table corruption
		  - Fixed a bug where post-update instructions with a positive
		     sign (eg. ldr r0,[r1],+r2) would always be forced negative

v1.36 2015-Oct-05 - Fixed another bug with elf dwarf format file corruption

v1.35 2015-Oct-01 - Fixed a bug with elf dwarf format file corruption

v1.34 2015-Jun-18 - Fixed a bug with elf section offsets using "at"

v1.33 2015-May-28 - Added on demand memory allocation for WIN32
		  - Fixed MRC bug with R15 as the destination

v1.32 2014-Dec-21 - Update with all fasm changes as at 1.71.31
		  - Change the format of the undocumented CRC32 directive

v1.31 2014-Jan-29 - Fixed long file names error during line number processing

v1.30 2013-Sep-12 - Fixed THUMB encoding of LDRB and LDRH. Updated for fasm
                     v1.71.13

v1.29 2012-Dec-24 - Added missing assert directive. Updated for fasm v1.71.07,
		     address space additions

v1.28 2012-Jul-11 - Fixed a bug with 65-bit values in section origins

v1.27 2012-Jun-09 - Updated for compatibility with fasm v1.70.02, 65-bit values

v1.26 2012-Feb-24 - Added support for ARM/THUMB mode v7VE instructions
		  - Added support for ARM/THUMB mode VFPv4 instructions
		  - Added support for ARM/THUMB mode SIMDv2 instructions
		  - Added alternate two operand forms for absolute difference
		  - Removed alternate two operand forms for multiply-accumulate

v1.25 2011-Oct-31 - Fixed a bug with BKPT handling in IT blocks in ARM mode

v1.24 2011-Oct-29 - Fixed a bug with crashes during expression parsing

v1.23 2011-Jul-31 - Fixed a bug with relocations corrupting patch code

v1.22 2010-Nov-24 - Fixed a bug with handling nameless sections in dwarf format

v1.21 2010-Oct-17 - Minimising the "code cannot be generated" problem. If the
		     assembler gets to a third repetition at the same state
		     then it takes action and uses wide instructions in
		     situations where the narrow instructions are causing
		     problems

v1.20 2010-Sep-17 - Fixed a bug with handling of files names in dwarf format

v1.19 2010-Sep-16 - Add support for half-precision and extended half-precision
		     number formatting. Compatible with fasm v1.69.24

v1.18 2010-Sep-09 - Update for compatibility with fasm v1.69.22

v1.17 2010-Sep-08 - Added support to separate byte and rotation values for
		     immediate values in shifter encoding

v1.16 2010-Apr-26 - Added experimental instruction CRC32
		  - Added experimental operator FIT
		  - Added alternate encoding logic for VMOV/VMVN 16-bit and
		     32-bit forms
		  - Generate an error with more than 16 double registers in
		     FLDMD/FSTMD/VLDM/VSTM/VPOP/VPUSH
		  - Fixed erroneous generation of conditional instructions when
		     mixing VIRTUAL with IT blocks
		  - Fixed encoding for THUMB mode PC relative immediate
		     addressing when placed inside auto IT block
		  - Fixed encoding for WLDRx/WSTRx with PC relative addressing

v1.15 2010-Apr-21 - Added support for ARM/THUMB mode v6T2 instructions
		  - Added support for ARM/THUMB mode v7 instructions
		  - Added support for ThumbEE instructions
		  - Added support for FPA coprocessors up to v2
		  - Added support for VFP coprocessors up to v3
		  - Added support for MAVERICK coprocessors
		  - Added support for Intel WMMXT coprocessors up to v2
		  - Added support for Advanced SIMD coprocessors
		  - Added support for alternate two register data processing
		     operands. Implicit destination is the first operand
		  - Added support for expressions in addresses to access PC
		     relative variables and locations
		  - Added support for automatic efficient IT block generation
		     in THUMB mode
		  - Added support for UAL assembly syntax
		  - Added support for an optional hash (#) before literal
		     values
		  - Added predefined variables %c and %p
		  - Added ARMDOC folder with example instruction formats for
		     each opcode supported
		  - Extended the alternate encoding logic
		  - Changed numeric separation character from single quote (')
		     to underscore (_)
		  - Changed non-UAL SRS syntax to use a space, instead of a
		     comma, between the mode number and writeback operator
		  - Removed directives CODEFP, CODENOFP, CODEV5, CODEV6,
		     CODEVFP1, CODEVFP2, ARM5, ARM6, VFP1 and VFP2. Use
		     PROCESSOR and COPROCESSOR instead

v1.14 2010-Feb-02 - Updated for compatibility with FASM 1.69.11
		  - Changed "LDRx reg,[reg,0]!" to generate  "LDRx reg,[reg,0]"
		  - Changed "LDRx reg,[reg],0" to generate  "LDRx reg,[reg,0]"
		  - Changed "LDC Px,Cx,[reg,0]!" to generate
		     "LDC Px,Cx,[reg,0]"
		  - Changed "LDC Px,Cx,[reg],0" to generate
		     "LDC Px,Cx,[reg,0]"
		  - Fixed encoding for thumb mode BLX
		  - Fixed encoding for PKHTB without shift
		  - Fixed encoding for SSAT, SSAT16
		  - Fixed encoding for UMAAL
		  - Allowed rotation parameter for SXTB, SXTH, UXTB, UXTH

v1.13 2008-Nov-04 - Updated register restrictions for STREX, SMLALD, SMLSLD,
		     UMAAL, SMLALxy
		  - Relaxed restriction of rotation count=0 (or omitted) for
		     PKHTB
		  - Enabled THUMB mode aliases for SXTB, SXTH, UXTB, UXTH

v1.12 2008-Jul-13 - Updated for compatibility with FASM 1.67.27
		  - Fixed "error: undefined symbol" displaying the wrong line

v1.11 2008-Mar-20 - Updated for compatibility with FASM 1.67.26 (note: no
		     version change)

v1.11 2007-Aug-31 - Updated for compatibility with FASM 1.67.22
		  - Fixed an address parser bug allowing "ldr rx,[constant]"
		     without a register base

v1.10 2007-Mar-04 - Updated for compatibility with FASM 1.67.21 expression
		     calculation
		  - Allowed forward referencing of register based structure
		     addressing
		  - Fixed a bug in the ARMLITRL.INC when generating PC relative
		     offsets

v1.09 2006-Aug-30 - Updated ARMTABLE.INC for compatibility with FASM 1.67
		     binary searches
		  - Updated PE format to initialise several accounting fields
		     and also to reset the "relocs stripped" flag if relocs are
		     included

v1.08 2006-Jun-09 - Fixed erroneous error with implicit r0 based addressing
		  - Fixed priority of unary minus to match FASM v1.66 priority
		  - Relaxed restrictions with register structure addresses when
		     using zero offset
		  - Enhanced MOV/MOVS to use ADD/SUB encoding when loading a
		     register structure member
		  - Generation of special encoding to allow user code to detect
		     unencodable immediate values and then select an alternate
		     coding without causing assembly errors
		  - Alignment bytes changed to 0xff to facilitate faster FLASH
		     ROM updates
		  - Added proc, apscall, import and literals macros to package,
		     see each individual file for usage and special notes
		  - STRUCT and RESOURCE converted from x86 to ARM format
		  - COREDLL.INC converted to an imports definition file

v1.07 2006-May-26 - Patch for basic "format PE" support for WinCE
		  - Added ARMPE example for WinCE (2006-06-02)
		  - COREDLL.DLL import ordinal equates added in "COREDLL.INC"
		     (2006-06-02)

v1.06 2006-Mar-03 - Updated to work within FASM version 1.66

v1.05 2006-Feb-14 - Patch for basic "format ELF executable" support
		  - Added ARMELF example

v1.04 2005-Nov-09 - Fixed incorrect classification of data/code when using
		     TIMES
		  - Improved line number embedding generation for more
		     efficient tables

v1.03 2005-Oct-20 - Fixed IF/ELSE/END IF skip bug with commas

v1.02 2005-Oct-03 - Fixed CPS mode change code generation
		  - Fixed THUMB ASR and LSR shift range check

v1.01 2005-Oct-01 - Fixed STMIA THUMB instruction checking for base register
		     validity
		  - Fixed error deferring for some expressions
		  - Fixed shift count of 32
		  - Added ARMv6 instructions
		  - Added VFPv2 instructions
		  - Added register aliases a1-a4, v1-v8, sb, sl, fp, ip
		  - Added CODE16, CODE32, CODEFP, CODENOFP, CODEV5, CODEV6,
		     CODEVFP1, CODEVFP2 directives
		  - Added ARM5, ARM6, VFP1, VFP2  combination directives
		  - Enforced code typing (generates an error if new
		     instructions are used but not enabled)
		  - Enforced VFP to be explicitly enabled before use
		  - Removed condition code "NV"

v1    2005-Sep-29 - First public release

(C) 26-Dec-2017 revolution
