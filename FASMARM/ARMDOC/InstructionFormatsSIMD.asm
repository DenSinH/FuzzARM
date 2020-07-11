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
;To avoid unnecessary repetition only ARM mode is used
;here. There is no change needed for THUMB mode except
;to specify that the processor supports version 7M
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
;In THUMB mode all instructions can be conditional. In
;ARM mode most instructions are unconditional. The
;condition code should be added at the end of the main
;opcode and before any size/type specifiers. For
;example: "addhi" and "vaddhi.i16". The syntax also
;supports the pre-UAL style of putting the condition
;before any modifiers like "s" or "fd". For example:
;"ldmhifd", "ldmfdhi".

;This file can be assembled by fasmarm.

virtual at r1
	expression.dword	rd 1
	expression.word		rw 1
	expression.hword	rh 1
	expression.byte		rb 1
end virtual

	;***********************************************
	;SIMD, ARM mode, all instructions are 32-bit
	;***********************************************

	code32

coprocessor COPRO_SIMD_INT

	vaba.s16	d0,d1,d2
	vaba.s16	q0,q1,q2

	vaba.s32	d0,d1,d2
	vaba.s32	q0,q1,q2

	vaba.s8	d0,d1,d2
	vaba.s8	q0,q1,q2

	vaba.u16	d0,d1,d2
	vaba.u16	q0,q1,q2

	vaba.u32	d0,d1,d2
	vaba.u32	q0,q1,q2

	vaba.u8	d0,d1,d2
	vaba.u8	q0,q1,q2

	vabal.s16	q0,d1,d2

	vabal.s32	q0,d1,d2

	vabal.s8	q0,d1,d2

	vabal.u16	q0,d1,d2

	vabal.u32	q0,d1,d2

	vabal.u8	q0,d1,d2

	vabd.s16	d0,d1
	vabd.s16	d0,d1,d2
	vabd.s16	q0,q1
	vabd.s16	q0,q1,q2

	vabd.s32	d0,d1
	vabd.s32	d0,d1,d2
	vabd.s32	q0,q1
	vabd.s32	q0,q1,q2

	vabd.s8	d0,d1
	vabd.s8	d0,d1,d2
	vabd.s8	q0,q1
	vabd.s8	q0,q1,q2

	vabd.u16	d0,d1
	vabd.u16	d0,d1,d2
	vabd.u16	q0,q1
	vabd.u16	q0,q1,q2

	vabd.u32	d0,d1
	vabd.u32	d0,d1,d2
	vabd.u32	q0,q1
	vabd.u32	q0,q1,q2

	vabd.u8	d0,d1
	vabd.u8	d0,d1,d2
	vabd.u8	q0,q1
	vabd.u8	q0,q1,q2

	vabdl.s16	q0,d1,d2

	vabdl.s32	q0,d1,d2

	vabdl.s8	q0,d1,d2

	vabdl.u16	q0,d1,d2

	vabdl.u32	q0,d1,d2

	vabdl.u8	q0,d1,d2

	vabs.s16	d0,d1
	vabs.s16	q0,q1

	vabs.s32	d0,d1
	vabs.s32	q0,q1

	vabs.s8	d0,d1
	vabs.s8	q0,q1

	vadd.i16	d0,d1
	vadd.i16	d0,d1,d2
	vadd.i16	q0,q1
	vadd.i16	q0,q1,q2

	vadd.i32	d0,d1
	vadd.i32	d0,d1,d2
	vadd.i32	q0,q1
	vadd.i32	q0,q1,q2

	vadd.i64	d0,d1
	vadd.i64	d0,d1,d2
	vadd.i64	q0,q1
	vadd.i64	q0,q1,q2

	vadd.i8	d0,d1
	vadd.i8	d0,d1,d2
	vadd.i8	q0,q1
	vadd.i8	q0,q1,q2

	vaddhn.i16	d0,q1,q2

	vaddhn.i32	d0,q1,q2

	vaddhn.i64	d0,q1,q2

	vaddl.s16	q0,d1,d2

	vaddl.s32	q0,d1,d2

	vaddl.s8	q0,d1,d2

	vaddl.u16	q0,d1,d2

	vaddl.u32	q0,d1,d2

	vaddl.u8	q0,d1,d2

	vaddw.s16	q0,d1
	vaddw.s16	q0,q1,d2

	vaddw.s32	q0,d1
	vaddw.s32	q0,q1,d2

	vaddw.s8	q0,d1
	vaddw.s8	q0,q1,d2

	vaddw.u16	q0,d1
	vaddw.u16	q0,q1,d2

	vaddw.u32	q0,d1
	vaddw.u32	q0,q1,d2

	vaddw.u8	q0,d1
	vaddw.u8	q0,q1,d2

	vand	d0,d1
	vand	d0,d1,d2
	vand	q0,q1
	vand	q0,q1,q2

	vand.i16	d0,not 1
	vand.i16	q0,0xfffe

	vand.i32	d0,not 1
	vand.i32	q0,not 1

	vbic	d0,d1
	vbic	d0,d1,d2
	vbic	q0,q1
	vbic	q0,q1,q2

	vbic.i16	d0,1
	vbic.i16	q0,not -2

	vbic.i32	d0,1
	vbic.i32	q0,1

	vbif	d0,d1
	vbif	d0,d1,d2
	vbif	q0,q1
	vbif	q0,q1,q2

	vbit	d0,d1
	vbit	d0,d1,d2
	vbit	q0,q1
	vbit	q0,q1,q2

	vbsl	d0,d1
	vbsl	d0,d1,d2
	vbsl	q0,q1
	vbsl	q0,q1,q2

	vceq.i16	d0,0
	vceq.i16	d0,d1
	vceq.i16	d0,d1,0
	vceq.i16	d0,d1,d2
	vceq.i16	q0,0
	vceq.i16	q0,q1
	vceq.i16	q0,q1,0
	vceq.i16	q0,q1,q2

	vceq.i32	d0,0
	vceq.i32	d0,d1
	vceq.i32	d0,d1,0
	vceq.i32	d0,d1,d2
	vceq.i32	q0,0
	vceq.i32	q0,q1
	vceq.i32	q0,q1,0
	vceq.i32	q0,q1,q2

	vceq.i8	d0,0
	vceq.i8	d0,d1
	vceq.i8	d0,d1,0
	vceq.i8	d0,d1,d2
	vceq.i8	q0,0
	vceq.i8	q0,q1
	vceq.i8	q0,q1,0
	vceq.i8	q0,q1,q2

	vcge.s16	d0,0
	vcge.s16	d0,d1
	vcge.s16	d0,d1,0
	vcge.s16	d0,d1,d2
	vcge.s16	q0,0
	vcge.s16	q0,q1
	vcge.s16	q0,q1,0
	vcge.s16	q0,q1,q2

	vcge.s32	d0,0
	vcge.s32	d0,d1
	vcge.s32	d0,d1,0
	vcge.s32	d0,d1,d2
	vcge.s32	q0,0
	vcge.s32	q0,q1
	vcge.s32	q0,q1,0
	vcge.s32	q0,q1,q2

	vcge.s8	d0,0
	vcge.s8	d0,d1
	vcge.s8	d0,d1,0
	vcge.s8	d0,d1,d2
	vcge.s8	q0,0
	vcge.s8	q0,q1
	vcge.s8	q0,q1,0
	vcge.s8	q0,q1,q2

	vcge.u16	d0,d1
	vcge.u16	d0,d1,d2
	vcge.u16	q0,q1
	vcge.u16	q0,q1,q2

	vcge.u32	d0,d1
	vcge.u32	d0,d1,d2
	vcge.u32	q0,q1
	vcge.u32	q0,q1,q2

	vcge.u8	d0,d1
	vcge.u8	d0,d1,d2
	vcge.u8	q0,q1
	vcge.u8	q0,q1,q2

	vcgt.s16	d0,0
	vcgt.s16	d0,d1
	vcgt.s16	d0,d1,0
	vcgt.s16	d0,d1,d2
	vcgt.s16	q0,0
	vcgt.s16	q0,q1
	vcgt.s16	q0,q1,0
	vcgt.s16	q0,q1,q2

	vcgt.s32	d0,0
	vcgt.s32	d0,d1
	vcgt.s32	d0,d1,0
	vcgt.s32	d0,d1,d2
	vcgt.s32	q0,0
	vcgt.s32	q0,q1
	vcgt.s32	q0,q1,0
	vcgt.s32	q0,q1,q2

	vcgt.s8	d0,0
	vcgt.s8	d0,d1
	vcgt.s8	d0,d1,0
	vcgt.s8	d0,d1,d2
	vcgt.s8	q0,0
	vcgt.s8	q0,q1
	vcgt.s8	q0,q1,0
	vcgt.s8	q0,q1,q2

	vcgt.u16	d0,d1
	vcgt.u16	d0,d1,d2
	vcgt.u16	q0,q1
	vcgt.u16	q0,q1,q2

	vcgt.u32	d0,d1
	vcgt.u32	d0,d1,d2
	vcgt.u32	q0,q1
	vcgt.u32	q0,q1,q2

	vcgt.u8	d0,d1
	vcgt.u8	d0,d1,d2
	vcgt.u8	q0,q1
	vcgt.u8	q0,q1,q2

	vcle.s16	d0,0
	vcle.s16	d0,d1
	vcle.s16	d0,d1,0
	vcle.s16	d0,d1,d2
	vcle.s16	q0,0
	vcle.s16	q0,q1
	vcle.s16	q0,q1,0
	vcle.s16	q0,q1,q2

	vcle.s32	d0,0
	vcle.s32	d0,d1
	vcle.s32	d0,d1,0
	vcle.s32	d0,d1,d2
	vcle.s32	q0,0
	vcle.s32	q0,q1
	vcle.s32	q0,q1,0
	vcle.s32	q0,q1,q2

	vcle.s8	d0,0
	vcle.s8	d0,d1
	vcle.s8	d0,d1,0
	vcle.s8	d0,d1,d2
	vcle.s8	q0,0
	vcle.s8	q0,q1
	vcle.s8	q0,q1,0
	vcle.s8	q0,q1,q2

	vcle.u16	d0,d1
	vcle.u16	d0,d1,d2
	vcle.u16	q0,q1
	vcle.u16	q0,q1,q2

	vcle.u32	d0,d1
	vcle.u32	d0,d1,d2
	vcle.u32	q0,q1
	vcle.u32	q0,q1,q2

	vcle.u8	d0,d1
	vcle.u8	d0,d1,d2
	vcle.u8	q0,q1
	vcle.u8	q0,q1,q2

	vcls.s16	d0,d1
	vcls.s16	q0,q1

	vcls.s32	d0,d1
	vcls.s32	q0,q1

	vcls.s8	d0,d1
	vcls.s8	q0,q1

	vclt.s16	d0,0
	vclt.s16	d0,d1
	vclt.s16	d0,d1,0
	vclt.s16	d0,d1,d2
	vclt.s16	q0,0
	vclt.s16	q0,q1
	vclt.s16	q0,q1,0
	vclt.s16	q0,q1,q2

	vclt.s32	d0,0
	vclt.s32	d0,d1
	vclt.s32	d0,d1,0
	vclt.s32	d0,d1,d2
	vclt.s32	q0,0
	vclt.s32	q0,q1
	vclt.s32	q0,q1,0
	vclt.s32	q0,q1,q2

	vclt.s8	d0,0
	vclt.s8	d0,d1
	vclt.s8	d0,d1,0
	vclt.s8	d0,d1,d2
	vclt.s8	q0,0
	vclt.s8	q0,q1
	vclt.s8	q0,q1,0
	vclt.s8	q0,q1,q2

	vclt.u16	d0,d1
	vclt.u16	d0,d1,d2
	vclt.u16	q0,q1
	vclt.u16	q0,q1,q2

	vclt.u32	d0,d1
	vclt.u32	d0,d1,d2
	vclt.u32	q0,q1
	vclt.u32	q0,q1,q2

	vclt.u8	d0,d1
	vclt.u8	d0,d1,d2
	vclt.u8	q0,q1
	vclt.u8	q0,q1,q2

	vclz.i16	d0,d1
	vclz.i16	q0,q1

	vclz.i32	d0,d1
	vclz.i32	q0,q1

	vclz.i8	d0,d1
	vclz.i8	q0,q1

	vcnt.8	d0,d1
	vcnt.8	q0,q1

	vdup.16	d0,d1[0]
	vdup.16	d0,r1
	vdup.16	q0,d1[1]
	vdup.16	q0,r1

	vdup.32	d0,d1[0]
	vdup.32	d0,r1
	vdup.32	q0,d1[1]
	vdup.32	q0,r1

	vdup.8	d0,d1[0]
	vdup.8	d0,r1
	vdup.8	q0,d1[1]
	vdup.8	q0,r1

	veor	d0,d1
	veor	d0,d1,d2
	veor	q0,q1
	veor	q0,q1,q2

	vext.16	d0,d1,1
	vext.16	d0,d1,d2,1
	vext.16	q0,q1,1
	vext.16	q0,q1,q2,1

	vext.32	d0,d1,1
	vext.32	d0,d1,d2,1
	vext.32	q0,q1,1
	vext.32	q0,q1,q2,1

	vext.64	d0,d1,0
	vext.64	d0,d1,d2,0
	vext.64	q0,q1,1
	vext.64	q0,q1,q2,1

	vext.8	d0,d1,2
	vext.8	d0,d1,d2,1
	vext.8	q0,q1,2
	vext.8	q0,q1,q2,1

	vhadd.s16	d0,d1
	vhadd.s16	d0,d1,d2
	vhadd.s16	q0,q1
	vhadd.s16	q0,q1,q2

	vhadd.s32	d0,d1
	vhadd.s32	d0,d1,d2
	vhadd.s32	q0,q1
	vhadd.s32	q0,q1,q2

	vhadd.s8	d0,d1
	vhadd.s8	d0,d1,d2
	vhadd.s8	q0,q1
	vhadd.s8	q0,q1,q2

	vhadd.u16	d0,d1
	vhadd.u16	d0,d1,d2
	vhadd.u16	q0,q1
	vhadd.u16	q0,q1,q2

	vhadd.u32	d0,d1
	vhadd.u32	d0,d1,d2
	vhadd.u32	q0,q1
	vhadd.u32	q0,q1,q2

	vhadd.u8	d0,d1
	vhadd.u8	d0,d1,d2
	vhadd.u8	q0,q1
	vhadd.u8	q0,q1,q2

	vhsub.s16	d0,d1
	vhsub.s16	d0,d1,d2
	vhsub.s16	q0,q1
	vhsub.s16	q0,q1,q2

	vhsub.s32	d0,d1
	vhsub.s32	d0,d1,d2
	vhsub.s32	q0,q1
	vhsub.s32	q0,q1,q2

	vhsub.s8	d0,d1
	vhsub.s8	d0,d1,d2
	vhsub.s8	q0,q1
	vhsub.s8	q0,q1,q2

	vhsub.u16	d0,d1
	vhsub.u16	d0,d1,d2
	vhsub.u16	q0,q1
	vhsub.u16	q0,q1,q2

	vhsub.u32	d0,d1
	vhsub.u32	d0,d1,d2
	vhsub.u32	q0,q1
	vhsub.u32	q0,q1,q2

	vhsub.u8	d0,d1
	vhsub.u8	d0,d1,d2
	vhsub.u8	q0,q1
	vhsub.u8	q0,q1,q2

	vld1.16	{d0},[r1]
	vld1.16	{d0},[r1]!
	vld1.16	{d0},[r1],8
	vld1.16	{d0},[r1],r2
	vld1.16	{d0},[r1@64]
	vld1.16	{d0},[r1@64]!
	vld1.16	{d0},[r1@64],8
	vld1.16	{d0},[r1@64],r2
	vld1.16	{d0,d1},[r2]
	vld1.16	{d0,d1},[r2]!
	vld1.16	{d0,d1},[r2],16
	vld1.16	{d0,d1},[r2],r3
	vld1.16	{d0,d1},[r2@64]
	vld1.16	{d0,d1},[r2@64]!
	vld1.16	{d0,d1},[r2@64],16
	vld1.16	{d0,d1},[r2@64],r3
	vld1.16	{d0,d1,d2},[r3]
	vld1.16	{d0,d1,d2},[r3]!
	vld1.16	{d0,d1,d2},[r3],24
	vld1.16	{d0,d1,d2},[r3],r4
	vld1.16	{d0,d1,d2},[r3@64]
	vld1.16	{d0,d1,d2},[r3@64]!
	vld1.16	{d0,d1,d2},[r3@64],24
	vld1.16	{d0,d1,d2},[r3@64],r4
	vld1.16	{d0,d1,d2,d3},[r4]
	vld1.16	{d0,d1,d2,d3},[r4]!
	vld1.16	{d0,d1,d2,d3},[r4],32
	vld1.16	{d0,d1,d2,d3},[r4],r5
	vld1.16	{d0,d1,d2,d3},[r4@64]
	vld1.16	{d0,d1,d2,d3},[r4@64]!
	vld1.16	{d0,d1,d2,d3},[r4@64],32
	vld1.16	{d0,d1,d2,d3},[r4@64],r5
	vld1.16	{d0[1]},[r2]
	vld1.16	{d0[1]},[r2]!
	vld1.16	{d0[1]},[r2],2
	vld1.16	{d0[1]},[r2],r3
	vld1.16	{d0[1]},[r2@16]
	vld1.16	{d0[1]},[r2@16]!
	vld1.16	{d0[1]},[r2@16],2
	vld1.16	{d0[1]},[r2@16],r3
	vld1.16	{d0[]},[r1]
	vld1.16	{d0[]},[r1]!
	vld1.16	{d0[]},[r1],2
	vld1.16	{d0[]},[r1],r2
	vld1.16	{d0[]},[r1@16]
	vld1.16	{d0[]},[r1@16]!
	vld1.16	{d0[]},[r1@16],2
	vld1.16	{d0[]},[r1@16],r2
	vld1.16	{d0[],d1[]},[r2]
	vld1.16	{d0[],d1[]},[r2]!
	vld1.16	{d0[],d1[]},[r2],2
	vld1.16	{d0[],d1[]},[r2],r3
	vld1.16	{d0[],d1[]},[r2@16]
	vld1.16	{d0[],d1[]},[r2@16]!
	vld1.16	{d0[],d1[]},[r2@16],2
	vld1.16	{d0[],d1[]},[r2@16],r3

	vld1.32	{d0},[r1]
	vld1.32	{d0},[r1]!
	vld1.32	{d0},[r1],8
	vld1.32	{d0},[r1],r2
	vld1.32	{d0},[r1@64]
	vld1.32	{d0},[r1@64]!
	vld1.32	{d0},[r1@64],8
	vld1.32	{d0},[r1@64],r2
	vld1.32	{d0,d1},[r2]
	vld1.32	{d0,d1},[r2]!
	vld1.32	{d0,d1},[r2],16
	vld1.32	{d0,d1},[r2],r3
	vld1.32	{d0,d1},[r2@64]
	vld1.32	{d0,d1},[r2@64]!
	vld1.32	{d0,d1},[r2@64],16
	vld1.32	{d0,d1},[r2@64],r3
	vld1.32	{d0,d1,d2},[r3]
	vld1.32	{d0,d1,d2},[r3]!
	vld1.32	{d0,d1,d2},[r3],24
	vld1.32	{d0,d1,d2},[r3],r4
	vld1.32	{d0,d1,d2},[r3@64]
	vld1.32	{d0,d1,d2},[r3@64]!
	vld1.32	{d0,d1,d2},[r3@64],24
	vld1.32	{d0,d1,d2},[r3@64],r4
	vld1.32	{d0,d1,d2,d3},[r4]
	vld1.32	{d0,d1,d2,d3},[r4]!
	vld1.32	{d0,d1,d2,d3},[r4],32
	vld1.32	{d0,d1,d2,d3},[r4],r5
	vld1.32	{d0,d1,d2,d3},[r4@64]
	vld1.32	{d0,d1,d2,d3},[r4@64]!
	vld1.32	{d0,d1,d2,d3},[r4@64],32
	vld1.32	{d0,d1,d2,d3},[r4@64],r5
	vld1.32	{d0[1]},[r2]
	vld1.32	{d0[1]},[r2]!
	vld1.32	{d0[1]},[r2],4
	vld1.32	{d0[1]},[r2],r3
	vld1.32	{d0[1]},[r2@32]
	vld1.32	{d0[1]},[r2@32]!
	vld1.32	{d0[1]},[r2@32],4
	vld1.32	{d0[1]},[r2@32],r3
	vld1.32	{d0[]},[r1]
	vld1.32	{d0[]},[r1]!
	vld1.32	{d0[]},[r1],4
	vld1.32	{d0[]},[r1],r2
	vld1.32	{d0[]},[r1@32]
	vld1.32	{d0[]},[r1@32]!
	vld1.32	{d0[]},[r1@32],4
	vld1.32	{d0[]},[r1@32],r2
	vld1.32	{d0[],d1[]},[r2]
	vld1.32	{d0[],d1[]},[r2]!
	vld1.32	{d0[],d1[]},[r2],4
	vld1.32	{d0[],d1[]},[r2],r3
	vld1.32	{d0[],d1[]},[r2@32]
	vld1.32	{d0[],d1[]},[r2@32]!
	vld1.32	{d0[],d1[]},[r2@32],4
	vld1.32	{d0[],d1[]},[r2@32],r3

	vld1.64	{d0},[r1]
	vld1.64	{d0},[r1]!
	vld1.64	{d0},[r1],8
	vld1.64	{d0},[r1],r2
	vld1.64	{d0},[r1@64]
	vld1.64	{d0},[r1@64]!
	vld1.64	{d0},[r1@64],8
	vld1.64	{d0},[r1@64],r2
	vld1.64	{d0,d1},[r2]
	vld1.64	{d0,d1},[r2]!
	vld1.64	{d0,d1},[r2],16
	vld1.64	{d0,d1},[r2],r3
	vld1.64	{d0,d1},[r2@64]
	vld1.64	{d0,d1},[r2@64]!
	vld1.64	{d0,d1},[r2@64],16
	vld1.64	{d0,d1},[r2@64],r3
	vld1.64	{d0,d1,d2},[r3]
	vld1.64	{d0,d1,d2},[r3]!
	vld1.64	{d0,d1,d2},[r3],24
	vld1.64	{d0,d1,d2},[r3],r4
	vld1.64	{d0,d1,d2},[r3@64]
	vld1.64	{d0,d1,d2},[r3@64]!
	vld1.64	{d0,d1,d2},[r3@64],24
	vld1.64	{d0,d1,d2},[r3@64],r4
	vld1.64	{d0,d1,d2,d3},[r4]
	vld1.64	{d0,d1,d2,d3},[r4]!
	vld1.64	{d0,d1,d2,d3},[r4],32
	vld1.64	{d0,d1,d2,d3},[r4],r5
	vld1.64	{d0,d1,d2,d3},[r4@64]
	vld1.64	{d0,d1,d2,d3},[r4@64]!
	vld1.64	{d0,d1,d2,d3},[r4@64],32
	vld1.64	{d0,d1,d2,d3},[r4@64],r5

	vld1.8	{d0},[r1]
	vld1.8	{d0},[r1]!
	vld1.8	{d0},[r1],8
	vld1.8	{d0},[r1],r2
	vld1.8	{d0},[r1@64]
	vld1.8	{d0},[r1@64]!
	vld1.8	{d0},[r1@64],8
	vld1.8	{d0},[r1@64],r2
	vld1.8	{d0,d1},[r2]
	vld1.8	{d0,d1},[r2]!
	vld1.8	{d0,d1},[r2],16
	vld1.8	{d0,d1},[r2],r3
	vld1.8	{d0,d1},[r2@64]
	vld1.8	{d0,d1},[r2@64]!
	vld1.8	{d0,d1},[r2@64],16
	vld1.8	{d0,d1},[r2@64],r3
	vld1.8	{d0,d1,d2},[r3]
	vld1.8	{d0,d1,d2},[r3]!
	vld1.8	{d0,d1,d2},[r3],24
	vld1.8	{d0,d1,d2},[r3],r4
	vld1.8	{d0,d1,d2},[r3@64]
	vld1.8	{d0,d1,d2},[r3@64]!
	vld1.8	{d0,d1,d2},[r3@64],24
	vld1.8	{d0,d1,d2},[r3@64],r4
	vld1.8	{d0,d1,d2,d3},[r4]
	vld1.8	{d0,d1,d2,d3},[r4]!
	vld1.8	{d0,d1,d2,d3},[r4],32
	vld1.8	{d0,d1,d2,d3},[r4],r5
	vld1.8	{d0,d1,d2,d3},[r4@64]
	vld1.8	{d0,d1,d2,d3},[r4@64]!
	vld1.8	{d0,d1,d2,d3},[r4@64],32
	vld1.8	{d0,d1,d2,d3},[r4@64],r5
	vld1.8	{d0[1]},[r2]
	vld1.8	{d0[1]},[r2]!
	vld1.8	{d0[1]},[r2],1
	vld1.8	{d0[1]},[r2],r3
	vld1.8	{d0[]},[r1]
	vld1.8	{d0[]},[r1]!
	vld1.8	{d0[]},[r1],1
	vld1.8	{d0[]},[r1],r2
	vld1.8	{d0[],d1[]},[r2]
	vld1.8	{d0[],d1[]},[r2]!
	vld1.8	{d0[],d1[]},[r2],1
	vld1.8	{d0[],d1[]},[r2],r3

	vld2.16	{d0,d1},[r2]
	vld2.16	{d0,d1},[r2]!
	vld2.16	{d0,d1},[r2],16
	vld2.16	{d0,d1},[r2],r3
	vld2.16	{d0,d1},[r2@64]
	vld2.16	{d0,d1},[r2@64]!
	vld2.16	{d0,d1},[r2@64],16
	vld2.16	{d0,d1},[r2@64],r3
	vld2.16	{d0,d2},[r3]
	vld2.16	{d0,d2},[r3]!
	vld2.16	{d0,d2},[r3],16
	vld2.16	{d0,d2},[r3],r4
	vld2.16	{d0,d2},[r3@64]
	vld2.16	{d0,d2},[r3@64]!
	vld2.16	{d0,d2},[r3@64],16
	vld2.16	{d0,d2},[r3@64],r4
	vld2.16	{d0,d1,d2,d3},[r4]
	vld2.16	{d0,d1,d2,d3},[r4]!
	vld2.16	{d0,d1,d2,d3},[r4],32
	vld2.16	{d0,d1,d2,d3},[r4],r5
	vld2.16	{d0,d1,d2,d3},[r4@64]
	vld2.16	{d0,d1,d2,d3},[r4@64]!
	vld2.16	{d0,d1,d2,d3},[r4@64],32
	vld2.16	{d0,d1,d2,d3},[r4@64],r5
	vld2.16	{d0[1],d1[1]},[r2]
	vld2.16	{d0[1],d1[1]},[r2]!
	vld2.16	{d0[1],d1[1]},[r2],4
	vld2.16	{d0[1],d1[1]},[r2],r3
	vld2.16	{d0[1],d1[1]},[r2@32]
	vld2.16	{d0[1],d1[1]},[r2@32]!
	vld2.16	{d0[1],d1[1]},[r2@32],4
	vld2.16	{d0[1],d1[1]},[r2@32],r3
	vld2.16	{d0[1],d2[1]},[r2]
	vld2.16	{d0[1],d2[1]},[r2]!
	vld2.16	{d0[1],d2[1]},[r2],4
	vld2.16	{d0[1],d2[1]},[r2],r3
	vld2.16	{d0[1],d2[1]},[r2@32]
	vld2.16	{d0[1],d2[1]},[r2@32]!
	vld2.16	{d0[1],d2[1]},[r2@32],4
	vld2.16	{d0[1],d2[1]},[r2@32],r3
	vld2.16	{d0[],d1[]},[r2]
	vld2.16	{d0[],d1[]},[r2]!
	vld2.16	{d0[],d1[]},[r2],4
	vld2.16	{d0[],d1[]},[r2],r3
	vld2.16	{d0[],d1[]},[r2@32]
	vld2.16	{d0[],d1[]},[r2@32]!
	vld2.16	{d0[],d1[]},[r2@32],4
	vld2.16	{d0[],d1[]},[r2@32],r3
	vld2.16	{d0[],d2[]},[r2]
	vld2.16	{d0[],d2[]},[r2]!
	vld2.16	{d0[],d2[]},[r2],4
	vld2.16	{d0[],d2[]},[r2],r3
	vld2.16	{d0[],d2[]},[r2@32]
	vld2.16	{d0[],d2[]},[r2@32]!
	vld2.16	{d0[],d2[]},[r2@32],4
	vld2.16	{d0[],d2[]},[r2@32],r3

	vld2.32	{d0,d1},[r2]
	vld2.32	{d0,d1},[r2]!
	vld2.32	{d0,d1},[r2],16
	vld2.32	{d0,d1},[r2],r3
	vld2.32	{d0,d1},[r2@64]
	vld2.32	{d0,d1},[r2@64]!
	vld2.32	{d0,d1},[r2@64],16
	vld2.32	{d0,d1},[r2@64],r3
	vld2.32	{d0,d2},[r3]
	vld2.32	{d0,d2},[r3]!
	vld2.32	{d0,d2},[r3],16
	vld2.32	{d0,d2},[r3],r4
	vld2.32	{d0,d2},[r3@64]
	vld2.32	{d0,d2},[r3@64]!
	vld2.32	{d0,d2},[r3@64],16
	vld2.32	{d0,d2},[r3@64],r4
	vld2.32	{d0,d1,d2,d3},[r4]
	vld2.32	{d0,d1,d2,d3},[r4]!
	vld2.32	{d0,d1,d2,d3},[r4],32
	vld2.32	{d0,d1,d2,d3},[r4],r5
	vld2.32	{d0,d1,d2,d3},[r4@64]
	vld2.32	{d0,d1,d2,d3},[r4@64]!
	vld2.32	{d0,d1,d2,d3},[r4@64],32
	vld2.32	{d0,d1,d2,d3},[r4@64],r5
	vld2.32	{d0[1],d1[1]},[r2]
	vld2.32	{d0[1],d1[1]},[r2]!
	vld2.32	{d0[1],d1[1]},[r2],8
	vld2.32	{d0[1],d1[1]},[r2],r3
	vld2.32	{d0[1],d1[1]},[r2@64]
	vld2.32	{d0[1],d1[1]},[r2@64]!
	vld2.32	{d0[1],d1[1]},[r2@64],8
	vld2.32	{d0[1],d1[1]},[r2@64],r3
	vld2.32	{d0[1],d2[1]},[r2]
	vld2.32	{d0[1],d2[1]},[r2]!
	vld2.32	{d0[1],d2[1]},[r2],8
	vld2.32	{d0[1],d2[1]},[r2],r3
	vld2.32	{d0[1],d2[1]},[r2@64]
	vld2.32	{d0[1],d2[1]},[r2@64]!
	vld2.32	{d0[1],d2[1]},[r2@64],8
	vld2.32	{d0[1],d2[1]},[r2@64],r3
	vld2.32	{d0[],d1[]},[r2]
	vld2.32	{d0[],d1[]},[r2]!
	vld2.32	{d0[],d1[]},[r2],8
	vld2.32	{d0[],d1[]},[r2],r3
	vld2.32	{d0[],d1[]},[r2@64]
	vld2.32	{d0[],d1[]},[r2@64]!
	vld2.32	{d0[],d1[]},[r2@64],8
	vld2.32	{d0[],d1[]},[r2@64],r3
	vld2.32	{d0[],d2[]},[r2]
	vld2.32	{d0[],d2[]},[r2]!
	vld2.32	{d0[],d2[]},[r2],8
	vld2.32	{d0[],d2[]},[r2],r3
	vld2.32	{d0[],d2[]},[r2@64]
	vld2.32	{d0[],d2[]},[r2@64]!
	vld2.32	{d0[],d2[]},[r2@64],8
	vld2.32	{d0[],d2[]},[r2@64],r3

	vld2.8	{d0,d1},[r2]
	vld2.8	{d0,d1},[r2]!
	vld2.8	{d0,d1},[r2],16
	vld2.8	{d0,d1},[r2],r3
	vld2.8	{d0,d1},[r2@64]
	vld2.8	{d0,d1},[r2@64]!
	vld2.8	{d0,d1},[r2@64],16
	vld2.8	{d0,d1},[r2@64],r3
	vld2.8	{d0,d2},[r3]
	vld2.8	{d0,d2},[r3]!
	vld2.8	{d0,d2},[r3],16
	vld2.8	{d0,d2},[r3],r4
	vld2.8	{d0,d2},[r3@64]
	vld2.8	{d0,d2},[r3@64]!
	vld2.8	{d0,d2},[r3@64],16
	vld2.8	{d0,d2},[r3@64],r4
	vld2.8	{d0,d1,d2,d3},[r4]
	vld2.8	{d0,d1,d2,d3},[r4]!
	vld2.8	{d0,d1,d2,d3},[r4],32
	vld2.8	{d0,d1,d2,d3},[r4],r5
	vld2.8	{d0,d1,d2,d3},[r4@64]
	vld2.8	{d0,d1,d2,d3},[r4@64]!
	vld2.8	{d0,d1,d2,d3},[r4@64],32
	vld2.8	{d0,d1,d2,d3},[r4@64],r5
	vld2.8	{d0[1],d1[1]},[r2]
	vld2.8	{d0[1],d1[1]},[r2]!
	vld2.8	{d0[1],d1[1]},[r2],2
	vld2.8	{d0[1],d1[1]},[r2],r3
	vld2.8	{d0[1],d1[1]},[r2@16]
	vld2.8	{d0[1],d1[1]},[r2@16]!
	vld2.8	{d0[1],d1[1]},[r2@16],2
	vld2.8	{d0[1],d1[1]},[r2@16],r3
	vld2.8	{d0[],d1[]},[r2]
	vld2.8	{d0[],d1[]},[r2]!
	vld2.8	{d0[],d1[]},[r2],2
	vld2.8	{d0[],d1[]},[r2],r3
	vld2.8	{d0[],d1[]},[r2@16]
	vld2.8	{d0[],d1[]},[r2@16]!
	vld2.8	{d0[],d1[]},[r2@16],2
	vld2.8	{d0[],d1[]},[r2@16],r3
	vld2.8	{d0[],d2[]},[r2]
	vld2.8	{d0[],d2[]},[r2]!
	vld2.8	{d0[],d2[]},[r2],2
	vld2.8	{d0[],d2[]},[r2],r3
	vld2.8	{d0[],d2[]},[r2@16]
	vld2.8	{d0[],d2[]},[r2@16]!
	vld2.8	{d0[],d2[]},[r2@16],2
	vld2.8	{d0[],d2[]},[r2@16],r3

	vld3.16	{d0,d1,d2},[r2]
	vld3.16	{d0,d1,d2},[r2]!
	vld3.16	{d0,d1,d2},[r2],24
	vld3.16	{d0,d1,d2},[r2],r3
	vld3.16	{d0,d1,d2},[r2@64]
	vld3.16	{d0,d1,d2},[r2@64]!
	vld3.16	{d0,d1,d2},[r2@64],24
	vld3.16	{d0,d1,d2},[r2@64],r3
	vld3.16	{d0,d2,d4},[r3]
	vld3.16	{d0,d2,d4},[r3]!
	vld3.16	{d0,d2,d4},[r3],24
	vld3.16	{d0,d2,d4},[r3],r4
	vld3.16	{d0,d2,d4},[r3@64]
	vld3.16	{d0,d2,d4},[r3@64]!
	vld3.16	{d0,d2,d4},[r3@64],24
	vld3.16	{d0,d2,d4},[r3@64],r4
	vld3.16	{d0[1],d1[1],d2[1]},[r2]
	vld3.16	{d0[1],d1[1],d2[1]},[r2]!
	vld3.16	{d0[1],d1[1],d2[1]},[r2],6
	vld3.16	{d0[1],d1[1],d2[1]},[r2],r3
	vld3.16	{d0[1],d2[1],d4[1]},[r2]
	vld3.16	{d0[1],d2[1],d4[1]},[r2]!
	vld3.16	{d0[1],d2[1],d4[1]},[r2],6
	vld3.16	{d0[1],d2[1],d4[1]},[r2],r3
	vld3.16	{d0[],d1[],d2[]},[r2]
	vld3.16	{d0[],d1[],d2[]},[r2]!
	vld3.16	{d0[],d1[],d2[]},[r2],6
	vld3.16	{d0[],d1[],d2[]},[r2],r3
	vld3.16	{d0[],d2[],d4[]},[r2]
	vld3.16	{d0[],d2[],d4[]},[r2]!
	vld3.16	{d0[],d2[],d4[]},[r2],6
	vld3.16	{d0[],d2[],d4[]},[r2],r3

	vld3.32	{d0,d1,d2},[r2]
	vld3.32	{d0,d1,d2},[r2]!
	vld3.32	{d0,d1,d2},[r2],24
	vld3.32	{d0,d1,d2},[r2],r3
	vld3.32	{d0,d1,d2},[r2@64]
	vld3.32	{d0,d1,d2},[r2@64]!
	vld3.32	{d0,d1,d2},[r2@64],24
	vld3.32	{d0,d1,d2},[r2@64],r3
	vld3.32	{d0,d2,d4},[r3]
	vld3.32	{d0,d2,d4},[r3]!
	vld3.32	{d0,d2,d4},[r3],24
	vld3.32	{d0,d2,d4},[r3],r4
	vld3.32	{d0,d2,d4},[r3@64]
	vld3.32	{d0,d2,d4},[r3@64]!
	vld3.32	{d0,d2,d4},[r3@64],24
	vld3.32	{d0,d2,d4},[r3@64],r4
	vld3.32	{d0[1],d1[1],d2[1]},[r2]
	vld3.32	{d0[1],d1[1],d2[1]},[r2]!
	vld3.32	{d0[1],d1[1],d2[1]},[r2],12
	vld3.32	{d0[1],d1[1],d2[1]},[r2],r3
	vld3.32	{d0[1],d2[1],d4[1]},[r2]
	vld3.32	{d0[1],d2[1],d4[1]},[r2]!
	vld3.32	{d0[1],d2[1],d4[1]},[r2],12
	vld3.32	{d0[1],d2[1],d4[1]},[r2],r3
	vld3.32	{d0[],d1[],d2[]},[r2]
	vld3.32	{d0[],d1[],d2[]},[r2]!
	vld3.32	{d0[],d1[],d2[]},[r2],12
	vld3.32	{d0[],d1[],d2[]},[r2],r3
	vld3.32	{d0[],d2[],d4[]},[r2]
	vld3.32	{d0[],d2[],d4[]},[r2]!
	vld3.32	{d0[],d2[],d4[]},[r2],12
	vld3.32	{d0[],d2[],d4[]},[r2],r3

	vld3.8	{d0,d1,d2},[r2]
	vld3.8	{d0,d1,d2},[r2]!
	vld3.8	{d0,d1,d2},[r2],24
	vld3.8	{d0,d1,d2},[r2],r3
	vld3.8	{d0,d1,d2},[r2@64]
	vld3.8	{d0,d1,d2},[r2@64]!
	vld3.8	{d0,d1,d2},[r2@64],24
	vld3.8	{d0,d1,d2},[r2@64],r3
	vld3.8	{d0,d2,d4},[r3]
	vld3.8	{d0,d2,d4},[r3]!
	vld3.8	{d0,d2,d4},[r3],24
	vld3.8	{d0,d2,d4},[r3],r4
	vld3.8	{d0,d2,d4},[r3@64]
	vld3.8	{d0,d2,d4},[r3@64]!
	vld3.8	{d0,d2,d4},[r3@64],24
	vld3.8	{d0,d2,d4},[r3@64],r4
	vld3.8	{d0[1],d1[1],d2[1]},[r2]
	vld3.8	{d0[1],d1[1],d2[1]},[r2]!
	vld3.8	{d0[1],d1[1],d2[1]},[r2],3
	vld3.8	{d0[1],d1[1],d2[1]},[r2],r3
	vld3.8	{d0[],d1[],d2[]},[r2]
	vld3.8	{d0[],d1[],d2[]},[r2]!
	vld3.8	{d0[],d1[],d2[]},[r2],3
	vld3.8	{d0[],d1[],d2[]},[r2],r3
	vld3.8	{d0[],d2[],d4[]},[r2]
	vld3.8	{d0[],d2[],d4[]},[r2]!
	vld3.8	{d0[],d2[],d4[]},[r2],3
	vld3.8	{d0[],d2[],d4[]},[r2],r3

	vld4.16	{d0,d1,d2,d3},[r4]
	vld4.16	{d0,d1,d2,d3},[r4]!
	vld4.16	{d0,d1,d2,d3},[r4],32
	vld4.16	{d0,d1,d2,d3},[r4],r5
	vld4.16	{d0,d1,d2,d3},[r4@64]
	vld4.16	{d0,d1,d2,d3},[r4@64]!
	vld4.16	{d0,d1,d2,d3},[r4@64],32
	vld4.16	{d0,d1,d2,d3},[r4@64],r5
	vld4.16	{d0,d2,d4,d6},[r4]
	vld4.16	{d0,d2,d4,d6},[r4]!
	vld4.16	{d0,d2,d4,d6},[r4],32
	vld4.16	{d0,d2,d4,d6},[r4],r5
	vld4.16	{d0,d2,d4,d6},[r4@64]
	vld4.16	{d0,d2,d4,d6},[r4@64]!
	vld4.16	{d0,d2,d4,d6},[r4@64],32
	vld4.16	{d0,d2,d4,d6},[r4@64],r5
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2]
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2]!
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2],8
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2],r3
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64]
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64]!
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64],8
	vld4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64],r3
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2]
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2]!
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2],8
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2],r3
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64]
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64]!
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64],8
	vld4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64],r3
	vld4.16	{d0[],d1[],d2[],d3[]},[r2]
	vld4.16	{d0[],d1[],d2[],d3[]},[r2]!
	vld4.16	{d0[],d1[],d2[],d3[]},[r2],8
	vld4.16	{d0[],d1[],d2[],d3[]},[r2],r3
	vld4.16	{d0[],d1[],d2[],d3[]},[r2@64]
	vld4.16	{d0[],d1[],d2[],d3[]},[r2@64]!
	vld4.16	{d0[],d1[],d2[],d3[]},[r2@64],8
	vld4.16	{d0[],d1[],d2[],d3[]},[r2@64],r3
	vld4.16	{d0[],d2[],d4[],d6[]},[r2]
	vld4.16	{d0[],d2[],d4[],d6[]},[r2]!
	vld4.16	{d0[],d2[],d4[],d6[]},[r2],8
	vld4.16	{d0[],d2[],d4[],d6[]},[r2],r3
	vld4.16	{d0[],d2[],d4[],d6[]},[r2@64]
	vld4.16	{d0[],d2[],d4[],d6[]},[r2@64]!
	vld4.16	{d0[],d2[],d4[],d6[]},[r2@64],8
	vld4.16	{d0[],d2[],d4[],d6[]},[r2@64],r3

	vld4.32	{d0,d1,d2,d3},[r4]
	vld4.32	{d0,d1,d2,d3},[r4]!
	vld4.32	{d0,d1,d2,d3},[r4],32
	vld4.32	{d0,d1,d2,d3},[r4],r5
	vld4.32	{d0,d1,d2,d3},[r4@64]
	vld4.32	{d0,d1,d2,d3},[r4@64]!
	vld4.32	{d0,d1,d2,d3},[r4@64],32
	vld4.32	{d0,d1,d2,d3},[r4@64],r5
	vld4.32	{d0,d2,d4,d6},[r4]
	vld4.32	{d0,d2,d4,d6},[r4]!
	vld4.32	{d0,d2,d4,d6},[r4],32
	vld4.32	{d0,d2,d4,d6},[r4],r5
	vld4.32	{d0,d2,d4,d6},[r4@64]
	vld4.32	{d0,d2,d4,d6},[r4@64]!
	vld4.32	{d0,d2,d4,d6},[r4@64],32
	vld4.32	{d0,d2,d4,d6},[r4@64],r5
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2]
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2]!
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2],16
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2],r3
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64]
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64]!
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64],16
	vld4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64],r3
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2]
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2]!
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2],16
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2],r3
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64]
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64]!
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64],16
	vld4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64],r3
	vld4.32	{d0[],d1[],d2[],d3[]},[r2]
	vld4.32	{d0[],d1[],d2[],d3[]},[r2]!
	vld4.32	{d0[],d1[],d2[],d3[]},[r2],16
	vld4.32	{d0[],d1[],d2[],d3[]},[r2],r3
	vld4.32	{d0[],d1[],d2[],d3[]},[r2@64]
	vld4.32	{d0[],d1[],d2[],d3[]},[r2@64]!
	vld4.32	{d0[],d1[],d2[],d3[]},[r2@64],16
	vld4.32	{d0[],d1[],d2[],d3[]},[r2@64],r3
	vld4.32	{d0[],d2[],d4[],d6[]},[r2]
	vld4.32	{d0[],d2[],d4[],d6[]},[r2]!
	vld4.32	{d0[],d2[],d4[],d6[]},[r2],16
	vld4.32	{d0[],d2[],d4[],d6[]},[r2],r3
	vld4.32	{d0[],d2[],d4[],d6[]},[r2@64]
	vld4.32	{d0[],d2[],d4[],d6[]},[r2@64]!
	vld4.32	{d0[],d2[],d4[],d6[]},[r2@64],16
	vld4.32	{d0[],d2[],d4[],d6[]},[r2@64],r3

	vld4.8	{d0,d1,d2,d3},[r4]
	vld4.8	{d0,d1,d2,d3},[r4]!
	vld4.8	{d0,d1,d2,d3},[r4],32
	vld4.8	{d0,d1,d2,d3},[r4],r5
	vld4.8	{d0,d1,d2,d3},[r4@64]
	vld4.8	{d0,d1,d2,d3},[r4@64]!
	vld4.8	{d0,d1,d2,d3},[r4@64],32
	vld4.8	{d0,d1,d2,d3},[r4@64],r5
	vld4.8	{d0,d2,d4,d6},[r4]
	vld4.8	{d0,d2,d4,d6},[r4]!
	vld4.8	{d0,d2,d4,d6},[r4],32
	vld4.8	{d0,d2,d4,d6},[r4],r5
	vld4.8	{d0,d2,d4,d6},[r4@64]
	vld4.8	{d0,d2,d4,d6},[r4@64]!
	vld4.8	{d0,d2,d4,d6},[r4@64],32
	vld4.8	{d0,d2,d4,d6},[r4@64],r5
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2]
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2]!
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2],4
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2],r3
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32]
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32]!
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32],4
	vld4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32],r3
	vld4.8	{d0[],d1[],d2[],d3[]},[r2]
	vld4.8	{d0[],d1[],d2[],d3[]},[r2]!
	vld4.8	{d0[],d1[],d2[],d3[]},[r2],4
	vld4.8	{d0[],d1[],d2[],d3[]},[r2],r3
	vld4.8	{d0[],d1[],d2[],d3[]},[r2@32]
	vld4.8	{d0[],d1[],d2[],d3[]},[r2@32]!
	vld4.8	{d0[],d1[],d2[],d3[]},[r2@32],4
	vld4.8	{d0[],d1[],d2[],d3[]},[r2@32],r3
	vld4.8	{d0[],d2[],d4[],d6[]},[r2]
	vld4.8	{d0[],d2[],d4[],d6[]},[r2]!
	vld4.8	{d0[],d2[],d4[],d6[]},[r2],4
	vld4.8	{d0[],d2[],d4[],d6[]},[r2],r3
	vld4.8	{d0[],d2[],d4[],d6[]},[r2@32]
	vld4.8	{d0[],d2[],d4[],d6[]},[r2@32]!
	vld4.8	{d0[],d2[],d4[],d6[]},[r2@32],4
	vld4.8	{d0[],d2[],d4[],d6[]},[r2@32],r3

	vmax.s16	d0,d1
	vmax.s16	d0,d1,d2
	vmax.s16	q0,q1
	vmax.s16	q0,q1,q2

	vmax.s32	d0,d1
	vmax.s32	d0,d1,d2
	vmax.s32	q0,q1
	vmax.s32	q0,q1,q2

	vmax.s8	d0,d1
	vmax.s8	d0,d1,d2
	vmax.s8	q0,q1
	vmax.s8	q0,q1,q2

	vmax.u16	d0,d1
	vmax.u16	d0,d1,d2
	vmax.u16	q0,q1
	vmax.u16	q0,q1,q2

	vmax.u32	d0,d1
	vmax.u32	d0,d1,d2
	vmax.u32	q0,q1
	vmax.u32	q0,q1,q2

	vmax.u8	d0,d1
	vmax.u8	d0,d1,d2
	vmax.u8	q0,q1
	vmax.u8	q0,q1,q2

	vmin.s16	d0,d1
	vmin.s16	d0,d1,d2
	vmin.s16	q0,q1
	vmin.s16	q0,q1,q2

	vmin.s32	d0,d1
	vmin.s32	d0,d1,d2
	vmin.s32	q0,q1
	vmin.s32	q0,q1,q2

	vmin.s8	d0,d1
	vmin.s8	d0,d1,d2
	vmin.s8	q0,q1
	vmin.s8	q0,q1,q2

	vmin.u16	d0,d1
	vmin.u16	d0,d1,d2
	vmin.u16	q0,q1
	vmin.u16	q0,q1,q2

	vmin.u32	d0,d1
	vmin.u32	d0,d1,d2
	vmin.u32	q0,q1
	vmin.u32	q0,q1,q2

	vmin.u8	d0,d1
	vmin.u8	d0,d1,d2
	vmin.u8	q0,q1
	vmin.u8	q0,q1,q2

	vmla.i16	d0,d1,d2
	vmla.i16	d0,d1,d2[0]
	vmla.i16	q0,q1,q2
	vmla.i16	q0,q1,d2[1]

	vmla.i32	d0,d1,d2
	vmla.i32	d0,d1,d2[0]
	vmla.i32	q0,q1,q2
	vmla.i32	q0,q1,d2[1]

	vmla.i8	d0,d1,d2
	vmla.i8	q0,q1,q2

	vmla.s16	d0,d1,d2
	vmla.s16	q0,q1,q2

	vmla.s32	d0,d1,d2
	vmla.s32	q0,q1,q2

	vmla.s8	d0,d1,d2
	vmla.s8	q0,q1,q2

	vmla.u16	d0,d1,d2
	vmla.u16	q0,q1,q2

	vmla.u32	d0,d1,d2
	vmla.u32	q0,q1,q2

	vmla.u8	d0,d1,d2
	vmla.u8	q0,q1,q2

	vmlal.s16	q0,d1,d2
	vmlal.s16	q0,d1,d2[0]

	vmlal.s32	q0,d1,d2
	vmlal.s32	q0,d1,d2[0]

	vmlal.s8	q0,d1,d2

	vmlal.u16	q0,d1,d2
	vmlal.u16	q0,d1,d2[1]

	vmlal.u32	q0,d1,d2
	vmlal.u32	q0,d1,d2[0]

	vmlal.u8	q0,d1,d2

	vmls.i16	d0,d1,d2
	vmls.i16	d0,d1,d2[0]
	vmls.i16	q0,q1,q2
	vmls.i16	q0,q1,d2[1]

	vmls.i32	d0,d1,d2
	vmls.i32	d0,d1,d2[0]
	vmls.i32	q0,q1,q2
	vmls.i32	q0,q1,d2[1]

	vmls.i8	d0,d1,d2
	vmls.i8	q0,q1,q2

	vmls.s16	d0,d1,d2
	vmls.s16	q0,q1,q2

	vmls.s32	d0,d1,d2
	vmls.s32	q0,q1,q2

	vmls.s8	d0,d1,d2
	vmls.s8	q0,q1,q2

	vmls.u16	d0,d1,d2
	vmls.u16	q0,q1,q2

	vmls.u32	d0,d1,d2
	vmls.u32	q0,q1,q2

	vmls.u8	d0,d1,d2
	vmls.u8	q0,q1,q2

	vmlsl.s16	q0,d1,d2
	vmlsl.s16	q0,d1,d2[1]

	vmlsl.s32	q0,d1,d2
	vmlsl.s32	q0,d1,d2[0]

	vmlsl.s8	q0,d1,d2

	vmlsl.u16	q0,d1,d2
	vmlsl.u16	q0,d1,d2[1]

	vmlsl.u32	q0,d1,d2
	vmlsl.u32	q0,d1,d2[0]

	vmlsl.u8	q0,d1,d2

	vmov	d0,d1
	vmov	q0,q1

	vmov.16	d0[1],r1

	vmov.8	d0[1],r1

	vmov.i16	d0,1
	vmov.i16	q0,1

	vmov.i32	d0,1
	vmov.i32	q0,1

	vmov.i64	d0,1
	vmov.i64	q0,1

	vmov.i8	d0,1
	vmov.i8	q0,1

	vmov.s16	r0,d1[1]

	vmov.s8	r0,d1[1]

	vmov.u16	r0,d1[1]

	vmov.u8	r0,d1[1]

	vmovl.s16	q0,d1

	vmovl.s32	q0,d1

	vmovl.s8	q0,d1

	vmovl.u16	q0,d1

	vmovl.u32	q0,d1

	vmovl.u8	q0,d1

	vmovn.i16	d0,q1

	vmovn.i32	d0,q1

	vmovn.i8	d0,q1

	vmul.i16	d0,d1
	vmul.i16	d0,d1,d2
	vmul.i16	d0,d1[1]
	vmul.i16	d0,d1,d2[1]
	vmul.i16	q0,q1
	vmul.i16	q0,q1,q2
	vmul.i16	q0,d1[1]
	vmul.i16	q0,q1,d2[1]

	vmul.i32	d0,d1
	vmul.i32	d0,d1,d2
	vmul.i32	d0,d1[0]
	vmul.i32	d0,d1,d2[0]
	vmul.i32	q0,q1
	vmul.i32	q0,q1,q2
	vmul.i32	q0,d1[0]
	vmul.i32	q0,q1,d2[0]

	vmul.i8	d0,d1
	vmul.i8	d0,d1,d2
	vmul.i8	q0,q1
	vmul.i8	q0,q1,q2

	vmul.p8	d0,d1
	vmul.p8	d0,d1,d2

	vmul.s16	d0,d1
	vmul.s16	d0,d1,d2

	vmul.s32	d0,d1
	vmul.s32	d0,d1,d2

	vmul.s8	d0,d1
	vmul.s8	d0,d1,d2
	vmul.s8	q0,q1
	vmul.s8	q0,q1,q2

	vmul.u16	d0,d1
	vmul.u16	d0,d1,d2

	vmul.u32	d0,d1
	vmul.u32	d0,d1,d2

	vmul.u8	d0,d1
	vmul.u8	d0,d1,d2
	vmul.u8	q0,q1
	vmul.u8	q0,q1,q2

	vmull.p8	q0,d1,d2

	vmull.s16	q0,d1,d2
	vmull.s16	q0,d1,d2[0]

	vmull.s32	q0,d1,d2
	vmull.s32	q0,d1,d2[0]

	vmull.s8	q0,d1,d2

	vmull.u16	q0,d1,d2
	vmull.u16	q0,d1,d2[1]

	vmull.u32	q0,d1,d2
	vmull.u32	q0,d1,d2[0]

	vmull.u8	q0,d1,d2

	vmvn	d0,d1
	vmvn	q0,q1

	vmvn.i16	d0,1
	vmvn.i16	q0,1

	vmvn.i32	d0,1
	vmvn.i32	q0,1

	vneg.s16	d0,d1
	vneg.s16	q0,q1

	vneg.s32	d0,d1
	vneg.s32	q0,q1

	vneg.s8	d0,d1
	vneg.s8	q0,q1

	vorn	d0,d1
	vorn	d0,d1,d2
	vorn	q0,q1
	vorn	q0,q1,q2

	vorn.i16	d0,not 1
	vorn.i16	q0,0xfffe

	vorn.i32	d0,not 1
	vorn.i32	q0,not 1

	vorr	d0,d1
	vorr	d0,d1,d2
	vorr	q0,q1
	vorr	q0,q1,q2

	vorr.i16	d0,1
	vorr.i16	q0,not -2

	vorr.i32	d0,1
	vorr.i32	q0,1

	vpadal.s16	d0,d1
	vpadal.s16	q0,q1

	vpadal.s32	d0,d1
	vpadal.s32	q0,q1

	vpadal.s8	d0,d1
	vpadal.s8	q0,q1

	vpadal.u16	d0,d1
	vpadal.u16	q0,q1

	vpadal.u32	d0,d1
	vpadal.u32	q0,q1

	vpadal.u8	d0,d1
	vpadal.u8	q0,q1

	vpadd.i16	d0,d1
	vpadd.i16	d0,d1,d2

	vpadd.i32	d0,d1
	vpadd.i32	d0,d1,d2

	vpadd.i8	d0,d1
	vpadd.i8	d0,d1,d2

	vpaddl.s16	d0,d1
	vpaddl.s16	q0,q1

	vpaddl.s32	d0,d1
	vpaddl.s32	q0,q1

	vpaddl.s8	d0,d1
	vpaddl.s8	q0,q1

	vpaddl.u16	d0,d1
	vpaddl.u16	q0,q1

	vpaddl.u32	d0,d1
	vpaddl.u32	q0,q1

	vpaddl.u8	d0,d1
	vpaddl.u8	q0,q1

	vpmax.s16	d0,d1
	vpmax.s16	d0,d1,d2

	vpmax.s32	d0,d1
	vpmax.s32	d0,d1,d2

	vpmax.s8	d0,d1
	vpmax.s8	d0,d1,d2

	vpmax.u16	d0,d1
	vpmax.u16	d0,d1,d2

	vpmax.u32	d0,d1
	vpmax.u32	d0,d1,d2

	vpmax.u8	d0,d1
	vpmax.u8	d0,d1,d2

	vpmin.s16	d0,d1
	vpmin.s16	d0,d1,d2

	vpmin.s32	d0,d1
	vpmin.s32	d0,d1,d2

	vpmin.s8	d0,d1
	vpmin.s8	d0,d1,d2

	vpmin.u16	d0,d1
	vpmin.u16	d0,d1,d2

	vpmin.u32	d0,d1
	vpmin.u32	d0,d1,d2

	vpmin.u8	d0,d1
	vpmin.u8	d0,d1,d2

	vqabs.s16	d0,d1
	vqabs.s16	q0,q1

	vqabs.s32	d0,d1
	vqabs.s32	q0,q1

	vqabs.s8	d0,d1
	vqabs.s8	q0,q1

	vqadd.s16	d0,d1
	vqadd.s16	d0,d1,d2
	vqadd.s16	q0,q1
	vqadd.s16	q0,q1,q2

	vqadd.s32	d0,d1
	vqadd.s32	d0,d1,d2
	vqadd.s32	q0,q1
	vqadd.s32	q0,q1,q2

	vqadd.s64	d0,d1
	vqadd.s64	d0,d1,d2
	vqadd.s64	q0,q1
	vqadd.s64	q0,q1,q2

	vqadd.s8	d0,d1
	vqadd.s8	d0,d1,d2
	vqadd.s8	q0,q1
	vqadd.s8	q0,q1,q2

	vqadd.u16	d0,d1
	vqadd.u16	d0,d1,d2
	vqadd.u16	q0,q1
	vqadd.u16	q0,q1,q2

	vqadd.u32	d0,d1
	vqadd.u32	d0,d1,d2
	vqadd.u32	q0,q1
	vqadd.u32	q0,q1,q2

	vqadd.u64	d0,d1
	vqadd.u64	d0,d1,d2
	vqadd.u64	q0,q1
	vqadd.u64	q0,q1,q2

	vqadd.u8	d0,d1
	vqadd.u8	d0,d1,d2
	vqadd.u8	q0,q1
	vqadd.u8	q0,q1,q2

	vqdmlal.s16	q0,d1,d2
	vqdmlal.s16	q0,d1,d2[0]

	vqdmlal.s32	q0,d1,d2
	vqdmlal.s32	q0,d1,d2[0]

	vqdmlsl.s16	q0,d1,d2
	vqdmlsl.s16	q0,d1,d2[0]

	vqdmlsl.s32	q0,d1,d2
	vqdmlsl.s32	q0,d1,d2[0]

	vqdmulh.s16	d0,d1
	vqdmulh.s16	d0,d1,d2
	vqdmulh.s16	d0,d1[1]
	vqdmulh.s16	d0,d1,d2[1]
	vqdmulh.s16	q0,q1
	vqdmulh.s16	q0,q1,q2
	vqdmulh.s16	q0,d1[1]
	vqdmulh.s16	q0,q1,d2[1]

	vqdmulh.s32	d0,d1
	vqdmulh.s32	d0,d1,d2
	vqdmulh.s32	d0,d1[0]
	vqdmulh.s32	d0,d1,d2[0]
	vqdmulh.s32	q0,q1
	vqdmulh.s32	q0,q1,q2
	vqdmulh.s32	q0,d1[0]
	vqdmulh.s32	q0,q1,d2[0]

	vqdmull.s16	q0,d1,d2
	vqdmull.s16	q0,d1,d2[0]

	vqdmull.s32	q0,d1,d2
	vqdmull.s32	q0,d1,d2[0]

	vqmovn.s16	d0,q1

	vqmovn.s32	d0,q1

	vqmovn.s64	d0,q1

	vqmovn.u16	d0,q1

	vqmovn.u32	d0,q1

	vqmovn.u64	d0,q1

	vqmovun.s16	d0,q1

	vqmovun.s32	d0,q1

	vqmovun.s64	d0,q1

	vqneg.s16	d0,d1
	vqneg.s16	q0,q1

	vqneg.s32	d0,d1
	vqneg.s32	q0,q1

	vqneg.s8	d0,d1
	vqneg.s8	q0,q1

	vqrdmulh.s16	d0,d1
	vqrdmulh.s16	d0,d1,d2
	vqrdmulh.s16	d0,d1[1]
	vqrdmulh.s16	d0,d1,d2[1]
	vqrdmulh.s16	q0,q1
	vqrdmulh.s16	q0,q1,q2
	vqrdmulh.s16	q0,d1[1]
	vqrdmulh.s16	q0,q1,d2[1]

	vqrdmulh.s32	d0,d1
	vqrdmulh.s32	d0,d1,d2
	vqrdmulh.s32	d0,d1[0]
	vqrdmulh.s32	d0,d1,d2[0]
	vqrdmulh.s32	q0,q1
	vqrdmulh.s32	q0,q1,q2
	vqrdmulh.s32	q0,d1[0]
	vqrdmulh.s32	q0,q1,d1[0]

	vqrshl.s16	d0,d1
	vqrshl.s16	d0,d1,d2
	vqrshl.s16	q0,q1
	vqrshl.s16	q0,q1,q2

	vqrshl.s32	d0,d1
	vqrshl.s32	d0,d1,d2
	vqrshl.s32	q0,q1
	vqrshl.s32	q0,q1,q2

	vqrshl.s64	d0,d1
	vqrshl.s64	d0,d1,d2
	vqrshl.s64	q0,q1
	vqrshl.s64	q0,q1,q2

	vqrshl.s8	d0,d1
	vqrshl.s8	d0,d1,d2
	vqrshl.s8	q0,q1
	vqrshl.s8	q0,q1,q2

	vqrshl.u16	d0,d1
	vqrshl.u16	d0,d1,d2
	vqrshl.u16	q0,q1
	vqrshl.u16	q0,q1,q2

	vqrshl.u32	d0,d1
	vqrshl.u32	d0,d1,d2
	vqrshl.u32	q0,q1
	vqrshl.u32	q0,q1,q2

	vqrshl.u64	d0,d1
	vqrshl.u64	d0,d1,d2
	vqrshl.u64	q0,q1
	vqrshl.u64	q0,q1,q2

	vqrshl.u8	d0,d1
	vqrshl.u8	d0,d1,d2
	vqrshl.u8	q0,q1
	vqrshl.u8	q0,q1,q2

	vqrshrn.s16	d0,q1,1

	vqrshrn.s32	d0,q1,1

	vqrshrn.s64	d0,q1,1

	vqrshrn.u16	d0,q1,1

	vqrshrn.u32	d0,q1,1

	vqrshrn.u64	d0,q1,1

	vqrshrun.s16	d0,q1,1

	vqrshrun.s32	d0,q1,1

	vqrshrun.s64	d0,q1,1

	vqshl.s16	d0,1
	vqshl.s16	d0,d1
	vqshl.s16	d0,d1,1
	vqshl.s16	d0,d1,d2
	vqshl.s16	q0,1
	vqshl.s16	q0,q1
	vqshl.s16	q0,q1,1
	vqshl.s16	q0,q1,q2

	vqshl.s32	d0,1
	vqshl.s32	d0,d1
	vqshl.s32	d0,d1,1
	vqshl.s32	d0,d1,d2
	vqshl.s32	q0,1
	vqshl.s32	q0,q1
	vqshl.s32	q0,q1,1
	vqshl.s32	q0,q1,q2

	vqshl.s64	d0,1
	vqshl.s64	d0,d1
	vqshl.s64	d0,d1,1
	vqshl.s64	d0,d1,d2
	vqshl.s64	q0,1
	vqshl.s64	q0,q1
	vqshl.s64	q0,q1,1
	vqshl.s64	q0,q1,q2

	vqshl.s8	d0,1
	vqshl.s8	d0,d1
	vqshl.s8	d0,d1,1
	vqshl.s8	d0,d1,d2
	vqshl.s8	q0,1
	vqshl.s8	q0,q1
	vqshl.s8	q0,q1,1
	vqshl.s8	q0,q1,q2

	vqshl.u16	d0,1
	vqshl.u16	d0,d1
	vqshl.u16	d0,d1,1
	vqshl.u16	d0,d1,d2
	vqshl.u16	q0,1
	vqshl.u16	q0,q1
	vqshl.u16	q0,q1,1
	vqshl.u16	q0,q1,q2

	vqshl.u32	d0,1
	vqshl.u32	d0,d1
	vqshl.u32	d0,d1,1
	vqshl.u32	d0,d1,d2
	vqshl.u32	q0,1
	vqshl.u32	q0,q1
	vqshl.u32	q0,q1,1
	vqshl.u32	q0,q1,q2

	vqshl.u64	d0,1
	vqshl.u64	d0,d1
	vqshl.u64	d0,d1,1
	vqshl.u64	d0,d1,d2
	vqshl.u64	q0,1
	vqshl.u64	q0,q1
	vqshl.u64	q0,q1,1
	vqshl.u64	q0,q1,q2

	vqshl.u8	d0,1
	vqshl.u8	d0,d1
	vqshl.u8	d0,d1,1
	vqshl.u8	d0,d1,d2
	vqshl.u8	q0,1
	vqshl.u8	q0,q1
	vqshl.u8	q0,q1,1
	vqshl.u8	q0,q1,q2

	vqshlu.s16	d0,1
	vqshlu.s16	d0,d1,1
	vqshlu.s16	q0,1
	vqshlu.s16	q0,q1,1

	vqshlu.s32	d0,1
	vqshlu.s32	d0,d1,1
	vqshlu.s32	q0,1
	vqshlu.s32	q0,q1,1

	vqshlu.s64	d0,1
	vqshlu.s64	d0,d1,1
	vqshlu.s64	q0,1
	vqshlu.s64	q0,q1,1

	vqshlu.s8	d0,1
	vqshlu.s8	d0,d1,1
	vqshlu.s8	q0,1
	vqshlu.s8	q0,q1,1

	vqshrn.s16	d0,q1,1

	vqshrn.s32	d0,q1,1

	vqshrn.s64	d0,q1,1

	vqshrn.u16	d0,q1,1

	vqshrn.u32	d0,q1,1

	vqshrn.u64	d0,q1,1

	vqshrun.s16	d0,q1,1

	vqshrun.s32	d0,q1,1

	vqshrun.s64	d0,q1,1

	vqsub.s16	d0,d1
	vqsub.s16	d0,d1,d2
	vqsub.s16	q0,q1
	vqsub.s16	q0,q1,q2

	vqsub.s32	d0,d1
	vqsub.s32	d0,d1,d2
	vqsub.s32	q0,q1
	vqsub.s32	q0,q1,q2

	vqsub.s64	d0,d1
	vqsub.s64	d0,d1,d2
	vqsub.s64	q0,q1
	vqsub.s64	q0,q1,q2

	vqsub.s8	d0,d1
	vqsub.s8	d0,d1,d2
	vqsub.s8	q0,q1
	vqsub.s8	q0,q1,q2

	vqsub.u16	d0,d1
	vqsub.u16	d0,d1,d2
	vqsub.u16	q0,q1
	vqsub.u16	q0,q1,q2

	vqsub.u32	d0,d1
	vqsub.u32	d0,d1,d2
	vqsub.u32	q0,q1
	vqsub.u32	q0,q1,q2

	vqsub.u64	d0,d1
	vqsub.u64	d0,d1,d2
	vqsub.u64	q0,q1
	vqsub.u64	q0,q1,q2

	vqsub.u8	d0,d1
	vqsub.u8	d0,d1,d2
	vqsub.u8	q0,q1
	vqsub.u8	q0,q1,q2

	vraddhn.i16	d0,q1,q2

	vraddhn.i32	d0,q1,q2

	vraddhn.i64	d0,q1,q2

	vrecpe.u32	d0,d1
	vrecpe.u32	q0,q1

	vrev16.8	d0,d1
	vrev16.8	q0,q1

	vrev32.16	d0,d1
	vrev32.16	q0,q1

	vrev32.8	d0,d1
	vrev32.8	q0,q1

	vrev64.16	d0,d1
	vrev64.16	q0,q1

	vrev64.32	d0,d1
	vrev64.32	q0,q1

	vrev64.8	d0,d1
	vrev64.8	q0,q1

	vrhadd.s16	d0,d1
	vrhadd.s16	d0,d1,d2
	vrhadd.s16	q0,q1
	vrhadd.s16	q0,q1,q2

	vrhadd.s32	d0,d1
	vrhadd.s32	d0,d1,d2
	vrhadd.s32	q0,q1
	vrhadd.s32	q0,q1,q2

	vrhadd.s8	d0,d1
	vrhadd.s8	d0,d1,d2
	vrhadd.s8	q0,q1
	vrhadd.s8	q0,q1,q2

	vrhadd.u16	d0,d1
	vrhadd.u16	d0,d1,d2
	vrhadd.u16	q0,q1
	vrhadd.u16	q0,q1,q2

	vrhadd.u32	d0,d1
	vrhadd.u32	d0,d1,d2
	vrhadd.u32	q0,q1
	vrhadd.u32	q0,q1,q2

	vrhadd.u8	d0,d1
	vrhadd.u8	d0,d1,d2
	vrhadd.u8	q0,q1
	vrhadd.u8	q0,q1,q2

	vrshl.s16	d0,d1
	vrshl.s16	d0,d1,d2
	vrshl.s16	q0,q1
	vrshl.s16	q0,q1,q2

	vrshl.s32	d0,d1
	vrshl.s32	d0,d1,d2
	vrshl.s32	q0,q1
	vrshl.s32	q0,q1,q2

	vrshl.s64	d0,d1
	vrshl.s64	d0,d1,d2
	vrshl.s64	q0,q1
	vrshl.s64	q0,q1,q2

	vrshl.s8	d0,d1
	vrshl.s8	d0,d1,d2
	vrshl.s8	q0,q1
	vrshl.s8	q0,q1,q2

	vrshl.u16	d0,d1
	vrshl.u16	d0,d1,d2
	vrshl.u16	q0,q1
	vrshl.u16	q0,q1,q2

	vrshl.u32	d0,d1
	vrshl.u32	d0,d1,d2
	vrshl.u32	q0,q1
	vrshl.u32	q0,q1,q2

	vrshl.u64	d0,d1
	vrshl.u64	d0,d1,d2
	vrshl.u64	q0,q1
	vrshl.u64	q0,q1,q2

	vrshl.u8	d0,d1
	vrshl.u8	d0,d1,d2
	vrshl.u8	q0,q1
	vrshl.u8	q0,q1,q2

	vrshr.s16	d0,1
	vrshr.s16	d0,d1,1
	vrshr.s16	q0,1
	vrshr.s16	q0,q1,1

	vrshr.s32	d0,1
	vrshr.s32	d0,d1,1
	vrshr.s32	q0,1
	vrshr.s32	q0,q1,1

	vrshr.s64	d0,1
	vrshr.s64	d0,d1,1
	vrshr.s64	q0,1
	vrshr.s64	q0,q1,1

	vrshr.s8	d0,1
	vrshr.s8	d0,d1,1
	vrshr.s8	q0,1
	vrshr.s8	q0,q1,1

	vrshr.u16	d0,1
	vrshr.u16	d0,d1,1
	vrshr.u16	q0,1
	vrshr.u16	q0,q1,1

	vrshr.u32	d0,1
	vrshr.u32	d0,d1,1
	vrshr.u32	q0,1
	vrshr.u32	q0,q1,1

	vrshr.u64	d0,1
	vrshr.u64	d0,d1,1
	vrshr.u64	q0,1
	vrshr.u64	q0,q1,1

	vrshr.u8	d0,1
	vrshr.u8	d0,d1,1
	vrshr.u8	q0,1
	vrshr.u8	q0,q1,1

	vrshrn.i16	d0,q1,1

	vrshrn.i32	d0,q1,1

	vrshrn.i64	d0,q1,1

	vrsqrte.u32	d0,d1
	vrsqrte.u32	q0,q1

	vrsra.s16	d0,1
	vrsra.s16	d0,d1,1
	vrsra.s16	q0,1
	vrsra.s16	q0,q1,1

	vrsra.s32	d0,1
	vrsra.s32	d0,d1,1
	vrsra.s32	q0,1
	vrsra.s32	q0,q1,1

	vrsra.s64	d0,1
	vrsra.s64	d0,d1,1
	vrsra.s64	q0,1
	vrsra.s64	q0,q1,1

	vrsra.s8	d0,1
	vrsra.s8	d0,d1,1
	vrsra.s8	q0,1
	vrsra.s8	q0,q1,1

	vrsra.u16	d0,1
	vrsra.u16	d0,d1,1
	vrsra.u16	q0,1
	vrsra.u16	q0,q1,1

	vrsra.u32	d0,1
	vrsra.u32	d0,d1,1
	vrsra.u32	q0,1
	vrsra.u32	q0,q1,1

	vrsra.u64	d0,1
	vrsra.u64	d0,d1,1
	vrsra.u64	q0,1
	vrsra.u64	q0,q1,1

	vrsra.u8	d0,1
	vrsra.u8	d0,d1,1
	vrsra.u8	q0,1
	vrsra.u8	q0,q1,1

	vrsubhn.i16	d0,q1,q2

	vrsubhn.i32	d0,q1,q2

	vrsubhn.i64	d0,q1,q2

	vshl.i16	d0,1
	vshl.i16	d0,d1,1
	vshl.i16	q0,1
	vshl.i16	q0,q1,1

	vshl.i32	d0,1
	vshl.i32	d0,d1,1
	vshl.i32	q0,1
	vshl.i32	q0,q1,1

	vshl.i64	d0,1
	vshl.i64	d0,d1,1
	vshl.i64	q0,1
	vshl.i64	q0,q1,1

	vshl.i8	d0,1
	vshl.i8	d0,d1,1
	vshl.i8	q0,1
	vshl.i8	q0,q1,1

	vshl.s16	d0,d1
	vshl.s16	d0,d1,d2
	vshl.s16	q0,q1
	vshl.s16	q0,q1,q2

	vshl.s32	d0,d1
	vshl.s32	d0,d1,d2
	vshl.s32	q0,q1
	vshl.s32	q0,q1,q2

	vshl.s64	d0,d1
	vshl.s64	d0,d1,d2
	vshl.s64	q0,q1
	vshl.s64	q0,q1,q2

	vshl.s8	d0,d1
	vshl.s8	d0,d1,d2
	vshl.s8	q0,q1
	vshl.s8	q0,q1,q2

	vshl.u16	d0,d1
	vshl.u16	d0,d1,d2
	vshl.u16	q0,q1
	vshl.u16	q0,q1,q2

	vshl.u32	d0,d1
	vshl.u32	d0,d1,d2
	vshl.u32	q0,q1
	vshl.u32	q0,q1,q2

	vshl.u64	d0,d1
	vshl.u64	d0,d1,d2
	vshl.u64	q0,q1
	vshl.u64	q0,q1,q2

	vshl.u8	d0,d1
	vshl.u8	d0,d1,d2
	vshl.u8	q0,q1
	vshl.u8	q0,q1,q2

	vshll.i16	q0,d1,16

	vshll.i32	q0,d1,32

	vshll.i8	q0,d1,8

	vshll.s16	q0,d1,1
	vshll.s16	q0,d1,16

	vshll.s32	q0,d1,1
	vshll.s32	q0,d1,32

	vshll.s8	q0,d1,1
	vshll.s8	q0,d1,8

	vshll.u16	q0,d1,1
	vshll.u16	q0,d1,16

	vshll.u32	q0,d1,1
	vshll.u32	q0,d1,32

	vshll.u8	q0,d1,1
	vshll.u8	q0,d1,8

	vshr.s16	d0,1
	vshr.s16	d0,d1,1
	vshr.s16	q0,1
	vshr.s16	q0,q1,1

	vshr.s32	d0,1
	vshr.s32	d0,d1,1
	vshr.s32	q0,1
	vshr.s32	q0,q1,1

	vshr.s64	d0,1
	vshr.s64	d0,d1,1
	vshr.s64	q0,1
	vshr.s64	q0,q1,1

	vshr.s8	d0,1
	vshr.s8	d0,d1,1
	vshr.s8	q0,1
	vshr.s8	q0,q1,1

	vshr.u16	d0,1
	vshr.u16	d0,d1,1
	vshr.u16	q0,1
	vshr.u16	q0,q1,1

	vshr.u32	d0,1
	vshr.u32	d0,d1,1
	vshr.u32	q0,1
	vshr.u32	q0,q1,1

	vshr.u64	d0,1
	vshr.u64	d0,d1,1
	vshr.u64	q0,1
	vshr.u64	q0,q1,1

	vshr.u8	d0,1
	vshr.u8	d0,d1,1
	vshr.u8	q0,1
	vshr.u8	q0,q1,1

	vshrn.i16	d0,q1,1

	vshrn.i32	d0,q1,1

	vshrn.i64	d0,q1,1

	vsli.16	d0,1
	vsli.16	d0,d1,1
	vsli.16	q0,1
	vsli.16	q0,q1,1

	vsli.32	d0,1
	vsli.32	d0,d1,1
	vsli.32	q0,1
	vsli.32	q0,q1,1

	vsli.64	d0,1
	vsli.64	d0,d1,1
	vsli.64	q0,1
	vsli.64	q0,q1,1

	vsli.8	d0,1
	vsli.8	d0,d1,1
	vsli.8	q0,1
	vsli.8	q0,q1,1

	vsra.s16	d0,1
	vsra.s16	d0,d1,1
	vsra.s16	q0,1
	vsra.s16	q0,q1,1

	vsra.s32	d0,1
	vsra.s32	d0,d1,1
	vsra.s32	q0,1
	vsra.s32	q0,q1,1

	vsra.s64	d0,1
	vsra.s64	d0,d1,1
	vsra.s64	q0,1
	vsra.s64	q0,q1,1

	vsra.s8	d0,1
	vsra.s8	d0,d1,1
	vsra.s8	q0,1
	vsra.s8	q0,q1,1

	vsra.u16	d0,1
	vsra.u16	d0,d1,1
	vsra.u16	q0,1
	vsra.u16	q0,q1,1

	vsra.u32	d0,1
	vsra.u32	d0,d1,1
	vsra.u32	q0,1
	vsra.u32	q0,q1,1

	vsra.u64	d0,1
	vsra.u64	d0,d1,1
	vsra.u64	q0,1
	vsra.u64	q0,q1,1

	vsra.u8	d0,1
	vsra.u8	d0,d1,1
	vsra.u8	q0,1
	vsra.u8	q0,q1,1

	vsri.16	d0,1
	vsri.16	d0,d1,1
	vsri.16	q0,1
	vsri.16	q0,q1,1

	vsri.32	d0,1
	vsri.32	d0,d1,1
	vsri.32	q0,1
	vsri.32	q0,q1,1

	vsri.64	d0,1
	vsri.64	d0,d1,1
	vsri.64	q0,1
	vsri.64	q0,q1,1

	vsri.8	d0,1
	vsri.8	d0,d1,1
	vsri.8	q0,1
	vsri.8	q0,q1,1

	vst1.16	{d0},[r1]
	vst1.16	{d0},[r1]!
	vst1.16	{d0},[r1],8
	vst1.16	{d0},[r1],r2
	vst1.16	{d0},[r1@64]
	vst1.16	{d0},[r1@64]!
	vst1.16	{d0},[r1@64],8
	vst1.16	{d0},[r1@64],r2
	vst1.16	{d0,d1},[r2]
	vst1.16	{d0,d1},[r2]!
	vst1.16	{d0,d1},[r2],16
	vst1.16	{d0,d1},[r2],r3
	vst1.16	{d0,d1},[r2@64]
	vst1.16	{d0,d1},[r2@64]!
	vst1.16	{d0,d1},[r2@64],16
	vst1.16	{d0,d1},[r2@64],r3
	vst1.16	{d0,d1,d2},[r3]
	vst1.16	{d0,d1,d2},[r3]!
	vst1.16	{d0,d1,d2},[r3],24
	vst1.16	{d0,d1,d2},[r3],r4
	vst1.16	{d0,d1,d2},[r3@64]
	vst1.16	{d0,d1,d2},[r3@64]!
	vst1.16	{d0,d1,d2},[r3@64],24
	vst1.16	{d0,d1,d2},[r3@64],r4
	vst1.16	{d0,d1,d2,d3},[r4]
	vst1.16	{d0,d1,d2,d3},[r4]!
	vst1.16	{d0,d1,d2,d3},[r4],32
	vst1.16	{d0,d1,d2,d3},[r4],r5
	vst1.16	{d0,d1,d2,d3},[r4@64]
	vst1.16	{d0,d1,d2,d3},[r4@64]!
	vst1.16	{d0,d1,d2,d3},[r4@64],32
	vst1.16	{d0,d1,d2,d3},[r4@64],r5
	vst1.16	{d0[1]},[r2]
	vst1.16	{d0[1]},[r2]!
	vst1.16	{d0[1]},[r2],2
	vst1.16	{d0[1]},[r2],r3
	vst1.16	{d0[1]},[r2@16]
	vst1.16	{d0[1]},[r2@16]!
	vst1.16	{d0[1]},[r2@16],2
	vst1.16	{d0[1]},[r2@16],r3

	vst1.32	{d0},[r1]
	vst1.32	{d0},[r1]!
	vst1.32	{d0},[r1],8
	vst1.32	{d0},[r1],r2
	vst1.32	{d0},[r1@64]
	vst1.32	{d0},[r1@64]!
	vst1.32	{d0},[r1@64],8
	vst1.32	{d0},[r1@64],r2
	vst1.32	{d0,d1},[r2]
	vst1.32	{d0,d1},[r2]!
	vst1.32	{d0,d1},[r2],16
	vst1.32	{d0,d1},[r2],r3
	vst1.32	{d0,d1},[r2@64]
	vst1.32	{d0,d1},[r2@64]!
	vst1.32	{d0,d1},[r2@64],16
	vst1.32	{d0,d1},[r2@64],r3
	vst1.32	{d0,d1,d2},[r3]
	vst1.32	{d0,d1,d2},[r3]!
	vst1.32	{d0,d1,d2},[r3],24
	vst1.32	{d0,d1,d2},[r3],r4
	vst1.32	{d0,d1,d2},[r3@64]
	vst1.32	{d0,d1,d2},[r3@64]!
	vst1.32	{d0,d1,d2},[r3@64],24
	vst1.32	{d0,d1,d2},[r3@64],r4
	vst1.32	{d0,d1,d2,d3},[r4]
	vst1.32	{d0,d1,d2,d3},[r4]!
	vst1.32	{d0,d1,d2,d3},[r4],32
	vst1.32	{d0,d1,d2,d3},[r4],r5
	vst1.32	{d0,d1,d2,d3},[r4@64]
	vst1.32	{d0,d1,d2,d3},[r4@64]!
	vst1.32	{d0,d1,d2,d3},[r4@64],32
	vst1.32	{d0,d1,d2,d3},[r4@64],r5
	vst1.32	{d0[1]},[r2]
	vst1.32	{d0[1]},[r2]!
	vst1.32	{d0[1]},[r2],4
	vst1.32	{d0[1]},[r2],r3
	vst1.32	{d0[1]},[r2@32]
	vst1.32	{d0[1]},[r2@32]!
	vst1.32	{d0[1]},[r2@32],4
	vst1.32	{d0[1]},[r2@32],r3

	vst1.64	{d0},[r1]
	vst1.64	{d0},[r1]!
	vst1.64	{d0},[r1],8
	vst1.64	{d0},[r1],r2
	vst1.64	{d0},[r1@64]
	vst1.64	{d0},[r1@64]!
	vst1.64	{d0},[r1@64],8
	vst1.64	{d0},[r1@64],r2
	vst1.64	{d0,d1},[r2]
	vst1.64	{d0,d1},[r2]!
	vst1.64	{d0,d1},[r2],16
	vst1.64	{d0,d1},[r2],r3
	vst1.64	{d0,d1},[r2@64]
	vst1.64	{d0,d1},[r2@64]!
	vst1.64	{d0,d1},[r2@64],16
	vst1.64	{d0,d1},[r2@64],r3
	vst1.64	{d0,d1,d2},[r3]
	vst1.64	{d0,d1,d2},[r3]!
	vst1.64	{d0,d1,d2},[r3],24
	vst1.64	{d0,d1,d2},[r3],r4
	vst1.64	{d0,d1,d2},[r3@64]
	vst1.64	{d0,d1,d2},[r3@64]!
	vst1.64	{d0,d1,d2},[r3@64],24
	vst1.64	{d0,d1,d2},[r3@64],r4
	vst1.64	{d0,d1,d2,d3},[r4]
	vst1.64	{d0,d1,d2,d3},[r4]!
	vst1.64	{d0,d1,d2,d3},[r4],32
	vst1.64	{d0,d1,d2,d3},[r4],r5
	vst1.64	{d0,d1,d2,d3},[r4@64]
	vst1.64	{d0,d1,d2,d3},[r4@64]!
	vst1.64	{d0,d1,d2,d3},[r4@64],32
	vst1.64	{d0,d1,d2,d3},[r4@64],r5

	vst1.8	{d0},[r1]
	vst1.8	{d0},[r1]!
	vst1.8	{d0},[r1],8
	vst1.8	{d0},[r1],r2
	vst1.8	{d0},[r1@64]
	vst1.8	{d0},[r1@64]!
	vst1.8	{d0},[r1@64],8
	vst1.8	{d0},[r1@64],r2
	vst1.8	{d0,d1},[r2]
	vst1.8	{d0,d1},[r2]!
	vst1.8	{d0,d1},[r2],16
	vst1.8	{d0,d1},[r2],r3
	vst1.8	{d0,d1},[r2@64]
	vst1.8	{d0,d1},[r2@64]!
	vst1.8	{d0,d1},[r2@64],16
	vst1.8	{d0,d1},[r2@64],r3
	vst1.8	{d0,d1,d2},[r3]
	vst1.8	{d0,d1,d2},[r3]!
	vst1.8	{d0,d1,d2},[r3],24
	vst1.8	{d0,d1,d2},[r3],r4
	vst1.8	{d0,d1,d2},[r3@64]
	vst1.8	{d0,d1,d2},[r3@64]!
	vst1.8	{d0,d1,d2},[r3@64],24
	vst1.8	{d0,d1,d2},[r3@64],r4
	vst1.8	{d0,d1,d2,d3},[r4]
	vst1.8	{d0,d1,d2,d3},[r4]!
	vst1.8	{d0,d1,d2,d3},[r4],32
	vst1.8	{d0,d1,d2,d3},[r4],r5
	vst1.8	{d0,d1,d2,d3},[r4@64]
	vst1.8	{d0,d1,d2,d3},[r4@64]!
	vst1.8	{d0,d1,d2,d3},[r4@64],32
	vst1.8	{d0,d1,d2,d3},[r4@64],r5
	vst1.8	{d0[1]},[r2]
	vst1.8	{d0[1]},[r2]!
	vst1.8	{d0[1]},[r2],1
	vst1.8	{d0[1]},[r2],r3

	vst2.16	{d0,d1},[r2]
	vst2.16	{d0,d1},[r2]!
	vst2.16	{d0,d1},[r2],16
	vst2.16	{d0,d1},[r2],r3
	vst2.16	{d0,d1},[r2@64]
	vst2.16	{d0,d1},[r2@64]!
	vst2.16	{d0,d1},[r2@64],16
	vst2.16	{d0,d1},[r2@64],r3
	vst2.16	{d0,d2},[r3]
	vst2.16	{d0,d2},[r3]!
	vst2.16	{d0,d2},[r3],16
	vst2.16	{d0,d2},[r3],r4
	vst2.16	{d0,d2},[r3@64]
	vst2.16	{d0,d2},[r3@64]!
	vst2.16	{d0,d2},[r3@64],16
	vst2.16	{d0,d2},[r3@64],r4
	vst2.16	{d0,d1,d2,d3},[r4]
	vst2.16	{d0,d1,d2,d3},[r4]!
	vst2.16	{d0,d1,d2,d3},[r4],32
	vst2.16	{d0,d1,d2,d3},[r4],r5
	vst2.16	{d0,d1,d2,d3},[r4@64]
	vst2.16	{d0,d1,d2,d3},[r4@64]!
	vst2.16	{d0,d1,d2,d3},[r4@64],32
	vst2.16	{d0,d1,d2,d3},[r4@64],r5
	vst2.16	{d0[1],d1[1]},[r2]
	vst2.16	{d0[1],d1[1]},[r2]!
	vst2.16	{d0[1],d1[1]},[r2],4
	vst2.16	{d0[1],d1[1]},[r2],r3
	vst2.16	{d0[1],d1[1]},[r2@32]
	vst2.16	{d0[1],d1[1]},[r2@32]!
	vst2.16	{d0[1],d1[1]},[r2@32],4
	vst2.16	{d0[1],d1[1]},[r2@32],r3
	vst2.16	{d0[1],d2[1]},[r2]
	vst2.16	{d0[1],d2[1]},[r2]!
	vst2.16	{d0[1],d2[1]},[r2],4
	vst2.16	{d0[1],d2[1]},[r2],r3
	vst2.16	{d0[1],d2[1]},[r2@32]
	vst2.16	{d0[1],d2[1]},[r2@32]!
	vst2.16	{d0[1],d2[1]},[r2@32],4
	vst2.16	{d0[1],d2[1]},[r2@32],r3
	vst2.32	{d0,d1},[r2]
	vst2.32	{d0,d1},[r2]!
	vst2.32	{d0,d1},[r2],16
	vst2.32	{d0,d1},[r2],r3
	vst2.32	{d0,d1},[r2@64]
	vst2.32	{d0,d1},[r2@64]!
	vst2.32	{d0,d1},[r2@64],16
	vst2.32	{d0,d1},[r2@64],r3
	vst2.32	{d0,d2},[r3]
	vst2.32	{d0,d2},[r3]!
	vst2.32	{d0,d2},[r3],16
	vst2.32	{d0,d2},[r3],r4
	vst2.32	{d0,d2},[r3@64]
	vst2.32	{d0,d2},[r3@64]!
	vst2.32	{d0,d2},[r3@64],16
	vst2.32	{d0,d2},[r3@64],r4
	vst2.32	{d0,d1,d2,d3},[r4]
	vst2.32	{d0,d1,d2,d3},[r4]!
	vst2.32	{d0,d1,d2,d3},[r4],32
	vst2.32	{d0,d1,d2,d3},[r4],r5
	vst2.32	{d0,d1,d2,d3},[r4@64]
	vst2.32	{d0,d1,d2,d3},[r4@64]!
	vst2.32	{d0,d1,d2,d3},[r4@64],32
	vst2.32	{d0,d1,d2,d3},[r4@64],r5
	vst2.32	{d0[1],d1[1]},[r2]
	vst2.32	{d0[1],d1[1]},[r2]!
	vst2.32	{d0[1],d1[1]},[r2],8
	vst2.32	{d0[1],d1[1]},[r2],r3
	vst2.32	{d0[1],d1[1]},[r2@64]
	vst2.32	{d0[1],d1[1]},[r2@64]!
	vst2.32	{d0[1],d1[1]},[r2@64],8
	vst2.32	{d0[1],d1[1]},[r2@64],r3
	vst2.32	{d0[1],d2[1]},[r2]
	vst2.32	{d0[1],d2[1]},[r2]!
	vst2.32	{d0[1],d2[1]},[r2],8
	vst2.32	{d0[1],d2[1]},[r2],r3
	vst2.32	{d0[1],d2[1]},[r2@64]
	vst2.32	{d0[1],d2[1]},[r2@64]!
	vst2.32	{d0[1],d2[1]},[r2@64],8
	vst2.32	{d0[1],d2[1]},[r2@64],r3

	vst2.8	{d0,d1},[r2]
	vst2.8	{d0,d1},[r2]!
	vst2.8	{d0,d1},[r2],16
	vst2.8	{d0,d1},[r2],r3
	vst2.8	{d0,d1},[r2@64]
	vst2.8	{d0,d1},[r2@64]!
	vst2.8	{d0,d1},[r2@64],16
	vst2.8	{d0,d1},[r2@64],r3
	vst2.8	{d0,d2},[r3]
	vst2.8	{d0,d2},[r3]!
	vst2.8	{d0,d2},[r3],16
	vst2.8	{d0,d2},[r3],r4
	vst2.8	{d0,d2},[r3@64]
	vst2.8	{d0,d2},[r3@64]!
	vst2.8	{d0,d2},[r3@64],16
	vst2.8	{d0,d2},[r3@64],r4
	vst2.8	{d0,d1,d2,d3},[r4]
	vst2.8	{d0,d1,d2,d3},[r4]!
	vst2.8	{d0,d1,d2,d3},[r4],32
	vst2.8	{d0,d1,d2,d3},[r4],r5
	vst2.8	{d0,d1,d2,d3},[r4@64]
	vst2.8	{d0,d1,d2,d3},[r4@64]!
	vst2.8	{d0,d1,d2,d3},[r4@64],32
	vst2.8	{d0,d1,d2,d3},[r4@64],r5
	vst2.8	{d0[1],d1[1]},[r2]
	vst2.8	{d0[1],d1[1]},[r2]!
	vst2.8	{d0[1],d1[1]},[r2],2
	vst2.8	{d0[1],d1[1]},[r2],r3
	vst2.8	{d0[1],d1[1]},[r2@16]
	vst2.8	{d0[1],d1[1]},[r2@16]!
	vst2.8	{d0[1],d1[1]},[r2@16],2
	vst2.8	{d0[1],d1[1]},[r2@16],r3

	vst3.16	{d0,d1,d2},[r2]
	vst3.16	{d0,d1,d2},[r2]!
	vst3.16	{d0,d1,d2},[r2],24
	vst3.16	{d0,d1,d2},[r2],r3
	vst3.16	{d0,d1,d2},[r2@64]
	vst3.16	{d0,d1,d2},[r2@64]!
	vst3.16	{d0,d1,d2},[r2@64],24
	vst3.16	{d0,d1,d2},[r2@64],r3
	vst3.16	{d0,d2,d4},[r3]
	vst3.16	{d0,d2,d4},[r3]!
	vst3.16	{d0,d2,d4},[r3],24
	vst3.16	{d0,d2,d4},[r3],r4
	vst3.16	{d0,d2,d4},[r3@64]
	vst3.16	{d0,d2,d4},[r3@64]!
	vst3.16	{d0,d2,d4},[r3@64],24
	vst3.16	{d0,d2,d4},[r3@64],r4
	vst3.16	{d0[1],d1[1],d2[1]},[r2]
	vst3.16	{d0[1],d1[1],d2[1]},[r2]!
	vst3.16	{d0[1],d1[1],d2[1]},[r2],6
	vst3.16	{d0[1],d1[1],d2[1]},[r2],r3
	vst3.16	{d0[1],d2[1],d4[1]},[r2]
	vst3.16	{d0[1],d2[1],d4[1]},[r2]!
	vst3.16	{d0[1],d2[1],d4[1]},[r2],6
	vst3.16	{d0[1],d2[1],d4[1]},[r2],r3

	vst3.32	{d0,d1,d2},[r2]
	vst3.32	{d0,d1,d2},[r2]!
	vst3.32	{d0,d1,d2},[r2],24
	vst3.32	{d0,d1,d2},[r2],r3
	vst3.32	{d0,d1,d2},[r2@64]
	vst3.32	{d0,d1,d2},[r2@64]!
	vst3.32	{d0,d1,d2},[r2@64],24
	vst3.32	{d0,d1,d2},[r2@64],r3
	vst3.32	{d0,d2,d4},[r3]
	vst3.32	{d0,d2,d4},[r3]!
	vst3.32	{d0,d2,d4},[r3],24
	vst3.32	{d0,d2,d4},[r3],r4
	vst3.32	{d0,d2,d4},[r3@64]
	vst3.32	{d0,d2,d4},[r3@64]!
	vst3.32	{d0,d2,d4},[r3@64],24
	vst3.32	{d0,d2,d4},[r3@64],r4
	vst3.32	{d0[1],d1[1],d2[1]},[r2]
	vst3.32	{d0[1],d1[1],d2[1]},[r2]!
	vst3.32	{d0[1],d1[1],d2[1]},[r2],12
	vst3.32	{d0[1],d1[1],d2[1]},[r2],r3
	vst3.32	{d0[1],d2[1],d4[1]},[r2]
	vst3.32	{d0[1],d2[1],d4[1]},[r2]!
	vst3.32	{d0[1],d2[1],d4[1]},[r2],12
	vst3.32	{d0[1],d2[1],d4[1]},[r2],r3

	vst3.8	{d0,d1,d2},[r2]
	vst3.8	{d0,d1,d2},[r2]!
	vst3.8	{d0,d1,d2},[r2],24
	vst3.8	{d0,d1,d2},[r2],r3
	vst3.8	{d0,d1,d2},[r2@64]
	vst3.8	{d0,d1,d2},[r2@64]!
	vst3.8	{d0,d1,d2},[r2@64],24
	vst3.8	{d0,d1,d2},[r2@64],r3
	vst3.8	{d0,d2,d4},[r3]
	vst3.8	{d0,d2,d4},[r3]!
	vst3.8	{d0,d2,d4},[r3],24
	vst3.8	{d0,d2,d4},[r3],r4
	vst3.8	{d0,d2,d4},[r3@64]
	vst3.8	{d0,d2,d4},[r3@64]!
	vst3.8	{d0,d2,d4},[r3@64],24
	vst3.8	{d0,d2,d4},[r3@64],r4
	vst3.8	{d0[1],d1[1],d2[1]},[r2]
	vst3.8	{d0[1],d1[1],d2[1]},[r2]!
	vst3.8	{d0[1],d1[1],d2[1]},[r2],3
	vst3.8	{d0[1],d1[1],d2[1]},[r2],r3

	vst4.16	{d0,d1,d2,d3},[r4]
	vst4.16	{d0,d1,d2,d3},[r4]!
	vst4.16	{d0,d1,d2,d3},[r4],32
	vst4.16	{d0,d1,d2,d3},[r4],r5
	vst4.16	{d0,d1,d2,d3},[r4@64]
	vst4.16	{d0,d1,d2,d3},[r4@64]!
	vst4.16	{d0,d1,d2,d3},[r4@64],32
	vst4.16	{d0,d1,d2,d3},[r4@64],r5
	vst4.16	{d0,d2,d4,d6},[r4]
	vst4.16	{d0,d2,d4,d6},[r4]!
	vst4.16	{d0,d2,d4,d6},[r4],32
	vst4.16	{d0,d2,d4,d6},[r4],r5
	vst4.16	{d0,d2,d4,d6},[r4@64]
	vst4.16	{d0,d2,d4,d6},[r4@64]!
	vst4.16	{d0,d2,d4,d6},[r4@64],32
	vst4.16	{d0,d2,d4,d6},[r4@64],r5
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2]
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2]!
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2],8
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2],r3
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64]
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64]!
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64],8
	vst4.16	{d0[1],d1[1],d2[1],d3[1]},[r2@64],r3
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2]
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2]!
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2],8
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2],r3
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64]
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64]!
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64],8
	vst4.16	{d0[1],d2[1],d4[1],d6[1]},[r2@64],r3

	vst4.32	{d0,d1,d2,d3},[r4]
	vst4.32	{d0,d1,d2,d3},[r4]!
	vst4.32	{d0,d1,d2,d3},[r4],32
	vst4.32	{d0,d1,d2,d3},[r4],r5
	vst4.32	{d0,d1,d2,d3},[r4@64]
	vst4.32	{d0,d1,d2,d3},[r4@64]!
	vst4.32	{d0,d1,d2,d3},[r4@64],32
	vst4.32	{d0,d1,d2,d3},[r4@64],r5
	vst4.32	{d0,d2,d4,d6},[r4]
	vst4.32	{d0,d2,d4,d6},[r4]!
	vst4.32	{d0,d2,d4,d6},[r4],32
	vst4.32	{d0,d2,d4,d6},[r4],r5
	vst4.32	{d0,d2,d4,d6},[r4@64]
	vst4.32	{d0,d2,d4,d6},[r4@64]!
	vst4.32	{d0,d2,d4,d6},[r4@64],32
	vst4.32	{d0,d2,d4,d6},[r4@64],r5
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2]
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2]!
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2],16
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2],r3
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64]
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64]!
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64],16
	vst4.32	{d0[1],d1[1],d2[1],d3[1]},[r2@64],r3
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2]
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2]!
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2],16
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2],r3
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64]
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64]!
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64],16
	vst4.32	{d0[1],d2[1],d4[1],d6[1]},[r2@64],r3

	vst4.8	{d0,d1,d2,d3},[r4]
	vst4.8	{d0,d1,d2,d3},[r4]!
	vst4.8	{d0,d1,d2,d3},[r4],32
	vst4.8	{d0,d1,d2,d3},[r4],r5
	vst4.8	{d0,d1,d2,d3},[r4@64]
	vst4.8	{d0,d1,d2,d3},[r4@64]!
	vst4.8	{d0,d1,d2,d3},[r4@64],32
	vst4.8	{d0,d1,d2,d3},[r4@64],r5
	vst4.8	{d0,d2,d4,d6},[r4]
	vst4.8	{d0,d2,d4,d6},[r4]!
	vst4.8	{d0,d2,d4,d6},[r4],32
	vst4.8	{d0,d2,d4,d6},[r4],r5
	vst4.8	{d0,d2,d4,d6},[r4@64]
	vst4.8	{d0,d2,d4,d6},[r4@64]!
	vst4.8	{d0,d2,d4,d6},[r4@64],32
	vst4.8	{d0,d2,d4,d6},[r4@64],r5
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2]
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2]!
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2],4
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2],r3
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32]
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32]!
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32],4
	vst4.8	{d0[1],d1[1],d2[1],d3[1]},[r2@32],r3

	vsub.i16	d0,d1
	vsub.i16	d0,d1,d2
	vsub.i16	q0,q1
	vsub.i16	q0,q1,q2

	vsub.i32	d0,d1
	vsub.i32	d0,d1,d2
	vsub.i32	q0,q1
	vsub.i32	q0,q1,q2

	vsub.i64	d0,d1
	vsub.i64	d0,d1,d2
	vsub.i64	q0,q1
	vsub.i64	q0,q1,q2

	vsub.i8	d0,d1
	vsub.i8	d0,d1,d2
	vsub.i8	q0,q1
	vsub.i8	q0,q1,q2

	vsubhn.i16	d0,q1,q2

	vsubhn.i32	d0,q1,q2

	vsubhn.i64	d0,q1,q2

	vsubl.s16	q0,d1,d2

	vsubl.s32	q0,d1,d2

	vsubl.s8	q0,d1,d2

	vsubl.u16	q0,d1,d2

	vsubl.u32	q0,d1,d2

	vsubl.u8	q0,d1,d2

	vsubw.s16	q0,d1
	vsubw.s16	q0,q1,d2

	vsubw.s32	q0,d1
	vsubw.s32	q0,q1,d2

	vsubw.s8	q0,d1
	vsubw.s8	q0,q1,d2

	vsubw.u16	q0,d1
	vsubw.u16	q0,q1,d2

	vsubw.u32	q0,d1
	vsubw.u32	q0,q1,d2

	vsubw.u8	q0,d1
	vsubw.u8	q0,q1,d2

	vswp	d0,d1
	vswp	q0,q1

	vtbl.8	d0,{d1},d2
	vtbl.8	d0,{d1,d2},d3
	vtbl.8	d0,{d1,d2,d3},d4
	vtbl.8	d0,{d1,d2,d3,d4},d5

	vtbx.8	d0,{d1},d2
	vtbx.8	d0,{d1,d2},d3
	vtbx.8	d0,{d1,d2,d3},d4
	vtbx.8	d0,{d1,d2,d3,d4},d5

	vtrn.16	d0,d1
	vtrn.16	q0,q1

	vtrn.32	d0,d1
	vtrn.32	q0,q1

	vtrn.8	d0,d1
	vtrn.8	q0,q1

	vtst.16	d0,d1
	vtst.16	d0,d1,d2
	vtst.16	q0,q1
	vtst.16	q0,q1,q2

	vtst.32	d0,d1
	vtst.32	d0,d1,d2
	vtst.32	q0,q1
	vtst.32	q0,q1,q2

	vtst.8	d0,d1
	vtst.8	d0,d1,d2
	vtst.8	q0,q1
	vtst.8	q0,q1,q2

	vuzp.16	d0,d1
	vuzp.16	q0,q1

	vuzp.32	d0,d1
	vuzp.32	q0,q1

	vuzp.8	d0,d1
	vuzp.8	q0,q1

	vzip.16	d0,d1
	vzip.16	q0,q1

	vzip.32	d0,d1
	vzip.32	q0,q1

	vzip.8	d0,d1
	vzip.8	q0,q1

