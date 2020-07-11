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
	;VFP, ARM mode, all instructions are 32-bit
	;***********************************************

	code32

coprocessor COPRO_VFP_V1xD

	fabss	s0,s1

	fadds	s0,s1
	fadds	s0,s1,s2

	fcmpes	s0,s1
	fcmpes	s0,0.0

	fcmpezs	s0

	fcmps	s0,s1
	fcmps	s0,0.0

	fcmpzs	s0

	fcpys	s0,s1

	fdivs	s0,s1
	fdivs	s0,s1,s2

	label_fldd:
	fldd	d0,[r1]
	fldd	d0,[r1,4]
	fldd	d0,[label_fldd]
	fldd	d0,[expression.word]

	fldmdbd	r0!,{d0-d3}

	fldmdbs	r0!,{s0-s3}

	fldmdbx	r0!,{d0-d3}

	fldmead	r0!,{d0-d3}

	fldmeas	r0!,{s0-s3}

	fldmeax	r0!,{d0-d3}

	fldmfdd	r0,{d0-d3}
	fldmfdd	r0!,{d0-d3}

	fldmfds	r0,{s0-s3}
	fldmfds	r0!,{s0-s3}

	fldmfdx	r0,{d0-d3}
	fldmfdx	r0!,{d0-d3}

	fldmiad	r0,{d0-d3}
	fldmiad	r0!,{d0-d3}

	fldmias	r0,{s0-s3}
	fldmias	r0!,{s0-s3}

	fldmiax	r0,{d0-d3}
	fldmiax	r0!,{d0-d3}

	fldmd	r0,{d0-d3}
	fldmd	r0!,{d0-d3}

	fldms	r0,{s0-s3}
	fldms	r0!,{s0-s3}

	fldmx	r0,{d0-d3}
	fldmx	r0!,{d0-d3}

	label_flds:
	flds	s0,[r1]
	flds	s0,[r1,4]
	flds	s0,[label_flds]
	flds	s0,[expression.word]

	fmacs	s0,s1,s2

	fmdhr	d0,r1

	fmdlr	d0,r1

	fmrdh	r0,d1

	fmrdl	r0,d1

	fmrs	r0,s1

	fmrx	r0,fpscr

	fmscs	s0,s1,s2

	fmsr	s0,r1

	fmstat

	fmuls	s0,s1
	fmuls	s0,s1,s2

	fmxr	fpscr,r1

	fnegs	s0,s1

	fnmacs	s0,s1,s2

	fnmscs	s0,s1,s2

	fnmuls	s0,s1
	fnmuls	s0,s1,s2

	fsqrts	s0,s1

	fstmdbd	r0!,{d0-d3}

	fstmdbs	r0!,{s0-s3}

	fstmdbx	r0!,{d0-d3}

	fstmead	r0,{d0-d3}
	fstmead	r0!,{d0-d3}

	fstmeas	r0,{s0-s3}
	fstmeas	r0!,{s0-s3}

	fstmeax	r0,{d0-d3}
	fstmeax	r0!,{d0-d3}

	fstmfdd	r0!,{d0-d3}

	fstmfds	r0!,{s0-s3}

	fstmfdx	r0!,{d0-d3}

	fstmiad	r0,{d0-d3}
	fstmiad	r0!,{d0-d3}

	fstmias	r0,{s0-s3}
	fstmias	r0!,{s0-s3}

	fstmiax	r0,{d0-d3}
	fstmiax	r0!,{d0-d3}

	fstmd	r0,{d0-d3}
	fstmd	r0!,{d0-d3}

	fstms	r0,{s0-s3}
	fstms	r0!,{s0-s3}

	fstmx	r0,{d0-d3}
	fstmx	r0!,{d0-d3}

	label_fstd:
	fstd	d0,[r1]
	fstd	d0,[r1,4]
	fstd	d0,[label_fstd]
	fstd	d0,[expression.word]

	label_fsts:
	fsts	s0,[r1]
	fsts	s0,[r1,4]
	fsts	s0,[label_fsts]
	fsts	s0,[expression.word]

	fsubs	s0,s1
	fsubs	s0,s1,s2

	fsitos	s0,s1

	ftosis	s0,s1

	ftosizs	s0,s1

	ftouis	s0,s1

	ftouizs	s0,s1

	fuitos	s0,s1

	vabs.f32	s0,s1

	vadd.f32	s0,s1
	vadd.f32	s0,s1,s2

	vcmp.f32	s0,0.0
	vcmp.f32	s0,s1

	vcmpe.f32	s0,0.0
	vcmpe.f32	s0,s1

	vcvt.f32.s32	s0,s1

	vcvt.f32.u32	s0,s1

	vcvt.s32.f32	s0,s1

	vcvt.u32.f32	s0,s1

	vcvtr.s32.f32	s0,s1

	vcvtr.u32.f32	s0,s1

	vdiv.f32	s0,s1
	vdiv.f32	s0,s1,s2

	vldm	r0!,{d0-d3}
	vldm	r0!,{s0-s3}
	vldm	r0,{d0-d3}
	vldm	r0,{s0-s3}

	vldm.32	r0!,{s0-s3}
	vldm.32	r0,{s0-s3}

	vldm.64	r0!,{d0-d3}
	vldm.64	r0,{d0-d3}

	vldmdb	r0!,{d0-d3}
	vldmdb	r0!,{s0-s3}

	vldmdb.32	r0!,{s0-s3}

	vldmdb.64	r0!,{d0-d3}

	vldmea	r0!,{d0-d3}
	vldmea	r0!,{s0-s3}

	vldmea.32	r0!,{s0-s3}

	vldmea.64	r0!,{d0-d3}

	vldmfd	r0!,{d0-d3}
	vldmfd	r0!,{s0-s3}
	vldmfd	r0,{d0-d3}
	vldmfd	r0,{s0-s3}

	vldmfd.32	r0!,{s0-s3}
	vldmfd.32	r0,{s0-s3}

	vldmfd.64	r0!,{d0-d3}
	vldmfd.64	r0,{d0-d3}

	vldmia	r0!,{d0-d3}
	vldmia	r0!,{s0-s3}
	vldmia	r0,{d0-d3}
	vldmia	r0,{s0-s3}

	vldmia.32	r0!,{s0-s3}
	vldmia.32	r0,{s0-s3}

	vldmia.64	r0!,{d0-d3}
	vldmia.64	r0,{d0-d3}

	label_vldr:
	vldr	d0,[expression.word]
	vldr	d0,[label_vldr]
	vldr	d0,[r1,4]
	vldr	d0,[r1]
	vldr	s0,[expression.word]
	vldr	s0,[label_vldr]
	vldr	s0,[r1,4]
	vldr	s0,[r1]

	label_vldr.32:
	vldr.32	s0,[expression.word]
	vldr.32	s0,[label_vldr.32]
	vldr.32	s0,[r1,4]
	vldr.32	s0,[r1]

	label_vldr.64:
	vldr.64	d0,[expression.word]
	vldr.64	d0,[label_vldr.64]
	vldr.64	d0,[r1,4]
	vldr.64	d0,[r1]

	vmla.f32	s0,s1,s2

	vmls.f32	s0,s1,s2

	vmov	d0[1],r1
	vmov	r0,d1[1]
	vmov	r0,s1
	vmov	s0,r1

	vmov.32	d0[1],r1
	vmov.32	r0,d1[1]

	vmov.f32	s0,s1

	vmrs	r0,fpscr

	vmsr	fpscr,r1

	vmul.f32	s0,s1
	vmul.f32	s0,s1,s2

	vneg.f32	s0,s1

	vnmla.f32	s0,s1,s2

	vnmls.f32	s0,s1,s2

	vnmul.f32	s0,s1
	vnmul.f32	s0,s1,s2

	vpop	{d0,d2,d1}
	vpop	{s0,s2,s1}

	vpush	{d0,d2,d1}
	vpush	{s0,s2,s1}

	vsqrt.f32	s0,s1

	vstm	r0!,{d0-d3}
	vstm	r0!,{s0-s3}
	vstm	r0,{d0-d3}
	vstm	r0,{s0-s3}

	vstm.32	r0!,{s0-s3}
	vstm.32	r0,{s0-s3}

	vstm.64	r0!,{d0-d3}
	vstm.64	r0,{d0-d3}

	vstmdb	r0!,{d0-d3}
	vstmdb	r0!,{s0-s3}

	vstmdb.32	r0!,{s0-s3}

	vstmdb.64	r0!,{d0-d3}

	vstmea	r0!,{d0-d3}
	vstmea	r0!,{s0-s3}
	vstmea	r0,{d0-d3}
	vstmea	r0,{s0-s3}

	vstmea.32	r0!,{s0-s3}
	vstmea.32	r0,{s0-s3}

	vstmea.64	r0!,{d0-d3}
	vstmea.64	r0,{d0-d3}

	vstmfd	r0!,{d0-d3}
	vstmfd	r0!,{s0-s3}

	vstmfd.32	r0!,{s0-s3}

	vstmfd.64	r0!,{d0-d3}

	vstmia	r0!,{d0-d3}
	vstmia	r0!,{s0-s3}
	vstmia	r0,{d0-d3}
	vstmia	r0,{s0-s3}

	vstmia.32	r0!,{s0-s3}
	vstmia.32	r0,{s0-s3}

	vstmia.64	r0!,{d0-d3}
	vstmia.64	r0,{d0-d3}

	label_vstr:
	vstr	d0,[expression.word]
	vstr	d0,[label_vstr]
	vstr	d0,[r1,4]
	vstr	d0,[r1]
	vstr	s0,[expression.word]
	vstr	s0,[label_vstr]
	vstr	s0,[r1,4]
	vstr	s0,[r1]

	label_vstr.32:
	vstr.32	s0,[expression.word]
	vstr.32	s0,[label_vstr.32]
	vstr.32	s0,[r1,4]
	vstr.32	s0,[r1]

	label_vstr.64:
	vstr.64	d0,[expression.word]
	vstr.64	d0,[label_vstr.64]
	vstr.64	d0,[r1,4]
	vstr.64	d0,[r1]

	vsub.f32	s0,s1
	vsub.f32	s0,s1,s2

