;FASMARM extension macros:
;
;Macros for imports section in PE file generation
;
;LIBRARY:
;
;  Usage: library name1,string1,name2,string2,...
;
;  name   - a prefix for program labels identifying data structures
;  string - a text ascii string identifying the DLL filename
;
;
;IMPORT:
;
;  Usage: import name,function1,ordinal1,function2,ordinal2,...
;
;  name     - a prefix for program labels identifying data structures
;  function - program label for the import
;  ordinal  - the DLL exported ordinal
;
;By default this file is included from "WINCE.INC".


macro library [name,string] {
    common
	align 4
   ;;	data import
    forward
	if defined name#_required
	    dw RVA name,0,0,RVA name#_name,RVA name
	end if
    common
	rw 5
   ;;	end data
    forward
	if defined name#_required
	    name#_name: db string,0
	end if
    common
	align 4
}

macro import name,[function,ordinal] {
    common
	align 4
	name:
    forward
	if used _#function
	    _#function dw ordinal
	end if
    common
	if $-name>0
	    name#_required=1
	    dw 0
	end if
    forward
	if used function
	  function:
	  if $+8-_#function<4096
	    ldr pc,[pc,_#function-$-8]
	  else
	    ldr r12,[pc]
	    ldr pc,[r12]
	    dw _#function
	  end if
	end if
}
