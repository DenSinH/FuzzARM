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

;These instructions show the condition or flag
;writeback ("s") syntaxes. Only the branch (b.cc)
;instruction can be conditional. The condition code
;should be added at the end of the main opcode. For
;example: "b.hi".

;This file can be assembled by fasmarm.

label expression.byte   byte   at x2+1
label expression.hword  hword  at x2+2
label expression.word   word   at x2+4
label expression.dword  dword  at x2+8
label expression.qword  qword  at x2+16
label expression.dqword dqword at x2+32

	;**************************************************
	;ARM64 mode, all instructions are 32-bits in length
	;**************************************************

	code64

processor CPU64_V8

	adc	w0,w1,w2
	adc	x0,x1,x2

	adcs	w0,w1,w2
	adcs	x0,x1,x2

	add	sp,sp,0x123
	add	sp,x2,0x123
	add	w1,w2,0x123
	add	w4,w8,0x123,lsl 12
	add	wsp,w2,0x123
	add	wsp,wsp,0x123
	add	w1,w2,wzr
	add	w1,w2,w3
	add	w1,w2,w3,asr 1
	add	w1,w2,w3,lsl 1
	add	w1,w2,w3,lsr 1
	add	w1,w2,w3,sxtb
	add	w1,w2,w3,sxtb 1
	add	w1,w2,w3,sxth
	add	w1,w2,w3,sxth 1
	add	w1,w2,w3,sxtw
	add	w1,w2,w3,sxtw 1
	add	w1,w2,w3,uxtb
	add	w1,w2,w3,uxtb 1
	add	w1,w2,w3,uxth
	add	w1,w2,w3,uxth 1
	add	w1,w2,w3,uxtw
	add	w1,w2,w3,uxtw 1
	add	w1,wsp,w2,uxtw 2
	add	w1,wsp,w3,uxtw
	add	w1,wsp,w3,uxtw 1
	add	wsp,w2,w3,uxtw
	add	wsp,wsp,w3,uxtw
	add	wzr,w2,w3
	add	wzr,w2,wzr
	add	wzr,wzr,w3
	add	wzr,wzr,wzr
	add	x1,x2,x3
	add	x1,x2,0x123
	add	x1,x2,0xFFF
	add	x1,x2,0xFFF,lsl 12
	add	x1,sp,0x123
	add	x1,sp,x3,uxtx
	add	x1,sp,x3,uxtx 4
	add	x1,x2,w3,sxtb
	add	x1,x2,w3,sxtb 2
	add	x1,x2,w3,sxth
	add	x1,x2,w3,sxth 2
	add	x1,x2,w3,sxtw
	add	x1,x2,w3,sxtw 2
	add	x1,x2,w3,uxtb
	add	x1,x2,w3,uxtb 2
	add	x1,x2,w3,uxth
	add	x1,x2,w3,uxth 2
	add	x1,x2,w3,uxtw
	add	x1,x2,w3,uxtw 2
	add	x1,x2,x3,asr 1
	add	x1,x2,x3,asr 63
	add	x1,x2,x3,lsl 1
	add	x1,x2,x3,lsr 1
	add	x1,x2,x3,sxtx
	add	x1,x2,x3,sxtx 3
	add	x1,x2,x3,uxtx
	add	x1,x2,x3,uxtx 2

	adds	w1,w2,w3
	adds	w1,w2,wzr
	adds	w1,wsp,0x123
	adds	w1,wsp,w3,uxtw
	adds	w1,wsp,w2,uxtw 2
	adds	w1,wzr,w3
	adds	w1,wzr,wzr
	adds	w8,w16,0x123,lsl 12
	adds	x8,x16,0x123,lsl 12
	adds	x1,x2,x3,asr 63

	label_adr:
	adr	x1,label_adr

	adrp	x1,$

	and	w1,w2,0x0001FE00
	and	w1,w2,w3
	and	w1,w2,w3,asr 4
	and	w1,w2,w3,lsl 4
	and	w1,w2,w3,lsr 4
	and	w1,w2,w3,ror 4
	and	wzr,w2,w3,ror 4
	and	x1,x2,0x0003FC0000000000
	and	x1,x2,x3
	and	x1,x2,x3,lsl 4
	and	x1,x2,x3,ror 4
	and	xzr,x2,x3,ror 4

	ands	w1,w2,0xFFFFFFF1
	ands	w1,w2,w3
	ands	w1,w2,w3,lsl 4
	ands	w1,w2,w3,ror 4
	ands	x1,x2,0x5555555555555555
	ands	x1,x2,x3
	ands	x1,x2,x3,lsl 4
	ands	x1,x2,x3,ror 4

	asr	w1,w2,1
	asr	w1,w2,w3
	asr	x1,x2,1
	asr	x1,x2,x3

	asrv	w1,w2,w3
	asrv	x1,x2,x3

	at	s12e0r,x1
	at	s12e0w,x1
	at	s12e1r,x1
	at	s12e1w,x1
	at	s1e0r,x1
	at	s1e0w,x1
	at	s1e1r,x1
	at	s1e1w,x1
	at	s1e2r,x1
	at	s1e2w,x1
	at	s1e3r,x1
	at	s1e3w,x1

	label_b:
	b	label_b
	b.al	label_b
	b.eq	label_b
	b.eq	label_b
	b.ge	label_b
	b.gt	label_b
	b.hi	label_b
	b.hs	label_b
	b.le	label_b
	b.lo	label_b
	b.ls	label_b
	b.lt	label_b
	b.mi	label_b
	b.ne	label_b
	b.pl	label_b
	b.vc	label_b
	b.vs	label_b

	bfi	w1,w2,3,27
	bfi	x1,x2,3,59

	bfm	w1,w2,3,31
	bfm	x1,x2,3,45

	bfxil	w1,w2,3,29
	bfxil	x1,x2,3,29

	bic	w1,w2,w3
	bic	w1,w2,w3,asr 4
	bic	w1,w2,w3,lsl 4
	bic	w1,w2,w3,lsr 4
	bic	w1,w2,w3,ror 4
	bic	x1,x2,x3
	bic	x1,x2,x3,lsl 4
	bic	x1,x2,x3,ror 4

	bics	w1,w2,w3
	bics	w1,w2,w3,lsl 4
	bics	w1,w2,w3,ror 4
	bics	x1,x2,x3
	bics	x1,x2,x3,lsl 4
	bics	x1,x2,x3,ror 4

	label_bl:
	bl	label_bl

	blr	x1

	br	x1

	brk	0xFFFF

	label_cbnz:
	cbnz	w1,label_cbnz
	cbnz	x1,label_cbnz

	label_cbz:
	cbz	w1,label_cbz
	cbz	x1,label_cbz

	ccmn	w1,2,0x0,ls
	ccmn	w1,w2,0x0,hs
	ccmn	x1,31,0x0,vs
	ccmn	x1,x2,0x1,ge

	ccmp	w1,2,0x0,ls
	ccmp	w1,w2,0x0,hs
	ccmp	x1,31,0x0,vs
	ccmp	x1,x2,0x1,ge

	cinc	w1,w2,hs

	cinv	w1,w2,hs

	clrex	0x5

	cls	w1,w2
	cls	x1,x2

	clz	w1,w2
	clz	x1,x2

	cmn	sp,x3,uxtx
	cmn	sp,x3,uxtx 1
	cmn	w2,w3
	cmn	w2,w3,asr 1
	cmn	w2,w3,asr 31
	cmn	w2,w3,lsl 1
	cmn	w2,w3,lsr 1
	cmn	wsp,w3,uxtw
	cmn	wsp,w3,uxtw 1
	cmn	x1,0x2
	cmn	x2,x3
	cmn	x2,x3,asr 1
	cmn	x2,x3,asr 63
	cmn	x2,x3,lsl 1
	cmn	x2,x3,lsr 1

	cmp	sp,x3,uxtx
	cmp	sp,x3,uxtx 1
	cmp	w2,w3
	cmp	w2,w3,asr 1
	cmp	w2,w3,asr 31
	cmp	w2,w3,lsl 1
	cmp	w2,w3,lsr 1
	cmp	wsp,w3,uxtw
	cmp	wsp,w3,uxtw 1
	cmp	x1,0x2
	cmp	x2,x3
	cmp	x2,x3,asr 1
	cmp	x2,x3,asr 63
	cmp	x2,x3,lsl 1
	cmp	x2,x3,lsr 1

	cneg	w1,w2,hs
	cneg	xzr,xzr,hs

	csel	w1,w2,w3,ne
	csel	x1,x2,x3,vs

	cset	w1,ne
	cset	x1,vs

	csetm	w1,ne
	csetm	x1,vs

	csinc	w1,w2,w3,ne
	csinc	x1,x2,x3,vs

	csinv	w1,w2,w3,ne
	csinv	x1,x2,x3,vs

	csneg	w1,w2,w3,ne
	csneg	x1,x2,x3,vs

	dc	cisw,x1
	dc	civac,x1
	dc	csw,x1
	dc	cvac,x1
	dc	cvau,x1
	dc	isw,x1
	dc	ivac,x1
	dc	zva,x1

	dcps1	0x0

	dcps1	0xFFFF

	dcps2	0xFFFF

	dcps3	0xFFFF

	dmb	ish
	dmb	ishld
	dmb	ishst
	dmb	ld
	dmb	nsh
	dmb	nshld
	dmb	nshst
	dmb	osh
	dmb	oshld
	dmb	oshst
	dmb	st
	dmb	sy

	drps

	dsb	ish
	dsb	ishld
	dsb	ishst
	dsb	ld
	dsb	nsh
	dsb	nshld
	dsb	nshst
	dsb	osh
	dsb	oshld
	dsb	oshst
	dsb	st
	dsb	sy

	eon	w1,w2,w3
	eon	w1,w2,w3,asr 4
	eon	w1,w2,w3,lsl 4
	eon	w1,w2,w3,lsr 4
	eon	w1,w2,w3,ror 4
	eon	wzr,w2,w3,ror 4
	eon	x1,x2,x3
	eon	x1,x2,x3,lsl 4
	eon	x1,x2,x3,ror 4
	eon	xzr,x2,x3,ror 4

	eor	sp,x2,0xAAAAAAAAAAAAAAAA
	eor	w1,w2,0xFFFFFFF1
	eor	w1,w2,w3
	eor	w1,w2,w3,asr 4
	eor	w1,w2,w3,lsl 4
	eor	w1,w2,w3,lsr 4
	eor	w1,w2,w3,ror 4
	eor	wzr,w2,w3,ror 4
	eor	x1,x2,0xFFFFFFFFFFFFFFF1
	eor	x1,x2,x3
	eor	x1,x2,x3,lsl 4
	eor	x1,x2,x3,ror 4
	eor	xzr,x2,x3,ror 4

	eret

	extr	w1,w2,w3,3
	extr	x1,x2,x3,35

	hint	4

	hlt	0xFFFF

	hvc	0xFFFF

	ic	iallu
	ic	ialluis
	ic	ivau,x1
	ic	ivau,xzr

	isb	sy

	ldar	w1,[x2]
	ldar	w1,[x2,0]
	ldar	x3,[x8]
	ldar	x3,[x8,0]

	ldarb	w1,[x2]
	ldarb	w1,[x2,0]

	ldarh	w1,[x2]
	ldarh	w1,[x2,0]

	ldaxp	w1,w8,[x2]
	ldaxp	w1,w8,[x2,0]
	ldaxp	x3,x2,[x8]
	ldaxp	x3,x2,[x8,0]

	ldaxr	w1,[x2]
	ldaxr	w1,[x2,0]
	ldaxr	x3,[x8]
	ldaxr	x3,[x8,0]

	ldaxrb	w1,[x2]
	ldaxrb	w1,[x2,0]

	ldaxrh	w1,[x2]
	ldaxrh	w1,[x2,0]

	ldnp	w0,w1,[x2]
	ldnp	w0,w1,[x2,+0x8]
	ldnp	w0,w1,[expression.dword]
	ldnp	x0,x1,[x2]
	ldnp	x0,x1,[x2,+0x8]
	ldnp	x0,x1,[expression.qword]

	ldp	w0,w1,[x2]
	ldp	w0,w1,[x2,+0x8]
	ldp	w0,w1,[expression.dword]
	ldp	w0,w1,[x2,+0x8]!
	ldp	w0,w1,[expression.dword]!
	ldp	w0,w1,[x2],+0x8
	ldp	x0,x1,[x2]
	ldp	x0,x1,[x2,+0x8]
	ldp	x0,x1,[expression.qword]
	ldp	x0,x1,[x2,+0x8]!
	ldp	x0,x1,[expression.qword]!
	ldp	x0,x1,[x2],+0x8

	ldpsw	x0,x1,[x2]
	ldpsw	x0,x1,[x2,+0x8]
	ldpsw	x0,x1,[expression.dword]
	ldpsw	x0,x1,[x2,+0x8]!
	ldpsw	x0,x1,[expression.dword]!
	ldpsw	x0,x1,[x2],+0x8

	label_ldr:
	ldr	w0,[x2,+0x8]
	ldr	w0,[expression.word]
	ldr	w0,[x2,+0x8]!
	ldr	w0,[expression.word]!
	ldr	w0,[x2],+0x8
	ldr	w0,[x2,w3,sxtw]
	ldr	w0,[x2,w3,sxtw 2]
	ldr	w0,[x2,w3,uxtw]
	ldr	w0,[x2,w3,uxtw 2]
	ldr	w0,[x2,x3]
	ldr	w0,[x2,x3,lsl 2]
	ldr	w0,[x2,x3,sxtx]
	ldr	w0,[x2,x3,sxtx 2]
	ldr	w0,label_ldr
	ldr	w0,[label_ldr]
	ldr	x0,[x2,+0x8]
	ldr	x0,[expression.dword]
	ldr	x0,[x2,+0x8]!
	ldr	x0,[expression.dword]!
	ldr	x0,[x2],+0x8
	ldr	x0,[x2,w3,sxtw]
	ldr	x0,[x2,w3,sxtw 3]
	ldr	x0,[x2,w3,uxtw]
	ldr	x0,[x2,w3,uxtw 3]
	ldr	x0,[x2,x3]
	ldr	x0,[x2,x3,lsl 3]
	ldr	x0,[x2,x3,sxtx]
	ldr	x0,[x2,x3,sxtx 3]
	ldr	x0,label_ldr
	ldr	x0,[label_ldr]

	ldrb	w0,[x2]
	ldrb	w0,[x2,+0x8]
	ldrb	w0,[expression.byte]
	ldrb	w0,[x2,+0x8]!
	ldrb	w0,[expression.byte]!
	ldrb	w0,[x2],+0x8
	ldrb	w0,[x2,w3,sxtw]
	ldrb	w0,[x2,w3,sxtw 0]
	ldrb	w0,[x2,w3,uxtw]
	ldrb	w0,[x2,w3,uxtw 0]
	ldrb	w0,[x2,x3]
	ldrb	w0,[x2,x3,lsl 0]
	ldrb	w0,[x2,x3,sxtx]
	ldrb	w0,[x2,x3,sxtx 0]

	ldrh	w0,[x2]
	ldrh	w0,[x2,+0x8]
	ldrh	w0,[expression.hword]
	ldrh	w0,[x2,+0x8]!
	ldrh	w0,[expression.hword]!
	ldrh	w0,[x2],+0x8
	ldrh	w0,[x2,w3,sxtw]
	ldrh	w0,[x2,w3,sxtw 1]
	ldrh	w0,[x2,w3,uxtw]
	ldrh	w0,[x2,w3,uxtw 1]
	ldrh	w0,[x2,x3]
	ldrh	w0,[x2,x3,lsl 1]
	ldrh	w0,[x2,x3,sxtx]
	ldrh	w0,[x2,x3,sxtx 1]

	ldrsb	w0,[x2]
	ldrsb	w0,[x2,+0x8]
	ldrsb	w0,[expression.byte]
	ldrsb	w0,[x2,+0x8]!
	ldrsb	w0,[expression.byte]!
	ldrsb	w0,[x2],+0x8
	ldrsb	w0,[x2,w3,sxtw]
	ldrsb	w0,[x2,w3,sxtw 0]
	ldrsb	w0,[x2,w3,uxtw]
	ldrsb	w0,[x2,w3,uxtw 0]
	ldrsb	w0,[x2,x3]
	ldrsb	w0,[x2,x3,lsl 0]
	ldrsb	w0,[x2,x3,sxtx]
	ldrsb	w0,[x2,x3,sxtx 0]

	ldrsh	w0,[x2]
	ldrsh	w0,[x2,+0x8]
	ldrsh	w0,[expression.hword]
	ldrsh	w0,[x2,+0x8]!
	ldrsh	w0,[expression.hword]!
	ldrsh	w0,[x2],+0x8
	ldrsh	w0,[x2,w3,sxtw]
	ldrsh	w0,[x2,w3,sxtw 1]
	ldrsh	w0,[x2,w3,uxtw]
	ldrsh	w0,[x2,w3,uxtw 1]
	ldrsh	w0,[x2,x3]
	ldrsh	w0,[x2,x3,lsl 1]
	ldrsh	w0,[x2,x3,sxtx]
	ldrsh	w0,[x2,x3,sxtx 1]

	label_ldrsw:
	ldrsw	x0,[x2]
	ldrsw	x0,[x2,+0x8]
	ldrsw	x0,[expression.word]
	ldrsw	x0,[x2,+0x8]!
	ldrsw	x0,[expression.word]!
	ldrsw	x0,[x2],+0x8
	ldrsw	x0,[x2,w3,sxtw]
	ldrsw	x0,[x2,w3,sxtw 2]
	ldrsw	x0,[x2,w3,uxtw]
	ldrsw	x0,[x2,w3,uxtw 2]
	ldrsw	x0,[x2,x3]
	ldrsw	x0,[x2,x3,lsl 2]
	ldrsw	x0,[x2,x3,sxtx]
	ldrsw	x0,[x2,x3,sxtx 2]
	ldrsw	x1,label_ldrsw
	ldrsw	x1,[label_ldrsw]

	ldtr	w0,[x2]
	ldtr	w0,[x2,+0x8]
	ldtr	w0,[expression.word]
	ldtr	x0,[x2]
	ldtr	x0,[x2,+0x8]
	ldtr	x0,[expression.dword]

	ldtrb	w0,[x2]
	ldtrb	w0,[x2,+0x8]
	ldtrb	w0,[expression.byte]

	ldtrh	w0,[x2]
	ldtrh	w0,[x2,+0x8]
	ldtrh	w0,[expression.hword]

	ldtrsb	w0,[x2]
	ldtrsb	w0,[x2,+0x8]
	ldtrsb	w0,[expression.byte]

	ldtrsh	w0,[x2]
	ldtrsh	w0,[x2,+0x8]
	ldtrsh	w0,[expression.hword]

	ldtrsw	x0,[x2]
	ldtrsw	x0,[x2,+0x8]
	ldtrsw	x0,[expression.word]

	ldur	w0,[x2]
	ldur	w0,[x2,+0x8]
	ldur	w0,[expression.word]
	ldur	x0,[x2]
	ldur	x0,[x2,+0x8]
	ldur	x0,[expression.dword]

	ldurb	w0,[x2]
	ldurb	w0,[x2,+0x8]
	ldurb	w0,[expression.byte]

	ldurh	w0,[x2]
	ldurh	w0,[x2,+0x8]
	ldurh	w0,[expression.hword]

	ldursb	w0,[x2]
	ldursb	w0,[x2,+0x8]
	ldursb	w0,[expression.byte]

	ldursh	w0,[x2]
	ldursh	w0,[x2,+0x8]
	ldursh	w0,[expression.hword]

	ldursw	x0,[x2]
	ldursw	x0,[x2,+0x8]
	ldursw	x0,[expression.word]

	ldxp	w1,w8,[x2]
	ldxp	w1,w8,[x2,0]
	ldxp	x3,x2,[x8]
	ldxp	x3,x2,[x8,0]

	ldxr	w1,[x2]
	ldxr	w1,[x2,0]
	ldxr	x3,[x8]
	ldxr	x3,[x8,0]

	ldxrb	w1,[x2]
	ldxrb	w1,[x2,0]

	ldxrh	w1,[x2]
	ldxrh	w1,[x2,0]

	lsl	w1,w2,1
	lsl	w1,w2,w3
	lsl	x1,x2,1
	lsl	x1,x2,x3

	lslv	w1,w2,w3
	lslv	x1,x2,x3

	lsr	w1,w2,1
	lsr	w1,w2,w3
	lsr	x1,x2,1
	lsr	x1,x2,x3

	lsrv	w1,w2,w3
	lsrv	x1,x2,x3

	madd	w1,w2,w3,w4
	madd	x1,x2,x3,x4

	mneg	w1,w2,w3
	mneg	x1,x2,x3

	mov	sp,sp
	mov	sp,x1
	mov	w0,w1
	mov	w1,0x00FFFFF0
	mov	w1,0x000FFFFF
	mov	w1,0x100FFFFF
	mov	wsp,0x0000FFFF
	mov	wsp,w1
	mov	wsp,wsp
	mov	wzr,w1
	mov	wzr,wzr
	mov	x0,x1
	mov	x1,0x000FFFFFFFFFFFF0
	mov	x1,0x0000FFFFFFFFFFFF
	mov	x1,0x1000FFFFFFFFFFFF
	mov	x1,sp
	mov	xzr,x1
	mov	xzr,xzr

	movk	w1,0xFFFF
	movk	w1,0xFFFF,lsl 16
	movk	x1,0xFFFF,lsl 32
	movk	x1,0xFFFF,lsl 48

	movn	w1,0xFFFF
	movn	w1,0xFFFF,lsl 16

	movz	w1,0xffff
	movz	w1,0xffff,lsl 0
	movz	w1,0xffff,lsl 16
	movz	x1,0xffff,lsl 32
	movz	x1,0xffff,lsl 48

	mrs	x1,vttbr_el2
	mrs	x2,s3_2_c3_c4_5
	mrs	x8,spsel

	msr	actlr_el1,x1
	msr	s3_2_c3_c4_5,x1

	msub	w1,w2,w3,w4
	msub	x1,x2,x3,x4

	mul	w1,w2,w3
	mul	x2,x3,x4

	mvn	w1,w2
	mvn	w1,w2,asr 4
	mvn	w1,w2,lsl 4
	mvn	w1,w2,lsr 4
	mvn	w1,w2,ror 4
	mvn	x1,x2
	mvn	x1,x2,asr 4
	mvn	x1,x2,lsl 4
	mvn	x1,x2,lsr 4
	mvn	x1,x2,ror 4

	neg	w1,w2
	neg	w1,w2,asr 14
	neg	w1,w2,lsl 4
	neg	w1,w2,lsr 4
	neg	x1,x2
	neg	x1,x2,asr 14
	neg	x1,x2,lsl 4
	neg	x1,x2,lsr 4

	negs	w1,w2
	negs	x1,x2

	ngc	w1,w2
	ngc	x1,x2

	ngcs	w1,w2
	ngcs	x1,x2

	nop

	orn	w1,w2,w3
	orn	w1,w2,w3,asr 4
	orn	w1,w2,w3,lsl 4
	orn	w1,w2,w3,lsr 4
	orn	w1,w2,w3,ror 4
	orn	x1,x2,x3
	orn	x1,x2,x3,asr 4
	orn	x1,x2,x3,lsl 4
	orn	x1,x2,x3,lsr 4
	orn	x1,x2,x3,ror 4

	orr	w1,w2,0xFFFFFFF1
	orr	w1,w2,w3
	orr	w1,w2,w3,asr 4
	orr	w1,w2,w3,lsl 4
	orr	w1,w2,w3,lsr 4
	orr	w1,w2,w3,ror 4
	orr	x1,x2,0xAAAAAAAAAAAAAAAA
	orr	x1,x2,x3
	orr	x1,x2,x3,lsl 4
	orr	x1,x2,x3,ror 4

	label_prfm:
	prfm	pldl2strm,[x2,+0x8]
	prfm	pldl2strm,[expression.dword]
	prfm	pldl2strm,[x2,w3,sxtw]
	prfm	pldl2strm,[x2,w3,sxtw 3]
	prfm	pldl2strm,[x2,w3,uxtw]
	prfm	pldl2strm,[x2,w3,uxtw 3]
	prfm	pldl2strm,[x2,x3]
	prfm	pldl2strm,[x2,x3,lsl 3]
	prfm	pldl2strm,[x2,x3,sxtx]
	prfm	pldl2strm,[x2,x3,sxtx 3]
	prfm	pldl2strm,label_prfm
	prfm	pldl2strm,[label_prfm]
	prfm	0x00,[x2,+0x8]
	prfm	0x01,[expression.dword]
	prfm	0x02,[x2,w3,sxtw]
	prfm	0x03,[x2,w3,sxtw 3]
	prfm	0x04,[x2,w3,uxtw]
	prfm	0x05,[x2,w3,uxtw 3]
	prfm	0x06,[x2,x3]
	prfm	0x07,[x2,x3,lsl 3]
	prfm	0x08,[x2,x3,sxtx]
	prfm	0x09,[x2,x3,sxtx 3]
	prfm	0x0a,label_prfm
	prfm	0x0b,[label_prfm]

	rbit	w1,w2
	rbit	x1,x2

	ret
	ret	x1

	rev	w1,w2
	rev	x1,x2

	rev16	w1,w2
	rev16	x1,x2

	rev32	x1,x2

	rev64	x1,x2

	ror	w1,w2,1
	ror	w1,w2,w3
	ror	x1,x2,1
	ror	x1,x2,x3

	rorv	w1,w2,w3
	rorv	x1,x2,x3

	sbc	w0,w1,w2
	sbc	x0,x1,x2

	sbcs	w0,w1,w2
	sbcs	x0,x1,x2

	sbfiz	w1,w2,3,28
	sbfiz	x1,x2,3,60

	sbfm	w1,w2,3,30
	sbfm	x1,x2,3,45

	sbfx	w1,w2,3,4
	sbfx	x1,x2,3,29

	sdiv	w1,w2,w3
	sdiv	x1,x2,x3

	sev

	sevl

	smaddl	x1,w2,w3,x4

	smc	0xFFFF

	smnegl	x1,w2,w3

	smsubl	x1,w2,w3,x4

	smulh	x1,x2,x3

	smull	x1,w2,w3

	stlr	w1,[x2]
	stlr	w1,[x2,0]
	stlr	x3,[x8]
	stlr	x3,[x8,0]

	stlrb	w1,[x2]
	stlrb	w1,[x2,0]

	stlrh	w1,[x2]
	stlrh	w1,[x2,0]

	stlxp	w1,w2,w3,[x4]
	stlxp	w1,w2,w3,[x4,0]
	stlxp	w1,x2,x3,[x4]
	stlxp	w1,x2,x3,[x4,0]

	stlxr	w1,w2,[x3]
	stlxr	w1,w2,[x3,0]
	stlxr	w1,x2,[x3]
	stlxr	w1,x2,[x3,0]

	stlxrb	w1,w2,[x3]
	stlxrb	w1,w2,[x3,0]

	stlxrh	w1,w2,[x3]
	stlxrh	w1,w2,[x3,0]

	stnp	w0,w1,[x2]
	stnp	w0,w1,[x2,+0x8]
	stnp	w0,w1,[expression.dword]
	stnp	x0,x1,[x2]
	stnp	x0,x1,[x2,+0x8]
	stnp	x0,x1,[expression.qword]

	stp	w0,w1,[x2]
	stp	w0,w1,[x2,+0x8]
	stp	w0,w1,[expression.dword]
	stp	w0,w1,[x2,+0x8]!
	stp	w0,w1,[expression.dword]!
	stp	w0,w1,[x2],+0x8
	stp	x0,x1,[x2]
	stp	x0,x1,[x2,+0x8]
	stp	x0,x1,[expression.qword]
	stp	x0,x1,[x2,+0x8]!
	stp	x0,x1,[expression.qword]!
	stp	x0,x1,[x2],+0x8

	str	w0,[x2,+0x8]
	str	w0,[expression.word]
	str	w0,[x2,+0x8]!
	str	w0,[expression.word]!
	str	w0,[x2],+0x8
	str	w0,[x2,w3,sxtw]
	str	w0,[x2,w3,sxtw 2]
	str	w0,[x2,w3,uxtw]
	str	w0,[x2,w3,uxtw 2]
	str	w0,[x2,x3]
	str	w0,[x2,x3,lsl 2]
	str	w0,[x2,x3,sxtx]
	str	w0,[x2,x3,sxtx 2]
	str	x0,[x2,+0x8]
	str	x0,[expression.dword]
	str	x0,[x2,+0x8]!
	str	x0,[expression.dword]!
	str	x0,[x2],+0x8
	str	x0,[x2,w3,sxtw]
	str	x0,[x2,w3,sxtw 3]
	str	x0,[x2,w3,uxtw]
	str	x0,[x2,w3,uxtw 3]
	str	x0,[x2,x3]
	str	x0,[x2,x3,lsl 3]
	str	x0,[x2,x3,sxtx]
	str	x0,[x2,x3,sxtx 3]

	strb	w0,[x2]
	strb	w0,[x2,+0x8]
	strb	w0,[expression.byte]
	strb	w0,[x2,+0x8]!
	strb	w0,[expression.byte]!
	strb	w0,[x2],+0x8
	strb	w0,[x2,w3,sxtw]
	strb	w0,[x2,w3,sxtw 0]
	strb	w0,[x2,w3,uxtw]
	strb	w0,[x2,w3,uxtw 0]
	strb	w0,[x2,x3]
	strb	w0,[x2,x3,lsl 0]
	strb	w0,[x2,x3,sxtx]
	strb	w0,[x2,x3,sxtx 0]

	strh	w0,[x2]
	strh	w0,[x2,+0x8]
	strh	w0,[expression.hword]
	strh	w0,[x2,+0x8]!
	strh	w0,[expression.hword]!
	strh	w0,[x2],+0x8
	strh	w0,[x2,w3,sxtw]
	strh	w0,[x2,w3,sxtw 1]
	strh	w0,[x2,w3,uxtw]
	strh	w0,[x2,w3,uxtw 1]
	strh	w0,[x2,x3]
	strh	w0,[x2,x3,lsl 1]
	strh	w0,[x2,x3,sxtx]
	strh	w0,[x2,x3,sxtx 1]

	sttr	w0,[x2]
	sttr	w0,[x2,+0x8]
	sttr	w0,[expression.word]
	sttr	x0,[x2]
	sttr	x0,[x2,+0x8]
	sttr	x0,[expression.dword]

	sttrb	w0,[x2]
	sttrb	w0,[x2,+0x8]
	sttrb	w0,[expression.byte]

	sttrh	w0,[x2]
	sttrh	w0,[x2,+0x8]
	sttrh	w0,[expression.hword]

	stur	w0,[x2]
	stur	w0,[x2,+0x8]
	stur	w0,[expression.word]
	stur	x0,[x2]
	stur	x0,[x2,+0x8]
	stur	x0,[expression.dword]

	sturb	w0,[x2]
	sturb	w0,[x2,+0x8]
	sturb	w0,[expression.byte]

	sturh	w0,[x2]
	sturh	w0,[x2,+0x8]
	sturh	w0,[expression.hword]

	stxp	w1,w2,w3,[x4]
	stxp	w1,w2,w3,[x4,0]
	stxp	w1,x2,x3,[x4]
	stxp	w1,x2,x3,[x4,0]

	stxr	w1,w2,[x3]
	stxr	w1,w2,[x3,0]
	stxr	w1,x2,[x3]
	stxr	w1,x2,[x3,0]

	stxrb	w1,w2,[x3]
	stxrb	w1,w2,[x3,0]

	stxrh	w1,w2,[x3]
	stxrh	w1,w2,[x3,0]

	sub	sp,sp,0x123
	sub	sp,x2,0x123
	sub	w1,w2,0x123
	sub	w4,w8,0x123,lsl 12
	sub	wsp,w2,0x123
	sub	wsp,wsp,0x123
	sub	w1,w2,wzr
	sub	w1,w2,w3
	sub	w1,w2,w3,asr 1
	sub	w1,w2,w3,lsl 1
	sub	w1,w2,w3,lsr 1
	sub	w1,w2,w3,sxtb
	sub	w1,w2,w3,sxtb 1
	sub	w1,w2,w3,sxth
	sub	w1,w2,w3,sxth 1
	sub	w1,w2,w3,sxtw
	sub	w1,w2,w3,sxtw 1
	sub	w1,w2,w3,uxtb
	sub	w1,w2,w3,uxtb 1
	sub	w1,w2,w3,uxth
	sub	w1,w2,w3,uxth 1
	sub	w1,w2,w3,uxtw
	sub	w1,w2,w3,uxtw 1
	sub	w1,wsp,w2,uxtw 2
	sub	w1,wsp,w3,uxtw
	sub	w1,wsp,w3,uxtw 1
	sub	wsp,w2,w3,uxtw
	sub	wsp,wsp,w3,uxtw
	sub	wzr,w2,w3
	sub	wzr,w2,wzr
	sub	wzr,wzr,w3
	sub	wzr,wzr,wzr
	sub	x1,x2,x3
	sub	x1,x2,0x123
	sub	x1,x2,0xFFF
	sub	x1,x2,0xFFF,lsl 12
	sub	x1,sp,0x123
	sub	x1,sp,x3,uxtx
	sub	x1,sp,x3,uxtx 4
	sub	x1,x2,w3,sxtb
	sub	x1,x2,w3,sxtb 2
	sub	x1,x2,w3,sxth
	sub	x1,x2,w3,sxth 2
	sub	x1,x2,w3,sxtw
	sub	x1,x2,w3,sxtw 2
	sub	x1,x2,w3,uxtb
	sub	x1,x2,w3,uxtb 2
	sub	x1,x2,w3,uxth
	sub	x1,x2,w3,uxth 2
	sub	x1,x2,w3,uxtw
	sub	x1,x2,w3,uxtw 2
	sub	x1,x2,x3,asr 1
	sub	x1,x2,x3,asr 63
	sub	x1,x2,x3,lsl 1
	sub	x1,x2,x3,lsr 1
	sub	x1,x2,x3,sxtx
	sub	x1,x2,x3,sxtx 3
	sub	x1,x2,x3,uxtx
	sub	x1,x2,x3,uxtx 2

	subs	w1,w2,w3
	subs	w1,w2,wzr
	subs	w1,wsp,0x123
	subs	w1,wsp,w3,uxtw
	subs	w1,wsp,w2,uxtw 2
	subs	w1,wzr,w3
	subs	w1,wzr,wzr
	subs	w8,w16,0x123,lsl 12
	subs	x8,x16,0x123,lsl 12
	subs	x1,x2,x3,asr 63

	svc	0xFFFF

	sxtb	w1,w2
	sxtb	x1,w2

	sxth	w1,w2
	sxth	x1,w2

	sxtw	x1,w2

	sys	1,c2,c3,4
	sys	1,c2,c3,4,x5

	sysl	x1,2,c3,c4,5

	label_tbnz:
	tbnz	w1,2,label_tbnz
	tbnz	x1,63,label_tbnz

	label_tbz:
	tbz	w1,2,label_tbz
	tbz	x1,63,label_tbz

	tlbi	alle1
	tlbi	aside1,x1

	tst	w1,0x0000000E
	tst	w1,w2
	tst	w2,w3,asr 4
	tst	w2,w3,lsl 4
	tst	w2,w3,lsr 4
	tst	w2,w3,ror 4
	tst	x1,0x00000000000FFE00
	tst	x1,x2
	tst	x2,x3,ror 4

	ubfiz	w1,w2,3,28
	ubfiz	x1,x2,3,60

	ubfm	w1,w2,3,31
	ubfm	x1,x2,3,31

	ubfx	w1,w2,3,4
	ubfx	x1,x2,3,29

	udiv	w1,w2,w3
	udiv	x1,x2,x3

	umaddl	x1,w2,w3,x4

	umnegl	x1,w2,w3

	umsubl	x1,w2,w3,x4

	umull	x1,w2,w3

	umulh	x1,x2,x3

	uxtb	w1,w2

	uxth	w1,w2

	wfe

	wfi

	yield