coprocessor COPRO_VFP_V1xD + COPRO_VFP_D32

	label_fldd_d32:
	fldd	d20,[r1]
	fldd	d20,[r1,4]
	fldd	d20,[label_fldd_d32]
	fldd	d20,[expression.word]

	fldmdbd	r0!,{d20-d23}

	fldmdbx	r0!,{d20-d23}

	fldmead	r0!,{d20-d23}

	fldmeax	r0!,{d20-d23}

	fldmfdd	r0,{d20-d23}
	fldmfdd	r0!,{d20-d23}

	fldmfdx	r0,{d20-d23}
	fldmfdx	r0!,{d20-d23}

	fldmiad	r0,{d20-d23}
	fldmiad	r0!,{d20-d23}

	fldmiax	r0,{d20-d23}
	fldmiax	r0!,{d20-d23}

	fldmd	r0,{d20-d23}
	fldmd	r0!,{d20-d23}

	fldmx	r0,{d20-d23}
	fldmx	r0!,{d20-d23}

	fmdhr	d20,r1

	fmdlr	d20,r1

	fmrdh	r0,d21

	fmrdl	r0,d21

	fstmdbd	r0!,{d20-d23}

	fstmdbx	r0!,{d20-d23}

	fstmead	r0,{d20-d23}
	fstmead	r0!,{d20-d23}

	fstmeax	r0,{d20-d23}
	fstmeax	r0!,{d20-d23}

	fstmfdd	r0!,{d20-d23}

	fstmfdx	r0!,{d20-d23}

	fstmiad	r0,{d20-d23}
	fstmiad	r0!,{d20-d23}

	fstmiax	r0,{d20-d23}
	fstmiax	r0!,{d20-d23}

	fstmd	r0,{d20-d23}
	fstmd	r0!,{d20-d23}

	fstmx	r0,{d20-d23}
	fstmx	r0!,{d20-d23}

	label_fstd_d32:
	fstd	d20,[r1]
	fstd	d20,[r1,4]
	fstd	d20,[label_fstd_d32]
	fstd	d20,[expression.word]

	vldm	r0!,{d20-d23}
	vldm	r0,{d20-d23}

	vldm.64	r0!,{d20-d23}
	vldm.64	r0,{d20-d23}

	vldmdb	r0!,{d20-d23}

	vldmdb.64	r0!,{d20-d23}

	vldmea	r0!,{d20-d23}

	vldmea.64	r0!,{d20-d23}

	vldmfd	r0!,{d20-d23}
	vldmfd	r0,{d20-d23}

	vldmfd.64	r0!,{d20-d23}
	vldmfd.64	r0,{d20-d23}

	vldmia	r0!,{d20-d23}
	vldmia	r0,{d20-d23}

	vldmia.64	r0!,{d20-d23}
	vldmia.64	r0,{d20-d23}

	label_vldr_d32:
	vldr	d20,[expression.word]
	vldr	d20,[label_vldr_d32]
	vldr	d20,[r1,4]
	vldr	d20,[r1]

	label_vldr.64_d32:
	vldr.64	d20,[expression.word]
	vldr.64	d20,[label_vldr.64_d32]
	vldr.64	d20,[r1,4]
	vldr.64	d20,[r1]

	vmov	d20[0],r1
	vmov	r0,d21[0]

	vmov.32	d20[0],r1
	vmov.32	r0,d21[0]

	vpop	{d5-d20}

	vpush	{d5-d20}

	vstm	r0!,{d20-d23}
	vstm	r0,{d20-d23}

	vstm.64	r0!,{d20-d23}
	vstm.64	r0,{d20-d23}

	vstmdb	r0!,{d20-d23}

	vstmdb.64	r0!,{d20-d23}

	vstmea	r0!,{d20-d23}
	vstmea	r0,{d20-d23}

	vstmea.64	r0!,{d20-d23}
	vstmea.64	r0,{d20-d23}

	vstmfd	r0!,{d20-d23}

	vstmfd.64	r0!,{d20-d23}

	vstmia	r0!,{d20-d23}
	vstmia	r0,{d20-d23}

	vstmia.64	r0!,{d20-d23}
	vstmia.64	r0,{d20-d23}

	label_vstr_d32:
	vstr	d20,[expression.word]
	vstr	d20,[label_vstr_d32]
	vstr	d20,[r1,4]
	vstr	d20,[r1]

	label_vstr.64_d32:
	vstr.64	d20,[expression.word]
	vstr.64	d20,[label_vstr.64_d32]
	vstr.64	d20,[r1,4]
	vstr.64	d20,[r1]

