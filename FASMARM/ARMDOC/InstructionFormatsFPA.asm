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
	;FPA, ARM mode, all instructions are 32-bit
	;***********************************************

	code32

coprocessor COPRO_FPA_V1
	absd	f0,1.0
	absd	f0,f1

	absdm	f0,1.0
	absdm	f0,f1

	absdp	f0,1.0
	absdp	f0,f1

	absdz	f0,1.0
	absdz	f0,f1

	abse	f0,1.0
	abse	f0,f1

	absem	f0,1.0
	absem	f0,f1

	absep	f0,1.0
	absep	f0,f1

	absez	f0,1.0
	absez	f0,f1

	abss	f0,1.0
	abss	f0,f1

	abssm	f0,1.0
	abssm	f0,f1

	abssp	f0,1.0
	abssp	f0,f1

	abssz	f0,1.0
	abssz	f0,f1

	acsd	f0,1.0
	acsd	f0,f1

	acsdm	f0,1.0
	acsdm	f0,f1

	acsdp	f0,1.0
	acsdp	f0,f1

	acsdz	f0,1.0
	acsdz	f0,f1

	acse	f0,1.0
	acse	f0,f1

	acsem	f0,1.0
	acsem	f0,f1

	acsep	f0,1.0
	acsep	f0,f1

	acsez	f0,1.0
	acsez	f0,f1

	acss	f0,1.0
	acss	f0,f1

	acssm	f0,1.0
	acssm	f0,f1

	acssp	f0,1.0
	acssp	f0,f1

	acssz	f0,1.0
	acssz	f0,f1

	adfd	f0,f1,2.0
	adfd	f0,f1,f2

	adfdm	f0,f1,2.0
	adfdm	f0,f1,f2

	adfdp	f0,f1,2.0
	adfdp	f0,f1,f2

	adfdz	f0,f1,2.0
	adfdz	f0,f1,f2

	adfe	f0,f1,2.0
	adfe	f0,f1,f2

	adfem	f0,f1,2.0
	adfem	f0,f1,f2

	adfep	f0,f1,2.0
	adfep	f0,f1,f2

	adfez	f0,f1,2.0
	adfez	f0,f1,f2

	adfs	f0,f1,2.0
	adfs	f0,f1,f2

	adfsm	f0,f1,2.0
	adfsm	f0,f1,f2

	adfsp	f0,f1,2.0
	adfsp	f0,f1,f2

	adfsz	f0,f1,2.0
	adfsz	f0,f1,f2

	asnd	f0,1.0
	asnd	f0,f1

	asndm	f0,1.0
	asndm	f0,f1

	asndp	f0,1.0
	asndp	f0,f1

	asndz	f0,1.0
	asndz	f0,f1

	asne	f0,1.0
	asne	f0,f1

	asnem	f0,1.0
	asnem	f0,f1

	asnep	f0,1.0
	asnep	f0,f1

	asnez	f0,1.0
	asnez	f0,f1

	asns	f0,1.0
	asns	f0,f1

	asnsm	f0,1.0
	asnsm	f0,f1

	asnsp	f0,1.0
	asnsp	f0,f1

	asnsz	f0,1.0
	asnsz	f0,f1

	atnd	f0,1.0
	atnd	f0,f1

	atndm	f0,1.0
	atndm	f0,f1

	atndp	f0,1.0
	atndp	f0,f1

	atndz	f0,1.0
	atndz	f0,f1

	atne	f0,1.0
	atne	f0,f1

	atnem	f0,1.0
	atnem	f0,f1

	atnep	f0,1.0
	atnep	f0,f1

	atnez	f0,1.0
	atnez	f0,f1

	atns	f0,1.0
	atns	f0,f1

	atnsm	f0,1.0
	atnsm	f0,f1

	atnsp	f0,1.0
	atnsp	f0,f1

	atnsz	f0,1.0
	atnsz	f0,f1

	cmf	f0,1.0
	cmf	f0,f1

	cmfe	f0,1.0
	cmfe	f0,f1

	cnf	f0,1.0
	cnf	f0,f1

	cnfe	f0,1.0
	cnfe	f0,f1

	cosd	f0,1.0
	cosd	f0,f1

	cosdm	f0,1.0
	cosdm	f0,f1

	cosdp	f0,1.0
	cosdp	f0,f1

	cosdz	f0,1.0
	cosdz	f0,f1

	cose	f0,1.0
	cose	f0,f1

	cosem	f0,1.0
	cosem	f0,f1

	cosep	f0,1.0
	cosep	f0,f1

	cosez	f0,1.0
	cosez	f0,f1

	coss	f0,1.0
	coss	f0,f1

	cossm	f0,1.0
	cossm	f0,f1

	cossp	f0,1.0
	cossp	f0,f1

	cossz	f0,1.0
	cossz	f0,f1

	dvfd	f0,f1,2.0
	dvfd	f0,f1,f2

	dvfdm	f0,f1,2.0
	dvfdm	f0,f1,f2

	dvfdp	f0,f1,2.0
	dvfdp	f0,f1,f2

	dvfdz	f0,f1,2.0
	dvfdz	f0,f1,f2

	dvfe	f0,f1,2.0
	dvfe	f0,f1,f2

	dvfem	f0,f1,2.0
	dvfem	f0,f1,f2

	dvfep	f0,f1,2.0
	dvfep	f0,f1,f2

	dvfez	f0,f1,2.0
	dvfez	f0,f1,f2

	dvfs	f0,f1,2.0
	dvfs	f0,f1,f2

	dvfsm	f0,f1,2.0
	dvfsm	f0,f1,f2

	dvfsp	f0,f1,2.0
	dvfsp	f0,f1,f2

	dvfsz	f0,f1,2.0
	dvfsz	f0,f1,f2

	expd	f0,1.0
	expd	f0,f1

	expdm	f0,1.0
	expdm	f0,f1

	expdp	f0,1.0
	expdp	f0,f1

	expdz	f0,1.0
	expdz	f0,f1

	expe	f0,1.0
	expe	f0,f1

	expem	f0,1.0
	expem	f0,f1

	expep	f0,1.0
	expep	f0,f1

	expez	f0,1.0
	expez	f0,f1

	exps	f0,1.0
	exps	f0,f1

	expsm	f0,1.0
	expsm	f0,f1

	expsp	f0,1.0
	expsp	f0,f1

	expsz	f0,1.0
	expsz	f0,f1

	fdvd	f0,f1,2.0
	fdvd	f0,f1,f2

	fdvdm	f0,f1,2.0
	fdvdm	f0,f1,f2

	fdvdp	f0,f1,2.0
	fdvdp	f0,f1,f2

	fdvdz	f0,f1,2.0
	fdvdz	f0,f1,f2

	fdve	f0,f1,2.0
	fdve	f0,f1,f2

	fdvem	f0,f1,2.0
	fdvem	f0,f1,f2

	fdvep	f0,f1,2.0
	fdvep	f0,f1,f2

	fdvez	f0,f1,2.0
	fdvez	f0,f1,f2

	fdvs	f0,f1,2.0
	fdvs	f0,f1,f2

	fdvsm	f0,f1,2.0
	fdvsm	f0,f1,f2

	fdvsp	f0,f1,2.0
	fdvsp	f0,f1,f2

	fdvsz	f0,f1,2.0
	fdvsz	f0,f1,f2

	fix	r0,f1

	fixm	r0,f1

	fixp	r0,f1

	fixz	r0,f1

	fltd	f0,r1

	fltdm	f0,r1

	fltdp	f0,r1

	fltdz	f0,r1

	flte	f0,r1

	fltem	f0,r1

	fltep	f0,r1

	fltez	f0,r1

	flts	f0,r1

	fltsm	f0,r1

	fltsp	f0,r1

	fltsz	f0,r1

	fmld	f0,f1,2.0
	fmld	f0,f1,f2

	fmldm	f0,f1,2.0
	fmldm	f0,f1,f2

	fmldp	f0,f1,2.0
	fmldp	f0,f1,f2

	fmldz	f0,f1,2.0
	fmldz	f0,f1,f2

	fmle	f0,f1,2.0
	fmle	f0,f1,f2

	fmlem	f0,f1,2.0
	fmlem	f0,f1,f2

	fmlep	f0,f1,2.0
	fmlep	f0,f1,f2

	fmlez	f0,f1,2.0
	fmlez	f0,f1,f2

	fmls	f0,f1,2.0
	fmls	f0,f1,f2

	fmlsm	f0,f1,2.0
	fmlsm	f0,f1,f2

	fmlsp	f0,f1,2.0
	fmlsp	f0,f1,f2

	fmlsz	f0,f1,2.0
	fmlsz	f0,f1,f2

	frdd	f0,f1,2.0
	frdd	f0,f1,f2

	frddm	f0,f1,2.0
	frddm	f0,f1,f2

	frddp	f0,f1,2.0
	frddp	f0,f1,f2

	frddz	f0,f1,2.0
	frddz	f0,f1,f2

	frde	f0,f1,2.0
	frde	f0,f1,f2

	frdem	f0,f1,2.0
	frdem	f0,f1,f2

	frdep	f0,f1,2.0
	frdep	f0,f1,f2

	frdez	f0,f1,2.0
	frdez	f0,f1,f2

	frds	f0,f1,2.0
	frds	f0,f1,f2

	frdsm	f0,f1,2.0
	frdsm	f0,f1,f2

	frdsp	f0,f1,2.0
	frdsp	f0,f1,f2

	frdsz	f0,f1,2.0
	frdsz	f0,f1,f2

	label_ldfd:
	ldfd	f0,[r1]
	ldfd	f0,[r1],4
	ldfd	f0,[r1],{2}
	ldfd	f0,[r1,4]
	ldfd	f0,[r1,4]!
	ldfd	f0,[label_ldfd]
	ldfd	f0,[expression.word]
	ldfd	f0,[expression.word]!

	label_ldfe:
	ldfe	f0,[r1]
	ldfe	f0,[r1],4
	ldfe	f0,[r1],{2}
	ldfe	f0,[r1,4]
	ldfe	f0,[r1,4]!
	ldfe	f0,[label_ldfe]
	ldfe	f0,[expression.word]
	ldfe	f0,[expression.word]!

	label_ldfp:
	ldfp	f0,[r1]
	ldfp	f0,[r1],4
	ldfp	f0,[r1],{2}
	ldfp	f0,[r1,4]
	ldfp	f0,[r1,4]!
	ldfp	f0,[label_ldfp]
	ldfp	f0,[expression.word]
	ldfp	f0,[expression.word]!

	label_ldfs:
	ldfs	f0,[r1]
	ldfs	f0,[r1],4
	ldfs	f0,[r1],{2}
	ldfs	f0,[r1,4]
	ldfs	f0,[r1,4]!
	ldfs	f0,[label_ldfs]
	ldfs	f0,[expression.word]
	ldfs	f0,[expression.word]!

	lgnd	f0,1.0
	lgnd	f0,f1

	lgndm	f0,1.0
	lgndm	f0,f1

	lgndp	f0,1.0
	lgndp	f0,f1

	lgndz	f0,1.0
	lgndz	f0,f1

	lgne	f0,1.0
	lgne	f0,f1

	lgnem	f0,1.0
	lgnem	f0,f1

	lgnep	f0,1.0
	lgnep	f0,f1

	lgnez	f0,1.0
	lgnez	f0,f1

	lgns	f0,1.0
	lgns	f0,f1

	lgnsm	f0,1.0
	lgnsm	f0,f1

	lgnsp	f0,1.0
	lgnsp	f0,f1

	lgnsz	f0,1.0
	lgnsz	f0,f1

	logd	f0,1.0
	logd	f0,f1

	logdm	f0,1.0
	logdm	f0,f1

	logdp	f0,1.0
	logdp	f0,f1

	logdz	f0,1.0
	logdz	f0,f1

	loge	f0,1.0
	loge	f0,f1

	logem	f0,1.0
	logem	f0,f1

	logep	f0,1.0
	logep	f0,f1

	logez	f0,1.0
	logez	f0,f1

	logs	f0,1.0
	logs	f0,f1

	logsm	f0,1.0
	logsm	f0,f1

	logsp	f0,1.0
	logsp	f0,f1

	logsz	f0,1.0
	logsz	f0,f1

	mnfd	f0,1.0
	mnfd	f0,f1

	mnfdm	f0,1.0
	mnfdm	f0,f1

	mnfdp	f0,1.0
	mnfdp	f0,f1

	mnfdz	f0,1.0
	mnfdz	f0,f1

	mnfe	f0,1.0
	mnfe	f0,f1

	mnfem	f0,1.0
	mnfem	f0,f1

	mnfep	f0,1.0
	mnfep	f0,f1

	mnfez	f0,1.0
	mnfez	f0,f1

	mnfs	f0,1.0
	mnfs	f0,f1

	mnfsm	f0,1.0
	mnfsm	f0,f1

	mnfsp	f0,1.0
	mnfsp	f0,f1

	mnfsz	f0,1.0
	mnfsz	f0,f1

	mufd	f0,f1,2.0
	mufd	f0,f1,f2

	mufdm	f0,f1,2.0
	mufdm	f0,f1,f2

	mufdp	f0,f1,2.0
	mufdp	f0,f1,f2

	mufdz	f0,f1,2.0
	mufdz	f0,f1,f2

	mufe	f0,f1,2.0
	mufe	f0,f1,f2

	mufem	f0,f1,2.0
	mufem	f0,f1,f2

	mufep	f0,f1,2.0
	mufep	f0,f1,f2

	mufez	f0,f1,2.0
	mufez	f0,f1,f2

	mufs	f0,f1,2.0
	mufs	f0,f1,f2

	mufsm	f0,f1,2.0
	mufsm	f0,f1,f2

	mufsp	f0,f1,2.0
	mufsp	f0,f1,f2

	mufsz	f0,f1,2.0
	mufsz	f0,f1,f2

	mvfd	f0,1.0
	mvfd	f0,f1

	mvfdm	f0,1.0
	mvfdm	f0,f1

	mvfdp	f0,1.0
	mvfdp	f0,f1

	mvfdz	f0,1.0
	mvfdz	f0,f1

	mvfe	f0,1.0
	mvfe	f0,f1

	mvfem	f0,1.0
	mvfem	f0,f1

	mvfep	f0,1.0
	mvfep	f0,f1

	mvfez	f0,1.0
	mvfez	f0,f1

	mvfs	f0,1.0
	mvfs	f0,f1

	mvfsm	f0,1.0
	mvfsm	f0,f1

	mvfsp	f0,1.0
	mvfsp	f0,f1

	mvfsz	f0,1.0
	mvfsz	f0,f1

	nrmd	f0,1.0
	nrmd	f0,f1

	nrmdm	f0,1.0
	nrmdm	f0,f1

	nrmdp	f0,1.0
	nrmdp	f0,f1

	nrmdz	f0,1.0
	nrmdz	f0,f1

	nrme	f0,1.0
	nrme	f0,f1

	nrmem	f0,1.0
	nrmem	f0,f1

	nrmep	f0,1.0
	nrmep	f0,f1

	nrmez	f0,1.0
	nrmez	f0,f1

	nrms	f0,1.0
	nrms	f0,f1

	nrmsm	f0,1.0
	nrmsm	f0,f1

	nrmsp	f0,1.0
	nrmsp	f0,f1

	nrmsz	f0,1.0
	nrmsz	f0,f1

	pold	f0,f1,2.0
	pold	f0,f1,f2

	poldm	f0,f1,2.0
	poldm	f0,f1,f2

	poldp	f0,f1,2.0
	poldp	f0,f1,f2

	poldz	f0,f1,2.0
	poldz	f0,f1,f2

	pole	f0,f1,2.0
	pole	f0,f1,f2

	polem	f0,f1,2.0
	polem	f0,f1,f2

	polep	f0,f1,2.0
	polep	f0,f1,f2

	polez	f0,f1,2.0
	polez	f0,f1,f2

	pols	f0,f1,2.0
	pols	f0,f1,f2

	polsm	f0,f1,2.0
	polsm	f0,f1,f2

	polsp	f0,f1,2.0
	polsp	f0,f1,f2

	polsz	f0,f1,2.0
	polsz	f0,f1,f2

	powd	f0,f1,2.0
	powd	f0,f1,f2

	powdm	f0,f1,2.0
	powdm	f0,f1,f2

	powdp	f0,f1,2.0
	powdp	f0,f1,f2

	powdz	f0,f1,2.0
	powdz	f0,f1,f2

	powe	f0,f1,2.0
	powe	f0,f1,f2

	powem	f0,f1,2.0
	powem	f0,f1,f2

	powep	f0,f1,2.0
	powep	f0,f1,f2

	powez	f0,f1,2.0
	powez	f0,f1,f2

	pows	f0,f1,2.0
	pows	f0,f1,f2

	powsm	f0,f1,2.0
	powsm	f0,f1,f2

	powsp	f0,f1,2.0
	powsp	f0,f1,f2

	powsz	f0,f1,2.0
	powsz	f0,f1,f2

	rdfd	f0,f1,2.0
	rdfd	f0,f1,f2

	rdfdm	f0,f1,2.0
	rdfdm	f0,f1,f2

	rdfdp	f0,f1,2.0
	rdfdp	f0,f1,f2

	rdfdz	f0,f1,2.0
	rdfdz	f0,f1,f2

	rdfe	f0,f1,2.0
	rdfe	f0,f1,f2

	rdfem	f0,f1,2.0
	rdfem	f0,f1,f2

	rdfep	f0,f1,2.0
	rdfep	f0,f1,f2

	rdfez	f0,f1,2.0
	rdfez	f0,f1,f2

	rdfs	f0,f1,2.0
	rdfs	f0,f1,f2

	rdfsm	f0,f1,2.0
	rdfsm	f0,f1,f2

	rdfsp	f0,f1,2.0
	rdfsp	f0,f1,f2

	rdfsz	f0,f1,2.0
	rdfsz	f0,f1,f2

	rfc	r0

	rfs	r0

	rmfd	f0,f1,2.0
	rmfd	f0,f1,f2

	rmfdm	f0,f1,2.0
	rmfdm	f0,f1,f2

	rmfdp	f0,f1,2.0
	rmfdp	f0,f1,f2

	rmfdz	f0,f1,2.0
	rmfdz	f0,f1,f2

	rmfe	f0,f1,2.0
	rmfe	f0,f1,f2

	rmfem	f0,f1,2.0
	rmfem	f0,f1,f2

	rmfep	f0,f1,2.0
	rmfep	f0,f1,f2

	rmfez	f0,f1,2.0
	rmfez	f0,f1,f2

	rmfs	f0,f1,2.0
	rmfs	f0,f1,f2

	rmfsm	f0,f1,2.0
	rmfsm	f0,f1,f2

	rmfsp	f0,f1,2.0
	rmfsp	f0,f1,f2

	rmfsz	f0,f1,2.0
	rmfsz	f0,f1,f2

	rndd	f0,1.0
	rndd	f0,f1

	rnddm	f0,1.0
	rnddm	f0,f1

	rnddp	f0,1.0
	rnddp	f0,f1

	rnddz	f0,1.0
	rnddz	f0,f1

	rnde	f0,1.0
	rnde	f0,f1

	rndem	f0,1.0
	rndem	f0,f1

	rndep	f0,1.0
	rndep	f0,f1

	rndez	f0,1.0
	rndez	f0,f1

	rnds	f0,1.0
	rnds	f0,f1

	rndsm	f0,1.0
	rndsm	f0,f1

	rndsp	f0,1.0
	rndsp	f0,f1

	rndsz	f0,1.0
	rndsz	f0,f1

	rpwd	f0,f1,2.0
	rpwd	f0,f1,f2

	rpwdm	f0,f1,2.0
	rpwdm	f0,f1,f2

	rpwdp	f0,f1,2.0
	rpwdp	f0,f1,f2

	rpwdz	f0,f1,2.0
	rpwdz	f0,f1,f2

	rpwe	f0,f1,2.0
	rpwe	f0,f1,f2

	rpwem	f0,f1,2.0
	rpwem	f0,f1,f2

	rpwep	f0,f1,2.0
	rpwep	f0,f1,f2

	rpwez	f0,f1,2.0
	rpwez	f0,f1,f2

	rpws	f0,f1,2.0
	rpws	f0,f1,f2

	rpwsm	f0,f1,2.0
	rpwsm	f0,f1,f2

	rpwsp	f0,f1,2.0
	rpwsp	f0,f1,f2

	rpwsz	f0,f1,2.0
	rpwsz	f0,f1,f2

	rsfd	f0,f1,2.0
	rsfd	f0,f1,f2

	rsfdm	f0,f1,2.0
	rsfdm	f0,f1,f2

	rsfdp	f0,f1,2.0
	rsfdp	f0,f1,f2

	rsfdz	f0,f1,2.0
	rsfdz	f0,f1,f2

	rsfe	f0,f1,2.0
	rsfe	f0,f1,f2

	rsfem	f0,f1,2.0
	rsfem	f0,f1,f2

	rsfep	f0,f1,2.0
	rsfep	f0,f1,f2

	rsfez	f0,f1,2.0
	rsfez	f0,f1,f2

	rsfs	f0,f1,2.0
	rsfs	f0,f1,f2

	rsfsm	f0,f1,2.0
	rsfsm	f0,f1,f2

	rsfsp	f0,f1,2.0
	rsfsp	f0,f1,f2

	rsfsz	f0,f1,2.0
	rsfsz	f0,f1,f2

	sind	f0,1.0
	sind	f0,f1

	sindm	f0,1.0
	sindm	f0,f1

	sindp	f0,1.0
	sindp	f0,f1

	sindz	f0,1.0
	sindz	f0,f1

	sine	f0,1.0
	sine	f0,f1

	sinem	f0,1.0
	sinem	f0,f1

	sinep	f0,1.0
	sinep	f0,f1

	sinez	f0,1.0
	sinez	f0,f1

	sins	f0,1.0
	sins	f0,f1

	sinsm	f0,1.0
	sinsm	f0,f1

	sinsp	f0,1.0
	sinsp	f0,f1

	sinsz	f0,1.0
	sinsz	f0,f1

	sqtd	f0,1.0
	sqtd	f0,f1

	sqtdm	f0,1.0
	sqtdm	f0,f1

	sqtdp	f0,1.0
	sqtdp	f0,f1

	sqtdz	f0,1.0
	sqtdz	f0,f1

	sqte	f0,1.0
	sqte	f0,f1

	sqtem	f0,1.0
	sqtem	f0,f1

	sqtep	f0,1.0
	sqtep	f0,f1

	sqtez	f0,1.0
	sqtez	f0,f1

	sqts	f0,1.0
	sqts	f0,f1

	sqtsm	f0,1.0
	sqtsm	f0,f1

	sqtsp	f0,1.0
	sqtsp	f0,f1

	sqtsz	f0,1.0
	sqtsz	f0,f1

	label_stfd:
	stfd	f0,[r1]
	stfd	f0,[r1],4
	stfd	f0,[r1],{2}
	stfd	f0,[r1,4]
	stfd	f0,[r1,4]!
	stfd	f0,[label_stfd]
	stfd	f0,[expression.word]
	stfd	f0,[expression.word]!

	label_stfe:
	stfe	f0,[r1]
	stfe	f0,[r1],4
	stfe	f0,[r1],{2}
	stfe	f0,[r1,4]
	stfe	f0,[r1,4]!
	stfe	f0,[label_stfe]
	stfe	f0,[expression.word]
	stfe	f0,[expression.word]!

	label_stfp:
	stfp	f0,[r1]
	stfp	f0,[r1],4
	stfp	f0,[r1],{2}
	stfp	f0,[r1,4]
	stfp	f0,[r1,4]!
	stfp	f0,[label_stfp]
	stfp	f0,[expression.word]
	stfp	f0,[expression.word]!

	label_stfs:
	stfs	f0,[r1]
	stfs	f0,[r1],4
	stfs	f0,[r1],{2}
	stfs	f0,[r1,4]
	stfs	f0,[r1,4]!
	stfs	f0,[label_stfs]
	stfs	f0,[expression.word]
	stfs	f0,[expression.word]!

	sufd	f0,f1,2.0
	sufd	f0,f1,f2

	sufdm	f0,f1,2.0
	sufdm	f0,f1,f2

	sufdp	f0,f1,2.0
	sufdp	f0,f1,f2

	sufdz	f0,f1,2.0
	sufdz	f0,f1,f2

	sufe	f0,f1,2.0
	sufe	f0,f1,f2

	sufem	f0,f1,2.0
	sufem	f0,f1,f2

	sufep	f0,f1,2.0
	sufep	f0,f1,f2

	sufez	f0,f1,2.0
	sufez	f0,f1,f2

	sufs	f0,f1,2.0
	sufs	f0,f1,f2

	sufsm	f0,f1,2.0
	sufsm	f0,f1,f2

	sufsp	f0,f1,2.0
	sufsp	f0,f1,f2

	sufsz	f0,f1,2.0
	sufsz	f0,f1,f2

	tand	f0,1.0
	tand	f0,f1

	tandm	f0,1.0
	tandm	f0,f1

	tandp	f0,1.0
	tandp	f0,f1

	tandz	f0,1.0
	tandz	f0,f1

	tane	f0,1.0
	tane	f0,f1

	tanem	f0,1.0
	tanem	f0,f1

	tanep	f0,1.0
	tanep	f0,f1

	tanez	f0,1.0
	tanez	f0,f1

	tans	f0,1.0
	tans	f0,f1

	tansm	f0,1.0
	tansm	f0,f1

	tansp	f0,1.0
	tansp	f0,f1

	tansz	f0,1.0
	tansz	f0,f1

	urdd	f0,1.0
	urdd	f0,f1

	urddm	f0,1.0
	urddm	f0,f1

	urddp	f0,1.0
	urddp	f0,f1

	urddz	f0,1.0
	urddz	f0,f1

	urde	f0,1.0
	urde	f0,f1

	urdem	f0,1.0
	urdem	f0,f1

	urdep	f0,1.0
	urdep	f0,f1

	urdez	f0,1.0
	urdez	f0,f1

	urds	f0,1.0
	urds	f0,f1

	urdsm	f0,1.0
	urdsm	f0,f1

	urdsp	f0,1.0
	urdsp	f0,f1

	urdsz	f0,1.0
	urdsz	f0,f1

	wfc	r0

	wfs	r0

coprocessor COPRO_FPA_V2

	label_lfm:
	lfm	f0,1,[r2]
	lfm	f0,1,[r2],4
	lfm	f0,1,[r2],{4}
	lfm	f0,1,[r2,4]
	lfm	f0,1,[r2,4]!
	lfm	f0,1,[label_lfm]
	lfm	f0,1,[expression.word]
	lfm	f0,1,[expression.word]!

	lfmea	f0,1,[r2]
	lfmea	f0,1,[r2]!

	lfmfd	f0,1,[r2]
	lfmfd	f0,1,[r2]!

	label_sfm:
	sfm	f0,1,[r2]
	sfm	f0,1,[r2],4
	sfm	f0,1,[r2],{4}
	sfm	f0,1,[r2,4]
	sfm	f0,1,[r2,4]!
	sfm	f0,1,[label_sfm]
	sfm	f0,1,[expression.word]
	sfm	f0,1,[expression.word]!

	sfmea	f0,1,[r2]
	sfmea	f0,1,[r2]!

	sfmfd	f0,1,[r2]
	sfmfd	f0,1,[r2]!