processor CPU64_FP

	fabd	d1,d2,d3
	fabd	s1,s2,s3
	fabd	v1.2d,v2.2d,v3.2d
	fabd	v1.2s,v2.2s,v3.2s
	fabd	v1.4s,v2.4s,v3.4s

	fabs	d1,d2
	fabs	s1,s2
	fabs	v1.2d,v2.2d
	fabs	v1.2s,v2.2s
	fabs	v1.4s,v2.4s

	facge	d1,d2,d3
	facge	s1,s2,s3
	facge	v1.2d,v2.2d,v3.2d
	facge	v1.2s,v2.2s,v3.2s
	facge	v1.4s,v2.4s,v3.4s

	facgt	d1,d2,d3
	facgt	s1,s2,s3
	facgt	v1.2d,v2.2d,v3.2d
	facgt	v1.2s,v2.2s,v3.2s
	facgt	v1.4s,v2.4s,v3.4s

	fadd	d1,d2,d3
	fadd	s1,s2,s3
	fadd	v1.2d,v2.2d,v3.2d
	fadd	v1.2s,v2.2s,v3.2s
	fadd	v1.4s,v2.4s,v3.4s

	faddp	d1,v2.2d
	faddp	s1,v2.2s
	faddp	v1.2d,v2.2d,v3.2d
	faddp	v1.2s,v2.2s,v3.2s
	faddp	v1.4s,v2.4s,v3.4s

	fccmp	d1,d2,0x1,ge
	fccmp	s1,s2,0x0,hs

	fccmpe	d1,d2,0x1,ge
	fccmpe	s1,s2,0x0,hs

	fcmeq	d1,d2,0
	fcmeq	d1,d2,d3
	fcmeq	s1,s2,0
	fcmeq	s1,s2,s3
	fcmeq	v1.2d,v2.2d,0
	fcmeq	v1.2d,v2.2d,v3.2d
	fcmeq	v1.2s,v2.2s,0
	fcmeq	v1.2s,v2.2s,v3.2s
	fcmeq	v1.4s,v2.4s,0
	fcmeq	v1.4s,v2.4s,v3.4s

	fcmge	d1,d2,0
	fcmge	d1,d2,d3
	fcmge	s1,s2,0
	fcmge	s1,s2,s3
	fcmge	v1.2d,v2.2d,0
	fcmge	v1.2d,v2.2d,v3.2d
	fcmge	v1.2s,v2.2s,0
	fcmge	v1.2s,v2.2s,v3.2s
	fcmge	v1.4s,v2.4s,0
	fcmge	v1.4s,v2.4s,v3.4s

	fcmgt	d1,d2,0
	fcmgt	d1,d2,d3
	fcmgt	s1,s2,0
	fcmgt	s1,s2,s3
	fcmgt	v1.2d,v2.2d,0
	fcmgt	v1.2d,v2.2d,v3.2d
	fcmgt	v1.2s,v2.2s,0
	fcmgt	v1.2s,v2.2s,v3.2s
	fcmgt	v1.4s,v2.4s,0
	fcmgt	v1.4s,v2.4s,v3.4s

	fcmle	d1,d2,0
	fcmle	s1,s2,0
	fcmle	v1.2d,v2.2d,0
	fcmle	v1.2s,v2.2s,0
	fcmle	v1.4s,v2.4s,0

	fcmlt	d1,d2,0
	fcmlt	s1,s2,0
	fcmlt	v1.2d,v2.2d,0
	fcmlt	v1.2s,v2.2s,0
	fcmlt	v1.4s,v2.4s,0

	fcmp	d1,0.0
	fcmp	d1,d2
	fcmp	s1,0.0
	fcmp	s1,s2

	fcmpe	d1,0.0
	fcmpe	d1,d2
	fcmpe	s1,0.0
	fcmpe	s1,s2

	fcsel	d1,d2,d3,vs
	fcsel	s1,s2,s3,ls

	fcvt	d1,h2
	fcvt	d1,s2
	fcvt	h1,d2
	fcvt	h1,s2
	fcvt	s1,d2
	fcvt	s1,h2

	fcvtas	d1,d2
	fcvtas	s1,s2
	fcvtas	v1.2d,v2.2d
	fcvtas	v1.2s,v2.2s
	fcvtas	v1.4s,v2.4s
	fcvtas	w1,d2
	fcvtas	w1,s2
	fcvtas	x1,d2
	fcvtas	x1,s2

	fcvtau	d1,d2
	fcvtau	s1,s2
	fcvtau	v1.2d,v2.2d
	fcvtau	v1.2s,v2.2s
	fcvtau	v1.4s,v2.4s
	fcvtau	w1,d2
	fcvtau	w1,s2
	fcvtau	x1,d2
	fcvtau	x1,s2

	fcvtl	v1.2d,v2.2s
	fcvtl	v1.4s,v2.4h

	fcvtl2	v1.2d,v2.4s
	fcvtl2	v1.4s,v2.8h

	fcvtms	d1,d2
	fcvtms	s1,s2
	fcvtms	v1.2d,v2.2d
	fcvtms	v1.2s,v2.2s
	fcvtms	v1.4s,v2.4s
	fcvtms	w1,d2
	fcvtms	w1,s2
	fcvtms	x1,d2
	fcvtms	x1,s2

	fcvtmu	d1,d2
	fcvtmu	s1,s2
	fcvtmu	v1.2d,v2.2d
	fcvtmu	v1.2s,v2.2s
	fcvtmu	v1.4s,v2.4s
	fcvtmu	w1,d2
	fcvtmu	w1,s2
	fcvtmu	x1,d2
	fcvtmu	x1,s2

	fcvtn	v1.2s,v2.2d
	fcvtn	v1.4h,v2.4s

	fcvtn2	v1.4s,v2.2d
	fcvtn2	v1.8h,v2.4s

	fcvtns	d1,d2
	fcvtns	s1,s2
	fcvtns	v1.2d,v2.2d
	fcvtns	v1.2s,v2.2s
	fcvtns	v1.4s,v2.4s
	fcvtns	w1,d2
	fcvtns	w1,s2
	fcvtns	x1,d2
	fcvtns	x1,s2

	fcvtnu	d1,d2
	fcvtnu	s1,s2
	fcvtnu	v1.2d,v2.2d
	fcvtnu	v1.2s,v2.2s
	fcvtnu	v1.4s,v2.4s
	fcvtnu	w1,d2
	fcvtnu	w1,s2
	fcvtnu	x1,d2
	fcvtnu	x1,s2

	fcvtps	d1,d2
	fcvtps	s1,s2
	fcvtps	v1.2d,v2.2d
	fcvtps	v1.2s,v2.2s
	fcvtps	v1.4s,v2.4s
	fcvtps	w1,d2
	fcvtps	w1,s2
	fcvtps	x1,d2
	fcvtps	x1,s2

	fcvtpu	d1,d2
	fcvtpu	s1,s2
	fcvtpu	v1.2d,v2.2d
	fcvtpu	v1.2s,v2.2s
	fcvtpu	v1.4s,v2.4s
	fcvtpu	w1,d2
	fcvtpu	w1,s2
	fcvtpu	x1,d2
	fcvtpu	x1,s2

	fcvtxn	s1,d2
	fcvtxn	v1.2s,v2.2d

	fcvtxn2	v1.4s,v2.2d

	fcvtzs	d1,d2
	fcvtzs	d1,d2,5
	fcvtzs	s1,s2
	fcvtzs	s1,s2,5
	fcvtzs	v1.2d,v2.2d
	fcvtzs	v1.2d,v2.2d,5
	fcvtzs	v1.2s,v2.2s
	fcvtzs	v1.2s,v2.2s,5
	fcvtzs	v1.4s,v2.4s
	fcvtzs	v1.4s,v2.4s,5
	fcvtzs	w1,d2
	fcvtzs	w1,d2,5
	fcvtzs	w1,s2
	fcvtzs	w1,s2,5
	fcvtzs	x1,d2
	fcvtzs	x1,d2,5
	fcvtzs	x1,s2
	fcvtzs	x1,s2,5

	fcvtzu	d1,d2
	fcvtzu	d1,d2,5
	fcvtzu	s1,s2
	fcvtzu	s1,s2,5
	fcvtzu	v1.2d,v2.2d
	fcvtzu	v1.2d,v2.2d,5
	fcvtzu	v1.2s,v2.2s
	fcvtzu	v1.2s,v2.2s,5
	fcvtzu	v1.4s,v2.4s
	fcvtzu	v1.4s,v2.4s,5
	fcvtzu	w1,d2
	fcvtzu	w1,d2,5
	fcvtzu	w1,s2
	fcvtzu	w1,s2,5
	fcvtzu	x1,d2
	fcvtzu	x1,d2,5
	fcvtzu	x1,s2
	fcvtzu	x1,s2,5

	fdiv	d1,d2,d3
	fdiv	s1,s2,s3
	fdiv	v1.2d,v2.2d,v3.2d
	fdiv	v1.2s,v2.2s,v3.2s
	fdiv	v1.4s,v2.4s,v3.4s

	fmadd	d1,d2,d3,d4
	fmadd	s1,s2,s3,s4

	fmax	d1,d2,d3
	fmax	s1,s2,s3
	fmax	v1.2d,v2.2d,v3.2d
	fmax	v1.2s,v2.2s,v3.2s
	fmax	v1.4s,v2.4s,v3.4s

	fmaxnm	d1,d2,d3
	fmaxnm	s1,s2,s3
	fmaxnm	v1.2d,v2.2d,v3.2d
	fmaxnm	v1.2s,v2.2s,v3.2s
	fmaxnm	v1.4s,v2.4s,v3.4s

	fmaxnmp	d1,v2.2d
	fmaxnmp	s1,v2.2s
	fmaxnmp	v1.2d,v2.2d,v3.2d
	fmaxnmp	v1.2s,v2.2s,v3.2s
	fmaxnmp	v1.4s,v2.4s,v3.4s

	fmaxnmv	s1,v2.4s

	fmaxp	d1,v2.2d
	fmaxp	s1,v2.2s
	fmaxp	v1.2d,v2.2d,v3.2d
	fmaxp	v1.2s,v2.2s,v3.2s
	fmaxp	v1.4s,v2.4s,v3.4s

	fmaxv	s1,v2.4s

	fmin	d1,d2,d3
	fmin	s1,s2,s3
	fmin	v1.2d,v2.2d,v3.2d
	fmin	v1.2s,v2.2s,v3.2s
	fmin	v1.4s,v2.4s,v3.4s

	fminnm	d1,d2,d3
	fminnm	s1,s2,s3
	fminnm	v1.2d,v2.2d,v3.2d
	fminnm	v1.2s,v2.2s,v3.2s
	fminnm	v1.4s,v2.4s,v3.4s

	fminnmp	d1,v2.2d
	fminnmp	s1,v2.2s
	fminnmp	v1.2d,v2.2d,v3.2d
	fminnmp	v1.2s,v2.2s,v3.2s
	fminnmp	v1.4s,v2.4s,v3.4s

	fminnmv	s1,v2.4s

	fminp	d1,v2.2d
	fminp	s1,v2.2s
	fminp	v1.2d,v2.2d,v3.2d
	fminp	v1.2s,v2.2s,v3.2s
	fminp	v1.4s,v2.4s,v3.4s

	fminv	s1,v2.4s

	fmla	d1,d2,v3.d[1]
	fmla	s1,s2,v3.s[3]
	fmla	v1.2d,v2.2d,v3.2d
	fmla	v1.2d,v2.2d,v3.d[0]
	fmla	v1.2s,v2.2s,v3.2s
	fmla	v1.2s,v2.2s,v3.s[2]
	fmla	v1.4s,v2.4s,v3.4s
	fmla	v1.4s,v2.4s,v3.s[1]

	fmls	d1,d2,v3.d[1]
	fmls	s1,s2,v3.s[3]
	fmls	v1.2d,v2.2d,v3.2d
	fmls	v1.2d,v2.2d,v3.d[0]
	fmls	v1.2s,v2.2s,v3.2s
	fmls	v1.2s,v2.2s,v3.s[2]
	fmls	v1.4s,v2.4s,v3.4s
	fmls	v1.4s,v2.4s,v3.s[1]

	fmov	d1,3.375
	fmov	d1,d2
	fmov	d1,x2
	fmov	s1,4.25
	fmov	s1,s2
	fmov	s1,w2
	fmov	v1.2d,7.75
	fmov	v1.2s,5.5
	fmov	v1.4s,6.75
	fmov	v1.d[1],x2
	fmov	w1,s2
	fmov	x1,d2
	fmov	x1,v2.d[1]

	fmsub	d1,d2,d3,d4
	fmsub	s1,s2,s3,s4

	fmul	d1,d2,d3
	fmul	d1,d2,v3.d[1]
	fmul	s1,s2,s3
	fmul	s1,s2,v3.s[3]
	fmul	v1.2d,v2.2d,v3.2d
	fmul	v1.2d,v2.2d,v3.d[0]
	fmul	v1.2s,v2.2s,v3.2s
	fmul	v1.2s,v2.2s,v3.s[2]
	fmul	v1.4s,v2.4s,v3.4s
	fmul	v1.4s,v2.4s,v3.s[1]

	fmulx	d1,d2,d3
	fmulx	d1,d2,v3.d[1]
	fmulx	s1,s2,s3
	fmulx	s1,s2,v3.s[3]
	fmulx	v1.2d,v2.2d,v3.2d
	fmulx	v1.2d,v2.2d,v3.d[0]
	fmulx	v1.2s,v2.2s,v3.2s
	fmulx	v1.2s,v2.2s,v3.s[2]
	fmulx	v1.4s,v2.4s,v3.4s
	fmulx	v1.4s,v2.4s,v3.s[1]

	fneg	d1,d2
	fneg	s1,s2
	fneg	v1.2d,v2.2d
	fneg	v1.2s,v2.2s
	fneg	v1.4s,v2.4s

	fnmadd	d1,d2,d3,d4
	fnmadd	s1,s2,s3,s4

	fnmsub	d1,d2,d3,d4
	fnmsub	s1,s2,s3,s4

	fnmul	d1,d2,d3
	fnmul	s1,s2,s3

	frecpe	d1,d2
	frecpe	s1,s2
	frecpe	v1.2d,v2.2d
	frecpe	v1.2s,v2.2s
	frecpe	v1.4s,v2.4s

	frecps	d1,d2,d3
	frecps	s1,s2,s3
	frecps	v1.2d,v2.2d,v3.2d
	frecps	v1.2s,v2.2s,v3.2s
	frecps	v1.4s,v2.4s,v3.4s

	frecpx	d1,d2
	frecpx	s1,s2

	frinta	d1,d2
	frinta	s1,s2
	frinta	v1.2d,v2.2d
	frinta	v1.2s,v2.2s
	frinta	v1.4s,v2.4s

	frinti	d1,d2
	frinti	s1,s2
	frinti	v1.2d,v2.2d
	frinti	v1.2s,v2.2s
	frinti	v1.4s,v2.4s

	frintm	d1,d2
	frintm	s1,s2
	frintm	v1.2d,v2.2d
	frintm	v1.2s,v2.2s
	frintm	v1.4s,v2.4s

	frintn	d1,d2
	frintn	s1,s2
	frintn	v1.2d,v2.2d
	frintn	v1.2s,v2.2s
	frintn	v1.4s,v2.4s

	frintp	d1,d2
	frintp	s1,s2
	frintp	v1.2d,v2.2d
	frintp	v1.2s,v2.2s
	frintp	v1.4s,v2.4s

	frintx	d1,d2
	frintx	s1,s2
	frintx	v1.2d,v2.2d
	frintx	v1.2s,v2.2s
	frintx	v1.4s,v2.4s

	frintz	d1,d2
	frintz	s1,s2
	frintz	v1.2d,v2.2d
	frintz	v1.2s,v2.2s
	frintz	v1.4s,v2.4s

	frsqrte	d1,d2
	frsqrte	s1,s2
	frsqrte	v1.2d,v2.2d
	frsqrte	v1.2s,v2.2s
	frsqrte	v1.4s,v2.4s
	frsqrts	d1,d2,d3
	frsqrts	s1,s2,s3
	frsqrts	v1.2d,v2.2d,v3.2d
	frsqrts	v1.2s,v2.2s,v3.2s
	frsqrts	v1.4s,v2.4s,v3.4s

	fsqrt	d1,d2
	fsqrt	s1,s2
	fsqrt	v1.2d,v2.2d
	fsqrt	v1.2s,v2.2s
	fsqrt	v1.4s,v2.4s

	fsub	d1,d2,d3
	fsub	s1,s2,s3
	fsub	v1.2d,v2.2d,v3.2d
	fsub	v1.2s,v2.2s,v3.2s
	fsub	v1.4s,v2.4s,v3.4s

	scvtf	d1,d2
	scvtf	d1,d2,5
	scvtf	d2,w1
	scvtf	d2,w1,5
	scvtf	d2,x1
	scvtf	d2,x1,5
	scvtf	s1,s2
	scvtf	s1,s2,5
	scvtf	s2,w1
	scvtf	s2,w1,5
	scvtf	s2,x1
	scvtf	s2,x1,5
	scvtf	v1.2d,v2.2d
	scvtf	v1.2d,v2.2d,5
	scvtf	v1.2s,v2.2s
	scvtf	v1.2s,v2.2s,5
	scvtf	v1.4s,v2.4s
	scvtf	v1.4s,v2.4s,5

	ucvtf	d1,d2
	ucvtf	d1,d2,5
	ucvtf	d2,w1
	ucvtf	d2,w1,5
	ucvtf	d2,x1
	ucvtf	d2,x1,5
	ucvtf	s1,s2
	ucvtf	s1,s2,5
	ucvtf	s2,w1
	ucvtf	s2,w1,5
	ucvtf	s2,x1
	ucvtf	s2,x1,5
	ucvtf	v1.2d,v2.2d
	ucvtf	v1.2d,v2.2d,5
	ucvtf	v1.2s,v2.2s
	ucvtf	v1.2s,v2.2s,5
	ucvtf	v1.4s,v2.4s
	ucvtf	v1.4s,v2.4s,5

	urecpe	v1.2s,v2.2s
	urecpe	v1.4s,v2.4s

	ursqrte	v1.2s,v2.2s
	ursqrte	v1.4s,v2.4s