coprocessor COPRO_VFP_V1

	fabsd	d0,d1

	faddd	d0,d1
	faddd	d0,d1,d2

	fcmpd	d0,d1
	fcmpd	d0,0.0

	fcmped	d0,d1
	fcmped	d0,0.0

	fcmpezd	d0

	fcmpzd	d0

	fcpyd	d0,d1

	fcvtds	d0,s1

	fcvtsd	s0,d1

	fdivd	d0,d1
	fdivd	d0,d1,d2

	fmacd	d0,d1,d2

	fmscd	d0,d1,d2

	fmuld	d0,d1
	fmuld	d0,d1,d2

	fnegd	d0,d1

	fnmacd	d0,d1,d2

	fnmscd	d0,d1,d2

	fnmuld	d0,d1
	fnmuld	d0,d1,d2

	fsitod	d0,s1

	fsqrtd	d0,d1

	fsubd	d0,d1
	fsubd	d0,d1,d2

	ftosid	s0,d1

	ftosizd	s0,d1

	ftouid	s0,d1

	ftouizd	s0,d1

	fuitod	d0,s0

	vabs.f64	d0,d1

	vadd.f64	d0,d1
	vadd.f64	d0,d1,d2

	vcmp.f64	d0,0.0
	vcmp.f64	d0,d1

	vcmpe.f64	d0,0.0
	vcmpe.f64	d0,d1

	vcvt.f32.f64	s0,d1

	vcvt.f64.f32	d0,s1

	vcvt.f64.s32	d0,s1

	vcvt.f64.u32	d0,s0

	vcvt.s32.f64	s0,d1

	vcvt.u32.f64	s0,d1

	vcvtr.s32.f64	s0,d1

	vcvtr.u32.f64	s0,d1

	vdiv.f64	d0,d1
	vdiv.f64	d0,d1,d2

	vmla.f64	d0,d1,d2

	vmls.f64	d0,d1,d2

	vmov.f64	d0,d1

	vmul.f64	d0,d1
	vmul.f64	d0,d1,d2

	vneg.f64	d0,d1

	vnmla.f64	d0,d1,d2

	vnmls.f64	d0,d1,d2

	vnmul.f64	d0,d1
	vnmul.f64	d0,d1,d2

	vsqrt.f64	d0,d1

	vsub.f64	d0,d1
	vsub.f64	d0,d1,d2

