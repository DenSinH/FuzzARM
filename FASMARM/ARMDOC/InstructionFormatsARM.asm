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
	;ARM mode, all instructions are 32-bit
	;***********************************************

	code32

processor CPU32_26BIT

	cmnp	r0,1
	cmnp	r0,1,2
	cmnp	r0,r1
	cmnp	r0,r1,rrx
	cmnp	r0,r1,lsl 2
	cmnp	r0,r1,lsr 2
	cmnp	r0,r1,asr 2
	cmnp	r0,r1,ror 2
	cmnp	r0,r1,lsl r2
	cmnp	r0,r1,lsr r2
	cmnp	r0,r1,asr r2
	cmnp	r0,r1,ror r2

	cmpp	r0,1
	cmpp	r0,1,2
	cmpp	r0,r1
	cmpp	r0,r1,rrx
	cmpp	r0,r1,lsl 2
	cmpp	r0,r1,lsr 2
	cmpp	r0,r1,asr 2
	cmpp	r0,r1,ror 2
	cmpp	r0,r1,lsl r2
	cmpp	r0,r1,lsr r2
	cmpp	r0,r1,asr r2
	cmpp	r0,r1,ror r2

	teqp	r0,1
	teqp	r0,1,2
	teqp	r0,r1
	teqp	r0,r1,rrx
	teqp	r0,r1,lsl 2
	teqp	r0,r1,lsr 2
	teqp	r0,r1,asr 2
	teqp	r0,r1,ror 2
	teqp	r0,r1,lsl r2
	teqp	r0,r1,lsr r2
	teqp	r0,r1,asr r2
	teqp	r0,r1,ror r2

	tstp	r0,1
	tstp	r0,1,2
	tstp	r0,r1
	tstp	r0,r1,rrx
	tstp	r0,r1,lsl 2
	tstp	r0,r1,lsr 2
	tstp	r0,r1,asr 2
	tstp	r0,r1,ror 2
	tstp	r0,r1,lsl r2
	tstp	r0,r1,lsr r2
	tstp	r0,r1,asr r2
	tstp	r0,r1,ror r2

