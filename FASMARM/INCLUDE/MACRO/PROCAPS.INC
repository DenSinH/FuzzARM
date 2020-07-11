;FASMARM extension macros:
;
;High level procedure macros for APS (ARM Procedure Standard) calling
;
;The APS call standard requires the first four parameters to be passed in registers r0-r3, any remaining
;parameters are placed on the stack and pushed in reverse order. The stack is always full descending.
;Caller always restores the stack. Any return values are in r0-r3.
;
;r4-r11 must always be preserved by procedures.
;r12 is always a scratch register and considered corruptable.
;r13 is always the stack register and is always used in full descending mode.
;r14 is always the return address and considered corruptable.
;
;These macros are NOT compatible with thumb mode
;
;
;APSCALL:
;
;  Usage: apscall name, arg1, size[arg2], addr arg3, [arg4], 'string', *'string', 'A'+0, ...
;
;  name      - required - specifies the name of the target procedure
;  args      - optional - any arguments required by the target procedure
;  addr      - refers to a PC relative address or a frame pointer relative address
;  size      - size override operator, can be byte, sbyte, hword, shword or word
;              byte   - zero extended byte value to 32 bit
;              sbyte  - sign extended byte value to 32 bit
;              hword  - zero extended half word value to 32 bit
;              shword - sign extended half word value to 32 bit
;              word   - 32 bit value
;  [arg]     - value stored at address arg
;  'string'  - literal ascii string placed directly in the code stream. For convenience
;  *'string' - literal unicode string placed directly in the code stream. For convenience
;  'A'+0     - immediate value zero extended to 32 bit, can be 1 through 4 characters in length
;
;  NOTE: "apscall" is safe to use inside an SP frame based procedure. The macro properly allocates the stack.
;
;
;PROC:
;
;  Usage: proc   name   base reg   uses [reg, reg-reg, reg]   nospill  ,arg1, arg2, arg3, ...
;
;  paramters:
;
;  name     - required - specifies the name of the procedure
;  base reg - optional - specifies the base register to use for the stack frame, default is R11 (fp)
;  uses [.] - optional - lists registers to be saved upon entry and restored upon exit. Square brackets are required.
;                        NOTE: if you specify LR to be saved it will be automatically restored to PC upon exit
;  nospill  - optional - specifies the first four parameters are not to be spilled to the stack upon entry
;                        See the "To spill or not to spill?" note
;  args     - optional - input arguments from calling procedure, must be started with and separated by commas
;
;  "name" must be first.
;  "base reg", "uses [.]" and "nospill" can be specified in any order after "name".
;  "args" must be placed last.
;
;  To spill or not to spill?
;
;  By omitting the "nospill" optional the proc macro will spill the first four arguments to the stack upon entry.
;  This creates the most reliable way to access input parameters at the small cost of extra object code.
;  By using the "nospill" option the first four arguments are aliased to the registers r0-r3 directly.
;  "nospill" mode is best suited for leaf and "register light" procedures where using the stack is unneccesary.
;  Accessing the first four parameters is different between the two cases:
;
;  eg1. proc foo nospill, bar1, bar2, bar3, bar4, bar5
;         mov r3,bar2   ;mov r3,r1 - from here on bar4 (r3) has been lost!
;         mov r0,bar2   ;mov r0,r1 - from here on bar1 (r0) has been lost!
;         mov r5,bar1   ;ERROR: bar1 (r0) was destroyed above
;         lea r4,[bar3] ;invalid: bar3 (r2) is not in memory
;         ldr r4,[bar3] ;invalid: bar3 (r2) is not in memory
;         ldr r4,[bar5] ;okay: ldr r0,[fp]
;       endp
;
;  compare to this:
;
;  eg2. proc foo, bar1, bar2, bar3, bar4, bar5
;         mov r3,bar2   ;add r3,fp,4
;         lea r3,[bar2] ;add r3,fp,4
;         ldr r0,[bar2] ;ldr r0,[fp,4]
;         ldr r5,[bar1] ;ldr r5,[fp]
;         lea r4,[bar3] ;add r4,fp,8
;         ldr r4,[bar5] ;ldr r4,[fp,10h]
;       endp
;
;  and also compare to this:
;
;  eg3. proc foo uses[r4-r6, lr], bar1, bar2, bar3, bar4, bar5
;         mov r3,bar2   ;add r3,fp,4
;         ldr r0,[bar2] ;ldr r0,[fp,4]
;         ldr r5,[bar1] ;ldr r5,[fp]
;         lea r4,[bar3] ;add r4,fp,8
;         ldr r4,[bar5] ;ldr r4,[fp,20h] ;note the different offset from above
;       endp
;
;
;  The stack frame:
;
;  eg4. Assume the calling procedure does this: "apscall MyFunc, arg1, arg2, arg3, arg4, arg5, arg6",
;       then: "proc MyFunc uses [fp, r4, lr], arg1, ..." creates a stack frame that looks like this:
;
;  arg6             - pushed by calling procedure       higher addresses up here
;  arg5             - pushed by calling procedure  <---------------^------------- FP points here
;  saved reg lr     - pushed by proc                               |
;  saved reg fp     - pushed by proc                               |
;  saved reg r4     - pushed by proc                               |
;  arg4 (reg r3)    - pushed by proc                               |
;  arg3 (reg r2)    - pushed by proc                               |
;  arg2 (reg r1)    - pushed by proc                               v
;  arg1 (reg r0)    - pushed by proc                    lower addresses down here
;  locals data      - uninitialised data <-- SP points here
;
;  NOTE: the order of register saving is always highest (r15) to lowest (r0) regardless of the
;        order they are specified in the "uses" statement.
;
;
;  eg5. Assume the calling procedure does this: "apscall MyFunc, arg1, arg2, arg3, arg4, arg5, arg6",
;       then: "proc MyFunc base r4 uses [r4, lr] nospill, arg1, ..." creates a stack frame that looks like this:
;
;  arg6             - pushed by calling procedure       higher addresses up here
;  arg5             - pushed by calling procedure  <---------------^------------- R4 points here
;  saved reg lr     - pushed by proc                               v
;  saved reg r4     - pushed by proc                    lower addresses down here
;  locals data      - uninitialised data <-- SP points here
;
;  NOTE: The first four arguments are still in registers r0-r3 and have not been spilled to the stack
;
;
;  eg6. Assume the calling procedure does this: "apscall MyFunc, arg1, arg2, arg3, arg4, arg5, arg6",
;       then: "proc MyFunc base sp uses [lr] nospill, arg1, ..." creates a stack frame that looks like this:
;
;  arg6             - pushed by calling procedure       higher addresses up here
;  arg5             - pushed by calling procedure                  |
;  saved reg lr     - pushed by proc                    lower addresses down here
;  locals data      - uninitialised data <-- SP points here
;
;  NOTE: Using sp based addressing requires special attention. The "apscall" macro has been
;        designed to properly issue parameters when using sp based variables but your code must
;        always restore sp before executing "apscall" or "ret".
;
;
;LOCALS/ENDL:
;
;  Usage: locals | endl
;
;  Valid inside a proc/endp pair only. Declares uninitialised locally addressable variables.
;  You can use any number of locals/endl pairs, they are all concatenated together on the stack at runtime.
;
;  eg7. proc foo
;         locals
;           varw dw ?
;           varh dh ?
;           varb db 100 dup (?)
;         endl
;           mov  r1,'x'
;           strb r1,[varb+2]
;           lea  r2,[varw]
;           ...
;       endp
;
;
;LOCAL:
;
;  Usage: local name definition | local name:type | local name[count]:type
;
;  Valid inside a proc/endp pair only. Declares uninitialised locally addressable variables.
;  You can use any number of local definitions, they are all concatenated together on the stack at runtime.
;
;  name       - the symbolic name of the variable
;  count      - must be numeric
;  type       - one of BYTE, HWORD, WORD, DWORD or a structure name
;  definition - the variable's definition statement
;
;  eg8. local MyVar1 db ?
;       local MyVar2 rb 8
;       local MyVar3:HWORD
;       local MyVar4[0x100]:BYTE
;
;
;RET:
;
;  Usage: ret(cond)
;
;  Valid inside a proc/endp pair only. Restores the state and returns to the calling procedure.
;
;  The worst case generated code by ret is three instructions for non-sp based procedures, and four
;  instructions plus one literal for sp based precedures.
;
;
;ENDP:
;
;  Usage: endp
;
;  Ends the current "proc", freeing all local scope equates.
;
;
;POP/PUSH:
;
;  Usage: push  reg, reg-reg, reg, ...   |   pop  reg, reg-reg, reg, ...
;
;  At least one reg required in the list. Convience macros for optimal full descending stack operations.
;
;
;LEA:
;
;  Usage: lea(cond) reg, [address]
;
;  Convienience macro to access locations that are PC or local frame based.
;  The macro automatically determines whether the address is a local variable or external variable
;  and generates the appropriate code.
;
;
;  General note: You may notice that some instructions below use uppercase, this is to integrate with the
;                literals macros in ARMLIRTL.INC.
;
;By default this file is included from "WINCE.INC".

