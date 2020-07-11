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
	;MAVERICK, ARM mode, all instructions are 32-bit
	;***********************************************

	code32

coprocessor COPRO_MAVERICK

	cfabs32	c0,c1

	cfabs64	c0,c1

	cfabsd	c0,c1

	cfabss	c0,c1

	cfadd32	c0,c1,c2

	cfadd64	c0,c1,c2

	cfaddd	c0,c1,c2

	cfadds	c0,c1,c2

	cfcmp32	r1,c1,c2

	cfcmp64	r1,c1,c2

	cfcmpd	r1,c1,c2

	cfcmps	r1,c1,c2

	cfcpyd	c0,c1

	cfcpys	c0,c1

	cfcvt32d	c0,c1

	cfcvt32s	c0,c1

	cfcvt64d	c0,c1

	cfcvt64s	c0,c1

	cfcvtd32	c0,c1

	cfcvtds	c0,c1

	cfcvts32	c0,c1

	cfcvtsd	c0,c1

	label_cfldr32:
	cfldr32	c0,[r1]
	cfldr32	c0,[r1],4
	cfldr32	c0,[r1],{4}
	cfldr32	c0,[r1,4]
	cfldr32	c0,[r1,4]!
	cfldr32	c0,[label_cfldr32]
	cfldr32	c0,[expression.word]
	cfldr32	c0,[expression.word]!

	label_cfldr64:
	cfldr64	c0,[r1]
	cfldr64	c0,[r1],4
	cfldr64	c0,[r1],{4}
	cfldr64	c0,[r1,4]
	cfldr64	c0,[r1,4]!
	cfldr64	c0,[label_cfldr64]
	cfldr64	c0,[expression.word]
	cfldr64	c0,[expression.word]!

	label_cfldrd:
	cfldrd	c0,[r1]
	cfldrd	c0,[r1],4
	cfldrd	c0,[r1],{4}
	cfldrd	c0,[r1,4]
	cfldrd	c0,[r1,4]!
	cfldrd	c0,[label_cfldrd]
	cfldrd	c0,[expression.word]
	cfldrd	c0,[expression.word]!

	label_cfldrs:
	cfldrs	c0,[r1]
	cfldrs	c0,[r1],4
	cfldrs	c0,[r1],{4}
	cfldrs	c0,[r1,4]
	cfldrs	c0,[r1,4]!
	cfldrs	c0,[label_cfldrs]
	cfldrs	c0,[expression.word]
	cfldrs	c0,[expression.word]!

	cfmac32	c0,c1,c2

	cfmadd32	a0,c1,c2,c3

	cfmadda32	a0,a1,c2,c4

	cfmsc32	c0,c1,c2

	cfmsub32	a0,c1,c2,c4

	cfmsuba32	a0,a1,c2,c4

	cfmul32	c0,c1,c2

	cfmul64	c0,c1,c2

	cfmuld	c0,c1,c2

	cfmuls	c0,c1,c2

	cfmv32a	c0,a1

	cfmv32ah	c0,a1

	cfmv32al	c0,a1

	cfmv32am	c0,a1

	cfmv32sc	c0,dspsc

	cfmv64a	c0,a1

	cfmv64hr	c0,r1

	cfmv64lr	c0,r1

	cfmva32	a0,c1

	cfmva64	a0,c1

	cfmvah32	a0,c1

	cfmval32	a0,c1

	cfmvam32	a0,c1

	cfmvdhr	c0,r1

	cfmvdlr	c0,r1

	cfmvr64h	r1,c1

	cfmvr64l	r1,c1

	cfmvrdh	r1,c1

	cfmvrdl	r1,c1

	cfmvrs	r1,c1

	cfmvsc32	dspsc,c0

	cfmvsr	c0,r1

	cfneg32	c0,c1

	cfneg64	c0,c1

	cfnegd	c0,c1

	cfnegs	c0,c1

	cfrshl32	c0,c1,r3

	cfrshl64	c0,c1,r3

	cfsh32	c0,c1,2

	cfsh64	c0,c1,2

	label_cfstr32:
	cfstr32	c0,[r1]
	cfstr32	c0,[r1],4
	cfstr32	c0,[r1],{4}
	cfstr32	c0,[r1,4]
	cfstr32	c0,[r1,4]!
	cfstr32	c0,[label_cfstr32]
	cfstr32	c0,[expression.word]
	cfstr32	c0,[expression.word]!

	label_cfstr64:
	cfstr64	c0,[r1]
	cfstr64	c0,[r1],4
	cfstr64	c0,[r1],{4}
	cfstr64	c0,[r1,4]
	cfstr64	c0,[r1,4]!
	cfstr64	c0,[label_cfstr64]
	cfstr64	c0,[expression.word]
	cfstr64	c0,[expression.word]!

	label_cfstrd:
	cfstrd	c0,[r1]
	cfstrd	c0,[r1],4
	cfstrd	c0,[r1],{4}
	cfstrd	c0,[r1,4]
	cfstrd	c0,[r1,4]!
	cfstrd	c0,[label_cfstrd]
	cfstrd	c0,[expression.word]
	cfstrd	c0,[expression.word]!

	label_cfstrs:
	cfstrs	c0,[r1]
	cfstrs	c0,[r1],4
	cfstrs	c0,[r1],{4}
	cfstrs	c0,[r1,4]
	cfstrs	c0,[r1,4]!
	cfstrs	c0,[label_cfstrs]
	cfstrs	c0,[expression.word]
	cfstrs	c0,[expression.word]!

	cfsub32	c0,c1,c2

	cfsub64	c0,c1,c2

	cfsubd	c0,c1,c2

	cfsubs	c0,c1,c2

	cftruncd32	c0,c1

	cftruncs32	c0,c1