processor CPU32_V1

	adc	r0,1
	adc	r0,1,2
	adc	r0,r1
	adc	r0,r1,rrx
	adc	r0,r1,lsl 2
	adc	r0,r1,lsr 2
	adc	r0,r1,asr 2
	adc	r0,r1,ror 2
	adc	r0,r1,lsl r2
	adc	r0,r1,lsr r2
	adc	r0,r1,asr r2
	adc	r0,r1,ror r2
	adc	r0,r1,2
	adc	r0,r1,2,4
	adc	r0,r1,r2
	adc	r0,r1,r2,rrx
	adc	r0,r1,r2,lsl 3
	adc	r0,r1,r2,lsr 3
	adc	r0,r1,r2,asr 3
	adc	r0,r1,r2,ror 3
	adc	r0,r1,r2,lsl r3
	adc	r0,r1,r2,lsr r3
	adc	r0,r1,r2,asr r3
	adc	r0,r1,r2,ror r3

	add	r0,1
	add	r0,1,2
	add	r0,r1
	add	r0,r1,rrx
	add	r0,r1,lsl 2
	add	r0,r1,lsr 2
	add	r0,r1,asr 2
	add	r0,r1,ror 2
	add	r0,r1,lsl r2
	add	r0,r1,lsr r2
	add	r0,r1,asr r2
	add	r0,r1,ror r2
	add	r0,r1,2
	add	r0,r1,2,4
	add	r0,r1,r2
	add	r0,r1,r2,rrx
	add	r0,r1,r2,lsl 3
	add	r0,r1,r2,lsr 3
	add	r0,r1,r2,asr 3
	add	r0,r1,r2,ror 3
	add	r0,r1,r2,lsl r3
	add	r0,r1,r2,lsr r3
	add	r0,r1,r2,asr r3
	add	r0,r1,r2,ror r3

	addw	r0,1
	addw	r0,r1,2

	label_adr:
	adr	r0,label_adr

	and	r0,1
	and	r0,1,2
	and	r0,r1
	and	r0,r1,rrx
	and	r0,r1,lsl 2
	and	r0,r1,lsr 2
	and	r0,r1,asr 2
	and	r0,r1,ror 2
	and	r0,r1,lsl r2
	and	r0,r1,lsr r2
	and	r0,r1,asr r2
	and	r0,r1,ror r2
	and	r0,r1,2
	and	r0,r1,2,4
	and	r0,r1,r2
	and	r0,r1,r2,rrx
	and	r0,r1,r2,lsl 3
	and	r0,r1,r2,lsr 3
	and	r0,r1,r2,asr 3
	and	r0,r1,r2,ror 3
	and	r0,r1,r2,lsl r3
	and	r0,r1,r2,lsr r3
	and	r0,r1,r2,asr r3
	and	r0,r1,r2,ror r3

	asr	r0,1
	asr	r0,r1
	asr	r0,r1,2
	asr	r0,r1,r2

	label_b:
	b	label_b

	bic	r0,1
	bic	r0,1,2
	bic	r0,r1
	bic	r0,r1,rrx
	bic	r0,r1,lsl 2
	bic	r0,r1,lsr 2
	bic	r0,r1,asr 2
	bic	r0,r1,ror 2
	bic	r0,r1,lsl r2
	bic	r0,r1,lsr r2
	bic	r0,r1,asr r2
	bic	r0,r1,ror r2
	bic	r0,r1,2
	bic	r0,r1,2,4
	bic	r0,r1,r2
	bic	r0,r1,r2,rrx
	bic	r0,r1,r2,lsl 3
	bic	r0,r1,r2,lsr 3
	bic	r0,r1,r2,asr 3
	bic	r0,r1,r2,ror 3
	bic	r0,r1,r2,lsl r3
	bic	r0,r1,r2,lsr r3
	bic	r0,r1,r2,asr r3
	bic	r0,r1,r2,ror r3

	label_bl:
	bl	label_bl

	cmn	r0,1
	cmn	r0,1,2
	cmn	r0,r1
	cmn	r0,r1,rrx
	cmn	r0,r1,lsl 2
	cmn	r0,r1,lsr 2
	cmn	r0,r1,asr 2
	cmn	r0,r1,ror 2
	cmn	r0,r1,lsl r2
	cmn	r0,r1,lsr r2
	cmn	r0,r1,asr r2
	cmn	r0,r1,ror r2

	cmp	r0,1
	cmp	r0,1,2
	cmp	r0,r1
	cmp	r0,r1,rrx
	cmp	r0,r1,lsl 2
	cmp	r0,r1,lsr 2
	cmp	r0,r1,asr 2
	cmp	r0,r1,ror 2
	cmp	r0,r1,lsl r2
	cmp	r0,r1,lsr r2
	cmp	r0,r1,asr r2
	cmp	r0,r1,ror r2

	cpy	r0,r1

	eor	r0,1
	eor	r0,1,2
	eor	r0,r1
	eor	r0,r1,rrx
	eor	r0,r1,lsl 2
	eor	r0,r1,lsr 2
	eor	r0,r1,asr 2
	eor	r0,r1,ror 2
	eor	r0,r1,lsl r2
	eor	r0,r1,lsr r2
	eor	r0,r1,asr r2
	eor	r0,r1,ror r2
	eor	r0,r1,2
	eor	r0,r1,2,4
	eor	r0,r1,r2
	eor	r0,r1,r2,rrx
	eor	r0,r1,r2,lsl 3
	eor	r0,r1,r2,lsr 3
	eor	r0,r1,r2,asr 3
	eor	r0,r1,r2,ror 3
	eor	r0,r1,r2,lsl r3
	eor	r0,r1,r2,lsr r3
	eor	r0,r1,r2,asr r3
	eor	r0,r1,r2,ror r3

	ldm	r0,{r1}
	ldm	r0,{r1,r2}
	ldm	r0,{r1-r3}
	ldm	r0,{r1-r3,r5}
	ldm	r0,{r1}^
	ldm	r0,{r1,r2}^
	ldm	r0,{r1-r3}^
	ldm	r0,{r1-r3,r5}^
	ldm	r0!,{r1}
	ldm	r0!,{r1,r2}
	ldm	r0!,{r1-r3}
	ldm	r0!,{r1-r3,r5}
	ldm	r0!,{r15}^
	ldm	r0!,{r1,r2,r15}^
	ldm	r0!,{r1-r3,r15}^
	ldm	r0!,{r1-r3,r15}^

	ldmda	r0,{r1}
	ldmda	r0,{r1,r2}
	ldmda	r0,{r1-r3}
	ldmda	r0,{r1-r3,r5}
	ldmda	r0,{r1}^
	ldmda	r0,{r1,r2}^
	ldmda	r0,{r1-r3}^
	ldmda	r0,{r1-r3,r5}^
	ldmda	r0!,{r1}
	ldmda	r0!,{r1,r2}
	ldmda	r0!,{r1-r3}
	ldmda	r0!,{r1-r3,r5}
	ldmda	r0!,{r15}^
	ldmda	r0!,{r1,r2,r15}^
	ldmda	r0!,{r1-r3,r15}^
	ldmda	r0!,{r1-r3,r15}^

	ldmdb	r0,{r1}
	ldmdb	r0,{r1,r2}
	ldmdb	r0,{r1-r3}
	ldmdb	r0,{r1-r3,r5}
	ldmdb	r0,{r1}^
	ldmdb	r0,{r1,r2}^
	ldmdb	r0,{r1-r3}^
	ldmdb	r0,{r1-r3,r5}^
	ldmdb	r0!,{r1}
	ldmdb	r0!,{r1,r2}
	ldmdb	r0!,{r1-r3}
	ldmdb	r0!,{r1-r3,r5}
	ldmdb	r0!,{r15}^
	ldmdb	r0!,{r1,r2,r15}^
	ldmdb	r0!,{r1-r3,r15}^
	ldmdb	r0!,{r1-r3,r15}^

	ldmea	r0,{r1}
	ldmea	r0,{r1,r2}
	ldmea	r0,{r1-r3}
	ldmea	r0,{r1-r3,r5}
	ldmea	r0,{r1}^
	ldmea	r0,{r1,r2}^
	ldmea	r0,{r1-r3}^
	ldmea	r0,{r1-r3,r5}^
	ldmea	r0!,{r1}
	ldmea	r0!,{r1,r2}
	ldmea	r0!,{r1-r3}
	ldmea	r0!,{r1-r3,r5}
	ldmea	r0!,{r15}^
	ldmea	r0!,{r1,r2,r15}^
	ldmea	r0!,{r1-r3,r15}^
	ldmea	r0!,{r1-r3,r15}^

	ldmed	r0,{r1}
	ldmed	r0,{r1,r2}
	ldmed	r0,{r1-r3}
	ldmed	r0,{r1-r3,r5}
	ldmed	r0,{r1}^
	ldmed	r0,{r1,r2}^
	ldmed	r0,{r1-r3}^
	ldmed	r0,{r1-r3,r5}^
	ldmed	r0!,{r1}
	ldmed	r0!,{r1,r2}
	ldmed	r0!,{r1-r3}
	ldmed	r0!,{r1-r3,r5}
	ldmed	r0!,{r15}^
	ldmed	r0!,{r1,r2,r15}^
	ldmed	r0!,{r1-r3,r15}^
	ldmed	r0!,{r1-r3,r15}^

	ldmfa	r0,{r1}
	ldmfa	r0,{r1,r2}
	ldmfa	r0,{r1-r3}
	ldmfa	r0,{r1-r3,r5}
	ldmfa	r0,{r1}^
	ldmfa	r0,{r1,r2}^
	ldmfa	r0,{r1-r3}^
	ldmfa	r0,{r1-r3,r5}^
	ldmfa	r0!,{r1}
	ldmfa	r0!,{r1,r2}
	ldmfa	r0!,{r1-r3}
	ldmfa	r0!,{r1-r3,r5}
	ldmfa	r0!,{r15}^
	ldmfa	r0!,{r1,r2,r15}^
	ldmfa	r0!,{r1-r3,r15}^
	ldmfa	r0!,{r1-r3,r15}^

	ldmfd	r0,{r1}
	ldmfd	r0,{r1,r2}
	ldmfd	r0,{r1-r3}
	ldmfd	r0,{r1-r3,r5}
	ldmfd	r0,{r1}^
	ldmfd	r0,{r1,r2}^
	ldmfd	r0,{r1-r3}^
	ldmfd	r0,{r1-r3,r5}^
	ldmfd	r0!,{r1}
	ldmfd	r0!,{r1,r2}
	ldmfd	r0!,{r1-r3}
	ldmfd	r0!,{r1-r3,r5}
	ldmfd	r0!,{r15}^
	ldmfd	r0!,{r1,r2,r15}^
	ldmfd	r0!,{r1-r3,r15}^
	ldmfd	r0!,{r1-r3,r15}^

	ldmia	r0,{r1}
	ldmia	r0,{r1,r2}
	ldmia	r0,{r1-r3}
	ldmia	r0,{r1-r3,r5}
	ldmia	r0,{r1}^
	ldmia	r0,{r1,r2}^
	ldmia	r0,{r1-r3}^
	ldmia	r0,{r1-r3,r5}^
	ldmia	r0!,{r1}
	ldmia	r0!,{r1,r2}
	ldmia	r0!,{r1-r3}
	ldmia	r0!,{r1-r3,r5}
	ldmia	r0!,{r15}^
	ldmia	r0!,{r1,r2,r15}^
	ldmia	r0!,{r1-r3,r15}^
	ldmia	r0!,{r1-r3,r15}^

	ldmib	r0,{r1}
	ldmib	r0,{r1,r2}
	ldmib	r0,{r1-r3}
	ldmib	r0,{r1-r3,r5}
	ldmib	r0,{r1}^
	ldmib	r0,{r1,r2}^
	ldmib	r0,{r1-r3}^
	ldmib	r0,{r1-r3,r5}^
	ldmib	r0!,{r1}
	ldmib	r0!,{r1,r2}
	ldmib	r0!,{r1-r3}
	ldmib	r0!,{r1-r3,r5}
	ldmib	r0!,{r15}^
	ldmib	r0!,{r1,r2,r15}^
	ldmib	r0!,{r1-r3,r15}^
	ldmib	r0!,{r1-r3,r15}^

	label_ldr:
	ldr	r0,[r1]
	ldr	r0,[r1],+r2
	ldr	r0,[r1],-r2
	ldr	r0,[r1],-r2,lsl 3
	ldr	r0,[r1],r2,lsr 3
	ldr	r0,[r1],r2,asr 3
	ldr	r0,[r1],r2,ror 3
	ldr	r0,[r1],-r2,lsl 3
	ldr	r0,[r1],-r2,lsr 3
	ldr	r0,[r1],-r2,asr 3
	ldr	r0,[r1],-r2,ror 3
	ldr	r0,[r1],r2,rrx
	ldr	r0,[r1],-r2,rrx
	ldr	r0,[r1],2
	ldr	r0,[r1,2]
	ldr	r0,[r1,2]!
	ldr	r0,[r1,r2]
	ldr	r0,[r1,-r2]
	ldr	r0,[r1,r2]!
	ldr	r0,[r1,-r2]!
	ldr	r0,[r1,r2,lsl 3]
	ldr	r0,[r1,r2,lsr 3]
	ldr	r0,[r1,r2,asr 3]
	ldr	r0,[r1,r2,ror 3]
	ldr	r0,[r1,-r2,lsl 3]
	ldr	r0,[r1,-r2,lsr 3]
	ldr	r0,[r1,-r2,asr 3]
	ldr	r0,[r1,-r2,ror 3]
	ldr	r0,[r1,r2,lsl 3]!
	ldr	r0,[r1,r2,lsr 3]!
	ldr	r0,[r1,r2,asr 3]!
	ldr	r0,[r1,r2,ror 3]!
	ldr	r0,[r1,-r2,lsl 3]!
	ldr	r0,[r1,-r2,lsr 3]!
	ldr	r0,[r1,-r2,asr 3]!
	ldr	r0,[r1,-r2,ror 3]!
	ldr	r0,[r1,r2,rrx]
	ldr	r0,[r1,-r2,rrx]
	ldr	r0,[r1,r2,rrx]!
	ldr	r0,[r1,-r2,rrx]!
	ldr	r0,[label_ldr]
	ldr	r0,[expression.word]
	ldr	r0,[expression.word]!

	label_ldrb:
	ldrb	r0,[r1]
	ldrb	r0,[r1],r2
	ldrb	r0,[r1],-r2
	ldrb	r0,[r1],-r2,lsl 3
	ldrb	r0,[r1],r2,lsr 3
	ldrb	r0,[r1],r2,asr 3
	ldrb	r0,[r1],r2,ror 3
	ldrb	r0,[r1],-r2,lsl 3
	ldrb	r0,[r1],-r2,lsr 3
	ldrb	r0,[r1],-r2,asr 3
	ldrb	r0,[r1],-r2,ror 3
	ldrb	r0,[r1],r2,rrx
	ldrb	r0,[r1],-r2,rrx
	ldrb	r0,[r1],2
	ldrb	r0,[r1,2]
	ldrb	r0,[r1,2]!
	ldrb	r0,[r1,r2]
	ldrb	r0,[r1,-r2]
	ldrb	r0,[r1,r2]!
	ldrb	r0,[r1,-r2]!
	ldrb	r0,[r1,r2,lsl 3]
	ldrb	r0,[r1,r2,lsr 3]
	ldrb	r0,[r1,r2,asr 3]
	ldrb	r0,[r1,r2,ror 3]
	ldrb	r0,[r1,-r2,lsl 3]
	ldrb	r0,[r1,-r2,lsr 3]
	ldrb	r0,[r1,-r2,asr 3]
	ldrb	r0,[r1,-r2,ror 3]
	ldrb	r0,[r1,r2,lsl 3]!
	ldrb	r0,[r1,r2,lsr 3]!
	ldrb	r0,[r1,r2,asr 3]!
	ldrb	r0,[r1,r2,ror 3]!
	ldrb	r0,[r1,-r2,lsl 3]!
	ldrb	r0,[r1,-r2,lsr 3]!
	ldrb	r0,[r1,-r2,asr 3]!
	ldrb	r0,[r1,-r2,ror 3]!
	ldrb	r0,[r1,r2,rrx]
	ldrb	r0,[r1,-r2,rrx]
	ldrb	r0,[r1,r2,rrx]!
	ldrb	r0,[r1,-r2,rrx]!
	ldrb	r0,[label_ldrb]
	ldrb	r0,[expression.byte]
	ldrb	r0,[expression.byte]!

	ldrbt	r0,[r1]
	ldrbt	r0,[r1],r2
	ldrbt	r0,[r1],-r2
	ldrbt	r0,[r1],r2,lsl 3
	ldrbt	r0,[r1],r2,lsr 3
	ldrbt	r0,[r1],r2,asr 3
	ldrbt	r0,[r1],r2,ror 3
	ldrbt	r0,[r1],-r2,lsl 3
	ldrbt	r0,[r1],-r2,lsr 3
	ldrbt	r0,[r1],-r2,asr 3
	ldrbt	r0,[r1],-r2,ror 3
	ldrbt	r0,[r1],r2,rrx
	ldrbt	r0,[r1],-r2,rrx
	ldrbt	r0,[r1],2

	ldrt	r0,[r1]
	ldrt	r0,[r1],r2
	ldrt	r0,[r1],-r2
	ldrt	r0,[r1],r2,lsl 3
	ldrt	r0,[r1],r2,lsr 3
	ldrt	r0,[r1],r2,asr 3
	ldrt	r0,[r1],r2,ror 3
	ldrt	r0,[r1],-r2,lsl 3
	ldrt	r0,[r1],-r2,lsr 3
	ldrt	r0,[r1],-r2,asr 3
	ldrt	r0,[r1],-r2,ror 3
	ldrt	r0,[r1],r2,rrx
	ldrt	r0,[r1],-r2,rrx
	ldrt	r0,[r1],2

	lsl	r0,1
	lsl	r0,r1
	lsl	r0,r1,2
	lsl	r0,r1,r2

	lsr	r0,1
	lsr	r0,r1
	lsr	r0,r1,2
	lsr	r0,r1,r2

	mov	r0,1
	mov	r0,1,2
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

	mvn	r0,1
	mvn	r0,1,2
	mvn	r0,r1
	mvn	r0,r1,rrx
	mvn	r0,r1,lsl 2
	mvn	r0,r1,lsr 2
	mvn	r0,r1,asr 2
	mvn	r0,r1,ror 2
	mvn	r0,r1,lsl r2
	mvn	r0,r1,lsr r2
	mvn	r0,r1,asr r2
	mvn	r0,r1,ror r2

	neg	r0
	neg	r0,r1

	nop

	orr	r0,1
	orr	r0,1,2
	orr	r0,r1
	orr	r0,r1,rrx
	orr	r0,r1,lsl 2
	orr	r0,r1,lsr 2
	orr	r0,r1,asr 2
	orr	r0,r1,ror 2
	orr	r0,r1,lsl r2
	orr	r0,r1,lsr r2
	orr	r0,r1,asr r2
	orr	r0,r1,ror r2
	orr	r0,r1,2
	orr	r0,r1,2,4
	orr	r0,r1,r2
	orr	r0,r1,r2,rrx
	orr	r0,r1,r2,lsl 3
	orr	r0,r1,r2,lsr 3
	orr	r0,r1,r2,asr 3
	orr	r0,r1,r2,ror 3
	orr	r0,r1,r2,lsl r3
	orr	r0,r1,r2,lsr r3
	orr	r0,r1,r2,asr r3
	orr	r0,r1,r2,ror r3

	pop	{r0}
	pop	{r0,r1}
	pop	{r0-r2}
	pop	{r0-r2,r4}

	push	{r0}
	push	{r0,r1}
	push	{r0-r2}
	push	{r0-r2,r4}

	ror	r0,1
	ror	r0,r1
	ror	r0,r1,2
	ror	r0,r1,r2

	rrx	r0
	rrx	r0,r1

	rsb	r0,1
	rsb	r0,1,2
	rsb	r0,r1
	rsb	r0,r1,rrx
	rsb	r0,r1,lsl 2
	rsb	r0,r1,lsr 2
	rsb	r0,r1,asr 2
	rsb	r0,r1,ror 2
	rsb	r0,r1,lsl r2
	rsb	r0,r1,lsr r2
	rsb	r0,r1,asr r2
	rsb	r0,r1,ror r2
	rsb	r0,r1,2
	rsb	r0,r1,2,4
	rsb	r0,r1,r2
	rsb	r0,r1,r2,rrx
	rsb	r0,r1,r2,lsl 3
	rsb	r0,r1,r2,lsr 3
	rsb	r0,r1,r2,asr 3
	rsb	r0,r1,r2,ror 3
	rsb	r0,r1,r2,lsl r3
	rsb	r0,r1,r2,lsr r3
	rsb	r0,r1,r2,asr r3
	rsb	r0,r1,r2,ror r3

	rsc	r0,1
	rsc	r0,1,2
	rsc	r0,r1
	rsc	r0,r1,rrx
	rsc	r0,r1,lsl 2
	rsc	r0,r1,lsr 2
	rsc	r0,r1,asr 2
	rsc	r0,r1,ror 2
	rsc	r0,r1,lsl r2
	rsc	r0,r1,lsr r2
	rsc	r0,r1,asr r2
	rsc	r0,r1,ror r2
	rsc	r0,r1,2
	rsc	r0,r1,2,4
	rsc	r0,r1,r2
	rsc	r0,r1,r2,rrx
	rsc	r0,r1,r2,lsl 3
	rsc	r0,r1,r2,lsr 3
	rsc	r0,r1,r2,asr 3
	rsc	r0,r1,r2,ror 3
	rsc	r0,r1,r2,lsl r3
	rsc	r0,r1,r2,lsr r3
	rsc	r0,r1,r2,asr r3
	rsc	r0,r1,r2,ror r3

	sbc	r0,1
	sbc	r0,1,2
	sbc	r0,r1
	sbc	r0,r1,rrx
	sbc	r0,r1,lsl 2
	sbc	r0,r1,lsr 2
	sbc	r0,r1,asr 2
	sbc	r0,r1,ror 2
	sbc	r0,r1,lsl r2
	sbc	r0,r1,lsr r2
	sbc	r0,r1,asr r2
	sbc	r0,r1,ror r2
	sbc	r0,r1,2
	sbc	r0,r1,2,4
	sbc	r0,r1,r2
	sbc	r0,r1,r2,rrx
	sbc	r0,r1,r2,lsl 3
	sbc	r0,r1,r2,lsr 3
	sbc	r0,r1,r2,asr 3
	sbc	r0,r1,r2,ror 3
	sbc	r0,r1,r2,lsl r3
	sbc	r0,r1,r2,lsr r3
	sbc	r0,r1,r2,asr r3
	sbc	r0,r1,r2,ror r3

	stm	r0,{r1}
	stm	r0,{r1,r2}
	stm	r0,{r1-r3}
	stm	r0,{r1-r3,r5}
	stm	r0,{r1}^
	stm	r0,{r1,r2}^
	stm	r0,{r1-r3}^
	stm	r0,{r1-r3,r5}^
	stm	r0!,{r1}
	stm	r0!,{r1,r2}
	stm	r0!,{r1-r3}
	stm	r0!,{r1-r3,r5}

	stmda	r0,{r1}
	stmda	r0,{r1,r2}
	stmda	r0,{r1-r3}
	stmda	r0,{r1-r3,r5}
	stmda	r0,{r1}^
	stmda	r0,{r1,r2}^
	stmda	r0,{r1-r3}^
	stmda	r0,{r1-r3,r5}^
	stmda	r0!,{r1}
	stmda	r0!,{r1,r2}
	stmda	r0!,{r1-r3}
	stmda	r0!,{r1-r3,r5}

	stmdb	r0,{r1}
	stmdb	r0,{r1,r2}
	stmdb	r0,{r1-r3}
	stmdb	r0,{r1-r3,r5}
	stmdb	r0,{r1}^
	stmdb	r0,{r1,r2}^
	stmdb	r0,{r1-r3}^
	stmdb	r0,{r1-r3,r5}^
	stmdb	r0!,{r1}
	stmdb	r0!,{r1,r2}
	stmdb	r0!,{r1-r3}
	stmdb	r0!,{r1-r3,r5}

	stmea	r0,{r1}
	stmea	r0,{r1,r2}
	stmea	r0,{r1-r3}
	stmea	r0,{r1-r3,r5}
	stmea	r0,{r1}^
	stmea	r0,{r1,r2}^
	stmea	r0,{r1-r3}^
	stmea	r0,{r1-r3,r5}^
	stmea	r0!,{r1}
	stmea	r0!,{r1,r2}
	stmea	r0!,{r1-r3}
	stmea	r0!,{r1-r3,r5}

	stmed	r0,{r1}
	stmed	r0,{r1,r2}
	stmed	r0,{r1-r3}
	stmed	r0,{r1-r3,r5}
	stmed	r0,{r1}^
	stmed	r0,{r1,r2}^
	stmed	r0,{r1-r3}^
	stmed	r0,{r1-r3,r5}^
	stmed	r0!,{r1}
	stmed	r0!,{r1,r2}
	stmed	r0!,{r1-r3}
	stmed	r0!,{r1-r3,r5}

	stmfa	r0,{r1}
	stmfa	r0,{r1,r2}
	stmfa	r0,{r1-r3}
	stmfa	r0,{r1-r3,r5}
	stmfa	r0,{r1}^
	stmfa	r0,{r1,r2}^
	stmfa	r0,{r1-r3}^
	stmfa	r0,{r1-r3,r5}^
	stmfa	r0!,{r1}
	stmfa	r0!,{r1,r2}
	stmfa	r0!,{r1-r3}
	stmfa	r0!,{r1-r3,r5}

	stmfd	r0,{r1}
	stmfd	r0,{r1,r2}
	stmfd	r0,{r1-r3}
	stmfd	r0,{r1-r3,r5}
	stmfd	r0,{r1}^
	stmfd	r0,{r1,r2}^
	stmfd	r0,{r1-r3}^
	stmfd	r0,{r1-r3,r5}^
	stmfd	r0!,{r1}
	stmfd	r0!,{r1,r2}
	stmfd	r0!,{r1-r3}
	stmfd	r0!,{r1-r3,r5}

	stmia	r0,{r1}
	stmia	r0,{r1,r2}
	stmia	r0,{r1-r3}
	stmia	r0,{r1-r3,r5}
	stmia	r0,{r1}^
	stmia	r0,{r1,r2}^
	stmia	r0,{r1-r3}^
	stmia	r0,{r1-r3,r5}^
	stmia	r0!,{r1}
	stmia	r0!,{r1,r2}
	stmia	r0!,{r1-r3}
	stmia	r0!,{r1-r3,r5}

	stmib	r0,{r1}
	stmib	r0,{r1,r2}
	stmib	r0,{r1-r3}
	stmib	r0,{r1-r3,r5}
	stmib	r0,{r1}^
	stmib	r0,{r1,r2}^
	stmib	r0,{r1-r3}^
	stmib	r0,{r1-r3,r5}^
	stmib	r0!,{r1}
	stmib	r0!,{r1,r2}
	stmib	r0!,{r1-r3}
	stmib	r0!,{r1-r3,r5}

	label_str:
	str	r0,[r1]
	str	r0,[r1],r2
	str	r0,[r1],-r2
	str	r0,[r1],-r2,lsl 3
	str	r0,[r1],r2,lsr 3
	str	r0,[r1],r2,asr 3
	str	r0,[r1],r2,ror 3
	str	r0,[r1],-r2,lsl 3
	str	r0,[r1],-r2,lsr 3
	str	r0,[r1],-r2,asr 3
	str	r0,[r1],-r2,ror 3
	str	r0,[r1],r2,rrx
	str	r0,[r1],-r2,rrx
	str	r0,[r1],2
	str	r0,[r1,2]
	str	r0,[r1,2]!
	str	r0,[r1,r2]
	str	r0,[r1,-r2]
	str	r0,[r1,r2]!
	str	r0,[r1,-r2]!
	str	r0,[r1,r2,lsl 3]
	str	r0,[r1,r2,lsr 3]
	str	r0,[r1,r2,asr 3]
	str	r0,[r1,r2,ror 3]
	str	r0,[r1,-r2,lsl 3]
	str	r0,[r1,-r2,lsr 3]
	str	r0,[r1,-r2,asr 3]
	str	r0,[r1,-r2,ror 3]
	str	r0,[r1,r2,lsl 3]!
	str	r0,[r1,r2,lsr 3]!
	str	r0,[r1,r2,asr 3]!
	str	r0,[r1,r2,ror 3]!
	str	r0,[r1,-r2,lsl 3]!
	str	r0,[r1,-r2,lsr 3]!
	str	r0,[r1,-r2,asr 3]!
	str	r0,[r1,-r2,ror 3]!
	str	r0,[r1,r2,rrx]
	str	r0,[r1,-r2,rrx]
	str	r0,[r1,r2,rrx]!
	str	r0,[r1,-r2,rrx]!
	str	r0,[label_str]
	str	r0,[expression.word]
	str	r0,[expression.word]!

	label_strb:
	strb	r0,[r1]
	strb	r0,[r1],r2
	strb	r0,[r1],-r2
	strb	r0,[r1],-r2,lsl 3
	strb	r0,[r1],r2,lsr 3
	strb	r0,[r1],r2,asr 3
	strb	r0,[r1],r2,ror 3
	strb	r0,[r1],-r2,lsl 3
	strb	r0,[r1],-r2,lsr 3
	strb	r0,[r1],-r2,asr 3
	strb	r0,[r1],-r2,ror 3
	strb	r0,[r1],r2,rrx
	strb	r0,[r1],-r2,rrx
	strb	r0,[r1],2
	strb	r0,[r1,2]
	strb	r0,[r1,2]!
	strb	r0,[r1,r2]
	strb	r0,[r1,-r2]
	strb	r0,[r1,r2]!
	strb	r0,[r1,-r2]!
	strb	r0,[r1,r2,lsl 3]
	strb	r0,[r1,r2,lsr 3]
	strb	r0,[r1,r2,asr 3]
	strb	r0,[r1,r2,ror 3]
	strb	r0,[r1,-r2,lsl 3]
	strb	r0,[r1,-r2,lsr 3]
	strb	r0,[r1,-r2,asr 3]
	strb	r0,[r1,-r2,ror 3]
	strb	r0,[r1,r2,lsl 3]!
	strb	r0,[r1,r2,lsr 3]!
	strb	r0,[r1,r2,asr 3]!
	strb	r0,[r1,r2,ror 3]!
	strb	r0,[r1,-r2,lsl 3]!
	strb	r0,[r1,-r2,lsr 3]!
	strb	r0,[r1,-r2,asr 3]!
	strb	r0,[r1,-r2,ror 3]!
	strb	r0,[r1,r2,rrx]
	strb	r0,[r1,-r2,rrx]
	strb	r0,[r1,r2,rrx]!
	strb	r0,[r1,-r2,rrx]!
	strb	r0,[label_strb]
	strb	r0,[expression.byte]
	strb	r0,[expression.byte]!

	strbt	r0,[r1]
	strbt	r0,[r1],r2
	strbt	r0,[r1],-r2
	strbt	r0,[r1],r2,lsl 3
	strbt	r0,[r1],r2,lsr 3
	strbt	r0,[r1],r2,asr 3
	strbt	r0,[r1],r2,ror 3
	strbt	r0,[r1],-r2,lsl 3
	strbt	r0,[r1],-r2,lsr 3
	strbt	r0,[r1],-r2,asr 3
	strbt	r0,[r1],-r2,ror 3
	strbt	r0,[r1],r2,rrx
	strbt	r0,[r1],-r2,rrx
	strbt	r0,[r1],2

	strt	r0,[r1]
	strt	r0,[r1],r2
	strt	r0,[r1],-r2
	strt	r0,[r1],r2,lsl 3
	strt	r0,[r1],r2,lsr 3
	strt	r0,[r1],r2,asr 3
	strt	r0,[r1],r2,ror 3
	strt	r0,[r1],-r2,lsl 3
	strt	r0,[r1],-r2,lsr 3
	strt	r0,[r1],-r2,asr 3
	strt	r0,[r1],-r2,ror 3
	strt	r0,[r1],r2,rrx
	strt	r0,[r1],-r2,rrx
	strt	r0,[r1],2

	sub	r0,1
	sub	r0,1,2
	sub	r0,r1
	sub	r0,r1,rrx
	sub	r0,r1,lsl 2
	sub	r0,r1,lsr 2
	sub	r0,r1,asr 2
	sub	r0,r1,ror 2
	sub	r0,r1,lsl r2
	sub	r0,r1,lsr r2
	sub	r0,r1,asr r2
	sub	r0,r1,ror r2
	sub	r0,r1,2
	sub	r0,r1,2,4
	sub	r0,r1,r2
	sub	r0,r1,r2,rrx
	sub	r0,r1,r2,lsl 3
	sub	r0,r1,r2,lsr 3
	sub	r0,r1,r2,asr 3
	sub	r0,r1,r2,ror 3
	sub	r0,r1,r2,lsl r3
	sub	r0,r1,r2,lsr r3
	sub	r0,r1,r2,asr r3
	sub	r0,r1,r2,ror r3

	subw	r0,1
	subw	r0,r1,2

	svc	1

	swi	1

	teq	r0,1
	teq	r0,1,2
	teq	r0,r1
	teq	r0,r1,rrx
	teq	r0,r1,lsl 2
	teq	r0,r1,lsr 2
	teq	r0,r1,asr 2
	teq	r0,r1,ror 2
	teq	r0,r1,lsl r2
	teq	r0,r1,lsr r2
	teq	r0,r1,asr r2
	teq	r0,r1,ror r2

	tst	r0,1
	tst	r0,1,2
	tst	r0,r1
	tst	r0,r1,rrx
	tst	r0,r1,lsl 2
	tst	r0,r1,lsr 2
	tst	r0,r1,asr 2
	tst	r0,r1,ror 2
	tst	r0,r1,lsl r2
	tst	r0,r1,lsr r2
	tst	r0,r1,asr r2
	tst	r0,r1,ror r2