macro def_ustring labl,[string] {common labl dU string}
macro def_astring labl,[string] {common labl dB string}

macro apscall function,[parameter] {
    common
	local pcount,tempcount,found,.skip,.size,param,last_value,temp,size,instr,i_s,msize
	virtual
		nop
		temp=$-$$
	end virtual
	if temp<>4
		halt ;APSCALL macro NOT usable in thumb mode
	end if
	if ~ parameter eq
		if .size
		    b .skip
		end if
		temp=$
		tempcount=0
    reverse
		local ..arg
		found equ no
		match i[like]za,:parameter: \{ found equ \}
		match =no:*ustring,found:parameter \{
		    def_ustring ..arg,ustring,0
		    found equ \}
		match =no:some=,more,found:parameter \{
		    def_astring ..arg,parameter,0
		    found equ \}
		match =no,found \{
		  if parameter eqtype ''
		    def_astring ..arg,parameter,0
		  end if \}
		tempcount=tempcount+1
    common
		pcount=tempcount
		align 4
		.size=$-temp
		if .size
		    .skip:
		end if
		lastvalue=1 shl 63
		tempcount=0
    reverse
		if tempcount<(pcount-4)
		    found equ no
		    define param parameter
		    match [address],parameter \{
			LDR lr,[address]
			lastvalue=1 shl 63
			str lr,[sp,-tempcount*4-4]
			found equ yes \}
		    irp i_s,b:byte:byte,sb:sbyte:byte,h:hword:hword,sh:shword:hword,:word:word \{
		     match instr:msize:size,LDR\#i_s \\{
		      match =msize[address],parameter \\\{
			instr lr,size[address]
			lastvalue=1 shl 63
			str lr,[sp,-tempcount*4-4]
			found equ yes \\\}\\}\}
		    match =addr address,param \{
			lea lr,[address]
			lastvalue=1 shl 63
			str lr,[sp,-tempcount*4-4]
			found equ yes \}
		    match value =no,parameter found \{
			if defined ..arg
			    lastvalue=1 shl 63
			    ADD lr,pc,..arg-$-8
			    str lr,[sp,-tempcount*4-4]
			else if value eqtype r0
			    str value,[sp,-tempcount*4-4]
			else if value eqtype 0
			    virtual
				dw value
				load temp word from $-4
			    end virtual
			    if temp <> lastvalue
				MOV lr,value
			    end if
			    lastvalue=temp
			    str lr,[sp,-tempcount*4-4]
			else
			    MOV lr,value
			    lastvalue=1 shl 63
			    str lr,[sp,-tempcount*4-4]
			end if \}
		end if
	    rept 4 p:0 \{\reverse
		if tempcount=pcount-p-1
		    found equ no
		    match [address],parameter \\{
			LDR r\#p,[address]
			found equ yes \\}
		    irp i_s,b:byte:byte,sb:sbyte:byte,h:hword:hword,sh:shword:hword,:word:word \\{
		     match instr:msize:size,LDR\\#i_s \\\{
		      match =msize[address],parameter \\\\{
			instr r\#p,size[address]
			found equ yes \\\\}\\\}\\}
		    match =addr address,param \\{
			lea r\#p,[address]
			found equ yes \\}
		    match value =no,parameter found \\{
			if ~ defined ..arg & value eqtype 0
			    virtual
				dw value
				load temp word from $-4
			    end virtual
			end if
			if defined ..arg
			    ADD r\#p,pc,..arg-$-8
			else if value eqtype 0 & lastvalue = temp
			    MOV r\#p,lr
			else if ~ r\#p eq value
			    MOV r\#p,value
			end if \\}
		end if
	    \}
		tempcount=tempcount+1
    common
	else
		pcount=0
	end if
	if pcount>4
		sub sp,sp,(pcount-4)*4
	end if
	if defined _#function & _#function-$-8<4096 & _#function-$-8>-4096
		mov lr,pc
		ldr pc,[pc,_#function-$-8]
	else
		bl function
	end if
	if pcount>4
		add sp,sp,(pcount-4)*4
	end if
}