coprocessor COPRO_VFP_V1 + COPRO_VFP_D32

	fabsd	d20,d21

	faddd	d20,d21
	faddd	d20,d21,d22

	fcmpd	d20,d21
	fcmpd	d20,0.0

	fcmped	d20,d21
	fcmped	d20,0.0

	fcmpezd	d20

	fcmpzd	d20

	fcpyd	d20,d21

	fcvtds	d20,s1

	fcvtsd	s0,d21

	fdivd	d20,d21
	fdivd	d20,d21,d22

	fmacd	d20,d21,d22

	fmscd	d20,d21,d22

	fmuld	d20,d21
	fmuld	d20,d21,d22

	fnegd	d20,d21

	fnmacd	d20,d21,d22

	fnmscd	d20,d21,d22

	fnmuld	d20,d21
	fnmuld	d20,d21,d22

	fsitod	d20,s1

	fsqrtd	d20,d21

	fsubd	d20,d21
	fsubd	d20,d21,d22

	ftosid	s0,d21

	ftosizd	s0,d21

	ftouid	s0,d21

	ftouizd	s0,d21

	fuitod	d20,s0

	vabs.f64	d20,d21

	vadd.f64	d20,d21
	vadd.f64	d20,d21,d22

	vcmp.f64	d20,0.0
	vcmp.f64	d20,d21

	vcmpe.f64	d20,0.0
	vcmpe.f64	d20,d21

	vcvt.f32.f64	s0,d21

	vcvt.f64.f32	d20,s1

	vcvt.f64.s32	d20,s1

	vcvt.f64.u32	d20,s0

	vcvt.s32.f64	s0,d21

	vcvt.u32.f64	s0,d21

	vcvtr.s32.f64	s0,d21

	vcvtr.u32.f64	s0,d21

	vdiv.f64	d20,d21
	vdiv.f64	d20,d21,d22

	vmla.f64	d20,d21,d22

	vmls.f64	d20,d21,d22

	vmov.f64	d20,d21

	vmul.f64	d20,d21
	vmul.f64	d20,d21,d22

	vneg.f64	d20,d21

	vnmla.f64	d20,d21,d22

	vnmls.f64	d20,d21,d22

	vnmul.f64	d20,d21
	vnmul.f64	d20,d21,d22

	vsqrt.f64	d20,d21

	vsub.f64	d20,d21
	vsub.f64	d20,d21,d22