processor CPU64_SIMD

	abs	d1,d2
	abs	v1.16b,v2.16b
	abs	v1.2d,v2.2d
	abs	v1.2s,v2.2s
	abs	v1.4h,v2.4h
	abs	v1.4s,v2.4s
	abs	v1.8b,v2.8b
	abs	v1.8h,v2.8h

	add	d1,d2,d3
	add	v1.16b,v2.16b,v3.16b
	add	v1.2d,v2.2d,v3.2d
	add	v1.2s,v2.2s,v3.2s
	add	v1.4h,v2.4h,v3.4h
	add	v1.4s,v2.4s,v3.4s
	add	v1.8b,v2.8b,v3.8b
	add	v1.8h,v2.8h,v3.8h

	addhn	v1.2s,v2.2d,v3.2d
	addhn	v1.4h,v2.4s,v3.4s
	addhn	v1.8b,v2.8h,v3.8h

	addhn2	v1.16b,v2.8h,v3.8h
	addhn2	v1.4s,v2.2d,v3.2d
	addhn2	v1.8h,v2.4s,v3.4s

	addp	d1,v2.2d
	addp	v1.16b,v2.16b,v3.16b
	addp	v1.2d,v2.2d,v3.2d
	addp	v1.2s,v2.2s,v3.2s
	addp	v1.4h,v2.4h,v3.4h
	addp	v1.4s,v2.4s,v3.4s
	addp	v1.8b,v2.8b,v3.8b
	addp	v1.8h,v2.8h,v3.8h

	addv	b1,v2.16b
	addv	b1,v2.8b
	addv	h1,v2.4h
	addv	h1,v2.8h
	addv	s1,v2.4s

	and	v1.16b,v2.16b,v3.16b
	and	v1.8b,v2.8b,v3.8b

	bic	v1.16b,v2.16b,v3.16b
	bic	v1.2s,0xFF
	bic	v1.2s,0xFF,lsl 0
	bic	v1.2s,0xFF,lsl 8
	bic	v1.2s,0xFF,lsl 16
	bic	v1.2s,0xFF,lsl 24
	bic	v1.4h,0xFE
	bic	v1.4h,0xFE,lsl 0
	bic	v1.4h,0xFF,lsl 8
	bic	v1.4s,0xFF
	bic	v1.4s,0xFF,lsl 0
	bic	v1.4s,0xFF,lsl 8
	bic	v1.4s,0xFF,lsl 16
	bic	v1.4s,0xFF,lsl 24
	bic	v1.8b,v2.8b,v3.8b
	bic	v1.8h,0xFF
	bic	v1.8h,0xFF,lsl 0
	bic	v1.8h,0xFF,lsl 8

	bif	v1.16b,v2.16b,v3.16b
	bif	v1.8b,v2.8b,v3.8b

	bit	v1.16b,v2.16b,v3.16b
	bit	v1.8b,v2.8b,v3.8b

	bsl	v1.16b,v2.16b,v3.16b
	bsl	v1.8b,v2.8b,v3.8b

	cls	v1.16b,v2.16b
	cls	v1.2s,v2.2s
	cls	v1.4h,v2.4h
	cls	v1.4s,v2.4s
	cls	v1.8b,v2.8b
	cls	v1.8h,v2.8h

	clz	v1.16b,v2.16b
	clz	v1.2s,v2.2s
	clz	v1.4h,v2.4h
	clz	v1.4s,v2.4s
	clz	v1.8b,v2.8b
	clz	v1.8h,v2.8h

	cmeq	d1,d2,0
	cmeq	d1,d2,d3
	cmeq	v1.16b,v2.16b,0
	cmeq	v1.16b,v2.16b,v3.16b
	cmeq	v1.2d,v2.2d,0
	cmeq	v1.2d,v2.2d,v3.2d
	cmeq	v1.2s,v2.2s,0
	cmeq	v1.2s,v2.2s,v3.2s
	cmeq	v1.4h,v2.4h,0
	cmeq	v1.4h,v2.4h,v3.4h
	cmeq	v1.4s,v2.4s,0
	cmeq	v1.4s,v2.4s,v3.4s
	cmeq	v1.8b,v2.8b,0
	cmeq	v1.8b,v2.8b,v3.8b
	cmeq	v1.8h,v2.8h,0
	cmeq	v1.8h,v2.8h,v3.8h

	cmge	d1,d2,0
	cmge	d1,d2,d3
	cmge	v1.16b,v2.16b,0
	cmge	v1.16b,v2.16b,v3.16b
	cmge	v1.2d,v2.2d,0
	cmge	v1.2d,v2.2d,v3.2d
	cmge	v1.2s,v2.2s,0
	cmge	v1.2s,v2.2s,v3.2s
	cmge	v1.4h,v2.4h,0
	cmge	v1.4h,v2.4h,v3.4h
	cmge	v1.4s,v2.4s,0
	cmge	v1.4s,v2.4s,v3.4s
	cmge	v1.8b,v2.8b,0
	cmge	v1.8b,v2.8b,v3.8b
	cmge	v1.8h,v2.8h,0
	cmge	v1.8h,v2.8h,v3.8h

	cmgt	d1,d2,0
	cmgt	d1,d2,d3
	cmgt	v1.16b,v2.16b,0
	cmgt	v1.16b,v2.16b,v3.16b
	cmgt	v1.2d,v2.2d,0
	cmgt	v1.2d,v2.2d,v3.2d
	cmgt	v1.2s,v2.2s,0
	cmgt	v1.2s,v2.2s,v3.2s
	cmgt	v1.4h,v2.4h,0
	cmgt	v1.4h,v2.4h,v3.4h
	cmgt	v1.4s,v2.4s,0
	cmgt	v1.4s,v2.4s,v3.4s
	cmgt	v1.8b,v2.8b,0
	cmgt	v1.8b,v2.8b,v3.8b
	cmgt	v1.8h,v2.8h,0
	cmgt	v1.8h,v2.8h,v3.8h

	cmhi	d1,d2,d3
	cmhi	v1.16b,v2.16b,v3.16b
	cmhi	v1.2d,v2.2d,v3.2d
	cmhi	v1.2s,v2.2s,v3.2s
	cmhi	v1.4h,v2.4h,v3.4h
	cmhi	v1.4s,v2.4s,v3.4s
	cmhi	v1.8b,v2.8b,v3.8b
	cmhi	v1.8h,v2.8h,v3.8h

	cmhs	d1,d2,d3
	cmhs	v1.16b,v2.16b,v3.16b
	cmhs	v1.2d,v2.2d,v3.2d
	cmhs	v1.2s,v2.2s,v3.2s
	cmhs	v1.4h,v2.4h,v3.4h
	cmhs	v1.4s,v2.4s,v3.4s
	cmhs	v1.8b,v2.8b,v3.8b
	cmhs	v1.8h,v2.8h,v3.8h

	cmle	d1,d2,0
	cmle	v1.16b,v2.16b,0
	cmle	v1.2d,v2.2d,0
	cmle	v1.2s,v2.2s,0
	cmle	v1.4h,v2.4h,0
	cmle	v1.4s,v2.4s,0
	cmle	v1.8b,v2.8b,0
	cmle	v1.8h,v2.8h,0

	cmlt	d1,d2,0
	cmlt	v1.16b,v2.16b,0
	cmlt	v1.2d,v2.2d,0
	cmlt	v1.2s,v2.2s,0
	cmlt	v1.4h,v2.4h,0
	cmlt	v1.4s,v2.4s,0
	cmlt	v1.8b,v2.8b,0
	cmlt	v1.8h,v2.8h,0

	cmtst	d1,d2,d3
	cmtst	v1.16b,v2.16b,v3.16b
	cmtst	v1.2d,v2.2d,v3.2d
	cmtst	v1.2s,v2.2s,v3.2s
	cmtst	v1.4h,v2.4h,v3.4h
	cmtst	v1.4s,v2.4s,v3.4s
	cmtst	v1.8b,v2.8b,v3.8b
	cmtst	v1.8h,v2.8h,v3.8h

	cnt	v1.16b,v2.16b
	cnt	v1.8b,v2.8b

	dup	v1.16b,v2.b[15]
	dup	v1.16b,w2
	dup	v1.2d,v2.d[1]
	dup	v1.2d,x2
	dup	v1.2s,v2.s[1]
	dup	v1.2s,w2
	dup	v1.4h,v2.h[1]
	dup	v1.4h,w2
	dup	v1.4s,v2.s[3]
	dup	v1.4s,w2
	dup	v1.8b,v2.b[1]
	dup	v1.8b,w2
	dup	v1.8h,v2.h[7]
	dup	v1.8h,w2

	eor	v1.16b,v2.16b,v3.16b
	eor	v1.8b,v2.8b,v3.8b

	ext	v1.16b,v2.16b,v3.16b,15
	ext	v1.8b,v2.8b,v3.8b,7

	ins	v2.b[15],w1
	ins	v2.h[7],w1
	ins	v2.s[3],w1
	ins	v2.d[1],x1

	ins	v1.b[15],v2.b[1]
	ins	v1.b[1],v2.b[15]
	ins	v1.h[7],v2.h[1]
	ins	v1.h[1],v2.h[7]
	ins	v1.s[3],v2.s[1]
	ins	v1.s[1],v2.s[3]
	ins	v1.d[1],v2.d[0]
	ins	v1.d[0],v2.d[1]

	ld1	{v1.16b,v2.16b,v3.16b,v4.16b},[sp]
	ld1	{v1.16b,v2.16b,v3.16b,v4.16b},[sp],64
	ld1	{v1.16b,v2.16b,v3.16b,v4.16b},[sp],x6
	ld1	{v1.16b,v2.16b,v3.16b},[x4]
	ld1	{v1.16b,v2.16b,v3.16b},[x4],48
	ld1	{v1.16b,v2.16b,v3.16b},[x4],x5
	ld1	{v1.16b,v2.16b},[x3]
	ld1	{v1.16b,v2.16b},[x3],32
	ld1	{v1.16b,v2.16b},[x3],x4
	ld1	{v1.16b},[x2]
	ld1	{v1.16b},[x2],16
	ld1	{v1.16b},[x2],x3
	ld1	{v1.1d,v2.1d,v3.1d,v4.1d},[sp]
	ld1	{v1.1d,v2.1d,v3.1d,v4.1d},[sp],32
	ld1	{v1.1d,v2.1d,v3.1d,v4.1d},[sp],x6
	ld1	{v1.1d,v2.1d,v3.1d},[x4]
	ld1	{v1.1d,v2.1d,v3.1d},[x4],24
	ld1	{v1.1d,v2.1d,v3.1d},[x4],x5
	ld1	{v1.1d,v2.1d},[x3]
	ld1	{v1.1d,v2.1d},[x3],16
	ld1	{v1.1d,v2.1d},[x3],x4
	ld1	{v1.1d},[x2]
	ld1	{v1.1d},[x2],8
	ld1	{v1.1d},[x2],x3
	ld1	{v1.2d,v2.2d,v3.2d,v4.2d},[sp]
	ld1	{v1.2d,v2.2d,v3.2d,v4.2d},[sp],64
	ld1	{v1.2d,v2.2d,v3.2d,v4.2d},[sp],x6
	ld1	{v1.2d,v2.2d,v3.2d},[x4]
	ld1	{v1.2d,v2.2d,v3.2d},[x4],48
	ld1	{v1.2d,v2.2d,v3.2d},[x4],x5
	ld1	{v1.2d,v2.2d},[x3]
	ld1	{v1.2d,v2.2d},[x3],32
	ld1	{v1.2d,v2.2d},[x3],x4
	ld1	{v1.2d},[x2]
	ld1	{v1.2d},[x2],16
	ld1	{v1.2d},[x2],x3
	ld1	{v1.2s,v2.2s,v3.2s,v4.2s},[sp]
	ld1	{v1.2s,v2.2s,v3.2s,v4.2s},[sp],32
	ld1	{v1.2s,v2.2s,v3.2s,v4.2s},[sp],x6
	ld1	{v1.2s,v2.2s,v3.2s},[x4]
	ld1	{v1.2s,v2.2s,v3.2s},[x4],24
	ld1	{v1.2s,v2.2s,v3.2s},[x4],x5
	ld1	{v1.2s,v2.2s},[x3]
	ld1	{v1.2s,v2.2s},[x3],16
	ld1	{v1.2s,v2.2s},[x3],x4
	ld1	{v1.2s},[x2]
	ld1	{v1.2s},[x2],8
	ld1	{v1.2s},[x2],x3
	ld1	{v1.4h,v2.4h,v3.4h,v4.4h},[sp]
	ld1	{v1.4h,v2.4h,v3.4h,v4.4h},[sp],32
	ld1	{v1.4h,v2.4h,v3.4h,v4.4h},[sp],x6
	ld1	{v1.4h,v2.4h,v3.4h},[x4]
	ld1	{v1.4h,v2.4h,v3.4h},[x4],24
	ld1	{v1.4h,v2.4h,v3.4h},[x4],x5
	ld1	{v1.4h,v2.4h},[x3]
	ld1	{v1.4h,v2.4h},[x3],16
	ld1	{v1.4h,v2.4h},[x3],x4
	ld1	{v1.4h},[x2]
	ld1	{v1.4h},[x2],8
	ld1	{v1.4h},[x2],x3
	ld1	{v1.4s,v2.4s,v3.4s,v4.4s},[sp]
	ld1	{v1.4s,v2.4s,v3.4s,v4.4s},[sp],64
	ld1	{v1.4s,v2.4s,v3.4s,v4.4s},[sp],x6
	ld1	{v1.4s,v2.4s,v3.4s},[x4]
	ld1	{v1.4s,v2.4s,v3.4s},[x4],48
	ld1	{v1.4s,v2.4s,v3.4s},[x4],x5
	ld1	{v1.4s,v2.4s},[x3]
	ld1	{v1.4s,v2.4s},[x3],32
	ld1	{v1.4s,v2.4s},[x3],x4
	ld1	{v1.4s},[x2]
	ld1	{v1.4s},[x2],16
	ld1	{v1.4s},[x2],x3
	ld1	{v1.8b,v2.8b,v3.8b,v4.8b},[sp]
	ld1	{v1.8b,v2.8b,v3.8b,v4.8b},[sp],32
	ld1	{v1.8b,v2.8b,v3.8b,v4.8b},[sp],x6
	ld1	{v1.8b,v2.8b,v3.8b},[x4]
	ld1	{v1.8b,v2.8b,v3.8b},[x4],24
	ld1	{v1.8b,v2.8b,v3.8b},[x4],x5
	ld1	{v1.8b,v2.8b},[x3]
	ld1	{v1.8b,v2.8b},[x3],16
	ld1	{v1.8b,v2.8b},[x3],x4
	ld1	{v1.8b},[x2]
	ld1	{v1.8b},[x2],8
	ld1	{v1.8b},[x2],x3
	ld1	{v1.8h,v2.8h,v3.8h,v4.8h},[sp]
	ld1	{v1.8h,v2.8h,v3.8h,v4.8h},[sp],64
	ld1	{v1.8h,v2.8h,v3.8h,v4.8h},[sp],x6
	ld1	{v1.8h,v2.8h,v3.8h},[x4]
	ld1	{v1.8h,v2.8h,v3.8h},[x4],48
	ld1	{v1.8h,v2.8h,v3.8h},[x4],x5
	ld1	{v1.8h,v2.8h},[x3]
	ld1	{v1.8h,v2.8h},[x3],32
	ld1	{v1.8h,v2.8h},[x3],x4
	ld1	{v1.8h},[x2]
	ld1	{v1.8h},[x2],16
	ld1	{v1.8h},[x2],x3
	ld1	{v1.b}[2],[x3]
	ld1	{v1.b}[2],[x3],1
	ld1	{v1.b}[2],[x3],x4
	ld1	{v1.d}[1],[x3]
	ld1	{v1.d}[1],[x3],8
	ld1	{v1.d}[1],[x3],x4
	ld1	{v1.h}[2],[x3]
	ld1	{v1.h}[2],[x3],2
	ld1	{v1.h}[2],[x3],x4
	ld1	{v1.s}[2],[x3]
	ld1	{v1.s}[2],[x3],4
	ld1	{v1.s}[2],[x3],x4

	ld1r	{v1.16b},[x2]
	ld1r	{v1.16b},[x2],1
	ld1r	{v1.16b},[x2],x3
	ld1r	{v1.1d},[x2]
	ld1r	{v1.1d},[x2],8
	ld1r	{v1.1d},[x2],x3
	ld1r	{v1.2d},[x2]
	ld1r	{v1.2d},[x2],8
	ld1r	{v1.2d},[x2],x3
	ld1r	{v1.2s},[x2]
	ld1r	{v1.2s},[x2],4
	ld1r	{v1.2s},[x2],x3
	ld1r	{v1.4h},[x2]
	ld1r	{v1.4h},[x2],2
	ld1r	{v1.4h},[x2],x3
	ld1r	{v1.4s},[x2]
	ld1r	{v1.4s},[x2],4
	ld1r	{v1.4s},[x2],x3
	ld1r	{v1.8b},[x2]
	ld1r	{v1.8b},[x2],1
	ld1r	{v1.8b},[x2],x3
	ld1r	{v1.8h},[x2]
	ld1r	{v1.8h},[x2],2
	ld1r	{v1.8h},[x2],x3

	ld2	{v1.16b,v2.16b},[x3]
	ld2	{v1.16b,v2.16b},[x3],32
	ld2	{v1.16b,v2.16b},[x3],x4
	ld2	{v1.2d,v2.2d},[x3]
	ld2	{v1.2d,v2.2d},[x3],32
	ld2	{v1.2d,v2.2d},[x3],x4
	ld2	{v1.2s,v2.2s},[x3]
	ld2	{v1.2s,v2.2s},[x3],16
	ld2	{v1.2s,v2.2s},[x3],x4
	ld2	{v1.4h,v2.4h},[x3]
	ld2	{v1.4h,v2.4h},[x3],16
	ld2	{v1.4h,v2.4h},[x3],x4
	ld2	{v1.4s,v2.4s},[x3]
	ld2	{v1.4s,v2.4s},[x3],32
	ld2	{v1.4s,v2.4s},[x3],x4
	ld2	{v1.8b,v2.8b},[x3]
	ld2	{v1.8b,v2.8b},[x3],16
	ld2	{v1.8b,v2.8b},[x3],x4
	ld2	{v1.8h,v2.8h},[x3]
	ld2	{v1.8h,v2.8h},[x3],32
	ld2	{v1.8h,v2.8h},[x3],x4
	ld2	{v1.b,v2.b}[15],[x3]
	ld2	{v1.b,v2.b}[2],[x3],2
	ld2	{v1.b,v2.b}[2],[x3],x4
	ld2	{v1.d,v2.d}[1],[x3]
	ld2	{v1.d,v2.d}[1],[x3],16
	ld2	{v1.d,v2.d}[1],[x3],x4
	ld2	{v1.h,v2.h}[2],[x3]
	ld2	{v1.h,v2.h}[2],[x3],4
	ld2	{v1.h,v2.h}[2],[x3],x4
	ld2	{v1.s,v2.s}[2],[x3]
	ld2	{v1.s,v2.s}[2],[x3],8
	ld2	{v1.s,v2.s}[2],[x3],x4

	ld2r	{v1.16b,v2.16b},[x2]
	ld2r	{v1.16b,v2.16b},[x2],2
	ld2r	{v1.16b,v2.16b},[x2],x3
	ld2r	{v1.1d,v2.1d},[x2]
	ld2r	{v1.1d,v2.1d},[x2],16
	ld2r	{v1.1d,v2.1d},[x2],x3
	ld2r	{v1.2d,v2.2d},[x2]
	ld2r	{v1.2d,v2.2d},[x2],16
	ld2r	{v1.2d,v2.2d},[x2],x3
	ld2r	{v1.2s,v2.2s},[x2]
	ld2r	{v1.2s,v2.2s},[x2],8
	ld2r	{v1.2s,v2.2s},[x2],x3
	ld2r	{v1.4h,v2.4h},[x2]
	ld2r	{v1.4h,v2.4h},[x2],4
	ld2r	{v1.4h,v2.4h},[x2],x3
	ld2r	{v1.4s,v2.4s},[x2]
	ld2r	{v1.4s,v2.4s},[x2],8
	ld2r	{v1.4s,v2.4s},[x2],x3
	ld2r	{v1.8b,v2.8b},[x2]
	ld2r	{v1.8b,v2.8b},[x2],2
	ld2r	{v1.8b,v2.8b},[x2],x3
	ld2r	{v1.8h,v2.8h},[x2]
	ld2r	{v1.8h,v2.8h},[x2],4
	ld2r	{v1.8h,v2.8h},[x2],x3

	ld3	{v1.16b,v2.16b,v3.16b},[x3]
	ld3	{v1.16b,v2.16b,v3.16b},[x3],48
	ld3	{v1.16b,v2.16b,v3.16b},[x3],x4
	ld3	{v1.2d,v2.2d,v3.2d},[x3]
	ld3	{v1.2d,v2.2d,v3.2d},[x3],48
	ld3	{v1.2d,v2.2d,v3.2d},[x3],x4
	ld3	{v1.2s,v2.2s,v3.2s},[x3]
	ld3	{v1.2s,v2.2s,v3.2s},[x3],24
	ld3	{v1.2s,v2.2s,v3.2s},[x3],x4
	ld3	{v1.4h,v2.4h,v3.4h},[x3]
	ld3	{v1.4h,v2.4h,v3.4h},[x3],24
	ld3	{v1.4h,v2.4h,v3.4h},[x3],x4
	ld3	{v1.4s,v2.4s,v3.4s},[x3]
	ld3	{v1.4s,v2.4s,v3.4s},[x3],48
	ld3	{v1.4s,v2.4s,v3.4s},[x3],x4
	ld3	{v1.8b,v2.8b,v3.8b},[x3]
	ld3	{v1.8b,v2.8b,v3.8b},[x3],24
	ld3	{v1.8b,v2.8b,v3.8b},[x3],x4
	ld3	{v1.8h,v2.8h,v3.8h},[x3]
	ld3	{v1.8h,v2.8h,v3.8h},[x3],48
	ld3	{v1.8h,v2.8h,v3.8h},[x3],x4
	ld3	{v1.b,v2.b,v3.b}[15],[x3]
	ld3	{v1.b,v2.b,v3.b}[2],[x3],3
	ld3	{v1.b,v2.b,v3.b}[2],[x3],x4
	ld3	{v1.d,v2.d,v3.d}[1],[x3]
	ld3	{v1.d,v2.d,v3.d}[1],[x3],24
	ld3	{v1.d,v2.d,v3.d}[1],[x3],x4
	ld3	{v1.h,v2.h,v3.h}[2],[x3]
	ld3	{v1.h,v2.h,v3.h}[2],[x3],6
	ld3	{v1.h,v2.h,v3.h}[2],[x3],x4
	ld3	{v1.s,v2.s,v3.s}[2],[x3]
	ld3	{v1.s,v2.s,v3.s}[2],[x3],12
	ld3	{v1.s,v2.s,v3.s}[2],[x3],x4

	ld3r	{v1.16b,v2.16b,v3.16b},[x2]
	ld3r	{v1.16b,v2.16b,v3.16b},[x2],3
	ld3r	{v1.16b,v2.16b,v3.16b},[x2],x3
	ld3r	{v1.1d,v2.1d,v3.1d},[x2]
	ld3r	{v1.1d,v2.1d,v3.1d},[x2],24
	ld3r	{v1.1d,v2.1d,v3.1d},[x2],x3
	ld3r	{v1.2d,v2.2d,v3.2d},[x2]
	ld3r	{v1.2d,v2.2d,v3.2d},[x2],24
	ld3r	{v1.2d,v2.2d,v3.2d},[x2],x3
	ld3r	{v1.2s,v2.2s,v3.2s},[x2]
	ld3r	{v1.2s,v2.2s,v3.2s},[x2],12
	ld3r	{v1.2s,v2.2s,v3.2s},[x2],x3
	ld3r	{v1.4h,v2.4h,v3.4h},[x2]
	ld3r	{v1.4h,v2.4h,v3.4h},[x2],6
	ld3r	{v1.4h,v2.4h,v3.4h},[x2],x3
	ld3r	{v1.4s,v2.4s,v3.4s},[x2]
	ld3r	{v1.4s,v2.4s,v3.4s},[x2],12
	ld3r	{v1.4s,v2.4s,v3.4s},[x2],x3
	ld3r	{v1.8b,v2.8b,v3.8b},[x2]
	ld3r	{v1.8b,v2.8b,v3.8b},[x2],3
	ld3r	{v1.8b,v2.8b,v3.8b},[x2],x3
	ld3r	{v1.8h,v2.8h,v3.8h},[x2]
	ld3r	{v1.8h,v2.8h,v3.8h},[x2],6
	ld3r	{v1.8h,v2.8h,v3.8h},[x2],x3

	ld4	{v1.16b,v2.16b,v3.16b,v4.16b},[x3]
	ld4	{v1.16b,v2.16b,v3.16b,v4.16b},[x3],64
	ld4	{v1.16b,v2.16b,v3.16b,v4.16b},[x3],x4
	ld4	{v1.2d,v2.2d,v3.2d,v4.2d},[x3]
	ld4	{v1.2d,v2.2d,v3.2d,v4.2d},[x3],64
	ld4	{v1.2d,v2.2d,v3.2d,v4.2d},[x3],x4
	ld4	{v1.2s,v2.2s,v3.2s,v4.2s},[x3]
	ld4	{v1.2s,v2.2s,v3.2s,v4.2s},[x3],32
	ld4	{v1.2s,v2.2s,v3.2s,v4.2s},[x3],x4
	ld4	{v1.4h,v2.4h,v3.4h,v4.4h},[x3]
	ld4	{v1.4h,v2.4h,v3.4h,v4.4h},[x3],32
	ld4	{v1.4h,v2.4h,v3.4h,v4.4h},[x3],x4
	ld4	{v1.4s,v2.4s,v3.4s,v4.4s},[x3]
	ld4	{v1.4s,v2.4s,v3.4s,v4.4s},[x3],64
	ld4	{v1.4s,v2.4s,v3.4s,v4.4s},[x3],x4
	ld4	{v1.8b,v2.8b,v3.8b,v4.8b},[x3]
	ld4	{v1.8b,v2.8b,v3.8b,v4.8b},[x3],32
	ld4	{v1.8b,v2.8b,v3.8b,v4.8b},[x3],x4
	ld4	{v1.8h,v2.8h,v3.8h,v4.8h},[x3]
	ld4	{v1.8h,v2.8h,v3.8h,v4.8h},[x3],64
	ld4	{v1.8h,v2.8h,v3.8h,v4.8h},[x3],x4
	ld4	{v1.b,v2.b,v3.b,v4.b}[15],[x3]
	ld4	{v1.b,v2.b,v3.b,v4.b}[2],[x3],4
	ld4	{v1.b,v2.b,v3.b,v4.b}[2],[x3],x4
	ld4	{v1.d,v2.d,v3.d,v4.d}[1],[x3]
	ld4	{v1.d,v2.d,v3.d,v4.d}[1],[x3],32
	ld4	{v1.d,v2.d,v3.d,v4.d}[1],[x3],x4
	ld4	{v1.h,v2.h,v3.h,v4.h}[2],[x3]
	ld4	{v1.h,v2.h,v3.h,v4.h}[2],[x3],8
	ld4	{v1.h,v2.h,v3.h,v4.h}[2],[x3],x4
	ld4	{v1.s,v2.s,v3.s,v4.s}[2],[x3]
	ld4	{v1.s,v2.s,v3.s,v4.s}[2],[x3],16
	ld4	{v1.s,v2.s,v3.s,v4.s}[2],[x3],x4

	ld4r	{v1.16b,v2.16b,v3.16b,v4.16b},[x2]
	ld4r	{v1.16b,v2.16b,v3.16b,v4.16b},[x2],4
	ld4r	{v1.16b,v2.16b,v3.16b,v4.16b},[x2],x3
	ld4r	{v1.1d,v2.1d,v3.1d,v4.1d},[x2]
	ld4r	{v1.1d,v2.1d,v3.1d,v4.1d},[x2],32
	ld4r	{v1.1d,v2.1d,v3.1d,v4.1d},[x2],x3
	ld4r	{v1.2d,v2.2d,v3.2d,v4.2d},[x2]
	ld4r	{v1.2d,v2.2d,v3.2d,v4.2d},[x2],32
	ld4r	{v1.2d,v2.2d,v3.2d,v4.2d},[x2],x3
	ld4r	{v1.2s,v2.2s,v3.2s,v4.2s},[x2]
	ld4r	{v1.2s,v2.2s,v3.2s,v4.2s},[x2],16
	ld4r	{v1.2s,v2.2s,v3.2s,v4.2s},[x2],x3
	ld4r	{v1.4h,v2.4h,v3.4h,v4.4h},[x2]
	ld4r	{v1.4h,v2.4h,v3.4h,v4.4h},[x2],8
	ld4r	{v1.4h,v2.4h,v3.4h,v4.4h},[x2],x3
	ld4r	{v1.4s,v2.4s,v3.4s,v4.4s},[x2]
	ld4r	{v1.4s,v2.4s,v3.4s,v4.4s},[x2],16
	ld4r	{v1.4s,v2.4s,v3.4s,v4.4s},[x2],x3
	ld4r	{v1.8b,v2.8b,v3.8b,v4.8b},[x2]
	ld4r	{v1.8b,v2.8b,v3.8b,v4.8b},[x2],4
	ld4r	{v1.8b,v2.8b,v3.8b,v4.8b},[x2],x3
	ld4r	{v1.8h,v2.8h,v3.8h,v4.8h},[x2]
	ld4r	{v1.8h,v2.8h,v3.8h,v4.8h},[x2],8
	ld4r	{v1.8h,v2.8h,v3.8h,v4.8h},[x2],x3

	ldnp	d0,d1,[x2]
	ldnp	d0,d1,[x2,+0x8]
	ldnp	d0,d1,[expression.qword]
	ldnp	q0,q1,[x2]
	ldnp	q0,q1,[x2,+0x20]
	ldnp	q0,q1,[expression.dqword]
	ldnp	s0,s1,[x2]
	ldnp	s0,s1,[x2,+0x8]
	ldnp	s0,s1,[expression.dword]

	ldp	d0,d1,[x2]
	ldp	d0,d1,[x2,+0x8]
	ldp	d0,d1,[expression.qword]
	ldp	d0,d1,[x2,+0x8]!
	ldp	d0,d1,[expression.qword]!
	ldp	d0,d1,[x2],+0x8
	ldp	q0,q1,[x2]
	ldp	q0,q1,[x2,+0x10]
	ldp	q0,q1,[expression.dqword]
	ldp	q0,q1,[x2,+0x10]!
	ldp	q0,q1,[expression.dqword]!
	ldp	q0,q1,[x2],+0x10
	ldp	s0,s1,[x2]
	ldp	s0,s1,[x2,+0x8]
	ldp	s0,s1,[expression.dword]
	ldp	s0,s1,[x2,+0x8]!
	ldp	s0,s1,[expression.dword]!
	ldp	s0,s1,[x2],+0x8

	ldr	b0,[x2]
	ldr	b0,[x2,+0x8]
	ldr	b0,[expression.byte]
	ldr	b0,[x2,+0x8]!
	ldr	b0,[expression.byte]!
	ldr	b0,[x2],+0x8
	ldr	b0,[x2,w3,sxtw]
	ldr	b0,[x2,w3,sxtw 0]
	ldr	b0,[x2,w3,uxtw]
	ldr	b0,[x2,w3,uxtw 0]
	ldr	b0,[x2,x3]
	ldr	b0,[x2,x3,lsl 0]
	ldr	b0,[x2,x3,sxtx]
	ldr	b0,[x2,x3,sxtx 0]
	ldr	h0,[x2]
	ldr	h0,[x2,+0x8]
	ldr	h0,[expression.hword]
	ldr	h0,[x2,+0x8]!
	ldr	h0,[expression.hword]!
	ldr	h0,[x2],+0x8
	ldr	h0,[x2,w3,sxtw]
	ldr	h0,[x2,w3,sxtw 1]
	ldr	h0,[x2,w3,uxtw]
	ldr	h0,[x2,w3,uxtw 1]
	ldr	h0,[x2,x3]
	ldr	h0,[x2,x3,lsl 1]
	ldr	h0,[x2,x3,sxtx]
	ldr	h0,[x2,x3,sxtx 1]
	ldr	s0,[x2,+0x8]
	ldr	s0,[expression.word]
	ldr	s0,[x2,+0x8]!
	ldr	s0,[expression.word]!
	ldr	s0,[x2],+0x8
	ldr	s0,[x2,w3,sxtw]
	ldr	s0,[x2,w3,sxtw 2]
	ldr	s0,[x2,w3,uxtw]
	ldr	s0,[x2,w3,uxtw 2]
	ldr	s0,[x2,x3]
	ldr	s0,[x2,x3,lsl 2]
	ldr	s0,[x2,x3,sxtx]
	ldr	s0,[x2,x3,sxtx 2]
	ldr	s0,label_ldr
	ldr	s0,[label_ldr]
	ldr	d0,[x2,+0x8]
	ldr	d0,[expression.dword]
	ldr	d0,[x2,+0x8]!
	ldr	d0,[expression.dword]!
	ldr	d0,[x2],+0x8
	ldr	d0,[x2,w3,sxtw]
	ldr	d0,[x2,w3,sxtw 3]
	ldr	d0,[x2,w3,uxtw]
	ldr	d0,[x2,w3,uxtw 3]
	ldr	d0,[x2,x3]
	ldr	d0,[x2,x3,lsl 3]
	ldr	d0,[x2,x3,sxtx]
	ldr	d0,[x2,x3,sxtx 3]
	ldr	d0,label_ldr
	ldr	d0,[label_ldr]
	ldr	q0,[x2,+0x8]
	ldr	q0,[expression.qword]
	ldr	q0,[x2,+0x8]!
	ldr	q0,[expression.qword]!
	ldr	q0,[x2],+0x8
	ldr	q0,[x2,w3,sxtw]
	ldr	q0,[x2,w3,sxtw 4]
	ldr	q0,[x2,w3,uxtw]
	ldr	q0,[x2,w3,uxtw 4]
	ldr	q0,[x2,x3]
	ldr	q0,[x2,x3,lsl 4]
	ldr	q0,[x2,x3,sxtx]
	ldr	q0,[x2,x3,sxtx 4]
	ldr	q0,label_ldr
	ldr	q0,[label_ldr]

	ldur	b0,[x2]
	ldur	b0,[x2,+0x8]
	ldur	b0,[expression.byte]
	ldur	h0,[x2]
	ldur	h0,[x2,+0x8]
	ldur	h0,[expression.hword]
	ldur	s0,[x2]
	ldur	s0,[x2,+0x8]
	ldur	s0,[expression.word]
	ldur	d0,[x2]
	ldur	d0,[x2,+0x8]
	ldur	d0,[expression.dword]
	ldur	q0,[x2]
	ldur	q0,[x2,+0x8]
	ldur	q0,[expression.qword]

	mla	v1.16b,v2.16b,v3.16b
	mla	v1.2s,v2.2s,v3.2s
	mla	v1.2s,v2.2s,v3.s[0]
	mla	v1.4h,v2.4h,v3.4h
	mla	v1.4h,v2.4h,v3.h[0]
	mla	v1.4s,v2.4s,v3.4s
	mla	v1.4s,v2.4s,v3.s[3]
	mla	v1.8b,v2.8b,v3.8b
	mla	v1.8h,v2.8h,v3.8h
	mla	v1.8h,v2.8h,v3.h[7]

	mls	v1.16b,v2.16b,v3.16b
	mls	v1.2s,v2.2s,v3.2s
	mls	v1.2s,v2.2s,v3.s[0]
	mls	v1.4h,v2.4h,v3.4h
	mls	v1.4h,v2.4h,v3.h[0]
	mls	v1.4s,v2.4s,v3.4s
	mls	v1.4s,v2.4s,v3.s[3]
	mls	v1.8b,v2.8b,v3.8b
	mls	v1.8h,v2.8h,v3.8h
	mls	v1.8h,v2.8h,v3.h[7]

	mov	b1,v2.b[0]
	mov	h1,v2.h[7]
	mov	s1,v2.s[3]
	mov	d1,v2.d[1]

	mov	v1.16b,v2.16b
	mov	v1.8b,v2.8b
	mov	v1.b[1],v2.b[15]
	mov	v1.d[0],v2.d[1]
	mov	v1.h[1],v2.h[7]
	mov	v1.s[1],v2.s[3]
	mov	v2.b[15],w1
	mov	v2.d[1],x1
	mov	v2.h[7],w1
	mov	v2.s[3],w1
	mov	w1,v2.s[0]
	mov	x1,v2.d[0]

	movi	d1,0xFFFFFFFF00FF00FF
	movi	v1.16b,0xAA
	movi	v1.2d,0x00FF00FF00FF00FF
	movi	v1.2s,0xAA,lsl 0
	movi	v1.2s,0xAA,lsl 8
	movi	v1.2s,0xAA,lsl 16
	movi	v1.2s,0xAA,lsl 24
	movi	v1.2s,0xAA,msl 8
	movi	v1.2s,0xAA,msl 16
	movi	v1.4h,0xAA,lsl 0
	movi	v1.4h,0xAA,lsl 8
	movi	v1.4s,0xAA,lsl 0
	movi	v1.4s,0xAA,lsl 8
	movi	v1.4s,0xAA,lsl 16
	movi	v1.4s,0xAA,lsl 24
	movi	v1.4s,0xAA,msl 8
	movi	v1.4s,0xAA,msl 16
	movi	v1.8b,0xAA
	movi	v1.8h,0xAA,lsl 0
	movi	v1.8h,0xAA,lsl 8

	mul	v1.16b,v2.16b,v3.16b
	mul	v1.2s,v2.2s,v3.2s
	mul	v1.2s,v2.2s,v3.s[0]
	mul	v1.4h,v2.4h,v3.4h
	mul	v1.4h,v2.4h,v3.h[0]
	mul	v1.4s,v2.4s,v3.4s
	mul	v1.4s,v2.4s,v3.s[3]
	mul	v1.8b,v2.8b,v3.8b
	mul	v1.8h,v2.8h,v3.8h
	mul	v1.8h,v2.8h,v3.h[7]

	mvn	v1.16b,v2.16b
	mvn	v1.8b,v2.8b

	mvni	v1.2s,0xAA
	mvni	v1.2s,0xAA,lsl 0
	mvni	v1.2s,0xAA,lsl 8
	mvni	v1.2s,0xAA,lsl 16
	mvni	v1.2s,0xAA,lsl 24
	mvni	v1.2s,0xAA,msl 8
	mvni	v1.2s,0xAA,msl 16
	mvni	v1.4h,0xAA
	mvni	v1.4h,0xAA,lsl 0
	mvni	v1.4h,0xAA,lsl 8
	mvni	v1.4s,0xAA
	mvni	v1.4s,0xAA,lsl 0
	mvni	v1.4s,0xAA,lsl 8
	mvni	v1.4s,0xAA,lsl 16
	mvni	v1.4s,0xAA,lsl 24
	mvni	v1.4s,0xAA,msl 8
	mvni	v1.4s,0xAA,msl 16
	mvni	v1.8h,0xAA
	mvni	v1.8h,0xAA,lsl 0
	mvni	v1.8h,0xAA,lsl 8

	neg	d1,d2
	neg	v1.16b,v2.16b
	neg	v1.2d,v2.2d
	neg	v1.2s,v2.2s
	neg	v1.4h,v2.4h
	neg	v1.4s,v2.4s
	neg	v1.8b,v2.8b
	neg	v1.8h,v2.8h

	not	v1.8b,v2.8b
	not	v1.16b,v2.16b

	orn	v1.16b,v2.16b,v3.16b
	orn	v1.8b,v2.8b,v3.8b

	orr	v1.16b,v2.16b,v3.16b
	orr	v1.8b,v2.8b,v3.8b
	orr	v1.4h,0xFE
	orr	v1.4h,0xFE,lsl 0
	orr	v3.8h,0xFB
	orr	v3.8h,0xFB,lsl 0
	orr	v4.8h,0xF7,lsl 8
	orr	v5.2s,0xEF
	orr	v5.2s,0xEF,lsl 0
	orr	v6.2s,0xDF,lsl 16
	orr	v7.4s,0xBF
	orr	v7.4s,0xBF,lsl 0
	orr	v8.4s,0x80,lsl 24

	pmul	v1.16b,v2.16b,v3.16b
	pmul	v1.8b,v2.8b,v3.8b

	pmull	v1.8h,v2.8b,v3.8b

	pmull2	v1.8h,v2.16b,v3.16b

	raddhn	v1.2s,v2.2d,v3.2d
	raddhn	v1.4h,v2.4s,v3.4s
	raddhn	v1.8b,v2.8h,v3.8h

	raddhn2	v1.16b,v2.8h,v3.8h
	raddhn2	v1.4s,v2.2d,v3.2d
	raddhn2	v1.8h,v2.4s,v3.4s

	rbit	v1.16b,v2.16b
	rbit	v1.8b,v2.8b

	rev16	v1.16b,v2.16b
	rev16	v1.8b,v2.8b

	rev32	v1.16b,v2.16b
	rev32	v1.4h,v2.4h
	rev32	v1.8b,v2.8b
	rev32	v1.8h,v2.8h

	rev64	v1.16b,v2.16b
	rev64	v1.2s,v2.2s
	rev64	v1.4h,v2.4h
	rev64	v1.4s,v2.4s
	rev64	v1.8b,v2.8b
	rev64	v1.8h,v2.8h

	rshrn	v1.2s,v2.2d,32
	rshrn	v1.4h,v2.4s,16
	rshrn	v1.8b,v2.8h,8

	rshrn2	v1.16b,v2.8h,8
	rshrn2	v1.4s,v2.2d,32
	rshrn2	v1.8h,v2.4s,16

	rsubhn	v1.2s,v2.2d,v3.2d
	rsubhn	v1.4h,v2.4s,v3.4s
	rsubhn	v1.8b,v2.8h,v3.8h

	rsubhn2	v1.16b,v2.8h,v3.8h
	rsubhn2	v1.4s,v2.2d,v3.2d
	rsubhn2	v1.8h,v2.4s,v3.4s

	saba	v1.16b,v2.16b,v3.16b
	saba	v1.2s,v2.2s,v3.2s
	saba	v1.4h,v2.4h,v3.4h
	saba	v1.4s,v2.4s,v3.4s
	saba	v1.8b,v2.8b,v3.8b
	saba	v1.8h,v2.8h,v3.8h

	sabal	v1.2d,v2.2s,v3.2s
	sabal	v1.4s,v2.4h,v3.4h
	sabal	v1.8h,v2.8b,v3.8b

	sabal2	v1.2d,v2.4s,v3.4s
	sabal2	v1.4s,v2.8h,v3.8h
	sabal2	v1.8h,v2.16b,v3.16b

	sabd	v1.16b,v2.16b,v3.16b
	sabd	v1.2s,v2.2s,v3.2s
	sabd	v1.4h,v2.4h,v3.4h
	sabd	v1.4s,v2.4s,v3.4s
	sabd	v1.8b,v2.8b,v3.8b
	sabd	v1.8h,v2.8h,v3.8h

	sabdl	v1.2d,v2.2s,v3.2s
	sabdl	v1.4s,v2.4h,v3.4h
	sabdl	v1.8h,v2.8b,v3.8b

	sabdl2	v1.2d,v2.4s,v3.4s
	sabdl2	v1.4s,v2.8h,v3.8h
	sabdl2	v1.8h,v2.16b,v3.16b

	sadalp	v1.1d,v2.2s
	sadalp	v1.2d,v2.4s
	sadalp	v1.2s,v2.4h
	sadalp	v1.4h,v2.8b
	sadalp	v1.4s,v2.8h
	sadalp	v1.8h,v2.16b

	saddl	v1.2d,v2.2s,v3.2s
	saddl	v1.4s,v2.4h,v3.4h
	saddl	v1.8h,v2.8b,v3.8b

	saddl2	v1.2d,v2.4s,v3.4s
	saddl2	v1.4s,v2.8h,v3.8h
	saddl2	v1.8h,v2.16b,v3.16b

	saddlp	v1.1d,v2.2s
	saddlp	v1.2d,v2.4s
	saddlp	v1.2s,v2.4h
	saddlp	v1.4h,v2.8b
	saddlp	v1.4s,v2.8h
	saddlp	v1.8h,v2.16b

	saddlv	d1,v2.4s
	saddlv	h1,v2.16b
	saddlv	h1,v2.8b
	saddlv	s1,v2.4h
	saddlv	s1,v2.8h

	saddw	v1.2d,v2.2d,v3.2s
	saddw	v1.4s,v2.4s,v3.4h
	saddw	v1.8h,v2.8h,v3.8b

	saddw2	v1.2d,v2.2d,v3.4s
	saddw2	v1.4s,v2.4s,v3.8h
	saddw2	v1.8h,v2.8h,v3.16b

	shadd	v1.16b,v2.16b,v3.16b
	shadd	v1.2s,v2.2s,v3.2s
	shadd	v1.4h,v2.4h,v3.4h
	shadd	v1.4s,v2.4s,v3.4s
	shadd	v1.8b,v2.8b,v3.8b
	shadd	v1.8h,v2.8h,v3.8h

	shl	d1,d2,1
	shl	v1.16b,v2.16b,7
	shl	v1.2d,v2.2d,63
	shl	v1.2s,v2.2s,1
	shl	v1.4h,v2.4h,1
	shl	v1.4s,v2.4s,31
	shl	v1.8b,v2.8b,1
	shl	v1.8h,v2.8h,15

	shll	v1.2d,v2.2s,32
	shll	v1.4s,v2.4h,16
	shll	v1.8h,v2.8b,8

	shll2	v1.2d,v2.4s,32
	shll2	v1.4s,v2.8h,16
	shll2	v1.8h,v2.16b,8

	shrn	v1.2s,v2.2d,3
	shrn	v1.4h,v2.4s,2
	shrn	v1.8b,v2.8h,1

	shrn2	v1.16b,v2.8h,1
	shrn2	v1.4s,v2.2d,3
	shrn2	v1.8h,v2.4s,2

	shsub	v1.16b,v2.16b,v3.16b
	shsub	v1.2s,v2.2s,v3.2s
	shsub	v1.4h,v2.4h,v3.4h
	shsub	v1.4s,v2.4s,v3.4s
	shsub	v1.8b,v2.8b,v3.8b
	shsub	v1.8h,v2.8h,v3.8h

	sli	d1,d2,1
	sli	v1.16b,v2.16b,7
	sli	v1.2d,v2.2d,63
	sli	v1.2s,v2.2s,1
	sli	v1.4h,v2.4h,1
	sli	v1.4s,v2.4s,31
	sli	v1.8b,v2.8b,1
	sli	v1.8h,v2.8h,15

	smax	v1.16b,v2.16b,v3.16b
	smax	v1.2s,v2.2s,v3.2s
	smax	v1.4h,v2.4h,v3.4h
	smax	v1.4s,v2.4s,v3.4s
	smax	v1.8b,v2.8b,v3.8b
	smax	v1.8h,v2.8h,v3.8h

	smaxp	v1.16b,v2.16b,v3.16b
	smaxp	v1.2s,v2.2s,v3.2s
	smaxp	v1.4h,v2.4h,v3.4h
	smaxp	v1.4s,v2.4s,v3.4s
	smaxp	v1.8b,v2.8b,v3.8b
	smaxp	v1.8h,v2.8h,v3.8h

	smaxv	b1,v2.16b
	smaxv	b1,v2.8b
	smaxv	h1,v2.4h
	smaxv	h1,v2.8h
	smaxv	s1,v2.4s

	smin	v1.16b,v2.16b,v3.16b
	smin	v1.2s,v2.2s,v3.2s
	smin	v1.4h,v2.4h,v3.4h
	smin	v1.4s,v2.4s,v3.4s
	smin	v1.8b,v2.8b,v3.8b
	smin	v1.8h,v2.8h,v3.8h

	sminp	v1.16b,v2.16b,v3.16b
	sminp	v1.2s,v2.2s,v3.2s
	sminp	v1.4h,v2.4h,v3.4h
	sminp	v1.4s,v2.4s,v3.4s
	sminp	v1.8b,v2.8b,v3.8b
	sminp	v1.8h,v2.8h,v3.8h

	sminv	b1,v2.16b
	sminv	b1,v2.8b
	sminv	h1,v2.4h
	sminv	h1,v2.8h
	sminv	s1,v2.4s

	smlal	v1.2d,v2.2s,v3.2s
	smlal	v1.2d,v2.2s,v31.s[3]
	smlal	v1.4s,v2.4h,v15.h[7]
	smlal	v1.4s,v2.4h,v3.4h
	smlal	v1.8h,v2.8b,v3.8b

	smlal2	v1.2d,v2.4s,v3.4s
	smlal2	v1.2d,v2.4s,v31.s[3]
	smlal2	v1.4s,v2.8h,v15.h[7]
	smlal2	v1.4s,v2.8h,v3.8h
	smlal2	v1.8h,v2.16b,v3.16b

	smlsl	v1.2d,v2.2s,v3.2s
	smlsl	v1.2d,v2.2s,v31.s[3]
	smlsl	v1.4s,v2.4h,v15.h[7]
	smlsl	v1.4s,v2.4h,v3.4h
	smlsl	v1.8h,v2.8b,v3.8b

	smlsl2	v1.2d,v2.4s,v3.4s
	smlsl2	v1.2d,v2.4s,v31.s[3]
	smlsl2	v1.4s,v2.8h,v15.h[7]
	smlsl2	v1.4s,v2.8h,v3.8h
	smlsl2	v1.8h,v2.16b,v3.16b

	smov	w1,v2.b[15]
	smov	w1,v2.h[7]
	smov	x1,v2.b[4]
	smov	x1,v2.h[2]
	smov	x1,v2.s[1]

	smull	v1.2d,v2.2s,v3.2s
	smull	v1.2d,v2.2s,v3.s[0]
	smull	v1.2d,v2.2s,v31.s[3]
	smull	v1.4s,v2.4h,v15.h[7]
	smull	v1.4s,v2.4h,v3.4h
	smull	v1.4s,v2.4h,v3.h[0]
	smull	v1.8h,v2.8b,v3.8b

	smull2	v1.2d,v2.4s,v3.4s
	smull2	v1.2d,v2.4s,v31.s[3]
	smull2	v1.4s,v2.8h,v15.h[7]
	smull2	v1.4s,v2.8h,v3.8h
	smull2	v1.8h,v2.16b,v3.16b

	sqabs	b1,b2
	sqabs	d1,d2
	sqabs	h1,h2
	sqabs	s1,s2
	sqabs	v1.16b,v2.16b
	sqabs	v1.2d,v2.2d
	sqabs	v1.2s,v2.2s
	sqabs	v1.4h,v2.4h
	sqabs	v1.4s,v2.4s
	sqabs	v1.8b,v2.8b
	sqabs	v1.8h,v2.8h

	sqadd	b1,b2,b3
	sqadd	d1,d2,d3
	sqadd	h1,h2,h3
	sqadd	s1,s2,s3
	sqadd	v1.16b,v2.16b,v3.16b
	sqadd	v1.2d,v2.2d,v3.2d
	sqadd	v1.2s,v2.2s,v3.2s
	sqadd	v1.4h,v2.4h,v3.4h
	sqadd	v1.4s,v2.4s,v3.4s
	sqadd	v1.8b,v2.8b,v3.8b
	sqadd	v1.8h,v2.8h,v3.8h

	sqdmlal	v1.2d,v2.2s,v3.2s
	sqdmlal	v1.2d,v2.2s,v31.s[3]
	sqdmlal	v1.4s,v2.4h,v15.h[7]
	sqdmlal	v1.4s,v2.4h,v3.4h

	sqdmlal2	v1.2d,v2.4s,v3.4s
	sqdmlal2	v1.2d,v2.4s,v31.s[3]
	sqdmlal2	v1.4s,v2.8h,v15.h[7]
	sqdmlal2	v1.4s,v2.8h,v3.8h

	sqdmlsl	v1.2d,v2.2s,v3.2s
	sqdmlsl	v1.2d,v2.2s,v31.s[3]
	sqdmlsl	v1.4s,v2.4h,v15.h[7]
	sqdmlsl	v1.4s,v2.4h,v3.4h

	sqdmlsl2	v1.2d,v2.4s,v3.4s
	sqdmlsl2	v1.2d,v2.4s,v31.s[3]
	sqdmlsl2	v1.4s,v2.8h,v15.h[7]
	sqdmlsl2	v1.4s,v2.8h,v3.8h

	sqdmulh	h1,h2,h3
	sqdmulh	h1,h2,v3.h[7]
	sqdmulh	s1,s2,s3
	sqdmulh	s1,s2,v3.s[3]
	sqdmulh	v1.2s,v2.2s,v3.2s
	sqdmulh	v1.2s,v2.2s,v3.s[0]
	sqdmulh	v1.4h,v2.4h,v3.4h
	sqdmulh	v1.4h,v2.4h,v3.h[0]
	sqdmulh	v1.4s,v2.4s,v3.4s
	sqdmulh	v1.4s,v2.4s,v3.s[3]
	sqdmulh	v1.8h,v2.8h,v3.8h
	sqdmulh	v1.8h,v2.8h,v3.h[7]

	sqdmull	v1.2d,v2.2s,v3.2s
	sqdmull	v1.2d,v2.2s,v31.s[3]
	sqdmull	v1.4s,v2.4h,v15.h[7]
	sqdmull	v1.4s,v2.4h,v3.4h

	sqdmull2	v1.2d,v2.4s,v3.4s
	sqdmull2	v1.2d,v2.4s,v31.s[3]
	sqdmull2	v1.4s,v2.8h,v15.h[7]
	sqdmull2	v1.4s,v2.8h,v3.8h

	sqneg	b1,b2
	sqneg	d1,d2
	sqneg	h1,h2
	sqneg	s1,s2
	sqneg	v1.16b,v2.16b
	sqneg	v1.2d,v2.2d
	sqneg	v1.2s,v2.2s
	sqneg	v1.4h,v2.4h
	sqneg	v1.4s,v2.4s
	sqneg	v1.8b,v2.8b
	sqneg	v1.8h,v2.8h

	sqrdmulh	h1,h2,h3
	sqrdmulh	h1,h2,v3.h[7]
	sqrdmulh	s1,s2,s3
	sqrdmulh	s1,s2,v3.s[3]
	sqrdmulh	v1.2s,v2.2s,v3.2s
	sqrdmulh	v1.2s,v2.2s,v3.s[0]
	sqrdmulh	v1.4h,v2.4h,v3.4h
	sqrdmulh	v1.4h,v2.4h,v3.h[0]
	sqrdmulh	v1.4s,v2.4s,v3.4s
	sqrdmulh	v1.4s,v2.4s,v3.s[3]
	sqrdmulh	v1.8h,v2.8h,v3.8h
	sqrdmulh	v1.8h,v2.8h,v3.h[7]

	sqrshl	b1,b2,b3
	sqrshl	d1,d2,d3
	sqrshl	h1,h2,h3
	sqrshl	s1,s2,s3
	sqrshl	v1.16b,v2.16b,v3.16b
	sqrshl	v1.2d,v2.2d,v3.2d
	sqrshl	v1.2s,v2.2s,v3.2s
	sqrshl	v1.4h,v2.4h,v3.4h
	sqrshl	v1.4s,v2.4s,v3.4s
	sqrshl	v1.8b,v2.8b,v3.8b
	sqrshl	v1.8h,v2.8h,v3.8h

	sqrshrn	b8,h8,1
	sqrshrn	h4,s4,2
	sqrshrn	s2,d2,3
	sqrshrn	v1.2s,v2.2d,3
	sqrshrn	v1.4h,v2.4s,2
	sqrshrn	v1.8b,v2.8h,1

	sqrshrn2	v1.16b,v2.8h,1
	sqrshrn2	v1.4s,v2.2d,3
	sqrshrn2	v1.8h,v2.4s,2

	sqrshrun	b8,h8,1
	sqrshrun	h4,s4,2
	sqrshrun	s2,d2,3
	sqrshrun	v1.8b,v2.8h,1
	sqrshrun	v1.4h,v2.4s,2
	sqrshrun	v1.2s,v2.2d,3

	sqrshrun2	v1.16b,v2.8h,1
	sqrshrun2	v1.8h,v2.4s,2
	sqrshrun2	v1.4s,v2.2d,3

	sqshl	b1,b2,1
	sqshl	b1,b2,b3
	sqshl	d1,d2,1
	sqshl	d1,d2,d3
	sqshl	h1,h2,1
	sqshl	h1,h2,h3
	sqshl	s1,s2,1
	sqshl	s1,s2,s3
	sqshl	v1.16b,v2.16b,7
	sqshl	v1.16b,v2.16b,v3.16b
	sqshl	v1.2d,v2.2d,63
	sqshl	v1.2d,v2.2d,v3.2d
	sqshl	v1.2s,v2.2s,1
	sqshl	v1.2s,v2.2s,v3.2s
	sqshl	v1.4h,v2.4h,1
	sqshl	v1.4h,v2.4h,v3.4h
	sqshl	v1.4s,v2.4s,31
	sqshl	v1.4s,v2.4s,v3.4s
	sqshl	v1.8b,v2.8b,1
	sqshl	v1.8b,v2.8b,v3.8b
	sqshl	v1.8h,v2.8h,15
	sqshl	v1.8h,v2.8h,v3.8h

	sqshlu	b1,b2,1
	sqshlu	d1,d2,1
	sqshlu	h1,h2,1
	sqshlu	s1,s2,1
	sqshlu	v1.16b,v2.16b,7
	sqshlu	v1.2d,v2.2d,63
	sqshlu	v1.2s,v2.2s,1
	sqshlu	v1.4h,v2.4h,1
	sqshlu	v1.4s,v2.4s,31
	sqshlu	v1.8b,v2.8b,1
	sqshlu	v1.8h,v2.8h,15

	sqshrn	b8,h8,1
	sqshrn	h4,s4,2
	sqshrn	s2,d2,3
	sqshrn	v1.2s,v2.2d,3
	sqshrn	v1.4h,v2.4s,2
	sqshrn	v1.8b,v2.8h,1

	sqshrn2	v1.16b,v2.8h,1
	sqshrn2	v1.4s,v2.2d,3
	sqshrn2	v1.8h,v2.4s,2

	sqshrun	b8,h8,1
	sqshrun	h4,s4,2
	sqshrun	s2,d2,3
	sqshrun	v1.8b,v2.8h,1
	sqshrun	v1.4h,v2.4s,2
	sqshrun	v1.2s,v2.2d,3

	sqshrun2	v1.16b,v2.8h,1
	sqshrun2	v1.8h,v2.4s,2
	sqshrun2	v1.4s,v2.2d,3

	sqsub	b1,b2,b3
	sqsub	d1,d2,d3
	sqsub	h1,h2,h3
	sqsub	s1,s2,s3
	sqsub	v1.16b,v2.16b,v3.16b
	sqsub	v1.2d,v2.2d,v3.2d
	sqsub	v1.2s,v2.2s,v3.2s
	sqsub	v1.4h,v2.4h,v3.4h
	sqsub	v1.4s,v2.4s,v3.4s
	sqsub	v1.8b,v2.8b,v3.8b
	sqsub	v1.8h,v2.8h,v3.8h

	sqxtn	b8,h8
	sqxtn	h4,s4
	sqxtn	s2,d2
	sqxtn	v1.2s,v2.2d
	sqxtn	v1.4h,v2.4s
	sqxtn	v1.8b,v2.8h

	sqxtn2	v1.16b,v2.8h
	sqxtn2	v1.4s,v2.2d
	sqxtn2	v1.8h,v2.4s

	sqxtun	b8,h8
	sqxtun	h4,s4
	sqxtun	s2,d2
	sqxtun	v1.2s,v2.2d
	sqxtun	v1.4h,v2.4s
	sqxtun	v1.8b,v2.8h

	sqxtun2	v1.16b,v2.8h
	sqxtun2	v1.4s,v2.2d
	sqxtun2	v1.8h,v2.4s

	srhadd	v1.16b,v2.16b,v3.16b
	srhadd	v1.2s,v2.2s,v3.2s
	srhadd	v1.4h,v2.4h,v3.4h
	srhadd	v1.4s,v2.4s,v3.4s
	srhadd	v1.8b,v2.8b,v3.8b
	srhadd	v1.8h,v2.8h,v3.8h

	sri	d1,d2,1
	sri	v1.16b,v2.16b,8
	sri	v1.2d,v2.2d,64
	sri	v1.2s,v2.2s,1
	sri	v1.4h,v2.4h,1
	sri	v1.4s,v2.4s,32
	sri	v1.8b,v2.8b,1
	sri	v1.8h,v2.8h,16

	srshl	d1,d2,d3
	srshl	v1.16b,v2.16b,v3.16b
	srshl	v1.2d,v2.2d,v3.2d
	srshl	v1.2s,v2.2s,v3.2s
	srshl	v1.4h,v2.4h,v3.4h
	srshl	v1.4s,v2.4s,v3.4s
	srshl	v1.8b,v2.8b,v3.8b
	srshl	v1.8h,v2.8h,v3.8h

	srshr	d1,d2,1
	srshr	v1.16b,v2.16b,8
	srshr	v1.2d,v2.2d,64
	srshr	v1.2s,v2.2s,1
	srshr	v1.4h,v2.4h,1
	srshr	v1.4s,v2.4s,32
	srshr	v1.8b,v2.8b,1
	srshr	v1.8h,v2.8h,16

	srsra	d1,d2,1
	srsra	v1.16b,v2.16b,8
	srsra	v1.2d,v2.2d,64
	srsra	v1.2s,v2.2s,1
	srsra	v1.4h,v2.4h,1
	srsra	v1.4s,v2.4s,32
	srsra	v1.8b,v2.8b,1
	srsra	v1.8h,v2.8h,16

	sshl	d1,d2,d3
	sshl	v1.16b,v2.16b,v3.16b
	sshl	v1.2d,v2.2d,v3.2d
	sshl	v1.2s,v2.2s,v3.2s
	sshl	v1.4h,v2.4h,v3.4h
	sshl	v1.4s,v2.4s,v3.4s
	sshl	v1.8b,v2.8b,v3.8b
	sshl	v1.8h,v2.8h,v3.8h

	sshll	v1.2d,v2.2s,3
	sshll	v1.4s,v2.4h,2
	sshll	v1.8h,v2.8b,1

	sshll2	v1.2d,v2.4s,31
	sshll2	v1.4s,v2.8h,15
	sshll2	v1.8h,v2.16b,7

	sshr	d1,d2,1
	sshr	v1.16b,v2.16b,8
	sshr	v1.2d,v2.2d,64
	sshr	v1.2s,v2.2s,1
	sshr	v1.4h,v2.4h,1
	sshr	v1.4s,v2.4s,32
	sshr	v1.8b,v2.8b,1
	sshr	v1.8h,v2.8h,16

	ssra	d1,d2,1
	ssra	v1.16b,v2.16b,8
	ssra	v1.2d,v2.2d,64
	ssra	v1.2s,v2.2s,1
	ssra	v1.4h,v2.4h,1
	ssra	v1.4s,v2.4s,32
	ssra	v1.8b,v2.8b,1
	ssra	v1.8h,v2.8h,16

	ssubl	v1.2d,v2.2s,v3.2s
	ssubl	v1.4s,v2.4h,v3.4h
	ssubl	v1.8h,v2.8b,v3.8b

	ssubl2	v1.2d,v2.4s,v3.4s
	ssubl2	v1.4s,v2.8h,v3.8h
	ssubl2	v1.8h,v2.16b,v3.16b

	ssubw	v1.2d,v2.2d,v3.2s
	ssubw	v1.4s,v2.4s,v3.4h
	ssubw	v1.8h,v2.8h,v3.8b

	ssubw2	v1.2d,v2.2d,v3.4s
	ssubw2	v1.4s,v2.4s,v3.8h
	ssubw2	v1.8h,v2.8h,v3.16b

	st1	{v1.16b,v2.16b,v3.16b,v4.16b},[sp]
	st1	{v1.16b,v2.16b,v3.16b,v4.16b},[sp],64
	st1	{v1.16b,v2.16b,v3.16b,v4.16b},[sp],x6
	st1	{v1.16b,v2.16b,v3.16b},[x4]
	st1	{v1.16b,v2.16b,v3.16b},[x4],48
	st1	{v1.16b,v2.16b,v3.16b},[x4],x5
	st1	{v1.16b,v2.16b},[x3]
	st1	{v1.16b,v2.16b},[x3],32
	st1	{v1.16b,v2.16b},[x3],x4
	st1	{v1.16b},[x2]
	st1	{v1.16b},[x2],16
	st1	{v1.16b},[x2],x3
	st1	{v1.1d,v2.1d,v3.1d,v4.1d},[sp]
	st1	{v1.1d,v2.1d,v3.1d,v4.1d},[sp],32
	st1	{v1.1d,v2.1d,v3.1d,v4.1d},[sp],x6
	st1	{v1.1d,v2.1d,v3.1d},[x4]
	st1	{v1.1d,v2.1d,v3.1d},[x4],24
	st1	{v1.1d,v2.1d,v3.1d},[x4],x5
	st1	{v1.1d,v2.1d},[x3]
	st1	{v1.1d,v2.1d},[x3],16
	st1	{v1.1d,v2.1d},[x3],x4
	st1	{v1.1d},[x2]
	st1	{v1.1d},[x2],8
	st1	{v1.1d},[x2],x3
	st1	{v1.2d,v2.2d,v3.2d,v4.2d},[sp]
	st1	{v1.2d,v2.2d,v3.2d,v4.2d},[sp],64
	st1	{v1.2d,v2.2d,v3.2d,v4.2d},[sp],x6
	st1	{v1.2d,v2.2d,v3.2d},[x4]
	st1	{v1.2d,v2.2d,v3.2d},[x4],48
	st1	{v1.2d,v2.2d,v3.2d},[x4],x5
	st1	{v1.2d,v2.2d},[x3]
	st1	{v1.2d,v2.2d},[x3],32
	st1	{v1.2d,v2.2d},[x3],x4
	st1	{v1.2d},[x2]
	st1	{v1.2d},[x2],16
	st1	{v1.2d},[x2],x3
	st1	{v1.2s,v2.2s,v3.2s,v4.2s},[sp]
	st1	{v1.2s,v2.2s,v3.2s,v4.2s},[sp],32
	st1	{v1.2s,v2.2s,v3.2s,v4.2s},[sp],x6
	st1	{v1.2s,v2.2s,v3.2s},[x4]
	st1	{v1.2s,v2.2s,v3.2s},[x4],24
	st1	{v1.2s,v2.2s,v3.2s},[x4],x5
	st1	{v1.2s,v2.2s},[x3]
	st1	{v1.2s,v2.2s},[x3],16
	st1	{v1.2s,v2.2s},[x3],x4
	st1	{v1.2s},[x2]
	st1	{v1.2s},[x2],8
	st1	{v1.2s},[x2],x3
	st1	{v1.4h,v2.4h,v3.4h,v4.4h},[sp]
	st1	{v1.4h,v2.4h,v3.4h,v4.4h},[sp],32
	st1	{v1.4h,v2.4h,v3.4h,v4.4h},[sp],x6
	st1	{v1.4h,v2.4h,v3.4h},[x4]
	st1	{v1.4h,v2.4h,v3.4h},[x4],24
	st1	{v1.4h,v2.4h,v3.4h},[x4],x5
	st1	{v1.4h,v2.4h},[x3]
	st1	{v1.4h,v2.4h},[x3],16
	st1	{v1.4h,v2.4h},[x3],x4
	st1	{v1.4h},[x2]
	st1	{v1.4h},[x2],8
	st1	{v1.4h},[x2],x3
	st1	{v1.4s,v2.4s,v3.4s,v4.4s},[sp]
	st1	{v1.4s,v2.4s,v3.4s,v4.4s},[sp],64
	st1	{v1.4s,v2.4s,v3.4s,v4.4s},[sp],x6
	st1	{v1.4s,v2.4s,v3.4s},[x4]
	st1	{v1.4s,v2.4s,v3.4s},[x4],48
	st1	{v1.4s,v2.4s,v3.4s},[x4],x5
	st1	{v1.4s,v2.4s},[x3]
	st1	{v1.4s,v2.4s},[x3],32
	st1	{v1.4s,v2.4s},[x3],x4
	st1	{v1.4s},[x2]
	st1	{v1.4s},[x2],16
	st1	{v1.4s},[x2],x3
	st1	{v1.8b,v2.8b,v3.8b,v4.8b},[sp]
	st1	{v1.8b,v2.8b,v3.8b,v4.8b},[sp],32
	st1	{v1.8b,v2.8b,v3.8b,v4.8b},[sp],x6
	st1	{v1.8b,v2.8b,v3.8b},[x4]
	st1	{v1.8b,v2.8b,v3.8b},[x4],24
	st1	{v1.8b,v2.8b,v3.8b},[x4],x5
	st1	{v1.8b,v2.8b},[x3]
	st1	{v1.8b,v2.8b},[x3],16
	st1	{v1.8b,v2.8b},[x3],x4
	st1	{v1.8b},[x2]
	st1	{v1.8b},[x2],8
	st1	{v1.8b},[x2],x3
	st1	{v1.8h,v2.8h,v3.8h,v4.8h},[sp]
	st1	{v1.8h,v2.8h,v3.8h,v4.8h},[sp],64
	st1	{v1.8h,v2.8h,v3.8h,v4.8h},[sp],x6
	st1	{v1.8h,v2.8h,v3.8h},[x4]
	st1	{v1.8h,v2.8h,v3.8h},[x4],48
	st1	{v1.8h,v2.8h,v3.8h},[x4],x5
	st1	{v1.8h,v2.8h},[x3]
	st1	{v1.8h,v2.8h},[x3],32
	st1	{v1.8h,v2.8h},[x3],x4
	st1	{v1.8h},[x2]
	st1	{v1.8h},[x2],16
	st1	{v1.8h},[x2],x3
	st1	{v1.b}[2],[x3]
	st1	{v1.b}[2],[x3],1
	st1	{v1.b}[2],[x3],x4
	st1	{v1.d}[1],[x3]
	st1	{v1.d}[1],[x3],8
	st1	{v1.d}[1],[x3],x4
	st1	{v1.h}[2],[x3]
	st1	{v1.h}[2],[x3],2
	st1	{v1.h}[2],[x3],x4
	st1	{v1.s}[2],[x3]
	st1	{v1.s}[2],[x3],4
	st1	{v1.s}[2],[x3],x4

	st2	{v1.16b,v2.16b},[x3]
	st2	{v1.16b,v2.16b},[x3],32
	st2	{v1.16b,v2.16b},[x3],x4
	st2	{v1.2d,v2.2d},[x3]
	st2	{v1.2d,v2.2d},[x3],32
	st2	{v1.2d,v2.2d},[x3],x4
	st2	{v1.2s,v2.2s},[x3]
	st2	{v1.2s,v2.2s},[x3],16
	st2	{v1.2s,v2.2s},[x3],x4
	st2	{v1.4h,v2.4h},[x3]
	st2	{v1.4h,v2.4h},[x3],16
	st2	{v1.4h,v2.4h},[x3],x4
	st2	{v1.4s,v2.4s},[x3]
	st2	{v1.4s,v2.4s},[x3],32
	st2	{v1.4s,v2.4s},[x3],x4
	st2	{v1.8b,v2.8b},[x3]
	st2	{v1.8b,v2.8b},[x3],16
	st2	{v1.8b,v2.8b},[x3],x4
	st2	{v1.8h,v2.8h},[x3]
	st2	{v1.8h,v2.8h},[x3],32
	st2	{v1.8h,v2.8h},[x3],x4
	st2	{v1.b,v2.b}[15],[x3]
	st2	{v1.b,v2.b}[2],[x3],2
	st2	{v1.b,v2.b}[2],[x3],x4
	st2	{v1.d,v2.d}[1],[x3]
	st2	{v1.d,v2.d}[1],[x3],16
	st2	{v1.d,v2.d}[1],[x3],x4
	st2	{v1.h,v2.h}[2],[x3]
	st2	{v1.h,v2.h}[2],[x3],4
	st2	{v1.h,v2.h}[2],[x3],x4
	st2	{v1.s,v2.s}[2],[x3]
	st2	{v1.s,v2.s}[2],[x3],8
	st2	{v1.s,v2.s}[2],[x3],x4

	st3	{v1.16b,v2.16b,v3.16b},[x3]
	st3	{v1.16b,v2.16b,v3.16b},[x3],48
	st3	{v1.16b,v2.16b,v3.16b},[x3],x4
	st3	{v1.2d,v2.2d,v3.2d},[x3]
	st3	{v1.2d,v2.2d,v3.2d},[x3],48
	st3	{v1.2d,v2.2d,v3.2d},[x3],x4
	st3	{v1.2s,v2.2s,v3.2s},[x3]
	st3	{v1.2s,v2.2s,v3.2s},[x3],24
	st3	{v1.2s,v2.2s,v3.2s},[x3],x4
	st3	{v1.4h,v2.4h,v3.4h},[x3]
	st3	{v1.4h,v2.4h,v3.4h},[x3],24
	st3	{v1.4h,v2.4h,v3.4h},[x3],x4
	st3	{v1.4s,v2.4s,v3.4s},[x3]
	st3	{v1.4s,v2.4s,v3.4s},[x3],48
	st3	{v1.4s,v2.4s,v3.4s},[x3],x4
	st3	{v1.8b,v2.8b,v3.8b},[x3]
	st3	{v1.8b,v2.8b,v3.8b},[x3],24
	st3	{v1.8b,v2.8b,v3.8b},[x3],x4
	st3	{v1.8h,v2.8h,v3.8h},[x3]
	st3	{v1.8h,v2.8h,v3.8h},[x3],48
	st3	{v1.8h,v2.8h,v3.8h},[x3],x4
	st3	{v1.b,v2.b,v3.b}[15],[x3]
	st3	{v1.b,v2.b,v3.b}[2],[x3],3
	st3	{v1.b,v2.b,v3.b}[2],[x3],x4
	st3	{v1.d,v2.d,v3.d}[1],[x3]
	st3	{v1.d,v2.d,v3.d}[1],[x3],24
	st3	{v1.d,v2.d,v3.d}[1],[x3],x4
	st3	{v1.h,v2.h,v3.h}[2],[x3]
	st3	{v1.h,v2.h,v3.h}[2],[x3],6
	st3	{v1.h,v2.h,v3.h}[2],[x3],x4
	st3	{v1.s,v2.s,v3.s}[2],[x3]
	st3	{v1.s,v2.s,v3.s}[2],[x3],12
	st3	{v1.s,v2.s,v3.s}[2],[x3],x4

	st4	{v1.16b,v2.16b,v3.16b,v4.16b},[x3]
	st4	{v1.16b,v2.16b,v3.16b,v4.16b},[x3],64
	st4	{v1.16b,v2.16b,v3.16b,v4.16b},[x3],x4
	st4	{v1.2d,v2.2d,v3.2d,v4.2d},[x3]
	st4	{v1.2d,v2.2d,v3.2d,v4.2d},[x3],64
	st4	{v1.2d,v2.2d,v3.2d,v4.2d},[x3],x4
	st4	{v1.2s,v2.2s,v3.2s,v4.2s},[x3]
	st4	{v1.2s,v2.2s,v3.2s,v4.2s},[x3],32
	st4	{v1.2s,v2.2s,v3.2s,v4.2s},[x3],x4
	st4	{v1.4h,v2.4h,v3.4h,v4.4h},[x3]
	st4	{v1.4h,v2.4h,v3.4h,v4.4h},[x3],32
	st4	{v1.4h,v2.4h,v3.4h,v4.4h},[x3],x4
	st4	{v1.4s,v2.4s,v3.4s,v4.4s},[x3]
	st4	{v1.4s,v2.4s,v3.4s,v4.4s},[x3],64
	st4	{v1.4s,v2.4s,v3.4s,v4.4s},[x3],x4
	st4	{v1.8b,v2.8b,v3.8b,v4.8b},[x3]
	st4	{v1.8b,v2.8b,v3.8b,v4.8b},[x3],32
	st4	{v1.8b,v2.8b,v3.8b,v4.8b},[x3],x4
	st4	{v1.8h,v2.8h,v3.8h,v4.8h},[x3]
	st4	{v1.8h,v2.8h,v3.8h,v4.8h},[x3],64
	st4	{v1.8h,v2.8h,v3.8h,v4.8h},[x3],x4
	st4	{v1.b,v2.b,v3.b,v4.b}[15],[x3]
	st4	{v1.b,v2.b,v3.b,v4.b}[2],[x3],4
	st4	{v1.b,v2.b,v3.b,v4.b}[2],[x3],x4
	st4	{v1.d,v2.d,v3.d,v4.d}[1],[x3]
	st4	{v1.d,v2.d,v3.d,v4.d}[1],[x3],32
	st4	{v1.d,v2.d,v3.d,v4.d}[1],[x3],x4
	st4	{v1.h,v2.h,v3.h,v4.h}[2],[x3]
	st4	{v1.h,v2.h,v3.h,v4.h}[2],[x3],8
	st4	{v1.h,v2.h,v3.h,v4.h}[2],[x3],x4
	st4	{v1.s,v2.s,v3.s,v4.s}[2],[x3]
	st4	{v1.s,v2.s,v3.s,v4.s}[2],[x3],16
	st4	{v1.s,v2.s,v3.s,v4.s}[2],[x3],x4

	stnp	d0,d1,[x2]
	stnp	d0,d1,[x2,+0x8]
	stnp	d0,d1,[expression.qword]
	stnp	q0,q1,[x2]
	stnp	q0,q1,[x2,+0x20]
	stnp	q0,q1,[expression.dqword]
	stnp	s0,s1,[x2]
	stnp	s0,s1,[x2,+0x8]
	stnp	s0,s1,[expression.dword]

	stp	d0,d1,[x2]
	stp	d0,d1,[x2,+0x8]
	stp	d0,d1,[expression.qword]
	stp	d0,d1,[x2,+0x8]!
	stp	d0,d1,[expression.qword]!
	stp	d0,d1,[x2],+0x8
	stp	q0,q1,[x2]
	stp	q0,q1,[x2,+0x10]
	stp	q0,q1,[expression.dqword]
	stp	q0,q1,[x2,+0x10]!
	stp	q0,q1,[expression.dqword]!
	stp	q0,q1,[x2],+0x10
	stp	s0,s1,[x2]
	stp	s0,s1,[x2,+0x8]
	stp	s0,s1,[expression.dword]
	stp	s0,s1,[x2,+0x8]!
	stp	s0,s1,[expression.dword]!
	stp	s0,s1,[x2],+0x8

	str	b0,[x2]
	str	b0,[x2,+0x8]
	str	b0,[expression.byte]
	str	b0,[x2,+0x8]!
	str	b0,[expression.byte]!
	str	b0,[x2],+0x8
	str	b0,[x2,w3,sxtw]
	str	b0,[x2,w3,sxtw 0]
	str	b0,[x2,w3,uxtw]
	str	b0,[x2,w3,uxtw 0]
	str	b0,[x2,x3]
	str	b0,[x2,x3,lsl 0]
	str	b0,[x2,x3,sxtx]
	str	b0,[x2,x3,sxtx 0]
	str	h0,[x2]
	str	h0,[x2,+0x8]
	str	h0,[expression.hword]
	str	h0,[x2,+0x8]!
	str	h0,[expression.hword]!
	str	h0,[x2],+0x8
	str	h0,[x2,w3,sxtw]
	str	h0,[x2,w3,sxtw 1]
	str	h0,[x2,w3,uxtw]
	str	h0,[x2,w3,uxtw 1]
	str	h0,[x2,x3]
	str	h0,[x2,x3,lsl 1]
	str	h0,[x2,x3,sxtx]
	str	h0,[x2,x3,sxtx 1]
	str	s0,[x2,+0x8]
	str	s0,[expression.word]
	str	s0,[x2,+0x8]!
	str	s0,[expression.word]!
	str	s0,[x2],+0x8
	str	s0,[x2,w3,sxtw]
	str	s0,[x2,w3,sxtw 2]
	str	s0,[x2,w3,uxtw]
	str	s0,[x2,w3,uxtw 2]
	str	s0,[x2,x3]
	str	s0,[x2,x3,lsl 2]
	str	s0,[x2,x3,sxtx]
	str	s0,[x2,x3,sxtx 2]
	str	d0,[x2,+0x8]
	str	d0,[expression.dword]
	str	d0,[x2,+0x8]!
	str	d0,[expression.dword]!
	str	d0,[x2],+0x8
	str	d0,[x2,w3,sxtw]
	str	d0,[x2,w3,sxtw 3]
	str	d0,[x2,w3,uxtw]
	str	d0,[x2,w3,uxtw 3]
	str	d0,[x2,x3]
	str	d0,[x2,x3,lsl 3]
	str	d0,[x2,x3,sxtx]
	str	d0,[x2,x3,sxtx 3]
	str	q0,[x2,+0x8]
	str	q0,[expression.qword]
	str	q0,[x2,+0x8]!
	str	q0,[expression.qword]!
	str	q0,[x2],+0x8
	str	q0,[x2,w3,sxtw]
	str	q0,[x2,w3,sxtw 4]
	str	q0,[x2,w3,uxtw]
	str	q0,[x2,w3,uxtw 4]
	str	q0,[x2,x3]
	str	q0,[x2,x3,lsl 4]
	str	q0,[x2,x3,sxtx]
	str	q0,[x2,x3,sxtx 4]

	stur	b0,[x2]
	stur	b0,[x2,+0x8]
	stur	b0,[expression.byte]
	stur	h0,[x2]
	stur	h0,[x2,+0x8]
	stur	h0,[expression.hword]
	stur	s0,[x2]
	stur	s0,[x2,+0x8]
	stur	s0,[expression.word]
	stur	d0,[x2]
	stur	d0,[x2,+0x8]
	stur	d0,[expression.dword]
	stur	q0,[x2]
	stur	q0,[x2,+0x8]
	stur	q0,[expression.qword]

	sub	d1,d2,d3
	sub	v1.16b,v2.16b,v3.16b
	sub	v1.2d,v2.2d,v3.2d
	sub	v1.2s,v2.2s,v3.2s
	sub	v1.4h,v2.4h,v3.4h
	sub	v1.4s,v2.4s,v3.4s
	sub	v1.8b,v2.8b,v3.8b
	sub	v1.8h,v2.8h,v3.8h

	subhn	v1.2s,v2.2d,v3.2d
	subhn	v1.4h,v2.4s,v3.4s
	subhn	v1.8b,v2.8h,v3.8h

	subhn2	v1.16b,v2.8h,v3.8h
	subhn2	v1.4s,v2.2d,v3.2d
	subhn2	v1.8h,v2.4s,v3.4s

	suqadd	b1,b2
	suqadd	d1,d2
	suqadd	h1,h2
	suqadd	s1,s2
	suqadd	v1.16b,v2.16b
	suqadd	v1.2d,v2.2d
	suqadd	v1.2s,v2.2s
	suqadd	v1.4h,v2.4h
	suqadd	v1.4s,v2.4s
	suqadd	v1.8b,v2.8b
	suqadd	v1.8h,v2.8h

	sxtl	v1.2d,v2.2s
	sxtl	v1.4s,v2.4h
	sxtl	v1.8h,v2.8b

	sxtl2	v1.2d,v2.4s
	sxtl2	v1.4s,v2.8h
	sxtl2	v1.8h,v2.16b

	tbl	v1.8b,{v2.16b},v6.8b
	tbl	v1.8b,{v2.16b,v3.16b},v6.8b
	tbl	v1.8b,{v2.16b,v3.16b,v4.16b},v6.8b
	tbl	v1.8b,{v2.16b,v3.16b,v4.16b,v5.16b},v6.8b

	tbx	v1.8b,{v2.16b},v6.8b
	tbx	v1.8b,{v2.16b,v3.16b},v6.8b
	tbx	v1.8b,{v2.16b,v3.16b,v4.16b},v6.8b
	tbx	v1.8b,{v2.16b,v3.16b,v4.16b,v5.16b},v6.8b

	trn1	v1.16b,v2.16b,v3.16b
	trn1	v1.2d,v2.2d,v3.2d
	trn1	v1.2s,v2.2s,v3.2s
	trn1	v1.4h,v2.4h,v3.4h
	trn1	v1.4s,v2.4s,v3.4s
	trn1	v1.8b,v2.8b,v3.8b
	trn1	v1.8h,v2.8h,v3.8h

	trn2	v1.16b,v2.16b,v3.16b
	trn2	v1.2d,v2.2d,v3.2d
	trn2	v1.2s,v2.2s,v3.2s
	trn2	v1.4h,v2.4h,v3.4h
	trn2	v1.4s,v2.4s,v3.4s
	trn2	v1.8b,v2.8b,v3.8b
	trn2	v1.8h,v2.8h,v3.8h

	uaba	v1.16b,v2.16b,v3.16b
	uaba	v1.2s,v2.2s,v3.2s
	uaba	v1.4h,v2.4h,v3.4h
	uaba	v1.4s,v2.4s,v3.4s
	uaba	v1.8b,v2.8b,v3.8b
	uaba	v1.8h,v2.8h,v3.8h

	uabal	v1.2d,v2.2s,v3.2s
	uabal	v1.4s,v2.4h,v3.4h
	uabal	v1.8h,v2.8b,v3.8b

	uabal2	v1.2d,v2.4s,v3.4s
	uabal2	v1.4s,v2.8h,v3.8h
	uabal2	v1.8h,v2.16b,v3.16b

	uabd	v1.16b,v2.16b,v3.16b
	uabd	v1.2s,v2.2s,v3.2s
	uabd	v1.4h,v2.4h,v3.4h
	uabd	v1.4s,v2.4s,v3.4s
	uabd	v1.8b,v2.8b,v3.8b
	uabd	v1.8h,v2.8h,v3.8h

	uabdl	v1.2d,v2.2s,v3.2s
	uabdl	v1.4s,v2.4h,v3.4h
	uabdl	v1.8h,v2.8b,v3.8b

	uabdl2	v1.2d,v2.4s,v3.4s
	uabdl2	v1.4s,v2.8h,v3.8h
	uabdl2	v1.8h,v2.16b,v3.16b

	uadalp	v1.1d,v2.2s
	uadalp	v1.2d,v2.4s
	uadalp	v1.2s,v2.4h
	uadalp	v1.4h,v2.8b
	uadalp	v1.4s,v2.8h
	uadalp	v1.8h,v2.16b

	uaddl	v1.2d,v2.2s,v3.2s
	uaddl	v1.4s,v2.4h,v3.4h
	uaddl	v1.8h,v2.8b,v3.8b

	uaddl2	v1.2d,v2.4s,v3.4s
	uaddl2	v1.4s,v2.8h,v3.8h
	uaddl2	v1.8h,v2.16b,v3.16b

	uaddlp	v1.1d,v2.2s
	uaddlp	v1.2d,v2.4s
	uaddlp	v1.2s,v2.4h
	uaddlp	v1.4h,v2.8b
	uaddlp	v1.4s,v2.8h
	uaddlp	v1.8h,v2.16b

	uaddlv	d1,v2.4s
	uaddlv	h1,v2.16b
	uaddlv	h1,v2.8b
	uaddlv	s1,v2.4h
	uaddlv	s1,v2.8h

	uaddw	v1.2d,v2.2d,v3.2s
	uaddw	v1.4s,v2.4s,v3.4h
	uaddw	v1.8h,v2.8h,v3.8b

	uaddw2	v1.2d,v2.2d,v3.4s
	uaddw2	v1.4s,v2.4s,v3.8h
	uaddw2	v1.8h,v2.8h,v3.16b

	uhadd	v1.16b,v2.16b,v3.16b
	uhadd	v1.2s,v2.2s,v3.2s
	uhadd	v1.4h,v2.4h,v3.4h
	uhadd	v1.4s,v2.4s,v3.4s
	uhadd	v1.8b,v2.8b,v3.8b
	uhadd	v1.8h,v2.8h,v3.8h

	uhsub	v1.16b,v2.16b,v3.16b
	uhsub	v1.2s,v2.2s,v3.2s
	uhsub	v1.4h,v2.4h,v3.4h
	uhsub	v1.4s,v2.4s,v3.4s
	uhsub	v1.8b,v2.8b,v3.8b
	uhsub	v1.8h,v2.8h,v3.8h

	umax	v1.16b,v2.16b,v3.16b
	umax	v1.2s,v2.2s,v3.2s
	umax	v1.4h,v2.4h,v3.4h
	umax	v1.4s,v2.4s,v3.4s
	umax	v1.8b,v2.8b,v3.8b
	umax	v1.8h,v2.8h,v3.8h

	umaxp	v1.16b,v2.16b,v3.16b
	umaxp	v1.2s,v2.2s,v3.2s
	umaxp	v1.4h,v2.4h,v3.4h
	umaxp	v1.4s,v2.4s,v3.4s
	umaxp	v1.8b,v2.8b,v3.8b
	umaxp	v1.8h,v2.8h,v3.8h

	umaxv	b1,v2.16b
	umaxv	b1,v2.8b
	umaxv	h1,v2.4h
	umaxv	h1,v2.8h
	umaxv	s1,v2.4s

	umin	v1.16b,v2.16b,v3.16b
	umin	v1.2s,v2.2s,v3.2s
	umin	v1.4h,v2.4h,v3.4h
	umin	v1.4s,v2.4s,v3.4s
	umin	v1.8b,v2.8b,v3.8b
	umin	v1.8h,v2.8h,v3.8h

	uminp	v1.16b,v2.16b,v3.16b
	uminp	v1.2s,v2.2s,v3.2s
	uminp	v1.4h,v2.4h,v3.4h
	uminp	v1.4s,v2.4s,v3.4s
	uminp	v1.8b,v2.8b,v3.8b
	uminp	v1.8h,v2.8h,v3.8h

	uminv	b1,v2.16b
	uminv	b1,v2.8b
	uminv	h1,v2.4h
	uminv	h1,v2.8h
	uminv	s1,v2.4s

	umlal	v1.2d,v2.2s,v3.2s
	umlal	v1.2d,v2.2s,v31.s[3]
	umlal	v1.4s,v2.4h,v15.h[7]
	umlal	v1.4s,v2.4h,v3.4h
	umlal	v1.8h,v2.8b,v3.8b

	umlal2	v1.2d,v2.4s,v3.4s
	umlal2	v1.2d,v2.4s,v31.s[3]
	umlal2	v1.4s,v2.8h,v15.h[7]
	umlal2	v1.4s,v2.8h,v3.8h
	umlal2	v1.8h,v2.16b,v3.16b

	umlsl	v1.2d,v2.2s,v3.2s
	umlsl	v1.2d,v2.2s,v31.s[3]
	umlsl	v1.4s,v2.4h,v15.h[7]
	umlsl	v1.4s,v2.4h,v3.4h
	umlsl	v1.8h,v2.8b,v3.8b

	umlsl2	v1.2d,v2.4s,v3.4s
	umlsl2	v1.2d,v2.4s,v31.s[3]
	umlsl2	v1.4s,v2.8h,v15.h[7]
	umlsl2	v1.4s,v2.8h,v3.8h
	umlsl2	v1.8h,v2.16b,v3.16b

	umov	w1,v2.b[15]
	umov	w1,v2.h[4]
	umov	w1,v2.s[2]
	umov	x1,v2.d[1]

	umull	v1.2d,v2.2s,v3.2s
	umull	v1.2d,v2.2s,v3.s[0]
	umull	v1.2d,v2.2s,v3.s[2]
	umull	v1.4s,v2.4h,v3.4h
	umull	v1.4s,v2.4h,v3.h[0]
	umull	v1.4s,v2.4h,v3.h[4]
	umull	v1.8h,v2.8b,v3.8b

	umull2	v1.2d,v2.4s,v3.4s
	umull2	v1.2d,v2.4s,v31.s[3]
	umull2	v1.4s,v2.8h,v15.h[7]
	umull2	v1.4s,v2.8h,v3.8h
	umull2	v1.8h,v2.16b,v3.16b

	uqadd	b1,b2,b3
	uqadd	d1,d2,d3
	uqadd	h1,h2,h3
	uqadd	s1,s2,s3
	uqadd	v1.16b,v2.16b,v3.16b
	uqadd	v1.2d,v2.2d,v3.2d
	uqadd	v1.2s,v2.2s,v3.2s
	uqadd	v1.4h,v2.4h,v3.4h
	uqadd	v1.4s,v2.4s,v3.4s
	uqadd	v1.8b,v2.8b,v3.8b
	uqadd	v1.8h,v2.8h,v3.8h

	uqrshl	b1,b2,b3
	uqrshl	d1,d2,d3
	uqrshl	h1,h2,h3
	uqrshl	s1,s2,s3
	uqrshl	v1.16b,v2.16b,v3.16b
	uqrshl	v1.2d,v2.2d,v3.2d
	uqrshl	v1.2s,v2.2s,v3.2s
	uqrshl	v1.4h,v2.4h,v3.4h
	uqrshl	v1.4s,v2.4s,v3.4s
	uqrshl	v1.8b,v2.8b,v3.8b
	uqrshl	v1.8h,v2.8h,v3.8h

	uqrshrn	b8,h8,1
	uqrshrn	h4,s4,2
	uqrshrn	s2,d2,3
	uqrshrn	v1.2s,v2.2d,3
	uqrshrn	v1.4h,v2.4s,2
	uqrshrn	v1.8b,v2.8h,1

	uqrshrn2	v1.16b,v2.8h,1
	uqrshrn2	v1.4s,v2.2d,3
	uqrshrn2	v1.8h,v2.4s,2

	uqshl	b1,b2,7
	uqshl	b1,b2,b3
	uqshl	d1,d2,63
	uqshl	d1,d2,d3
	uqshl	h1,h2,15
	uqshl	h1,h2,h3
	uqshl	s1,s2,31
	uqshl	s1,s2,s3
	uqshl	v1.16b,v2.16b,7
	uqshl	v1.16b,v2.16b,v3.16b
	uqshl	v1.2d,v2.2d,63
	uqshl	v1.2d,v2.2d,v3.2d
	uqshl	v1.2s,v2.2s,1
	uqshl	v1.2s,v2.2s,v3.2s
	uqshl	v1.4h,v2.4h,1
	uqshl	v1.4h,v2.4h,v3.4h
	uqshl	v1.4s,v2.4s,31
	uqshl	v1.4s,v2.4s,v3.4s
	uqshl	v1.8b,v2.8b,1
	uqshl	v1.8b,v2.8b,v3.8b
	uqshl	v1.8h,v2.8h,15
	uqshl	v1.8h,v2.8h,v3.8h

	uqshrn	b8,h8,1
	uqshrn	h4,s4,2
	uqshrn	s2,d2,3
	uqshrn	v1.2s,v2.2d,3
	uqshrn	v1.4h,v2.4s,2
	uqshrn	v1.8b,v2.8h,1

	uqshrn2	v1.16b,v2.8h,1
	uqshrn2	v1.4s,v2.2d,3
	uqshrn2	v1.8h,v2.4s,2

	uqsub	b1,b2,b3
	uqsub	d1,d2,d3
	uqsub	h1,h2,h3
	uqsub	s1,s2,s3
	uqsub	v1.16b,v2.16b,v3.16b
	uqsub	v1.2d,v2.2d,v3.2d
	uqsub	v1.2s,v2.2s,v3.2s
	uqsub	v1.4h,v2.4h,v3.4h
	uqsub	v1.4s,v2.4s,v3.4s
	uqsub	v1.8b,v2.8b,v3.8b
	uqsub	v1.8h,v2.8h,v3.8h

	uqxtn	b8,h8
	uqxtn	h4,s4
	uqxtn	s2,d2
	uqxtn	v1.2s,v2.2d
	uqxtn	v1.4h,v2.4s
	uqxtn	v1.8b,v2.8h

	uqxtn2	v1.16b,v2.8h
	uqxtn2	v1.4s,v2.2d
	uqxtn2	v1.8h,v2.4s

	urhadd	v1.16b,v2.16b,v3.16b
	urhadd	v1.2s,v2.2s,v3.2s
	urhadd	v1.4h,v2.4h,v3.4h
	urhadd	v1.4s,v2.4s,v3.4s
	urhadd	v1.8b,v2.8b,v3.8b
	urhadd	v1.8h,v2.8h,v3.8h

	urshl	d1,d2,d3
	urshl	v1.16b,v2.16b,v3.16b
	urshl	v1.2d,v2.2d,v3.2d
	urshl	v1.2s,v2.2s,v3.2s
	urshl	v1.4h,v2.4h,v3.4h
	urshl	v1.4s,v2.4s,v3.4s
	urshl	v1.8b,v2.8b,v3.8b
	urshl	v1.8h,v2.8h,v3.8h

	urshr	d1,d2,1
	urshr	v1.16b,v2.16b,8
	urshr	v1.2d,v2.2d,64
	urshr	v1.2s,v2.2s,1
	urshr	v1.4h,v2.4h,1
	urshr	v1.4s,v2.4s,32
	urshr	v1.8b,v2.8b,1
	urshr	v1.8h,v2.8h,16

	ursra	d1,d2,1
	ursra	v1.16b,v2.16b,8
	ursra	v1.2d,v2.2d,64
	ursra	v1.2s,v2.2s,1
	ursra	v1.4h,v2.4h,1
	ursra	v1.4s,v2.4s,32
	ursra	v1.8b,v2.8b,1
	ursra	v1.8h,v2.8h,16

	ushl	d1,d2,d3
	ushl	v1.16b,v2.16b,v3.16b
	ushl	v1.2d,v2.2d,v3.2d
	ushl	v1.2s,v2.2s,v3.2s
	ushl	v1.4h,v2.4h,v3.4h
	ushl	v1.4s,v2.4s,v3.4s
	ushl	v1.8b,v2.8b,v3.8b
	ushl	v1.8h,v2.8h,v3.8h

	ushll	v1.2d,v2.2s,3
	ushll	v1.4s,v2.4h,2
	ushll	v1.8h,v2.8b,1

	ushll2	v1.2d,v2.4s,31
	ushll2	v1.4s,v2.8h,15
	ushll2	v1.8h,v2.16b,7

	ushr	d1,d2,1
	ushr	v1.16b,v2.16b,8
	ushr	v1.2d,v2.2d,64
	ushr	v1.2s,v2.2s,1
	ushr	v1.4h,v2.4h,1
	ushr	v1.4s,v2.4s,32
	ushr	v1.8b,v2.8b,1
	ushr	v1.8h,v2.8h,16

	usqadd	b1,b2
	usqadd	d1,d2
	usqadd	h1,h2
	usqadd	s1,s2
	usqadd	v1.16b,v2.16b
	usqadd	v1.2d,v2.2d
	usqadd	v1.2s,v2.2s
	usqadd	v1.4h,v2.4h
	usqadd	v1.4s,v2.4s
	usqadd	v1.8b,v2.8b
	usqadd	v1.8h,v2.8h

	usra	d1,d2,1
	usra	v1.16b,v2.16b,8
	usra	v1.2d,v2.2d,64
	usra	v1.2s,v2.2s,1
	usra	v1.4h,v2.4h,1
	usra	v1.4s,v2.4s,32
	usra	v1.8b,v2.8b,1
	usra	v1.8h,v2.8h,16

	usubl	v1.2d,v2.2s,v3.2s
	usubl	v1.4s,v2.4h,v3.4h
	usubl	v1.8h,v2.8b,v3.8b

	usubl2	v1.2d,v2.4s,v3.4s
	usubl2	v1.4s,v2.8h,v3.8h
	usubl2	v1.8h,v2.16b,v3.16b

	usubw	v1.2d,v2.2d,v3.2s
	usubw	v1.4s,v2.4s,v3.4h
	usubw	v1.8h,v2.8h,v3.8b

	usubw2	v1.2d,v2.2d,v3.4s
	usubw2	v1.4s,v2.4s,v3.8h
	usubw2	v1.8h,v2.8h,v3.16b

	uxtl	v1.2d,v2.2s
	uxtl	v1.4s,v2.4h
	uxtl	v1.8h,v2.8b

	uxtl2	v1.2d,v2.4s
	uxtl2	v1.4s,v2.8h
	uxtl2	v1.8h,v2.16b

	uzp1	v1.16b,v2.16b,v3.16b
	uzp1	v1.2d,v2.2d,v3.2d
	uzp1	v1.2s,v2.2s,v3.2s
	uzp1	v1.4h,v2.4h,v3.4h
	uzp1	v1.4s,v2.4s,v3.4s
	uzp1	v1.8b,v2.8b,v3.8b
	uzp1	v1.8h,v2.8h,v3.8h

	uzp2	v1.16b,v2.16b,v3.16b
	uzp2	v1.2d,v2.2d,v3.2d
	uzp2	v1.2s,v2.2s,v3.2s
	uzp2	v1.4h,v2.4h,v3.4h
	uzp2	v1.4s,v2.4s,v3.4s
	uzp2	v1.8b,v2.8b,v3.8b
	uzp2	v1.8h,v2.8h,v3.8h

	xtn	v1.8b,v2.8h
	xtn	v1.4h,v2.4s
	xtn	v1.2s,v2.2d

	xtn2	v1.16b,v2.8h
	xtn2	v1.8h,v2.4s
	xtn2	v1.4s,v2.2d

	zip1	v1.16b,v2.16b,v3.16b
	zip1	v1.2d,v2.2d,v3.2d
	zip1	v1.2s,v2.2s,v3.2s
	zip1	v1.4h,v2.4h,v3.4h
	zip1	v1.4s,v2.4s,v3.4s
	zip1	v1.8b,v2.8b,v3.8b
	zip1	v1.8h,v2.8h,v3.8h

	zip2	v1.16b,v2.16b,v3.16b
	zip2	v1.2d,v2.2d,v3.2d
	zip2	v1.2s,v2.2s,v3.2s
	zip2	v1.4h,v2.4h,v3.4h
	zip2	v1.4s,v2.4s,v3.4s
	zip2	v1.8b,v2.8b,v3.8b
	zip2	v1.8h,v2.8h,v3.8h

processor CPU64_CRC

	crc32b	w1,w2,w3

	crc32cb	w1,w2,w3

	crc32ch	w1,w2,w3

	crc32cw	w1,w2,w3

	crc32cx	w1,w2,x3

	crc32h	w1,w2,w3

	crc32w	w1,w2,w3

	crc32x	w1,w2,x3

processor CPU64_CRYPTO

	aesd	v1.16b,v2.16b

	aese	v1.16b,v2.16b

	aesimc	v1.16b,v2.16b

	aesmc	v1.16b,v2.16b

	pmull	v1.1q,v2.1d,v3.1d

	pmull2	v1.1q,v2.2d,v3.2d

	sha1c	q1,s2,v3.4s

	sha1h	s1,s2

	sha1m	q1,s2,v3.4s

	sha1p	q1,s2,v3.4s

	sha1su0	v1.4s,v2.4s,v3.4s

	sha1su1	v1.4s,v2.4s

	sha256h	q1,q2,v3.4s

	sha256h2	q1,q2,v3.4s

	sha256su0	v1.4s,v2.4s

	sha256su1	v1.4s,v2.4s,v3.4s