processor CPU32_V2

	cdp	p9,1,c2,c3,c4
	cdp	p9,1,c2,c3,c4,5

	label_ldc:
	ldc	p9,c1,[r2]
	ldc	p9,c1,[r2],4
	ldc	p9,c1,[r2],{4}
	ldc	p9,c1,[r2,4]
	ldc	p9,c1,[r2,4]!
	ldc	p9,c1,[label_ldc]
	ldc	p9,c1,[expression.word]
	ldc	p9,c1,[expression.word]!

	label_ldcl:
	ldcl	p9,c1,[r2]
	ldcl	p9,c1,[r2],4
	ldcl	p9,c1,[r2],{4}
	ldcl	p9,c1,[r2,4]
	ldcl	p9,c1,[r2,4]!
	ldcl	p9,c1,[label_ldcl]
	ldcl	p9,c1,[expression.word]
	ldcl	p9,c1,[expression.word]!

	mcr	p9,1,r2,c3,c4
	mcr	p9,1,r2,c3,c4,5

	mla	r0,r1,r2,r3

	mrc	p9,1,r2,c3,c4
	mrc	p9,1,r15,c3,c4,5

	mul	r0,r1
	mul	r0,r1,r2

	label_stc:
	stc	p9,c1,[r2]
	stc	p9,c1,[r2],4
	stc	p9,c1,[r2],{4}
	stc	p9,c1,[r2,4]
	stc	p9,c1,[r2,4]!
	stc	p9,c1,[label_stc]
	stc	p9,c1,[expression.word]
	stc	p9,c1,[expression.word]!

	label_stcl:
	stcl	p9,c1,[r2]
	stcl	p9,c1,[r2],4
	stcl	p9,c1,[r2],{4}
	stcl	p9,c1,[r2,4]
	stcl	p9,c1,[r2,4]!
	stcl	p9,c1,[label_stcl]
	stcl	p9,c1,[expression.word]
	stcl	p9,c1,[expression.word]!