coprocessor COPRO_VFP_V2

	fmdrr	d0,r1,r2

	fmrrd	r0,r1,d2

	fmrrs	r0,r1,{s2,s3}

	fmsrr	{s0,s1},r2,r3

	vmov	d0,r1,r2
	vmov	r0,r1,d2
	vmov	r0,r1,s2,s3
	vmov	s0,s1,r2,r3

coprocessor COPRO_VFP_V2 + COPRO_VFP_D32

	fmdrr	d20,r1,r2

	fmrrd	r0,r1,d22

	vmov	d20,r1,r2
	vmov	r0,r1,d22

coprocessor COPRO_VFP_V3

	fconsts	s0,1.0
	fconsts	s0,1

	fconstd	d0,1.0
	fconstd	d0,1

	fshtod	d0,1
	fshtod	d0,d0,1

	fshtos	s0,1
	fshtos	s0,s0,1

	fsltod	d0,1
	fsltod	d0,d0,1

	fsltos	s0,1
	fsltos	s0,s0,1

	ftoshd	d0,1
	ftoshd	d0,d0,1

	ftoshs	s0,1
	ftoshs	s0,s0,1

	ftosld	d0,1
	ftosld	d0,d0,1

	ftosls	s0,1
	ftosls	s0,s0,1

	ftouhd	d0,1
	ftouhd	d0,d0,1

	ftouhs	s0,1
	ftouhs	s0,s0,1

	ftould	d0,1
	ftould	d0,d0,1

	ftouls	s0,1
	ftouls	s0,s0,1

	fuhtod	d0,1
	fuhtod	d0,d0,1

	fuhtos	s0,1
	fuhtos	s0,s0,1

	fultod	d0,1
	fultod	d0,d0,1

	fultos	s0,1
	fultos	s0,s0,1

	vcvt.f32.s16	s0,1
	vcvt.f32.s16	s0,s0,1

	vcvt.f32.s32	s0,1
	vcvt.f32.s32	s0,s0,1

	vcvt.f32.u16	s0,1
	vcvt.f32.u16	s0,s0,1

	vcvt.f32.u32	s0,1
	vcvt.f32.u32	s0,s0,1

	vcvt.f64.s16	d0,1
	vcvt.f64.s16	d0,d0,1

	vcvt.f64.s32	d0,3
	vcvt.f64.s32	d0,d0,3

	vcvt.f64.u16	d0,1
	vcvt.f64.u16	d0,d0,1

	vcvt.f64.u32	d0,3
	vcvt.f64.u32	d0,d0,3

	vcvt.s16.f32	s0,1
	vcvt.s16.f32	s0,s0,1

	vcvt.s16.f64	d0,1
	vcvt.s16.f64	d0,d0,1

	vcvt.s32.f32	s0,1
	vcvt.s32.f32	s0,s0,1

	vcvt.s32.f64	d0,3
	vcvt.s32.f64	d0,d0,3

	vcvt.u16.f32	s0,1
	vcvt.u16.f32	s0,s0,1

	vcvt.u16.f64	d0,1
	vcvt.u16.f64	d0,d0,1

	vcvt.u32.f32	s0,1
	vcvt.u32.f32	s0,s0,1

	vcvt.u32.f64	d0,3
	vcvt.u32.f64	d0,d0,3

	vmov.f32	s0,1
	vmov.f32	s0,1.0

	vmov.f64	d0,1
	vmov.f64	d0,1.0

