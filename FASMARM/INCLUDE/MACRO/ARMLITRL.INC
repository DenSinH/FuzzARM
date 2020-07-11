;FASMARM extension macros:
;
;Macros for using large constants directly with data processing and memory instructions
;
;Access to the macros is always with the first three characters as uppercase.
;This is necessary to prevent excess memory usage with normal instructions not requiring this functionality.
;
;NOTE: these macro use R12 (ip) for intermediate values. Don't rely on R12 being preserved.
;
;These macros are NOT compatible with thumb mode
;
;These macros allow you to do things like this:
;
;ADDne r11,r2,0x12345678   ;compiles to "ldrne r11,[pc,..lit?0]" and "addne r11,r2,r11"   with "..lit?0 dw 0x12345678"
;ADD   r11,r11,0x12345678  ;compiles to "ldr r12,[pc,..lit?0]"   and "add r11,r11,r12"
;LDRhi r0,[r0,-0x12345678] ;compiles to "ldrhi r12,[pc,..lit?0]" and "ldrhi r0,[r0,-r12]"
;STRb  r0,[r3,0xcc000000]  ;compiles to "mov r12,0xcc000000"     and "strb r0,[r3,r12]"
;CMP   r2,0x101            ;compiles to "ldr r12,[pc,..lit?1]"   and "cmp r2,r12"         with "..lit?1 dw 0x101"
;CMP   r2,0x100            ;compiles to "cmp r2,0x100"
;
;Notice that the allocation of literals is optimised to reuse values where possible and only allocated when necessary.
;
;You will need to periodically dump the literals to the output before the labels get more than 4Kbytes distant
;from the source instruction. Generally you can do this after an unconditional branch, and usually at the
;end of a procedure. Simply dump at an appropriate place with "literals".
;
;These macros will correctly handle any ARM format the assembler can handle, so you could do all your code by using
;these macros, but this can create excessive demands on memory and increases compilation time. These macros are
;especially useful where you might use symbolic constants and not be sure of the required size. Just put the base
;instruction in uppercase and let the macros decide the best encoding for you.
;
;The PROCAPS.INC macros have ben designed to use these macros also. When you include this file along with PROCAPS.INC
;then they will cooperate to produce easy to program and also optimised output for your project.
;
;By default this file is included from "WINCEX.INC".

macro make_dp_instr instr,suffix,regs,flag {
 irp cond,,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo \{
  match inst,instr\#cond\#suffix\\{
   macro inst regs,[arg] \\\{
    \\\common
    \\\local encoding,..lit,z,c,..pc,arg_pc
    if ~ defined encoding | encoding <> 0xf7ffffff
     inst regs,arg
     load encoding word from $-4
    else
     ..pc=$
     match billg =$ lots,:arg: \\\\{match :a:,billg\\\\#..pc\\\\#lots \\\\\{arg_pc equ a\\\\\}\\\\}
     match =arg_pc,arg_pc \\\\{arg_pc equ arg\\\\}
     match ra=,rb:ld,regs:ldr\#cond \\\\{
      match =pc,rb\\\\\{arg_pc equ arg_pc-4\\\\\}
      match =r15,rb\\\\\{arg_pc equ arg_pc-4\\\\\}
      if ra eq rb
       if ra eq ip
	halt ;cannot use ip,ip,large constant
       end if
       ld ip,[pc,..lit-$-8]
       inst regs,ip
      else
       ld ra,[pc,..lit-$-8]
       inst regs,ra
      end if
     \\\\}
     match =0:ld,flag:ldr\#cond \\\\{
      ld ip,[pc,..lit-$-8]
      instr regs,ip
     \\\\}
     match =1:ld,flag:ldr\#cond \\\\{
      ld regs,[pc,..lit-$-8]
     \\\\}
     if arg eqtype 0
      virtual
       dW arg_pc
       load c word from $-4
      end virtual
      repeat 17
       if %=17
	encoding=0xf7ffffff
	break
       end if
       if (c shl(%*2-2))or(c shr(34-%*2))and 0xffffff00=0
	encoding=0
	break
       end if
      end repeat
     end if
     macro z \\\\{
      if defined encoding & encoding = 0xf7ffffff
       literal@found=0
       repeat ($-literals@start)/4
	load literal@value word from literals@start+(%-1)*4
	if literal@value=c
	 label ..lit word at literals@start+(%-1)*4
	 literal@found=1
	 break
	end if
       end repeat
       if ~ literal@found
	..lit dW arg_pc
       end if
      end if
     \\\\}
     literal@words equ literal@words,z
    end if
   \\\}
  \\}
 \}
}

irps instr,ADC ADD AND BIC EOR ORR RSB RSC SBC SUB {
 make_dp_instr instr,,<rd,rn>
 make_dp_instr instr,s,<rd,rn>
}
irps instr,CMN CMP TST TEQ {
 make_dp_instr instr,,rn,0
}
irps instr,MOV MVN {
 make_dp_instr instr,,rd,1
 make_dp_instr instr,s,rd,1
}
purge make_dp_instr

macro make_mem_instr instr,suffix,limit {
 irp cond,,eq,ne,cs,cc,mi,pl,vs,vc,hi,ls,ge,lt,gt,le,al,hs,lo \{
  match inst,instr\#cond\#suffix\\{
   macro inst reg,[arg] \\\{
    \\\common
    \\\local off,pre,rn,bru,minus
     minus equ
     off equ
     match [r=,o],arg \\\\{
      rn equ r
      bru equ
      off equ o
      pre equ 1
     \\\\}
     match [r=,o]=!,arg \\\\{
      rn equ r
      bru equ !
      off equ o
      pre equ 1
     \\\\}
     match [r]=,o,arg \\\\{
      rn equ r
      off equ o
      pre equ 0
     \\\\}
     match ,off \\\\{
      inst reg,arg
     \\\\}
     match val:mv,off:MOV\#cond \\\\{
      if off eqtype 0
       if off>=limit | off<=-limit
	match -o,off\\\\\{
	 off equ o
	 minus equ -
	\\\\\}
	mv ip,off
	match =1,pre\\\\\{inst reg,[rn,minus ip]bru\\\\\}
	match =0,pre\\\\\{inst reg,[rn],minus ip\\\\\}
       else
	inst reg,arg
       end if
      else
       inst reg,arg
      end if
     \\\\}
   \\\}
  \\}
 \}
}
irps instr,LDR STR {
 make_mem_instr instr,,4096
 make_mem_instr instr,b,4096
 make_mem_instr instr,bt,4096
 make_mem_instr instr,t,4096
 make_mem_instr instr,h,256
 make_mem_instr instr,d,256
}
make_mem_instr LDR,sh,256
make_mem_instr LDR,sb,256

purge make_mem_instr

macro def_astring labl,[string] {
	common
	local ..db,z
	labl=..db
	macro z \{
		if defined labl
			..db dB string
		end if
	\}
	literal@astrings equ literal@astrings,z
}

macro def_ustring labl,[string] {
	common
	local ..du,z
	labl=..du
	macro z \{
		if defined labl
			align 2
			..du dU string
		end if
	\}
	literal@ustrings equ literal@ustrings,z
}

literal@words equ align 4,literals@start=$
literal@ustrings equ align 2
literal@astrings equ align 1

macro literals {
	match j,literal@words,literal@ustrings,literal@astrings\{
		irp i,j\\{
			i
		\\}
	\}
	literal@words equ align 4,literals@start=$
	literal@ustrings equ align 2
	literal@astrings equ align 1
}
