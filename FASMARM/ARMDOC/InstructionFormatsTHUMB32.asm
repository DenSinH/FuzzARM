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
	;THUMB mode, 32-bit instructions
	;***********************************************

	thumb

processor CPU32_V4T

	label_bl_t32:
	bl	label_bl_t32

processor CPU32_X

	label_blx_t32:
	blx	label_blx_t32

processor CPU32_Z

	smc	0

	smi	0

processor CPU32_6M

	dmb
	dmb	sy

	dsb
	dsb	sy

	isb
	isb	sy

	mrs	r0,primask

	msr	primask,r0

processor CPU32_7M

	adc	r0,1
	adc	r0,r1
	adc	r0,r1,rrx
	adc	r0,r1,lsl 2
	adc	r0,r1,lsr 2
	adc	r0,r1,asr 2
	adc	r0,r1,ror 2
	adc	r0,r1,2
	adc	r0,r1,r2
	adc	r0,r1,r2,rrx
	adc	r0,r1,r2,lsl 3
	adc	r0,r1,r2,lsr 3
	adc	r0,r1,r2,asr 3
	adc	r0,r1,r2,ror 3

	add	r0,1
	add	r0,r1
	add	r0,r1,rrx
	add	r0,r1,lsl 2
	add	r0,r1,lsr 2
	add	r0,r1,asr 2
	add	r0,r1,ror 2
	add	r0,r1,2
	add	r0,r1,r2
	add	r0,r1,r2,rrx
	add	r0,r1,r2,lsl 3
	add	r0,r1,r2,lsr 3
	add	r0,r1,r2,asr 3
	add	r0,r1,r2,ror 3

	addw	r0,1
	addw	r0,r1,2

	label_adr_t32:
	adr	r0,label_adr_t32

	and	r0,1
	and	r0,r1
	and	r0,r1,rrx
	and	r0,r1,lsl 2
	and	r0,r1,lsr 2
	and	r0,r1,asr 2
	and	r0,r1,ror 2
	and	r0,r1,2
	and	r0,r1,r2
	and	r0,r1,r2,rrx
	and	r0,r1,r2,lsl 3
	and	r0,r1,r2,lsr 3
	and	r0,r1,r2,asr 3
	and	r0,r1,r2,ror 3

	asr	r0,1
	asr	r0,r1
	asr	r0,r1,2
	asr	r0,r1,r2

	label_b_t32:
	b	label_b_t32

	label_bcc_t32:
	bcc	label_bcc_t32

	bfc	r0,1,2

	bfi	r0,r1,2,3

	bic	r0,1
	bic	r0,r1
	bic	r0,r1,rrx
	bic	r0,r1,lsl 2
	bic	r0,r1,lsr 2
	bic	r0,r1,asr 2
	bic	r0,r1,ror 2
	bic	r0,r1,2
	bic	r0,r1,r2
	bic	r0,r1,r2,rrx
	bic	r0,r1,r2,lsl 3
	bic	r0,r1,r2,lsr 3
	bic	r0,r1,r2,asr 3
	bic	r0,r1,r2,ror 3

	cdp	p9,1,c2,c3,c4
	cdp	p9,1,c2,c3,c4,5

	cdp2	p9,1,c2,c3,c4
	cdp2	p9,1,c2,c3,c4,5

	clrex

	clz	r0,r1

	cmn	r0,1
	cmn	r0,r1
	cmn	r0,r1,rrx
	cmn	r0,r1,lsl 2
	cmn	r0,r1,lsr 2
	cmn	r0,r1,asr 2
	cmn	r0,r1,ror 2

	cmp	r0,1
	cmp	r0,r1
	cmp	r0,r1,rrx
	cmp	r0,r1,lsl 2
	cmp	r0,r1,lsr 2
	cmp	r0,r1,asr 2
	cmp	r0,r1,ror 2

	cpy	r0,r1

	dbg	0

	eor	r0,1
	eor	r0,r1
	eor	r0,r1,rrx
	eor	r0,r1,lsl 2
	eor	r0,r1,lsr 2
	eor	r0,r1,asr 2
	eor	r0,r1,ror 2
	eor	r0,r1,2
	eor	r0,r1,r2
	eor	r0,r1,r2,rrx
	eor	r0,r1,r2,lsl 3
	eor	r0,r1,r2,lsr 3
	eor	r0,r1,r2,asr 3
	eor	r0,r1,r2,ror 3

	label_ldc_t32:
	ldc	p9,c1,[r2]
	ldc	p9,c1,[r2],4
	ldc	p9,c1,[r2],{4}
	ldc	p9,c1,[r2,4]
	ldc	p9,c1,[r2,4]!
	ldc	p9,c1,[label_ldc_t32]
	ldc	p9,c1,[expression.word]
	ldc	p9,c1,[expression.word]!

	label_ldc2_t32:
	ldc2	p9,c1,[r2]
	ldc2	p9,c1,[r2],4
	ldc2	p9,c1,[r2],{4}
	ldc2	p9,c1,[r2,4]
	ldc2	p9,c1,[r2,4]!
	ldc2	p9,c1,[label_ldc2_t32]
	ldc2	p9,c1,[expression.word]
	ldc2	p9,c1,[expression.word]!

	label_ldc2l_t32:
	ldc2l	p9,c1,[r2]
	ldc2l	p9,c1,[r2],4
	ldc2l	p9,c1,[r2],{4}
	ldc2l	p9,c1,[r2,4]
	ldc2l	p9,c1,[r2,4]!
	ldc2l	p9,c1,[label_ldc2l_t32]
	ldc2l	p9,c1,[expression.word]
	ldc2l	p9,c1,[expression.word]!

	label_ldcl_t32:
	ldcl	p9,c1,[r2]
	ldcl	p9,c1,[r2],4
	ldcl	p9,c1,[r2],{4}
	ldcl	p9,c1,[r2,4]
	ldcl	p9,c1,[r2,4]!
	ldcl	p9,c1,[label_ldcl_t32]
	ldcl	p9,c1,[expression.word]
	ldcl	p9,c1,[expression.word]!

	ldm	r0,{r1}
	ldm	r0,{r1,r2}
	ldm	r0,{r1-r3}
	ldm	r0,{r1-r3,r5}
	ldm	r0!,{r1}
	ldm	r0!,{r1,r2}
	ldm	r0!,{r1-r3}
	ldm	r0!,{r1-r3,r5}

	ldmia	r0,{r1}
	ldmia	r0,{r1,r2}
	ldmia	r0,{r1-r3}
	ldmia	r0,{r1-r3,r5}
	ldmia	r0!,{r1}
	ldmia	r0!,{r1,r2}
	ldmia	r0!,{r1-r3}
	ldmia	r0!,{r1-r3,r5}

	ldmdb	r0,{r1}
	ldmdb	r0,{r1,r2}
	ldmdb	r0,{r1-r3}
	ldmdb	r0,{r1-r3,r5}
	ldmdb	r0!,{r1}
	ldmdb	r0!,{r1,r2}
	ldmdb	r0!,{r1-r3}
	ldmdb	r0!,{r1-r3,r5}

	ldmea	r0,{r1}
	ldmea	r0,{r1,r2}
	ldmea	r0,{r1-r3}
	ldmea	r0,{r1-r3,r5}
	ldmea	r0!,{r1}
	ldmea	r0!,{r1,r2}
	ldmea	r0!,{r1-r3}
	ldmea	r0!,{r1-r3,r5}

	ldmfd	r0,{r1}
	ldmfd	r0,{r1,r2}
	ldmfd	r0,{r1-r3}
	ldmfd	r0,{r1-r3,r5}
	ldmfd	r0!,{r1}
	ldmfd	r0!,{r1,r2}
	ldmfd	r0!,{r1-r3}
	ldmfd	r0!,{r1-r3,r5}

	label_ldr_t32:
	ldr	r0,[r1]
	ldr	r0,[r1],2
	ldr	r0,[r1,2]
	ldr	r0,[r1,2]!
	ldr	r0,[r1,r2]
	ldr	r0,[r1,r2,lsl 3]
	ldr	r0,[label_ldr_t32]
	ldr	r0,[expression.word]
	ldr	r0,[expression.word]!

	label_ldrb_t32:
	ldrb	r0,[r1]
	ldrb	r0,[r1],2
	ldrb	r0,[r1,2]
	ldrb	r0,[r1,2]!
	ldrb	r0,[r1,r2]
	ldrb	r0,[r1,r2,lsl 3]
	ldrb	r0,[label_ldrb_t32]
	ldrb	r0,[expression.byte]
	ldrb	r0,[expression.byte]!

	ldrb	r0,[r13]
	ldrb	r0,[r13,2]
	ldrb	r0,[r13,r2]

	ldrbt	r0,[r1]
	ldrbt	r0,[r1,2]
	ldrbt	r0,[expression.byte]

	label_ldrd_t32:
	ldrd	r0,[r1]
	ldrd	r0,[r2],4
	ldrd	r0,[r1,4]
	ldrd	r0,[r2,4]!
	ldrd	r0,[label_ldrd_t32]
	ldrd	r2,[expression.dword]
	ldrd	r2,[expression.dword]!
	ldrd	r0,r1,[r2]
	ldrd	r0,r1,[r2],4
	ldrd	r0,r1,[r2,4]
	ldrd	r0,r1,[r2,4]!
	ldrd	r0,r1,[label_ldrd_t32]
	ldrd	r0,r2,[expression.dword]
	ldrd	r0,r2,[expression.dword]!

	ldrex	r0,[r1]
	ldrex	r0,[r1,4]
	ldrex	r0,[expression.word]

	label_ldrh_t32:
	ldrh	r0,[r1]
	ldrh	r0,[r1],2
	ldrh	r0,[r1,2]
	ldrh	r0,[r1,2]!
	ldrh	r0,[r1,r2]
	ldrh	r0,[r1,r2,lsl 3]
	ldrh	r0,[label_ldrh_t32]
	ldrh	r0,[expression.hword]
	ldrh	r0,[expression.hword]!

	ldrh	r0,[r13]
	ldrh	r0,[r13,2]
	ldrh	r0,[r13,r2]

	ldrht	r0,[r1]
	ldrht	r0,[r1,2]
	ldrht	r0,[expression.hword]

	label_ldrsb_t32:
	ldrsb	r0,[r1]
	ldrsb	r0,[r1],2
	ldrsb	r0,[r1,2]
	ldrsb	r0,[r1,2]!
	ldrsb	r0,[r1,r2]
	ldrsb	r0,[r1,r2,lsl 3]
	ldrsb	r0,[label_ldrsb_t32]
	ldrsb	r0,[expression.byte]
	ldrsb	r0,[expression.byte]!

	ldrsbt	r0,[r1]
	ldrsbt	r0,[r1,2]
	ldrsbt	r0,[expression.byte]

	label_ldrsh_t32:
	ldrsh	r0,[r1]
	ldrsh	r0,[r1],2
	ldrsh	r0,[r1,2]
	ldrsh	r0,[r1,2]!
	ldrsh	r0,[r1,r2]
	ldrsh	r0,[r1,r2,lsl 3]
	ldrsh	r0,[label_ldrsh_t32]
	ldrsh	r0,[expression.hword]
	ldrsh	r0,[expression.hword]!

	ldrsht	r0,[r1]
	ldrsht	r0,[r1,2]
	ldrsht	r0,[expression.hword]

	ldrt	r0,[r1]
	ldrt	r0,[r1,2]
	ldrt	r0,[expression.word]

	lsl	r0,1
	lsl	r0,r1
	lsl	r0,r1,2
	lsl	r0,r1,r2

	lsr	r0,1
	lsr	r0,r1
	lsr	r0,r1,2
	lsr	r0,r1,r2

	mcr	p9,1,r2,c3,c4
	mcr	p9,1,r2,c3,c4,5

	mcr2	p9,1,r2,c3,c4
	mcr2	p9,1,r2,c3,c4,5

	mcrr	p9,1,r2,r3,c4

	mcrr2	p9,1,r2,r3,c4

	mla	r0,r1,r2,r3

	mls	r0,r1,r2,r3

	mov	r0,1
	mov	r0,r1
	mov	r0,r1,rrx
	mov	r0,r1,lsl 2
	mov	r0,r1,lsr 2
	mov	r0,r1,asr 2
	mov	r0,r1,ror 2
	mov	r0,r1,lsl r2
	mov	r0,r1,lsr r2
	mov	r0,r1,asr r2
	mov	r0,r1,ror r2
	mov	r0,expression.word

	movt	r0,1

	movw	r0,1

	mrc	p9,1,r2,c3,c4
	mrc	p9,1,r15,c3,c4,5

	mrc2	p9,1,r2,c3,c4
	mrc2	p9,1,r15,c3,c4,5

	mrrc	p9,1,r2,r3,c4

	mrrc2	p9,1,r2,r3,c4

	mrs	r0,basepri

	msr	basepri,r0

	mul	r0,r1
	mul	r0,r1,r2

	mvn	r0,1
	mvn	r0,r1
	mvn	r0,r1,rrx
	mvn	r0,r1,lsl 2
	mvn	r0,r1,lsr 2
	mvn	r0,r1,asr 2
	mvn	r0,r1,ror 2

	neg	r0
	neg	r0,r1

	nop

	orn	r0,1
	orn	r0,r1
	orn	r0,r1,rrx
	orn	r0,r1,lsl 2
	orn	r0,r1,lsr 2
	orn	r0,r1,asr 2
	orn	r0,r1,ror 2
	orn	r0,r1,2
	orn	r0,r1,r2
	orn	r0,r1,r2,rrx
	orn	r0,r1,r2,lsl 3
	orn	r0,r1,r2,lsr 3
	orn	r0,r1,r2,asr 3
	orn	r0,r1,r2,ror 3

	orr	r0,1
	orr	r0,r1
	orr	r0,r1,rrx
	orr	r0,r1,lsl 2
	orr	r0,r1,lsr 2
	orr	r0,r1,asr 2
	orr	r0,r1,ror 2
	orr	r0,r1,2
	orr	r0,r1,r2
	orr	r0,r1,r2,rrx
	orr	r0,r1,r2,lsl 3
	orr	r0,r1,r2,lsr 3
	orr	r0,r1,r2,asr 3
	orr	r0,r1,r2,ror 3

	label_pld_t32:
	pld	[r1]
	pld	[r1,2]
	pld	[r1,r2]
	pld	[r1,r2,lsl 3]
	pld	[label_pld_t32]
	pld	[expression.byte]

	pop	{r0}
	pop	{r0,r1}
	pop	{r0-r2}
	pop	{r0-r2,r4}

	push	{r0}
	push	{r0,r1}
	push	{r0-r2}
	push	{r0-r2,r4}

	rbit	r0,r1

	rev	r0,r1

	rev16	r0,r1

	revsh	r0,r1

	ror	r0,1
	ror	r0,r1
	ror	r0,r1,2
	ror	r0,r1,r2

	rrx	r0
	rrx	r0,r1

	rsb	r0,1
	rsb	r0,r1
	rsb	r0,r1,rrx
	rsb	r0,r1,lsl 2
	rsb	r0,r1,lsr 2
	rsb	r0,r1,asr 2
	rsb	r0,r1,ror 2
	rsb	r0,r1,2
	rsb	r0,r1,r2
	rsb	r0,r1,r2,rrx
	rsb	r0,r1,r2,lsl 3
	rsb	r0,r1,r2,lsr 3
	rsb	r0,r1,r2,asr 3
	rsb	r0,r1,r2,ror 3

	sbc	r0,1
	sbc	r0,r1
	sbc	r0,r1,rrx
	sbc	r0,r1,lsl 2
	sbc	r0,r1,lsr 2
	sbc	r0,r1,asr 2
	sbc	r0,r1,ror 2
	sbc	r0,r1,2
	sbc	r0,r1,r2
	sbc	r0,r1,r2,rrx
	sbc	r0,r1,r2,lsl 3
	sbc	r0,r1,r2,lsr 3
	sbc	r0,r1,r2,asr 3
	sbc	r0,r1,r2,ror 3

	sbfx	r0,r1,2,3

	sev

	smlal	r0,r1,r2,r3

	smull	r0,r1,r2,r3

	label_stc_t32:
	stc	p9,c1,[r2]
	stc	p9,c1,[r2],4
	stc	p9,c1,[r2],{4}
	stc	p9,c1,[r2,4]
	stc	p9,c1,[r2,4]!
	stc	p9,c1,[label_stc_t32]
	stc	p9,c1,[expression.word]
	stc	p9,c1,[expression.word]!

	label_stc2_t32:
	stc2	p9,c1,[r2]
	stc2	p9,c1,[r2],4
	stc2	p9,c1,[r2],{4}
	stc2	p9,c1,[r2,4]
	stc2	p9,c1,[r2,4]!
	stc2	p9,c1,[label_stc2_t32]
	stc2	p9,c1,[expression.word]
	stc2	p9,c1,[expression.word]!

	label_stc2l_t32:
	stc2l	p9,c1,[r2]
	stc2l	p9,c1,[r2],4
	stc2l	p9,c1,[r2],{4}
	stc2l	p9,c1,[r2,4]
	stc2l	p9,c1,[r2,4]!
	stc2l	p9,c1,[label_stc2l_t32]
	stc2l	p9,c1,[expression.word]
	stc2l	p9,c1,[expression.word]!

	label_stcl_t32:
	stcl	p9,c1,[r2]
	stcl	p9,c1,[r2],4
	stcl	p9,c1,[r2],{4}
	stcl	p9,c1,[r2,4]
	stcl	p9,c1,[r2,4]!
	stcl	p9,c1,[label_stcl_t32]
	stcl	p9,c1,[expression.word]
	stcl	p9,c1,[expression.word]!

	stm	r0,{r1}
	stm	r0,{r1,r2}
	stm	r0,{r1-r3}
	stm	r0,{r1-r3,r5}
	stm	r0!,{r1}
	stm	r0!,{r1,r2}
	stm	r0!,{r1-r3}
	stm	r0!,{r1-r3,r5}

	stmia	r0,{r1}
	stmia	r0,{r1,r2}
	stmia	r0,{r1-r3}
	stmia	r0,{r1-r3,r5}
	stmia	r0!,{r1}
	stmia	r0!,{r1,r2}
	stmia	r0!,{r1-r3}
	stmia	r0!,{r1-r3,r5}

	stmdb	r0,{r1}
	stmdb	r0,{r1,r2}
	stmdb	r0,{r1-r3}
	stmdb	r0,{r1-r3,r5}
	stmdb	r0!,{r1}
	stmdb	r0!,{r1,r2}
	stmdb	r0!,{r1-r3}
	stmdb	r0!,{r1-r3,r5}

	stmea	r0,{r1}
	stmea	r0,{r1,r2}
	stmea	r0,{r1-r3}
	stmea	r0,{r1-r3,r5}
	stmea	r0!,{r1}
	stmea	r0!,{r1,r2}
	stmea	r0!,{r1-r3}
	stmea	r0!,{r1-r3,r5}

	stmfd	r0,{r1}
	stmfd	r0,{r1,r2}
	stmfd	r0,{r1-r3}
	stmfd	r0,{r1-r3,r5}
	stmfd	r0!,{r1}
	stmfd	r0!,{r1,r2}
	stmfd	r0!,{r1-r3}
	stmfd	r0!,{r1-r3,r5}

	str	r0,[r1]
	str	r0,[r1],2
	str	r0,[r1,2]
	str	r0,[r1,2]!
	str	r0,[r1,r2]
	str	r0,[r1,r2,lsl 3]
	str	r0,[expression.word]
	str	r0,[expression.word]!

	strb	r0,[r1]
	strb	r0,[r1],2
	strb	r0,[r1,2]
	strb	r0,[r1,2]!
	strb	r0,[r1,r2]
	strb	r0,[r1,r2,lsl 3]
	strb	r0,[expression.byte]
	strb	r0,[expression.byte]!

	strbt	r0,[r1]
	strbt	r0,[r1,2]
	strbt	r0,[expression.byte]

	strd	r0,[r1]
	strd	r0,[r2],4
	strd	r0,[r1,4]
	strd	r0,[r2,4]!
	strd	r2,[expression.dword]
	strd	r2,[expression.dword]!
	strd	r0,r1,[r2]
	strd	r0,r1,[r2],4
	strd	r0,r1,[r2,4]
	strd	r0,r1,[r2,4]!
	strd	r0,r2,[expression.dword]
	strd	r0,r2,[expression.dword]!

	strex	r0,r1,[r2]
	strex	r0,r1,[r2,4]
	strex	r2,r4,[expression.word]

	strh	r0,[r1]
	strh	r0,[r1],2
	strh	r0,[r1,2]
	strh	r0,[r1,2]!
	strh	r0,[r1,r2]
	strh	r0,[r1,r2,lsl 3]
	strh	r0,[expression.hword]
	strh	r0,[expression.hword]!

	strht	r0,[r1]
	strht	r0,[r1,2]
	strht	r0,[expression.hword]

	strt	r0,[r1]
	strt	r0,[r1,2]
	strt	r0,[expression.word]

	sub	r0,1
	sub	r0,r1
	sub	r0,r1,rrx
	sub	r0,r1,lsl 2
	sub	r0,r1,lsr 2
	sub	r0,r1,asr 2
	sub	r0,r1,ror 2
	sub	r0,r1,2
	sub	r0,r1,r2
	sub	r0,r1,r2,rrx
	sub	r0,r1,r2,lsl 3
	sub	r0,r1,r2,lsr 3
	sub	r0,r1,r2,asr 3
	sub	r0,r1,r2,ror 3

	subw	r0,1
	subw	r0,r1,2

	sxtb	r0,r1
	sxtb	r0,r1,ror 8

	sxth	r0,r1
	sxth	r0,r1,ror 8

	tbb	[r0,r1]

	tbh	[r0,r1,lsl 1]

	teq	r0,1
	teq	r0,r1
	teq	r0,r1,rrx
	teq	r0,r1,lsl 2
	teq	r0,r1,lsr 2
	teq	r0,r1,asr 2
	teq	r0,r1,ror 2

	tst	r0,1
	tst	r0,r1
	tst	r0,r1,rrx
	tst	r0,r1,lsl 2
	tst	r0,r1,lsr 2
	tst	r0,r1,asr 2
	tst	r0,r1,ror 2

	ubfx	r0,r1,2,3

	umlal	r0,r1,r2,r3

	umull	r0,r1,r2,r3

	und.w
	und	0x100

	uxtb	r0,r1
	uxtb	r0,r1,ror 8

	uxth	r0,r1
	uxth	r0,r1,ror 8

	wfe

	wfi

	yield