processor CPU32_A

	swp	r0,r1,[r2]
	swpb	r0,r1,[r2]

processor CPU32_V3

	mrs	r0,apsr
	mrs	r0,cpsr
	mrs	r0,spsr

	msr	cpsr,r1
	msr	cpsr_fsxc,r1
	msr	cpsr,1
	msr	cpsr_fsxc,1

processor CPU32_M

	smlal	r0,r1,r2,r3

	smull	r0,r1,r2,r3

	umlal	r0,r1,r2,r3

	umull	r0,r1,r2,r3

processor CPU32_V4

	label_ldrh:
	ldrh	r0,[r1]
	ldrh	r0,[r1],r2
	ldrh	r0,[r1],-r2
	ldrh	r0,[r1],2
	ldrh	r0,[r1,2]
	ldrh	r0,[r1,2]!
	ldrh	r0,[r1,r2]
	ldrh	r0,[r1,-r2]
	ldrh	r0,[r1,r2]!
	ldrh	r0,[r1,-r2]!
	ldrh	r0,[label_ldrh]
	ldrh	r0,[expression.hword]
	ldrh	r0,[expression.hword]!

	label_ldrsb:
	ldrsb	r0,[r1]
	ldrsb	r0,[r1],r2
	ldrsb	r0,[r1],-r2
	ldrsb	r0,[r1],2
	ldrsb	r0,[r1,2]
	ldrsb	r0,[r1,2]!
	ldrsb	r0,[r1,r2]
	ldrsb	r0,[r1,-r2]
	ldrsb	r0,[r1,r2]!
	ldrsb	r0,[r1,-r2]!
	ldrsb	r0,[label_ldrsb]
	ldrsb	r0,[expression.byte]
	ldrsb	r0,[expression.byte]!

	label_ldrsh:
	ldrsh	r0,[r1]
	ldrsh	r0,[r1],r2
	ldrsh	r0,[r1],-r2
	ldrsh	r0,[r1],2
	ldrsh	r0,[r1,2]
	ldrsh	r0,[r1,2]!
	ldrsh	r0,[r1,r2]
	ldrsh	r0,[r1,-r2]
	ldrsh	r0,[r1,r2]!
	ldrsh	r0,[r1,-r2]!
	ldrsh	r0,[label_ldrsh]
	ldrsh	r0,[expression.hword]
	ldrsh	r0,[expression.hword]!

	label_strh:
	strh	r0,[r1]
	strh	r0,[r1],r2
	strh	r0,[r1],-r2
	strh	r0,[r1],2
	strh	r0,[r1,2]
	strh	r0,[r1,2]!
	strh	r0,[r1,r2]
	strh	r0,[r1,-r2]
	strh	r0,[r1,r2]!
	strh	r0,[r1,-r2]!
	strh	r0,[label_strh]
	strh	r0,[expression.hword]
	strh	r0,[expression.hword]!