coprocessor COPRO_VFP_V3 + COPRO_VFP_D32

	fconstd	d20,1.0
	fconstd	d20,1

	fshtod	d20,1
	fshtod	d20,d20,1

	fsltod	d20,1
	fsltod	d20,d20,1

	ftoshd	d20,1
	ftoshd	d20,d20,1

	ftosld	d20,1
	ftosld	d20,d20,1

	ftouhd	d20,1
	ftouhd	d20,d20,1

	ftould	d20,1
	ftould	d20,d20,1

	fuhtod	d20,1
	fuhtod	d20,d20,1

	fultod	d20,1
	fultod	d20,d20,1

	vcvt.f64.s16	d20,1
	vcvt.f64.s16	d20,d20,1

	vcvt.f64.s32	d20,1
	vcvt.f64.s32	d20,d20,1

	vcvt.f64.u16	d20,1
	vcvt.f64.u16	d20,d20,1

	vcvt.f64.u32	d20,1
	vcvt.f64.u32	d20,d20,1

	vcvt.s16.f64	d20,1
	vcvt.s16.f64	d20,d20,1

	vcvt.s32.f64	d20,1
	vcvt.s32.f64	d20,d20,1

	vcvt.u16.f64	d20,1
	vcvt.u16.f64	d20,d20,1

	vcvt.u32.f64	d20,1
	vcvt.u32.f64	d20,d20,1

	vmov.f64	d20,1
	vmov.f64	d20,1.0