processor CPU32_T2

	bxj	r0

	cps	0

	cpsid	iflags_a
	cpsid	iflags_a,0

	cpsie	iflags_a
	cpsie	iflags_a,0

	mrs	r0,cpsr
	mrs	r0,spsr

	msr	cpsr,r1
	msr	cpsr_fsxc,r1

	pkhbt	r0,r1
	pkhbt	r0,r1,lsl 3
	pkhbt	r0,r1,r2
	pkhbt	r0,r1,r2,lsl 3

	pkhtb	r0,r1
	pkhtb	r0,r1,asr 3
	pkhtb	r0,r1,r2
	pkhtb	r0,r1,r2,asr 3

	qadd	r0,r1
	qadd	r0,r1,r2

	qadd16	r0,r1
	qadd16	r0,r1,r2

	qadd8	r0,r1
	qadd8	r0,r1,r2

	qaddsubx	r0,r1
	qaddsubx	r0,r1,r2

	qasx	r0,r1
	qasx	r0,r1,r2

	qdadd	r0,r1
	qdadd	r0,r1,r2

	qdsub	r0,r1
	qdsub	r0,r1,r2

	qsub	r0,r1
	qsub	r0,r1,r2

	qsax	r0,r1
	qsax	r0,r1,r2

	qsub16	r0,r1
	qsub16	r0,r1,r2

	qsub8	r0,r1
	qsub8	r0,r1,r2

	qsubaddx	r0,r1
	qsubaddx	r0,r1,r2

	rfe	r0
	rfe	r0!

	rfedb	r0
	rfedb	r0!

	rfeea	r0
	rfeea	r0!

	rfefd	r0
	rfefd	r0!

	rfeia	r0
	rfeia	r0!

	sadd16	r0,r1
	sadd16	r0,r1,r2

	sadd8	r0,r1
	sadd8	r0,r1,r2

	saddsubx	r0,r1
	saddsubx	r0,r1,r2

	sasx	r0,r1
	sasx	r0,r1,r2

	sel	r0,r1
	sel	r0,r1,r2

	shadd16	r0,r1
	shadd16	r0,r1,r2

	shadd8	r0,r1
	shadd8	r0,r1,r2

	shaddsubx	r0,r1
	shaddsubx	r0,r1,r2

	shasx	r0,r1
	shasx	r0,r1,r2

	shsax	r0,r1
	shsax	r0,r1,r2

	shsub16	r0,r1
	shsub16	r0,r1,r2

	shsub8	r0,r1
	shsub8	r0,r1,r2

	shsubaddx	r0,r1
	shsubaddx	r0,r1,r2

	smlad	r0,r1,r2,r3

	smladx	r0,r1,r2,r3

	smlabb	r0,r1,r2,r3

	smlabt	r0,r1,r2,r3

	smlalbb	r0,r1,r2,r3

	smlalbt	r0,r1,r2,r3

	smlald	r0,r1,r2,r3

	smlaldx	r0,r1,r2,r3

	smlaltb	r0,r1,r2,r3

	smlaltt	r0,r1,r2,r3

	smlatb	r0,r1,r2,r3

	smlatt	r0,r1,r2,r3

	smlawb	r0,r1,r2,r3

	smlawt	r0,r1,r2,r3

	smlsd	r0,r1,r2,r3

	smlsdx	r0,r1,r2,r3

	smlsld	r0,r1,r2,r3

	smlsldx	r0,r1,r2,r3

	smmla	r0,r1,r2,r3

	smmlar	r0,r1,r2,r3

	smmls	r0,r1,r2,r3

	smmlsr	r0,r1,r2,r3

	smmul	r0,r1
	smmul	r0,r1,r2

	smmulr	r0,r1
	smmulr	r0,r1,r2

	smuad	r0,r1
	smuad	r0,r1,r2

	smuadx	r0,r1
	smuadx	r0,r1,r2

	smulbb	r0,r1
	smulbb	r0,r1,r2

	smulbt	r0,r1
	smulbt	r0,r1,r2

	smultb	r0,r1
	smultb	r0,r1,r2

	smultt	r0,r1
	smultt	r0,r1,r2

	smulwb	r0,r1
	smulwb	r0,r1,r2

	smulwt	r0,r1
	smulwt	r0,r1,r2

	smusd	r0,r1
	smusd	r0,r1,r2

	smusdx	r0,r1
	smusdx	r0,r1,r2

	srs	0
	srs	0 !
	srs	sp,0
	srs	sp!,0

	srsdb	0
	srsdb	0 !
	srsdb	sp,0
	srsdb	sp!,0

	srsea	0
	srsea	0 !
	srsea	sp,0
	srsea	sp!,0

	srsfd	0
	srsfd	0 !
	srsfd	sp,0
	srsfd	sp!,0

	srsia	0
	srsia	0 !
	srsia	sp,0
	srsia	sp!,0

	ssat	r0,1,r2
	ssat	r0,1,r2,lsl 3
	ssat	r0,1,r2,asr 3

	ssat16	r0,1,r2

	ssax	r0,r1
	ssax	r0,r1,r2

	ssub16	r0,r1
	ssub16	r0,r1,r2

	ssub8	r0,r1
	ssub8	r0,r1,r2

	ssubaddx	r0,r1
	ssubaddx	r0,r1,r2

	sxtab	r0,r1,r2
	sxtab	r0,r1,r2,ror 8

	sxtab16	r0,r1,r2
	sxtab16	r0,r1,r2,ror 8

	sxtah	r0,r1,r2
	sxtah	r0,r1,r2,ror 8

	sxtb16	r0,r1
	sxtb16	r0,r1,ror 8

	uadd16	r0,r1
	uadd16	r0,r1,r2

	uadd8	r0,r1
	uadd8	r0,r1,r2

	uaddsubx	r0,r1
	uaddsubx	r0,r1,r2

	uasx	r0,r1
	uasx	r0,r1,r2

	uhadd16	r0,r1
	uhadd16	r0,r1,r2

	uhadd8	r0,r1
	uhadd8	r0,r1,r2

	uhaddsubx	r0,r1
	uhaddsubx	r0,r1,r2

	uhasx	r0,r1
	uhasx	r0,r1,r2

	uhsax	r0,r1
	uhsax	r0,r1,r2

	uhsub16	r0,r1
	uhsub16	r0,r1,r2

	uhsub8	r0,r1
	uhsub8	r0,r1,r2

	uhsubaddx	r0,r1
	uhsubaddx	r0,r1,r2

	umaal	r0,r1,r2,r3

	uqadd16	r0,r1
	uqadd16	r0,r1,r2

	uqadd8	r0,r1
	uqadd8	r0,r1,r2

	uqaddsubx	r0,r1
	uqaddsubx	r0,r1,r2

	uqasx	r0,r1
	uqasx	r0,r1,r2

	uqsax	r0,r1
	uqsax	r0,r1,r2

	uqsub16	r0,r1
	uqsub16	r0,r1,r2

	uqsub8	r0,r1
	uqsub8	r0,r1,r2

	uqsubaddx	r0,r1
	uqsubaddx	r0,r1,r2

	usad8	r0,r1,r2

	usada8	r0,r1,r2,r3

	usat	r0,1,r2
	usat	r0,1,r2,lsl 3
	usat	r0,1,r2,asr 3

	usat16	r0,1,r2

	usax	r0,r1
	usax	r0,r1,r2

	usub16	r0,r1
	usub16	r0,r1,r2

	usub8	r0,r1
	usub8	r0,r1,r2

	usubaddx	r0,r1
	usubaddx	r0,r1,r2

	uxtab	r0,r1,r2
	uxtab	r0,r1,r2,ror 8

	uxtab16	r0,r1,r2
	uxtab16	r0,r1,r2,ror 8

	uxtah	r0,r1,r2
	uxtah	r0,r1,r2,ror 8

	uxtb16	r0,r1
	uxtb16	r0,r1,ror 8

