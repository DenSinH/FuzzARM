
;Extended WinCE programming headers

	format	PE GUI

	include 'WINCE.INC'
	include 'MACRO\ARMLITRL.INC'

macro .code {section '.text' code readable executable}
macro .data {section '.data' data readable writeable}

macro .end begin {
	entry begin
	section '.idata' import readable writeable
	library coredll,'COREDLL.DLL'
	include	'APICE\COREDLL.INC'
}

macro endp {
	literals
	endp
}