coprocessor COPRO_VFP_HP

	vcvtb.f32.f16	s0,s1

	vcvtb.f16.f32	s0,s1

	vcvtt.f32.f16	s0,s1

	vcvtt.f16.f32	s0,s1

coprocessor COPRO_VFP_V4

	vfma.f32	s0,s1,s2

	vfma.f64	d0,d1,d2

	vfms.f32	s0,s1,s2

	vfms.f64	d0,d1,d2

	vfnma.f32	s0,s1,s2

	vfnma.f64	d0,d1,d2

	vfnms.f32	s0,s1,s2

	vfnms.f64	d0,d1,d2

coprocessor COPRO_VFP_V4 + COPRO_VFP_D32

	vfma.f64	d20,d21,d22

	vfnma.f64	d20,d21,d22

	vfms.f64	d20,d21,d22

	vfnms.f64	d20,d21,d22

coprocessor COPRO_SIMD_V8

	vcvtm.s32.f32	s0,s1
	vcvtm.u32.f32	s0,s1
	vcvtm.s32.f64	s0,d1
	vcvtm.u32.f64	s0,d1

	vcvtp.s32.f32	s0,s1
	vcvtp.u32.f32	s0,s1
	vcvtp.s32.f64	s0,d1
	vcvtp.u32.f64	s0,d1

	vcvtn.s32.f32	s0,s1
	vcvtn.u32.f32	s0,s1
	vcvtn.s32.f64	s0,d1
	vcvtn.u32.f64	s0,d1

	vcvta.s32.f32	s0,s1
	vcvta.u32.f32	s0,s1
	vcvta.s32.f64	s0,d1
	vcvta.u32.f64	s0,d1

	vcvtb.f16.f64	s0,d1
	vcvtb.f64.f16	d0,s1

	vcvtt.f16.f64	s0,d1
	vcvtt.f64.f16	d0,s1

	vmaxnm.f32	s0,s1,s2
	vmaxnm.f64	d0,d1,d2

	vminnm.f32	s0,s1,s2
	vminnm.f64	d0,d1,d2

	vrintm.f32.f32	s0,s1
	vrintm.f64.f64	d0,d1

	vrintp.f32.f32	s0,s1
	vrintp.f64.f64	d0,d1

	vrintn.f32.f32	s0,s1
	vrintn.f64.f64	d0,d1

	vrinta.f32.f32	s0,s1
	vrinta.f64.f64	d0,d1

	vrintx.f32.f32	s0,s1
	vrintx.f64.f64	d0,d1

	vrintz.f32.f32	s0,s1
	vrintz.f64.f64	d0,d1

	vrintr.f32.f32	s0,s1
	vrintr.f64.f64	d0,d1

	vseleq.f32	s0,s1,s2
	vseleq.f64	d0,d1,d2

	vselvs.f32	s0,s1,s2
	vselvs.f64	d0,d1,d2

	vselge.f32	s0,s1,s2
	vselge.f64	d0,d1,d2

	vselgt.f32	s0,s1,s2
	vselgt.f64	d0,d1,d2
