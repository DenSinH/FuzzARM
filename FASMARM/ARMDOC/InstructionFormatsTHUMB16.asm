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

;These instructions do not show any condition or flag
;writeback ("s") syntaxes. Almost all instructions can
;be conditional. The condition code should be added at
;the end of the main opcode and before any size/type
;specifiers. For example: "addhi" and "vaddhi.i16". The
;syntax also supports the pre-UAL style of putting the
;condition before any modifiers like "s" or "fd". For
;example: "ldmhifd", "ldmfdhi" and "addhis", "addshi".

;This file can be assembled by fasmarm.

virtual at r1
	expression.dword	rd 1
	expression.word		rw 1
	expression.hword	rh 1
	expression.byte		rb 1
end virtual

	;***********************************************
	;THUMB mode, pre-UAL 16-bit instructions
	;***********************************************

	code16						;pre-UAL syntax, the 's' is otional

macro align {times(($ and 2)shr 1)dh 0xde_00}

processor CPU32_V4T

	adc	r0,r1
	adc	r0,r0,r1

	add	r0,r1,2
	add	r0,1
	add	r0,r1,r2

	and	r0,r1
	and	r0,r0,r1

	asr	r0,1
	asr	r0,r1,2
	asr	r0,r1
	asr	r0,r0,r1

	bic	r0,r1
	bic	r0,r0,r1

	eor	r0,r1
	eor	r0,r0,r1

	ldm	r0!,{r1}
	ldm	r0!,{r0}

	ldmia	r0!,{r1}
	ldmia	r0!,{r0}

	lsl	r0,1
	lsl	r0,r1,2
	lsl	r0,r1
	lsl	r0,r0,r1

	lsr	r0,1
	lsr	r0,r1,2
	lsr	r0,r1
	lsr	r0,r0,r1

	mov	r0,1
	mov	r0,r1
	mov	r0,expression.dword

	mul	r0,r1
	mul	r0,r1,r0
	mul	r0,r0,r1

	mvn	r0,r1

	neg	r0
	neg	r0,r1

	orr	r0,r1
	orr	r0,r0,r1

	ror	r0,r1
	ror	r0,r0,r1

	rsb	r0,0
	rsb	r0,r1,0

	sbc	r0,r1
	sbc	r0,r0,r1

	sub	r0,r1,2
	sub	r0,1
	sub	r0,r1,r2

	;***********************************************
	;THUMB mode, UAL 16-bit instructions
	;***********************************************

	thumb						;UAL syntax, the 's', if given, is mandatory

	adcs	r0,r1
	adcs	r0,r0,r1

	adds	r0,r1,2
	adds	r0,1
	adds	r0,r1,r2

	ands	r0,r1
	ands	r0,r0,r1

	asrs	r0,1
	asrs	r0,r1,2
	asrs	r0,r1
	asrs	r0,r0,r1

	bics	r0,r1
	bics	r0,r0,r1

	eors	r0,r1
	eors	r0,r0,r1

	ldm	r0!,{r1}
	ldm	r0,{r0}

	ldmia	r0!,{r1}
	ldmia	r0,{r0}

	lsls	r0,1
	lsls	r0,r1,2
	lsls	r0,r1
	lsls	r0,r0,r1

	lsrs	r0,1
	lsrs	r0,r1,2
	lsrs	r0,r1
	lsrs	r0,r0,r1

	movs	r0,1
	movs	r0,r1
	movs	r0,expression.dword

	muls	r0,r1
	muls	r0,r1,r0
	muls	r0,r0,r1

	mvns	r0,r1

	negs	r0
	negs	r0,r1

	orrs	r0,r1
	orrs	r0,r0,r1

	rors	r0,r1
	rors	r0,r0,r1

	rsbs	r0,0
	rsbs	r0,r1,0

	sbcs	r0,r1
	sbcs	r0,r0,r1

	subs	r0,r1,2
	subs	r0,1
	subs	r0,r1,r2

	;both pre-UAL and UAL syntaxes, no 's' is allowed

	add	r8,r9
	add	r0,sp,4
	add	sp,4
	add	sp,sp,4
	add	r0,pc,4

	adr	r0,label_adr_t16
	align
	label_adr_t16:

	bx	r0

	cmn	r0,r1

	cmp	r0,1
	cmp	r0,r1
	cmp	r8,r9

	ldr	r0,[r1]
	ldr	r0,[r1,4]
	ldr	r0,[sp]
	ldr	r0,[sp,4]
	ldr	r0,[label_ldr_t16]
	ldr	r0,[pc]
	ldr	r0,[pc,4]
	ldr	r0,[r1,r2]
	ldr	r1,[sp],4
	ldr	r15,[sp],4
	align
	label_ldr_t16:

	ldrb	r0,[r1]
	ldrb	r0,[r1,2]
	ldrb	r0,[r1,r2]

	ldrh	r0,[r1]
	ldrh	r0,[r1,2]
	ldrh	r0,[r1,r2]

	ldrsb	r0,[r1,r2]

	ldrsh	r0,[r1,r2]

	mov	r8,r9

	nop

	pop	{r0}
	pop	{r0,r15}

	push	{r0}
	push	{r0,r14}

	stm	r0!,{r1}
	stm	r0!,{r1,r2}

	stmia	r0!,{r1}
	stmia	r0!,{r1,r2}

	str	r0,[r1]
	str	r0,[r1,4]
	str	r0,[sp]
	str	r0,[sp,4]
	str	r0,[r1,r2]
	str	r1,[sp,-4]!
	str	r14,[sp,-4]!

	strb	r0,[r1]
	strb	r0,[r1,4]
	strb	r0,[r1,r2]

	strh	r0,[r1]
	strh	r0,[r1,4]
	strb	r0,[r1,r2]

	sub	sp,4
	sub	sp,sp,4

	svc	0

	swi	0

	tst	r0,r1

	bcc	label_bcc_t16
	label_bcc_t16:

	b	label_b_t16
	label_b_t16:

processor CPU32_V5T

	bkpt	0

	blx	r0

processor CPU32_V6T

	cpy	r0,r1

	rev	r0,r1

	rev16	r0,r1

	revsh	r0,r1

	sxtb	r0
	sxtb	r0,r1

	sxth	r0
	sxth	r0,r1

	uxtb	r0
	uxtb	r0,r1

	uxth	r0
	uxth	r0,r1

processor CPU32_ALIGN

	cpsie	iflags_a

	cpsid	iflags_a

	setend	le

processor CPU32_6M

	add	r0,r1

	yield

	wfe

	wfi

	sev

processor CPU32_7M

	cbnz	r0,label_cbnz_t16
	dh	0xde00
	label_cbnz_t16:

	cbz	r0,label_cbz_t16
	dh	0xde00
	label_cbz_t16:

processor CPU32_7M + CPU32_V5T

	it	cc
	bkpt	0	;dummy fill to satisfy IT checks

	ite	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itee	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	iteee	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	iteet	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itet	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itete	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itett	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itt	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itte	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	ittee	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	ittet	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	ittt	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	ittte	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	itttt	cc
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks
	bkpt	0	;dummy fill to satisfy IT checks

	;***********************************************
	;THUMBEE mode, 16-bit instructions
	;***********************************************

	thumbee

processor CPU32_T2EE

	chka	r0,r1

	hb	0
	hbl	0
	hblp	0,0
	hbp	0,0

	ldr	r0,[r1,r2,lsl 2]
	ldr	r0,[r1,-4]
	ldr	r0,[r9]
	ldr	r0,[r9,4]
	ldr	r0,[r10]
	ldr	r0,[r10,4]

	ldrb	r0,[r1,r2]

	ldrh	r0,[r1,r2,lsl 1]

	ldrsb	r0,[r1,r2]

	ldrsh	r0,[r1,r2,lsl 1]

	str	r0,[r1,r2,lsl 2]
	str	r0,[r9]
	str	r0,[r9,4]

	strb	r0,[r1,r2]

	strh	r0,[r1,r2,lsl 1]

processor CPU32_V8

	hlt	0

	sevl
	sevl.n

processor 0	;16-bit UND is always encodable, it ignores the processor directive

	und
	und	0