processor CPU32_V4T

	bx	r0

processor CPU32_V5

	label_blx:
	blx	label_blx
	blx	r0

	bkpt	0

	cdp2	p9,1,c2,c3,c4
	cdp2	p9,1,c2,c3,c4,5

	clz	r0,r1

	label_ldc2:
	ldc2	p9,c1,[r2]
	ldc2	p9,c1,[r2],4
	ldc2	p9,c1,[r2],{4}
	ldc2	p9,c1,[r2,4]
	ldc2	p9,c1,[r2,4]!
	ldc2	p9,c1,[label_ldc2]
	ldc2	p9,c1,[expression.word]
	ldc2	p9,c1,[expression.word]!

	label_ldc2l:
	ldc2l	p9,c1,[r2]
	ldc2l	p9,c1,[r2],4
	ldc2l	p9,c1,[r2],{4}
	ldc2l	p9,c1,[r2,4]
	ldc2l	p9,c1,[r2,4]!
	ldc2l	p9,c1,[label_ldc2l]
	ldc2l	p9,c1,[expression.word]
	ldc2l	p9,c1,[expression.word]!

	mcr2	p9,1,r2,c3,c4
	mcr2	p9,1,r2,c3,c4,5

	mrc2	p9,1,r2,c3,c4
	mrc2	p9,1,r15,c3,c4,5

	label_stc2:
	stc2	p9,c1,[r2]
	stc2	p9,c1,[r2],4
	stc2	p9,c1,[r2],{4}
	stc2	p9,c1,[r2,4]
	stc2	p9,c1,[r2,4]!
	stc2	p9,c1,[label_stc2]
	stc2	p9,c1,[expression.word]
	stc2	p9,c1,[expression.word]!

	label_stc2l:
	stc2l	p9,c1,[r2]
	stc2l	p9,c1,[r2],4
	stc2l	p9,c1,[r2],{4}
	stc2l	p9,c1,[r2,4]
	stc2l	p9,c1,[r2,4]!
	stc2l	p9,c1,[label_stc2l]
	stc2l	p9,c1,[expression.word]
	stc2l	p9,c1,[expression.word]!