macro popcount val,result {
	local r
	r=0
	repeat 16
		r=r+(((val)shr(%-1))and 1)
	end repeat
	result=r
}

macro push [list] {
    common
	local bits,popc
	virtual
		stmdb sp!,{list\}
		load bits hword from $-4
	end virtual
	popcount bits,popc
	if popc=1
		str list,[sp,-4]!
	else
		stmdb sp!,{list\}
	end if
}

macro pop [list] {
    common
	local bits,popc
	virtual
		ldmia sp!,{list\}
		load bits hword from $-4
	end virtual
	popcount bits,popc
	if popc=1
		ldr list,[sp],+4
	else
		ldmia sp!,{list\}
	end if
}

irp cond,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo {
  macro push#cond [list] \{
    \common
	\local bits,popc
	virtual
		stm#cond#db sp!,\\{list\\}
		load bits hword from $-4
	end virtual
	popcount bits,popc
	if popc=1
		str#cond list,[sp,-4]!
	else
		stm#cond#db sp!,\\{list\\}
	end if
  \}
  macro pop#cond [list] \{
    \common
	\local bits,popc
	virtual
		ldm#cond#ia sp!,\\{list\\}
		load bits hword from $-4
	end virtual
	popcount bits,popc
	if popc=1
		ldr#cond list,[sp],+4
	else
		ldm#cond#ia sp!,\\{list\\}
	end if
  \}
}