coprocessor COPRO_SIMD_FLOAT

	vabd.f32	d0,d1
	vabd.f32	d0,d1,d2
	vabd.f32	q0,q1
	vabd.f32	q0,q1,q2

	vabs.f32	d0,d1
	vabs.f32	q0,q1

	vacge.f32	d0,d1
	vacge.f32	d0,d1,d2
	vacge.f32	q0,q1
	vacge.f32	q0,q1,q2

	vacgt.f32	d0,d1
	vacgt.f32	d0,d1,d2
	vacgt.f32	q0,q1
	vacgt.f32	q0,q1,q2

	vacle.f32	d0,d1
	vacle.f32	d0,d1,d2
	vacle.f32	q0,q1
	vacle.f32	q0,q1,q2

	vaclt.f32	d0,d1
	vaclt.f32	d0,d1,d2
	vaclt.f32	q0,q1
	vaclt.f32	q0,q1,q2

	vadd.f32	d0,d1
	vadd.f32	d0,d1,d2
	vadd.f32	q0,q1
	vadd.f32	q0,q1,q2

	vceq.f32	d0,0
	vceq.f32	d0,d1
	vceq.f32	d0,d1,0
	vceq.f32	d0,d1,d2
	vceq.f32	q0,0
	vceq.f32	q0,q1
	vceq.f32	q0,q1,0
	vceq.f32	q0,q1,q2

	vcge.f32	d0,0
	vcge.f32	d0,d1
	vcge.f32	d0,d1,0
	vcge.f32	d0,d1,d2
	vcge.f32	q0,0
	vcge.f32	q0,q1
	vcge.f32	q0,q1,0
	vcge.f32	q0,q1,q2

	vcgt.f32	d0,0
	vcgt.f32	d0,d1
	vcgt.f32	d0,d1,0
	vcgt.f32	d0,d1,d2
	vcgt.f32	q0,0
	vcgt.f32	q0,q1
	vcgt.f32	q0,q1,0
	vcgt.f32	q0,q1,q2

	vcle.f32	d0,0
	vcle.f32	d0,d1
	vcle.f32	d0,d1,0
	vcle.f32	d0,d1,d2
	vcle.f32	q0,0
	vcle.f32	q0,q1
	vcle.f32	q0,q1,0
	vcle.f32	q0,q1,q2

	vclt.f32	d0,0
	vclt.f32	d0,d1
	vclt.f32	d0,d1,0
	vclt.f32	d0,d1,d2
	vclt.f32	q0,0
	vclt.f32	q0,q1
	vclt.f32	q0,q1,0
	vclt.f32	q0,q1,q2

	vcvt.f32.s32	d0,d1
	vcvt.f32.s32	d0,d1,2
	vcvt.f32.s32	q0,q1
	vcvt.f32.s32	q0,q1,2

	vcvt.f32.u32	d0,d1
	vcvt.f32.u32	d0,d1,2
	vcvt.f32.u32	q0,q1
	vcvt.f32.u32	q0,q1,2

	vcvt.s32.f32	d0,d1
	vcvt.s32.f32	d0,d1,2
	vcvt.s32.f32	q0,q1
	vcvt.s32.f32	q0,q1,2

	vcvt.u32.f32	d0,d1
	vcvt.u32.f32	d0,d1,2
	vcvt.u32.f32	q0,q1
	vcvt.u32.f32	q0,q1,2

	vmax.f32	d0,d1
	vmax.f32	d0,d1,d2
	vmax.f32	q0,q1
	vmax.f32	q0,q1,q2

	vmin.f32	d0,d1
	vmin.f32	d0,d1,d2
	vmin.f32	q0,q1
	vmin.f32	q0,q1,q2

	vmla.f32	d0,d1,d2
	vmla.f32	d0,d1,d2[0]
	vmla.f32	q0,q1,q2
	vmla.f32	q0,q1,d2[1]

	vmls.f32	d0,d1,d2
	vmls.f32	d0,d1,d2[0]
	vmls.f32	q0,q1,q2
	vmls.f32	q0,q1,d2[1]

	vmov.f32	d0,1
	vmov.f32	d0,1.0
	vmov.f32	q0,1
	vmov.f32	q0,1.0

	vmul.f32	d0,d1
	vmul.f32	d0,d1,d2
	vmul.f32	d0,d1[0]
	vmul.f32	d0,d1,d2[0]
	vmul.f32	q0,q1
	vmul.f32	q0,q1,q2
	vmul.f32	q0,d1[0]
	vmul.f32	q0,q1,d1[0]

	vneg.f32	d0,d1
	vneg.f32	q0,q1

	vpadd.f32	d0,d1
	vpadd.f32	d0,d1,d2

	vpmax.f32	d0,d1
	vpmax.f32	d0,d1,d2

	vpmin.f32	d0,d1
	vpmin.f32	d0,d1,d2

	vrecpe.f32	d0,d1
	vrecpe.f32	q0,q1

	vrecps.f32	d0,d1
	vrecps.f32	d0,d1,d2
	vrecps.f32	q0,q1
	vrecps.f32	q0,q1,q2

	vrsqrte.f32	d0,d1
	vrsqrte.f32	q0,q1

	vrsqrts.f32	d0,d1
	vrsqrts.f32	d0,d1,d2
	vrsqrts.f32	q0,q1
	vrsqrts.f32	q0,q1,q2

	vsub.f32	d0,d1
	vsub.f32	d0,d1,d2
	vsub.f32	q0,q1
	vsub.f32	q0,q1,q2

