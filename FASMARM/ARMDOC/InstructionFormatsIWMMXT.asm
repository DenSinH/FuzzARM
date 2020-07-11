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
;Almost all instructions can be conditional. The
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
	;IWMMXT, ARM mode, all instructions are 32-bit
	;***********************************************

	code32

coprocessor COPRO_IWMMXT_V1

	tandcb	r15

	tandch	r15

	tandcw	r15

	tbcstb	wr0,r1

	tbcsth	wr0,r1

	tbcstw	wr0,r1

	textrcb	r15,4

	textrch	r15,2

	textrcw	r15,1

	textrmsb	r0,wr1,2

	textrmsh	r0,wr1,2

	textrmsw	r0,wr1,2

	textrmub	r0,wr1,2

	textrmuh	r0,wr1,2

	textrmuw	r0,wr1,2

	tinsrb	wr0,r1,2

	tinsrh	wr0,r1,2

	tinsrw	wr0,r1,2

	tmcr	wcgr0,r1

	tmcrr	wr0,r1,r2

	tmia	wr0,r1,r2

	tmiabb	wr0,r1,r2

	tmiabt	wr0,r1,r2

	tmiaph	wr0,r1,r2

	tmiatb	wr0,r1,r2

	tmiatt	wr0,r1,r2

	tmovmskb	r0,wr1

	tmovmskh	r0,wr1

	tmovmskw	r0,wr1

	tmrc	r0,wcgr1

	tmrrc	r0,r1,wr2

	torcb	r15

	torch	r15

	torcw	r15

	waccb	wr0,wr1

	wacch	wr0,wr1

	waccw	wr0,wr1

	waddb	wr0,wr1,wr2

	waddbss	wr0,wr1,wr2

	waddbus	wr0,wr1,wr2

	waddh	wr0,wr1,wr2

	waddhss	wr0,wr1,wr2

	waddhus	wr0,wr1,wr2

	waddw	wr0,wr1,wr2

	waddwss	wr0,wr1,wr2

	waddwus	wr0,wr1,wr2

	waligni	wr0,wr1,wr2,3

	walignr0	wr1,wr1,wr2

	walignr1	wr1,wr1,wr2

	walignr2	wr1,wr1,wr2

	walignr3	wr1,wr1,wr2

	wand	wr0,wr1,wr2

	wandn	wr0,wr1,wr2

	wavg2b	wr0,wr1,wr2

	wavg2br	wr0,wr1,wr2

	wavg2h	wr0,wr1,wr2

	wavg2hr	wr0,wr1,wr2

	wcmpeqb	wr0,wr1,wr2

	wcmpeqh	wr0,wr1,wr2

	wcmpeqw	wr0,wr1,wr2

	wcmpgtsb	wr1,wr1,wr2

	wcmpgtsh	wr1,wr1,wr2

	wcmpgtsw	wr1,wr1,wr2

	wcmpgtub	wr1,wr1,wr2

	wcmpgtuh	wr1,wr1,wr2

	wcmpgtuw	wr1,wr1,wr2

	label_wldrb:
	wldrb	wr0,[r1]
	wldrb	wr0,[r1],4
	wldrb	wr0,[r1],{4}
	wldrb	wr0,[r1,4]
	wldrb	wr0,[r1,4]!
	wldrb	wr0,[label_wldrb]
	wldrb	wr0,[expression.byte]
	wldrb	wr0,[expression.byte]!

	label_wldrd:
	wldrd	wr0,[r1]
	wldrd	wr0,[r1],4
	wldrd	wr0,[r1],{4}
	wldrd	wr0,[r1,4]
	wldrd	wr0,[r1,4]!
	wldrd	wr0,[label_wldrd]
	wldrd	wr0,[expression.dword]
	wldrd	wr0,[expression.dword]!

	label_wldrh:
	wldrh	wr0,[r1]
	wldrh	wr0,[r1],4
	wldrh	wr0,[r1],{4}
	wldrh	wr0,[r1,4]
	wldrh	wr0,[r1,4]!
	wldrh	wr0,[label_wldrh]
	wldrh	wr0,[expression.hword]
	wldrh	wr0,[expression.hword]!

	label_wldrw:
	wldrw	wr0,[r1]
	wldrw	wr0,[r1],4
	wldrw	wr0,[r1],{4}
	wldrw	wr0,[r1,4]
	wldrw	wr0,[r1,4]!
	wldrw	wr0,[label_wldrw]
	wldrw	wr0,[expression.word]
	wldrw	wr0,[expression.word]!
	wldrw	wcgr0,[r1]
	wldrw	wcgr0,[r1],4
	wldrw	wcgr0,[r1],{4}
	wldrw	wcgr0,[r1,4]
	wldrw	wcgr0,[r1,4]!
	wldrw	wcgr0,[label_wldrw]
	wldrw	wcgr0,[expression.word]
	wldrw	wcgr0,[expression.word]!

	wmacs	wr0,wr1,wr2

	wmacsz	wr0,wr1,wr2

	wmacu	wr0,wr1,wr2

	wmacuz	wr0,wr1,wr2

	wmadds	wr0,wr1,wr2

	wmaddu	wr0,wr1,wr2

	wmaxsb	wr0,wr1,wr2

	wmaxsh	wr0,wr1,wr2

	wmaxsw	wr0,wr1,wr2

	wmaxub	wr0,wr1,wr2

	wmaxuh	wr0,wr1,wr2

	wmaxuw	wr0,wr1,wr2

	wminsb	wr0,wr1,wr2

	wminsh	wr0,wr1,wr2

	wminsw	wr0,wr1,wr2

	wminub	wr0,wr1,wr2

	wminuh	wr0,wr1,wr2

	wminuw	wr0,wr1,wr2

	wmov	wr0,wr1

	wmulsl	wr0,wr1,wr2

	wmulsm	wr0,wr1,wr2

	wmulul	wr0,wr1,wr2

	wmulum	wr0,wr1,wr2

	wor	wr0,wr1,wr2

	wpackdss	wr1,wr1,wr2

	wpackdus	wr1,wr1,wr2

	wpackhss	wr1,wr1,wr2

	wpackhus	wr1,wr1,wr2

	wpackwss	wr1,wr1,wr2

	wpackwus	wr1,wr1,wr2

	wrord	wr0,wr1,wr2

	wrordg	wr0,wr1,wcgr2

	wrorh	wr0,wr1,wr2

	wrorhg	wr0,wr1,wcgr2

	wrorw	wr0,wr1,wr2

	wrorwg	wr0,wr1,wcgr2

	wsadb	wr0,wr1,wr2

	wsadbz	wr0,wr1,wr2

	wsadh	wr0,wr1,wr2

	wsadhz	wr0,wr1,wr2

	wshufh	wr0,wr1,2

	wshufh	wr0,wr1,2

	wslld	wr0,wr1,wr2

	wslldg	wr0,wr1,wcgr2

	wsllh	wr0,wr1,wr2

	wsllhg	wr0,wr1,wcgr2

	wsllw	wr0,wr1,wr2

	wsllwg	wr0,wr1,wcgr2

	wsrad	wr0,wr1,wr2

	wsradg	wr0,wr1,wcgr2

	wsrah	wr0,wr1,wr2

	wsrahg	wr0,wr1,wcgr2

	wsraw	wr0,wr1,wr2

	wsrawg	wr0,wr1,wcgr2

	wsrld	wr0,wr1,wr2

	wsrldg	wr0,wr1,wcgr2

	wsrlh	wr0,wr1,wr2

	wsrlhg	wr0,wr1,wcgr2

	wsrlw	wr0,wr1,wr2

	wsrlwg	wr0,wr1,wcgr2

	label_wstrb:
	wstrb	wr0,[r1]
	wstrb	wr0,[r1],4
	wstrb	wr0,[r1],{4}
	wstrb	wr0,[r1,4]
	wstrb	wr0,[r1,4]!
	wstrb	wr0,[label_wstrb]
	wstrb	wr0,[expression.byte]
	wstrb	wr0,[expression.byte]!

	label_wstrd:
	wstrd	wr0,[r1]
	wstrd	wr0,[r1],4
	wstrd	wr0,[r1],{4}
	wstrd	wr0,[r1,4]
	wstrd	wr0,[r1,4]!
	wstrd	wr0,[label_wstrd]
	wstrd	wr0,[expression.dword]
	wstrd	wr0,[expression.dword]!

	label_wstrh:
	wstrh	wr0,[r1]
	wstrh	wr0,[r1],4
	wstrh	wr0,[r1],{4}
	wstrh	wr0,[r1,4]
	wstrh	wr0,[r1,4]!
	wstrh	wr0,[label_wstrh]
	wstrh	wr0,[expression.hword]
	wstrh	wr0,[expression.hword]!

	label_wstrw:
	wstrw	wr0,[r1]
	wstrw	wr0,[r1],4
	wstrw	wr0,[r1],{4}
	wstrw	wr0,[r1,4]
	wstrw	wr0,[r1,4]!
	wstrw	wr0,[label_wstrw]
	wstrw	wr0,[expression.word]
	wstrw	wr0,[expression.word]!
	wstrw	wcgr0,[r1]
	wstrw	wcgr0,[r1],4
	wstrw	wcgr0,[r1],{4}
	wstrw	wcgr0,[r1,4]
	wstrw	wcgr0,[r1,4]!
	wstrw	wcgr0,[label_wstrw]
	wstrw	wcgr0,[expression.word]
	wstrw	wcgr0,[expression.word]!

	wsubb	wr0,wr1,wr2

	wsubbss	wr0,wr1,wr2

	wsubbus	wr0,wr1,wr2

	wsubh	wr0,wr1,wr2

	wsubhss	wr0,wr1,wr2

	wsubhus	wr0,wr1,wr2

	wsubw	wr0,wr1,wr2

	wsubwss	wr0,wr1,wr2

	wsubwus	wr0,wr1,wr2

	wunpckehsb	wr0,wr1

	wunpckehsh	wr0,wr1

	wunpckehsw	wr0,wr1

	wunpckehub	wr0,wr1

	wunpckehuh	wr0,wr1

	wunpckehuw	wr0,wr1

	wunpckelsb	wr0,wr1

	wunpckelsh	wr0,wr1

	wunpckelsw	wr0,wr1

	wunpckelub	wr0,wr1

	wunpckeluh	wr0,wr1

	wunpckeluw	wr0,wr1

	wunpckihb	wr0,wr1,wr2

	wunpckihh	wr0,wr1,wr2

	wunpckihw	wr0,wr1,wr2

	wunpckilb	wr0,wr1,wr2

	wunpckilh	wr0,wr1,wr2

	wunpckilw	wr0,wr1,wr2

	wxor	wr0,wr1,wr2

	wzero	wr0

