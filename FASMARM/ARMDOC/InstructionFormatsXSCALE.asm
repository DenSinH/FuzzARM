;This document is intended to show the basic formats for
;all of the instructions supported by fasmarm.

;These formats are divided into sections showing the CPU
;processor directive needed to enable the instruction.

;Opcodes are listed in alphabetical order within each
;section. A blank line separates each opcode from the
;next.

;Instructions can appear in many places. Different
;versions of the instruction set can allow for different
;sets of available parameters so be sure to check for
;instructions listed in more than one place. If you are
;having trouble working out what format fasmarm is
;expecting then you can search through here for all
;instances to find the situation that matches your code.

;Coprocessor formats are divided firstly by the
;coprocessor type and secondly by the implementation
;version. Coprocessor instructions are available in both
;ARM and THUMB modes and use the same format for both.
;There is no change needed for THUMB mode except to
;specify that the processor supports version 7M
;architecture instructions. 

;The example codes given here are merely indicative of
;which parameters go where. They are not intended as an
;enumeration of all possible allowed values of the
;parameters. Usually only one register or one immediate
;value for each parameter is given so as to show what
;type of parameter is expected at each position. If you
;try to assemble a value that is undefined,
;unpredictable or not encodable fasmarm will give a
;short error message complaining that the parameter is
;invalid.

;These instructions do not show any condition syntax.
;All instructions can be conditional. The condition code
;should be added at the end of the main opcode and
;before any size/type specifiers. For example: "addhi"
;and "vaddhi.i16". The syntax also supports the pre-UAL
;style of putting the condition before any modifiers
;like "s" or "fd". For example: "ldmhifd", "ldmfdhi".

;This file can be assembled by fasmarm.

virtual at r1
	expression.dword	rd 1
	expression.word		rw 1
	expression.hword	rh 1
	expression.byte		rb 1
end virtual

	;***********************************************
	;xScale, ARM mode, all instructions are 32-bit
	;***********************************************

	code32

coprocessor COPRO_XSCALE

	mia	acc0,r1,r2

	miaph	acc0,r1,r2

	miabb	acc0,r1,r2

	miabt	acc0,r1,r2

	miatb	acc0,r1,r2

	miatt	acc0,r1,r2

	mar	acc0,r1,r2

	mra	r0,r1,acc0

	;***********************************************
	;xScale, THUMB mode, all instructions are 32-bit
	;***********************************************

processor CPU32_7M

	thumb

	mia	acc0,r1,r2

	miaph	acc0,r1,r2

	miabb	acc0,r1,r2

	miabt	acc0,r1,r2

	miatb	acc0,r1,r2

	miatt	acc0,r1,r2

	mar	acc0,r1,r2

	mra	r0,r1,acc0