coprocessor COPRO_SIMD_HP

	vcvt.f32.f16	q0,d1

	vcvt.f16.f32	d0,q1

coprocessor COPRO_SIMD_V2

	vfma.f32	q0,q1,q2
	vfma.f32	d0,d1,d2

	vfms.f32	q0,q1,q2
	vfms.f32	d0,d1,d2

coprocessor COPRO_SIMD_V8

	vcvtm.s32.f32	d0,d1
	vcvtm.u32.f32	d0,d1
	vcvtm.s32.f32	q0,q1
	vcvtm.u32.f32	q0,q1

	vcvtp.s32.f32	d0,d1
	vcvtp.u32.f32	d0,d1
	vcvtp.s32.f32	q0,q1
	vcvtp.u32.f32	q0,q1

	vcvtn.s32.f32	d0,d1
	vcvtn.u32.f32	d0,d1
	vcvtn.s32.f32	q0,q1
	vcvtn.u32.f32	q0,q1

	vcvta.s32.f32	d0,d1
	vcvta.u32.f32	d0,d1
	vcvta.s32.f32	q0,q1
	vcvta.u32.f32	q0,q1

	vmaxnm.f32	d0,d1,d2
	vmaxnm.f32	q0,q1,q2

	vminnm.f32	d0,d1,d2
	vminnm.f32	q0,q1,q2

	vrintm.f32.f32	d0,d1
	vrintm.f32.f32	q0,q1

	vrintp.f32.f32	d0,d1
	vrintp.f32.f32	q0,q1

	vrintn.f32.f32	d0,d1
	vrintn.f32.f32	q0,q1

	vrinta.f32.f32	d0,d1
	vrinta.f32.f32	q0,q1

	vrintx.f32.f32	d0,d1
	vrintx.f32.f32	q0,q1

	vrintz.f32.f32	d0,d1
	vrintz.f32.f32	q0,q1

coprocessor COPRO_SIMD_CRYPTO

	aese.8	q0,q1
	aesd.8	q0,q1
	aesmc.8	q0,q1
	aesimc.8	q0,q1

	sha1h.32	q0,q1
	sha1c.32	q0,q1,q2
	sha1p.32	q0,q1,q2
	sha1m.32	q0,q1,q2
	sha1su0.32	q0,q1,q2
	sha1su1.32	q0,q1

	sha256h.32	q0,q1,q2
	sha256h2.32	q0,q1,q2
	sha256su0.32	q0,q1
	sha256su1.32	q0,q1,q2

	vmull.p64	q0,d1,d2