macro proc [parameter] {
    common
	local use,pname,parg,stack_count,bits,curr_off,locals_size,regbase,locals_names,spill,spill_size,param_count
	match n remaining,parameter: \{pname equ n\}
    if used pname
	use equ
	parg equ
	locals_names equ
	regbase equ fp
	spill equ all
	match junk =uses[u] remaining,parameter: \{use equ u\}
	match junk =base b remaining,parameter: \{regbase equ b\}
	match junk =nospill remaining,parameter: \{spill equ no\}
	match :junk=,remaining,use:parameter \{parg equ remaining\}
	match u:junk]=,remaining,use:parameter \{parg equ remaining\}
	match :u:junk]foo=,remaining,parg:use:parameter \{parg equ remaining\}
	match ,parg \{spill equ no\}
	match =all:p1=,p2=,p3=,more,spill:parg\{spill equ ,r0,r1,r2,r3\}
	match =all:p1=,p2=,p3,spill:parg\{spill equ ,r0,r1,r2\}
	match =all:p1=,p2,spill:parg\{spill equ ,r0,r1\}
	match =all:p1,spill:parg\{spill equ ,r0\}
	match =no:p1=,p2=,p3=,p4=,more,spill:parg\{irp arg,p1 r0,p2 r1,p3 r2,p4 r3\\{match a r,arg\\\{a equ r\\\}\\}spill equ\}
	match =no:p1=,p2=,p3=,p4,spill:parg\{irp arg,p1 r0,p2 r1,p3 r2,p4 r3\\{match a r,arg\\\{a equ r\\\}\\}spill equ\}
	match =no:p1=,p2=,p3,spill:parg\{irp arg,p1 r0,p2 r1,p3 r2\\{match a r,arg\\\{a equ r\\\}\\}spill equ\}
	match =no:p1=,p2,spill:parg\{irp arg,p1 r0,p2 r1\\{match a r,arg\\\{a equ r\\\}\\}spill equ\}
	match =no:p1,spill:parg\{p1 equ r0\}
	match =no,spill\{spill equ\}
	match =,any,spill \{
	    virtual at 0
		ldmia sp!,{any\\}
		load bits hword from $-4
		popcount bits,spill_count
	    end virtual
	\}
	match ,spill\{spill_count=0\}
	match any,use \{
	    virtual at 0
		ldmia sp!,{any\\}
		load bits hword from $-4
		popcount bits,stack_count
	    end virtual
	\}
	match ,use\{stack_count=0\}
	curr_off=0
	match =,junk:args,spill:parg \{
	    irp arg,args \\{
		\\local ..arg
		arg equ ..arg
		if curr_off<4
		    if regbase eq sp
			virtual at regbase+curr_off*4+locals_size
		    else if param_count >= 4
			virtual at regbase-(4-curr_off+stack_count)*4
		    else
			virtual at regbase-(param_count-curr_off+stack_count)*4
		    end if
			    ..arg dw ?
			end virtual
		else
		    if regbase eq sp
			virtual at regbase+stack_count*4+curr_off*4+locals_size
		    else
			virtual at regbase+(curr_off-4)*4
		    end if
			    ..arg dw ?
			end virtual
		end if
		curr_off=curr_off+1
	    \\}
	    param_count=curr_off
	\}
	match :p1=,p2=,p3=,p4=,others,spill:parg \{
	  param_count=5
	  if regbase eq sp
	    virtual at regbase+(stack_count+spill_count)*4+locals_size
	  else
	    virtual at regbase
	  end if
	    irp arg,others \\{
		\\local ..arg
		arg equ ..arg
		..arg dw ?
	    \\}
	    end virtual
	\}
	align 4
	use32
    pname:
	match :=,regs,use:spill\{push regs\}
	match junk,use\{push use spill\}
	if (~ regbase eq sp) & ((locals_size+spill_count) | (defined param_count & param_count>4))
	    add regbase,sp,(stack_count+spill_count)*4
	end if
	if (locals_size)
	    SUB sp,sp,locals_size
	end if
    irp cond,,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo \{
     match rt:sb1:AD2:ld:ldia:xb,ret\#cond:sub\#cond:ADD\#cond:ldr\#cond:ldm\#cond\#ia:bx\#cond\\{
      macro rt \\\{
	if (~ regbase eq sp) & ((locals_size+spill_count) | (defined param_count & param_count>4))
	    sb1 sp,regbase,stack_count*4
	end if
	if (regbase eq sp) & locals_size+spill_count
	    AD2 sp,sp,locals_size+spill_count*4
	end if
	if stack_count>1
		ldia sp!,{use\\\\}
		store hword ((bits and 0x3fff)+((bits and 0x4000)shl 1)) at $-4
		if ~ bits and 0x4000
			xb lr
		end if
	else if stack_count=1
		if use eq lr
			ld pc,[sp],+4
		else
			ld use,[sp],+4
			xb lr
		end if
	else
		xb lr
	end if
      \\\}
     \\}
    \}
    curr_off=0
    local in_locals
    in_locals=0
    macro locals \{
	if in_locals
	    halt - locals is not allowed to be recursive
	end if
	if regbase eq sp
	    virtual at regbase+curr_off
	else
	    virtual at regbase-locals_size+curr_off-((stack_count+spill_count)*4)
	end if
	in_locals=1
    \}
    local ..s,size,reserve,op,def,copy
    macro \local [arg] \{
      \common
	locals
      \forward
	found equ no
	define copy arg
	match name[count]:type,copy \\{
	    irp op,BYTE rb,HWORD rh,WORD rw,DWORD rd \\\{
	     match size reserve,op \\\\{
	      match =size,type \\\\\{
		name reserve count
		found equ \\\\\}\\\\}\\\}
	    match =no,found \\\{
		virtual
		    name type
		    ..s=$-$$
		end virtual
		rb count*..s
		found equ \\\}
	\\}
	match =no:name:type,found:copy \\{
	    irp op,BYTE db,HWORD dh,WORD dw,DWORD dd \\\{
	     match size def,op \\\\{
	      match =size,type \\\\\{
		name def ?
		found equ \\\\\}\\\\}\\\}
	    match =no,found \\\{
		name type
		found equ \\\}
	\\}
	match =no,found \\{ arg \\}
      \common
	endl
    \}
    macro endl \{
	in_locals=0
	curr_off=curr_off+$-$$
	end virtual
    \}
    macro close_proc \{
	locals_size=(curr_off+3)and not 3
	match a,parg \\{ restore a \\}
	match =,a,locals_names \\{ restore a \\}
	restruc db,dh,du,dw,dd,rb,rh,rw,rd
    \}
    irp op,db 1,dh 2,du 2,dw 4,dd 4,rb 1,rh 2,rw 4,rd 4 \{
	\local already
	match str bytes,op \\{
	    struc str [v]\\\{
		\\\common
		\\\local ..arg
		already equ no
		match foo =. bar,:locals_names:\\\\{already equ\\\\}
		match =no,already\\\\{
			locals_names equ locals_names,.
			. equ ..arg
		\\\\}
		times ($$-$-curr_off)and(bytes-1) db ?
		. str v
	    \\\}
	\\}
    \}
    irp cond,,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo \{
     \local ad
     match inst,lea\#cond\\{
      macro inst dest,var \\\{
	found equ no
	define copy var
	match [v=+off],copy \\\\{
	    match ad:some=,=v=,more , ADD\#cond::,parg locals_names,: \\\\\{
		ad dest,regbase,v-regbase+off
		found equ
	    \\\\\}
	\\\\}
	match [v=-off],copy \\\\{
	    match ad:some=,=v=,more , ADD\#cond::,parg locals_names,: \\\\\{
		ad dest,regbase,v-regbase-off
		found equ
	    \\\\\}
	\\\\}
	match [v=,off],copy \\\\{
	    match ad:some=,=v=,more , ADD\#cond::,parg locals_names,: \\\\\{
		ad dest,regbase,v-regbase+off
		found equ
	    \\\\\}
	\\\\}
	match [v]:=no,copy:found \\\\{
	    match ad:some=,=v=,more , ADD\#cond::,parg locals_names,: \\\\\{
		ad dest,regbase,v-regbase
		found equ
	    \\\\\}
	\\\\}
	match ad:[v]:=no,ADD\#cond:copy:found \\\\{
	    ad dest,pc,v-$-8
	    found equ
	\\\\}
	match =no,found\\\\{
	    halt ;malformed expression, use: lea reg,[address]
	\\\\}
      \\\}
     \\}
    \}
}

macro endp {
    close_proc
    purge locals,endl,close_proc,local
    irp cond,,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo\{
	purge lea\#cond
	purge ret\#cond
    \}
    end if
}

irp cond,,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo {
 local found,inst,ad,d,v
 match inst,lea#cond\{
  macro inst dest,var \\{
    found equ no
    match ad:d:[v],ADD#cond:dest:var \\\{
	ad d,pc,v-$-8
	found equ
    \\\}
    match =no,found \\\{
	halt ;malformed expression, use: lea reg,[address]
    \\\}
  \\}
 \}
}