coprocessor COPRO_IWMMXT_V2
	torvscb	r15

	torvsch	r15

	torvscw	r15

	wabsb	wr0,wr1

	wabsdiffb	wr0,wr1,wr2

	wabsdiffh	wr0,wr1,wr2

	wabsdiffw	wr0,wr1,wr2

	wabsh	wr0,wr1

	wabsw	wr0,wr1

	waddhc	wr0,wr1,wr2

	waddsubhx	wr0,wr1,wr2

	waddwc	wr0,wr1,wr2

	wavg4	wr0,wr1,wr2

	wavg4r	wr0,wr1,wr2

	wldrd	wr0,[r1],r2
	wldrd	wr0,[r1],-r2
	wldrd	wr0,[r1],r2,lsl 2
	wldrd	wr0,[r1],-r2,lsl 2
	wldrd	wr0,[r1,r2]
	wldrd	wr0,[r1,-r2]
	wldrd	wr0,[r1,r2]!
	wldrd	wr0,[r1,-r2]!
	wldrd	wr0,[r1,r2,lsl 2]
	wldrd	wr0,[r1,-r2,lsl 2]
	wldrd	wr0,[r1,r2,lsl 2]!
	wldrd	wr0,[r1,-r2,lsl 2]!

	wmaddsn	wr0,wr1,wr2

	wmaddsx	wr0,wr1,wr2

	wmaddun	wr0,wr1,wr2

	wmaddux	wr0,wr1,wr2

	wmerge	wr0,wr1,wr2,3

	wmiabb	wr0,wr1,wr2

	wmiabbn	wr0,wr1,wr2

	wmiabt	wr0,wr1,wr2

	wmiabtn	wr0,wr1,wr2

	wmiatb	wr0,wr1,wr2

	wmiatbn	wr0,wr1,wr2

	wmiatt	wr0,wr1,wr2

	wmiattn	wr0,wr1,wr2

	wmiawbb	wr0,wr1,wr2

	wmiawbbn	wr0,wr1,wr2

	wmiawbt	wr0,wr1,wr2

	wmiawbtn	wr0,wr1,wr2

	wmiawtb	wr0,wr1,wr2

	wmiawtbn	wr0,wr1,wr2

	wmiawtt	wr0,wr1,wr2

	wmiawttn	wr0,wr1,wr2

	wmulsmr	wr0,wr1,wr2

	wmulumr	wr0,wr1,wr2

	wmulwl	wr0,wr1,wr2

	wmulwsm	wr0,wr1,wr2

	wmulwsmr	wr0,wr1,wr2

	wmulwum	wr0,wr1,wr2

	wmulwumr	wr0,wr1,wr2

	wqmiabb	wr0,wr1,wr2

	wqmiabbn	wr0,wr1,wr2

	wqmiabt	wr0,wr1,wr2

	wqmiabtn	wr0,wr1,wr2

	wqmiatb	wr0,wr1,wr2

	wqmiatbn	wr0,wr1,wr2

	wqmiatt	wr0,wr1,wr2

	wqmiattn	wr0,wr1,wr2

	wqmulm	wr0,wr1,wr2

	wqmulmr	wr0,wr1,wr2

	wqmulwm	wr0,wr1,wr2

	wqmulwmr	wr0,wr1,wr2

	wrord	wr0,wr1,2

	wrorh	wr0,wr1,2

	wrorw	wr0,wr1,2

	wslld	wr0,wr1,2

	wsllh	wr0,wr1,2

	wsllw	wr0,wr1,2

	wsrad	wr0,wr1,2

	wsrah	wr0,wr1,2

	wsraw	wr0,wr1,2

	wsrld	wr0,wr1,2

	wsrlh	wr0,wr1,2

	wsrlw	wr0,wr1,2

	wstrd	wr0,[r1],r2
	wstrd	wr0,[r1],-r2
	wstrd	wr0,[r1],r2,lsl 2
	wstrd	wr0,[r1],-r2,lsl 2
	wstrd	wr0,[r1,r2]
	wstrd	wr0,[r1,-r2]
	wstrd	wr0,[r1,r2]!
	wstrd	wr0,[r1,-r2]!
	wstrd	wr0,[r1,r2,lsl 2]
	wstrd	wr0,[r1,-r2,lsl 2]
	wstrd	wr0,[r1,r2,lsl 2]!
	wstrd	wr0,[r1,-r2,lsl 2]!

	wsubaddhx	wr0,wr1,wr2