processor CPU32_E

	qadd	r0,r1
	qadd	r0,r1,r2

	qdadd	r0,r1
	qdadd	r0,r1,r2

	qdsub	r0,r1
	qdsub	r0,r1,r2

	qsub	r0,r1
	qsub	r0,r1,r2

	smlabb	r0,r1,r2,r3

	smlabt	r0,r1,r2,r3

	smlalbb	r0,r1,r2,r3

	smlalbt	r0,r1,r2,r3

	smlaltb	r0,r1,r2,r3

	smlaltt	r0,r1,r2,r3

	smlatb	r0,r1,r2,r3

	smlatt	r0,r1,r2,r3

	smlawb	r0,r1,r2,r3

	smlawt	r0,r1,r2,r3

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

processor CPU32_P

	label_ldrd:
	ldrd	r0,[r2]
	ldrd	r0,[r2],r3
	ldrd	r0,[r2],-r3
	ldrd	r0,[r2],3
	ldrd	r0,[r2,3]
	ldrd	r0,[r2,3]!
	ldrd	r0,[r2,r3]
	ldrd	r0,[r2,-r3]
	ldrd	r0,[r2,r3]!
	ldrd	r0,[r2,-r3]!
	ldrd	r0,[label_ldrd]
	ldrd	r0,[expression.dword]
	ldrd	r0,[expression.dword]!
	ldrd	r0,r1,[r2]
	ldrd	r0,r1,[r2],r3
	ldrd	r0,r1,[r2],-r3
	ldrd	r0,r1,[r2],3
	ldrd	r0,r1,[r2,3]
	ldrd	r0,r1,[r2,3]!
	ldrd	r0,r1,[r2,r3]
	ldrd	r0,r1,[r2,-r3]
	ldrd	r0,r1,[r2,r3]!
	ldrd	r0,r1,[r2,-r3]!
	ldrd	r0,r1,[label_ldrd]
	ldrd	r0,r1,[expression.dword]
	ldrd	r0,r1,[expression.dword]!

	mcrr	p9,1,r2,r3,c4

	mrrc	p9,1,r2,r3,c4

	label_pld:
	pld	[r0]
	pld	[r0,1]
	pld	[r0,r1]
	pld	[r0,-r1]
	pld	[r0,r1,lsl 2]
	pld	[r0,r1,lsr 2]
	pld	[r0,r1,asr 2]
	pld	[r0,r1,ror 2]
	pld	[r0,-r1,lsl 2]
	pld	[r0,-r1,lsr 2]
	pld	[r0,-r1,asr 2]
	pld	[r0,-r1,ror 2]
	pld	[r0,r1,rrx]
	pld	[r0,-r1,rrx]
	pld	[label_pld]
	pld	[expression.byte]

	label_strd:
	strd	r0,[r2]
	strd	r0,[r2],r3
	strd	r0,[r2],-r3
	strd	r0,[r2],3
	strd	r0,[r2,3]
	strd	r0,[r2,3]!
	strd	r0,[r2,r3]
	strd	r0,[r2,-r3]
	strd	r0,[r2,r3]!
	strd	r0,[r2,-r3]!
	strd	r0,[label_strd]
	strd	r0,[expression.dword]
	strd	r0,[expression.dword]!
	strd	r0,r1,[r2]
	strd	r0,r1,[r2],r3
	strd	r0,r1,[r2],-r3
	strd	r0,r1,[r2],3
	strd	r0,r1,[r2,3]
	strd	r0,r1,[r2,3]!
	strd	r0,r1,[r2,r3]
	strd	r0,r1,[r2,-r3]
	strd	r0,r1,[r2,r3]!
	strd	r0,r1,[r2,-r3]!
	strd	r0,r1,[label_strd]
	strd	r0,r1,[expression.dword]
	strd	r0,r1,[expression.dword]!