processor CPU32_V7

	ldrexd	r0,[r2]
	ldrexd	r0,r1,[r2]

	label_pli_t32:
	pli	[r1]
	pli	[r1,2]
	pli	[r1,r2]
	pli	[r1,r2,lsl 3]
	pli	[label_pli_t32]
	pli	[expression.byte]

	strexd	r0,r1,[r3]
	strexd	r0,r1,r2,[r3]

processor CPU32_SYNC

	ldrexb	r0,[r1]
	ldrexb	r0,[r1,0]
	ldrexb	r0,byte[expression.dword]

	ldrexh	r0,[r1]
	ldrexh	r0,[r1,0]
	ldrexh	r0,hword[expression.dword]

	strexb	r0,r1,[r2]
	strexb	r0,r1,[r2,0]
	strexb	r0,r1,byte[expression.dword]

	strexh	r0,r1,[r2]
	strexh	r0,r1,[r2,0]
	strexh	r0,r1,hword[expression.dword]

processor CPU32_DIV

	sdiv	r0,r1
	sdiv	r0,r1,r2

	udiv	r0,r1
	udiv	r0,r1,r2

processor CPU32_T2EE

	enterx

	leavex

processor CPU32_MP

	pldw	[r1]
	pldw	[r1,2]
	pldw	[r1,r2]
	pldw	[r1,r2,lsl 3]
	pldw	[expression.byte]

processor CPU32_V8

	dcps1
	dcps2
	dcps3

	lda	r0,[r1]
	ldab	r0,[r1]
	ldah	r0,[r1]

	ldaex	r0,[r1]
	ldaexb	r0,[r1]
	ldaexh	r0,[r1]
	ldaexd	r0,[r2]
	ldaexd	r0,r1,[r2]

	sevl.w

	stl	r0,[r1]
	stlb	r0,[r1]
	stlh	r0,[r1]

	stlex	r2,r0,[r3]
	stlexb	r2,r0,[r3]
	stlexh	r2,r0,[r3]
	stlexd	r2,r0,[r3]
	stlexd	r2,r0,r1,[r3]

processor CPU32_CRC

	crc32b	r0,r1,r2
	crc32h	r0,r1,r2
	crc32w	r0,r1,r2

	crc32cb	r0,r1,r2
	crc32ch	r0,r1,r2
	crc32cw	r0,r1,r2
