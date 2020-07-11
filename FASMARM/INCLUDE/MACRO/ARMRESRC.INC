
;Macroinstructions for making resources for WinCE with FASMARM
;By default this file is included from "WINCE.INC".

	dq fix dd
	dd fix dw
	dw fix dh
	rq fix rd
	rd fix rw
	rw fix rh

	include 'MACRO\RESOURCE.INC'

	rw fix rw
	rd fix rd
	rq fix rq
	dw fix dw
	dd fix dd
	dq fix dq