processor CPU32_J

	bxj	r0

processor CPU32_V6

	cps	0

	cpsid	iflags_a
	cpsid	iflags_a,1

	cpsie	iflags_a
	cpsie	iflags_a,1

	ldrex	r0,[r1]
	ldrex	r0,[r1,0]

	mcrr2	p9,1,r2,r3,c4

	mrrc2	p9,1,r2,r3,c4

	pkhbt	r0,r1
	pkhbt	r0,r1,lsl 3
	pkhbt	r0,r1,r2
	pkhbt	r0,r1,r2,lsl 3

	pkhtb	r0,r1
	pkhtb	r0,r1,asr 3
	pkhtb	r0,r1,r2
	pkhtb	r0,r1,r2,asr 3

	qadd16	r0,r1
	qadd16	r0,r1,r2

	qadd8	r0,r1
	qadd8	r0,r1,r2

	qaddsubx	r0,r1
	qaddsubx	r0,r1,r2

	qasx	r0,r1
	qasx	r0,r1,r2

	qsax	r0,r1
	qsax	r0,r1,r2

	qsub16	r0,r1
	qsub16	r0,r1,r2

	qsub8	r0,r1
	qsub8	r0,r1,r2

	qsubaddx	r0,r1
	qsubaddx	r0,r1,r2

	rev	r0,r1

	rev16	r0,r1

	revsh	r0,r1

	rfe	r0
	rfe	r0!

	rfeda	r0
	rfeda	r0!

	rfedb	r0
	rfedb	r0!

	rfeea	r0
	rfeea	r0!

	rfeed	r0
	rfeed	r0!

	rfefa	r0
	rfefa	r0!

	rfefd	r0
	rfefd	r0!

	rfeia	r0
	rfeia	r0!

	rfeib	r0
	rfeib	r0!

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

	setend	le

	ssax	r0,r1
	ssax	r0,r1,r2

	ssub16	r0,r1
	ssub16	r0,r1,r2

	ssub8	r0,r1
	ssub8	r0,r1,r2

	ssubaddx	r0,r1
	ssubaddx	r0,r1,r2

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

	smlald	r0,r1,r2,r3

	smlaldx	r0,r1,r2,r3

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

	smusd	r0,r1
	smusd	r0,r1,r2

	smusdx	r0,r1
	smusdx	r0,r1,r2

	srs	0
	srs	0 !
	srs	sp,0
	srs	sp!,0

	srsda	0
	srsda	0 !
	srsda	sp,0
	srsda	sp!,0

	srsdb	0
	srsdb	0 !
	srsdb	sp,0
	srsdb	sp!,0

	srsea	0
	srsea	0 !
	srsea	sp,0
	srsea	sp!,0

	srsed	0
	srsed	0 !
	srsed	sp,0
	srsed	sp!,0

	srsfa	0
	srsfa	0 !
	srsfa	sp,0
	srsfa	sp!,0

	srsfd	0
	srsfd	0 !
	srsfd	sp,0
	srsfd	sp!,0

	srsia	0
	srsia	0 !
	srsia	sp,0
	srsia	sp!,0

	srsib	0
	srsib	0 !
	srsib	sp,0
	srsib	sp!,0

	ssat	r0,1,r2
	ssat	r0,1,r2,lsl 3
	ssat	r0,1,r2,asr 3

	ssat16	r0,1,r2

	strex	r0,r1,[r1]
	strex	r0,r1,[r1,0]

	sxtab	r0,r1,r2
	sxtab	r0,r1,r2,ror 8

	sxtab16	r0,r1,r2
	sxtab16	r0,r1,r2,ror 8

	sxtah	r0,r1,r2
	sxtah	r0,r1,r2,ror 8

	sxtb	r0,r1
	sxtb	r0,r1,ror 8

	sxtb16	r0,r1
	sxtb16	r0,r1,ror 8

	sxth	r0,r1
	sxth	r0,r1,ror 8

	uadd16	r0,r1
	uadd16	r0,r1,r2

	uadd8	r0,r1
	uadd8	r0,r1,r2

	uaddsubx	r0,r1
	uaddsubx	r0,r1,r2

	uasx	r0,r1
	uasx	r0,r1,r2

	usax	r0,r1
	usax	r0,r1,r2

	usub16	r0,r1
	usub16	r0,r1,r2

	usub8	r0,r1
	usub8	r0,r1,r2

	usubaddx	r0,r1
	usubaddx	r0,r1,r2

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

	uxtab	r0,r1,r2
	uxtab	r0,r1,r2,ror 8

	uxtab16	r0,r1,r2
	uxtab16	r0,r1,r2,ror 8

	uxtah	r0,r1,r2
	uxtah	r0,r1,r2,ror 8

	uxtb	r0,r1
	uxtb	r0,r1,ror 8

	uxtb16	r0,r1
	uxtb16	r0,r1,ror 8

	uxth	r0,r1
	uxth	r0,r1,ror 8

processor CPU32_K

	clrex

	ldrexb	r0,[r1]
	ldrexb	r0,[r1,0]

	ldrexd	r0,[r1]
	ldrexd	r0,r1,[r2]

	ldrexh	r0,[r1]
	ldrexh	r0,[r1,0]

	strexb	r0,r1,[r2]
	strexb	r0,r1,[r2,0]

	strexd	r0,r2,[r4]
	strexd	r0,r2,r3,[r4]

	strexh	r0,r1,[r2]
	strexh	r0,r1,[r2,0]

	sev

	wfe

	wfi

	yield

processor CPU32_Z

	smc	0

	smi	0

processor CPU32_T2

	bfc	r0,1,2

	bfi	r0,r1,2,3

	mls	r0,r1,r2,r3

	rbit	r0,r1

	ldrht	r0,[r1]
	ldrht	r0,[r1],r2
	ldrht	r0,[r1],-r2
	ldrht	r0,[r1],2

	ldrsbt	r0,[r1]
	ldrsbt	r0,[r1],-r2
	ldrsbt	r0,[r1],r2
	ldrsbt	r0,[r1],2

	ldrsht	r0,[r1]
	ldrsht	r0,[r1],r2
	ldrsht	r0,[r1],-r2
	ldrsht	r0,[r1],2

	movt	r0,1

	movw	r0,1

	sbfx	r0,r1,2,3

	strht	r0,[r1]
	strht	r0,[r1],r2
	strht	r0,[r1],-r2
	strht	r0,[r1],2

	ubfx	r0,r1,2,3

processor CPU32_V7

	dbg	0

	dmb
	dmb	sy

	dsb
	dsb	sy

	isb
	isb	sy

	label_pli:
	pli	[r0]
	pli	[r0,1]
	pli	[r0,r1]
	pli	[r0,-r1]
	pli	[r0,r1,lsl 2]
	pli	[r0,r1,lsr 2]
	pli	[r0,r1,asr 2]
	pli	[r0,r1,ror 2]
	pli	[r0,-r1,lsl 2]
	pli	[r0,-r1,lsr 2]
	pli	[r0,-r1,asr 2]
	pli	[r0,-r1,ror 2]
	pli	[r0,r1,rrx]
	pli	[r0,-r1,rrx]
	pli	[label_pli]
	pli	[expression.byte]

processor CPU32_MP

	label_pldw:
	pldw	[r0]
	pldw	[r0,1]
	pldw	[r0,r1]
	pldw	[r0,-r1]
	pldw	[r0,r1,lsl 2]
	pldw	[r0,r1,lsr 2]
	pldw	[r0,r1,asr 2]
	pldw	[r0,r1,ror 2]
	pldw	[r0,-r1,lsl 2]
	pldw	[r0,-r1,lsr 2]
	pldw	[r0,-r1,asr 2]
	pldw	[r0,-r1,ror 2]
	pldw	[r0,r1,rrx]
	pldw	[r0,-r1,rrx]
	pldw	[label_pldw]
	pldw	[expression.byte]

processor CPU32_VE

	eret

	hvc	0

	msr	lr_fiq,r0

	mrs	r0,lr_fiq

	sdiv	r0,r1
	sdiv	r0,r1,r2

	udiv	r0,r1
	udiv	r0,r1,r2

processor CPU32_V8

	hlt	0

	lda	r0,[r1]
	ldab	r0,[r1]
	ldah	r0,[r1]

	ldaex	r0,[r1]
	ldaexb	r0,[r1]
	ldaexh	r0,[r1]
	ldaexd	r0,[r2]
	ldaexd	r0,r1,[r2]

	sevl
	
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

processor 0	;In ARM mode, UND is always encodable, it ignores the processor directive

	und
	und	0
