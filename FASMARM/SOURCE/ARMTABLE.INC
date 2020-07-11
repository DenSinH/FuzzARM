; ARMv8 assembler core module v1.43 for flat assembler,
; Copyright (c) 2005-2017, Revolution.
; All rights reserved.
;
; Some portions are Copyright (c) 1999-2016, Tomasz Grysztar.
; All rights reserved.

include_variable db 'INCLUDE',0

symbol_characters db 27
 db 9,0Ah,0Dh,1Ah,20h,'+-/*=<>()[]{}:,|&~#`;\'

preprocessor_directives:
 db 6,'define'
 dw define_symbolic_constant-directive_handler
 db 7,'include'
 dw include_file-directive_handler
 db 3,'irp'
 dw irp_directive-directive_handler
 db 4,'irps'
 dw irps_directive-directive_handler
 db 4,'irpv'
 dw irpv_directive-directive_handler
 db 5,'macro'
 dw define_macro-directive_handler
 db 5,'match'
 dw match_directive-directive_handler
 db 8,'postpone'
 dw postpone_directive-directive_handler
 db 5,'purge'
 dw purge_macro-directive_handler
 db 4,'rept'
 dw rept_directive-directive_handler
 db 7,'restore'
 dw restore_equ_constant-directive_handler
 db 7,'restruc'
 dw purge_struc-directive_handler
 db 5,'struc'
 dw define_struc-directive_handler
 db 0

macro_directives:
 db 6,'common'
 dw common_block-directive_handler
 db 7,'forward'
 dw forward_block-directive_handler
 db 5,'local'
 dw local_symbols-directive_handler
 db 7,'reverse'
 dw reverse_block-directive_handler
 db 0

operators:
 db 1,'+',80h
 db 1,'-',81h
 db 1,'*',90h
 db 1,'/',91h
 db 3,'and',0B0h
 db 3,'mod',0A0h
 db 2,'or',0B1h
 db 3,'shl',0C0h
 db 3,'shr',0C1h
 db 3,'xor',0B2h
 db 0

single_operand_operators:
 db 1,'+',082h
 db 1,'-',083h
 db 3,'bsf',0E0h
 db 3,'bsr',0E1h
 db 3,'fit',0D1h		;ARM operator fit
 db 3,'not',0D0h
 db 3,'plt',0F1h
 db 3,'rva',0F0h
 db 0

directive_operators:
 db 5,'align',8Ch
 db 2,'as',86h
 db 2,'at',80h
 db 11,'coprocessor',08Eh	;ARM coprocessor instructions selected
 db 7,'defined',88h
 db 3,'dup',81h
 db 2,'eq',0F0h
 db 6,'eqtype',0F7h
 db 4,'from',82h
 db 2,'in',0F6h
 db 2,'on',84h
 db 9,'processor',08Fh		;ARM processor instructions selected
 db 3,'ptr',85h
 db 10,'relativeto',0F8h
 db 4,'used',89h
 db 0

address_sizes:
	db	0

symbols:
	dw	symbols_1-symbols,(symbols_2-symbols_1)/(1+2)
	dw	symbols_2-symbols,(symbols_3-symbols_2)/(2+2)
	dw	symbols_3-symbols,(symbols_4-symbols_3)/(3+2)
	dw	symbols_4-symbols,(symbols_5-symbols_4)/(4+2)
	dw	symbols_5-symbols,(symbols_6-symbols_5)/(5+2)
	dw	symbols_6-symbols,(symbols_7-symbols_6)/(6+2)
	dw	symbols_7-symbols,(symbols_8-symbols_7)/(7+2)
	dw	symbols_8-symbols,(symbols_9-symbols_8)/(8+2)
	dw	symbols_9-symbols,(symbols_10-symbols_9)/(9+2)
	dw	symbols_10-symbols,(symbols_11-symbols_10)/(10+2)
	dw	symbols_11-symbols,(symbols_12-symbols_11)/(11+2)
	dw	symbols_12-symbols,(symbols_13-symbols_12)/(12+2)
	dw	symbols_13-symbols,(symbols_14-symbols_13)/(13+2)
	dw	symbols_14-symbols,(symbols_15-symbols_14)/(14+2)
	dw	symbols_15-symbols,(symbols_16-symbols_15)/(15+2)
	dw	symbols_16-symbols,(symbols_17-symbols_16)/(16+2)
	dw	symbols_17-symbols,(symbols_end-symbols_17)/(17+2)

base_@16	= 0x1010
base_@16.size	= 0x10				;r0@16-r15@16

base_@32	= base_@16+base_@16.size
base_@32.size	= 0x10				;r0@32-r15@32

base_@64	= base_@32+base_@32.size
base_@64.size	= 0x10				;r0@64-r15@64

base_@128	= base_@64+base_@64.size
base_@128.size	= 0x10				;r0@128-r15@128

base_@256	= base_@128+base_@128.size
base_@256.size	= 0x10				;r0@256-r15@256

base_reg	= base_@256+base_@256.size
base_reg.size	= 0x10				;r0-r15

dword_reg	= base_reg+base_reg.size
dword_reg.size	= 0x20				;x0-x30,xzr

size_opr	= 0x1100
size_opr.size	= 33				;byte,hword,word,dword,qword,dqword

sys_at		= 0x1200
sys_at.size	= 12				;0-11

sys_dc		= sys_at+sys_at.size
sys_dc.size	= 8				;0-7

sys_ic		= sys_dc+sys_dc.size
sys_ic.size	= 3				;0-2

sys_tlbi	= sys_ic+sys_ic.size
sys_tlbi.size	= 32				;0-31

sys_msr		= sys_tlbi+sys_tlbi.size
sys_msr.size	= 384				;0-383

sys_pstate	= sys_msr+sys_msr.size
sys_pstate.size	= 2				;daifclr, daifset

base_reg!	= sys_pstate+sys_pstate.size
base_reg!.size	= 0x10				;r0!-r15!

vect_breg	= base_reg!+base_reg!.size
vect_breg.size	= 0x20				;b0-b31

vect_hreg	= vect_breg+vect_breg.size
vect_hreg.size	= 0x20				;h0-h31

vect_sreg	= vect_hreg+vect_hreg.size
vect_sreg.size	= 0x20				;s0-s31

vfps_reg	= vect_sreg
vfps_reg.size	= 0x20				;s0-s31

vect_dreg	= vect_sreg+vect_sreg.size
vect_dreg.size	= 0x20				;d0-d31

vfpd_reg	= vect_dreg
vfpd_reg.size	= 0x20				;d0-d31

vect_qreg	= vect_dreg+vect_dreg.size
vect_qreg.size	= 0x20				;q0-q31

simd_qreg	= vect_qreg
simd_qreg.size	= 0x10				;q0-q15

word_reg	= vect_qreg+vect_qreg.size
word_reg.size	= 0x21				;w0-w30,wzr,wsp

banked_reg	= word_reg+word_reg.size
banked_reg.size	= 0x3f				;0-62

vect_v8b	= banked_reg+banked_reg.size
vect_v8b.size	= 0x20				;v0.8b-v31.8b

vect_v16b	= vect_v8b+vect_v8b.size
vect_v16b.size	= 0x20				;v0.16b-v31.16b

vect_v4h	= vect_v16b+vect_v16b.size
vect_v4h.size	= 0x20				;v0.4h-v31.4h

vect_v8h	= vect_v4h+vect_v4h.size
vect_v8h.size	= 0x20				;v0.8h-v31.8h

vect_v2s	= vect_v8h+vect_v8h.size
vect_v2s.size	= 0x20				;v0.2s-v31.2s

vect_v4s	= vect_v2s+vect_v2s.size
vect_v4s.size	= 0x20				;v0.4s-v31.4s

vect_v2d	= vect_v4s+vect_v4s.size
vect_v2d.size	= 0x20				;v0.2d-v31.2d

vect_v1d	= vect_v2d+vect_v2d.size
vect_v1d.size	= 0x20				;v0.1d-v31.1d

vect_v1q	= vect_v1d+vect_v1d.size
vect_v1q.size	= 0x20				;v0.1q-v31.1q

vect_vb		= vect_v1q+vect_v1q.size
vect_vb.size	= 0x20				;v0.b-v31.b

vect_vh		= vect_vb+vect_vb.size
vect_vh.size	= 0x20				;v0.h-v31.h

vect_vs		= vect_vh+vect_vh.size
vect_vs.size	= 0x20				;v0.s-v31.s

vect_vd		= vect_vs+vect_vs.size
vect_vd.size	= 0x20				;v0.d-v31.d

cpro_sel	= vect_vd+vect_vd.size
cpro_sel.size	= 0x10				;p0-p15

cpro_reg	= cpro_sel+cpro_sel.size
cpro_reg.size	= 0x10				;c0-c15

shift_op	= cpro_reg+cpro_reg.size
shift_op.size	= 4				;asr, lsl, lsr, ror

rrx_op		= shift_op+shift_op.size
rrx_op.size	= 1				;rrx

msl_op		= rrx_op+rrx_op.size
msl_op.size	= 1				;msl

endian		= msl_op+msl_op.size
endian.size	= 2				;be, le

modifier	= endian+endian.size
modifier.size	= 2				;!, ^

psr_reg		= modifier+modifier.size
psr_reg.size	= 16+16+3			;cpse, spsr

iflags		= psr_reg+psr_reg.size
iflags.size	= 8				;a, i, f

vfp_syst	= iflags+iflags.size
vfp_syst.size	= 11				;

acc_40bt	= vfp_syst+vfp_syst.size
acc_40bt.size	= 8				;acc0-acc7

iwmmx_wreg	= acc_40bt+acc_40bt.size
iwmmx_wreg.size	= 0x10				;wr0-wr15

iwmmx_creg	= iwmmx_wreg+iwmmx_wreg.size
iwmmx_creg.size	= 12				;

mvrk_areg	= iwmmx_creg+iwmmx_creg.size
mvrk_areg.size	= 1				;a0

mvrk_psc	= mvrk_areg+mvrk_areg.size
mvrk_psc.size	= 1				;dspsc

fpa_freg	= mvrk_psc+mvrk_psc.size
fpa_freg.size	= 8				;f0-f7

barrier		= fpa_freg+fpa_freg.size
barrier.size	= 0x10				;

condition	= barrier+barrier.size
condition.size	= 16				;

sysm_reg	= condition+condition.size
sysm_reg.size	= 21				;

xtnd_op		= sysm_reg+sysm_reg.size
xtnd_op.size	= 8				;

prf_op		= xtnd_op+xtnd_op.size
prf_op.size	= 2*8+2*2+1 + 1			;

assert prf_op+prf_op.size <= 0x1800

		; 0x18	mz, pe, elf, coff, pe64, elf64, binary
		; 0x19	code, data, dwarf, linkinfo, readable, writable, shareable, writeable, executable, linkremove, discardable, notpageable
		; 0x1a	export, fixups, import, resource
		; 0x1b	nx, dll, efi, gui, wdm, large, native, console, efiboot, efiruntime
		; 0x1c	ms, ms64
		; 0x1d	static
		; 0x1e	note, dynamic, interpreter
		; 0x1f	cpu_sel, copro_sel

cpu_sel.all32	= 0x1f00
cpu_sel.all64	= 0x1f01
copro_sel.all	= 0x1f02

cpu_sel		= 0x1f03
cpu_sel.size	= 37

copro_sel	= cpu_sel+cpu_sel.size
copro_sel.size	= 19

macro symbol_maker symbol,value {db symbol,(value) shr 8,(value) and 0xff}

symbols_1:
	symbol_maker	'!',modifier+0
	symbol_maker	'^',modifier+1
symbols_2:
	symbol_maker	'a0',mvrk_areg
	symbol_maker	'a1',base_reg+0
	symbol_maker	'a2',base_reg+1
	symbol_maker	'a3',base_reg+2
	symbol_maker	'a4',base_reg+3
	symbol_maker	'al',condition+0xe
	symbol_maker	'b0',vect_breg+0
	symbol_maker	'b1',vect_breg+1
	symbol_maker	'b2',vect_breg+2
	symbol_maker	'b3',vect_breg+3
	symbol_maker	'b4',vect_breg+4
	symbol_maker	'b5',vect_breg+5
	symbol_maker	'b6',vect_breg+6
	symbol_maker	'b7',vect_breg+7
	symbol_maker	'b8',vect_breg+8
	symbol_maker	'b9',vect_breg+9
	symbol_maker	'be',endian+1
	symbol_maker	'c0',cpro_reg+0
	symbol_maker	'c1',cpro_reg+1
	symbol_maker	'c2',cpro_reg+2
	symbol_maker	'c3',cpro_reg+3
	symbol_maker	'c4',cpro_reg+4
	symbol_maker	'c5',cpro_reg+5
	symbol_maker	'c6',cpro_reg+6
	symbol_maker	'c7',cpro_reg+7
	symbol_maker	'c8',cpro_reg+8
	symbol_maker	'c9',cpro_reg+9
	symbol_maker	'cc',condition+0x3
	symbol_maker	'cs',condition+0x2
	symbol_maker	'd0',vect_dreg+0
	symbol_maker	'd1',vect_dreg+1
	symbol_maker	'd2',vect_dreg+2
	symbol_maker	'd3',vect_dreg+3
	symbol_maker	'd4',vect_dreg+4
	symbol_maker	'd5',vect_dreg+5
	symbol_maker	'd6',vect_dreg+6
	symbol_maker	'd7',vect_dreg+7
	symbol_maker	'd8',vect_dreg+8
	symbol_maker	'd9',vect_dreg+9
;;	symbol_maker	'eq',condition+0x0
	symbol_maker	'f0',fpa_freg+0
	symbol_maker	'f1',fpa_freg+1
	symbol_maker	'f2',fpa_freg+2
	symbol_maker	'f3',fpa_freg+3
	symbol_maker	'f4',fpa_freg+4
	symbol_maker	'f5',fpa_freg+5
	symbol_maker	'f6',fpa_freg+6
	symbol_maker	'f7',fpa_freg+7
	symbol_maker	'fp',base_reg+11
	symbol_maker	'ge',condition+0xa
	symbol_maker	'gt',condition+0xc
	symbol_maker	'h0',vect_hreg+0
	symbol_maker	'h1',vect_hreg+1
	symbol_maker	'h2',vect_hreg+2
	symbol_maker	'h3',vect_hreg+3
	symbol_maker	'h4',vect_hreg+4
	symbol_maker	'h5',vect_hreg+5
	symbol_maker	'h6',vect_hreg+6
	symbol_maker	'h7',vect_hreg+7
	symbol_maker	'h8',vect_hreg+8
	symbol_maker	'h9',vect_hreg+9
	symbol_maker	'hi',condition+0x8
	symbol_maker	'hs',condition+0x2
	symbol_maker	'ip',base_reg+12
	symbol_maker	'ld',barrier+1101b
	symbol_maker	'le',endian+0
;;	symbol_maker	'le',condition+0xd
	symbol_maker	'lo',condition+0x3
	symbol_maker	'lr',base_reg+14
	symbol_maker	'ls',condition+0x9
	symbol_maker	'lt',condition+0xb
	symbol_maker	'mi',condition+0x4
	symbol_maker	'ms',1Ch shl 8 + 41h
	symbol_maker	'mz',18h shl 8 + 20h
	symbol_maker	'ne',condition+0x1
	symbol_maker	'nv',condition+0xf
	symbol_maker	'nx',1Bh shl 8 + 83h
	symbol_maker	'p0',cpro_sel+0
	symbol_maker	'p1',cpro_sel+1
	symbol_maker	'p2',cpro_sel+2
	symbol_maker	'p3',cpro_sel+3
	symbol_maker	'p4',cpro_sel+4
	symbol_maker	'p5',cpro_sel+5
	symbol_maker	'p6',cpro_sel+6
	symbol_maker	'p7',cpro_sel+7
	symbol_maker	'p8',cpro_sel+8
	symbol_maker	'p9',cpro_sel+9
	symbol_maker	'pc',base_reg+15
	symbol_maker	'pe',18h shl 8 + 30h
	symbol_maker	'pl',condition+0x5
	symbol_maker	'q0',vect_qreg+0
	symbol_maker	'q1',vect_qreg+1
	symbol_maker	'q2',vect_qreg+2
	symbol_maker	'q3',vect_qreg+3
	symbol_maker	'q4',vect_qreg+4
	symbol_maker	'q5',vect_qreg+5
	symbol_maker	'q6',vect_qreg+6
	symbol_maker	'q7',vect_qreg+7
	symbol_maker	'q8',vect_qreg+8
	symbol_maker	'q9',vect_qreg+9
	symbol_maker	'r0',base_reg+0
	symbol_maker	'r1',base_reg+1
	symbol_maker	'r2',base_reg+2
	symbol_maker	'r3',base_reg+3
	symbol_maker	'r4',base_reg+4
	symbol_maker	'r5',base_reg+5
	symbol_maker	'r6',base_reg+6
	symbol_maker	'r7',base_reg+7
	symbol_maker	'r8',base_reg+8
	symbol_maker	'r9',base_reg+9
	symbol_maker	's0',vect_sreg+0
	symbol_maker	's1',vect_sreg+1
	symbol_maker	's2',vect_sreg+2
	symbol_maker	's3',vect_sreg+3
	symbol_maker	's4',vect_sreg+4
	symbol_maker	's5',vect_sreg+5
	symbol_maker	's6',vect_sreg+6
	symbol_maker	's7',vect_sreg+7
	symbol_maker	's8',vect_sreg+8
	symbol_maker	's9',vect_sreg+9
	symbol_maker	'sb',base_reg+9
	symbol_maker	'sl',base_reg+10
	symbol_maker	'sp',base_reg+13
	symbol_maker	'st',barrier+1110b
	symbol_maker	'sy',barrier+1111b
	symbol_maker	'v1',base_reg+4
	symbol_maker	'v2',base_reg+5
	symbol_maker	'v3',base_reg+6
	symbol_maker	'v4',base_reg+7
	symbol_maker	'v5',base_reg+8
	symbol_maker	'v6',base_reg+9
	symbol_maker	'v7',base_reg+10
	symbol_maker	'v8',base_reg+11
	symbol_maker	'vc',condition+0x7
	symbol_maker	'vs',condition+0x6
	symbol_maker	'w0',word_reg+0
	symbol_maker	'w1',word_reg+1
	symbol_maker	'w2',word_reg+2
	symbol_maker	'w3',word_reg+3
	symbol_maker	'w4',word_reg+4
	symbol_maker	'w5',word_reg+5
	symbol_maker	'w6',word_reg+6
	symbol_maker	'w7',word_reg+7
	symbol_maker	'w8',word_reg+8
	symbol_maker	'w9',word_reg+9
	symbol_maker	'x0',dword_reg+0
	symbol_maker	'x1',dword_reg+1
	symbol_maker	'x2',dword_reg+2
	symbol_maker	'x3',dword_reg+3
	symbol_maker	'x4',dword_reg+4
	symbol_maker	'x5',dword_reg+5
	symbol_maker	'x6',dword_reg+6
	symbol_maker	'x7',dword_reg+7
	symbol_maker	'x8',dword_reg+8
	symbol_maker	'x9',dword_reg+9
symbols_3:
	symbol_maker	'a1!',base_reg!+0
	symbol_maker	'a2!',base_reg!+1
	symbol_maker	'a3!',base_reg!+2
	symbol_maker	'a4!',base_reg!+3
	symbol_maker	'asr',shift_op+2
	symbol_maker	'b10',vect_breg+10
	symbol_maker	'b11',vect_breg+11
	symbol_maker	'b12',vect_breg+12
	symbol_maker	'b13',vect_breg+13
	symbol_maker	'b14',vect_breg+14
	symbol_maker	'b15',vect_breg+15
	symbol_maker	'b16',vect_breg+16
	symbol_maker	'b17',vect_breg+17
	symbol_maker	'b18',vect_breg+18
	symbol_maker	'b19',vect_breg+19
	symbol_maker	'b20',vect_breg+20
	symbol_maker	'b21',vect_breg+21
	symbol_maker	'b22',vect_breg+22
	symbol_maker	'b23',vect_breg+23
	symbol_maker	'b24',vect_breg+24
	symbol_maker	'b25',vect_breg+25
	symbol_maker	'b26',vect_breg+26
	symbol_maker	'b27',vect_breg+27
	symbol_maker	'b28',vect_breg+28
	symbol_maker	'b29',vect_breg+29
	symbol_maker	'b30',vect_breg+30
	symbol_maker	'b31',vect_breg+31
	symbol_maker	'c10',cpro_reg+10
	symbol_maker	'c11',cpro_reg+11
	symbol_maker	'c12',cpro_reg+12
	symbol_maker	'c13',cpro_reg+13
	symbol_maker	'c14',cpro_reg+14
	symbol_maker	'c15',cpro_reg+15
	symbol_maker	'csw',sys_dc+(sys_encode_csw-sys_encode_table_dc) shr 1
	symbol_maker	'd10',vect_dreg+10
	symbol_maker	'd11',vect_dreg+11
	symbol_maker	'd12',vect_dreg+12
	symbol_maker	'd13',vect_dreg+13
	symbol_maker	'd14',vect_dreg+14
	symbol_maker	'd15',vect_dreg+15
	symbol_maker	'd16',vect_dreg+16
	symbol_maker	'd17',vect_dreg+17
	symbol_maker	'd18',vect_dreg+18
	symbol_maker	'd19',vect_dreg+19
	symbol_maker	'd20',vect_dreg+20
	symbol_maker	'd21',vect_dreg+21
	symbol_maker	'd22',vect_dreg+22
	symbol_maker	'd23',vect_dreg+23
	symbol_maker	'd24',vect_dreg+24
	symbol_maker	'd25',vect_dreg+25
	symbol_maker	'd26',vect_dreg+26
	symbol_maker	'd27',vect_dreg+27
	symbol_maker	'd28',vect_dreg+28
	symbol_maker	'd29',vect_dreg+29
	symbol_maker	'd30',vect_dreg+30
	symbol_maker	'd31',vect_dreg+31
	symbol_maker	'dll',1Bh shl 8 + 80h
	symbol_maker	'efi',1Bh shl 10
	symbol_maker	'elf',18h shl 8 + 50h
	symbol_maker	'fp!',base_reg!+11
	symbol_maker	'gui',1Bh shl 8 + 9
	symbol_maker	'h10',vect_hreg+10
	symbol_maker	'h11',vect_hreg+11
	symbol_maker	'h12',vect_hreg+12
	symbol_maker	'h13',vect_hreg+13
	symbol_maker	'h14',vect_hreg+14
	symbol_maker	'h15',vect_hreg+15
	symbol_maker	'h16',vect_hreg+16
	symbol_maker	'h17',vect_hreg+17
	symbol_maker	'h18',vect_hreg+18
	symbol_maker	'h19',vect_hreg+19
	symbol_maker	'h20',vect_hreg+20
	symbol_maker	'h21',vect_hreg+21
	symbol_maker	'h22',vect_hreg+22
	symbol_maker	'h23',vect_hreg+23
	symbol_maker	'h24',vect_hreg+24
	symbol_maker	'h25',vect_hreg+25
	symbol_maker	'h26',vect_hreg+26
	symbol_maker	'h27',vect_hreg+27
	symbol_maker	'h28',vect_hreg+28
	symbol_maker	'h29',vect_hreg+29
	symbol_maker	'h30',vect_hreg+30
	symbol_maker	'h31',vect_hreg+31
	symbol_maker	'ip!',base_reg!+12
	symbol_maker	'ish',barrier+1011b
	symbol_maker	'isw',sys_dc+(sys_encode_isw-sys_encode_table_dc) shr 1
	symbol_maker	'lr!',base_reg!+14
	symbol_maker	'lsl',shift_op+0
	symbol_maker	'lsr',shift_op+1
	symbol_maker	'msl',msl_op+0
	symbol_maker	'msp',sysm_reg+8
	symbol_maker	'nsh',barrier+0111b
	symbol_maker	'osh',barrier+0011b
	symbol_maker	'p10',cpro_sel+10
	symbol_maker	'p11',cpro_sel+11
	symbol_maker	'p12',cpro_sel+12
	symbol_maker	'p13',cpro_sel+13
	symbol_maker	'p14',cpro_sel+14
	symbol_maker	'p15',cpro_sel+15
	symbol_maker	'pc!',base_reg!+15
	symbol_maker	'psp',sysm_reg+9
	symbol_maker	'q10',vect_qreg+10
	symbol_maker	'q11',vect_qreg+11
	symbol_maker	'q12',vect_qreg+12
	symbol_maker	'q13',vect_qreg+13
	symbol_maker	'q14',vect_qreg+14
	symbol_maker	'q15',vect_qreg+15
	symbol_maker	'q16',vect_qreg+16
	symbol_maker	'q17',vect_qreg+17
	symbol_maker	'q18',vect_qreg+18
	symbol_maker	'q19',vect_qreg+19
	symbol_maker	'q20',vect_qreg+20
	symbol_maker	'q21',vect_qreg+21
	symbol_maker	'q22',vect_qreg+22
	symbol_maker	'q23',vect_qreg+23
	symbol_maker	'q24',vect_qreg+24
	symbol_maker	'q25',vect_qreg+25
	symbol_maker	'q26',vect_qreg+26
	symbol_maker	'q27',vect_qreg+27
	symbol_maker	'q28',vect_qreg+28
	symbol_maker	'q29',vect_qreg+29
	symbol_maker	'q30',vect_qreg+30
	symbol_maker	'q31',vect_qreg+31
	symbol_maker	'r0!',base_reg!+0
	symbol_maker	'r1!',base_reg!+1
	symbol_maker	'r10',base_reg+10
	symbol_maker	'r11',base_reg+11
	symbol_maker	'r12',base_reg+12
	symbol_maker	'r13',base_reg+13
	symbol_maker	'r14',base_reg+14
	symbol_maker	'r15',base_reg+15
	symbol_maker	'r2!',base_reg!+2
	symbol_maker	'r3!',base_reg!+3
	symbol_maker	'r4!',base_reg!+4
	symbol_maker	'r5!',base_reg!+5
	symbol_maker	'r6!',base_reg!+6
	symbol_maker	'r7!',base_reg!+7
	symbol_maker	'r8!',base_reg!+8
	symbol_maker	'r9!',base_reg!+9
	symbol_maker	'ror',shift_op+3
	symbol_maker	'rrx',rrx_op+0
	symbol_maker	's10',vect_sreg+10
	symbol_maker	's11',vect_sreg+11
	symbol_maker	's12',vect_sreg+12
	symbol_maker	's13',vect_sreg+13
	symbol_maker	's14',vect_sreg+14
	symbol_maker	's15',vect_sreg+15
	symbol_maker	's16',vect_sreg+16
	symbol_maker	's17',vect_sreg+17
	symbol_maker	's18',vect_sreg+18
	symbol_maker	's19',vect_sreg+19
	symbol_maker	's20',vect_sreg+20
	symbol_maker	's21',vect_sreg+21
	symbol_maker	's22',vect_sreg+22
	symbol_maker	's23',vect_sreg+23
	symbol_maker	's24',vect_sreg+24
	symbol_maker	's25',vect_sreg+25
	symbol_maker	's26',vect_sreg+26
	symbol_maker	's27',vect_sreg+27
	symbol_maker	's28',vect_sreg+28
	symbol_maker	's29',vect_sreg+29
	symbol_maker	's30',vect_sreg+30
	symbol_maker	's31',vect_sreg+31
	symbol_maker	'sb!',base_reg!+9
	symbol_maker	'sl!',base_reg!+10
	symbol_maker	'sp!',base_reg!+13
	symbol_maker	'v1!',base_reg!+4
	symbol_maker	'v2!',base_reg!+5
	symbol_maker	'v3!',base_reg!+6
	symbol_maker	'v4!',base_reg!+7
	symbol_maker	'v5!',base_reg!+8
	symbol_maker	'v6!',base_reg!+9
	symbol_maker	'v7!',base_reg!+10
	symbol_maker	'v8!',base_reg!+11
	symbol_maker	'w10',word_reg+10
	symbol_maker	'w11',word_reg+11
	symbol_maker	'w12',word_reg+12
	symbol_maker	'w13',word_reg+13
	symbol_maker	'w14',word_reg+14
	symbol_maker	'w15',word_reg+15
	symbol_maker	'w16',word_reg+16
	symbol_maker	'w17',word_reg+17
	symbol_maker	'w18',word_reg+18
	symbol_maker	'w19',word_reg+19
	symbol_maker	'w20',word_reg+20
	symbol_maker	'w21',word_reg+21
	symbol_maker	'w22',word_reg+22
	symbol_maker	'w23',word_reg+23
	symbol_maker	'w24',word_reg+24
	symbol_maker	'w25',word_reg+25
	symbol_maker	'w26',word_reg+26
	symbol_maker	'w27',word_reg+27
	symbol_maker	'w28',word_reg+28
	symbol_maker	'w29',word_reg+29
	symbol_maker	'w30',word_reg+30
	symbol_maker	'wdm',1Bh shl 8 + 81h
	symbol_maker	'wr0',iwmmx_wreg+0
	symbol_maker	'wr1',iwmmx_wreg+1
	symbol_maker	'wr2',iwmmx_wreg+2
	symbol_maker	'wr3',iwmmx_wreg+3
	symbol_maker	'wr4',iwmmx_wreg+4
	symbol_maker	'wr5',iwmmx_wreg+5
	symbol_maker	'wr6',iwmmx_wreg+6
	symbol_maker	'wr7',iwmmx_wreg+7
	symbol_maker	'wr8',iwmmx_wreg+8
	symbol_maker	'wr9',iwmmx_wreg+9
	symbol_maker	'wsp',word_reg+32
	symbol_maker	'wzr',word_reg+31
	symbol_maker	'x10',dword_reg+10
	symbol_maker	'x11',dword_reg+11
	symbol_maker	'x12',dword_reg+12
	symbol_maker	'x13',dword_reg+13
	symbol_maker	'x14',dword_reg+14
	symbol_maker	'x15',dword_reg+15
	symbol_maker	'x16',dword_reg+16
	symbol_maker	'x17',dword_reg+17
	symbol_maker	'x18',dword_reg+18
	symbol_maker	'x19',dword_reg+19
	symbol_maker	'x20',dword_reg+20
	symbol_maker	'x21',dword_reg+21
	symbol_maker	'x22',dword_reg+22
	symbol_maker	'x23',dword_reg+23
	symbol_maker	'x24',dword_reg+24
	symbol_maker	'x25',dword_reg+25
	symbol_maker	'x26',dword_reg+26
	symbol_maker	'x27',dword_reg+27
	symbol_maker	'x28',dword_reg+28
	symbol_maker	'x29',dword_reg+29
	symbol_maker	'x30',dword_reg+30
	symbol_maker	'xzr',dword_reg+31
	symbol_maker	'zva',sys_dc+(sys_encode_zva-sys_encode_table_dc) shr 1
symbols_4:
	symbol_maker	'acc0',acc_40bt+0
	symbol_maker	'acc1',acc_40bt+1
	symbol_maker	'acc2',acc_40bt+2
	symbol_maker	'acc3',acc_40bt+3
	symbol_maker	'acc4',acc_40bt+4
	symbol_maker	'acc5',acc_40bt+5
	symbol_maker	'acc6',acc_40bt+6
	symbol_maker	'acc7',acc_40bt+7
	symbol_maker	'apsr',psr_reg+34
	symbol_maker	'byte',size_opr+1
	symbol_maker	'cisw',sys_dc+(sys_encode_cisw-sys_encode_table_dc) shr 1
	symbol_maker	'code',19h shl 8 + 5
	symbol_maker	'coff',18h shl 8 + 40h
	symbol_maker	'cpsr',psr_reg+32
	symbol_maker	'cvac',sys_dc+(sys_encode_cvac-sys_encode_table_dc) shr 1
	symbol_maker	'cvau',sys_dc+(sys_encode_cvau-sys_encode_table_dc) shr 1
	symbol_maker	'daif',sys_msr+(sys_encode_daif-sys_encode_table_msr) shr 1
	symbol_maker	'data',19h shl 8 + 6
	symbol_maker	'epsr',sysm_reg+6
	symbol_maker	'fpcr',sys_msr+(sys_encode_fpcr-sys_encode_table_msr) shr 1
	symbol_maker	'fpsr',sys_msr+(sys_encode_fpsr-sys_encode_table_msr) shr 1
	symbol_maker	'ipsr',sysm_reg+5
	symbol_maker	'ivac',sys_dc+(sys_encode_ivac-sys_encode_table_dc) shr 1
	symbol_maker	'ivau',sys_ic+(sys_encode_ivau-sys_encode_table_ic) shr 1
	symbol_maker	'ms64',1Ch shl 8 + 49h
	symbol_maker	'note',1Eh shl 8 + 4
	symbol_maker	'nzcv',sys_msr+(sys_encode_nzcv-sys_encode_table_msr) shr 1
	symbol_maker	'pe64',18h shl 8 + 38h
	symbol_maker	'r10!',base_reg!+10
	symbol_maker	'r11!',base_reg!+11
	symbol_maker	'r12!',base_reg!+12
	symbol_maker	'r13!',base_reg!+13
	symbol_maker	'r14!',base_reg!+14
	symbol_maker	'r15!',base_reg!+15
	symbol_maker	'spsr',psr_reg+33
	symbol_maker	'sxtb',xtnd_op+4
	symbol_maker	'sxth',xtnd_op+5
	symbol_maker	'sxtw',xtnd_op+6
	symbol_maker	'sxtx',xtnd_op+7
	symbol_maker	'syst',barrier+1110b
	symbol_maker	'uxtb',xtnd_op+0
	symbol_maker	'uxth',xtnd_op+1
	symbol_maker	'uxtw',xtnd_op+2
	symbol_maker	'uxtx',xtnd_op+3
	symbol_maker	'v0.b',vect_vb+0
	symbol_maker	'v0.d',vect_vd+0
	symbol_maker	'v0.h',vect_vh+0
	symbol_maker	'v0.s',vect_vs+0
	symbol_maker	'v1.b',vect_vb+1
	symbol_maker	'v1.d',vect_vd+1
	symbol_maker	'v1.h',vect_vh+1
	symbol_maker	'v1.s',vect_vs+1
	symbol_maker	'v2.b',vect_vb+2
	symbol_maker	'v2.d',vect_vd+2
	symbol_maker	'v2.h',vect_vh+2
	symbol_maker	'v2.s',vect_vs+2
	symbol_maker	'v3.b',vect_vb+3
	symbol_maker	'v3.d',vect_vd+3
	symbol_maker	'v3.h',vect_vh+3
	symbol_maker	'v3.s',vect_vs+3
	symbol_maker	'v4.b',vect_vb+4
	symbol_maker	'v4.d',vect_vd+4
	symbol_maker	'v4.h',vect_vh+4
	symbol_maker	'v4.s',vect_vs+4
	symbol_maker	'v5.b',vect_vb+5
	symbol_maker	'v5.d',vect_vd+5
	symbol_maker	'v5.h',vect_vh+5
	symbol_maker	'v5.s',vect_vs+5
	symbol_maker	'v6.b',vect_vb+6
	symbol_maker	'v6.d',vect_vd+6
	symbol_maker	'v6.h',vect_vh+6
	symbol_maker	'v6.s',vect_vs+6
	symbol_maker	'v7.b',vect_vb+7
	symbol_maker	'v7.d',vect_vd+7
	symbol_maker	'v7.h',vect_vh+7
	symbol_maker	'v7.s',vect_vs+7
	symbol_maker	'v8.b',vect_vb+8
	symbol_maker	'v8.d',vect_vd+8
	symbol_maker	'v8.h',vect_vh+8
	symbol_maker	'v8.s',vect_vs+8
	symbol_maker	'v9.b',vect_vb+9
	symbol_maker	'v9.d',vect_vd+9
	symbol_maker	'v9.h',vect_vh+9
	symbol_maker	'v9.s',vect_vs+9
	symbol_maker	'vae1',sys_tlbi+(sys_encode_vae1-sys_encode_table_tlbi) shr 1
	symbol_maker	'vae2',sys_tlbi+(sys_encode_vae2-sys_encode_table_tlbi) shr 1
	symbol_maker	'vae3',sys_tlbi+(sys_encode_vae3-sys_encode_table_tlbi) shr 1
	symbol_maker	'wcid',iwmmx_creg+0
	symbol_maker	'wcon',iwmmx_creg+1
	symbol_maker	'word',size_opr+4
	symbol_maker	'wr10',iwmmx_wreg+10
	symbol_maker	'wr11',iwmmx_wreg+11
	symbol_maker	'wr12',iwmmx_wreg+12
	symbol_maker	'wr13',iwmmx_wreg+13
	symbol_maker	'wr14',iwmmx_wreg+14
	symbol_maker	'wr15',iwmmx_wreg+15
	symbol_maker	'xpsr',sysm_reg+3
symbols_5:
	symbol_maker	'alle1',sys_tlbi+(sys_encode_alle1-sys_encode_table_tlbi) shr 1
	symbol_maker	'alle2',sys_tlbi+(sys_encode_alle2-sys_encode_table_tlbi) shr 1
	symbol_maker	'alle3',sys_tlbi+(sys_encode_alle3-sys_encode_table_tlbi) shr 1
	symbol_maker	'civac',sys_dc+(sys_encode_civac-sys_encode_table_dc) shr 1
	symbol_maker	'dspsc',mvrk_psc+0
	symbol_maker	'dwarf',19h shl 8 + 0C0h
	symbol_maker	'dword',size_opr+8
	symbol_maker	'eapsr',sysm_reg+2
	symbol_maker	'elf64',18h shl 8 + 58h
	symbol_maker	'fpexc',vfp_syst+8
	symbol_maker	'fpscr',vfp_syst+1
	symbol_maker	'fpsid',vfp_syst+0
	symbol_maker	'hword',size_opr+2
	symbol_maker	'iallu',sys_ic+(sys_encode_iallu-sys_encode_table_ic) shr 1
	symbol_maker	'iapsr',sysm_reg+1
	symbol_maker	'iepsr',sysm_reg+7
	symbol_maker	'ishld',barrier+1001b
	symbol_maker	'ishst',barrier+1010b
	symbol_maker	'large',1Bh shl 8 + 82h
	symbol_maker	'mvfr0',vfp_syst+7
	symbol_maker	'mvfr1',vfp_syst+6
	symbol_maker	'nshld',barrier+0101b
	symbol_maker	'nshst',barrier+0110b
	symbol_maker	'oshld',barrier+0001b
	symbol_maker	'oshst',barrier+0010b
	symbol_maker	'qword',size_opr+16
	symbol_maker	'r0@16',base_@16+0
	symbol_maker	'r0@32',base_@32+0
	symbol_maker	'r0@64',base_@64+0
	symbol_maker	'r1@16',base_@16+1
	symbol_maker	'r1@32',base_@32+1
	symbol_maker	'r1@64',base_@64+1
	symbol_maker	'r2@16',base_@16+2
	symbol_maker	'r2@32',base_@32+2
	symbol_maker	'r2@64',base_@64+2
	symbol_maker	'r3@16',base_@16+3
	symbol_maker	'r3@32',base_@32+3
	symbol_maker	'r3@64',base_@64+3
	symbol_maker	'r4@16',base_@16+4
	symbol_maker	'r4@32',base_@32+4
	symbol_maker	'r4@64',base_@64+4
	symbol_maker	'r5@16',base_@16+5
	symbol_maker	'r5@32',base_@32+5
	symbol_maker	'r5@64',base_@64+5
	symbol_maker	'r6@16',base_@16+6
	symbol_maker	'r6@32',base_@32+6
	symbol_maker	'r6@64',base_@64+6
	symbol_maker	'r7@16',base_@16+7
	symbol_maker	'r7@32',base_@32+7
	symbol_maker	'r7@64',base_@64+7
	symbol_maker	'r8@16',base_@16+8
	symbol_maker	'r8@32',base_@32+8
	symbol_maker	'r8@64',base_@64+8
	symbol_maker	'r9@16',base_@16+9
	symbol_maker	'r9@32',base_@32+9
	symbol_maker	'r9@64',base_@64+9
	symbol_maker	's1e0r',sys_at+(sys_encode_s1e0r-sys_encode_table_at) shr 1
	symbol_maker	's1e0w',sys_at+(sys_encode_s1e0w-sys_encode_table_at) shr 1
	symbol_maker	's1e1r',sys_at+(sys_encode_s1e1r-sys_encode_table_at) shr 1
	symbol_maker	's1e1w',sys_at+(sys_encode_s1e1w-sys_encode_table_at) shr 1
	symbol_maker	's1e2r',sys_at+(sys_encode_s1e2r-sys_encode_table_at) shr 1
	symbol_maker	's1e2w',sys_at+(sys_encode_s1e2w-sys_encode_table_at) shr 1
	symbol_maker	's1e3r',sys_at+(sys_encode_s1e3r-sys_encode_table_at) shr 1
	symbol_maker	's1e3w',sys_at+(sys_encode_s1e3w-sys_encode_table_at) shr 1
	symbol_maker	'spsel',sys_msr+(sys_encode_spsel-sys_encode_table_msr) shr 1
;;	symbol_maker	'spsel',sys_pstate+(sys_pencode_spsel-sys_encode_table_pstate) shr 1
	symbol_maker	'v0.1d',vect_v1d+0
	symbol_maker	'v0.1q',vect_v1q+0
	symbol_maker	'v0.2d',vect_v2d+0
	symbol_maker	'v0.2s',vect_v2s+0
	symbol_maker	'v0.4h',vect_v4h+0
	symbol_maker	'v0.4s',vect_v4s+0
	symbol_maker	'v0.8b',vect_v8b+0
	symbol_maker	'v0.8h',vect_v8h+0
	symbol_maker	'v1.1d',vect_v1d+1
	symbol_maker	'v1.1q',vect_v1q+1
	symbol_maker	'v1.2d',vect_v2d+1
	symbol_maker	'v1.2s',vect_v2s+1
	symbol_maker	'v1.4h',vect_v4h+1
	symbol_maker	'v1.4s',vect_v4s+1
	symbol_maker	'v1.8b',vect_v8b+1
	symbol_maker	'v1.8h',vect_v8h+1
	symbol_maker	'v10.b',vect_vb+10
	symbol_maker	'v10.d',vect_vd+10
	symbol_maker	'v10.h',vect_vh+10
	symbol_maker	'v10.s',vect_vs+10
	symbol_maker	'v11.b',vect_vb+11
	symbol_maker	'v11.d',vect_vd+11
	symbol_maker	'v11.h',vect_vh+11
	symbol_maker	'v11.s',vect_vs+11
	symbol_maker	'v12.b',vect_vb+12
	symbol_maker	'v12.d',vect_vd+12
	symbol_maker	'v12.h',vect_vh+12
	symbol_maker	'v12.s',vect_vs+12
	symbol_maker	'v13.b',vect_vb+13
	symbol_maker	'v13.d',vect_vd+13
	symbol_maker	'v13.h',vect_vh+13
	symbol_maker	'v13.s',vect_vs+13
	symbol_maker	'v14.b',vect_vb+14
	symbol_maker	'v14.d',vect_vd+14
	symbol_maker	'v14.h',vect_vh+14
	symbol_maker	'v14.s',vect_vs+14
	symbol_maker	'v15.b',vect_vb+15
	symbol_maker	'v15.d',vect_vd+15
	symbol_maker	'v15.h',vect_vh+15
	symbol_maker	'v15.s',vect_vs+15
	symbol_maker	'v16.b',vect_vb+16
	symbol_maker	'v16.d',vect_vd+16
	symbol_maker	'v16.h',vect_vh+16
	symbol_maker	'v16.s',vect_vs+16
	symbol_maker	'v17.b',vect_vb+17
	symbol_maker	'v17.d',vect_vd+17
	symbol_maker	'v17.h',vect_vh+17
	symbol_maker	'v17.s',vect_vs+17
	symbol_maker	'v18.b',vect_vb+18
	symbol_maker	'v18.d',vect_vd+18
	symbol_maker	'v18.h',vect_vh+18
	symbol_maker	'v18.s',vect_vs+18
	symbol_maker	'v19.b',vect_vb+19
	symbol_maker	'v19.d',vect_vd+19
	symbol_maker	'v19.h',vect_vh+19
	symbol_maker	'v19.s',vect_vs+19
	symbol_maker	'v2.1d',vect_v1d+2
	symbol_maker	'v2.1q',vect_v1q+2
	symbol_maker	'v2.2d',vect_v2d+2
	symbol_maker	'v2.2s',vect_v2s+2
	symbol_maker	'v2.4h',vect_v4h+2
	symbol_maker	'v2.4s',vect_v4s+2
	symbol_maker	'v2.8b',vect_v8b+2
	symbol_maker	'v2.8h',vect_v8h+2
	symbol_maker	'v20.b',vect_vb+20
	symbol_maker	'v20.d',vect_vd+20
	symbol_maker	'v20.h',vect_vh+20
	symbol_maker	'v20.s',vect_vs+20
	symbol_maker	'v21.b',vect_vb+21
	symbol_maker	'v21.d',vect_vd+21
	symbol_maker	'v21.h',vect_vh+21
	symbol_maker	'v21.s',vect_vs+21
	symbol_maker	'v22.b',vect_vb+22
	symbol_maker	'v22.d',vect_vd+22
	symbol_maker	'v22.h',vect_vh+22
	symbol_maker	'v22.s',vect_vs+22
	symbol_maker	'v23.b',vect_vb+23
	symbol_maker	'v23.d',vect_vd+23
	symbol_maker	'v23.h',vect_vh+23
	symbol_maker	'v23.s',vect_vs+23
	symbol_maker	'v24.b',vect_vb+24
	symbol_maker	'v24.d',vect_vd+24
	symbol_maker	'v24.h',vect_vh+24
	symbol_maker	'v24.s',vect_vs+24
	symbol_maker	'v25.b',vect_vb+25
	symbol_maker	'v25.d',vect_vd+25
	symbol_maker	'v25.h',vect_vh+25
	symbol_maker	'v25.s',vect_vs+25
	symbol_maker	'v26.b',vect_vb+26
	symbol_maker	'v26.d',vect_vd+26
	symbol_maker	'v26.h',vect_vh+26
	symbol_maker	'v26.s',vect_vs+26
	symbol_maker	'v27.b',vect_vb+27
	symbol_maker	'v27.d',vect_vd+27
	symbol_maker	'v27.h',vect_vh+27
	symbol_maker	'v27.s',vect_vs+27
	symbol_maker	'v28.b',vect_vb+28
	symbol_maker	'v28.d',vect_vd+28
	symbol_maker	'v28.h',vect_vh+28
	symbol_maker	'v28.s',vect_vs+28
	symbol_maker	'v29.b',vect_vb+29
	symbol_maker	'v29.d',vect_vd+29
	symbol_maker	'v29.h',vect_vh+29
	symbol_maker	'v29.s',vect_vs+29
	symbol_maker	'v3.1d',vect_v1d+3
	symbol_maker	'v3.1q',vect_v1q+3
	symbol_maker	'v3.2d',vect_v2d+3
	symbol_maker	'v3.2s',vect_v2s+3
	symbol_maker	'v3.4h',vect_v4h+3
	symbol_maker	'v3.4s',vect_v4s+3
	symbol_maker	'v3.8b',vect_v8b+3
	symbol_maker	'v3.8h',vect_v8h+3
	symbol_maker	'v30.b',vect_vb+30
	symbol_maker	'v30.d',vect_vd+30
	symbol_maker	'v30.h',vect_vh+30
	symbol_maker	'v30.s',vect_vs+30
	symbol_maker	'v31.b',vect_vb+31
	symbol_maker	'v31.d',vect_vd+31
	symbol_maker	'v31.h',vect_vh+31
	symbol_maker	'v31.s',vect_vs+31
	symbol_maker	'v4.1d',vect_v1d+4
	symbol_maker	'v4.1q',vect_v1q+4
	symbol_maker	'v4.2d',vect_v2d+4
	symbol_maker	'v4.2s',vect_v2s+4
	symbol_maker	'v4.4h',vect_v4h+4
	symbol_maker	'v4.4s',vect_v4s+4
	symbol_maker	'v4.8b',vect_v8b+4
	symbol_maker	'v4.8h',vect_v8h+4
	symbol_maker	'v5.1d',vect_v1d+5
	symbol_maker	'v5.1q',vect_v1q+5
	symbol_maker	'v5.2d',vect_v2d+5
	symbol_maker	'v5.2s',vect_v2s+5
	symbol_maker	'v5.4h',vect_v4h+5
	symbol_maker	'v5.4s',vect_v4s+5
	symbol_maker	'v5.8b',vect_v8b+5
	symbol_maker	'v5.8h',vect_v8h+5
	symbol_maker	'v6.1d',vect_v1d+6
	symbol_maker	'v6.1q',vect_v1q+6
	symbol_maker	'v6.2d',vect_v2d+6
	symbol_maker	'v6.2s',vect_v2s+6
	symbol_maker	'v6.4h',vect_v4h+6
	symbol_maker	'v6.4s',vect_v4s+6
	symbol_maker	'v6.8b',vect_v8b+6
	symbol_maker	'v6.8h',vect_v8h+6
	symbol_maker	'v7.1d',vect_v1d+7
	symbol_maker	'v7.1q',vect_v1q+7
	symbol_maker	'v7.2d',vect_v2d+7
	symbol_maker	'v7.2s',vect_v2s+7
	symbol_maker	'v7.4h',vect_v4h+7
	symbol_maker	'v7.4s',vect_v4s+7
	symbol_maker	'v7.8b',vect_v8b+7
	symbol_maker	'v7.8h',vect_v8h+7
	symbol_maker	'v8.1d',vect_v1d+8
	symbol_maker	'v8.1q',vect_v1q+8
	symbol_maker	'v8.2d',vect_v2d+8
	symbol_maker	'v8.2s',vect_v2s+8
	symbol_maker	'v8.4h',vect_v4h+8
	symbol_maker	'v8.4s',vect_v4s+8
	symbol_maker	'v8.8b',vect_v8b+8
	symbol_maker	'v8.8h',vect_v8h+8
	symbol_maker	'v9.1d',vect_v1d+9
	symbol_maker	'v9.1q',vect_v1q+9
	symbol_maker	'v9.2d',vect_v2d+9
	symbol_maker	'v9.2s',vect_v2s+9
	symbol_maker	'v9.4h',vect_v4h+9
	symbol_maker	'v9.4s',vect_v4s+9
	symbol_maker	'v9.8b',vect_v8b+9
	symbol_maker	'v9.8h',vect_v8h+9
	symbol_maker	'vaae1',sys_tlbi+(sys_encode_vaae1-sys_encode_table_tlbi) shr 1
	symbol_maker	'vale1',sys_tlbi+(sys_encode_vale1-sys_encode_table_tlbi) shr 1
	symbol_maker	'vale2',sys_tlbi+(sys_encode_vale2-sys_encode_table_tlbi) shr 1
	symbol_maker	'vale3',sys_tlbi+(sys_encode_vale3-sys_encode_table_tlbi) shr 1
	symbol_maker	'wcasf',iwmmx_creg+3
	symbol_maker	'wcgr0',iwmmx_creg+8
	symbol_maker	'wcgr1',iwmmx_creg+9
	symbol_maker	'wcgr2',iwmmx_creg+10
	symbol_maker	'wcgr3',iwmmx_creg+11
	symbol_maker	'wcssf',iwmmx_creg+2
symbols_6:
	symbol_maker	'apsr_g',psr_reg+4
	symbol_maker	'aside1',sys_tlbi+(sys_encode_aside1-sys_encode_table_tlbi) shr 1
	symbol_maker	'binary',18h shl 8 + 10h
	symbol_maker	'cpsr_c',psr_reg+1
	symbol_maker	'cpsr_f',psr_reg+8
	symbol_maker	'cpsr_s',psr_reg+4
	symbol_maker	'cpsr_x',psr_reg+2
	symbol_maker	'dqword',size_opr+32
	symbol_maker	'export',1Ah shl 8 + 0
	symbol_maker	'fixups',1Ah shl 8 + 5
	symbol_maker	'fpinst',vfp_syst+9
	symbol_maker	'import',1Ah shl 8 + 1
	symbol_maker	'lr_abt',banked_reg+20
	symbol_maker	'lr_fiq',banked_reg+14
	symbol_maker	'lr_irq',banked_reg+16
	symbol_maker	'lr_mon',banked_reg+28
	symbol_maker	'lr_svc',banked_reg+18
	symbol_maker	'lr_und',banked_reg+22
	symbol_maker	'lr_usr',banked_reg+6
	symbol_maker	'native',1Bh shl 8 + 1
	symbol_maker	'r0@128',base_@128+0
	symbol_maker	'r0@256',base_@256+0
	symbol_maker	'r10@16',base_@16+10
	symbol_maker	'r10@32',base_@32+10
	symbol_maker	'r10@64',base_@64+10
	symbol_maker	'r11@16',base_@16+11
	symbol_maker	'r11@32',base_@32+11
	symbol_maker	'r11@64',base_@64+11
	symbol_maker	'r12@16',base_@16+12
	symbol_maker	'r12@32',base_@32+12
	symbol_maker	'r12@64',base_@64+12
	symbol_maker	'r13@16',base_@16+13
	symbol_maker	'r13@32',base_@32+13
	symbol_maker	'r13@64',base_@64+13
	symbol_maker	'r14@16',base_@16+14
	symbol_maker	'r14@32',base_@32+14
	symbol_maker	'r14@64',base_@64+14
	symbol_maker	'r15@16',base_@16+15
	symbol_maker	'r15@32',base_@32+15
	symbol_maker	'r15@64',base_@64+15
	symbol_maker	'r1@128',base_@128+1
	symbol_maker	'r1@256',base_@256+1
	symbol_maker	'r2@128',base_@128+2
	symbol_maker	'r2@256',base_@256+2
	symbol_maker	'r3@128',base_@128+3
	symbol_maker	'r3@256',base_@256+3
	symbol_maker	'r4@128',base_@128+4
	symbol_maker	'r4@256',base_@256+4
	symbol_maker	'r5@128',base_@128+5
	symbol_maker	'r5@256',base_@256+5
	symbol_maker	'r6@128',base_@128+6
	symbol_maker	'r6@256',base_@256+6
	symbol_maker	'r7@128',base_@128+7
	symbol_maker	'r7@256',base_@256+7
	symbol_maker	'r8@128',base_@128+8
	symbol_maker	'r8@256',base_@256+8
	symbol_maker	'r8_fiq',banked_reg+8
	symbol_maker	'r8_usr',banked_reg+0
	symbol_maker	'r9@128',base_@128+9
	symbol_maker	'r9@256',base_@256+9
	symbol_maker	'r9_fiq',banked_reg+9
	symbol_maker	'r9_usr',banked_reg+1
	symbol_maker	's12e0r',sys_at+(sys_encode_s12e0r-sys_encode_table_at) shr 1
	symbol_maker	's12e0w',sys_at+(sys_encode_s12e0w-sys_encode_table_at) shr 1
	symbol_maker	's12e1r',sys_at+(sys_encode_s12e1r-sys_encode_table_at) shr 1
	symbol_maker	's12e1w',sys_at+(sys_encode_s12e1w-sys_encode_table_at) shr 1
	symbol_maker	'sp_abt',banked_reg+21
	symbol_maker	'sp_el0',sys_msr+(sys_encode_sp_el0-sys_encode_table_msr) shr 1
	symbol_maker	'sp_el1',sys_msr+(sys_encode_sp_el1-sys_encode_table_msr) shr 1
	symbol_maker	'sp_el2',sys_msr+(sys_encode_sp_el2-sys_encode_table_msr) shr 1
	symbol_maker	'sp_fiq',banked_reg+13
	symbol_maker	'sp_hyp',banked_reg+31
	symbol_maker	'sp_irq',banked_reg+17
	symbol_maker	'sp_mon',banked_reg+29
	symbol_maker	'sp_svc',banked_reg+19
	symbol_maker	'sp_und',banked_reg+23
	symbol_maker	'sp_usr',banked_reg+5
	symbol_maker	'spsr_c',psr_reg+1
	symbol_maker	'spsr_f',psr_reg+8
	symbol_maker	'spsr_s',psr_reg+4
	symbol_maker	'spsr_x',psr_reg+2
	symbol_maker	'static',1Dh shl 8 + 1
	symbol_maker	'v0.16b',vect_v16b+0
	symbol_maker	'v1.16b',vect_v16b+1
	symbol_maker	'v10.1d',vect_v1d+10
	symbol_maker	'v10.1q',vect_v1q+20
	symbol_maker	'v10.2d',vect_v2d+10
	symbol_maker	'v10.2s',vect_v2s+10
	symbol_maker	'v10.4h',vect_v4h+10
	symbol_maker	'v10.4s',vect_v4s+10
	symbol_maker	'v10.8b',vect_v8b+10
	symbol_maker	'v10.8h',vect_v8h+10
	symbol_maker	'v11.1d',vect_v1d+11
	symbol_maker	'v11.1q',vect_v1q+21
	symbol_maker	'v11.2d',vect_v2d+11
	symbol_maker	'v11.2s',vect_v2s+11
	symbol_maker	'v11.4h',vect_v4h+11
	symbol_maker	'v11.4s',vect_v4s+11
	symbol_maker	'v11.8b',vect_v8b+11
	symbol_maker	'v11.8h',vect_v8h+11
	symbol_maker	'v12.1d',vect_v1d+12
	symbol_maker	'v12.1q',vect_v1q+22
	symbol_maker	'v12.2d',vect_v2d+12
	symbol_maker	'v12.2s',vect_v2s+12
	symbol_maker	'v12.4h',vect_v4h+12
	symbol_maker	'v12.4s',vect_v4s+12
	symbol_maker	'v12.8b',vect_v8b+12
	symbol_maker	'v12.8h',vect_v8h+12
	symbol_maker	'v13.1d',vect_v1d+13
	symbol_maker	'v13.1q',vect_v1q+23
	symbol_maker	'v13.2d',vect_v2d+13
	symbol_maker	'v13.2s',vect_v2s+13
	symbol_maker	'v13.4h',vect_v4h+13
	symbol_maker	'v13.4s',vect_v4s+13
	symbol_maker	'v13.8b',vect_v8b+13
	symbol_maker	'v13.8h',vect_v8h+13
	symbol_maker	'v14.1d',vect_v1d+14
	symbol_maker	'v14.1q',vect_v1q+24
	symbol_maker	'v14.2d',vect_v2d+14
	symbol_maker	'v14.2s',vect_v2s+14
	symbol_maker	'v14.4h',vect_v4h+14
	symbol_maker	'v14.4s',vect_v4s+14
	symbol_maker	'v14.8b',vect_v8b+14
	symbol_maker	'v14.8h',vect_v8h+14
	symbol_maker	'v15.1d',vect_v1d+15
	symbol_maker	'v15.1q',vect_v1q+25
	symbol_maker	'v15.2d',vect_v2d+15
	symbol_maker	'v15.2s',vect_v2s+15
	symbol_maker	'v15.4h',vect_v4h+15
	symbol_maker	'v15.4s',vect_v4s+15
	symbol_maker	'v15.8b',vect_v8b+15
	symbol_maker	'v15.8h',vect_v8h+15
	symbol_maker	'v16.1d',vect_v1d+16
	symbol_maker	'v16.1q',vect_v1q+26
	symbol_maker	'v16.2d',vect_v2d+16
	symbol_maker	'v16.2s',vect_v2s+16
	symbol_maker	'v16.4h',vect_v4h+16
	symbol_maker	'v16.4s',vect_v4s+16
	symbol_maker	'v16.8b',vect_v8b+16
	symbol_maker	'v16.8h',vect_v8h+16
	symbol_maker	'v17.1d',vect_v1d+17
	symbol_maker	'v17.1q',vect_v1q+27
	symbol_maker	'v17.2d',vect_v2d+17
	symbol_maker	'v17.2s',vect_v2s+17
	symbol_maker	'v17.4h',vect_v4h+17
	symbol_maker	'v17.4s',vect_v4s+17
	symbol_maker	'v17.8b',vect_v8b+17
	symbol_maker	'v17.8h',vect_v8h+17
	symbol_maker	'v18.1d',vect_v1d+18
	symbol_maker	'v18.1q',vect_v1q+28
	symbol_maker	'v18.2d',vect_v2d+18
	symbol_maker	'v18.2s',vect_v2s+18
	symbol_maker	'v18.4h',vect_v4h+18
	symbol_maker	'v18.4s',vect_v4s+18
	symbol_maker	'v18.8b',vect_v8b+18
	symbol_maker	'v18.8h',vect_v8h+18
	symbol_maker	'v19.1d',vect_v1d+19
	symbol_maker	'v19.1q',vect_v1q+29
	symbol_maker	'v19.2d',vect_v2d+19
	symbol_maker	'v19.2s',vect_v2s+19
	symbol_maker	'v19.4h',vect_v4h+19
	symbol_maker	'v19.4s',vect_v4s+19
	symbol_maker	'v19.8b',vect_v8b+19
	symbol_maker	'v19.8h',vect_v8h+19
	symbol_maker	'v2.16b',vect_v16b+2
	symbol_maker	'v20.1d',vect_v1d+20
	symbol_maker	'v20.1q',vect_v1q+20
	symbol_maker	'v20.2d',vect_v2d+20
	symbol_maker	'v20.2s',vect_v2s+20
	symbol_maker	'v20.4h',vect_v4h+20
	symbol_maker	'v20.4s',vect_v4s+20
	symbol_maker	'v20.8b',vect_v8b+20
	symbol_maker	'v20.8h',vect_v8h+20
	symbol_maker	'v21.1d',vect_v1d+21
	symbol_maker	'v21.1q',vect_v1q+21
	symbol_maker	'v21.2d',vect_v2d+21
	symbol_maker	'v21.2s',vect_v2s+21
	symbol_maker	'v21.4h',vect_v4h+21
	symbol_maker	'v21.4s',vect_v4s+21
	symbol_maker	'v21.8b',vect_v8b+21
	symbol_maker	'v21.8h',vect_v8h+21
	symbol_maker	'v22.1d',vect_v1d+22
	symbol_maker	'v22.1q',vect_v1q+22
	symbol_maker	'v22.2d',vect_v2d+22
	symbol_maker	'v22.2s',vect_v2s+22
	symbol_maker	'v22.4h',vect_v4h+22
	symbol_maker	'v22.4s',vect_v4s+22
	symbol_maker	'v22.8b',vect_v8b+22
	symbol_maker	'v22.8h',vect_v8h+22
	symbol_maker	'v23.1d',vect_v1d+23
	symbol_maker	'v23.1q',vect_v1q+23
	symbol_maker	'v23.2d',vect_v2d+23
	symbol_maker	'v23.2s',vect_v2s+23
	symbol_maker	'v23.4h',vect_v4h+23
	symbol_maker	'v23.4s',vect_v4s+23
	symbol_maker	'v23.8b',vect_v8b+23
	symbol_maker	'v23.8h',vect_v8h+23
	symbol_maker	'v24.1d',vect_v1d+24
	symbol_maker	'v24.1q',vect_v1q+24
	symbol_maker	'v24.2d',vect_v2d+24
	symbol_maker	'v24.2s',vect_v2s+24
	symbol_maker	'v24.4h',vect_v4h+24
	symbol_maker	'v24.4s',vect_v4s+24
	symbol_maker	'v24.8b',vect_v8b+24
	symbol_maker	'v24.8h',vect_v8h+24
	symbol_maker	'v25.1d',vect_v1d+25
	symbol_maker	'v25.1q',vect_v1q+25
	symbol_maker	'v25.2d',vect_v2d+25
	symbol_maker	'v25.2s',vect_v2s+25
	symbol_maker	'v25.4h',vect_v4h+25
	symbol_maker	'v25.4s',vect_v4s+25
	symbol_maker	'v25.8b',vect_v8b+25
	symbol_maker	'v25.8h',vect_v8h+25
	symbol_maker	'v26.1d',vect_v1d+26
	symbol_maker	'v26.1q',vect_v1q+26
	symbol_maker	'v26.2d',vect_v2d+26
	symbol_maker	'v26.2s',vect_v2s+26
	symbol_maker	'v26.4h',vect_v4h+26
	symbol_maker	'v26.4s',vect_v4s+26
	symbol_maker	'v26.8b',vect_v8b+26
	symbol_maker	'v26.8h',vect_v8h+26
	symbol_maker	'v27.1d',vect_v1d+27
	symbol_maker	'v27.1q',vect_v1q+27
	symbol_maker	'v27.2d',vect_v2d+27
	symbol_maker	'v27.2s',vect_v2s+27
	symbol_maker	'v27.4h',vect_v4h+27
	symbol_maker	'v27.4s',vect_v4s+27
	symbol_maker	'v27.8b',vect_v8b+27
	symbol_maker	'v27.8h',vect_v8h+27
	symbol_maker	'v28.1d',vect_v1d+28
	symbol_maker	'v28.1q',vect_v1q+28
	symbol_maker	'v28.2d',vect_v2d+28
	symbol_maker	'v28.2s',vect_v2s+28
	symbol_maker	'v28.4h',vect_v4h+28
	symbol_maker	'v28.4s',vect_v4s+28
	symbol_maker	'v28.8b',vect_v8b+28
	symbol_maker	'v28.8h',vect_v8h+28
	symbol_maker	'v29.1d',vect_v1d+29
	symbol_maker	'v29.1q',vect_v1q+29
	symbol_maker	'v29.2d',vect_v2d+29
	symbol_maker	'v29.2s',vect_v2s+29
	symbol_maker	'v29.4h',vect_v4h+29
	symbol_maker	'v29.4s',vect_v4s+29
	symbol_maker	'v29.8b',vect_v8b+29
	symbol_maker	'v29.8h',vect_v8h+29
	symbol_maker	'v3.16b',vect_v16b+3
	symbol_maker	'v30.1d',vect_v1d+30
	symbol_maker	'v30.1q',vect_v1q+30
	symbol_maker	'v30.2d',vect_v2d+30
	symbol_maker	'v30.2s',vect_v2s+30
	symbol_maker	'v30.4h',vect_v4h+30
	symbol_maker	'v30.4s',vect_v4s+30
	symbol_maker	'v30.8b',vect_v8b+30
	symbol_maker	'v30.8h',vect_v8h+30
	symbol_maker	'v31.1d',vect_v1d+31
	symbol_maker	'v31.1q',vect_v1q+31
	symbol_maker	'v31.2d',vect_v2d+31
	symbol_maker	'v31.2s',vect_v2s+31
	symbol_maker	'v31.4h',vect_v4h+31
	symbol_maker	'v31.4s',vect_v4s+31
	symbol_maker	'v31.8b',vect_v8b+31
	symbol_maker	'v31.8h',vect_v8h+31
	symbol_maker	'v4.16b',vect_v16b+4
	symbol_maker	'v5.16b',vect_v16b+5
	symbol_maker	'v6.16b',vect_v16b+6
	symbol_maker	'v7.16b',vect_v16b+7
	symbol_maker	'v8.16b',vect_v16b+8
	symbol_maker	'v9.16b',vect_v16b+9
	symbol_maker	'vaale1',sys_tlbi+(sys_encode_vaale1-sys_encode_table_tlbi) shr 1
	symbol_maker	'vae1is',sys_tlbi+(sys_encode_vae1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vae2is',sys_tlbi+(sys_encode_vae2is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vae3is',sys_tlbi+(sys_encode_vae3is-sys_encode_table_tlbi) shr 1
symbols_7:
	symbol_maker	'alle1is',sys_tlbi+(sys_encode_alle1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'alle2is',sys_tlbi+(sys_encode_alle2is-sys_encode_table_tlbi) shr 1
	symbol_maker	'alle3is',sys_tlbi+(sys_encode_alle3is-sys_encode_table_tlbi) shr 1
	symbol_maker	'basepri',sysm_reg+17
	symbol_maker	'console',1Bh shl 8 + 3
	symbol_maker	'control',sysm_reg+20
	symbol_maker	'cpsr_cf',psr_reg+1
	symbol_maker	'cpsr_cs',psr_reg+1
	symbol_maker	'cpsr_cx',psr_reg+1
	symbol_maker	'cpsr_fc',psr_reg+8
	symbol_maker	'cpsr_fs',psr_reg+8
	symbol_maker	'cpsr_fx',psr_reg+8
	symbol_maker	'cpsr_sc',psr_reg+4
	symbol_maker	'cpsr_sf',psr_reg+4
	symbol_maker	'cpsr_sx',psr_reg+4
	symbol_maker	'cpsr_xc',psr_reg+2
	symbol_maker	'cpsr_xf',psr_reg+2
	symbol_maker	'cpsr_xs',psr_reg+2
	symbol_maker	'cpu32_a',cpu_sel+CPU32_CAPABILITY_A
	symbol_maker	'cpu32_e',cpu_sel+CPU32_CAPABILITY_E
	symbol_maker	'cpu32_j',cpu_sel+CPU32_CAPABILITY_J
	symbol_maker	'cpu32_k',cpu_sel+CPU32_CAPABILITY_K
	symbol_maker	'cpu32_m',cpu_sel+CPU32_CAPABILITY_M
	symbol_maker	'cpu32_p',cpu_sel+CPU32_CAPABILITY_P
	symbol_maker	'cpu32_x',cpu_sel+CPU32_CAPABILITY_X
	symbol_maker	'cpu32_z',cpu_sel+CPU32_CAPABILITY_Z
	symbol_maker	'ctr_el0',sys_msr+(sys_encode_ctr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'daifclr',sys_pstate+(sys_pencode_daifclr-sys_encode_table_pstate) shr 1
	symbol_maker	'daifset',sys_pstate+(sys_pencode_daifset-sys_encode_table_pstate) shr 1
	symbol_maker	'dlr_el0',sys_msr+(sys_encode_dlr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'dynamic',1Eh shl 8 + 2
	symbol_maker	'efiboot',1Bh shl 8 + 11
	symbol_maker	'elr_el1',sys_msr+(sys_encode_elr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'elr_el2',sys_msr+(sys_encode_elr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'elr_el3',sys_msr+(sys_encode_elr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'elr_hyp',banked_reg+30
	symbol_maker	'esr_el1',sys_msr+(sys_encode_esr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'esr_el2',sys_msr+(sys_encode_esr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'esr_el3',sys_msr+(sys_encode_esr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'far_el1',sys_msr+(sys_encode_far_el1-sys_encode_table_msr) shr 1
	symbol_maker	'far_el2',sys_msr+(sys_encode_far_el2-sys_encode_table_msr) shr 1
	symbol_maker	'far_el3',sys_msr+(sys_encode_far_el3-sys_encode_table_msr) shr 1
	symbol_maker	'fpinst2',vfp_syst+10
	symbol_maker	'hcr_el2',sys_msr+(sys_encode_hcr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ialluis',sys_ic+(sys_encode_ialluis-sys_encode_table_ic) shr 1
	symbol_maker	'ipas2e1',sys_tlbi+(sys_encode_ipas2e1-sys_encode_table_tlbi) shr 1
	symbol_maker	'isr_el1',sys_msr+(sys_encode_isr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'par_el1',sys_msr+(sys_encode_par_el1-sys_encode_table_msr) shr 1
	symbol_maker	'primask',sysm_reg+16
	symbol_maker	'r10@128',base_@128+10
	symbol_maker	'r10@256',base_@256+10
	symbol_maker	'r10_fiq',banked_reg+10
	symbol_maker	'r10_usr',banked_reg+2
	symbol_maker	'r11@128',base_@128+11
	symbol_maker	'r11@256',base_@256+11
	symbol_maker	'r11_fiq',banked_reg+11
	symbol_maker	'r11_usr',banked_reg+3
	symbol_maker	'r12@128',base_@128+12
	symbol_maker	'r12@256',base_@256+12
	symbol_maker	'r12_fiq',banked_reg+12
	symbol_maker	'r12_usr',banked_reg+4
	symbol_maker	'r13@128',base_@128+13
	symbol_maker	'r13@256',base_@256+13
	symbol_maker	'r14@128',base_@128+14
	symbol_maker	'r14@256',base_@256+14
	symbol_maker	'r15@128',base_@128+15
	symbol_maker	'r15@256',base_@256+15
	symbol_maker	'rmr_el1',sys_msr+(sys_encode_rmr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'rmr_el2',sys_msr+(sys_encode_rmr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'rmr_el3',sys_msr+(sys_encode_rmr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'scr_el3',sys_msr+(sys_encode_scr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_cf',psr_reg+16+8+1
	symbol_maker	'spsr_cs',psr_reg+16+4+1
	symbol_maker	'spsr_cx',psr_reg+16+2+1
	symbol_maker	'spsr_fc',psr_reg+16+1+8
	symbol_maker	'spsr_fs',psr_reg+16+4+8
	symbol_maker	'spsr_fx',psr_reg+16+2+8
	symbol_maker	'spsr_sc',psr_reg+16+1+4
	symbol_maker	'spsr_sf',psr_reg+16+8+4
	symbol_maker	'spsr_sx',psr_reg+16+2+4
	symbol_maker	'spsr_xc',psr_reg+16+1+2
	symbol_maker	'spsr_xf',psr_reg+16+8+2
	symbol_maker	'spsr_xs',psr_reg+16+4+2
	symbol_maker	'tcr_el1',sys_msr+(sys_encode_tcr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'tcr_el2',sys_msr+(sys_encode_tcr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'tcr_el3',sys_msr+(sys_encode_tcr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'v10.16b',vect_v16b+10
	symbol_maker	'v11.16b',vect_v16b+11
	symbol_maker	'v12.16b',vect_v16b+12
	symbol_maker	'v13.16b',vect_v16b+13
	symbol_maker	'v14.16b',vect_v16b+14
	symbol_maker	'v15.16b',vect_v16b+15
	symbol_maker	'v16.16b',vect_v16b+16
	symbol_maker	'v17.16b',vect_v16b+17
	symbol_maker	'v18.16b',vect_v16b+18
	symbol_maker	'v19.16b',vect_v16b+19
	symbol_maker	'v20.16b',vect_v16b+20
	symbol_maker	'v21.16b',vect_v16b+21
	symbol_maker	'v22.16b',vect_v16b+22
	symbol_maker	'v23.16b',vect_v16b+23
	symbol_maker	'v24.16b',vect_v16b+24
	symbol_maker	'v25.16b',vect_v16b+25
	symbol_maker	'v26.16b',vect_v16b+26
	symbol_maker	'v27.16b',vect_v16b+27
	symbol_maker	'v28.16b',vect_v16b+28
	symbol_maker	'v29.16b',vect_v16b+29
	symbol_maker	'v30.16b',vect_v16b+30
	symbol_maker	'v31.16b',vect_v16b+31
	symbol_maker	'vaae1is',sys_tlbi+(sys_encode_vaae1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vale1is',sys_tlbi+(sys_encode_vale1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vale2is',sys_tlbi+(sys_encode_vale2is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vale3is',sys_tlbi+(sys_encode_vale3is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vmalle1',sys_tlbi+(sys_encode_vmalle1-sys_encode_table_tlbi) shr 1
symbols_8:
	symbol_maker	'aidr_el1',sys_msr+(sys_encode_aidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'aside1is',sys_tlbi+(sys_encode_aside1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'cpsr_all',psr_reg+8+1
	symbol_maker	'cpsr_cfs',psr_reg+8+4+1
	symbol_maker	'cpsr_cfx',psr_reg+8+2+1
	symbol_maker	'cpsr_csf',psr_reg+8+4+1
	symbol_maker	'cpsr_csx',psr_reg+4+2+1
	symbol_maker	'cpsr_ctl',psr_reg+1
	symbol_maker	'cpsr_cxf',psr_reg+8+2+1
	symbol_maker	'cpsr_cxs',psr_reg+4+2+1
	symbol_maker	'cpsr_fcs',psr_reg+1+4+8
	symbol_maker	'cpsr_fcx',psr_reg+1+2+8
	symbol_maker	'cpsr_flg',psr_reg+8
	symbol_maker	'cpsr_fsc',psr_reg+1+4+8
	symbol_maker	'cpsr_fsx',psr_reg+4+2+8
	symbol_maker	'cpsr_fxc',psr_reg+1+2+8
	symbol_maker	'cpsr_fxs',psr_reg+4+2+8
	symbol_maker	'cpsr_scf',psr_reg+8+1+4
	symbol_maker	'cpsr_scx',psr_reg+1+2+4
	symbol_maker	'cpsr_sfc',psr_reg+8+1+4
	symbol_maker	'cpsr_sfx',psr_reg+8+2+4
	symbol_maker	'cpsr_sxc',psr_reg+1+2+4
	symbol_maker	'cpsr_sxf',psr_reg+8+2+4
	symbol_maker	'cpsr_xcf',psr_reg+8+1+2
	symbol_maker	'cpsr_xcs',psr_reg+4+1+2
	symbol_maker	'cpsr_xfc',psr_reg+8+1+2
	symbol_maker	'cpsr_xfs',psr_reg+8+4+2
	symbol_maker	'cpsr_xsc',psr_reg+4+1+2
	symbol_maker	'cpsr_xsf',psr_reg+8+4+2
	symbol_maker	'cptr_el2',sys_msr+(sys_encode_cptr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'cptr_el3',sys_msr+(sys_encode_cptr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'cpu32_6m',cpu_sel+CPU32_CAPABILITY_6M
	symbol_maker	'cpu32_7m',cpu_sel+CPU32_CAPABILITY_7M
	symbol_maker	'cpu32_mp',cpu_sel+CPU32_CAPABILITY_MP
	symbol_maker	'cpu32_t2',cpu_sel+CPU32_CAPABILITY_T2
	symbol_maker	'cpu32_v1',cpu_sel+CPU32_CAPABILITY_V1
	symbol_maker	'cpu32_v2',cpu_sel+CPU32_CAPABILITY_V2
	symbol_maker	'cpu32_v3',cpu_sel+CPU32_CAPABILITY_V3
	symbol_maker	'cpu32_v4',cpu_sel+CPU32_CAPABILITY_V4
	symbol_maker	'cpu32_v5',cpu_sel+CPU32_CAPABILITY_V5
	symbol_maker	'cpu32_v6',cpu_sel+CPU32_CAPABILITY_V6
	symbol_maker	'cpu32_v7',cpu_sel+CPU32_CAPABILITY_V7
	symbol_maker	'cpu32_v8',cpu_sel+CPU32_CAPABILITY_V8
	symbol_maker	'cpu32_ve',cpu_sel+CPU32_CAPABILITY_VE
	symbol_maker	'cpu64_fp',cpu_sel+CPU64_CAPABILITY_FP
	symbol_maker	'cpu64_v8',cpu_sel+CPU64_CAPABILITY_V8
	symbol_maker	'hacr_el2',sys_msr+(sys_encode_hacr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'hstr_el2',sys_msr+(sys_encode_hstr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'iflags_a',iflags+4
	symbol_maker	'iflags_f',iflags+1
	symbol_maker	'iflags_i',iflags+2
	symbol_maker	'ipas2le1',sys_tlbi+(sys_encode_ipas2le1-sys_encode_table_tlbi) shr 1
	symbol_maker	'linkinfo',19h shl 8 + 9
	symbol_maker	'mair_el1',sys_msr+(sys_encode_mair_el1-sys_encode_table_msr) shr 1
	symbol_maker	'mair_el2',sys_msr+(sys_encode_mair_el2-sys_encode_table_msr) shr 1
	symbol_maker	'mair_el3',sys_msr+(sys_encode_mair_el3-sys_encode_table_msr) shr 1
	symbol_maker	'mdcr_el2',sys_msr+(sys_encode_mdcr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'mdcr_el3',sys_msr+(sys_encode_mdcr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'midr_el1',sys_msr+(sys_encode_midr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmcr_el0',sys_msr+(sys_encode_pmcr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'readable',19h shl 8 + 30
	symbol_maker	'resource',1Ah shl 8 + 2
	symbol_maker	'spsr_abt',banked_reg+32+20
;;	symbol_maker	'spsr_abt',sys_msr+(sys_encode_spsr_abt-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_all',psr_reg+16+8+1
	symbol_maker	'spsr_cfs',psr_reg+16+8+4+1
	symbol_maker	'spsr_cfx',psr_reg+16+8+2+1
	symbol_maker	'spsr_csf',psr_reg+16+8+4+1
	symbol_maker	'spsr_csx',psr_reg+16+4+2+1
	symbol_maker	'spsr_ctl',psr_reg+16+1
	symbol_maker	'spsr_cxf',psr_reg+16+8+2+1
	symbol_maker	'spsr_cxs',psr_reg+16+4+2+1
	symbol_maker	'spsr_el1',sys_msr+(sys_encode_spsr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_el2',sys_msr+(sys_encode_spsr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_el3',sys_msr+(sys_encode_spsr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_fcs',psr_reg+16+1+4+8
	symbol_maker	'spsr_fcx',psr_reg+16+1+2+8
	symbol_maker	'spsr_fiq',banked_reg+32+14
;;	symbol_maker	'spsr_fiq',sys_msr+(sys_encode_spsr_fiq-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_flg',psr_reg+16+8
	symbol_maker	'spsr_fsc',psr_reg+16+1+4+8
	symbol_maker	'spsr_fsx',psr_reg+16+4+2+8
	symbol_maker	'spsr_fxc',psr_reg+16+1+2+8
	symbol_maker	'spsr_fxs',psr_reg+16+4+2+8
	symbol_maker	'spsr_hyp',banked_reg+32+30
	symbol_maker	'spsr_irq',banked_reg+32+16
;;	symbol_maker	'spsr_irq',sys_msr+(sys_encode_spsr_irq-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_mon',banked_reg+32+28
	symbol_maker	'spsr_scf',psr_reg+16+8+1+4
	symbol_maker	'spsr_scx',psr_reg+16+1+2+4
	symbol_maker	'spsr_sfc',psr_reg+16+8+1+4
	symbol_maker	'spsr_sfx',psr_reg+16+8+2+4
	symbol_maker	'spsr_svc',banked_reg+32+18
	symbol_maker	'spsr_sxc',psr_reg+16+1+2+4
	symbol_maker	'spsr_sxf',psr_reg+16+8+2+4
	symbol_maker	'spsr_und',banked_reg+32+22
;;	symbol_maker	'spsr_und',sys_msr+(sys_encode_spsr_und-sys_encode_table_msr) shr 1
	symbol_maker	'spsr_xcf',psr_reg+16+8+1+2
	symbol_maker	'spsr_xcs',psr_reg+16+4+1+2
	symbol_maker	'spsr_xfc',psr_reg+16+8+1+2
	symbol_maker	'spsr_xfs',psr_reg+16+8+4+2
	symbol_maker	'spsr_xsc',psr_reg+16+4+1+2
	symbol_maker	'spsr_xsf',psr_reg+16+8+4+2
	symbol_maker	'vaale1is',sys_tlbi+(sys_encode_vaale1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vbar_el1',sys_msr+(sys_encode_vbar_el1-sys_encode_table_msr) shr 1
	symbol_maker	'vbar_el2',sys_msr+(sys_encode_vbar_el2-sys_encode_table_msr) shr 1
	symbol_maker	'vbar_el3',sys_msr+(sys_encode_vbar_el3-sys_encode_table_msr) shr 1
	symbol_maker	'vtcr_el2',sys_msr+(sys_encode_vtcr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'writable',19h shl 8 + 31
symbols_9:
	symbol_maker	'actlr_el1',sys_msr+(sys_encode_actlr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'actlr_el2',sys_msr+(sys_encode_actlr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'actlr_el3',sys_msr+(sys_encode_actlr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'afsr0_el1',sys_msr+(sys_encode_afsr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'afsr0_el2',sys_msr+(sys_encode_afsr0_el2-sys_encode_table_msr) shr 1
	symbol_maker	'afsr0_el3',sys_msr+(sys_encode_afsr0_el3-sys_encode_table_msr) shr 1
	symbol_maker	'afsr1_el1',sys_msr+(sys_encode_afsr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'afsr1_el2',sys_msr+(sys_encode_afsr1_el2-sys_encode_table_msr) shr 1
	symbol_maker	'afsr1_el3',sys_msr+(sys_encode_afsr1_el3-sys_encode_table_msr) shr 1
	symbol_maker	'amair_el1',sys_msr+(sys_encode_amair_el1-sys_encode_table_msr) shr 1
	symbol_maker	'amair_el2',sys_msr+(sys_encode_amair_el2-sys_encode_table_msr) shr 1
	symbol_maker	'amair_el3',sys_msr+(sys_encode_amair_el3-sys_encode_table_msr) shr 1
	symbol_maker	'clidr_el1',sys_msr+(sys_encode_clidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'copro_all',copro_sel.all
	symbol_maker	'cpacr_el1',sys_msr+(sys_encode_cpacr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'cpsr_cfsx',psr_reg+8+4+2+1
	symbol_maker	'cpsr_cfxs',psr_reg+8+4+2+1
	symbol_maker	'cpsr_csfx',psr_reg+8+4+2+1
	symbol_maker	'cpsr_csxf',psr_reg+8+4+2+1
	symbol_maker	'cpsr_cxfs',psr_reg+8+4+2+1
	symbol_maker	'cpsr_cxsf',psr_reg+8+4+2+1
	symbol_maker	'cpsr_fcsx',psr_reg+1+4+2+8
	symbol_maker	'cpsr_fcxs',psr_reg+1+4+2+8
	symbol_maker	'cpsr_fscx',psr_reg+1+4+2+8
	symbol_maker	'cpsr_fsxc',psr_reg+1+4+2+8
	symbol_maker	'cpsr_fxcs',psr_reg+1+4+2+8
	symbol_maker	'cpsr_fxsc',psr_reg+1+4+2+8
	symbol_maker	'cpsr_scfx',psr_reg+8+1+2+4
	symbol_maker	'cpsr_scxf',psr_reg+8+1+2+4
	symbol_maker	'cpsr_sfcx',psr_reg+8+1+2+4
	symbol_maker	'cpsr_sfxc',psr_reg+8+1+2+4
	symbol_maker	'cpsr_sxcf',psr_reg+8+1+2+4
	symbol_maker	'cpsr_sxfc',psr_reg+8+1+2+4
	symbol_maker	'cpsr_xcfs',psr_reg+8+4+1+2
	symbol_maker	'cpsr_xcsf',psr_reg+8+4+1+2
	symbol_maker	'cpsr_xfcs',psr_reg+8+4+1+2
	symbol_maker	'cpsr_xfsc',psr_reg+8+4+1+2
	symbol_maker	'cpsr_xscf',psr_reg+8+4+1+2
	symbol_maker	'cpsr_xsfc',psr_reg+8+4+1+2
	symbol_maker	'cpu32_all',cpu_sel.all32
	symbol_maker	'cpu32_crc',cpu_sel+CPU32_CAPABILITY_CRC
	symbol_maker	'cpu32_div',cpu_sel+CPU32_CAPABILITY_DIV
	symbol_maker	'cpu32_v4t',cpu_sel+CPU32_CAPABILITY_V4T
	symbol_maker	'cpu32_v5t',cpu_sel+CPU32_CAPABILITY_V5T
	symbol_maker	'cpu32_v6t',cpu_sel+CPU32_CAPABILITY_V6T
	symbol_maker	'cpu64_all',cpu_sel.all64
	symbol_maker	'cpu64_crc',cpu_sel+CPU64_CAPABILITY_CRC
	symbol_maker	'currentel',sys_msr+(sys_encode_currentel-sys_encode_table_msr) shr 1
	symbol_maker	'dczid_el0',sys_msr+(sys_encode_dczid_el0-sys_encode_table_msr) shr 1
	symbol_maker	'dspsr_el0',sys_msr+(sys_encode_dspsr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'faultmask',sysm_reg+19
	symbol_maker	'hpfar_el2',sys_msr+(sys_encode_hpfar_el2-sys_encode_table_msr) shr 1
	symbol_maker	'iflags_af',iflags+4+1
	symbol_maker	'iflags_ai',iflags+4+2
	symbol_maker	'iflags_fa',iflags+1+4
	symbol_maker	'iflags_fi',iflags+1+2
	symbol_maker	'iflags_ia',iflags+2+4
	symbol_maker	'iflags_if',iflags+2+1
	symbol_maker	'ipas2e1is',sys_tlbi+(sys_encode_ipas2e1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'mdrar_el1',sys_msr+(sys_encode_mdrar_el1-sys_encode_table_msr) shr 1
	symbol_maker	'mdscr_el1',sys_msr+(sys_encode_mdscr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'mpidr_el1',sys_msr+(sys_encode_mpidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'mvfr0_el1',sys_msr+(sys_encode_mvfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'mvfr1_el1',sys_msr+(sys_encode_mvfr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'mvfr2_el1',sys_msr+(sys_encode_mvfr2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'osdlr_el1',sys_msr+(sys_encode_osdlr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'oslar_el1',sys_msr+(sys_encode_oslar_el1-sys_encode_table_msr) shr 1
	symbol_maker	'oslsr_el1',sys_msr+(sys_encode_oslsr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pldl1keep',prf_op+0*8+0*2+0
	symbol_maker	'pldl1strm',prf_op+0*8+0*2+1
	symbol_maker	'pldl2keep',prf_op+0*8+1*2+0
	symbol_maker	'pldl2strm',prf_op+0*8+1*2+1
	symbol_maker	'pldl3keep',prf_op+0*8+2*2+0
	symbol_maker	'pldl3strm',prf_op+0*8+2*2+1
	symbol_maker	'plil1keep',prf_op+1*8+0*2+0
	symbol_maker	'plil1strm',prf_op+1*8+0*2+1
	symbol_maker	'plil2keep',prf_op+1*8+1*2+0
	symbol_maker	'plil2strm',prf_op+1*8+1*2+1
	symbol_maker	'plil3keep',prf_op+1*8+2*2+0
	symbol_maker	'plil3strm',prf_op+1*8+2*2+1
	symbol_maker	'pstl1keep',prf_op+2*8+0*2+0
	symbol_maker	'pstl1strm',prf_op+2*8+0*2+1
	symbol_maker	'pstl2keep',prf_op+2*8+1*2+0
	symbol_maker	'pstl2strm',prf_op+2*8+1*2+1
	symbol_maker	'pstl3keep',prf_op+2*8+2*2+0
	symbol_maker	'pstl3strm',prf_op+2*8+2*2+1
	symbol_maker	'rvbar_el1',sys_msr+(sys_encode_rvbar_el1-sys_encode_table_msr) shr 1
	symbol_maker	'rvbar_el2',sys_msr+(sys_encode_rvbar_el2-sys_encode_table_msr) shr 1
	symbol_maker	'rvbar_el3',sys_msr+(sys_encode_rvbar_el3-sys_encode_table_msr) shr 1
	symbol_maker	'sctlr_el1',sys_msr+(sys_encode_sctlr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'sctlr_el2',sys_msr+(sys_encode_sctlr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'sctlr_el3',sys_msr+(sys_encode_sctlr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'shareable',19h shl 8 + 28
	symbol_maker	'spsr_cfsx',psr_reg+16+8+4+2+1
	symbol_maker	'spsr_cfxs',psr_reg+16+8+4+2+1
	symbol_maker	'spsr_csfx',psr_reg+16+8+4+2+1
	symbol_maker	'spsr_csxf',psr_reg+16+8+4+2+1
	symbol_maker	'spsr_cxfs',psr_reg+16+8+4+2+1
	symbol_maker	'spsr_cxsf',psr_reg+16+8+4+2+1
	symbol_maker	'spsr_fcsx',psr_reg+16+1+4+2+8
	symbol_maker	'spsr_fcxs',psr_reg+16+1+4+2+8
	symbol_maker	'spsr_fscx',psr_reg+16+1+4+2+8
	symbol_maker	'spsr_fsxc',psr_reg+16+1+4+2+8
	symbol_maker	'spsr_fxcs',psr_reg+16+1+4+2+8
	symbol_maker	'spsr_fxsc',psr_reg+16+1+4+2+8
	symbol_maker	'spsr_scfx',psr_reg+16+8+1+2+4
	symbol_maker	'spsr_scxf',psr_reg+16+8+1+2+4
	symbol_maker	'spsr_sfcx',psr_reg+16+8+1+2+4
	symbol_maker	'spsr_sfxc',psr_reg+16+8+1+2+4
	symbol_maker	'spsr_sxcf',psr_reg+16+8+1+2+4
	symbol_maker	'spsr_sxfc',psr_reg+16+8+1+2+4
	symbol_maker	'spsr_xcfs',psr_reg+16+8+4+1+2
	symbol_maker	'spsr_xcsf',psr_reg+16+8+4+1+2
	symbol_maker	'spsr_xfcs',psr_reg+16+8+4+1+2
	symbol_maker	'spsr_xfsc',psr_reg+16+8+4+1+2
	symbol_maker	'spsr_xscf',psr_reg+16+8+4+1+2
	symbol_maker	'spsr_xsfc',psr_reg+16+8+4+1+2
	symbol_maker	'tpidr_el0',sys_msr+(sys_encode_tpidr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'tpidr_el1',sys_msr+(sys_encode_tpidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'tpidr_el2',sys_msr+(sys_encode_tpidr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'tpidr_el3',sys_msr+(sys_encode_tpidr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'ttbr0_el1',sys_msr+(sys_encode_ttbr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'ttbr0_el2',sys_msr+(sys_encode_ttbr0_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ttbr0_el3',sys_msr+(sys_encode_ttbr0_el3-sys_encode_table_msr) shr 1
	symbol_maker	'ttbr1_el1',sys_msr+(sys_encode_ttbr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'vmalle1is',sys_tlbi+(sys_encode_vmalle1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'vpidr_el2',sys_msr+(sys_encode_vpidr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'vttbr_el2',sys_msr+(sys_encode_vttbr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'writeable',19h shl 8 + 31
symbols_10:
	symbol_maker	'apsr_nzcvq',psr_reg+8
	symbol_maker	'ccsidr_el1',sys_msr+(sys_encode_ccsidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'cntfrq_el0',sys_msr+(sys_encode_cntfrq_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cntpct_el0',sys_msr+(sys_encode_cntpct_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cntvct_el0',sys_msr+(sys_encode_cntvct_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cpu32_sync',cpu_sel+CPU32_CAPABILITY_SYNC
	symbol_maker	'cpu32_t2ee',cpu_sel+CPU32_CAPABILITY_T2EE
	symbol_maker	'cpu64_simd',cpu_sel+CPU64_CAPABILITY_SIMD
	symbol_maker	'csselr_el1',sys_msr+(sys_encode_csselr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dacr32_el2',sys_msr+(sys_encode_dacr32_el2-sys_encode_table_msr) shr 1
	symbol_maker	'dbgdtr_el0',sys_msr+(sys_encode_dbgdtr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'efiruntime',1Bh shl 8 + 12
	symbol_maker	'executable',19h shl 8 + 29
	symbol_maker	'iflags_afi',iflags+4+1+2
	symbol_maker	'iflags_aif',iflags+4+2+1
	symbol_maker	'iflags_fai',iflags+1+4+2
	symbol_maker	'iflags_fia',iflags+1+2+4
	symbol_maker	'iflags_iaf',iflags+2+4+1
	symbol_maker	'iflags_ifa',iflags+2+1+4
	symbol_maker	'ifsr32_el2',sys_msr+(sys_encode_ifsr32_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ipas2le1is',sys_tlbi+(sys_encode_ipas2le1is-sys_encode_table_tlbi) shr 1
	symbol_maker	'linkremove',19h shl 8 + 11
	symbol_maker	'mdccsr_el0',sys_msr+(sys_encode_mdccsr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'oseccr_el1',sys_msr+(sys_encode_oseccr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmselr_el0',sys_msr+(sys_encode_pmselr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'revidr_el1',sys_msr+(sys_encode_revidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'sder32_el3',sys_msr+(sys_encode_sder32_el3-sys_encode_table_msr) shr 1
	symbol_maker	'vmalls12e1',sys_tlbi+(sys_encode_vmalls12e1-sys_encode_table_tlbi) shr 1
	symbol_maker	'vmpidr_el2',sys_msr+(sys_encode_vmpidr_el2-sys_encode_table_msr) shr 1
symbols_11:
	symbol_maker	'apsr_nzcvqg',psr_reg+8+4
	symbol_maker	'basepri_max',sysm_reg+18
	symbol_maker	'cnthctl_el2',sys_msr+(sys_encode_cnthctl_el2-sys_encode_table_msr) shr 1
	symbol_maker	'cntkctl_el1',sys_msr+(sys_encode_cntkctl_el1-sys_encode_table_msr) shr 1
	symbol_maker	'cntvoff_el2',sys_msr+(sys_encode_cntvoff_el2-sys_encode_table_msr) shr 1
	symbol_maker	'cpu32_26bit',cpu_sel+CPU32_CAPABILITY_26BIT
	symbol_maker	'cpu32_align',cpu_sel+CPU32_CAPABILITY_ALIGN
	symbol_maker	'dbgbcr0_el1',sys_msr+(sys_encode_dbgbcr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr1_el1',sys_msr+(sys_encode_dbgbcr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr2_el1',sys_msr+(sys_encode_dbgbcr2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr3_el1',sys_msr+(sys_encode_dbgbcr3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr4_el1',sys_msr+(sys_encode_dbgbcr4_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr5_el1',sys_msr+(sys_encode_dbgbcr5_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr6_el1',sys_msr+(sys_encode_dbgbcr6_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr7_el1',sys_msr+(sys_encode_dbgbcr7_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr8_el1',sys_msr+(sys_encode_dbgbcr8_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr9_el1',sys_msr+(sys_encode_dbgbcr9_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr0_el1',sys_msr+(sys_encode_dbgbvr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr1_el1',sys_msr+(sys_encode_dbgbvr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr2_el1',sys_msr+(sys_encode_dbgbvr2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr3_el1',sys_msr+(sys_encode_dbgbvr3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr4_el1',sys_msr+(sys_encode_dbgbvr4_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr5_el1',sys_msr+(sys_encode_dbgbvr5_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr6_el1',sys_msr+(sys_encode_dbgbvr6_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr7_el1',sys_msr+(sys_encode_dbgbvr7_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr8_el1',sys_msr+(sys_encode_dbgbvr8_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr9_el1',sys_msr+(sys_encode_dbgbvr9_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgprcr_el1',sys_msr+(sys_encode_dbgprcr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr0_el1',sys_msr+(sys_encode_dbgwcr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr1_el1',sys_msr+(sys_encode_dbgwcr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr2_el1',sys_msr+(sys_encode_dbgwcr2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr3_el1',sys_msr+(sys_encode_dbgwcr3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr4_el1',sys_msr+(sys_encode_dbgwcr4_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr5_el1',sys_msr+(sys_encode_dbgwcr5_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr6_el1',sys_msr+(sys_encode_dbgwcr6_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr7_el1',sys_msr+(sys_encode_dbgwcr7_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr8_el1',sys_msr+(sys_encode_dbgwcr8_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr9_el1',sys_msr+(sys_encode_dbgwcr9_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr0_el1',sys_msr+(sys_encode_dbgwvr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr1_el1',sys_msr+(sys_encode_dbgwvr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr2_el1',sys_msr+(sys_encode_dbgwvr2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr3_el1',sys_msr+(sys_encode_dbgwvr3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr4_el1',sys_msr+(sys_encode_dbgwvr4_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr5_el1',sys_msr+(sys_encode_dbgwvr5_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr6_el1',sys_msr+(sys_encode_dbgwvr6_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr7_el1',sys_msr+(sys_encode_dbgwvr7_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr8_el1',sys_msr+(sys_encode_dbgwvr8_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr9_el1',sys_msr+(sys_encode_dbgwvr9_el1-sys_encode_table_msr) shr 1
	symbol_maker	'discardable',19h shl 8 + 25
	symbol_maker	'fpexc32_el2',sys_msr+(sys_encode_fpexc32_el2-sys_encode_table_msr) shr 1
	symbol_maker	'icc_dir_el1',sys_msr+(sys_encode_icc_dir_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_pmr_el1',sys_msr+(sys_encode_icc_pmr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_rpr_el1',sys_msr+(sys_encode_icc_rpr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_sre_el1',sys_msr+(sys_encode_icc_sre_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_sre_el2',sys_msr+(sys_encode_icc_sre_el2-sys_encode_table_msr) shr 1
	symbol_maker	'icc_sre_el3',sys_msr+(sys_encode_icc_sre_el3-sys_encode_table_msr) shr 1
	symbol_maker	'ich_hcr_el2',sys_msr+(sys_encode_ich_hcr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr0_el2',sys_msr+(sys_encode_ich_lr0_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr1_el2',sys_msr+(sys_encode_ich_lr1_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr2_el2',sys_msr+(sys_encode_ich_lr2_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr3_el2',sys_msr+(sys_encode_ich_lr3_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr4_el2',sys_msr+(sys_encode_ich_lr4_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr5_el2',sys_msr+(sys_encode_ich_lr5_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr6_el2',sys_msr+(sys_encode_ich_lr6_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr7_el2',sys_msr+(sys_encode_ich_lr7_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr8_el2',sys_msr+(sys_encode_ich_lr8_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr9_el2',sys_msr+(sys_encode_ich_lr9_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_vtr_el2',sys_msr+(sys_encode_ich_vtr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'icv_dir_el1',sys_msr+(sys_encode_icv_dir_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_pmr_el1',sys_msr+(sys_encode_icv_pmr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_rpr_el1',sys_msr+(sys_encode_icv_rpr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_afr0_el1',sys_msr+(sys_encode_id_afr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_dfr0_el1',sys_msr+(sys_encode_id_dfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_pfr0_el1',sys_msr+(sys_encode_id_pfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_pfr1_el1',sys_msr+(sys_encode_id_pfr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'interpreter',1Eh shl 8 + 3
	symbol_maker	'mdccint_el1',sys_msr+(sys_encode_mdccint_el1-sys_encode_table_msr) shr 1
	symbol_maker	'notpageable',19h shl 8 + 27
	symbol_maker	'osdtrrx_el1',sys_msr+(sys_encode_osdtrrx_el1-sys_encode_table_msr) shr 1
	symbol_maker	'osdtrtx_el1',sys_msr+(sys_encode_osdtrtx_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmccntr_el0',sys_msr+(sys_encode_pmccntr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmceid0_el0',sys_msr+(sys_encode_pmceid0_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmceid1_el0',sys_msr+(sys_encode_pmceid1_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmswinc_el0',sys_msr+(sys_encode_pmswinc_el0-sys_encode_table_msr) shr 1
	symbol_maker	'tpidrro_el0',sys_msr+(sys_encode_tpidrro_el0-sys_encode_table_msr) shr 1
symbols_12:
	symbol_maker	'cntp_ctl_el0',sys_msr+(sys_encode_cntp_ctl_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cntv_ctl_el0',sys_msr+(sys_encode_cntv_ctl_el0-sys_encode_table_msr) shr 1
	symbol_maker	'copro_fpa_v1',copro_sel+COPRO_CAPABILITY_FPA_V1
	symbol_maker	'copro_fpa_v2',copro_sel+COPRO_CAPABILITY_FPA_V2
	symbol_maker	'copro_vfp_hp',copro_sel+COPRO_CAPABILITY_VFP_HP
	symbol_maker	'copro_vfp_v1',copro_sel+COPRO_CAPABILITY_VFP_V1
	symbol_maker	'copro_vfp_v2',copro_sel+COPRO_CAPABILITY_VFP_V2
	symbol_maker	'copro_vfp_v3',copro_sel+COPRO_CAPABILITY_VFP_V3
	symbol_maker	'copro_vfp_v4',copro_sel+COPRO_CAPABILITY_VFP_V4
	symbol_maker	'copro_xscale',copro_sel+COPRO_CAPABILITY_XSCALE
	symbol_maker	'cpu64_crypto',cpu_sel+CPU64_CAPABILITY_CRYPTO
	symbol_maker	'dbgbcr10_el1',sys_msr+(sys_encode_dbgbcr10_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr11_el1',sys_msr+(sys_encode_dbgbcr11_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr12_el1',sys_msr+(sys_encode_dbgbcr12_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr13_el1',sys_msr+(sys_encode_dbgbcr13_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr14_el1',sys_msr+(sys_encode_dbgbcr14_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbcr15_el1',sys_msr+(sys_encode_dbgbcr15_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr10_el1',sys_msr+(sys_encode_dbgbvr10_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr11_el1',sys_msr+(sys_encode_dbgbvr11_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr12_el1',sys_msr+(sys_encode_dbgbvr12_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr13_el1',sys_msr+(sys_encode_dbgbvr13_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr14_el1',sys_msr+(sys_encode_dbgbvr14_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgbvr15_el1',sys_msr+(sys_encode_dbgbvr15_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgdtrrx_el0',sys_msr+(sys_encode_dbgdtrrx_el0-sys_encode_table_msr) shr 1
	symbol_maker	'dbgdtrtx_el0',sys_msr+(sys_encode_dbgdtrtx_el0-sys_encode_table_msr) shr 1
	symbol_maker	'dbgvcr32_el2',sys_msr+(sys_encode_dbgvcr32_el2-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr10_el1',sys_msr+(sys_encode_dbgwcr10_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr11_el1',sys_msr+(sys_encode_dbgwcr11_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr12_el1',sys_msr+(sys_encode_dbgwcr12_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr13_el1',sys_msr+(sys_encode_dbgwcr13_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr14_el1',sys_msr+(sys_encode_dbgwcr14_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwcr15_el1',sys_msr+(sys_encode_dbgwcr15_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr10_el1',sys_msr+(sys_encode_dbgwvr10_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr11_el1',sys_msr+(sys_encode_dbgwvr11_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr12_el1',sys_msr+(sys_encode_dbgwvr12_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr13_el1',sys_msr+(sys_encode_dbgwvr13_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr14_el1',sys_msr+(sys_encode_dbgwvr14_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgwvr15_el1',sys_msr+(sys_encode_dbgwvr15_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_bpr0_el1',sys_msr+(sys_encode_icc_bpr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_bpr1_el1',sys_msr+(sys_encode_icc_bpr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ctlr_el1',sys_msr+(sys_encode_icc_ctlr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ctlr_el3',sys_msr+(sys_encode_icc_ctlr_el3-sys_encode_table_msr) shr 1
	symbol_maker	'icc_iar0_el1',sys_msr+(sys_encode_icc_iar0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_iar1_el1',sys_msr+(sys_encode_icc_iar1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'ich_eisr_el2',sys_msr+(sys_encode_ich_eisr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr10_el2',sys_msr+(sys_encode_ich_lr10_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr11_el2',sys_msr+(sys_encode_ich_lr11_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr12_el2',sys_msr+(sys_encode_ich_lr12_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr13_el2',sys_msr+(sys_encode_ich_lr13_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr14_el2',sys_msr+(sys_encode_ich_lr14_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_lr15_el2',sys_msr+(sys_encode_ich_lr15_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_misr_el2',sys_msr+(sys_encode_ich_misr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_vmcr_el2',sys_msr+(sys_encode_ich_vmcr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'icv_bpr0_el1',sys_msr+(sys_encode_icv_bpr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_bpr1_el1',sys_msr+(sys_encode_icv_bpr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ctlr_el1',sys_msr+(sys_encode_icv_ctlr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_iar0_el1',sys_msr+(sys_encode_icv_iar0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_iar1_el1',sys_msr+(sys_encode_icv_iar1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_isar0_el1',sys_msr+(sys_encode_id_isar0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_isar1_el1',sys_msr+(sys_encode_id_isar1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_isar2_el1',sys_msr+(sys_encode_id_isar2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_isar3_el1',sys_msr+(sys_encode_id_isar3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_isar4_el1',sys_msr+(sys_encode_id_isar4_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_isar5_el1',sys_msr+(sys_encode_id_isar5_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_mmfr0_el1',sys_msr+(sys_encode_id_mmfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_mmfr1_el1',sys_msr+(sys_encode_id_mmfr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_mmfr2_el1',sys_msr+(sys_encode_id_mmfr2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_mmfr3_el1',sys_msr+(sys_encode_id_mmfr3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_mmfr4_el1',sys_msr+(sys_encode_id_mmfr4_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmovsclr_el0',sys_msr+(sys_encode_pmovsclr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmovsset_el0',sys_msr+(sys_encode_pmovsset_el0-sys_encode_table_msr) shr 1
	symbol_maker	'vmalls12e1is',sys_tlbi+(sys_encode_vmalls12e1is-sys_encode_table_tlbi) shr 1
symbols_13:
	symbol_maker	'cnthp_ctl_el2',sys_msr+(sys_encode_cnthp_ctl_el2-sys_encode_table_msr) shr 1
	symbol_maker	'cntp_cval_el0',sys_msr+(sys_encode_cntp_cval_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cntp_tval_el0',sys_msr+(sys_encode_cntp_tval_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cntps_ctl_el1',sys_msr+(sys_encode_cntps_ctl_el1-sys_encode_table_msr) shr 1
	symbol_maker	'cntv_cval_el0',sys_msr+(sys_encode_cntv_cval_el0-sys_encode_table_msr) shr 1
	symbol_maker	'cntv_tval_el0',sys_msr+(sys_encode_cntv_tval_el0-sys_encode_table_msr) shr 1
	symbol_maker	'copro_simd_hp',copro_sel+COPRO_CAPABILITY_SIMD_HP
	symbol_maker	'copro_simd_v2',copro_sel+COPRO_CAPABILITY_SIMD_V2
	symbol_maker	'copro_simd_v8',copro_sel+COPRO_CAPABILITY_SIMD_V8
	symbol_maker	'copro_vfp_d32',copro_sel+COPRO_CAPABILITY_VFP_D32
	symbol_maker	'icc_ap0r0_el1',sys_msr+(sys_encode_icc_ap0r0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap0r1_el1',sys_msr+(sys_encode_icc_ap0r1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap0r2_el1',sys_msr+(sys_encode_icc_ap0r2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap0r3_el1',sys_msr+(sys_encode_icc_ap0r3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap1r0_el1',sys_msr+(sys_encode_icc_ap1r0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap1r1_el1',sys_msr+(sys_encode_icc_ap1r1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap1r2_el1',sys_msr+(sys_encode_icc_ap1r2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_ap1r3_el1',sys_msr+(sys_encode_icc_ap1r3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_eoir0_el1',sys_msr+(sys_encode_icc_eoir0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_eoir1_el1',sys_msr+(sys_encode_icc_eoir1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_sgi0r_el1',sys_msr+(sys_encode_icc_sgi0r_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_sgi1r_el1',sys_msr+(sys_encode_icc_sgi1r_el1-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap0r0_el2',sys_msr+(sys_encode_ich_ap0r0_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap0r1_el2',sys_msr+(sys_encode_ich_ap0r1_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap0r2_el2',sys_msr+(sys_encode_ich_ap0r2_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap0r3_el2',sys_msr+(sys_encode_ich_ap0r3_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap1r0_el2',sys_msr+(sys_encode_ich_ap1r0_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap1r1_el2',sys_msr+(sys_encode_ich_ap1r1_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap1r2_el2',sys_msr+(sys_encode_ich_ap1r2_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_ap1r3_el2',sys_msr+(sys_encode_ich_ap1r3_el2-sys_encode_table_msr) shr 1
	symbol_maker	'ich_elrsr_el2',sys_msr+(sys_encode_ich_elrsr_el2-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap0r0_el1',sys_msr+(sys_encode_icv_ap0r0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap0r1_el1',sys_msr+(sys_encode_icv_ap0r1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap0r2_el1',sys_msr+(sys_encode_icv_ap0r2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap0r3_el1',sys_msr+(sys_encode_icv_ap0r3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap1r0_el1',sys_msr+(sys_encode_icv_ap1r0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap1r1_el1',sys_msr+(sys_encode_icv_ap1r1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap1r2_el1',sys_msr+(sys_encode_icv_ap1r2_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_ap1r3_el1',sys_msr+(sys_encode_icv_ap1r3_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_eoir0_el1',sys_msr+(sys_encode_icv_eoir0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_eoir1_el1',sys_msr+(sys_encode_icv_eoir1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmccfiltr_el0',sys_msr+(sys_encode_pmccfiltr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr0_el0',sys_msr+(sys_encode_pmevcntr0_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr1_el0',sys_msr+(sys_encode_pmevcntr1_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr2_el0',sys_msr+(sys_encode_pmevcntr2_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr3_el0',sys_msr+(sys_encode_pmevcntr3_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr4_el0',sys_msr+(sys_encode_pmevcntr4_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr5_el0',sys_msr+(sys_encode_pmevcntr5_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr6_el0',sys_msr+(sys_encode_pmevcntr6_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr7_el0',sys_msr+(sys_encode_pmevcntr7_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr8_el0',sys_msr+(sys_encode_pmevcntr8_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr9_el0',sys_msr+(sys_encode_pmevcntr9_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmuserenr_el0',sys_msr+(sys_encode_pmuserenr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmxevcntr_el0',sys_msr+(sys_encode_pmxevcntr_el0-sys_encode_table_msr) shr 1
symbols_14:
	symbol_maker	'cnthp_cval_el2',sys_msr+(sys_encode_cnthp_cval_el2-sys_encode_table_msr) shr 1
	symbol_maker	'cnthp_tval_el2',sys_msr+(sys_encode_cnthp_tval_el2-sys_encode_table_msr) shr 1
	symbol_maker	'cntps_cval_el1',sys_msr+(sys_encode_cntps_cval_el1-sys_encode_table_msr) shr 1
	symbol_maker	'cntps_tval_el1',sys_msr+(sys_encode_cntps_tval_el1-sys_encode_table_msr) shr 1
	symbol_maker	'contextidr_el1',sys_msr+(sys_encode_contextidr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'copro_maverick',copro_sel+COPRO_CAPABILITY_MAVERICK
	symbol_maker	'copro_simd_int',copro_sel+COPRO_CAPABILITY_SIMD_INT
	symbol_maker	'copro_vfp_v1xd',copro_sel+COPRO_CAPABILITY_VFP_V1xD
	symbol_maker	'icc_asgi1r_el1',sys_msr+(sys_encode_icc_asgi1r_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_hppir0_el1',sys_msr+(sys_encode_icc_hppir0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_hppir1_el1',sys_msr+(sys_encode_icc_hppir1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_hppir0_el1',sys_msr+(sys_encode_icv_hppir0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_hppir1_el1',sys_msr+(sys_encode_icv_hppir1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmcntenclr_el0',sys_msr+(sys_encode_pmcntenclr_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmcntenset_el0',sys_msr+(sys_encode_pmcntenset_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr10_el0',sys_msr+(sys_encode_pmevcntr10_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr11_el0',sys_msr+(sys_encode_pmevcntr11_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr12_el0',sys_msr+(sys_encode_pmevcntr12_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr13_el0',sys_msr+(sys_encode_pmevcntr13_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr14_el0',sys_msr+(sys_encode_pmevcntr14_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr15_el0',sys_msr+(sys_encode_pmevcntr15_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr16_el0',sys_msr+(sys_encode_pmevcntr16_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr17_el0',sys_msr+(sys_encode_pmevcntr17_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr18_el0',sys_msr+(sys_encode_pmevcntr18_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr19_el0',sys_msr+(sys_encode_pmevcntr19_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr20_el0',sys_msr+(sys_encode_pmevcntr20_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr21_el0',sys_msr+(sys_encode_pmevcntr21_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr22_el0',sys_msr+(sys_encode_pmevcntr22_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr23_el0',sys_msr+(sys_encode_pmevcntr23_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr24_el0',sys_msr+(sys_encode_pmevcntr24_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr25_el0',sys_msr+(sys_encode_pmevcntr25_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr26_el0',sys_msr+(sys_encode_pmevcntr26_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr27_el0',sys_msr+(sys_encode_pmevcntr27_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr28_el0',sys_msr+(sys_encode_pmevcntr28_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr29_el0',sys_msr+(sys_encode_pmevcntr29_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevcntr30_el0',sys_msr+(sys_encode_pmevcntr30_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper0_el0',sys_msr+(sys_encode_pmevtyper0_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper1_el0',sys_msr+(sys_encode_pmevtyper1_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper2_el0',sys_msr+(sys_encode_pmevtyper2_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper3_el0',sys_msr+(sys_encode_pmevtyper3_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper4_el0',sys_msr+(sys_encode_pmevtyper4_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper5_el0',sys_msr+(sys_encode_pmevtyper5_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper6_el0',sys_msr+(sys_encode_pmevtyper6_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper7_el0',sys_msr+(sys_encode_pmevtyper7_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper8_el0',sys_msr+(sys_encode_pmevtyper8_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper9_el0',sys_msr+(sys_encode_pmevtyper9_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmintenclr_el1',sys_msr+(sys_encode_pmintenclr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmintenset_el1',sys_msr+(sys_encode_pmintenset_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmxevtyper_el0',sys_msr+(sys_encode_pmxevtyper_el0-sys_encode_table_msr) shr 1
symbols_15:
	symbol_maker	'copro_iwmmxt_v1',copro_sel+COPRO_CAPABILITY_IWMMXT_V1
	symbol_maker	'copro_iwmmxt_v2',copro_sel+COPRO_CAPABILITY_IWMMXT_V2
	symbol_maker	'dbgclaimclr_el1',sys_msr+(sys_encode_dbgclaimclr_el1-sys_encode_table_msr) shr 1
	symbol_maker	'dbgclaimset_el1',sys_msr+(sys_encode_dbgclaimset_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_igrpen0_el1',sys_msr+(sys_encode_icc_igrpen0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_igrpen1_el1',sys_msr+(sys_encode_icc_igrpen1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icc_igrpen1_el3',sys_msr+(sys_encode_icc_igrpen1_el3-sys_encode_table_msr) shr 1
	symbol_maker	'icv_igrpen0_el1',sys_msr+(sys_encode_icv_igrpen0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'icv_igrpen1_el1',sys_msr+(sys_encode_icv_igrpen1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64afr0_el1',sys_msr+(sys_encode_id_aa64afr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64afr1_el1',sys_msr+(sys_encode_id_aa64afr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64dfr0_el1',sys_msr+(sys_encode_id_aa64dfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64dfr1_el1',sys_msr+(sys_encode_id_aa64dfr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64pfr0_el1',sys_msr+(sys_encode_id_aa64pfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64pfr1_el1',sys_msr+(sys_encode_id_aa64pfr1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper10_el0',sys_msr+(sys_encode_pmevtyper10_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper11_el0',sys_msr+(sys_encode_pmevtyper11_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper12_el0',sys_msr+(sys_encode_pmevtyper12_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper13_el0',sys_msr+(sys_encode_pmevtyper13_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper14_el0',sys_msr+(sys_encode_pmevtyper14_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper15_el0',sys_msr+(sys_encode_pmevtyper15_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper16_el0',sys_msr+(sys_encode_pmevtyper16_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper17_el0',sys_msr+(sys_encode_pmevtyper17_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper18_el0',sys_msr+(sys_encode_pmevtyper18_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper19_el0',sys_msr+(sys_encode_pmevtyper19_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper20_el0',sys_msr+(sys_encode_pmevtyper20_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper21_el0',sys_msr+(sys_encode_pmevtyper21_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper22_el0',sys_msr+(sys_encode_pmevtyper22_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper23_el0',sys_msr+(sys_encode_pmevtyper23_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper24_el0',sys_msr+(sys_encode_pmevtyper24_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper25_el0',sys_msr+(sys_encode_pmevtyper25_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper26_el0',sys_msr+(sys_encode_pmevtyper26_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper27_el0',sys_msr+(sys_encode_pmevtyper27_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper28_el0',sys_msr+(sys_encode_pmevtyper28_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper29_el0',sys_msr+(sys_encode_pmevtyper29_el0-sys_encode_table_msr) shr 1
	symbol_maker	'pmevtyper30_el0',sys_msr+(sys_encode_pmevtyper30_el0-sys_encode_table_msr) shr 1
symbols_16:
	symbol_maker	'copro_simd_float',copro_sel+COPRO_CAPABILITY_SIMD_FLOAT
	symbol_maker	'id_aa64isar0_el1',sys_msr+(sys_encode_id_aa64isar0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64isar1_el1',sys_msr+(sys_encode_id_aa64isar1_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64mmfr0_el1',sys_msr+(sys_encode_id_aa64mmfr0_el1-sys_encode_table_msr) shr 1
	symbol_maker	'id_aa64mmfr1_el1',sys_msr+(sys_encode_id_aa64mmfr1_el1-sys_encode_table_msr) shr 1
symbols_17:
	symbol_maker	'copro_simd_crypto',copro_sel+COPRO_CAPABILITY_SIMD_CRYPTO
	symbol_maker	'dbgauthstatus_el1',sys_msr+(sys_encode_dbgauthstatus_el1-sys_encode_table_msr) shr 1
symbols_end:

purge symbol_maker

	align 2
sys_encode_table_at:
	;at					op0           op1            crn            crm            op2
	sys_encode_s12e0r:		dw	001b shl 14 + 0100b shl 11 + 00111b shl 7 + 01000b shl 3 + 0110b
	sys_encode_s12e0w:		dw	001b shl 14 + 0100b shl 11 + 00111b shl 7 + 01000b shl 3 + 0111b
	sys_encode_s12e1r:		dw	001b shl 14 + 0100b shl 11 + 00111b shl 7 + 01000b shl 3 + 0100b
	sys_encode_s12e1w:		dw	001b shl 14 + 0100b shl 11 + 00111b shl 7 + 01000b shl 3 + 0101b
	sys_encode_s1e0r:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 01000b shl 3 + 0010b
	sys_encode_s1e0w:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 01000b shl 3 + 0011b
	sys_encode_s1e1r:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 01000b shl 3 + 0000b
	sys_encode_s1e1w:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 01000b shl 3 + 0001b
	sys_encode_s1e2r:		dw	001b shl 14 + 0100b shl 11 + 00111b shl 7 + 01000b shl 3 + 0000b
	sys_encode_s1e2w:		dw	001b shl 14 + 0100b shl 11 + 00111b shl 7 + 01000b shl 3 + 0001b
	sys_encode_s1e3r:		dw	001b shl 14 + 0110b shl 11 + 00111b shl 7 + 01000b shl 3 + 0000b
	sys_encode_s1e3w:		dw	001b shl 14 + 0110b shl 11 + 00111b shl 7 + 01000b shl 3 + 0001b
sys_encode_table_dc:
	;dc					op0           op1            crn            crm            op2
	sys_encode_cisw:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 01110b shl 3 + 0010b
	sys_encode_civac:		dw	001b shl 14 + 0011b shl 11 + 00111b shl 7 + 01110b shl 3 + 0001b
	sys_encode_csw:			dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 01010b shl 3 + 0010b
	sys_encode_cvac:		dw	001b shl 14 + 0011b shl 11 + 00111b shl 7 + 01010b shl 3 + 0001b
	sys_encode_cvau:		dw	001b shl 14 + 0011b shl 11 + 00111b shl 7 + 01011b shl 3 + 0001b
	sys_encode_isw:			dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 00110b shl 3 + 0010b
	sys_encode_ivac:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 00110b shl 3 + 0001b
	sys_encode_zva:			dw	001b shl 14 + 0011b shl 11 + 00111b shl 7 + 00100b shl 3 + 0001b
sys_encode_table_ic:
	;ic					op0           op1            crn            crm            op2
	sys_encode_iallu:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 00101b shl 3 + 0000b
	sys_encode_ialluis:		dw	001b shl 14 + 0000b shl 11 + 00111b shl 7 + 00001b shl 3 + 0000b
	sys_encode_ivau:		dw	001b shl 14 + 0011b shl 11 + 00111b shl 7 + 00101b shl 3 + 0001b
sys_encode_table_tlbi:
	;tlbi					op0           op1            crn            crm            op2
	sys_encode_alle1:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00111b shl 3 + 0100b
	sys_encode_alle1is:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00011b shl 3 + 0100b
	sys_encode_alle2:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00111b shl 3 + 0000b
	sys_encode_alle2is:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00011b shl 3 + 0000b
	sys_encode_alle3:		dw	001b shl 14 + 0110b shl 11 + 01000b shl 7 + 00111b shl 3 + 0000b
	sys_encode_alle3is:		dw	001b shl 14 + 0110b shl 11 + 01000b shl 7 + 00011b shl 3 + 0000b
	sys_encode_aside1:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00111b shl 3 + 0010b
	sys_encode_aside1is:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00011b shl 3 + 0010b
	sys_encode_ipas2e1:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00100b shl 3 + 0001b
	sys_encode_ipas2e1is:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00000b shl 3 + 0001b
	sys_encode_ipas2le1:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00100b shl 3 + 0101b
	sys_encode_ipas2le1is:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00000b shl 3 + 0101b
	sys_encode_vaae1:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00111b shl 3 + 0011b
	sys_encode_vaae1is:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00011b shl 3 + 0011b
	sys_encode_vaale1:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00111b shl 3 + 0111b
	sys_encode_vaale1is:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00011b shl 3 + 0111b
	sys_encode_vae1:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00111b shl 3 + 0001b
	sys_encode_vae1is:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00011b shl 3 + 0001b
	sys_encode_vae2:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00111b shl 3 + 0001b
	sys_encode_vae2is:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00011b shl 3 + 0001b
	sys_encode_vae3:		dw	001b shl 14 + 0110b shl 11 + 01000b shl 7 + 00111b shl 3 + 0001b
	sys_encode_vae3is:		dw	001b shl 14 + 0110b shl 11 + 01000b shl 7 + 00011b shl 3 + 0001b
	sys_encode_vale1:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00111b shl 3 + 0101b
	sys_encode_vale1is:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00011b shl 3 + 0101b
	sys_encode_vale2:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00111b shl 3 + 0101b
	sys_encode_vale2is:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00011b shl 3 + 0101b
	sys_encode_vale3:		dw	001b shl 14 + 0110b shl 11 + 01000b shl 7 + 00111b shl 3 + 0101b
	sys_encode_vale3is:		dw	001b shl 14 + 0110b shl 11 + 01000b shl 7 + 00011b shl 3 + 0101b
	sys_encode_vmalle1:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00111b shl 3 + 0000b
	sys_encode_vmalle1is:		dw	001b shl 14 + 0000b shl 11 + 01000b shl 7 + 00011b shl 3 + 0000b
	sys_encode_vmalls12e1:		dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00111b shl 3 + 0110b
	sys_encode_vmalls12e1is:	dw	001b shl 14 + 0100b shl 11 + 01000b shl 7 + 00011b shl 3 + 0110b
sys_encode_table_msr:
	;msr/mrs				op0           op1            crn            crm            op2
	sys_encode_actlr_el1:		dw	011b shl 14 + 0000b shl 11 + 00001b shl 7 + 00000b shl 3 + 0001b
	sys_encode_actlr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00000b shl 3 + 0001b
	sys_encode_actlr_el3:		dw	011b shl 14 + 0110b shl 11 + 00001b shl 7 + 00000b shl 3 + 0001b
	sys_encode_afsr0_el1:		dw	011b shl 14 + 0000b shl 11 + 00101b shl 7 + 00001b shl 3 + 0000b
	sys_encode_afsr0_el2:		dw	011b shl 14 + 0100b shl 11 + 00101b shl 7 + 00001b shl 3 + 0000b
	sys_encode_afsr0_el3:		dw	011b shl 14 + 0110b shl 11 + 00101b shl 7 + 00001b shl 3 + 0000b
	sys_encode_afsr1_el1:		dw	011b shl 14 + 0000b shl 11 + 00101b shl 7 + 00001b shl 3 + 0001b
	sys_encode_afsr1_el2:		dw	011b shl 14 + 0100b shl 11 + 00101b shl 7 + 00001b shl 3 + 0001b
	sys_encode_afsr1_el3:		dw	011b shl 14 + 0110b shl 11 + 00101b shl 7 + 00001b shl 3 + 0001b
	sys_encode_aidr_el1:		dw	011b shl 14 + 0001b shl 11 + 00000b shl 7 + 00000b shl 3 + 0111b
	sys_encode_amair_el1:		dw	011b shl 14 + 0000b shl 11 + 01010b shl 7 + 00011b shl 3 + 0000b
	sys_encode_amair_el2:		dw	011b shl 14 + 0100b shl 11 + 01010b shl 7 + 00011b shl 3 + 0000b
	sys_encode_amair_el3:		dw	011b shl 14 + 0110b shl 11 + 01010b shl 7 + 00011b shl 3 + 0000b
	sys_encode_ccsidr_el1:		dw	011b shl 14 + 0001b shl 11 + 00000b shl 7 + 00000b shl 3 + 0000b
	sys_encode_clidr_el1:		dw	011b shl 14 + 0001b shl 11 + 00000b shl 7 + 00000b shl 3 + 0001b
	sys_encode_cntfrq_el0:		dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00000b shl 3 + 0000b
	sys_encode_cnthctl_el2:		dw	011b shl 14 + 0100b shl 11 + 01110b shl 7 + 00001b shl 3 + 0000b
	sys_encode_cnthp_ctl_el2:	dw	011b shl 14 + 0100b shl 11 + 01110b shl 7 + 00010b shl 3 + 0001b
	sys_encode_cnthp_cval_el2:	dw	011b shl 14 + 0100b shl 11 + 01110b shl 7 + 00010b shl 3 + 0010b
	sys_encode_cnthp_tval_el2:	dw	011b shl 14 + 0100b shl 11 + 01110b shl 7 + 00010b shl 3 + 0000b
	sys_encode_cntkctl_el1:		dw	011b shl 14 + 0000b shl 11 + 01110b shl 7 + 00001b shl 3 + 0000b
	sys_encode_cntp_ctl_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00010b shl 3 + 0001b
	sys_encode_cntp_cval_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00010b shl 3 + 0010b
	sys_encode_cntp_tval_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00010b shl 3 + 0000b
	sys_encode_cntpct_el0:		dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00000b shl 3 + 0001b
	sys_encode_cntps_ctl_el1:	dw	011b shl 14 + 0111b shl 11 + 01110b shl 7 + 00010b shl 3 + 0001b
	sys_encode_cntps_cval_el1:	dw	011b shl 14 + 0111b shl 11 + 01110b shl 7 + 00010b shl 3 + 0010b
	sys_encode_cntps_tval_el1:	dw	011b shl 14 + 0111b shl 11 + 01110b shl 7 + 00010b shl 3 + 0000b
	sys_encode_cntv_ctl_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00011b shl 3 + 0001b
	sys_encode_cntv_cval_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00011b shl 3 + 0010b
	sys_encode_cntv_tval_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00011b shl 3 + 0000b
	sys_encode_cntvct_el0:		dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 00000b shl 3 + 0010b
	sys_encode_cntvoff_el2:		dw	011b shl 14 + 0100b shl 11 + 01110b shl 7 + 00000b shl 3 + 0011b
	sys_encode_contextidr_el1:	dw	011b shl 14 + 0000b shl 11 + 01101b shl 7 + 00000b shl 3 + 0001b
	sys_encode_cpacr_el1:		dw	011b shl 14 + 0000b shl 11 + 00001b shl 7 + 00000b shl 3 + 0010b
	sys_encode_cptr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00001b shl 3 + 0010b
	sys_encode_cptr_el3:		dw	011b shl 14 + 0110b shl 11 + 00001b shl 7 + 00001b shl 3 + 0010b
	sys_encode_csselr_el1:		dw	011b shl 14 + 0010b shl 11 + 00000b shl 7 + 00000b shl 3 + 0000b
	sys_encode_ctr_el0:		dw	011b shl 14 + 0011b shl 11 + 00000b shl 7 + 00000b shl 3 + 0001b
	sys_encode_currentel:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00010b shl 3 + 0010b
	sys_encode_dacr32_el2:		dw	011b shl 14 + 0100b shl 11 + 00011b shl 7 + 00000b shl 3 + 0000b
	sys_encode_daif:		dw	011b shl 14 + 0011b shl 11 + 00100b shl 7 + 00010b shl 3 + 0001b
	sys_encode_dbgauthstatus_el1:	dw	010b shl 14 + 0000b shl 11 + 00111b shl 7 + 01110b shl 3 + 0110b
	sys_encode_dbgbcr0_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0101b
	sys_encode_dbgbcr1_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0101b
	sys_encode_dbgbcr10_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01010b shl 3 + 0101b
	sys_encode_dbgbcr11_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01011b shl 3 + 0101b
	sys_encode_dbgbcr12_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01100b shl 3 + 0101b
	sys_encode_dbgbcr13_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01101b shl 3 + 0101b
	sys_encode_dbgbcr14_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01110b shl 3 + 0101b
	sys_encode_dbgbcr15_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01111b shl 3 + 0101b
	sys_encode_dbgbcr2_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0101b
	sys_encode_dbgbcr3_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0101b
	sys_encode_dbgbcr4_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00100b shl 3 + 0101b
	sys_encode_dbgbcr5_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0101b
	sys_encode_dbgbcr6_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0101b
	sys_encode_dbgbcr7_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00111b shl 3 + 0101b
	sys_encode_dbgbcr8_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01000b shl 3 + 0101b
	sys_encode_dbgbcr9_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01001b shl 3 + 0101b
	sys_encode_dbgbvr0_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0100b
	sys_encode_dbgbvr1_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0100b
	sys_encode_dbgbvr10_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01010b shl 3 + 0100b
	sys_encode_dbgbvr11_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01011b shl 3 + 0100b
	sys_encode_dbgbvr12_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01100b shl 3 + 0100b
	sys_encode_dbgbvr13_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01101b shl 3 + 0100b
	sys_encode_dbgbvr14_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01110b shl 3 + 0100b
	sys_encode_dbgbvr15_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01111b shl 3 + 0100b
	sys_encode_dbgbvr2_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0100b
	sys_encode_dbgbvr3_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0100b
	sys_encode_dbgbvr4_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00100b shl 3 + 0100b
	sys_encode_dbgbvr5_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0100b
	sys_encode_dbgbvr6_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0100b
	sys_encode_dbgbvr7_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00111b shl 3 + 0100b
	sys_encode_dbgbvr8_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01000b shl 3 + 0100b
	sys_encode_dbgbvr9_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01001b shl 3 + 0100b
	sys_encode_dbgclaimclr_el1:	dw	010b shl 14 + 0000b shl 11 + 00111b shl 7 + 01001b shl 3 + 0110b
	sys_encode_dbgclaimset_el1:	dw	010b shl 14 + 0000b shl 11 + 00111b shl 7 + 01000b shl 3 + 0110b
	sys_encode_dbgdtr_el0:		dw	010b shl 14 + 0011b shl 11 + 00000b shl 7 + 00100b shl 3 + 0000b
	sys_encode_dbgdtrrx_el0:	dw	010b shl 14 + 0011b shl 11 + 00000b shl 7 + 00101b shl 3 + 0000b
	sys_encode_dbgdtrtx_el0:	dw	010b shl 14 + 0011b shl 11 + 00000b shl 7 + 00101b shl 3 + 0000b
	sys_encode_dbgprcr_el1:		dw	010b shl 14 + 0000b shl 11 + 00001b shl 7 + 00100b shl 3 + 0100b
	sys_encode_dbgvcr32_el2:	dw	010b shl 14 + 0100b shl 11 + 00000b shl 7 + 00111b shl 3 + 0000b
	sys_encode_dbgwcr0_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0111b
	sys_encode_dbgwcr1_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0111b
	sys_encode_dbgwcr10_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01010b shl 3 + 0111b
	sys_encode_dbgwcr11_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01011b shl 3 + 0111b
	sys_encode_dbgwcr12_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01100b shl 3 + 0111b
	sys_encode_dbgwcr13_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01101b shl 3 + 0111b
	sys_encode_dbgwcr14_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01110b shl 3 + 0111b
	sys_encode_dbgwcr15_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01111b shl 3 + 0111b
	sys_encode_dbgwcr2_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0111b
	sys_encode_dbgwcr3_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0111b
	sys_encode_dbgwcr4_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00100b shl 3 + 0111b
	sys_encode_dbgwcr5_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0111b
	sys_encode_dbgwcr6_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0111b
	sys_encode_dbgwcr7_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00111b shl 3 + 0111b
	sys_encode_dbgwcr8_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01000b shl 3 + 0111b
	sys_encode_dbgwcr9_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01001b shl 3 + 0111b
	sys_encode_dbgwvr0_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0110b
	sys_encode_dbgwvr1_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0110b
	sys_encode_dbgwvr10_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01010b shl 3 + 0110b
	sys_encode_dbgwvr11_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01011b shl 3 + 0110b
	sys_encode_dbgwvr12_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01100b shl 3 + 0110b
	sys_encode_dbgwvr13_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01101b shl 3 + 0110b
	sys_encode_dbgwvr14_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01110b shl 3 + 0110b
	sys_encode_dbgwvr15_el1:	dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01111b shl 3 + 0110b
	sys_encode_dbgwvr2_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0110b
	sys_encode_dbgwvr3_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0110b
	sys_encode_dbgwvr4_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00100b shl 3 + 0110b
	sys_encode_dbgwvr5_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0110b
	sys_encode_dbgwvr6_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0110b
	sys_encode_dbgwvr7_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00111b shl 3 + 0110b
	sys_encode_dbgwvr8_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01000b shl 3 + 0110b
	sys_encode_dbgwvr9_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 01001b shl 3 + 0110b
	sys_encode_dczid_el0:		dw	011b shl 14 + 0011b shl 11 + 00000b shl 7 + 00000b shl 3 + 0111b
	sys_encode_dlr_el0:		dw	011b shl 14 + 0011b shl 11 + 00100b shl 7 + 00101b shl 3 + 0001b
	sys_encode_dspsr_el0:		dw	011b shl 14 + 0011b shl 11 + 00100b shl 7 + 00101b shl 3 + 0000b
	sys_encode_elr_el1:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00000b shl 3 + 0001b
	sys_encode_elr_el2:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00000b shl 3 + 0001b
	sys_encode_elr_el3:		dw	011b shl 14 + 0110b shl 11 + 00100b shl 7 + 00000b shl 3 + 0001b
	sys_encode_esr_el1:		dw	011b shl 14 + 0000b shl 11 + 00101b shl 7 + 00010b shl 3 + 0000b
	sys_encode_esr_el2:		dw	011b shl 14 + 0100b shl 11 + 00101b shl 7 + 00010b shl 3 + 0000b
	sys_encode_esr_el3:		dw	011b shl 14 + 0110b shl 11 + 00101b shl 7 + 00010b shl 3 + 0000b
	sys_encode_far_el1:		dw	011b shl 14 + 0000b shl 11 + 00110b shl 7 + 00000b shl 3 + 0000b
	sys_encode_far_el2:		dw	011b shl 14 + 0100b shl 11 + 00110b shl 7 + 00000b shl 3 + 0000b
	sys_encode_far_el3:		dw	011b shl 14 + 0110b shl 11 + 00110b shl 7 + 00000b shl 3 + 0000b
	sys_encode_fpcr:		dw	011b shl 14 + 0011b shl 11 + 00100b shl 7 + 00100b shl 3 + 0000b
	sys_encode_fpexc32_el2:		dw	011b shl 14 + 0100b shl 11 + 00101b shl 7 + 00011b shl 3 + 0000b
	sys_encode_fpsr:		dw	011b shl 14 + 0011b shl 11 + 00100b shl 7 + 00100b shl 3 + 0001b
	sys_encode_hacr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00001b shl 3 + 0111b
	sys_encode_hcr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00001b shl 3 + 0000b
	sys_encode_hpfar_el2:		dw	011b shl 14 + 0100b shl 11 + 00110b shl 7 + 00000b shl 3 + 0100b
	sys_encode_hstr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00001b shl 3 + 0011b
	sys_encode_icc_ap0r0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0100b
	sys_encode_icc_ap0r1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0101b
	sys_encode_icc_ap0r2_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0110b
	sys_encode_icc_ap0r3_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0111b
	sys_encode_icc_ap1r0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0000b
	sys_encode_icc_ap1r1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0001b
	sys_encode_icc_ap1r2_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0010b
	sys_encode_icc_ap1r3_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0011b
	sys_encode_icc_asgi1r_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0110b
	sys_encode_icc_bpr0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0011b
	sys_encode_icc_bpr1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0011b
	sys_encode_icc_ctlr_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0100b
	sys_encode_icc_ctlr_el3:	dw	011b shl 14 + 0110b shl 11 + 01100b shl 7 + 01100b shl 3 + 0100b
	sys_encode_icc_dir_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0001b
	sys_encode_icc_eoir0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0001b
	sys_encode_icc_eoir1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0001b
	sys_encode_icc_hppir0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0010b
	sys_encode_icc_hppir1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0010b
	sys_encode_icc_iar0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0000b
	sys_encode_icc_iar1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0000b
	sys_encode_icc_igrpen0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0110b
	sys_encode_icc_igrpen1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0111b
	sys_encode_icc_igrpen1_el3:	dw	011b shl 14 + 0110b shl 11 + 01100b shl 7 + 01100b shl 3 + 0111b
	sys_encode_icc_pmr_el1:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00110b shl 3 + 0000b
	sys_encode_icc_rpr_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0011b
	sys_encode_icc_sgi0r_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0111b
	sys_encode_icc_sgi1r_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0101b
	sys_encode_icc_sre_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0101b
	sys_encode_icc_sre_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01001b shl 3 + 0101b
	sys_encode_icc_sre_el3:		dw	011b shl 14 + 0110b shl 11 + 01100b shl 7 + 01100b shl 3 + 0101b
	sys_encode_ich_ap0r0_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01000b shl 3 + 0000b
	sys_encode_ich_ap0r1_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01000b shl 3 + 0001b
	sys_encode_ich_ap0r2_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01000b shl 3 + 0010b
	sys_encode_ich_ap0r3_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01000b shl 3 + 0011b
	sys_encode_ich_ap1r0_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01001b shl 3 + 0000b
	sys_encode_ich_ap1r1_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01001b shl 3 + 0001b
	sys_encode_ich_ap1r2_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01001b shl 3 + 0010b
	sys_encode_ich_ap1r3_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01001b shl 3 + 0011b
	sys_encode_ich_eisr_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01011b shl 3 + 0011b
	sys_encode_ich_elrsr_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01011b shl 3 + 0101b
	sys_encode_ich_hcr_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01011b shl 3 + 0000b
	sys_encode_ich_lr0_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0000b
	sys_encode_ich_lr1_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0001b
	sys_encode_ich_lr10_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0010b
	sys_encode_ich_lr11_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0011b
	sys_encode_ich_lr12_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0100b
	sys_encode_ich_lr13_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0101b
	sys_encode_ich_lr14_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0110b
	sys_encode_ich_lr15_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0111b
	sys_encode_ich_lr2_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0010b
	sys_encode_ich_lr3_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0011b
	sys_encode_ich_lr4_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0100b
	sys_encode_ich_lr5_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0101b
	sys_encode_ich_lr6_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0110b
	sys_encode_ich_lr7_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01100b shl 3 + 0111b
	sys_encode_ich_lr8_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0000b
	sys_encode_ich_lr9_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01101b shl 3 + 0001b
	sys_encode_ich_misr_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01011b shl 3 + 0010b
	sys_encode_ich_vmcr_el2:	dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01011b shl 3 + 0111b
	sys_encode_ich_vtr_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 01011b shl 3 + 0001b
	sys_encode_icv_ap0r0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0100b
	sys_encode_icv_ap0r1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0101b
	sys_encode_icv_ap0r2_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0110b
	sys_encode_icv_ap0r3_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0111b
	sys_encode_icv_ap1r0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0000b
	sys_encode_icv_ap1r1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0001b
	sys_encode_icv_ap1r2_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0010b
	sys_encode_icv_ap1r3_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01001b shl 3 + 0011b
	sys_encode_icv_bpr0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0011b
	sys_encode_icv_bpr1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0011b
	sys_encode_icv_ctlr_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0100b
	sys_encode_icv_dir_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0001b
	sys_encode_icv_eoir0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0001b
	sys_encode_icv_eoir1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0001b
	sys_encode_icv_hppir0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0010b
	sys_encode_icv_hppir1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0010b
	sys_encode_icv_iar0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01000b shl 3 + 0000b
	sys_encode_icv_iar1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0000b
	sys_encode_icv_igrpen0_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0110b
	sys_encode_icv_igrpen1_el1:	dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01100b shl 3 + 0111b
	sys_encode_icv_pmr_el1:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00110b shl 3 + 0000b
	sys_encode_icv_rpr_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 01011b shl 3 + 0011b
	sys_encode_id_aa64afr0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0100b
	sys_encode_id_aa64afr1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0101b
	sys_encode_id_aa64dfr0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0000b
	sys_encode_id_aa64dfr1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00101b shl 3 + 0001b
	sys_encode_id_aa64isar0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0000b
	sys_encode_id_aa64isar1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0001b
	sys_encode_id_aa64mmfr0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00111b shl 3 + 0000b
	sys_encode_id_aa64mmfr1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00111b shl 3 + 0001b
	sys_encode_id_aa64pfr0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00100b shl 3 + 0000b
	sys_encode_id_aa64pfr1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00100b shl 3 + 0001b
	sys_encode_id_afr0_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0011b
	sys_encode_id_dfr0_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0010b
	sys_encode_id_isar0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0000b
	sys_encode_id_isar1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0001b
	sys_encode_id_isar2_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0010b
	sys_encode_id_isar3_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0011b
	sys_encode_id_isar4_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0100b
	sys_encode_id_isar5_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0101b
	sys_encode_id_mmfr0_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0100b
	sys_encode_id_mmfr1_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0101b
	sys_encode_id_mmfr2_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0110b
	sys_encode_id_mmfr3_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0111b
	sys_encode_id_mmfr4_el1:	dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0110b
	sys_encode_id_pfr0_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0000b
	sys_encode_id_pfr1_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00001b shl 3 + 0001b
	sys_encode_ifsr32_el2:		dw	011b shl 14 + 0100b shl 11 + 00101b shl 7 + 00000b shl 3 + 0001b
	sys_encode_isr_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 00001b shl 3 + 0000b
	sys_encode_mair_el1:		dw	011b shl 14 + 0000b shl 11 + 01010b shl 7 + 00010b shl 3 + 0000b
	sys_encode_mair_el2:		dw	011b shl 14 + 0100b shl 11 + 01010b shl 7 + 00010b shl 3 + 0000b
	sys_encode_mair_el3:		dw	011b shl 14 + 0110b shl 11 + 01010b shl 7 + 00010b shl 3 + 0000b
	sys_encode_mdccint_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0000b
	sys_encode_mdccsr_el0:		dw	010b shl 14 + 0011b shl 11 + 00000b shl 7 + 00001b shl 3 + 0000b
	sys_encode_mdcr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00001b shl 3 + 0001b
	sys_encode_mdcr_el3:		dw	011b shl 14 + 0110b shl 11 + 00001b shl 7 + 00011b shl 3 + 0001b
	sys_encode_mdrar_el1:		dw	010b shl 14 + 0000b shl 11 + 00001b shl 7 + 00000b shl 3 + 0000b
	sys_encode_mdscr_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00010b shl 3 + 0010b
	sys_encode_midr_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0000b
	sys_encode_mpidr_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0101b
	sys_encode_mvfr0_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0000b
	sys_encode_mvfr1_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0001b
	sys_encode_mvfr2_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0010b
	sys_encode_nzcv:		dw	011b shl 14 + 0011b shl 11 + 00100b shl 7 + 00010b shl 3 + 0000b
	sys_encode_osdlr_el1:		dw	010b shl 14 + 0000b shl 11 + 00001b shl 7 + 00011b shl 3 + 0100b
	sys_encode_osdtrrx_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0010b
	sys_encode_osdtrtx_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00011b shl 3 + 0010b
	sys_encode_oseccr_el1:		dw	010b shl 14 + 0000b shl 11 + 00000b shl 7 + 00110b shl 3 + 0010b
	sys_encode_oslar_el1:		dw	010b shl 14 + 0000b shl 11 + 00001b shl 7 + 00000b shl 3 + 0100b
	sys_encode_oslsr_el1:		dw	010b shl 14 + 0000b shl 11 + 00001b shl 7 + 00001b shl 3 + 0100b
	sys_encode_par_el1:		dw	011b shl 14 + 0000b shl 11 + 00111b shl 7 + 00100b shl 3 + 0000b
	sys_encode_pmccfiltr_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0111b
	sys_encode_pmccntr_el0:		dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01101b shl 3 + 0000b
	sys_encode_pmceid0_el0:		dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0110b
	sys_encode_pmceid1_el0:		dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0111b
	sys_encode_pmcntenclr_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0010b
	sys_encode_pmcntenset_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0001b
	sys_encode_pmcr_el0:		dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0000b
	sys_encode_pmevcntr0_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0000b
	sys_encode_pmevcntr1_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0001b
	sys_encode_pmevcntr10_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0010b
	sys_encode_pmevcntr11_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0011b
	sys_encode_pmevcntr12_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0100b
	sys_encode_pmevcntr13_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0101b
	sys_encode_pmevcntr14_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0110b
	sys_encode_pmevcntr15_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0111b
	sys_encode_pmevcntr16_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0000b
	sys_encode_pmevcntr17_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0001b
	sys_encode_pmevcntr18_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0010b
	sys_encode_pmevcntr19_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0011b
	sys_encode_pmevcntr2_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0010b
	sys_encode_pmevcntr20_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0100b
	sys_encode_pmevcntr21_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0101b
	sys_encode_pmevcntr22_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0110b
	sys_encode_pmevcntr23_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01010b shl 3 + 0111b
	sys_encode_pmevcntr24_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0000b
	sys_encode_pmevcntr25_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0001b
	sys_encode_pmevcntr26_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0010b
	sys_encode_pmevcntr27_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0011b
	sys_encode_pmevcntr28_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0100b
	sys_encode_pmevcntr29_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0101b
	sys_encode_pmevcntr3_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0011b
	sys_encode_pmevcntr30_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01011b shl 3 + 0110b
	sys_encode_pmevcntr4_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0100b
	sys_encode_pmevcntr5_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0101b
	sys_encode_pmevcntr6_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0110b
	sys_encode_pmevcntr7_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01000b shl 3 + 0111b
	sys_encode_pmevcntr8_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0000b
	sys_encode_pmevcntr9_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01001b shl 3 + 0001b
	sys_encode_pmevtyper0_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0000b
	sys_encode_pmevtyper1_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0001b
	sys_encode_pmevtyper10_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0010b
	sys_encode_pmevtyper11_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0011b
	sys_encode_pmevtyper12_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0100b
	sys_encode_pmevtyper13_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0101b
	sys_encode_pmevtyper14_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0110b
	sys_encode_pmevtyper15_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0111b
	sys_encode_pmevtyper16_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0000b
	sys_encode_pmevtyper17_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0001b
	sys_encode_pmevtyper18_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0010b
	sys_encode_pmevtyper19_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0011b
	sys_encode_pmevtyper2_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0010b
	sys_encode_pmevtyper20_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0100b
	sys_encode_pmevtyper21_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0101b
	sys_encode_pmevtyper22_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0110b
	sys_encode_pmevtyper23_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01110b shl 3 + 0111b
	sys_encode_pmevtyper24_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0000b
	sys_encode_pmevtyper25_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0001b
	sys_encode_pmevtyper26_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0010b
	sys_encode_pmevtyper27_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0011b
	sys_encode_pmevtyper28_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0100b
	sys_encode_pmevtyper29_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0101b
	sys_encode_pmevtyper3_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0011b
	sys_encode_pmevtyper30_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01111b shl 3 + 0110b
	sys_encode_pmevtyper4_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0100b
	sys_encode_pmevtyper5_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0101b
	sys_encode_pmevtyper6_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0110b
	sys_encode_pmevtyper7_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01100b shl 3 + 0111b
	sys_encode_pmevtyper8_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0000b
	sys_encode_pmevtyper9_el0:	dw	011b shl 14 + 0011b shl 11 + 01110b shl 7 + 01101b shl 3 + 0001b
	sys_encode_pmintenclr_el1:	dw	011b shl 14 + 0000b shl 11 + 01001b shl 7 + 01110b shl 3 + 0010b
	sys_encode_pmintenset_el1:	dw	011b shl 14 + 0000b shl 11 + 01001b shl 7 + 01110b shl 3 + 0001b
	sys_encode_pmovsclr_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0011b
	sys_encode_pmovsset_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01110b shl 3 + 0011b
	sys_encode_pmselr_el0:		dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0101b
	sys_encode_pmswinc_el0:		dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01100b shl 3 + 0100b
	sys_encode_pmuserenr_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01110b shl 3 + 0000b
	sys_encode_pmxevcntr_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01101b shl 3 + 0010b
	sys_encode_pmxevtyper_el0:	dw	011b shl 14 + 0011b shl 11 + 01001b shl 7 + 01101b shl 3 + 0001b
	sys_encode_revidr_el1:		dw	011b shl 14 + 0000b shl 11 + 00000b shl 7 + 00000b shl 3 + 0110b
	sys_encode_rmr_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 00000b shl 3 + 0010b
	sys_encode_rmr_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 00000b shl 3 + 0010b
	sys_encode_rmr_el3:		dw	011b shl 14 + 0110b shl 11 + 01100b shl 7 + 00000b shl 3 + 0010b
	sys_encode_rvbar_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 00000b shl 3 + 0001b
	sys_encode_rvbar_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 00000b shl 3 + 0001b
	sys_encode_rvbar_el3:		dw	011b shl 14 + 0110b shl 11 + 01100b shl 7 + 00000b shl 3 + 0001b
	sys_encode_scr_el3:		dw	011b shl 14 + 0110b shl 11 + 00001b shl 7 + 00001b shl 3 + 0000b
	sys_encode_sctlr_el1:		dw	011b shl 14 + 0000b shl 11 + 00001b shl 7 + 00000b shl 3 + 0000b
	sys_encode_sctlr_el2:		dw	011b shl 14 + 0100b shl 11 + 00001b shl 7 + 00000b shl 3 + 0000b
	sys_encode_sctlr_el3:		dw	011b shl 14 + 0110b shl 11 + 00001b shl 7 + 00000b shl 3 + 0000b
	sys_encode_sder32_el3:		dw	011b shl 14 + 0110b shl 11 + 00001b shl 7 + 00001b shl 3 + 0001b
	sys_encode_sp_el0:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00001b shl 3 + 0000b
	sys_encode_sp_el1:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00001b shl 3 + 0000b
	sys_encode_sp_el2:		dw	011b shl 14 + 0110b shl 11 + 00100b shl 7 + 00001b shl 3 + 0000b
	sys_encode_spsel:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00010b shl 3 + 0000b
	sys_encode_spsr_abt:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00011b shl 3 + 0001b
	sys_encode_spsr_el1:		dw	011b shl 14 + 0000b shl 11 + 00100b shl 7 + 00000b shl 3 + 0000b
	sys_encode_spsr_el2:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00000b shl 3 + 0000b
	sys_encode_spsr_el3:		dw	011b shl 14 + 0110b shl 11 + 00100b shl 7 + 00000b shl 3 + 0000b
	sys_encode_spsr_fiq:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00011b shl 3 + 0011b
	sys_encode_spsr_irq:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00011b shl 3 + 0000b
	sys_encode_spsr_und:		dw	011b shl 14 + 0100b shl 11 + 00100b shl 7 + 00011b shl 3 + 0010b
	sys_encode_tcr_el1:		dw	011b shl 14 + 0000b shl 11 + 00010b shl 7 + 00000b shl 3 + 0010b
	sys_encode_tcr_el2:		dw	011b shl 14 + 0100b shl 11 + 00010b shl 7 + 00000b shl 3 + 0010b
	sys_encode_tcr_el3:		dw	011b shl 14 + 0110b shl 11 + 00010b shl 7 + 00000b shl 3 + 0010b
	sys_encode_tpidr_el0:		dw	011b shl 14 + 0011b shl 11 + 01101b shl 7 + 00000b shl 3 + 0010b
	sys_encode_tpidr_el1:		dw	011b shl 14 + 0000b shl 11 + 01101b shl 7 + 00000b shl 3 + 0100b
	sys_encode_tpidr_el2:		dw	011b shl 14 + 0100b shl 11 + 01101b shl 7 + 00000b shl 3 + 0010b
	sys_encode_tpidr_el3:		dw	011b shl 14 + 0110b shl 11 + 01101b shl 7 + 00000b shl 3 + 0010b
	sys_encode_tpidrro_el0:		dw	011b shl 14 + 0011b shl 11 + 01101b shl 7 + 00000b shl 3 + 0011b
	sys_encode_ttbr0_el1:		dw	011b shl 14 + 0000b shl 11 + 00010b shl 7 + 00000b shl 3 + 0000b
	sys_encode_ttbr0_el2:		dw	011b shl 14 + 0100b shl 11 + 00010b shl 7 + 00000b shl 3 + 0000b
	sys_encode_ttbr0_el3:		dw	011b shl 14 + 0110b shl 11 + 00010b shl 7 + 00000b shl 3 + 0000b
	sys_encode_ttbr1_el1:		dw	011b shl 14 + 0000b shl 11 + 00010b shl 7 + 00000b shl 3 + 0001b
	sys_encode_vbar_el1:		dw	011b shl 14 + 0000b shl 11 + 01100b shl 7 + 00000b shl 3 + 0000b
	sys_encode_vbar_el2:		dw	011b shl 14 + 0100b shl 11 + 01100b shl 7 + 00000b shl 3 + 0000b
	sys_encode_vbar_el3:		dw	011b shl 14 + 0110b shl 11 + 01100b shl 7 + 00000b shl 3 + 0000b
	sys_encode_vmpidr_el2:		dw	011b shl 14 + 0100b shl 11 + 00000b shl 7 + 00000b shl 3 + 0101b
	sys_encode_vpidr_el2:		dw	011b shl 14 + 0100b shl 11 + 00000b shl 7 + 00000b shl 3 + 0000b
	sys_encode_vtcr_el2:		dw	011b shl 14 + 0100b shl 11 + 00010b shl 7 + 00001b shl 3 + 0010b
	sys_encode_vttbr_el2:		dw	011b shl 14 + 0100b shl 11 + 00010b shl 7 + 00001b shl 3 + 0000b
sys_encode_table_pstate:
	;msr imm				op0           op1            crn            crm            op2
	sys_pencode_daifclr:		dw	000b shl 14 + 0011b shl 11 + 00100b shl 7 + 00000b shl 3 + 0111b
	sys_pencode_daifset:		dw	000b shl 14 + 0011b shl 11 + 00100b shl 7 + 00000b shl 3 + 0110b
	sys_pencode_spsel:		dw	000b shl 14 + 0000b shl 11 + 00100b shl 7 + 00000b shl 3 + 0101b

data_directives:
	dw	data_directives_2-data_directives,(data_directives_3-data_directives_2)/(2+3)
	dw	data_directives_3-data_directives,(data_directives_4-data_directives_3)/(3+3)
	dw	data_directives_4-data_directives,(data_directives_end-data_directives_4)/(4+3)

data_directives_2:
	db	'db',1
	dw	data_bytes-instruction_handler
	db	'dd',8
	dw	data_qwords-instruction_handler		;ARM dwords
	db	'dh',2
	dw	data_words-instruction_handler		;ARM hwords
	db	'du',2
	dw	data_unicode-instruction_handler
	db	'dw',4
	dw	data_dwords-instruction_handler		;ARM words
	db	'rb',1
	dw	reserve_bytes-instruction_handler
	db	'rd',8
	dw	reserve_qwords-instruction_handler	;ARM dwords
	db	'rh',2
	dw	reserve_words-instruction_handler	;ARM hwords
	db	'rw',4
	dw	reserve_dwords-instruction_handler	;ARM words
data_directives_3:
data_directives_4:
	db	'file',1
	dw	data_file-instruction_handler
data_directives_end:

instructions:
	dd	instructions_1-instructions,(instructions_2-instructions_1)/(1+3)
	dd	instructions_2-instructions,(instructions_3-instructions_2)/(2+3)
	dd	instructions_3-instructions,(instructions_4-instructions_3)/(3+3)
	dd	instructions_4-instructions,(instructions_5-instructions_4)/(4+3)
	dd	instructions_5-instructions,(instructions_6-instructions_5)/(5+3)
	dd	instructions_6-instructions,(instructions_7-instructions_6)/(6+3)
	dd	instructions_7-instructions,(instructions_8-instructions_7)/(7+3)
	dd	instructions_8-instructions,(instructions_9-instructions_8)/(8+3)
	dd	instructions_9-instructions,(instructions_10-instructions_9)/(9+3)
	dd	instructions_10-instructions,(instructions_11-instructions_10)/(10+3)
	dd	instructions_11-instructions,(instructions_12-instructions_11)/(11+3)
	dd	instructions_12-instructions,(instructions_13-instructions_12)/(12+3)
	dd	instructions_13-instructions,(instructions_14-instructions_13)/(13+3)
	dd	instructions_14-instructions,(instructions_15-instructions_14)/(14+3)
	dd	instructions_15-instructions,(instructions_16-instructions_15)/(15+3)
	dd	instructions_16-instructions,(instructions_end-instructions_16)/(16+3)
instructions_1:
	db	'b',0xe0
	dw	ARM_instruction_b-instruction_handler
	db	0
instructions_2:
	db	'at',0xf0
	dw	ARM_instruction_at-instruction_handler
	db	'bl',0xe0
	dw	ARM_instruction_bl-instruction_handler
	db	'br',0xf0
	dw	ARM_instruction_br-instruction_handler
	db	'bx',0xe0
	dw	ARM_instruction_bx-instruction_handler
	db	'dc',0xf0
	dw	ARM_instruction_dc-instruction_handler
	db	'hb',0xe0
	dw	ARM_instruction_hb-instruction_handler
	db	'ic',0xf0
	dw	ARM_instruction_ic-instruction_handler
	db	'if',0x00
	dw	if_directive-instruction_handler
	db	'it',0xf0
	dw	ARM_instruction_it-instruction_handler
	db	0
instructions_3:
	db	'abs',0xf0
	dw	ARM_instruction_abs-instruction_handler
	db	'adc',0xe0
	dw	ARM_instruction_adc-instruction_handler
	db	'add',0xe0
	dw	ARM_instruction_add-instruction_handler
	db	'adr',0xe0
	dw	ARM_instruction_adr-instruction_handler
	db	'and',0xe0
	dw	ARM_instruction_and-instruction_handler
	db	'asr',0xe0
	dw	ARM_instruction_asr-instruction_handler
	db	'b.n',0xe4
	dw	ARM_instruction_b-instruction_handler
	db	'b.w',0xe2
	dw	ARM_instruction_b-instruction_handler
	db	'bfc',0xe0
	dw	ARM_instruction_bfc-instruction_handler
	db	'bfi',0xe0
	dw	ARM_instruction_bfi-instruction_handler
	db	'bfm',0xf0
	dw	ARM_instruction_bfm-instruction_handler
	db	'bic',0xe0
	dw	ARM_instruction_bic-instruction_handler
	db	'bif',0xf0
	dw	ARM_instruction_bif-instruction_handler
	db	'bit',0xf0
	dw	ARM_instruction_bit-instruction_handler
	db	'blr',0xf0
	dw	ARM_instruction_blr-instruction_handler
	db	'blx',0xe0
	dw	ARM_instruction_blx-instruction_handler
	db	'brk',0xf0
	dw	ARM_instruction_brk-instruction_handler
	db	'bsl',0xf0
	dw	ARM_instruction_bsl-instruction_handler
	db	'bxj',0xe0
	dw	ARM_instruction_bxj-instruction_handler
	db	'b~~',0x00
	dw	ARM_instruction_b-instruction_handler
	db	'cbz',0xf0
	dw	ARM_instruction_cbz-instruction_handler
	db	'cdp',0xe0
	dw	ARM_instruction_cdp-instruction_handler
	db	'cls',0xf0
	dw	ARM_instruction_cls-instruction_handler
	db	'clz',0xe0
	dw	ARM_instruction_clz-instruction_handler
	db	'cmf',0xe0
	dw	ARM_instruction_cmf-instruction_handler
	db	'cmn',0xe0
	dw	ARM_instruction_cmn-instruction_handler
	db	'cmp',0xe0
	dw	ARM_instruction_cmp-instruction_handler
	db	'cnf',0xe0
	dw	ARM_instruction_cnf-instruction_handler
	db	'cnt',0xf0
	dw	ARM_instruction_cnt-instruction_handler
	db	'cps',0xf0
	dw	ARM_instruction_cps-instruction_handler
	db	'cpy',0xe0
	dw	ARM_instruction_cpy-instruction_handler
	db	'dbg',0xe0
	dw	ARM_instruction_dbg-instruction_handler
	db	'dmb',0xf0
	dw	ARM_instruction_dmb-instruction_handler
	db	'dsb',0xf0
	dw	ARM_instruction_dsb-instruction_handler
	db	'dup',0xf0
	dw	ARM_instruction_dup-instruction_handler
	db	'end',0x00
	dw	end_directive-instruction_handler
	db	'eon',0xf0
	dw	ARM_instruction_eon-instruction_handler
	db	'eor',0xe0
	dw	ARM_instruction_eor-instruction_handler
	db	'err',0x00
	dw	err_directive-instruction_handler
	db	'ext',0xf0
	dw	ARM_instruction_ext-instruction_handler
	db	'fix',0xe0
	dw	ARM_instruction_fix-instruction_handler
	db	'hbl',0xe0
	dw	ARM_instruction_hbl-instruction_handler
	db	'hbp',0xe0
	dw	ARM_instruction_hbp-instruction_handler
	db	'hlt',0xe0
	dw	ARM_instruction_hlt-instruction_handler
	db	'hvc',0xe0
	dw	ARM_instruction_hvc-instruction_handler
	db	'ins',0xf0
	dw	ARM_instruction_ins-instruction_handler
	db	'isb',0xf0
	dw	ARM_instruction_isb-instruction_handler
	db	'ite',0xf0
	dw	ARM_instruction_ite-instruction_handler
	db	'itt',0xf0
	dw	ARM_instruction_itt-instruction_handler
	db	'ld1',0xf0
	dw	ARM_instruction_ld1-instruction_handler
	db	'ld2',0xf0
	dw	ARM_instruction_ld2-instruction_handler
	db	'ld3',0xf0
	dw	ARM_instruction_ld3-instruction_handler
	db	'ld4',0xf0
	dw	ARM_instruction_ld4-instruction_handler
	db	'lda',0xe0
	dw	ARM_instruction_lda-instruction_handler
	db	'ldc',0xe0
	dw	ARM_instruction_ldc-instruction_handler
	db	'ldm',0xe0
	dw	ARM_instruction_ldm-instruction_handler
	db	'ldp',0xf0
	dw	ARM_instruction_ldp-instruction_handler
	db	'ldr',0xe0
	dw	ARM_instruction_ldr-instruction_handler
	db	'lfm',0xe0
	dw	ARM_instruction_lfm-instruction_handler
	db	'lsl',0xe0
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsr',0xe0
	dw	ARM_instruction_lsr-instruction_handler
	db	'mar',0xe0
	dw	ARM_instruction_mar-instruction_handler
	db	'mcr',0xe0
	dw	ARM_instruction_mcr-instruction_handler
	db	'mia',0xe0
	dw	ARM_instruction_mia-instruction_handler
	db	'mla',0xe0
	dw	ARM_instruction_mla-instruction_handler
	db	'mls',0xe0
	dw	ARM_instruction_mls-instruction_handler
	db	'mov',0xe0
	dw	ARM_instruction_mov-instruction_handler
	db	'mra',0xe0
	dw	ARM_instruction_mra-instruction_handler
	db	'mrc',0xe0
	dw	ARM_instruction_mrc-instruction_handler
	db	'mrs',0xe0
	dw	ARM_instruction_mrs-instruction_handler
	db	'msr',0xe0
	dw	ARM_instruction_msr-instruction_handler
	db	'mul',0xe0
	dw	ARM_instruction_mul-instruction_handler
	db	'mvn',0xe0
	dw	ARM_instruction_mvn-instruction_handler
	db	'neg',0xe0
	dw	ARM_instruction_neg-instruction_handler
	db	'ngc',0xf0
	dw	ARM_instruction_ngc-instruction_handler
	db	'nop',0xe0
	dw	ARM_instruction_nop-instruction_handler
	db	'not',0xf0
	dw	ARM_instruction_not-instruction_handler
	db	'org',0x00
	dw	ARM_org_directive-instruction_handler
	db	'orn',0xe0
	dw	ARM_instruction_orn-instruction_handler
	db	'orr',0xe0
	dw	ARM_instruction_orr-instruction_handler
	db	'pld',0xe0
	dw	ARM_instruction_pld-instruction_handler
	db	'pli',0xe0
	dw	ARM_instruction_pli-instruction_handler
	db	'pop',0xe0
	dw	ARM_instruction_pop-instruction_handler
	db	'ret',0xf0
	dw	ARM_instruction_ret-instruction_handler
	db	'rev',0xe0
	dw	ARM_instruction_rev-instruction_handler
	db	'rfc',0xe0
	dw	ARM_instruction_rfc-instruction_handler
	db	'rfe',0xf0
	dw	ARM_instruction_rfe-instruction_handler
	db	'rfs',0xe0
	dw	ARM_instruction_rfs-instruction_handler
	db	'ror',0xe0
	dw	ARM_instruction_ror-instruction_handler
	db	'rrx',0xe0
	dw	ARM_instruction_rrx-instruction_handler
	db	'rsb',0xe0
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsc',0xe0
	dw	ARM_instruction_rsc-instruction_handler
	db	'sbc',0xe0
	dw	ARM_instruction_sbc-instruction_handler
	db	'sel',0xe0
	dw	ARM_instruction_sel-instruction_handler
	db	'sev',0xe0
	dw	ARM_instruction_sev-instruction_handler
	db	'sfm',0xe0
	dw	ARM_instruction_sfm-instruction_handler
	db	'shl',0xf0
	dw	ARM_instruction_shl-instruction_handler
	db	'sli',0xf0
	dw	ARM_instruction_sli-instruction_handler
	db	'smc',0xe0
	dw	ARM_instruction_smc-instruction_handler
	db	'smi',0xe0
	dw	ARM_instruction_smi-instruction_handler
	db	'sri',0xf0
	dw	ARM_instruction_sri-instruction_handler
	db	'srs',0xf0
	dw	ARM_instruction_srs-instruction_handler
	db	'st1',0xf0
	dw	ARM_instruction_st1-instruction_handler
	db	'st2',0xf0
	dw	ARM_instruction_st2-instruction_handler
	db	'st3',0xf0
	dw	ARM_instruction_st3-instruction_handler
	db	'st4',0xf0
	dw	ARM_instruction_st4-instruction_handler
	db	'stc',0xe0
	dw	ARM_instruction_stc-instruction_handler
	db	'stl',0xe0
	dw	ARM_instruction_stl-instruction_handler
	db	'stm',0xe0
	dw	ARM_instruction_stm-instruction_handler
	db	'stp',0xf0
	dw	ARM_instruction_stp-instruction_handler
	db	'str',0xe0
	dw	ARM_instruction_str-instruction_handler
	db	'sub',0xe0
	dw	ARM_instruction_sub-instruction_handler
	db	'svc',0xe0
	dw	ARM_instruction_svc-instruction_handler
	db	'swi',0xe0
	dw	ARM_instruction_swi-instruction_handler
	db	'swp',0xe0
	dw	ARM_instruction_swp-instruction_handler
	db	'sys',0xf0
	dw	ARM_instruction_sys-instruction_handler
	db	'tbb',0xe0
	dw	ARM_instruction_tbb-instruction_handler
	db	'tbh',0xe0
	dw	ARM_instruction_tbh-instruction_handler
	db	'tbl',0xf0
	dw	ARM_instruction_tbl-instruction_handler
	db	'tbx',0xf0
	dw	ARM_instruction_tbx-instruction_handler
	db	'tbz',0xf0
	dw	ARM_instruction_tbz-instruction_handler
	db	'teq',0xe0
	dw	ARM_instruction_teq-instruction_handler
	db	'tst',0xe0
	dw	ARM_instruction_tst-instruction_handler
	db	'und',0xe0
	dw	ARM_instruction_und-instruction_handler
	db	'wfc',0xe0
	dw	ARM_instruction_wfc-instruction_handler
	db	'wfe',0xe0
	dw	ARM_instruction_wfe-instruction_handler
	db	'wfi',0xe0
	dw	ARM_instruction_wfi-instruction_handler
	db	'wfs',0xe0
	dw	ARM_instruction_wfs-instruction_handler
	db	'wor',0xe0
	dw	ARM_instruction_wor-instruction_handler
	db	'xtn',0xf0
	dw	ARM_instruction_xtn-instruction_handler
	db	0
instructions_4:
	db	'absd',0xe0
	dw	ARM_instruction_absd-instruction_handler
	db	'abse',0xe0
	dw	ARM_instruction_abse-instruction_handler
	db	'abss',0xe0
	dw	ARM_instruction_abss-instruction_handler
	db	'acsd',0xe0
	dw	ARM_instruction_acsd-instruction_handler
	db	'acse',0xe0
	dw	ARM_instruction_acse-instruction_handler
	db	'acss',0xe0
	dw	ARM_instruction_acss-instruction_handler
	db	'adcs',0xe1
	dw	ARM_instruction_adc-instruction_handler
	db	'addp',0xf0
	dw	ARM_instruction_addp-instruction_handler
	db	'adds',0xe1
	dw	ARM_instruction_add-instruction_handler
	db	'addv',0xf0
	dw	ARM_instruction_addv-instruction_handler
	db	'addw',0xe0
	dw	ARM_instruction_addw-instruction_handler
	db	'adfd',0xe0
	dw	ARM_instruction_adfd-instruction_handler
	db	'adfe',0xe0
	dw	ARM_instruction_adfe-instruction_handler
	db	'adfs',0xe0
	dw	ARM_instruction_adfs-instruction_handler
	db	'adrp',0xf0
	dw	ARM_instruction_adrp-instruction_handler
	db	'aesd',0xf0
	dw	ARM_instruction_aesd-instruction_handler
	db	'aese',0xf0
	dw	ARM_instruction_aese-instruction_handler
	db	'ands',0xe1
	dw	ARM_instruction_and-instruction_handler
	db	'asnd',0xe0
	dw	ARM_instruction_asnd-instruction_handler
	db	'asne',0xe0
	dw	ARM_instruction_asne-instruction_handler
	db	'asns',0xe0
	dw	ARM_instruction_asns-instruction_handler
	db	'asrs',0xe1
	dw	ARM_instruction_asr-instruction_handler
	db	'asrv',0xf0
	dw	ARM_instruction_asrv-instruction_handler
	db	'atnd',0xe0
	dw	ARM_instruction_atnd-instruction_handler
	db	'atne',0xe0
	dw	ARM_instruction_atne-instruction_handler
	db	'atns',0xe0
	dw	ARM_instruction_atns-instruction_handler
	db	'b.al',0xf0
	dw	ARM_instruction_b.al-instruction_handler
	db	'b.cc',0xf0
	dw	ARM_instruction_b.cc-instruction_handler
	db	'b.cs',0xf0
	dw	ARM_instruction_b.cs-instruction_handler
	db	'b.eq',0xf0
	dw	ARM_instruction_b.eq-instruction_handler
	db	'b.ge',0xf0
	dw	ARM_instruction_b.ge-instruction_handler
	db	'b.gt',0xf0
	dw	ARM_instruction_b.gt-instruction_handler
	db	'b.hi',0xf0
	dw	ARM_instruction_b.hi-instruction_handler
	db	'b.hs',0xf0
	dw	ARM_instruction_b.hs-instruction_handler
	db	'b.le',0xf0
	dw	ARM_instruction_b.le-instruction_handler
	db	'b.lo',0xf0
	dw	ARM_instruction_b.lo-instruction_handler
	db	'b.ls',0xf0
	dw	ARM_instruction_b.ls-instruction_handler
	db	'b.lt',0xf0
	dw	ARM_instruction_b.lt-instruction_handler
	db	'b.mi',0xf0
	dw	ARM_instruction_b.mi-instruction_handler
	db	'b.ne',0xf0
	dw	ARM_instruction_b.ne-instruction_handler
	db	'b.nv',0xf0
	dw	ARM_instruction_b.nv-instruction_handler
	db	'b.pl',0xf0
	dw	ARM_instruction_b.pl-instruction_handler
	db	'b.vc',0xf0
	dw	ARM_instruction_b.vc-instruction_handler
	db	'b.vs',0xf0
	dw	ARM_instruction_b.vs-instruction_handler
	db	'bics',0xe1
	dw	ARM_instruction_bic-instruction_handler
	db	'bkpt',0xe0
	dw	ARM_instruction_bkpt-instruction_handler
	db	'bl~~',0x00
	dw	ARM_instruction_bl-instruction_handler
	db	'bx.n',0xe4
	dw	ARM_instruction_bx-instruction_handler
	db	'bx.w',0xe2
	dw	ARM_instruction_bx-instruction_handler
	db	'bx~~',0x00
	dw	ARM_instruction_bx-instruction_handler
	db	'cbnz',0xf0
	dw	ARM_instruction_cbnz-instruction_handler
	db	'ccmn',0xf0
	dw	ARM_instruction_ccmn-instruction_handler
	db	'ccmp',0xf0
	dw	ARM_instruction_ccmp-instruction_handler
	db	'cdp2',0xe0
	dw	ARM_instruction_cdp2-instruction_handler
	db	'chka',0xe0
	dw	ARM_instruction_chka-instruction_handler
	db	'cinc',0xf0
	dw	ARM_instruction_cinc-instruction_handler
	db	'cinv',0xf0
	dw	ARM_instruction_cinv-instruction_handler
	db	'cmeq',0xf0
	dw	ARM_instruction_cmeq-instruction_handler
	db	'cmfe',0xe0
	dw	ARM_instruction_cmfe-instruction_handler
	db	'cmge',0xf0
	dw	ARM_instruction_cmge-instruction_handler
	db	'cmgt',0xf0
	dw	ARM_instruction_cmgt-instruction_handler
	db	'cmhi',0xf0
	dw	ARM_instruction_cmhi-instruction_handler
	db	'cmhs',0xf0
	dw	ARM_instruction_cmhs-instruction_handler
	db	'cmle',0xf0
	dw	ARM_instruction_cmle-instruction_handler
	db	'cmlt',0xf0
	dw	ARM_instruction_cmlt-instruction_handler
	db	'cmnp',0xe0
	dw	ARM_instruction_cmnp-instruction_handler
	db	'cmpp',0xe0
	dw	ARM_instruction_cmpp-instruction_handler
	db	'cneg',0xf0
	dw	ARM_instruction_cneg-instruction_handler
	db	'cnfe',0xe0
	dw	ARM_instruction_cnfe-instruction_handler
	db	'cosd',0xe0
	dw	ARM_instruction_cosd-instruction_handler
	db	'cose',0xe0
	dw	ARM_instruction_cose-instruction_handler
	db	'coss',0xe0
	dw	ARM_instruction_coss-instruction_handler
	db	'csel',0xf0
	dw	ARM_instruction_csel-instruction_handler
	db	'cset',0xf0
	dw	ARM_instruction_cset-instruction_handler
	db	'data',0x00
	dw	data_directive-instruction_handler
	db	'drps',0xf0
	dw	ARM_instruction_drps-instruction_handler
	db	'dvfd',0xe0
	dw	ARM_instruction_dvfd-instruction_handler
	db	'dvfe',0xe0
	dw	ARM_instruction_dvfe-instruction_handler
	db	'dvfs',0xe0
	dw	ARM_instruction_dvfs-instruction_handler
	db	'else',0x00
	dw	else_directive-instruction_handler
	db	'eors',0xe1
	dw	ARM_instruction_eor-instruction_handler
	db	'eret',0xe0
	dw	ARM_instruction_eret-instruction_handler
	db	'expd',0xe0
	dw	ARM_instruction_expd-instruction_handler
	db	'expe',0xe0
	dw	ARM_instruction_expe-instruction_handler
	db	'exps',0xe0
	dw	ARM_instruction_exps-instruction_handler
	db	'extr',0xf0
	dw	ARM_instruction_extr-instruction_handler
	db	'fabd',0xf0
	dw	ARM_instruction_fabd-instruction_handler
	db	'fabs',0xf0
	dw	ARM_instruction_fabs-instruction_handler
	db	'fadd',0xf0
	dw	ARM_instruction_fadd-instruction_handler
	db	'fcmp',0xf0
	dw	ARM_instruction_fcmp-instruction_handler
	db	'fcvt',0xf0
	dw	ARM_instruction_fcvt-instruction_handler
	db	'fdiv',0xf0
	dw	ARM_instruction_fdiv-instruction_handler
	db	'fdvd',0xe0
	dw	ARM_instruction_fdvd-instruction_handler
	db	'fdve',0xe0
	dw	ARM_instruction_fdve-instruction_handler
	db	'fdvs',0xe0
	dw	ARM_instruction_fdvs-instruction_handler
	db	'fixm',0xe0
	dw	ARM_instruction_fixm-instruction_handler
	db	'fixp',0xe0
	dw	ARM_instruction_fixp-instruction_handler
	db	'fixz',0xe0
	dw	ARM_instruction_fixz-instruction_handler
	db	'fldd',0xe0
	dw	ARM_instruction_fldd-instruction_handler
	db	'flds',0xe0
	dw	ARM_instruction_flds-instruction_handler
	db	'fltd',0xe0
	dw	ARM_instruction_fltd-instruction_handler
	db	'flte',0xe0
	dw	ARM_instruction_flte-instruction_handler
	db	'flts',0xe0
	dw	ARM_instruction_flts-instruction_handler
	db	'fmax',0xf0
	dw	ARM_instruction_fmax-instruction_handler
	db	'fmin',0xf0
	dw	ARM_instruction_fmin-instruction_handler
	db	'fmla',0xf0
	dw	ARM_instruction_fmla-instruction_handler
	db	'fmld',0xe0
	dw	ARM_instruction_fmld-instruction_handler
	db	'fmle',0xe0
	dw	ARM_instruction_fmle-instruction_handler
	db	'fmls',0xe0
	dw	ARM_instruction_fmls-instruction_handler
	db	'fmov',0xf0
	dw	ARM_instruction_fmov-instruction_handler
	db	'fmrs',0xe0
	dw	ARM_instruction_fmrs-instruction_handler
	db	'fmrx',0xe0
	dw	ARM_instruction_fmrx-instruction_handler
	db	'fmsr',0xe0
	dw	ARM_instruction_fmsr-instruction_handler
	db	'fmul',0xf0
	dw	ARM_instruction_fmul-instruction_handler
	db	'fmxr',0xe0
	dw	ARM_instruction_fmxr-instruction_handler
	db	'fneg',0xf0
	dw	ARM_instruction_fneg-instruction_handler
	db	'frdd',0xe0
	dw	ARM_instruction_frdd-instruction_handler
	db	'frde',0xe0
	dw	ARM_instruction_frde-instruction_handler
	db	'frds',0xe0
	dw	ARM_instruction_frds-instruction_handler
	db	'fstd',0xe0
	dw	ARM_instruction_fstd-instruction_handler
	db	'fsts',0xe0
	dw	ARM_instruction_fsts-instruction_handler
	db	'fsub',0xf0
	dw	ARM_instruction_fsub-instruction_handler
	db	'hblp',0xe0
	dw	ARM_instruction_hblp-instruction_handler
	db	'hb~~',0x00
	dw	ARM_instruction_hb-instruction_handler
	db	'heap',0x00
	dw	heap_directive-instruction_handler
	db	'hint',0xf0
	dw	ARM_instruction_hint-instruction_handler
	db	'itee',0xf0
	dw	ARM_instruction_itee-instruction_handler
	db	'itet',0xf0
	dw	ARM_instruction_itet-instruction_handler
	db	'itte',0xf0
	dw	ARM_instruction_itte-instruction_handler
	db	'ittt',0xf0
	dw	ARM_instruction_ittt-instruction_handler
	db	'ld1r',0xf0
	dw	ARM_instruction_ld1r-instruction_handler
	db	'ld2r',0xf0
	dw	ARM_instruction_ld2r-instruction_handler
	db	'ld3r',0xf0
	dw	ARM_instruction_ld3r-instruction_handler
	db	'ld4r',0xf0
	dw	ARM_instruction_ld4r-instruction_handler
	db	'ldab',0xe0
	dw	ARM_instruction_ldab-instruction_handler
	db	'ldah',0xe0
	dw	ARM_instruction_ldah-instruction_handler
	db	'ldar',0xf0
	dw	ARM_instruction_ldar-instruction_handler
	db	'ldc2',0xe0
	dw	ARM_instruction_ldc2-instruction_handler
	db	'ldcl',0xe0
	dw	ARM_instruction_ldcl-instruction_handler
	db	'ldfd',0xe0
	dw	ARM_instruction_ldfd-instruction_handler
	db	'ldfe',0xe0
	dw	ARM_instruction_ldfe-instruction_handler
	db	'ldfp',0xe0
	dw	ARM_instruction_ldfp-instruction_handler
	db	'ldfs',0xe0
	dw	ARM_instruction_ldfs-instruction_handler
	db	'ldnp',0xf0
	dw	ARM_instruction_ldnp-instruction_handler
	db	'ldrb',0xe0
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldrd',0xe0
	dw	ARM_instruction_ldrd-instruction_handler
	db	'ldrh',0xe0
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldrt',0xe0
	dw	ARM_instruction_ldrt-instruction_handler
	db	'ldtr',0xf0
	dw	ARM_instruction_ldtr-instruction_handler
	db	'ldur',0xf0
	dw	ARM_instruction_ldur-instruction_handler
	db	'ldxp',0xf0
	dw	ARM_instruction_ldxp-instruction_handler
	db	'ldxr',0xf0
	dw	ARM_instruction_ldxr-instruction_handler
	db	'lgnd',0xe0
	dw	ARM_instruction_lgnd-instruction_handler
	db	'lgne',0xe0
	dw	ARM_instruction_lgne-instruction_handler
	db	'lgns',0xe0
	dw	ARM_instruction_lgns-instruction_handler
	db	'load',0x00
	dw	load_directive-instruction_handler
	db	'logd',0xe0
	dw	ARM_instruction_logd-instruction_handler
	db	'loge',0xe0
	dw	ARM_instruction_loge-instruction_handler
	db	'logs',0xe0
	dw	ARM_instruction_logs-instruction_handler
	db	'lsls',0xe1
	dw	ARM_instruction_lsl-instruction_handler
	db	'lslv',0xf0
	dw	ARM_instruction_lslv-instruction_handler
	db	'lsrs',0xe1
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsrv',0xf0
	dw	ARM_instruction_lsrv-instruction_handler
	db	'madd',0xf0
	dw	ARM_instruction_madd-instruction_handler
	db	'mcr2',0xe0
	dw	ARM_instruction_mcr2-instruction_handler
	db	'mcrr',0xe0
	dw	ARM_instruction_mcrr-instruction_handler
	db	'mlas',0xe1
	dw	ARM_instruction_mla-instruction_handler
	db	'mneg',0xf0
	dw	ARM_instruction_mneg-instruction_handler
	db	'mnfd',0xe0
	dw	ARM_instruction_mnfd-instruction_handler
	db	'mnfe',0xe0
	dw	ARM_instruction_mnfe-instruction_handler
	db	'mnfs',0xe0
	dw	ARM_instruction_mnfs-instruction_handler
	db	'movi',0xf0
	dw	ARM_instruction_movi-instruction_handler
	db	'movk',0xf0
	dw	ARM_instruction_movk-instruction_handler
	db	'movn',0xf0
	dw	ARM_instruction_movn-instruction_handler
	db	'movs',0xe1
	dw	ARM_instruction_mov-instruction_handler
	db	'movt',0xe0
	dw	ARM_instruction_movt-instruction_handler
	db	'movw',0xe0
	dw	ARM_instruction_movw-instruction_handler
	db	'movz',0xf0
	dw	ARM_instruction_movz-instruction_handler
	db	'mrc2',0xe0
	dw	ARM_instruction_mrc2-instruction_handler
	db	'mrrc',0xe0
	dw	ARM_instruction_mrrc-instruction_handler
	db	'msub',0xf0
	dw	ARM_instruction_msub-instruction_handler
	db	'mufd',0xe0
	dw	ARM_instruction_mufd-instruction_handler
	db	'mufe',0xe0
	dw	ARM_instruction_mufe-instruction_handler
	db	'mufs',0xe0
	dw	ARM_instruction_mufs-instruction_handler
	db	'muls',0xe1
	dw	ARM_instruction_mul-instruction_handler
	db	'mvfd',0xe0
	dw	ARM_instruction_mvfd-instruction_handler
	db	'mvfe',0xe0
	dw	ARM_instruction_mvfe-instruction_handler
	db	'mvfs',0xe0
	dw	ARM_instruction_mvfs-instruction_handler
	db	'mvni',0xf0
	dw	ARM_instruction_mvni-instruction_handler
	db	'mvns',0xe1
	dw	ARM_instruction_mvn-instruction_handler
	db	'negs',0xe1
	dw	ARM_instruction_neg-instruction_handler
	db	'ngcs',0xf1
	dw	ARM_instruction_ngc-instruction_handler
	db	'nrmd',0xe0
	dw	ARM_instruction_nrmd-instruction_handler
	db	'nrme',0xe0
	dw	ARM_instruction_nrme-instruction_handler
	db	'nrms',0xe0
	dw	ARM_instruction_nrms-instruction_handler
	db	'orns',0xe1
	dw	ARM_instruction_orn-instruction_handler
	db	'orrs',0xe1
	dw	ARM_instruction_orr-instruction_handler
	db	'pldw',0xe0
	dw	ARM_instruction_pldw-instruction_handler
	db	'pmul',0xf0
	dw	ARM_instruction_pmul-instruction_handler
	db	'pold',0xe0
	dw	ARM_instruction_pold-instruction_handler
	db	'pole',0xe0
	dw	ARM_instruction_pole-instruction_handler
	db	'pols',0xe0
	dw	ARM_instruction_pols-instruction_handler
	db	'powd',0xe0
	dw	ARM_instruction_powd-instruction_handler
	db	'powe',0xe0
	dw	ARM_instruction_powe-instruction_handler
	db	'pows',0xe0
	dw	ARM_instruction_pows-instruction_handler
	db	'prfm',0xf0
	dw	ARM_instruction_prfm-instruction_handler
	db	'push',0xe0
	dw	ARM_instruction_push-instruction_handler
	db	'qadd',0xe0
	dw	ARM_instruction_qadd-instruction_handler
	db	'qasx',0xe0
	dw	ARM_instruction_qasx-instruction_handler
	db	'qsax',0xe0
	dw	ARM_instruction_qsax-instruction_handler
	db	'qsub',0xe0
	dw	ARM_instruction_qsub-instruction_handler
	db	'rbit',0xe0
	dw	ARM_instruction_rbit-instruction_handler
	db	'rdfd',0xe0
	dw	ARM_instruction_rdfd-instruction_handler
	db	'rdfe',0xe0
	dw	ARM_instruction_rdfe-instruction_handler
	db	'rdfs',0xe0
	dw	ARM_instruction_rdfs-instruction_handler
	db	'rmfd',0xe0
	dw	ARM_instruction_rmfd-instruction_handler
	db	'rmfe',0xe0
	dw	ARM_instruction_rmfe-instruction_handler
	db	'rmfs',0xe0
	dw	ARM_instruction_rmfs-instruction_handler
	db	'rndd',0xe0
	dw	ARM_instruction_rndd-instruction_handler
	db	'rnde',0xe0
	dw	ARM_instruction_rnde-instruction_handler
	db	'rnds',0xe0
	dw	ARM_instruction_rnds-instruction_handler
	db	'rors',0xe1
	dw	ARM_instruction_ror-instruction_handler
	db	'rorv',0xf0
	dw	ARM_instruction_rorv-instruction_handler
	db	'rpwd',0xe0
	dw	ARM_instruction_rpwd-instruction_handler
	db	'rpwe',0xe0
	dw	ARM_instruction_rpwe-instruction_handler
	db	'rpws',0xe0
	dw	ARM_instruction_rpws-instruction_handler
	db	'rrxs',0xe1
	dw	ARM_instruction_rrx-instruction_handler
	db	'rsbs',0xe1
	dw	ARM_instruction_rsb-instruction_handler
	db	'rscs',0xe1
	dw	ARM_instruction_rsc-instruction_handler
	db	'rsfd',0xe0
	dw	ARM_instruction_rsfd-instruction_handler
	db	'rsfe',0xe0
	dw	ARM_instruction_rsfe-instruction_handler
	db	'rsfs',0xe0
	dw	ARM_instruction_rsfs-instruction_handler
	db	'saba',0xf0
	dw	ARM_instruction_saba-instruction_handler
	db	'sabd',0xf0
	dw	ARM_instruction_sabd-instruction_handler
	db	'sasx',0xe0
	dw	ARM_instruction_sasx-instruction_handler
	db	'sbcs',0xe1
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbfm',0xf0
	dw	ARM_instruction_sbfm-instruction_handler
	db	'sbfx',0xe0
	dw	ARM_instruction_sbfx-instruction_handler
	db	'sdiv',0xe0
	dw	ARM_instruction_sdiv-instruction_handler
	db	'sevl',0xe0
	dw	ARM_instruction_sevl-instruction_handler
	db	'shll',0xf0
	dw	ARM_instruction_shll-instruction_handler
	db	'shrn',0xf0
	dw	ARM_instruction_shrn-instruction_handler
	db	'sind',0xe0
	dw	ARM_instruction_sind-instruction_handler
	db	'sine',0xe0
	dw	ARM_instruction_sine-instruction_handler
	db	'sins',0xe0
	dw	ARM_instruction_sins-instruction_handler
	db	'smax',0xf0
	dw	ARM_instruction_smax-instruction_handler
	db	'smin',0xf0
	dw	ARM_instruction_smin-instruction_handler
	db	'smov',0xf0
	dw	ARM_instruction_smov-instruction_handler
	db	'sqtd',0xe0
	dw	ARM_instruction_sqtd-instruction_handler
	db	'sqte',0xe0
	dw	ARM_instruction_sqte-instruction_handler
	db	'sqts',0xe0
	dw	ARM_instruction_sqts-instruction_handler
	db	'ssat',0xe0
	dw	ARM_instruction_ssat-instruction_handler
	db	'ssax',0xe0
	dw	ARM_instruction_ssax-instruction_handler
	db	'sshl',0xf0
	dw	ARM_instruction_sshl-instruction_handler
	db	'sshr',0xf0
	dw	ARM_instruction_sshr-instruction_handler
	db	'ssra',0xf0
	dw	ARM_instruction_ssra-instruction_handler
	db	'stc2',0xe0
	dw	ARM_instruction_stc2-instruction_handler
	db	'stcl',0xe0
	dw	ARM_instruction_stcl-instruction_handler
	db	'stfd',0xe0
	dw	ARM_instruction_stfd-instruction_handler
	db	'stfe',0xe0
	dw	ARM_instruction_stfe-instruction_handler
	db	'stfp',0xe0
	dw	ARM_instruction_stfp-instruction_handler
	db	'stfs',0xe0
	dw	ARM_instruction_stfs-instruction_handler
	db	'stlb',0xe0
	dw	ARM_instruction_stlb-instruction_handler
	db	'stlh',0xe0
	dw	ARM_instruction_stlh-instruction_handler
	db	'stlr',0xf0
	dw	ARM_instruction_stlr-instruction_handler
	db	'stnp',0xf0
	dw	ARM_instruction_stnp-instruction_handler
	db	'strb',0xe0
	dw	ARM_instruction_strb-instruction_handler
	db	'strd',0xe0
	dw	ARM_instruction_strd-instruction_handler
	db	'strh',0xe0
	dw	ARM_instruction_strh-instruction_handler
	db	'strt',0xe0
	dw	ARM_instruction_strt-instruction_handler
	db	'sttr',0xf0
	dw	ARM_instruction_sttr-instruction_handler
	db	'stur',0xf0
	dw	ARM_instruction_stur-instruction_handler
	db	'stxp',0xf0
	dw	ARM_instruction_stxp-instruction_handler
	db	'stxr',0xf0
	dw	ARM_instruction_stxr-instruction_handler
	db	'subs',0xe1
	dw	ARM_instruction_sub-instruction_handler
	db	'subw',0xe0
	dw	ARM_instruction_subw-instruction_handler
	db	'sufd',0xe0
	dw	ARM_instruction_sufd-instruction_handler
	db	'sufe',0xe0
	dw	ARM_instruction_sufe-instruction_handler
	db	'sufs',0xe0
	dw	ARM_instruction_sufs-instruction_handler
	db	'swpb',0xe0
	dw	ARM_instruction_swpb-instruction_handler
	db	'sxtb',0xe0
	dw	ARM_instruction_sxtb-instruction_handler
	db	'sxth',0xe0
	dw	ARM_instruction_sxth-instruction_handler
	db	'sxtl',0xf0
	dw	ARM_instruction_sxtl-instruction_handler
	db	'sxtw',0xf0
	dw	ARM_instruction_sxtw-instruction_handler
	db	'sysl',0xf0
	dw	ARM_instruction_sysl-instruction_handler
	db	'tand',0xe0
	dw	ARM_instruction_tand-instruction_handler
	db	'tane',0xe0
	dw	ARM_instruction_tane-instruction_handler
	db	'tans',0xe0
	dw	ARM_instruction_tans-instruction_handler
	db	'tbnz',0xf0
	dw	ARM_instruction_tbnz-instruction_handler
	db	'teqp',0xe0
	dw	ARM_instruction_teqp-instruction_handler
	db	'tlbi',0xf0
	dw	ARM_instruction_tlbi-instruction_handler
	db	'tmcr',0xe0
	dw	ARM_instruction_tmcr-instruction_handler
	db	'tmia',0xe0
	dw	ARM_instruction_tmia-instruction_handler
	db	'tmrc',0xe0
	dw	ARM_instruction_tmrc-instruction_handler
	db	'trn1',0xf0
	dw	ARM_instruction_trn1-instruction_handler
	db	'trn2',0xf0
	dw	ARM_instruction_trn2-instruction_handler
	db	'tstp',0xe0
	dw	ARM_instruction_tstp-instruction_handler
	db	'uaba',0xf0
	dw	ARM_instruction_uaba-instruction_handler
	db	'uabd',0xf0
	dw	ARM_instruction_uabd-instruction_handler
	db	'uasx',0xe0
	dw	ARM_instruction_uasx-instruction_handler
	db	'ubfm',0xf0
	dw	ARM_instruction_ubfm-instruction_handler
	db	'ubfx',0xe0
	dw	ARM_instruction_ubfx-instruction_handler
	db	'udiv',0xe0
	dw	ARM_instruction_udiv-instruction_handler
	db	'umax',0xf0
	dw	ARM_instruction_umax-instruction_handler
	db	'umin',0xf0
	dw	ARM_instruction_umin-instruction_handler
	db	'umov',0xf0
	dw	ARM_instruction_umov-instruction_handler
	db	'urdd',0xe0
	dw	ARM_instruction_urdd-instruction_handler
	db	'urde',0xe0
	dw	ARM_instruction_urde-instruction_handler
	db	'urds',0xe0
	dw	ARM_instruction_urds-instruction_handler
	db	'usat',0xe0
	dw	ARM_instruction_usat-instruction_handler
	db	'usax',0xe0
	dw	ARM_instruction_usax-instruction_handler
	db	'ushl',0xf0
	dw	ARM_instruction_ushl-instruction_handler
	db	'ushr',0xf0
	dw	ARM_instruction_ushr-instruction_handler
	db	'usra',0xf0
	dw	ARM_instruction_usra-instruction_handler
	db	'uxtb',0xe0
	dw	ARM_instruction_uxtb-instruction_handler
	db	'uxth',0xe0
	dw	ARM_instruction_uxth-instruction_handler
	db	'uxtl',0xf0
	dw	ARM_instruction_uxtl-instruction_handler
	db	'uzp1',0xf0
	dw	ARM_instruction_uzp1-instruction_handler
	db	'uzp2',0xf0
	dw	ARM_instruction_uzp2-instruction_handler
	db	'vand',0xe0
	dw	ARM_instruction_vand-instruction_handler
	db	'vbic',0xe0
	dw	ARM_instruction_vbic-instruction_handler
	db	'vbif',0xe0
	dw	ARM_instruction_vbif-instruction_handler
	db	'vbit',0xe0
	dw	ARM_instruction_vbit-instruction_handler
	db	'vbsl',0xe0
	dw	ARM_instruction_vbsl-instruction_handler
	db	'veor',0xe0
	dw	ARM_instruction_veor-instruction_handler
	db	'vldm',0xe0
	dw	ARM_instruction_vldm-instruction_handler
	db	'vldr',0xe0
	dw	ARM_instruction_vldr-instruction_handler
	db	'vmov',0xe0
	dw	ARM_instruction_vmov-instruction_handler
	db	'vmrs',0xe0
	dw	ARM_instruction_vmrs-instruction_handler
	db	'vmsr',0xe0
	dw	ARM_instruction_vmsr-instruction_handler
	db	'vmvn',0xe0
	dw	ARM_instruction_vmvn-instruction_handler
	db	'vorn',0xe0
	dw	ARM_instruction_vorn-instruction_handler
	db	'vorr',0xe0
	dw	ARM_instruction_vorr-instruction_handler
	db	'vpop',0xe0
	dw	ARM_instruction_vpop-instruction_handler
	db	'vstm',0xe0
	dw	ARM_instruction_vstm-instruction_handler
	db	'vstr',0xe0
	dw	ARM_instruction_vstr-instruction_handler
	db	'vswp',0xe0
	dw	ARM_instruction_vswp-instruction_handler
	db	'wand',0xe0
	dw	ARM_instruction_wand-instruction_handler
	db	'wmov',0xe0
	dw	ARM_instruction_wmov-instruction_handler
	db	'wxor',0xe0
	dw	ARM_instruction_wxor-instruction_handler
	db	'xtn2',0xf0
	dw	ARM_instruction_xtn2-instruction_handler
	db	'zip1',0xf0
	dw	ARM_instruction_zip1-instruction_handler
	db	'zip2',0xf0
	dw	ARM_instruction_zip2-instruction_handler
	db	0
instructions_5:
	db	'absdm',0xe0
	dw	ARM_instruction_absdm-instruction_handler
	db	'absdp',0xe0
	dw	ARM_instruction_absdp-instruction_handler
	db	'absdz',0xe0
	dw	ARM_instruction_absdz-instruction_handler
	db	'absem',0xe0
	dw	ARM_instruction_absem-instruction_handler
	db	'absep',0xe0
	dw	ARM_instruction_absep-instruction_handler
	db	'absez',0xe0
	dw	ARM_instruction_absez-instruction_handler
	db	'abssm',0xe0
	dw	ARM_instruction_abssm-instruction_handler
	db	'abssp',0xe0
	dw	ARM_instruction_abssp-instruction_handler
	db	'abssz',0xe0
	dw	ARM_instruction_abssz-instruction_handler
	db	'acsdm',0xe0
	dw	ARM_instruction_acsdm-instruction_handler
	db	'acsdp',0xe0
	dw	ARM_instruction_acsdp-instruction_handler
	db	'acsdz',0xe0
	dw	ARM_instruction_acsdz-instruction_handler
	db	'acsem',0xe0
	dw	ARM_instruction_acsem-instruction_handler
	db	'acsep',0xe0
	dw	ARM_instruction_acsep-instruction_handler
	db	'acsez',0xe0
	dw	ARM_instruction_acsez-instruction_handler
	db	'acssm',0xe0
	dw	ARM_instruction_acssm-instruction_handler
	db	'acssp',0xe0
	dw	ARM_instruction_acssp-instruction_handler
	db	'acssz',0xe0
	dw	ARM_instruction_acssz-instruction_handler
	db	'adc.n',0xe4
	dw	ARM_instruction_adc-instruction_handler
	db	'adc.w',0xe2
	dw	ARM_instruction_adc-instruction_handler
	db	'adc~~',0x00
	dw	ARM_instruction_adc-instruction_handler
	db	'add.n',0xe4
	dw	ARM_instruction_add-instruction_handler
	db	'add.w',0xe2
	dw	ARM_instruction_add-instruction_handler
	db	'addhn',0xf0
	dw	ARM_instruction_addhn-instruction_handler
	db	'add~~',0x00
	dw	ARM_instruction_add-instruction_handler
	db	'adfdm',0xe0
	dw	ARM_instruction_adfdm-instruction_handler
	db	'adfdp',0xe0
	dw	ARM_instruction_adfdp-instruction_handler
	db	'adfdz',0xe0
	dw	ARM_instruction_adfdz-instruction_handler
	db	'adfem',0xe0
	dw	ARM_instruction_adfem-instruction_handler
	db	'adfep',0xe0
	dw	ARM_instruction_adfep-instruction_handler
	db	'adfez',0xe0
	dw	ARM_instruction_adfez-instruction_handler
	db	'adfsm',0xe0
	dw	ARM_instruction_adfsm-instruction_handler
	db	'adfsp',0xe0
	dw	ARM_instruction_adfsp-instruction_handler
	db	'adfsz',0xe0
	dw	ARM_instruction_adfsz-instruction_handler
	db	'adr.n',0xe4
	dw	ARM_instruction_adr-instruction_handler
	db	'adr.w',0xe2
	dw	ARM_instruction_adr-instruction_handler
	db	'adr~~',0x00
	dw	ARM_instruction_adr-instruction_handler
	db	'aesmc',0xf0
	dw	ARM_instruction_aesmc-instruction_handler
	db	'align',0x00
	dw	align_directive-instruction_handler
	db	'and.n',0xe4
	dw	ARM_instruction_and-instruction_handler
	db	'and.w',0xe2
	dw	ARM_instruction_and-instruction_handler
	db	'and~~',0x00
	dw	ARM_instruction_and-instruction_handler
	db	'asndm',0xe0
	dw	ARM_instruction_asndm-instruction_handler
	db	'asndp',0xe0
	dw	ARM_instruction_asndp-instruction_handler
	db	'asndz',0xe0
	dw	ARM_instruction_asndz-instruction_handler
	db	'asnem',0xe0
	dw	ARM_instruction_asnem-instruction_handler
	db	'asnep',0xe0
	dw	ARM_instruction_asnep-instruction_handler
	db	'asnez',0xe0
	dw	ARM_instruction_asnez-instruction_handler
	db	'asnsm',0xe0
	dw	ARM_instruction_asnsm-instruction_handler
	db	'asnsp',0xe0
	dw	ARM_instruction_asnsp-instruction_handler
	db	'asnsz',0xe0
	dw	ARM_instruction_asnsz-instruction_handler
	db	'asr.n',0xe4
	dw	ARM_instruction_asr-instruction_handler
	db	'asr.w',0xe2
	dw	ARM_instruction_asr-instruction_handler
	db	'asr~~',0x00
	dw	ARM_instruction_asr-instruction_handler
	db	'atndm',0xe0
	dw	ARM_instruction_atndm-instruction_handler
	db	'atndp',0xe0
	dw	ARM_instruction_atndp-instruction_handler
	db	'atndz',0xe0
	dw	ARM_instruction_atndz-instruction_handler
	db	'atnem',0xe0
	dw	ARM_instruction_atnem-instruction_handler
	db	'atnep',0xe0
	dw	ARM_instruction_atnep-instruction_handler
	db	'atnez',0xe0
	dw	ARM_instruction_atnez-instruction_handler
	db	'atnsm',0xe0
	dw	ARM_instruction_atnsm-instruction_handler
	db	'atnsp',0xe0
	dw	ARM_instruction_atnsp-instruction_handler
	db	'atnsz',0xe0
	dw	ARM_instruction_atnsz-instruction_handler
	db	'bfc~~',0x00
	dw	ARM_instruction_bfc-instruction_handler
	db	'bfi~~',0x00
	dw	ARM_instruction_bfi-instruction_handler
	db	'bfxil',0xf0
	dw	ARM_instruction_bfxil-instruction_handler
	db	'bic.n',0xe4
	dw	ARM_instruction_bic-instruction_handler
	db	'bic.w',0xe2
	dw	ARM_instruction_bic-instruction_handler
	db	'bic~~',0x00
	dw	ARM_instruction_bic-instruction_handler
	db	'blx.n',0xe4
	dw	ARM_instruction_blx-instruction_handler
	db	'blx.w',0xe2
	dw	ARM_instruction_blx-instruction_handler
	db	'blx~~',0x00
	dw	ARM_instruction_blx-instruction_handler
	db	'break',0x00
	dw	break_directive-instruction_handler
	db	'bxj~~',0x00
	dw	ARM_instruction_bxj-instruction_handler
	db	'b~~.n',0x04
	dw	ARM_instruction_b-instruction_handler
	db	'b~~.w',0x02
	dw	ARM_instruction_b-instruction_handler
	db	'cbz.n',0xf4
	dw	ARM_instruction_cbz-instruction_handler
	db	'cbz.w',0xf2
	dw	ARM_instruction_cbz-instruction_handler
	db	'cdp~~',0x00
	dw	ARM_instruction_cdp-instruction_handler
	db	'clrex',0xe0
	dw	ARM_instruction_clrex-instruction_handler
	db	'clz~~',0x00
	dw	ARM_instruction_clz-instruction_handler
	db	'cmf~~',0x00
	dw	ARM_instruction_cmf-instruction_handler
	db	'cmn.n',0xe4
	dw	ARM_instruction_cmn-instruction_handler
	db	'cmn.w',0xe2
	dw	ARM_instruction_cmn-instruction_handler
	db	'cmn~~',0x00
	dw	ARM_instruction_cmn-instruction_handler
	db	'cmp.n',0xe4
	dw	ARM_instruction_cmp-instruction_handler
	db	'cmp.w',0xe2
	dw	ARM_instruction_cmp-instruction_handler
	db	'cmp~~',0x00
	dw	ARM_instruction_cmp-instruction_handler
	db	'cmtst',0xf0
	dw	ARM_instruction_cmtst-instruction_handler
	db	'cnf~~',0x00
	dw	ARM_instruction_cnf-instruction_handler
	db	'cosdm',0xe0
	dw	ARM_instruction_cosdm-instruction_handler
	db	'cosdp',0xe0
	dw	ARM_instruction_cosdp-instruction_handler
	db	'cosdz',0xe0
	dw	ARM_instruction_cosdz-instruction_handler
	db	'cosem',0xe0
	dw	ARM_instruction_cosem-instruction_handler
	db	'cosep',0xe0
	dw	ARM_instruction_cosep-instruction_handler
	db	'cosez',0xe0
	dw	ARM_instruction_cosez-instruction_handler
	db	'cossm',0xe0
	dw	ARM_instruction_cossm-instruction_handler
	db	'cossp',0xe0
	dw	ARM_instruction_cossp-instruction_handler
	db	'cossz',0xe0
	dw	ARM_instruction_cossz-instruction_handler
	db	'cps.n',0xf4
	dw	ARM_instruction_cps-instruction_handler
	db	'cps.w',0xf2
	dw	ARM_instruction_cps-instruction_handler
	db	'cpsid',0xf0
	dw	ARM_instruction_cpsid-instruction_handler
	db	'cpsie',0xf0
	dw	ARM_instruction_cpsie-instruction_handler
	db	'cpy.n',0xe4
	dw	ARM_instruction_cpy-instruction_handler
	db	'cpy.w',0xe2
	dw	ARM_instruction_cpy-instruction_handler
	db	'cpy~~',0x00
	dw	ARM_instruction_cpy-instruction_handler
	db	'crc32',0xf0
	dw	ARM_instruction_crc32-instruction_handler
	db	'csetm',0xf0
	dw	ARM_instruction_csetm-instruction_handler
	db	'csinc',0xf0
	dw	ARM_instruction_csinc-instruction_handler
	db	'csinv',0xf0
	dw	ARM_instruction_csinv-instruction_handler
	db	'csneg',0xf0
	dw	ARM_instruction_csneg-instruction_handler
	db	'dbg~~',0x00
	dw	ARM_instruction_dbg-instruction_handler
	db	'dcps1',0xe0
	dw	ARM_instruction_dcps1-instruction_handler
	db	'dcps2',0xe0
	dw	ARM_instruction_dcps2-instruction_handler
	db	'dcps3',0xe0
	dw	ARM_instruction_dcps3-instruction_handler
	db	'dvfdm',0xe0
	dw	ARM_instruction_dvfdm-instruction_handler
	db	'dvfdp',0xe0
	dw	ARM_instruction_dvfdp-instruction_handler
	db	'dvfdz',0xe0
	dw	ARM_instruction_dvfdz-instruction_handler
	db	'dvfem',0xe0
	dw	ARM_instruction_dvfem-instruction_handler
	db	'dvfep',0xe0
	dw	ARM_instruction_dvfep-instruction_handler
	db	'dvfez',0xe0
	dw	ARM_instruction_dvfez-instruction_handler
	db	'dvfsm',0xe0
	dw	ARM_instruction_dvfsm-instruction_handler
	db	'dvfsp',0xe0
	dw	ARM_instruction_dvfsp-instruction_handler
	db	'dvfsz',0xe0
	dw	ARM_instruction_dvfsz-instruction_handler
	db	'entry',0x00
	dw	entry_directive-instruction_handler
	db	'eor.n',0xe4
	dw	ARM_instruction_eor-instruction_handler
	db	'eor.w',0xe2
	dw	ARM_instruction_eor-instruction_handler
	db	'eor~~',0x00
	dw	ARM_instruction_eor-instruction_handler
	db	'expdm',0xe0
	dw	ARM_instruction_expdm-instruction_handler
	db	'expdp',0xe0
	dw	ARM_instruction_expdp-instruction_handler
	db	'expdz',0xe0
	dw	ARM_instruction_expdz-instruction_handler
	db	'expem',0xe0
	dw	ARM_instruction_expem-instruction_handler
	db	'expep',0xe0
	dw	ARM_instruction_expep-instruction_handler
	db	'expez',0xe0
	dw	ARM_instruction_expez-instruction_handler
	db	'expsm',0xe0
	dw	ARM_instruction_expsm-instruction_handler
	db	'expsp',0xe0
	dw	ARM_instruction_expsp-instruction_handler
	db	'expsz',0xe0
	dw	ARM_instruction_expsz-instruction_handler
	db	'extrn',0x00
	dw	extrn_directive-instruction_handler
	db	'fabsd',0xe0
	dw	ARM_instruction_fabsd-instruction_handler
	db	'fabss',0xe0
	dw	ARM_instruction_fabss-instruction_handler
	db	'facge',0xf0
	dw	ARM_instruction_facge-instruction_handler
	db	'facgt',0xf0
	dw	ARM_instruction_facgt-instruction_handler
	db	'faddd',0xe0
	dw	ARM_instruction_faddd-instruction_handler
	db	'faddp',0xf0
	dw	ARM_instruction_faddp-instruction_handler
	db	'fadds',0xe0
	dw	ARM_instruction_fadds-instruction_handler
	db	'fccmp',0xf0
	dw	ARM_instruction_fccmp-instruction_handler
	db	'fcmeq',0xf0
	dw	ARM_instruction_fcmeq-instruction_handler
	db	'fcmge',0xf0
	dw	ARM_instruction_fcmge-instruction_handler
	db	'fcmgt',0xf0
	dw	ARM_instruction_fcmgt-instruction_handler
	db	'fcmle',0xf0
	dw	ARM_instruction_fcmle-instruction_handler
	db	'fcmlt',0xf0
	dw	ARM_instruction_fcmlt-instruction_handler
	db	'fcmpd',0xe0
	dw	ARM_instruction_fcmpd-instruction_handler
	db	'fcmpe',0xf0
	dw	ARM_instruction_fcmpe-instruction_handler
	db	'fcmps',0xe0
	dw	ARM_instruction_fcmps-instruction_handler
	db	'fcpyd',0xe0
	dw	ARM_instruction_fcpyd-instruction_handler
	db	'fcpys',0xe0
	dw	ARM_instruction_fcpys-instruction_handler
	db	'fcsel',0xf0
	dw	ARM_instruction_fcsel-instruction_handler
	db	'fcvtl',0xf0
	dw	ARM_instruction_fcvtl-instruction_handler
	db	'fcvtn',0xf0
	dw	ARM_instruction_fcvtn-instruction_handler
	db	'fdivd',0xe0
	dw	ARM_instruction_fdivd-instruction_handler
	db	'fdivs',0xe0
	dw	ARM_instruction_fdivs-instruction_handler
	db	'fdvdm',0xe0
	dw	ARM_instruction_fdvdm-instruction_handler
	db	'fdvdp',0xe0
	dw	ARM_instruction_fdvdp-instruction_handler
	db	'fdvdz',0xe0
	dw	ARM_instruction_fdvdz-instruction_handler
	db	'fdvem',0xe0
	dw	ARM_instruction_fdvem-instruction_handler
	db	'fdvep',0xe0
	dw	ARM_instruction_fdvep-instruction_handler
	db	'fdvez',0xe0
	dw	ARM_instruction_fdvez-instruction_handler
	db	'fdvsm',0xe0
	dw	ARM_instruction_fdvsm-instruction_handler
	db	'fdvsp',0xe0
	dw	ARM_instruction_fdvsp-instruction_handler
	db	'fdvsz',0xe0
	dw	ARM_instruction_fdvsz-instruction_handler
	db	'fix~~',0x00
	dw	ARM_instruction_fix-instruction_handler
	db	'fldmd',0xe0
	dw	ARM_instruction_fldmd-instruction_handler
	db	'fldms',0xe0
	dw	ARM_instruction_fldms-instruction_handler
	db	'fldmx',0xe0
	dw	ARM_instruction_fldmx-instruction_handler
	db	'fltdm',0xe0
	dw	ARM_instruction_fltdm-instruction_handler
	db	'fltdp',0xe0
	dw	ARM_instruction_fltdp-instruction_handler
	db	'fltdz',0xe0
	dw	ARM_instruction_fltdz-instruction_handler
	db	'fltem',0xe0
	dw	ARM_instruction_fltem-instruction_handler
	db	'fltep',0xe0
	dw	ARM_instruction_fltep-instruction_handler
	db	'fltez',0xe0
	dw	ARM_instruction_fltez-instruction_handler
	db	'fltsm',0xe0
	dw	ARM_instruction_fltsm-instruction_handler
	db	'fltsp',0xe0
	dw	ARM_instruction_fltsp-instruction_handler
	db	'fltsz',0xe0
	dw	ARM_instruction_fltsz-instruction_handler
	db	'fmacd',0xe0
	dw	ARM_instruction_fmacd-instruction_handler
	db	'fmacs',0xe0
	dw	ARM_instruction_fmacs-instruction_handler
	db	'fmadd',0xf0
	dw	ARM_instruction_fmadd-instruction_handler
	db	'fmaxp',0xf0
	dw	ARM_instruction_fmaxp-instruction_handler
	db	'fmaxv',0xf0
	dw	ARM_instruction_fmaxv-instruction_handler
	db	'fmdhr',0xe0
	dw	ARM_instruction_fmdhr-instruction_handler
	db	'fmdlr',0xe0
	dw	ARM_instruction_fmdlr-instruction_handler
	db	'fmdrr',0xe0
	dw	ARM_instruction_fmdrr-instruction_handler
	db	'fminp',0xf0
	dw	ARM_instruction_fminp-instruction_handler
	db	'fminv',0xf0
	dw	ARM_instruction_fminv-instruction_handler
	db	'fmldm',0xe0
	dw	ARM_instruction_fmldm-instruction_handler
	db	'fmldp',0xe0
	dw	ARM_instruction_fmldp-instruction_handler
	db	'fmldz',0xe0
	dw	ARM_instruction_fmldz-instruction_handler
	db	'fmlem',0xe0
	dw	ARM_instruction_fmlem-instruction_handler
	db	'fmlep',0xe0
	dw	ARM_instruction_fmlep-instruction_handler
	db	'fmlez',0xe0
	dw	ARM_instruction_fmlez-instruction_handler
	db	'fmlsm',0xe0
	dw	ARM_instruction_fmlsm-instruction_handler
	db	'fmlsp',0xe0
	dw	ARM_instruction_fmlsp-instruction_handler
	db	'fmlsz',0xe0
	dw	ARM_instruction_fmlsz-instruction_handler
	db	'fmrdh',0xe0
	dw	ARM_instruction_fmrdh-instruction_handler
	db	'fmrdl',0xe0
	dw	ARM_instruction_fmrdl-instruction_handler
	db	'fmrrd',0xe0
	dw	ARM_instruction_fmrrd-instruction_handler
	db	'fmrrs',0xe0
	dw	ARM_instruction_fmrrs-instruction_handler
	db	'fmscd',0xe0
	dw	ARM_instruction_fmscd-instruction_handler
	db	'fmscs',0xe0
	dw	ARM_instruction_fmscs-instruction_handler
	db	'fmsrr',0xe0
	dw	ARM_instruction_fmsrr-instruction_handler
	db	'fmsub',0xf0
	dw	ARM_instruction_fmsub-instruction_handler
	db	'fmuld',0xe0
	dw	ARM_instruction_fmuld-instruction_handler
	db	'fmuls',0xe0
	dw	ARM_instruction_fmuls-instruction_handler
	db	'fmulx',0xf0
	dw	ARM_instruction_fmulx-instruction_handler
	db	'fnegd',0xe0
	dw	ARM_instruction_fnegd-instruction_handler
	db	'fnegs',0xe0
	dw	ARM_instruction_fnegs-instruction_handler
	db	'fnmul',0xf0
	dw	ARM_instruction_fnmul-instruction_handler
	db	'frddm',0xe0
	dw	ARM_instruction_frddm-instruction_handler
	db	'frddp',0xe0
	dw	ARM_instruction_frddp-instruction_handler
	db	'frddz',0xe0
	dw	ARM_instruction_frddz-instruction_handler
	db	'frdem',0xe0
	dw	ARM_instruction_frdem-instruction_handler
	db	'frdep',0xe0
	dw	ARM_instruction_frdep-instruction_handler
	db	'frdez',0xe0
	dw	ARM_instruction_frdez-instruction_handler
	db	'frdsm',0xe0
	dw	ARM_instruction_frdsm-instruction_handler
	db	'frdsp',0xe0
	dw	ARM_instruction_frdsp-instruction_handler
	db	'frdsz',0xe0
	dw	ARM_instruction_frdsz-instruction_handler
	db	'fsqrt',0xf0
	dw	ARM_instruction_fsqrt-instruction_handler
	db	'fstmd',0xe0
	dw	ARM_instruction_fstmd-instruction_handler
	db	'fstms',0xe0
	dw	ARM_instruction_fstms-instruction_handler
	db	'fstmx',0xe0
	dw	ARM_instruction_fstmx-instruction_handler
	db	'fsubd',0xe0
	dw	ARM_instruction_fsubd-instruction_handler
	db	'fsubs',0xe0
	dw	ARM_instruction_fsubs-instruction_handler
	db	'hbl~~',0x00
	dw	ARM_instruction_hbl-instruction_handler
	db	'hbp~~',0x00
	dw	ARM_instruction_hbp-instruction_handler
	db	'iteee',0xf0
	dw	ARM_instruction_iteee-instruction_handler
	db	'iteet',0xf0
	dw	ARM_instruction_iteet-instruction_handler
	db	'itete',0xf0
	dw	ARM_instruction_itete-instruction_handler
	db	'itett',0xf0
	dw	ARM_instruction_itett-instruction_handler
	db	'ittee',0xf0
	dw	ARM_instruction_ittee-instruction_handler
	db	'ittet',0xf0
	dw	ARM_instruction_ittet-instruction_handler
	db	'ittte',0xf0
	dw	ARM_instruction_ittte-instruction_handler
	db	'itttt',0xf0
	dw	ARM_instruction_itttt-instruction_handler
	db	'label',0x00
	dw	label_directive-instruction_handler
	db	'ldaex',0xe0
	dw	ARM_instruction_ldaex-instruction_handler
	db	'ldarb',0xf0
	dw	ARM_instruction_ldarb-instruction_handler
	db	'ldarh',0xf0
	dw	ARM_instruction_ldarh-instruction_handler
	db	'ldaxp',0xf0
	dw	ARM_instruction_ldaxp-instruction_handler
	db	'ldaxr',0xf0
	dw	ARM_instruction_ldaxr-instruction_handler
	db	'lda~~',0x00
	dw	ARM_instruction_lda-instruction_handler
	db	'ldc2l',0xe0
	dw	ARM_instruction_ldc2l-instruction_handler
	db	'ldc~~',0x00
	dw	ARM_instruction_ldc-instruction_handler
	db	'ldm.n',0xe4
	dw	ARM_instruction_ldm-instruction_handler
	db	'ldm.w',0xe2
	dw	ARM_instruction_ldm-instruction_handler
	db	'ldmda',0xe0
	dw	ARM_instruction_ldmda-instruction_handler
	db	'ldmdb',0xe0
	dw	ARM_instruction_ldmdb-instruction_handler
	db	'ldmea',0xe0
	dw	ARM_instruction_ldmea-instruction_handler
	db	'ldmed',0xe0
	dw	ARM_instruction_ldmed-instruction_handler
	db	'ldmfa',0xe0
	dw	ARM_instruction_ldmfa-instruction_handler
	db	'ldmfd',0xe0
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldmia',0xe0
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldmib',0xe0
	dw	ARM_instruction_ldmib-instruction_handler
	db	'ldm~~',0x00
	dw	ARM_instruction_ldm-instruction_handler
	db	'ldpsw',0xf0
	dw	ARM_instruction_ldpsw-instruction_handler
	db	'ldr.n',0xe4
	dw	ARM_instruction_ldr-instruction_handler
	db	'ldr.w',0xe2
	dw	ARM_instruction_ldr-instruction_handler
	db	'ldrbt',0xe0
	dw	ARM_instruction_ldrbt-instruction_handler
	db	'ldrex',0xe0
	dw	ARM_instruction_ldrex-instruction_handler
	db	'ldrht',0xe0
	dw	ARM_instruction_ldrht-instruction_handler
	db	'ldrsb',0xe0
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldrsh',0xe0
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldrsw',0xf0
	dw	ARM_instruction_ldrsw-instruction_handler
	db	'ldr~~',0x00
	dw	ARM_instruction_ldr-instruction_handler
	db	'ldtrb',0xf0
	dw	ARM_instruction_ldtrb-instruction_handler
	db	'ldtrh',0xf0
	dw	ARM_instruction_ldtrh-instruction_handler
	db	'ldurb',0xf0
	dw	ARM_instruction_ldurb-instruction_handler
	db	'ldurh',0xf0
	dw	ARM_instruction_ldurh-instruction_handler
	db	'ldxrb',0xf0
	dw	ARM_instruction_ldxrb-instruction_handler
	db	'ldxrh',0xf0
	dw	ARM_instruction_ldxrh-instruction_handler
	db	'lfmea',0xe0
	dw	ARM_instruction_lfmea-instruction_handler
	db	'lfmfd',0xe0
	dw	ARM_instruction_lfmfd-instruction_handler
	db	'lfm~~',0x00
	dw	ARM_instruction_lfm-instruction_handler
	db	'lgndm',0xe0
	dw	ARM_instruction_lgndm-instruction_handler
	db	'lgndp',0xe0
	dw	ARM_instruction_lgndp-instruction_handler
	db	'lgndz',0xe0
	dw	ARM_instruction_lgndz-instruction_handler
	db	'lgnem',0xe0
	dw	ARM_instruction_lgnem-instruction_handler
	db	'lgnep',0xe0
	dw	ARM_instruction_lgnep-instruction_handler
	db	'lgnez',0xe0
	dw	ARM_instruction_lgnez-instruction_handler
	db	'lgnsm',0xe0
	dw	ARM_instruction_lgnsm-instruction_handler
	db	'lgnsp',0xe0
	dw	ARM_instruction_lgnsp-instruction_handler
	db	'lgnsz',0xe0
	dw	ARM_instruction_lgnsz-instruction_handler
	db	'logdm',0xe0
	dw	ARM_instruction_logdm-instruction_handler
	db	'logdp',0xe0
	dw	ARM_instruction_logdp-instruction_handler
	db	'logdz',0xe0
	dw	ARM_instruction_logdz-instruction_handler
	db	'logem',0xe0
	dw	ARM_instruction_logem-instruction_handler
	db	'logep',0xe0
	dw	ARM_instruction_logep-instruction_handler
	db	'logez',0xe0
	dw	ARM_instruction_logez-instruction_handler
	db	'logsm',0xe0
	dw	ARM_instruction_logsm-instruction_handler
	db	'logsp',0xe0
	dw	ARM_instruction_logsp-instruction_handler
	db	'logsz',0xe0
	dw	ARM_instruction_logsz-instruction_handler
	db	'lsl.n',0xe4
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsl.w',0xe2
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsl~~',0x00
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsr.n',0xe4
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsr.w',0xe2
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsr~~',0x00
	dw	ARM_instruction_lsr-instruction_handler
	db	'mar~~',0x00
	dw	ARM_instruction_mar-instruction_handler
	db	'mcrr2',0xe0
	dw	ARM_instruction_mcrr2-instruction_handler
	db	'mcr~~',0x00
	dw	ARM_instruction_mcr-instruction_handler
	db	'miabb',0xe0
	dw	ARM_instruction_miabb-instruction_handler
	db	'miabt',0xe0
	dw	ARM_instruction_miabt-instruction_handler
	db	'miaph',0xe0
	dw	ARM_instruction_miaph-instruction_handler
	db	'miatb',0xe0
	dw	ARM_instruction_miatb-instruction_handler
	db	'miatt',0xe0
	dw	ARM_instruction_miatt-instruction_handler
	db	'mia~~',0x00
	dw	ARM_instruction_mia-instruction_handler
	db	'mla~~',0x00
	dw	ARM_instruction_mla-instruction_handler
	db	'mls~~',0x00
	dw	ARM_instruction_mls-instruction_handler
	db	'mnfdm',0xe0
	dw	ARM_instruction_mnfdm-instruction_handler
	db	'mnfdp',0xe0
	dw	ARM_instruction_mnfdp-instruction_handler
	db	'mnfdz',0xe0
	dw	ARM_instruction_mnfdz-instruction_handler
	db	'mnfem',0xe0
	dw	ARM_instruction_mnfem-instruction_handler
	db	'mnfep',0xe0
	dw	ARM_instruction_mnfep-instruction_handler
	db	'mnfez',0xe0
	dw	ARM_instruction_mnfez-instruction_handler
	db	'mnfsm',0xe0
	dw	ARM_instruction_mnfsm-instruction_handler
	db	'mnfsp',0xe0
	dw	ARM_instruction_mnfsp-instruction_handler
	db	'mnfsz',0xe0
	dw	ARM_instruction_mnfsz-instruction_handler
	db	'mov.n',0xe4
	dw	ARM_instruction_mov-instruction_handler
	db	'mov.w',0xe2
	dw	ARM_instruction_mov-instruction_handler
	db	'mov~~',0x00
	dw	ARM_instruction_mov-instruction_handler
	db	'mra~~',0x00
	dw	ARM_instruction_mra-instruction_handler
	db	'mrc~~',0x00
	dw	ARM_instruction_mrc-instruction_handler
	db	'mrrc2',0xe0
	dw	ARM_instruction_mrrc2-instruction_handler
	db	'mrs~~',0x00
	dw	ARM_instruction_mrs-instruction_handler
	db	'msr~~',0x00
	dw	ARM_instruction_msr-instruction_handler
	db	'mufdm',0xe0
	dw	ARM_instruction_mufdm-instruction_handler
	db	'mufdp',0xe0
	dw	ARM_instruction_mufdp-instruction_handler
	db	'mufdz',0xe0
	dw	ARM_instruction_mufdz-instruction_handler
	db	'mufem',0xe0
	dw	ARM_instruction_mufem-instruction_handler
	db	'mufep',0xe0
	dw	ARM_instruction_mufep-instruction_handler
	db	'mufez',0xe0
	dw	ARM_instruction_mufez-instruction_handler
	db	'mufsm',0xe0
	dw	ARM_instruction_mufsm-instruction_handler
	db	'mufsp',0xe0
	dw	ARM_instruction_mufsp-instruction_handler
	db	'mufsz',0xe0
	dw	ARM_instruction_mufsz-instruction_handler
	db	'mul.n',0xe4
	dw	ARM_instruction_mul-instruction_handler
	db	'mul.w',0xe2
	dw	ARM_instruction_mul-instruction_handler
	db	'mul~~',0x00
	dw	ARM_instruction_mul-instruction_handler
	db	'mvfdm',0xe0
	dw	ARM_instruction_mvfdm-instruction_handler
	db	'mvfdp',0xe0
	dw	ARM_instruction_mvfdp-instruction_handler
	db	'mvfdz',0xe0
	dw	ARM_instruction_mvfdz-instruction_handler
	db	'mvfem',0xe0
	dw	ARM_instruction_mvfem-instruction_handler
	db	'mvfep',0xe0
	dw	ARM_instruction_mvfep-instruction_handler
	db	'mvfez',0xe0
	dw	ARM_instruction_mvfez-instruction_handler
	db	'mvfsm',0xe0
	dw	ARM_instruction_mvfsm-instruction_handler
	db	'mvfsp',0xe0
	dw	ARM_instruction_mvfsp-instruction_handler
	db	'mvfsz',0xe0
	dw	ARM_instruction_mvfsz-instruction_handler
	db	'mvn.n',0xe4
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvn.w',0xe2
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvn~~',0x00
	dw	ARM_instruction_mvn-instruction_handler
	db	'neg.n',0xe4
	dw	ARM_instruction_neg-instruction_handler
	db	'neg.w',0xe2
	dw	ARM_instruction_neg-instruction_handler
	db	'neg~~',0x00
	dw	ARM_instruction_neg-instruction_handler
	db	'nop.n',0xe4
	dw	ARM_instruction_nop-instruction_handler
	db	'nop.w',0xe2
	dw	ARM_instruction_nop-instruction_handler
	db	'nop~~',0x00
	dw	ARM_instruction_nop-instruction_handler
	db	'nrmdm',0xe0
	dw	ARM_instruction_nrmdm-instruction_handler
	db	'nrmdp',0xe0
	dw	ARM_instruction_nrmdp-instruction_handler
	db	'nrmdz',0xe0
	dw	ARM_instruction_nrmdz-instruction_handler
	db	'nrmem',0xe0
	dw	ARM_instruction_nrmem-instruction_handler
	db	'nrmep',0xe0
	dw	ARM_instruction_nrmep-instruction_handler
	db	'nrmez',0xe0
	dw	ARM_instruction_nrmez-instruction_handler
	db	'nrmsm',0xe0
	dw	ARM_instruction_nrmsm-instruction_handler
	db	'nrmsp',0xe0
	dw	ARM_instruction_nrmsp-instruction_handler
	db	'nrmsz',0xe0
	dw	ARM_instruction_nrmsz-instruction_handler
	db	'orn~~',0x00
	dw	ARM_instruction_orn-instruction_handler
	db	'orr.n',0xe4
	dw	ARM_instruction_orr-instruction_handler
	db	'orr.w',0xe2
	dw	ARM_instruction_orr-instruction_handler
	db	'orr~~',0x00
	dw	ARM_instruction_orr-instruction_handler
	db	'pkhbt',0xe0
	dw	ARM_instruction_pkhbt-instruction_handler
	db	'pkhtb',0xe0
	dw	ARM_instruction_pkhtb-instruction_handler
	db	'pld~~',0x00
	dw	ARM_instruction_pld-instruction_handler
	db	'pli~~',0x00
	dw	ARM_instruction_pli-instruction_handler
	db	'pmull',0xf0
	dw	ARM_instruction_pmull-instruction_handler
	db	'poldm',0xe0
	dw	ARM_instruction_poldm-instruction_handler
	db	'poldp',0xe0
	dw	ARM_instruction_poldp-instruction_handler
	db	'poldz',0xe0
	dw	ARM_instruction_poldz-instruction_handler
	db	'polem',0xe0
	dw	ARM_instruction_polem-instruction_handler
	db	'polep',0xe0
	dw	ARM_instruction_polep-instruction_handler
	db	'polez',0xe0
	dw	ARM_instruction_polez-instruction_handler
	db	'polsm',0xe0
	dw	ARM_instruction_polsm-instruction_handler
	db	'polsp',0xe0
	dw	ARM_instruction_polsp-instruction_handler
	db	'polsz',0xe0
	dw	ARM_instruction_polsz-instruction_handler
	db	'pop.n',0xe4
	dw	ARM_instruction_pop-instruction_handler
	db	'pop.w',0xe2
	dw	ARM_instruction_pop-instruction_handler
	db	'pop~~',0x00
	dw	ARM_instruction_pop-instruction_handler
	db	'powdm',0xe0
	dw	ARM_instruction_powdm-instruction_handler
	db	'powdp',0xe0
	dw	ARM_instruction_powdp-instruction_handler
	db	'powdz',0xe0
	dw	ARM_instruction_powdz-instruction_handler
	db	'powem',0xe0
	dw	ARM_instruction_powem-instruction_handler
	db	'powep',0xe0
	dw	ARM_instruction_powep-instruction_handler
	db	'powez',0xe0
	dw	ARM_instruction_powez-instruction_handler
	db	'powsm',0xe0
	dw	ARM_instruction_powsm-instruction_handler
	db	'powsp',0xe0
	dw	ARM_instruction_powsp-instruction_handler
	db	'powsz',0xe0
	dw	ARM_instruction_powsz-instruction_handler
	db	'qadd8',0xe0
	dw	ARM_instruction_qadd8-instruction_handler
	db	'qdadd',0xe0
	dw	ARM_instruction_qdadd-instruction_handler
	db	'qdsub',0xe0
	dw	ARM_instruction_qdsub-instruction_handler
	db	'qsub8',0xe0
	dw	ARM_instruction_qsub8-instruction_handler
	db	'rdfdm',0xe0
	dw	ARM_instruction_rdfdm-instruction_handler
	db	'rdfdp',0xe0
	dw	ARM_instruction_rdfdp-instruction_handler
	db	'rdfdz',0xe0
	dw	ARM_instruction_rdfdz-instruction_handler
	db	'rdfem',0xe0
	dw	ARM_instruction_rdfem-instruction_handler
	db	'rdfep',0xe0
	dw	ARM_instruction_rdfep-instruction_handler
	db	'rdfez',0xe0
	dw	ARM_instruction_rdfez-instruction_handler
	db	'rdfsm',0xe0
	dw	ARM_instruction_rdfsm-instruction_handler
	db	'rdfsp',0xe0
	dw	ARM_instruction_rdfsp-instruction_handler
	db	'rdfsz',0xe0
	dw	ARM_instruction_rdfsz-instruction_handler
	db	'rev.n',0xe4
	dw	ARM_instruction_rev-instruction_handler
	db	'rev.w',0xe2
	dw	ARM_instruction_rev-instruction_handler
	db	'rev16',0xe0
	dw	ARM_instruction_rev16-instruction_handler
	db	'rev32',0xf0
	dw	ARM_instruction_rev32-instruction_handler
	db	'rev64',0xf0
	dw	ARM_instruction_rev64-instruction_handler
	db	'revsh',0xe0
	dw	ARM_instruction_revsh-instruction_handler
	db	'rev~~',0x00
	dw	ARM_instruction_rev-instruction_handler
	db	'rfc~~',0x00
	dw	ARM_instruction_rfc-instruction_handler
	db	'rfeda',0xf0
	dw	ARM_instruction_rfeda-instruction_handler
	db	'rfedb',0xf0
	dw	ARM_instruction_rfedb-instruction_handler
	db	'rfeea',0xf0
	dw	ARM_instruction_rfeea-instruction_handler
	db	'rfeed',0xf0
	dw	ARM_instruction_rfeed-instruction_handler
	db	'rfefa',0xf0
	dw	ARM_instruction_rfefa-instruction_handler
	db	'rfefd',0xf0
	dw	ARM_instruction_rfefd-instruction_handler
	db	'rfeia',0xf0
	dw	ARM_instruction_rfeia-instruction_handler
	db	'rfeib',0xf0
	dw	ARM_instruction_rfeib-instruction_handler
	db	'rfs~~',0x00
	dw	ARM_instruction_rfs-instruction_handler
	db	'rmfdm',0xe0
	dw	ARM_instruction_rmfdm-instruction_handler
	db	'rmfdp',0xe0
	dw	ARM_instruction_rmfdp-instruction_handler
	db	'rmfdz',0xe0
	dw	ARM_instruction_rmfdz-instruction_handler
	db	'rmfem',0xe0
	dw	ARM_instruction_rmfem-instruction_handler
	db	'rmfep',0xe0
	dw	ARM_instruction_rmfep-instruction_handler
	db	'rmfez',0xe0
	dw	ARM_instruction_rmfez-instruction_handler
	db	'rmfsm',0xe0
	dw	ARM_instruction_rmfsm-instruction_handler
	db	'rmfsp',0xe0
	dw	ARM_instruction_rmfsp-instruction_handler
	db	'rmfsz',0xe0
	dw	ARM_instruction_rmfsz-instruction_handler
	db	'rnddm',0xe0
	dw	ARM_instruction_rnddm-instruction_handler
	db	'rnddp',0xe0
	dw	ARM_instruction_rnddp-instruction_handler
	db	'rnddz',0xe0
	dw	ARM_instruction_rnddz-instruction_handler
	db	'rndem',0xe0
	dw	ARM_instruction_rndem-instruction_handler
	db	'rndep',0xe0
	dw	ARM_instruction_rndep-instruction_handler
	db	'rndez',0xe0
	dw	ARM_instruction_rndez-instruction_handler
	db	'rndsm',0xe0
	dw	ARM_instruction_rndsm-instruction_handler
	db	'rndsp',0xe0
	dw	ARM_instruction_rndsp-instruction_handler
	db	'rndsz',0xe0
	dw	ARM_instruction_rndsz-instruction_handler
	db	'ror.n',0xe4
	dw	ARM_instruction_ror-instruction_handler
	db	'ror.w',0xe2
	dw	ARM_instruction_ror-instruction_handler
	db	'ror~~',0x00
	dw	ARM_instruction_ror-instruction_handler
	db	'rpwdm',0xe0
	dw	ARM_instruction_rpwdm-instruction_handler
	db	'rpwdp',0xe0
	dw	ARM_instruction_rpwdp-instruction_handler
	db	'rpwdz',0xe0
	dw	ARM_instruction_rpwdz-instruction_handler
	db	'rpwem',0xe0
	dw	ARM_instruction_rpwem-instruction_handler
	db	'rpwep',0xe0
	dw	ARM_instruction_rpwep-instruction_handler
	db	'rpwez',0xe0
	dw	ARM_instruction_rpwez-instruction_handler
	db	'rpwsm',0xe0
	dw	ARM_instruction_rpwsm-instruction_handler
	db	'rpwsp',0xe0
	dw	ARM_instruction_rpwsp-instruction_handler
	db	'rpwsz',0xe0
	dw	ARM_instruction_rpwsz-instruction_handler
	db	'rrx~~',0x00
	dw	ARM_instruction_rrx-instruction_handler
	db	'rsb.n',0xe4
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsb.w',0xe2
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsb~~',0x00
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsc~~',0x00
	dw	ARM_instruction_rsc-instruction_handler
	db	'rsfdm',0xe0
	dw	ARM_instruction_rsfdm-instruction_handler
	db	'rsfdp',0xe0
	dw	ARM_instruction_rsfdp-instruction_handler
	db	'rsfdz',0xe0
	dw	ARM_instruction_rsfdz-instruction_handler
	db	'rsfem',0xe0
	dw	ARM_instruction_rsfem-instruction_handler
	db	'rsfep',0xe0
	dw	ARM_instruction_rsfep-instruction_handler
	db	'rsfez',0xe0
	dw	ARM_instruction_rsfez-instruction_handler
	db	'rsfsm',0xe0
	dw	ARM_instruction_rsfsm-instruction_handler
	db	'rsfsp',0xe0
	dw	ARM_instruction_rsfsp-instruction_handler
	db	'rsfsz',0xe0
	dw	ARM_instruction_rsfsz-instruction_handler
	db	'rshrn',0xf0
	dw	ARM_instruction_rshrn-instruction_handler
	db	'sabal',0xf0
	dw	ARM_instruction_sabal-instruction_handler
	db	'sabdl',0xf0
	dw	ARM_instruction_sabdl-instruction_handler
	db	'sadd8',0xe0
	dw	ARM_instruction_sadd8-instruction_handler
	db	'saddl',0xf0
	dw	ARM_instruction_saddl-instruction_handler
	db	'saddw',0xf0
	dw	ARM_instruction_saddw-instruction_handler
	db	'sbc.n',0xe4
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbc.w',0xe2
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbc~~',0x00
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbfiz',0xf0
	dw	ARM_instruction_sbfiz-instruction_handler
	db	'scvtf',0xf0
	dw	ARM_instruction_scvtf-instruction_handler
	db	'sel~~',0x00
	dw	ARM_instruction_sel-instruction_handler
	db	'sev.n',0xe4
	dw	ARM_instruction_sev-instruction_handler
	db	'sev.w',0xe2
	dw	ARM_instruction_sev-instruction_handler
	db	'sev~~',0x00
	dw	ARM_instruction_sev-instruction_handler
	db	'sfmea',0xe0
	dw	ARM_instruction_sfmea-instruction_handler
	db	'sfmfd',0xe0
	dw	ARM_instruction_sfmfd-instruction_handler
	db	'sfm~~',0x00
	dw	ARM_instruction_sfm-instruction_handler
	db	'sha1c',0xf0
	dw	ARM_instruction_sha1c-instruction_handler
	db	'sha1h',0xf0
	dw	ARM_instruction_sha1h-instruction_handler
	db	'sha1m',0xf0
	dw	ARM_instruction_sha1m-instruction_handler
	db	'sha1p',0xf0
	dw	ARM_instruction_sha1p-instruction_handler
	db	'shadd',0xf0
	dw	ARM_instruction_shadd-instruction_handler
	db	'shasx',0xe0
	dw	ARM_instruction_shasx-instruction_handler
	db	'shll2',0xf0
	dw	ARM_instruction_shll2-instruction_handler
	db	'shrn2',0xf0
	dw	ARM_instruction_shrn2-instruction_handler
	db	'shsax',0xe0
	dw	ARM_instruction_shsax-instruction_handler
	db	'shsub',0xf0
	dw	ARM_instruction_shsub-instruction_handler
	db	'sindm',0xe0
	dw	ARM_instruction_sindm-instruction_handler
	db	'sindp',0xe0
	dw	ARM_instruction_sindp-instruction_handler
	db	'sindz',0xe0
	dw	ARM_instruction_sindz-instruction_handler
	db	'sinem',0xe0
	dw	ARM_instruction_sinem-instruction_handler
	db	'sinep',0xe0
	dw	ARM_instruction_sinep-instruction_handler
	db	'sinez',0xe0
	dw	ARM_instruction_sinez-instruction_handler
	db	'sinsm',0xe0
	dw	ARM_instruction_sinsm-instruction_handler
	db	'sinsp',0xe0
	dw	ARM_instruction_sinsp-instruction_handler
	db	'sinsz',0xe0
	dw	ARM_instruction_sinsz-instruction_handler
	db	'smaxp',0xf0
	dw	ARM_instruction_smaxp-instruction_handler
	db	'smaxv',0xf0
	dw	ARM_instruction_smaxv-instruction_handler
	db	'smc~~',0x00
	dw	ARM_instruction_smc-instruction_handler
	db	'sminp',0xf0
	dw	ARM_instruction_sminp-instruction_handler
	db	'sminv',0xf0
	dw	ARM_instruction_sminv-instruction_handler
	db	'smi~~',0x00
	dw	ARM_instruction_smi-instruction_handler
	db	'smlad',0xe0
	dw	ARM_instruction_smlad-instruction_handler
	db	'smlal',0xe0
	dw	ARM_instruction_smlal-instruction_handler
	db	'smlsd',0xe0
	dw	ARM_instruction_smlsd-instruction_handler
	db	'smlsl',0xf0
	dw	ARM_instruction_smlsl-instruction_handler
	db	'smmla',0xe0
	dw	ARM_instruction_smmla-instruction_handler
	db	'smmls',0xe0
	dw	ARM_instruction_smmls-instruction_handler
	db	'smmul',0xe0
	dw	ARM_instruction_smmul-instruction_handler
	db	'smuad',0xe0
	dw	ARM_instruction_smuad-instruction_handler
	db	'smulh',0xf0
	dw	ARM_instruction_smulh-instruction_handler
	db	'smull',0xe0
	dw	ARM_instruction_smull-instruction_handler
	db	'smusd',0xe0
	dw	ARM_instruction_smusd-instruction_handler
	db	'sqabs',0xf0
	dw	ARM_instruction_sqabs-instruction_handler
	db	'sqadd',0xf0
	dw	ARM_instruction_sqadd-instruction_handler
	db	'sqneg',0xf0
	dw	ARM_instruction_sqneg-instruction_handler
	db	'sqshl',0xf0
	dw	ARM_instruction_sqshl-instruction_handler
	db	'sqsub',0xf0
	dw	ARM_instruction_sqsub-instruction_handler
	db	'sqtdm',0xe0
	dw	ARM_instruction_sqtdm-instruction_handler
	db	'sqtdp',0xe0
	dw	ARM_instruction_sqtdp-instruction_handler
	db	'sqtdz',0xe0
	dw	ARM_instruction_sqtdz-instruction_handler
	db	'sqtem',0xe0
	dw	ARM_instruction_sqtem-instruction_handler
	db	'sqtep',0xe0
	dw	ARM_instruction_sqtep-instruction_handler
	db	'sqtez',0xe0
	dw	ARM_instruction_sqtez-instruction_handler
	db	'sqtsm',0xe0
	dw	ARM_instruction_sqtsm-instruction_handler
	db	'sqtsp',0xe0
	dw	ARM_instruction_sqtsp-instruction_handler
	db	'sqtsz',0xe0
	dw	ARM_instruction_sqtsz-instruction_handler
	db	'sqxtn',0xf0
	dw	ARM_instruction_sqxtn-instruction_handler
	db	'srsda',0xf0
	dw	ARM_instruction_srsda-instruction_handler
	db	'srsdb',0xf0
	dw	ARM_instruction_srsdb-instruction_handler
	db	'srsea',0xf0
	dw	ARM_instruction_srsea-instruction_handler
	db	'srsed',0xf0
	dw	ARM_instruction_srsed-instruction_handler
	db	'srsfa',0xf0
	dw	ARM_instruction_srsfa-instruction_handler
	db	'srsfd',0xf0
	dw	ARM_instruction_srsfd-instruction_handler
	db	'srshl',0xf0
	dw	ARM_instruction_srshl-instruction_handler
	db	'srshr',0xf0
	dw	ARM_instruction_srshr-instruction_handler
	db	'srsia',0xf0
	dw	ARM_instruction_srsia-instruction_handler
	db	'srsib',0xf0
	dw	ARM_instruction_srsib-instruction_handler
	db	'srsra',0xf0
	dw	ARM_instruction_srsra-instruction_handler
	db	'sshll',0xf0
	dw	ARM_instruction_sshll-instruction_handler
	db	'ssub8',0xe0
	dw	ARM_instruction_ssub8-instruction_handler
	db	'ssubl',0xf0
	dw	ARM_instruction_ssubl-instruction_handler
	db	'ssubw',0xf0
	dw	ARM_instruction_ssubw-instruction_handler
	db	'stack',0x00
	dw	stack_directive-instruction_handler
	db	'stc2l',0xe0
	dw	ARM_instruction_stc2l-instruction_handler
	db	'stc~~',0x00
	dw	ARM_instruction_stc-instruction_handler
	db	'stlex',0xe0
	dw	ARM_instruction_stlex-instruction_handler
	db	'stlrb',0xf0
	dw	ARM_instruction_stlrb-instruction_handler
	db	'stlrh',0xf0
	dw	ARM_instruction_stlrh-instruction_handler
	db	'stlxp',0xf0
	dw	ARM_instruction_stlxp-instruction_handler
	db	'stlxr',0xf0
	dw	ARM_instruction_stlxr-instruction_handler
	db	'stl~~',0x00
	dw	ARM_instruction_stl-instruction_handler
	db	'stm.n',0xe4
	dw	ARM_instruction_stm-instruction_handler
	db	'stm.w',0xe2
	dw	ARM_instruction_stm-instruction_handler
	db	'stmda',0xe0
	dw	ARM_instruction_stmda-instruction_handler
	db	'stmdb',0xe0
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stmea',0xe0
	dw	ARM_instruction_stmea-instruction_handler
	db	'stmed',0xe0
	dw	ARM_instruction_stmed-instruction_handler
	db	'stmfa',0xe0
	dw	ARM_instruction_stmfa-instruction_handler
	db	'stmfd',0xe0
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stmia',0xe0
	dw	ARM_instruction_stmia-instruction_handler
	db	'stmib',0xe0
	dw	ARM_instruction_stmib-instruction_handler
	db	'stm~~',0x00
	dw	ARM_instruction_stm-instruction_handler
	db	'store',0x00
	dw	store_directive-instruction_handler
	db	'str.n',0xe4
	dw	ARM_instruction_str-instruction_handler
	db	'str.w',0xe2
	dw	ARM_instruction_str-instruction_handler
	db	'strbt',0xe0
	dw	ARM_instruction_strbt-instruction_handler
	db	'strex',0xe0
	dw	ARM_instruction_strex-instruction_handler
	db	'strht',0xe0
	dw	ARM_instruction_strht-instruction_handler
	db	'str~~',0x00
	dw	ARM_instruction_str-instruction_handler
	db	'sttrb',0xf0
	dw	ARM_instruction_sttrb-instruction_handler
	db	'sttrh',0xf0
	dw	ARM_instruction_sttrh-instruction_handler
	db	'sturb',0xf0
	dw	ARM_instruction_sturb-instruction_handler
	db	'sturh',0xf0
	dw	ARM_instruction_sturh-instruction_handler
	db	'stxrb',0xf0
	dw	ARM_instruction_stxrb-instruction_handler
	db	'stxrh',0xf0
	dw	ARM_instruction_stxrh-instruction_handler
	db	'sub.n',0xe4
	dw	ARM_instruction_sub-instruction_handler
	db	'sub.w',0xe2
	dw	ARM_instruction_sub-instruction_handler
	db	'subhn',0xf0
	dw	ARM_instruction_subhn-instruction_handler
	db	'sub~~',0x00
	dw	ARM_instruction_sub-instruction_handler
	db	'sufdm',0xe0
	dw	ARM_instruction_sufdm-instruction_handler
	db	'sufdp',0xe0
	dw	ARM_instruction_sufdp-instruction_handler
	db	'sufdz',0xe0
	dw	ARM_instruction_sufdz-instruction_handler
	db	'sufem',0xe0
	dw	ARM_instruction_sufem-instruction_handler
	db	'sufep',0xe0
	dw	ARM_instruction_sufep-instruction_handler
	db	'sufez',0xe0
	dw	ARM_instruction_sufez-instruction_handler
	db	'sufsm',0xe0
	dw	ARM_instruction_sufsm-instruction_handler
	db	'sufsp',0xe0
	dw	ARM_instruction_sufsp-instruction_handler
	db	'sufsz',0xe0
	dw	ARM_instruction_sufsz-instruction_handler
	db	'svc.n',0xe4
	dw	ARM_instruction_svc-instruction_handler
	db	'svc.w',0xe2
	dw	ARM_instruction_svc-instruction_handler
	db	'svc~~',0x00
	dw	ARM_instruction_svc-instruction_handler
	db	'swi.n',0xe4
	dw	ARM_instruction_swi-instruction_handler
	db	'swi.w',0xe2
	dw	ARM_instruction_swi-instruction_handler
	db	'swi~~',0x00
	dw	ARM_instruction_swi-instruction_handler
	db	'swp~~',0x00
	dw	ARM_instruction_swp-instruction_handler
	db	'sxtab',0xe0
	dw	ARM_instruction_sxtab-instruction_handler
	db	'sxtah',0xe0
	dw	ARM_instruction_sxtah-instruction_handler
	db	'sxtl2',0xf0
	dw	ARM_instruction_sxtl2-instruction_handler
	db	'tandm',0xe0
	dw	ARM_instruction_tandm-instruction_handler
	db	'tandp',0xe0
	dw	ARM_instruction_tandp-instruction_handler
	db	'tandz',0xe0
	dw	ARM_instruction_tandz-instruction_handler
	db	'tanem',0xe0
	dw	ARM_instruction_tanem-instruction_handler
	db	'tanep',0xe0
	dw	ARM_instruction_tanep-instruction_handler
	db	'tanez',0xe0
	dw	ARM_instruction_tanez-instruction_handler
	db	'tansm',0xe0
	dw	ARM_instruction_tansm-instruction_handler
	db	'tansp',0xe0
	dw	ARM_instruction_tansp-instruction_handler
	db	'tansz',0xe0
	dw	ARM_instruction_tansz-instruction_handler
	db	'tbb~~',0x00
	dw	ARM_instruction_tbb-instruction_handler
	db	'tbh~~',0x00
	dw	ARM_instruction_tbh-instruction_handler
	db	'teq~~',0x00
	dw	ARM_instruction_teq-instruction_handler
	db	'thumb',0x00
	dw	ARM_thumb_directive-instruction_handler
	db	'times',0x00
	dw	times_directive-instruction_handler
	db	'tmcrr',0xe0
	dw	ARM_instruction_tmcrr-instruction_handler
	db	'tmrrc',0xe0
	dw	ARM_instruction_tmrrc-instruction_handler
	db	'torcb',0xe0
	dw	ARM_instruction_torcb-instruction_handler
	db	'torch',0xe0
	dw	ARM_instruction_torch-instruction_handler
	db	'torcw',0xe0
	dw	ARM_instruction_torcw-instruction_handler
	db	'tst.n',0xe4
	dw	ARM_instruction_tst-instruction_handler
	db	'tst.w',0xe2
	dw	ARM_instruction_tst-instruction_handler
	db	'tst~~',0x00
	dw	ARM_instruction_tst-instruction_handler
	db	'uabal',0xf0
	dw	ARM_instruction_uabal-instruction_handler
	db	'uabdl',0xf0
	dw	ARM_instruction_uabdl-instruction_handler
	db	'uadd8',0xe0
	dw	ARM_instruction_uadd8-instruction_handler
	db	'uaddl',0xf0
	dw	ARM_instruction_uaddl-instruction_handler
	db	'uaddw',0xf0
	dw	ARM_instruction_uaddw-instruction_handler
	db	'ubfiz',0xf0
	dw	ARM_instruction_ubfiz-instruction_handler
	db	'ucvtf',0xf0
	dw	ARM_instruction_ucvtf-instruction_handler
	db	'uhadd',0xf0
	dw	ARM_instruction_uhadd-instruction_handler
	db	'uhasx',0xe0
	dw	ARM_instruction_uhasx-instruction_handler
	db	'uhsax',0xe0
	dw	ARM_instruction_uhsax-instruction_handler
	db	'uhsub',0xf0
	dw	ARM_instruction_uhsub-instruction_handler
	db	'umaal',0xe0
	dw	ARM_instruction_umaal-instruction_handler
	db	'umaxp',0xf0
	dw	ARM_instruction_umaxp-instruction_handler
	db	'umaxv',0xf0
	dw	ARM_instruction_umaxv-instruction_handler
	db	'uminp',0xf0
	dw	ARM_instruction_uminp-instruction_handler
	db	'uminv',0xf0
	dw	ARM_instruction_uminv-instruction_handler
	db	'umlal',0xe0
	dw	ARM_instruction_umlal-instruction_handler
	db	'umlsl',0xf0
	dw	ARM_instruction_umlsl-instruction_handler
	db	'umulh',0xf0
	dw	ARM_instruction_umulh-instruction_handler
	db	'umull',0xe0
	dw	ARM_instruction_umull-instruction_handler
	db	'und.n',0xe4
	dw	ARM_instruction_und-instruction_handler
	db	'und.w',0xe2
	dw	ARM_instruction_und-instruction_handler
	db	'und~~',0x00
	dw	ARM_instruction_und-instruction_handler
	db	'uqadd',0xf0
	dw	ARM_instruction_uqadd-instruction_handler
	db	'uqasx',0xe0
	dw	ARM_instruction_uqasx-instruction_handler
	db	'uqsax',0xe0
	dw	ARM_instruction_uqsax-instruction_handler
	db	'uqshl',0xf0
	dw	ARM_instruction_uqshl-instruction_handler
	db	'uqsub',0xf0
	dw	ARM_instruction_uqsub-instruction_handler
	db	'uqxtn',0xf0
	dw	ARM_instruction_uqxtn-instruction_handler
	db	'urddm',0xe0
	dw	ARM_instruction_urddm-instruction_handler
	db	'urddp',0xe0
	dw	ARM_instruction_urddp-instruction_handler
	db	'urddz',0xe0
	dw	ARM_instruction_urddz-instruction_handler
	db	'urdem',0xe0
	dw	ARM_instruction_urdem-instruction_handler
	db	'urdep',0xe0
	dw	ARM_instruction_urdep-instruction_handler
	db	'urdez',0xe0
	dw	ARM_instruction_urdez-instruction_handler
	db	'urdsm',0xe0
	dw	ARM_instruction_urdsm-instruction_handler
	db	'urdsp',0xe0
	dw	ARM_instruction_urdsp-instruction_handler
	db	'urdsz',0xe0
	dw	ARM_instruction_urdsz-instruction_handler
	db	'urshl',0xf0
	dw	ARM_instruction_urshl-instruction_handler
	db	'urshr',0xf0
	dw	ARM_instruction_urshr-instruction_handler
	db	'ursra',0xf0
	dw	ARM_instruction_ursra-instruction_handler
	db	'usad8',0xe0
	dw	ARM_instruction_usad8-instruction_handler
	db	'use16',0x00
	dw	ARM_code16_directive-instruction_handler
	db	'use32',0x00
	dw	ARM_code32_directive-instruction_handler
	db	'use64',0x00
	dw	ARM_code64_directive-instruction_handler
	db	'ushll',0xf0
	dw	ARM_instruction_ushll-instruction_handler
	db	'usub8',0xe0
	dw	ARM_instruction_usub8-instruction_handler
	db	'usubl',0xf0
	dw	ARM_instruction_usubl-instruction_handler
	db	'usubw',0xf0
	dw	ARM_instruction_usubw-instruction_handler
	db	'uxtab',0xe0
	dw	ARM_instruction_uxtab-instruction_handler
	db	'uxtah',0xe0
	dw	ARM_instruction_uxtah-instruction_handler
	db	'uxtl2',0xf0
	dw	ARM_instruction_uxtl2-instruction_handler
	db	'vpush',0xe0
	dw	ARM_instruction_vpush-instruction_handler
	db	'wabsb',0xe0
	dw	ARM_instruction_wabsb-instruction_handler
	db	'wabsh',0xe0
	dw	ARM_instruction_wabsh-instruction_handler
	db	'wabsw',0xe0
	dw	ARM_instruction_wabsw-instruction_handler
	db	'waccb',0xe0
	dw	ARM_instruction_waccb-instruction_handler
	db	'wacch',0xe0
	dw	ARM_instruction_wacch-instruction_handler
	db	'waccw',0xe0
	dw	ARM_instruction_waccw-instruction_handler
	db	'waddb',0xe0
	dw	ARM_instruction_waddb-instruction_handler
	db	'waddh',0xe0
	dw	ARM_instruction_waddh-instruction_handler
	db	'waddw',0xe0
	dw	ARM_instruction_waddw-instruction_handler
	db	'wandn',0xe0
	dw	ARM_instruction_wandn-instruction_handler
	db	'wavg4',0xe0
	dw	ARM_instruction_wavg4-instruction_handler
	db	'wfc~~',0x00
	dw	ARM_instruction_wfc-instruction_handler
	db	'wfe.n',0xe4
	dw	ARM_instruction_wfe-instruction_handler
	db	'wfe.w',0xe2
	dw	ARM_instruction_wfe-instruction_handler
	db	'wfe~~',0x00
	dw	ARM_instruction_wfe-instruction_handler
	db	'wfi.n',0xe4
	dw	ARM_instruction_wfi-instruction_handler
	db	'wfi.w',0xe2
	dw	ARM_instruction_wfi-instruction_handler
	db	'wfi~~',0x00
	dw	ARM_instruction_wfi-instruction_handler
	db	'wfs~~',0x00
	dw	ARM_instruction_wfs-instruction_handler
	db	'while',0x00
	dw	while_directive-instruction_handler
	db	'wldrb',0xe0
	dw	ARM_instruction_wldrb-instruction_handler
	db	'wldrd',0xe0
	dw	ARM_instruction_wldrd-instruction_handler
	db	'wldrh',0xe0
	dw	ARM_instruction_wldrh-instruction_handler
	db	'wldrw',0xe0
	dw	ARM_instruction_wldrw-instruction_handler
	db	'wmacs',0xe0
	dw	ARM_instruction_wmacs-instruction_handler
	db	'wmacu',0xe0
	dw	ARM_instruction_wmacu-instruction_handler
	db	'wor~~',0x00
	dw	ARM_instruction_wor-instruction_handler
	db	'wrord',0xe0
	dw	ARM_instruction_wrord-instruction_handler
	db	'wrorh',0xe0
	dw	ARM_instruction_wrorh-instruction_handler
	db	'wrorw',0xe0
	dw	ARM_instruction_wrorw-instruction_handler
	db	'wsadb',0xe0
	dw	ARM_instruction_wsadb-instruction_handler
	db	'wsadh',0xe0
	dw	ARM_instruction_wsadh-instruction_handler
	db	'wslld',0xe0
	dw	ARM_instruction_wslld-instruction_handler
	db	'wsllh',0xe0
	dw	ARM_instruction_wsllh-instruction_handler
	db	'wsllw',0xe0
	dw	ARM_instruction_wsllw-instruction_handler
	db	'wsrad',0xe0
	dw	ARM_instruction_wsrad-instruction_handler
	db	'wsrah',0xe0
	dw	ARM_instruction_wsrah-instruction_handler
	db	'wsraw',0xe0
	dw	ARM_instruction_wsraw-instruction_handler
	db	'wsrld',0xe0
	dw	ARM_instruction_wsrld-instruction_handler
	db	'wsrlh',0xe0
	dw	ARM_instruction_wsrlh-instruction_handler
	db	'wsrlw',0xe0
	dw	ARM_instruction_wsrlw-instruction_handler
	db	'wstrb',0xe0
	dw	ARM_instruction_wstrb-instruction_handler
	db	'wstrd',0xe0
	dw	ARM_instruction_wstrd-instruction_handler
	db	'wstrh',0xe0
	dw	ARM_instruction_wstrh-instruction_handler
	db	'wstrw',0xe0
	dw	ARM_instruction_wstrw-instruction_handler
	db	'wsubb',0xe0
	dw	ARM_instruction_wsubb-instruction_handler
	db	'wsubh',0xe0
	dw	ARM_instruction_wsubh-instruction_handler
	db	'wsubw',0xe0
	dw	ARM_instruction_wsubw-instruction_handler
	db	'wzero',0xe0
	dw	ARM_instruction_wzero-instruction_handler
	db	'yield',0xe0
	dw	ARM_instruction_yield-instruction_handler
	db	0
instructions_6:
	db	'abs~~d',0x00
	dw	ARM_instruction_absd-instruction_handler
	db	'abs~~e',0x00
	dw	ARM_instruction_abse-instruction_handler
	db	'abs~~s',0x00
	dw	ARM_instruction_abss-instruction_handler
	db	'acs~~d',0x00
	dw	ARM_instruction_acsd-instruction_handler
	db	'acs~~e',0x00
	dw	ARM_instruction_acse-instruction_handler
	db	'acs~~s',0x00
	dw	ARM_instruction_acss-instruction_handler
	db	'adcs.n',0xe5
	dw	ARM_instruction_adc-instruction_handler
	db	'adcs.w',0xe3
	dw	ARM_instruction_adc-instruction_handler
	db	'adcs~~',0x01
	dw	ARM_instruction_adc-instruction_handler
	db	'adc~~s',0x01
	dw	ARM_instruction_adc-instruction_handler
	db	'addhn2',0xf0
	dw	ARM_instruction_addhn2-instruction_handler
	db	'adds.n',0xe5
	dw	ARM_instruction_add-instruction_handler
	db	'adds.w',0xe3
	dw	ARM_instruction_add-instruction_handler
	db	'adds~~',0x01
	dw	ARM_instruction_add-instruction_handler
	db	'addw~~',0x00
	dw	ARM_instruction_addw-instruction_handler
	db	'add~~s',0x01
	dw	ARM_instruction_add-instruction_handler
	db	'adf~~d',0x00
	dw	ARM_instruction_adfd-instruction_handler
	db	'adf~~e',0x00
	dw	ARM_instruction_adfe-instruction_handler
	db	'adf~~s',0x00
	dw	ARM_instruction_adfs-instruction_handler
	db	'aesd.8',0xf0
	dw	ARM_instruction_aesd.8-instruction_handler
	db	'aese.8',0xf0
	dw	ARM_instruction_aese.8-instruction_handler
	db	'aesimc',0xf0
	dw	ARM_instruction_aesimc-instruction_handler
	db	'ands.n',0xe5
	dw	ARM_instruction_and-instruction_handler
	db	'ands.w',0xe3
	dw	ARM_instruction_and-instruction_handler
	db	'ands~~',0x01
	dw	ARM_instruction_and-instruction_handler
	db	'and~~s',0x01
	dw	ARM_instruction_and-instruction_handler
	db	'asn~~d',0x00
	dw	ARM_instruction_asnd-instruction_handler
	db	'asn~~e',0x00
	dw	ARM_instruction_asne-instruction_handler
	db	'asn~~s',0x00
	dw	ARM_instruction_asns-instruction_handler
	db	'asrs.n',0xe5
	dw	ARM_instruction_asr-instruction_handler
	db	'asrs.w',0xe3
	dw	ARM_instruction_asr-instruction_handler
	db	'asrs~~',0x01
	dw	ARM_instruction_asr-instruction_handler
	db	'asr~~s',0x01
	dw	ARM_instruction_asr-instruction_handler
	db	'assert',0x00
	dw	assert_directive-instruction_handler
	db	'atn~~d',0x00
	dw	ARM_instruction_atnd-instruction_handler
	db	'atn~~e',0x00
	dw	ARM_instruction_atne-instruction_handler
	db	'atn~~s',0x00
	dw	ARM_instruction_atns-instruction_handler
	db	'bics.n',0xe5
	dw	ARM_instruction_bic-instruction_handler
	db	'bics.w',0xe3
	dw	ARM_instruction_bic-instruction_handler
	db	'bics~~',0x01
	dw	ARM_instruction_bic-instruction_handler
	db	'bic~~s',0x01
	dw	ARM_instruction_bic-instruction_handler
	db	'bx~~.n',0x04
	dw	ARM_instruction_bx-instruction_handler
	db	'bx~~.w',0x02
	dw	ARM_instruction_bx-instruction_handler
	db	'cbnz.n',0xf4
	dw	ARM_instruction_cbnz-instruction_handler
	db	'cbnz.w',0xf2
	dw	ARM_instruction_cbnz-instruction_handler
	db	'cdp2~~',0x00
	dw	ARM_instruction_cdp2-instruction_handler
	db	'cfabsd',0xe0
	dw	ARM_instruction_cfabsd-instruction_handler
	db	'cfabss',0xe0
	dw	ARM_instruction_cfabss-instruction_handler
	db	'cfaddd',0xe0
	dw	ARM_instruction_cfaddd-instruction_handler
	db	'cfadds',0xe0
	dw	ARM_instruction_cfadds-instruction_handler
	db	'cfcmpd',0xe0
	dw	ARM_instruction_cfcmpd-instruction_handler
	db	'cfcmps',0xe0
	dw	ARM_instruction_cfcmps-instruction_handler
	db	'cfcpyd',0xe0
	dw	ARM_instruction_cfcpyd-instruction_handler
	db	'cfcpys',0xe0
	dw	ARM_instruction_cfcpys-instruction_handler
	db	'cfldrd',0xe0
	dw	ARM_instruction_cfldrd-instruction_handler
	db	'cfldrs',0xe0
	dw	ARM_instruction_cfldrs-instruction_handler
	db	'cfmuld',0xe0
	dw	ARM_instruction_cfmuld-instruction_handler
	db	'cfmuls',0xe0
	dw	ARM_instruction_cfmuls-instruction_handler
	db	'cfmvrs',0xe0
	dw	ARM_instruction_cfmvrs-instruction_handler
	db	'cfmvsr',0xe0
	dw	ARM_instruction_cfmvsr-instruction_handler
	db	'cfnegd',0xe0
	dw	ARM_instruction_cfnegd-instruction_handler
	db	'cfnegs',0xe0
	dw	ARM_instruction_cfnegs-instruction_handler
	db	'cfsh32',0xe0
	dw	ARM_instruction_cfsh32-instruction_handler
	db	'cfsh64',0xe0
	dw	ARM_instruction_cfsh64-instruction_handler
	db	'cfstrd',0xe0
	dw	ARM_instruction_cfstrd-instruction_handler
	db	'cfstrs',0xe0
	dw	ARM_instruction_cfstrs-instruction_handler
	db	'cfsubd',0xe0
	dw	ARM_instruction_cfsubd-instruction_handler
	db	'cfsubs',0xe0
	dw	ARM_instruction_cfsubs-instruction_handler
	db	'chka~~',0x00
	dw	ARM_instruction_chka-instruction_handler
	db	'cmfe~~',0x00
	dw	ARM_instruction_cmfe-instruction_handler
	db	'cmnp~~',0x00
	dw	ARM_instruction_cmnp-instruction_handler
	db	'cmn~~p',0x00
	dw	ARM_instruction_cmnp-instruction_handler
	db	'cmpp~~',0x00
	dw	ARM_instruction_cmpp-instruction_handler
	db	'cmp~~p',0x00
	dw	ARM_instruction_cmpp-instruction_handler
	db	'cnfe~~',0x00
	dw	ARM_instruction_cnfe-instruction_handler
	db	'code16',0x00
	dw	ARM_code16_directive-instruction_handler
	db	'code32',0x00
	dw	ARM_code32_directive-instruction_handler
	db	'code64',0x00
	dw	ARM_code64_directive-instruction_handler
	db	'cos~~d',0x00
	dw	ARM_instruction_cosd-instruction_handler
	db	'cos~~e',0x00
	dw	ARM_instruction_cose-instruction_handler
	db	'cos~~s',0x00
	dw	ARM_instruction_coss-instruction_handler
	db	'crc32b',0xf0
	dw	ARM_instruction_crc32b-instruction_handler
	db	'crc32h',0xf0
	dw	ARM_instruction_crc32h-instruction_handler
	db	'crc32w',0xf0
	dw	ARM_instruction_crc32w-instruction_handler
	db	'crc32x',0xf0
	dw	ARM_instruction_crc32x-instruction_handler
	db	'dvf~~d',0x00
	dw	ARM_instruction_dvfd-instruction_handler
	db	'dvf~~e',0x00
	dw	ARM_instruction_dvfe-instruction_handler
	db	'dvf~~s',0x00
	dw	ARM_instruction_dvfs-instruction_handler
	db	'enterx',0xf0
	dw	ARM_instruction_enterx-instruction_handler
	db	'eors.n',0xe5
	dw	ARM_instruction_eor-instruction_handler
	db	'eors.w',0xe3
	dw	ARM_instruction_eor-instruction_handler
	db	'eors~~',0x01
	dw	ARM_instruction_eor-instruction_handler
	db	'eor~~s',0x01
	dw	ARM_instruction_eor-instruction_handler
	db	'eret~~',0x00
	dw	ARM_instruction_eret-instruction_handler
	db	'exp~~d',0x00
	dw	ARM_instruction_expd-instruction_handler
	db	'exp~~e',0x00
	dw	ARM_instruction_expe-instruction_handler
	db	'exp~~s',0x00
	dw	ARM_instruction_exps-instruction_handler
	db	'fccmpe',0xf0
	dw	ARM_instruction_fccmpe-instruction_handler
	db	'fcmped',0xe0
	dw	ARM_instruction_fcmped-instruction_handler
	db	'fcmpes',0xe0
	dw	ARM_instruction_fcmpes-instruction_handler
	db	'fcmpzd',0xe0
	dw	ARM_instruction_fcmpzd-instruction_handler
	db	'fcmpzs',0xe0
	dw	ARM_instruction_fcmpzs-instruction_handler
	db	'fcvtas',0xf0
	dw	ARM_instruction_fcvtas-instruction_handler
	db	'fcvtau',0xf0
	dw	ARM_instruction_fcvtau-instruction_handler
	db	'fcvtds',0xe0
	dw	ARM_instruction_fcvtds-instruction_handler
	db	'fcvtl2',0xf0
	dw	ARM_instruction_fcvtl2-instruction_handler
	db	'fcvtms',0xf0
	dw	ARM_instruction_fcvtms-instruction_handler
	db	'fcvtmu',0xf0
	dw	ARM_instruction_fcvtmu-instruction_handler
	db	'fcvtn2',0xf0
	dw	ARM_instruction_fcvtn2-instruction_handler
	db	'fcvtns',0xf0
	dw	ARM_instruction_fcvtns-instruction_handler
	db	'fcvtnu',0xf0
	dw	ARM_instruction_fcvtnu-instruction_handler
	db	'fcvtps',0xf0
	dw	ARM_instruction_fcvtps-instruction_handler
	db	'fcvtpu',0xf0
	dw	ARM_instruction_fcvtpu-instruction_handler
	db	'fcvtsd',0xe0
	dw	ARM_instruction_fcvtsd-instruction_handler
	db	'fcvtxn',0xf0
	dw	ARM_instruction_fcvtxn-instruction_handler
	db	'fcvtzs',0xf0
	dw	ARM_instruction_fcvtzs-instruction_handler
	db	'fcvtzu',0xf0
	dw	ARM_instruction_fcvtzu-instruction_handler
	db	'fdv~~d',0x00
	dw	ARM_instruction_fdvd-instruction_handler
	db	'fdv~~e',0x00
	dw	ARM_instruction_fdve-instruction_handler
	db	'fdv~~s',0x00
	dw	ARM_instruction_fdvs-instruction_handler
	db	'fix~~m',0x00
	dw	ARM_instruction_fixm-instruction_handler
	db	'fix~~p',0x00
	dw	ARM_instruction_fixp-instruction_handler
	db	'fix~~z',0x00
	dw	ARM_instruction_fixz-instruction_handler
	db	'fldd~~',0x00
	dw	ARM_instruction_fldd-instruction_handler
	db	'flds~~',0x00
	dw	ARM_instruction_flds-instruction_handler
	db	'flt~~d',0x00
	dw	ARM_instruction_fltd-instruction_handler
	db	'flt~~e',0x00
	dw	ARM_instruction_flte-instruction_handler
	db	'flt~~s',0x00
	dw	ARM_instruction_flts-instruction_handler
	db	'fmaxnm',0xf0
	dw	ARM_instruction_fmaxnm-instruction_handler
	db	'fminnm',0xf0
	dw	ARM_instruction_fminnm-instruction_handler
	db	'fml~~d',0x00
	dw	ARM_instruction_fmld-instruction_handler
	db	'fml~~e',0x00
	dw	ARM_instruction_fmle-instruction_handler
	db	'fml~~s',0x00
	dw	ARM_instruction_fmls-instruction_handler
	db	'fmrs~~',0x00
	dw	ARM_instruction_fmrs-instruction_handler
	db	'fmrx~~',0x00
	dw	ARM_instruction_fmrx-instruction_handler
	db	'fmsr~~',0x00
	dw	ARM_instruction_fmsr-instruction_handler
	db	'fmstat',0xe0
	dw	ARM_instruction_fmstat-instruction_handler
	db	'fmxr~~',0x00
	dw	ARM_instruction_fmxr-instruction_handler
	db	'fnmacd',0xe0
	dw	ARM_instruction_fnmacd-instruction_handler
	db	'fnmacs',0xe0
	dw	ARM_instruction_fnmacs-instruction_handler
	db	'fnmadd',0xf0
	dw	ARM_instruction_fnmadd-instruction_handler
	db	'fnmscd',0xe0
	dw	ARM_instruction_fnmscd-instruction_handler
	db	'fnmscs',0xe0
	dw	ARM_instruction_fnmscs-instruction_handler
	db	'fnmsub',0xf0
	dw	ARM_instruction_fnmsub-instruction_handler
	db	'fnmuld',0xe0
	dw	ARM_instruction_fnmuld-instruction_handler
	db	'fnmuls',0xe0
	dw	ARM_instruction_fnmuls-instruction_handler
	db	'format',0x00
	dw	ARM_format_directive-instruction_handler
	db	'frd~~d',0x00
	dw	ARM_instruction_frdd-instruction_handler
	db	'frd~~e',0x00
	dw	ARM_instruction_frde-instruction_handler
	db	'frd~~s',0x00
	dw	ARM_instruction_frds-instruction_handler
	db	'frecpe',0xf0
	dw	ARM_instruction_frecpe-instruction_handler
	db	'frecps',0xf0
	dw	ARM_instruction_frecps-instruction_handler
	db	'frecpx',0xf0
	dw	ARM_instruction_frecpx-instruction_handler
	db	'frinta',0xf0
	dw	ARM_instruction_frinta-instruction_handler
	db	'frinti',0xf0
	dw	ARM_instruction_frinti-instruction_handler
	db	'frintm',0xf0
	dw	ARM_instruction_frintm-instruction_handler
	db	'frintn',0xf0
	dw	ARM_instruction_frintn-instruction_handler
	db	'frintp',0xf0
	dw	ARM_instruction_frintp-instruction_handler
	db	'frintx',0xf0
	dw	ARM_instruction_frintx-instruction_handler
	db	'frintz',0xf0
	dw	ARM_instruction_frintz-instruction_handler
	db	'fshtod',0xe0
	dw	ARM_instruction_fshtod-instruction_handler
	db	'fshtos',0xe0
	dw	ARM_instruction_fshtos-instruction_handler
	db	'fsitod',0xe0
	dw	ARM_instruction_fsitod-instruction_handler
	db	'fsitos',0xe0
	dw	ARM_instruction_fsitos-instruction_handler
	db	'fsltod',0xe0
	dw	ARM_instruction_fsltod-instruction_handler
	db	'fsltos',0xe0
	dw	ARM_instruction_fsltos-instruction_handler
	db	'fsqrtd',0xe0
	dw	ARM_instruction_fsqrtd-instruction_handler
	db	'fsqrts',0xe0
	dw	ARM_instruction_fsqrts-instruction_handler
	db	'fstd~~',0x00
	dw	ARM_instruction_fstd-instruction_handler
	db	'fsts~~',0x00
	dw	ARM_instruction_fsts-instruction_handler
	db	'ftoshd',0xe0
	dw	ARM_instruction_ftoshd-instruction_handler
	db	'ftoshs',0xe0
	dw	ARM_instruction_ftoshs-instruction_handler
	db	'ftosid',0xe0
	dw	ARM_instruction_ftosid-instruction_handler
	db	'ftosis',0xe0
	dw	ARM_instruction_ftosis-instruction_handler
	db	'ftosld',0xe0
	dw	ARM_instruction_ftosld-instruction_handler
	db	'ftosls',0xe0
	dw	ARM_instruction_ftosls-instruction_handler
	db	'ftouhd',0xe0
	dw	ARM_instruction_ftouhd-instruction_handler
	db	'ftouhs',0xe0
	dw	ARM_instruction_ftouhs-instruction_handler
	db	'ftouid',0xe0
	dw	ARM_instruction_ftouid-instruction_handler
	db	'ftouis',0xe0
	dw	ARM_instruction_ftouis-instruction_handler
	db	'ftould',0xe0
	dw	ARM_instruction_ftould-instruction_handler
	db	'ftouls',0xe0
	dw	ARM_instruction_ftouls-instruction_handler
	db	'fuhtod',0xe0
	dw	ARM_instruction_fuhtod-instruction_handler
	db	'fuhtos',0xe0
	dw	ARM_instruction_fuhtos-instruction_handler
	db	'fuitod',0xe0
	dw	ARM_instruction_fuitod-instruction_handler
	db	'fuitos',0xe0
	dw	ARM_instruction_fuitos-instruction_handler
	db	'fultod',0xe0
	dw	ARM_instruction_fultod-instruction_handler
	db	'fultos',0xe0
	dw	ARM_instruction_fultos-instruction_handler
	db	'hblp~~',0x00
	dw	ARM_instruction_hblp-instruction_handler
	db	'ldab~~',0x00
	dw	ARM_instruction_ldab-instruction_handler
	db	'ldaexb',0xe0
	dw	ARM_instruction_ldaexb-instruction_handler
	db	'ldaexd',0xe0
	dw	ARM_instruction_ldaexd-instruction_handler
	db	'ldaexh',0xe0
	dw	ARM_instruction_ldaexh-instruction_handler
	db	'ldah~~',0x00
	dw	ARM_instruction_ldah-instruction_handler
	db	'ldaxrb',0xf0
	dw	ARM_instruction_ldaxrb-instruction_handler
	db	'ldaxrh',0xf0
	dw	ARM_instruction_ldaxrh-instruction_handler
	db	'lda~~b',0x00
	dw	ARM_instruction_ldab-instruction_handler
	db	'lda~~h',0x00
	dw	ARM_instruction_ldah-instruction_handler
	db	'ldc2~~',0x00
	dw	ARM_instruction_ldc2-instruction_handler
	db	'ldcl~~',0x00
	dw	ARM_instruction_ldcl-instruction_handler
	db	'ldc~~l',0x00
	dw	ARM_instruction_ldcl-instruction_handler
	db	'ldf~~d',0x00
	dw	ARM_instruction_ldfd-instruction_handler
	db	'ldf~~e',0x00
	dw	ARM_instruction_ldfe-instruction_handler
	db	'ldf~~p',0x00
	dw	ARM_instruction_ldfp-instruction_handler
	db	'ldf~~s',0x00
	dw	ARM_instruction_ldfs-instruction_handler
	db	'ldrb.n',0xe4
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldrb.w',0xe2
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldrb~~',0x00
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldrd~~',0x00
	dw	ARM_instruction_ldrd-instruction_handler
	db	'ldrexb',0xe0
	dw	ARM_instruction_ldrexb-instruction_handler
	db	'ldrexd',0xe0
	dw	ARM_instruction_ldrexd-instruction_handler
	db	'ldrexh',0xe0
	dw	ARM_instruction_ldrexh-instruction_handler
	db	'ldrh.n',0xe4
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldrh.w',0xe2
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldrh~~',0x00
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldrsbt',0xe0
	dw	ARM_instruction_ldrsbt-instruction_handler
	db	'ldrsht',0xe0
	dw	ARM_instruction_ldrsht-instruction_handler
	db	'ldrt~~',0x00
	dw	ARM_instruction_ldrt-instruction_handler
	db	'ldr~~b',0x00
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldr~~d',0x00
	dw	ARM_instruction_ldrd-instruction_handler
	db	'ldr~~h',0x00
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldr~~t',0x00
	dw	ARM_instruction_ldrt-instruction_handler
	db	'ldtrsb',0xf0
	dw	ARM_instruction_ldtrsb-instruction_handler
	db	'ldtrsh',0xf0
	dw	ARM_instruction_ldtrsh-instruction_handler
	db	'ldtrsw',0xf0
	dw	ARM_instruction_ldtrsw-instruction_handler
	db	'ldursb',0xf0
	dw	ARM_instruction_ldursb-instruction_handler
	db	'ldursh',0xf0
	dw	ARM_instruction_ldursh-instruction_handler
	db	'ldursw',0xf0
	dw	ARM_instruction_ldursw-instruction_handler
	db	'leavex',0xf0
	dw	ARM_instruction_leavex-instruction_handler
	db	'lgn~~d',0x00
	dw	ARM_instruction_lgnd-instruction_handler
	db	'lgn~~e',0x00
	dw	ARM_instruction_lgne-instruction_handler
	db	'lgn~~s',0x00
	dw	ARM_instruction_lgns-instruction_handler
	db	'log~~d',0x00
	dw	ARM_instruction_logd-instruction_handler
	db	'log~~e',0x00
	dw	ARM_instruction_loge-instruction_handler
	db	'log~~s',0x00
	dw	ARM_instruction_logs-instruction_handler
	db	'lsls.n',0xe5
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsls.w',0xe3
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsls~~',0x01
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsl~~s',0x01
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsrs.n',0xe5
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsrs.w',0xe3
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsrs~~',0x01
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsr~~s',0x01
	dw	ARM_instruction_lsr-instruction_handler
	db	'mcr2~~',0x00
	dw	ARM_instruction_mcr2-instruction_handler
	db	'mcrr~~',0x00
	dw	ARM_instruction_mcrr-instruction_handler
	db	'mlas~~',0x01
	dw	ARM_instruction_mla-instruction_handler
	db	'mla~~s',0x01
	dw	ARM_instruction_mla-instruction_handler
	db	'mnf~~d',0x00
	dw	ARM_instruction_mnfd-instruction_handler
	db	'mnf~~e',0x00
	dw	ARM_instruction_mnfe-instruction_handler
	db	'mnf~~s',0x00
	dw	ARM_instruction_mnfs-instruction_handler
	db	'movs.n',0xe5
	dw	ARM_instruction_mov-instruction_handler
	db	'movs.w',0xe3
	dw	ARM_instruction_mov-instruction_handler
	db	'movs~~',0x01
	dw	ARM_instruction_mov-instruction_handler
	db	'movt~~',0x00
	dw	ARM_instruction_movt-instruction_handler
	db	'movw~~',0x00
	dw	ARM_instruction_movw-instruction_handler
	db	'mov~~s',0x01
	dw	ARM_instruction_mov-instruction_handler
	db	'mrc2~~',0x00
	dw	ARM_instruction_mrc2-instruction_handler
	db	'mrrc~~',0x00
	dw	ARM_instruction_mrrc-instruction_handler
	db	'muf~~d',0x00
	dw	ARM_instruction_mufd-instruction_handler
	db	'muf~~e',0x00
	dw	ARM_instruction_mufe-instruction_handler
	db	'muf~~s',0x00
	dw	ARM_instruction_mufs-instruction_handler
	db	'muls.n',0xe5
	dw	ARM_instruction_mul-instruction_handler
	db	'muls.w',0xe3
	dw	ARM_instruction_mul-instruction_handler
	db	'muls~~',0x01
	dw	ARM_instruction_mul-instruction_handler
	db	'mul~~s',0x01
	dw	ARM_instruction_mul-instruction_handler
	db	'mvf~~d',0x00
	dw	ARM_instruction_mvfd-instruction_handler
	db	'mvf~~e',0x00
	dw	ARM_instruction_mvfe-instruction_handler
	db	'mvf~~s',0x00
	dw	ARM_instruction_mvfs-instruction_handler
	db	'mvns.n',0xe5
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvns.w',0xe3
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvns~~',0x01
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvn~~s',0x01
	dw	ARM_instruction_mvn-instruction_handler
	db	'negs.n',0xe5
	dw	ARM_instruction_neg-instruction_handler
	db	'negs.w',0xe3
	dw	ARM_instruction_neg-instruction_handler
	db	'negs~~',0x01
	dw	ARM_instruction_neg-instruction_handler
	db	'neg~~s',0x01
	dw	ARM_instruction_neg-instruction_handler
	db	'nrm~~d',0x00
	dw	ARM_instruction_nrmd-instruction_handler
	db	'nrm~~e',0x00
	dw	ARM_instruction_nrme-instruction_handler
	db	'nrm~~s',0x00
	dw	ARM_instruction_nrms-instruction_handler
	db	'orns~~',0x01
	dw	ARM_instruction_orn-instruction_handler
	db	'orn~~s',0x01
	dw	ARM_instruction_orn-instruction_handler
	db	'orrs.n',0xe5
	dw	ARM_instruction_orr-instruction_handler
	db	'orrs.w',0xe3
	dw	ARM_instruction_orr-instruction_handler
	db	'orrs~~',0x01
	dw	ARM_instruction_orr-instruction_handler
	db	'orr~~s',0x01
	dw	ARM_instruction_orr-instruction_handler
	db	'pldw~~',0x00
	dw	ARM_instruction_pldw-instruction_handler
	db	'pmull2',0xf0
	dw	ARM_instruction_pmull2-instruction_handler
	db	'pol~~d',0x00
	dw	ARM_instruction_pold-instruction_handler
	db	'pol~~e',0x00
	dw	ARM_instruction_pole-instruction_handler
	db	'pol~~s',0x00
	dw	ARM_instruction_pols-instruction_handler
	db	'pow~~d',0x00
	dw	ARM_instruction_powd-instruction_handler
	db	'pow~~e',0x00
	dw	ARM_instruction_powe-instruction_handler
	db	'pow~~s',0x00
	dw	ARM_instruction_pows-instruction_handler
	db	'public',0x00
	dw	public_directive-instruction_handler
	db	'push.n',0xe4
	dw	ARM_instruction_push-instruction_handler
	db	'push.w',0xe2
	dw	ARM_instruction_push-instruction_handler
	db	'push~~',0x00
	dw	ARM_instruction_push-instruction_handler
	db	'qadd16',0xe0
	dw	ARM_instruction_qadd16-instruction_handler
	db	'qadd~~',0x00
	dw	ARM_instruction_qadd-instruction_handler
	db	'qasx~~',0x00
	dw	ARM_instruction_qasx-instruction_handler
	db	'qsax~~',0x00
	dw	ARM_instruction_qsax-instruction_handler
	db	'qsub16',0xe0
	dw	ARM_instruction_qsub16-instruction_handler
	db	'qsub~~',0x00
	dw	ARM_instruction_qsub-instruction_handler
	db	'raddhn',0xf0
	dw	ARM_instruction_raddhn-instruction_handler
	db	'rbit~~',0x00
	dw	ARM_instruction_rbit-instruction_handler
	db	'rdf~~d',0x00
	dw	ARM_instruction_rdfd-instruction_handler
	db	'rdf~~e',0x00
	dw	ARM_instruction_rdfe-instruction_handler
	db	'rdf~~s',0x00
	dw	ARM_instruction_rdfs-instruction_handler
	db	'repeat',0x00
	dw	repeat_directive-instruction_handler
	db	'rmf~~d',0x00
	dw	ARM_instruction_rmfd-instruction_handler
	db	'rmf~~e',0x00
	dw	ARM_instruction_rmfe-instruction_handler
	db	'rmf~~s',0x00
	dw	ARM_instruction_rmfs-instruction_handler
	db	'rnd~~d',0x00
	dw	ARM_instruction_rndd-instruction_handler
	db	'rnd~~e',0x00
	dw	ARM_instruction_rnde-instruction_handler
	db	'rnd~~s',0x00
	dw	ARM_instruction_rnds-instruction_handler
	db	'rors.n',0xe5
	dw	ARM_instruction_ror-instruction_handler
	db	'rors.w',0xe3
	dw	ARM_instruction_ror-instruction_handler
	db	'rors~~',0x01
	dw	ARM_instruction_ror-instruction_handler
	db	'ror~~s',0x01
	dw	ARM_instruction_ror-instruction_handler
	db	'rpw~~d',0x00
	dw	ARM_instruction_rpwd-instruction_handler
	db	'rpw~~e',0x00
	dw	ARM_instruction_rpwe-instruction_handler
	db	'rpw~~s',0x00
	dw	ARM_instruction_rpws-instruction_handler
	db	'rrxs~~',0x01
	dw	ARM_instruction_rrx-instruction_handler
	db	'rrx~~s',0x01
	dw	ARM_instruction_rrx-instruction_handler
	db	'rsbs.n',0xe5
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsbs.w',0xe3
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsbs~~',0x01
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsb~~s',0x01
	dw	ARM_instruction_rsb-instruction_handler
	db	'rscs~~',0x01
	dw	ARM_instruction_rsc-instruction_handler
	db	'rsc~~s',0x01
	dw	ARM_instruction_rsc-instruction_handler
	db	'rsf~~d',0x00
	dw	ARM_instruction_rsfd-instruction_handler
	db	'rsf~~e',0x00
	dw	ARM_instruction_rsfe-instruction_handler
	db	'rsf~~s',0x00
	dw	ARM_instruction_rsfs-instruction_handler
	db	'rshrn2',0xf0
	dw	ARM_instruction_rshrn2-instruction_handler
	db	'rsubhn',0xf0
	dw	ARM_instruction_rsubhn-instruction_handler
	db	'sabal2',0xf0
	dw	ARM_instruction_sabal2-instruction_handler
	db	'sabdl2',0xf0
	dw	ARM_instruction_sabdl2-instruction_handler
	db	'sadalp',0xf0
	dw	ARM_instruction_sadalp-instruction_handler
	db	'sadd16',0xe0
	dw	ARM_instruction_sadd16-instruction_handler
	db	'saddl2',0xf0
	dw	ARM_instruction_saddl2-instruction_handler
	db	'saddlp',0xf0
	dw	ARM_instruction_saddlp-instruction_handler
	db	'saddlv',0xf0
	dw	ARM_instruction_saddlv-instruction_handler
	db	'saddw2',0xf0
	dw	ARM_instruction_saddw2-instruction_handler
	db	'sasx~~',0x00
	dw	ARM_instruction_sasx-instruction_handler
	db	'sbcs.n',0xe5
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbcs.w',0xe3
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbcs~~',0x01
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbc~~s',0x01
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbfx~~',0x00
	dw	ARM_instruction_sbfx-instruction_handler
	db	'sdiv~~',0x00
	dw	ARM_instruction_sdiv-instruction_handler
	db	'setend',0xf0
	dw	ARM_instruction_setend-instruction_handler
	db	'sevl.n',0xe4
	dw	ARM_instruction_sevl-instruction_handler
	db	'sevl.w',0xe2
	dw	ARM_instruction_sevl-instruction_handler
	db	'sevl~~',0x00
	dw	ARM_instruction_sevl-instruction_handler
	db	'shadd8',0xe0
	dw	ARM_instruction_shadd8-instruction_handler
	db	'shsub8',0xe0
	dw	ARM_instruction_shsub8-instruction_handler
	db	'sin~~d',0x00
	dw	ARM_instruction_sind-instruction_handler
	db	'sin~~e',0x00
	dw	ARM_instruction_sine-instruction_handler
	db	'sin~~s',0x00
	dw	ARM_instruction_sins-instruction_handler
	db	'smaddl',0xf0
	dw	ARM_instruction_smaddl-instruction_handler
	db	'smlabb',0xe0
	dw	ARM_instruction_smlabb-instruction_handler
	db	'smlabt',0xe0
	dw	ARM_instruction_smlabt-instruction_handler
	db	'smladx',0xe0
	dw	ARM_instruction_smladx-instruction_handler
	db	'smlal2',0xf0
	dw	ARM_instruction_smlal2-instruction_handler
	db	'smlald',0xe0
	dw	ARM_instruction_smlald-instruction_handler
	db	'smlals',0xe1
	dw	ARM_instruction_smlal-instruction_handler
	db	'smlatb',0xe0
	dw	ARM_instruction_smlatb-instruction_handler
	db	'smlatt',0xe0
	dw	ARM_instruction_smlatt-instruction_handler
	db	'smlawb',0xe0
	dw	ARM_instruction_smlawb-instruction_handler
	db	'smlawt',0xe0
	dw	ARM_instruction_smlawt-instruction_handler
	db	'smlsdx',0xe0
	dw	ARM_instruction_smlsdx-instruction_handler
	db	'smlsl2',0xf0
	dw	ARM_instruction_smlsl2-instruction_handler
	db	'smlsld',0xe0
	dw	ARM_instruction_smlsld-instruction_handler
	db	'smmlar',0xe0
	dw	ARM_instruction_smmlar-instruction_handler
	db	'smmlsr',0xe0
	dw	ARM_instruction_smmlsr-instruction_handler
	db	'smmulr',0xe0
	dw	ARM_instruction_smmulr-instruction_handler
	db	'smnegl',0xf0
	dw	ARM_instruction_smnegl-instruction_handler
	db	'smsubl',0xf0
	dw	ARM_instruction_smsubl-instruction_handler
	db	'smuadx',0xe0
	dw	ARM_instruction_smuadx-instruction_handler
	db	'smulbb',0xe0
	dw	ARM_instruction_smulbb-instruction_handler
	db	'smulbt',0xe0
	dw	ARM_instruction_smulbt-instruction_handler
	db	'smull2',0xf0
	dw	ARM_instruction_smull2-instruction_handler
	db	'smulls',0xe1
	dw	ARM_instruction_smull-instruction_handler
	db	'smultb',0xe0
	dw	ARM_instruction_smultb-instruction_handler
	db	'smultt',0xe0
	dw	ARM_instruction_smultt-instruction_handler
	db	'smulwb',0xe0
	dw	ARM_instruction_smulwb-instruction_handler
	db	'smulwt',0xe0
	dw	ARM_instruction_smulwt-instruction_handler
	db	'smusdx',0xe0
	dw	ARM_instruction_smusdx-instruction_handler
	db	'sqrshl',0xf0
	dw	ARM_instruction_sqrshl-instruction_handler
	db	'sqshlu',0xf0
	dw	ARM_instruction_sqshlu-instruction_handler
	db	'sqshrn',0xf0
	dw	ARM_instruction_sqshrn-instruction_handler
	db	'sqt~~d',0x00
	dw	ARM_instruction_sqtd-instruction_handler
	db	'sqt~~e',0x00
	dw	ARM_instruction_sqte-instruction_handler
	db	'sqt~~s',0x00
	dw	ARM_instruction_sqts-instruction_handler
	db	'sqxtn2',0xf0
	dw	ARM_instruction_sqxtn2-instruction_handler
	db	'sqxtun',0xf0
	dw	ARM_instruction_sqxtun-instruction_handler
	db	'srhadd',0xf0
	dw	ARM_instruction_srhadd-instruction_handler
	db	'ssat16',0xe0
	dw	ARM_instruction_ssat16-instruction_handler
	db	'ssat~~',0x00
	dw	ARM_instruction_ssat-instruction_handler
	db	'ssax~~',0x00
	dw	ARM_instruction_ssax-instruction_handler
	db	'sshll2',0xf0
	dw	ARM_instruction_sshll2-instruction_handler
	db	'ssub16',0xe0
	dw	ARM_instruction_ssub16-instruction_handler
	db	'ssubl2',0xf0
	dw	ARM_instruction_ssubl2-instruction_handler
	db	'ssubw2',0xf0
	dw	ARM_instruction_ssubw2-instruction_handler
	db	'stc2~~',0x00
	dw	ARM_instruction_stc2-instruction_handler
	db	'stcl~~',0x00
	dw	ARM_instruction_stcl-instruction_handler
	db	'stc~~l',0x00
	dw	ARM_instruction_stcl-instruction_handler
	db	'stf~~d',0x00
	dw	ARM_instruction_stfd-instruction_handler
	db	'stf~~e',0x00
	dw	ARM_instruction_stfe-instruction_handler
	db	'stf~~p',0x00
	dw	ARM_instruction_stfp-instruction_handler
	db	'stf~~s',0x00
	dw	ARM_instruction_stfs-instruction_handler
	db	'stlb~~',0x00
	dw	ARM_instruction_stlb-instruction_handler
	db	'stlexb',0xe0
	dw	ARM_instruction_stlexb-instruction_handler
	db	'stlexd',0xe0
	dw	ARM_instruction_stlexd-instruction_handler
	db	'stlexh',0xe0
	dw	ARM_instruction_stlexh-instruction_handler
	db	'stlh~~',0x00
	dw	ARM_instruction_stlh-instruction_handler
	db	'stlxrb',0xf0
	dw	ARM_instruction_stlxrb-instruction_handler
	db	'stlxrh',0xf0
	dw	ARM_instruction_stlxrh-instruction_handler
	db	'stl~~b',0x00
	dw	ARM_instruction_stlb-instruction_handler
	db	'stl~~h',0x00
	dw	ARM_instruction_stlh-instruction_handler
	db	'strb.n',0xe4
	dw	ARM_instruction_strb-instruction_handler
	db	'strb.w',0xe2
	dw	ARM_instruction_strb-instruction_handler
	db	'strb~~',0x00
	dw	ARM_instruction_strb-instruction_handler
	db	'strd~~',0x00
	dw	ARM_instruction_strd-instruction_handler
	db	'strexb',0xe0
	dw	ARM_instruction_strexb-instruction_handler
	db	'strexd',0xe0
	dw	ARM_instruction_strexd-instruction_handler
	db	'strexh',0xe0
	dw	ARM_instruction_strexh-instruction_handler
	db	'strh.n',0xe4
	dw	ARM_instruction_strh-instruction_handler
	db	'strh.w',0xe2
	dw	ARM_instruction_strh-instruction_handler
	db	'strh~~',0x00
	dw	ARM_instruction_strh-instruction_handler
	db	'strt~~',0x00
	dw	ARM_instruction_strt-instruction_handler
	db	'str~~b',0x00
	dw	ARM_instruction_strb-instruction_handler
	db	'str~~d',0x00
	dw	ARM_instruction_strd-instruction_handler
	db	'str~~h',0x00
	dw	ARM_instruction_strh-instruction_handler
	db	'str~~t',0x00
	dw	ARM_instruction_strt-instruction_handler
	db	'subhn2',0xf0
	dw	ARM_instruction_subhn2-instruction_handler
	db	'subs.n',0xe5
	dw	ARM_instruction_sub-instruction_handler
	db	'subs.w',0xe3
	dw	ARM_instruction_sub-instruction_handler
	db	'subs~~',0x01
	dw	ARM_instruction_sub-instruction_handler
	db	'subw~~',0x00
	dw	ARM_instruction_subw-instruction_handler
	db	'sub~~s',0x01
	dw	ARM_instruction_sub-instruction_handler
	db	'suf~~d',0x00
	dw	ARM_instruction_sufd-instruction_handler
	db	'suf~~e',0x00
	dw	ARM_instruction_sufe-instruction_handler
	db	'suf~~s',0x00
	dw	ARM_instruction_sufs-instruction_handler
	db	'suqadd',0xf0
	dw	ARM_instruction_suqadd-instruction_handler
	db	'swpb~~',0x00
	dw	ARM_instruction_swpb-instruction_handler
	db	'swp~~b',0x00
	dw	ARM_instruction_swpb-instruction_handler
	db	'sxtb.n',0xe4
	dw	ARM_instruction_sxtb-instruction_handler
	db	'sxtb.w',0xe2
	dw	ARM_instruction_sxtb-instruction_handler
	db	'sxtb16',0xe0
	dw	ARM_instruction_sxtb16-instruction_handler
	db	'sxtb~~',0x00
	dw	ARM_instruction_sxtb-instruction_handler
	db	'sxth.n',0xe4
	dw	ARM_instruction_sxth-instruction_handler
	db	'sxth.w',0xe2
	dw	ARM_instruction_sxth-instruction_handler
	db	'sxth~~',0x00
	dw	ARM_instruction_sxth-instruction_handler
	db	'tandcb',0xe0
	dw	ARM_instruction_tandcb-instruction_handler
	db	'tandch',0xe0
	dw	ARM_instruction_tandch-instruction_handler
	db	'tandcw',0xe0
	dw	ARM_instruction_tandcw-instruction_handler
	db	'tan~~d',0x00
	dw	ARM_instruction_tand-instruction_handler
	db	'tan~~e',0x00
	dw	ARM_instruction_tane-instruction_handler
	db	'tan~~s',0x00
	dw	ARM_instruction_tans-instruction_handler
	db	'tbcstb',0xe0
	dw	ARM_instruction_tbcstb-instruction_handler
	db	'tbcsth',0xe0
	dw	ARM_instruction_tbcsth-instruction_handler
	db	'tbcstw',0xe0
	dw	ARM_instruction_tbcstw-instruction_handler
	db	'teqp~~',0x00
	dw	ARM_instruction_teqp-instruction_handler
	db	'teq~~p',0x00
	dw	ARM_instruction_teqp-instruction_handler
	db	'tinsrb',0xe0
	dw	ARM_instruction_tinsrb-instruction_handler
	db	'tinsrh',0xe0
	dw	ARM_instruction_tinsrh-instruction_handler
	db	'tinsrw',0xe0
	dw	ARM_instruction_tinsrw-instruction_handler
	db	'tmcr~~',0x00
	dw	ARM_instruction_tmcr-instruction_handler
	db	'tmiabb',0xe0
	dw	ARM_instruction_tmiabb-instruction_handler
	db	'tmiabt',0xe0
	dw	ARM_instruction_tmiabt-instruction_handler
	db	'tmiaph',0xe0
	dw	ARM_instruction_tmiaph-instruction_handler
	db	'tmiatb',0xe0
	dw	ARM_instruction_tmiatb-instruction_handler
	db	'tmiatt',0xe0
	dw	ARM_instruction_tmiatt-instruction_handler
	db	'tmia~~',0x00
	dw	ARM_instruction_tmia-instruction_handler
	db	'tmrc~~',0x00
	dw	ARM_instruction_tmrc-instruction_handler
	db	'tstp~~',0x00
	dw	ARM_instruction_tstp-instruction_handler
	db	'tst~~p',0x00
	dw	ARM_instruction_tstp-instruction_handler
	db	'uabal2',0xf0
	dw	ARM_instruction_uabal2-instruction_handler
	db	'uabdl2',0xf0
	dw	ARM_instruction_uabdl2-instruction_handler
	db	'uadalp',0xf0
	dw	ARM_instruction_uadalp-instruction_handler
	db	'uadd16',0xe0
	dw	ARM_instruction_uadd16-instruction_handler
	db	'uaddl2',0xf0
	dw	ARM_instruction_uaddl2-instruction_handler
	db	'uaddlp',0xf0
	dw	ARM_instruction_uaddlp-instruction_handler
	db	'uaddlv',0xf0
	dw	ARM_instruction_uaddlv-instruction_handler
	db	'uaddw2',0xf0
	dw	ARM_instruction_uaddw2-instruction_handler
	db	'uasx~~',0x00
	dw	ARM_instruction_uasx-instruction_handler
	db	'ubfx~~',0x00
	dw	ARM_instruction_ubfx-instruction_handler
	db	'udiv~~',0x00
	dw	ARM_instruction_udiv-instruction_handler
	db	'uhadd8',0xe0
	dw	ARM_instruction_uhadd8-instruction_handler
	db	'uhsub8',0xe0
	dw	ARM_instruction_uhsub8-instruction_handler
	db	'umaddl',0xf0
	dw	ARM_instruction_umaddl-instruction_handler
	db	'umlal2',0xf0
	dw	ARM_instruction_umlal2-instruction_handler
	db	'umlals',0xe1
	dw	ARM_instruction_umlal-instruction_handler
	db	'umlsl2',0xf0
	dw	ARM_instruction_umlsl2-instruction_handler
	db	'umnegl',0xf0
	dw	ARM_instruction_umnegl-instruction_handler
	db	'umsubl',0xf0
	dw	ARM_instruction_umsubl-instruction_handler
	db	'umull2',0xf0
	dw	ARM_instruction_umull2-instruction_handler
	db	'umulls',0xe1
	dw	ARM_instruction_umull-instruction_handler
	db	'uqadd8',0xe0
	dw	ARM_instruction_uqadd8-instruction_handler
	db	'uqrshl',0xf0
	dw	ARM_instruction_uqrshl-instruction_handler
	db	'uqshrn',0xf0
	dw	ARM_instruction_uqshrn-instruction_handler
	db	'uqsub8',0xe0
	dw	ARM_instruction_uqsub8-instruction_handler
	db	'uqxtn2',0xf0
	dw	ARM_instruction_uqxtn2-instruction_handler
	db	'urd~~d',0x00
	dw	ARM_instruction_urdd-instruction_handler
	db	'urd~~e',0x00
	dw	ARM_instruction_urde-instruction_handler
	db	'urd~~s',0x00
	dw	ARM_instruction_urds-instruction_handler
	db	'urecpe',0xf0
	dw	ARM_instruction_urecpe-instruction_handler
	db	'urhadd',0xf0
	dw	ARM_instruction_urhadd-instruction_handler
	db	'usada8',0xe0
	dw	ARM_instruction_usada8-instruction_handler
	db	'usat16',0xe0
	dw	ARM_instruction_usat16-instruction_handler
	db	'usat~~',0x00
	dw	ARM_instruction_usat-instruction_handler
	db	'usax~~',0x00
	dw	ARM_instruction_usax-instruction_handler
	db	'ushll2',0xf0
	dw	ARM_instruction_ushll2-instruction_handler
	db	'usqadd',0xf0
	dw	ARM_instruction_usqadd-instruction_handler
	db	'usub16',0xe0
	dw	ARM_instruction_usub16-instruction_handler
	db	'usubl2',0xf0
	dw	ARM_instruction_usubl2-instruction_handler
	db	'usubw2',0xf0
	dw	ARM_instruction_usubw2-instruction_handler
	db	'uxtb.n',0xe4
	dw	ARM_instruction_uxtb-instruction_handler
	db	'uxtb.w',0xe2
	dw	ARM_instruction_uxtb-instruction_handler
	db	'uxtb16',0xe0
	dw	ARM_instruction_uxtb16-instruction_handler
	db	'uxtb~~',0x00
	dw	ARM_instruction_uxtb-instruction_handler
	db	'uxth.n',0xe4
	dw	ARM_instruction_uxth-instruction_handler
	db	'uxth.w',0xe2
	dw	ARM_instruction_uxth-instruction_handler
	db	'uxth~~',0x00
	dw	ARM_instruction_uxth-instruction_handler
	db	'vand~~',0x00
	dw	ARM_instruction_vand-instruction_handler
	db	'vbic~~',0x00
	dw	ARM_instruction_vbic-instruction_handler
	db	'vbif~~',0x00
	dw	ARM_instruction_vbif-instruction_handler
	db	'vbit~~',0x00
	dw	ARM_instruction_vbit-instruction_handler
	db	'vbsl~~',0x00
	dw	ARM_instruction_vbsl-instruction_handler
	db	'vcnt.8',0xe0
	dw	ARM_instruction_vcnt.8-instruction_handler
	db	'vdup.8',0xe0
	dw	ARM_instruction_vdup.8-instruction_handler
	db	'veor~~',0x00
	dw	ARM_instruction_veor-instruction_handler
	db	'vext.8',0xe0
	dw	ARM_instruction_vext.8-instruction_handler
	db	'vld1.8',0xe0
	dw	ARM_instruction_vld1.8-instruction_handler
	db	'vld2.8',0xe0
	dw	ARM_instruction_vld2.8-instruction_handler
	db	'vld3.8',0xe0
	dw	ARM_instruction_vld3.8-instruction_handler
	db	'vld4.8',0xe0
	dw	ARM_instruction_vld4.8-instruction_handler
	db	'vldmdb',0xe0
	dw	ARM_instruction_vldmdb-instruction_handler
	db	'vldmea',0xe0
	dw	ARM_instruction_vldmea-instruction_handler
	db	'vldmfd',0xe0
	dw	ARM_instruction_vldmfd-instruction_handler
	db	'vldmia',0xe0
	dw	ARM_instruction_vldmia-instruction_handler
	db	'vldm~~',0x00
	dw	ARM_instruction_vldm-instruction_handler
	db	'vldr~~',0x00
	dw	ARM_instruction_vldr-instruction_handler
	db	'vmov.8',0xe0
	dw	ARM_instruction_vmov.8-instruction_handler
	db	'vmov~~',0x00
	dw	ARM_instruction_vmov-instruction_handler
	db	'vmrs~~',0x00
	dw	ARM_instruction_vmrs-instruction_handler
	db	'vmsr~~',0x00
	dw	ARM_instruction_vmsr-instruction_handler
	db	'vmvn~~',0x00
	dw	ARM_instruction_vmvn-instruction_handler
	db	'vorn~~',0x00
	dw	ARM_instruction_vorn-instruction_handler
	db	'vorr~~',0x00
	dw	ARM_instruction_vorr-instruction_handler
	db	'vpop~~',0x00
	dw	ARM_instruction_vpop-instruction_handler
	db	'vsli.8',0xe0
	dw	ARM_instruction_vsli.8-instruction_handler
	db	'vsri.8',0xe0
	dw	ARM_instruction_vsri.8-instruction_handler
	db	'vst1.8',0xe0
	dw	ARM_instruction_vst1.8-instruction_handler
	db	'vst2.8',0xe0
	dw	ARM_instruction_vst2.8-instruction_handler
	db	'vst3.8',0xe0
	dw	ARM_instruction_vst3.8-instruction_handler
	db	'vst4.8',0xe0
	dw	ARM_instruction_vst4.8-instruction_handler
	db	'vstmdb',0xe0
	dw	ARM_instruction_vstmdb-instruction_handler
	db	'vstmea',0xe0
	dw	ARM_instruction_vstmea-instruction_handler
	db	'vstmfd',0xe0
	dw	ARM_instruction_vstmfd-instruction_handler
	db	'vstmia',0xe0
	dw	ARM_instruction_vstmia-instruction_handler
	db	'vstm~~',0x00
	dw	ARM_instruction_vstm-instruction_handler
	db	'vstr~~',0x00
	dw	ARM_instruction_vstr-instruction_handler
	db	'vswp~~',0x00
	dw	ARM_instruction_vswp-instruction_handler
	db	'vtbl.8',0xe0
	dw	ARM_instruction_vtbl.8-instruction_handler
	db	'vtbx.8',0xe0
	dw	ARM_instruction_vtbx.8-instruction_handler
	db	'vtrn.8',0xe0
	dw	ARM_instruction_vtrn.8-instruction_handler
	db	'vtst.8',0xe0
	dw	ARM_instruction_vtst.8-instruction_handler
	db	'vuzp.8',0xe0
	dw	ARM_instruction_vuzp.8-instruction_handler
	db	'vzip.8',0xe0
	dw	ARM_instruction_vzip.8-instruction_handler
	db	'waddhc',0xe0
	dw	ARM_instruction_waddhc-instruction_handler
	db	'waddwc',0xe0
	dw	ARM_instruction_waddwc-instruction_handler
	db	'wand~~',0x00
	dw	ARM_instruction_wand-instruction_handler
	db	'wavg2b',0xe0
	dw	ARM_instruction_wavg2b-instruction_handler
	db	'wavg2h',0xe0
	dw	ARM_instruction_wavg2h-instruction_handler
	db	'wavg4r',0xe0
	dw	ARM_instruction_wavg4r-instruction_handler
	db	'wmacsz',0xe0
	dw	ARM_instruction_wmacsz-instruction_handler
	db	'wmacuz',0xe0
	dw	ARM_instruction_wmacuz-instruction_handler
	db	'wmadds',0xe0
	dw	ARM_instruction_wmadds-instruction_handler
	db	'wmaddu',0xe0
	dw	ARM_instruction_wmaddu-instruction_handler
	db	'wmaxsb',0xe0
	dw	ARM_instruction_wmaxsb-instruction_handler
	db	'wmaxsh',0xe0
	dw	ARM_instruction_wmaxsh-instruction_handler
	db	'wmaxsw',0xe0
	dw	ARM_instruction_wmaxsw-instruction_handler
	db	'wmaxub',0xe0
	dw	ARM_instruction_wmaxub-instruction_handler
	db	'wmaxuh',0xe0
	dw	ARM_instruction_wmaxuh-instruction_handler
	db	'wmaxuw',0xe0
	dw	ARM_instruction_wmaxuw-instruction_handler
	db	'wmerge',0xe0
	dw	ARM_instruction_wmerge-instruction_handler
	db	'wmiabb',0xe0
	dw	ARM_instruction_wmiabb-instruction_handler
	db	'wmiabt',0xe0
	dw	ARM_instruction_wmiabt-instruction_handler
	db	'wmiatb',0xe0
	dw	ARM_instruction_wmiatb-instruction_handler
	db	'wmiatt',0xe0
	dw	ARM_instruction_wmiatt-instruction_handler
	db	'wminsb',0xe0
	dw	ARM_instruction_wminsb-instruction_handler
	db	'wminsh',0xe0
	dw	ARM_instruction_wminsh-instruction_handler
	db	'wminsw',0xe0
	dw	ARM_instruction_wminsw-instruction_handler
	db	'wminub',0xe0
	dw	ARM_instruction_wminub-instruction_handler
	db	'wminuh',0xe0
	dw	ARM_instruction_wminuh-instruction_handler
	db	'wminuw',0xe0
	dw	ARM_instruction_wminuw-instruction_handler
	db	'wmov~~',0x00
	dw	ARM_instruction_wmov-instruction_handler
	db	'wmulsl',0xe0
	dw	ARM_instruction_wmulsl-instruction_handler
	db	'wmulsm',0xe0
	dw	ARM_instruction_wmulsm-instruction_handler
	db	'wmulul',0xe0
	dw	ARM_instruction_wmulul-instruction_handler
	db	'wmulum',0xe0
	dw	ARM_instruction_wmulum-instruction_handler
	db	'wmulwl',0xe0
	dw	ARM_instruction_wmulwl-instruction_handler
	db	'wqmulm',0xe0
	dw	ARM_instruction_wqmulm-instruction_handler
	db	'wrordg',0xe0
	dw	ARM_instruction_wrordg-instruction_handler
	db	'wrorhg',0xe0
	dw	ARM_instruction_wrorhg-instruction_handler
	db	'wrorwg',0xe0
	dw	ARM_instruction_wrorwg-instruction_handler
	db	'wsadbz',0xe0
	dw	ARM_instruction_wsadbz-instruction_handler
	db	'wsadhz',0xe0
	dw	ARM_instruction_wsadhz-instruction_handler
	db	'wshufh',0xe0
	dw	ARM_instruction_wshufh-instruction_handler
	db	'wslldg',0xe0
	dw	ARM_instruction_wslldg-instruction_handler
	db	'wsllhg',0xe0
	dw	ARM_instruction_wsllhg-instruction_handler
	db	'wsllwg',0xe0
	dw	ARM_instruction_wsllwg-instruction_handler
	db	'wsradg',0xe0
	dw	ARM_instruction_wsradg-instruction_handler
	db	'wsrahg',0xe0
	dw	ARM_instruction_wsrahg-instruction_handler
	db	'wsrawg',0xe0
	dw	ARM_instruction_wsrawg-instruction_handler
	db	'wsrldg',0xe0
	dw	ARM_instruction_wsrldg-instruction_handler
	db	'wsrlhg',0xe0
	dw	ARM_instruction_wsrlhg-instruction_handler
	db	'wsrlwg',0xe0
	dw	ARM_instruction_wsrlwg-instruction_handler
	db	'wxor~~',0x00
	dw	ARM_instruction_wxor-instruction_handler
	db	0
instructions_7:
	db	'abs~~dm',0x00
	dw	ARM_instruction_absdm-instruction_handler
	db	'abs~~dp',0x00
	dw	ARM_instruction_absdp-instruction_handler
	db	'abs~~dz',0x00
	dw	ARM_instruction_absdz-instruction_handler
	db	'abs~~em',0x00
	dw	ARM_instruction_absem-instruction_handler
	db	'abs~~ep',0x00
	dw	ARM_instruction_absep-instruction_handler
	db	'abs~~ez',0x00
	dw	ARM_instruction_absez-instruction_handler
	db	'abs~~sm',0x00
	dw	ARM_instruction_abssm-instruction_handler
	db	'abs~~sp',0x00
	dw	ARM_instruction_abssp-instruction_handler
	db	'abs~~sz',0x00
	dw	ARM_instruction_abssz-instruction_handler
	db	'acs~~dm',0x00
	dw	ARM_instruction_acsdm-instruction_handler
	db	'acs~~dp',0x00
	dw	ARM_instruction_acsdp-instruction_handler
	db	'acs~~dz',0x00
	dw	ARM_instruction_acsdz-instruction_handler
	db	'acs~~em',0x00
	dw	ARM_instruction_acsem-instruction_handler
	db	'acs~~ep',0x00
	dw	ARM_instruction_acsep-instruction_handler
	db	'acs~~ez',0x00
	dw	ARM_instruction_acsez-instruction_handler
	db	'acs~~sm',0x00
	dw	ARM_instruction_acssm-instruction_handler
	db	'acs~~sp',0x00
	dw	ARM_instruction_acssp-instruction_handler
	db	'acs~~sz',0x00
	dw	ARM_instruction_acssz-instruction_handler
	db	'adc~~.n',0x04
	dw	ARM_instruction_adc-instruction_handler
	db	'adc~~.w',0x02
	dw	ARM_instruction_adc-instruction_handler
	db	'add~~.n',0x04
	dw	ARM_instruction_add-instruction_handler
	db	'add~~.w',0x02
	dw	ARM_instruction_add-instruction_handler
	db	'adf~~dm',0x00
	dw	ARM_instruction_adfdm-instruction_handler
	db	'adf~~dp',0x00
	dw	ARM_instruction_adfdp-instruction_handler
	db	'adf~~dz',0x00
	dw	ARM_instruction_adfdz-instruction_handler
	db	'adf~~em',0x00
	dw	ARM_instruction_adfem-instruction_handler
	db	'adf~~ep',0x00
	dw	ARM_instruction_adfep-instruction_handler
	db	'adf~~ez',0x00
	dw	ARM_instruction_adfez-instruction_handler
	db	'adf~~sm',0x00
	dw	ARM_instruction_adfsm-instruction_handler
	db	'adf~~sp',0x00
	dw	ARM_instruction_adfsp-instruction_handler
	db	'adf~~sz',0x00
	dw	ARM_instruction_adfsz-instruction_handler
	db	'adr~~.n',0x04
	dw	ARM_instruction_adr-instruction_handler
	db	'adr~~.w',0x02
	dw	ARM_instruction_adr-instruction_handler
	db	'aesmc.8',0xf0
	dw	ARM_instruction_aesmc.8-instruction_handler
	db	'and~~.n',0x04
	dw	ARM_instruction_and-instruction_handler
	db	'and~~.w',0x02
	dw	ARM_instruction_and-instruction_handler
	db	'asn~~dm',0x00
	dw	ARM_instruction_asndm-instruction_handler
	db	'asn~~dp',0x00
	dw	ARM_instruction_asndp-instruction_handler
	db	'asn~~dz',0x00
	dw	ARM_instruction_asndz-instruction_handler
	db	'asn~~em',0x00
	dw	ARM_instruction_asnem-instruction_handler
	db	'asn~~ep',0x00
	dw	ARM_instruction_asnep-instruction_handler
	db	'asn~~ez',0x00
	dw	ARM_instruction_asnez-instruction_handler
	db	'asn~~sm',0x00
	dw	ARM_instruction_asnsm-instruction_handler
	db	'asn~~sp',0x00
	dw	ARM_instruction_asnsp-instruction_handler
	db	'asn~~sz',0x00
	dw	ARM_instruction_asnsz-instruction_handler
	db	'asr~~.n',0x04
	dw	ARM_instruction_asr-instruction_handler
	db	'asr~~.w',0x02
	dw	ARM_instruction_asr-instruction_handler
	db	'atn~~dm',0x00
	dw	ARM_instruction_atndm-instruction_handler
	db	'atn~~dp',0x00
	dw	ARM_instruction_atndp-instruction_handler
	db	'atn~~dz',0x00
	dw	ARM_instruction_atndz-instruction_handler
	db	'atn~~em',0x00
	dw	ARM_instruction_atnem-instruction_handler
	db	'atn~~ep',0x00
	dw	ARM_instruction_atnep-instruction_handler
	db	'atn~~ez',0x00
	dw	ARM_instruction_atnez-instruction_handler
	db	'atn~~sm',0x00
	dw	ARM_instruction_atnsm-instruction_handler
	db	'atn~~sp',0x00
	dw	ARM_instruction_atnsp-instruction_handler
	db	'atn~~sz',0x00
	dw	ARM_instruction_atnsz-instruction_handler
	db	'bic~~.n',0x04
	dw	ARM_instruction_bic-instruction_handler
	db	'bic~~.w',0x02
	dw	ARM_instruction_bic-instruction_handler
	db	'blx~~.n',0x04
	dw	ARM_instruction_blx-instruction_handler
	db	'blx~~.w',0x02
	dw	ARM_instruction_blx-instruction_handler
	db	'cfabs32',0xe0
	dw	ARM_instruction_cfabs32-instruction_handler
	db	'cfabs64',0xe0
	dw	ARM_instruction_cfabs64-instruction_handler
	db	'cfadd32',0xe0
	dw	ARM_instruction_cfadd32-instruction_handler
	db	'cfadd64',0xe0
	dw	ARM_instruction_cfadd64-instruction_handler
	db	'cfcmp32',0xe0
	dw	ARM_instruction_cfcmp32-instruction_handler
	db	'cfcmp64',0xe0
	dw	ARM_instruction_cfcmp64-instruction_handler
	db	'cfcvtds',0xe0
	dw	ARM_instruction_cfcvtds-instruction_handler
	db	'cfcvtsd',0xe0
	dw	ARM_instruction_cfcvtsd-instruction_handler
	db	'cfldr32',0xe0
	dw	ARM_instruction_cfldr32-instruction_handler
	db	'cfldr64',0xe0
	dw	ARM_instruction_cfldr64-instruction_handler
	db	'cfmac32',0xe0
	dw	ARM_instruction_cfmac32-instruction_handler
	db	'cfmsc32',0xe0
	dw	ARM_instruction_cfmsc32-instruction_handler
	db	'cfmul32',0xe0
	dw	ARM_instruction_cfmul32-instruction_handler
	db	'cfmul64',0xe0
	dw	ARM_instruction_cfmul64-instruction_handler
	db	'cfmv32a',0xe0
	dw	ARM_instruction_cfmv32a-instruction_handler
	db	'cfmv64a',0xe0
	dw	ARM_instruction_cfmv64a-instruction_handler
	db	'cfmva32',0xe0
	dw	ARM_instruction_cfmva32-instruction_handler
	db	'cfmva64',0xe0
	dw	ARM_instruction_cfmva64-instruction_handler
	db	'cfmvdhr',0xe0
	dw	ARM_instruction_cfmvdhr-instruction_handler
	db	'cfmvdlr',0xe0
	dw	ARM_instruction_cfmvdlr-instruction_handler
	db	'cfmvrdh',0xe0
	dw	ARM_instruction_cfmvrdh-instruction_handler
	db	'cfmvrdl',0xe0
	dw	ARM_instruction_cfmvrdl-instruction_handler
	db	'cfneg32',0xe0
	dw	ARM_instruction_cfneg32-instruction_handler
	db	'cfneg64',0xe0
	dw	ARM_instruction_cfneg64-instruction_handler
	db	'cfstr32',0xe0
	dw	ARM_instruction_cfstr32-instruction_handler
	db	'cfstr64',0xe0
	dw	ARM_instruction_cfstr64-instruction_handler
	db	'cfsub32',0xe0
	dw	ARM_instruction_cfsub32-instruction_handler
	db	'cfsub64',0xe0
	dw	ARM_instruction_cfsub64-instruction_handler
	db	'clrex~~',0x00
	dw	ARM_instruction_clrex-instruction_handler
	db	'cmn~~.n',0x04
	dw	ARM_instruction_cmn-instruction_handler
	db	'cmn~~.w',0x02
	dw	ARM_instruction_cmn-instruction_handler
	db	'cmp~~.n',0x04
	dw	ARM_instruction_cmp-instruction_handler
	db	'cmp~~.w',0x02
	dw	ARM_instruction_cmp-instruction_handler
	db	'cos~~dm',0x00
	dw	ARM_instruction_cosdm-instruction_handler
	db	'cos~~dp',0x00
	dw	ARM_instruction_cosdp-instruction_handler
	db	'cos~~dz',0x00
	dw	ARM_instruction_cosdz-instruction_handler
	db	'cos~~em',0x00
	dw	ARM_instruction_cosem-instruction_handler
	db	'cos~~ep',0x00
	dw	ARM_instruction_cosep-instruction_handler
	db	'cos~~ez',0x00
	dw	ARM_instruction_cosez-instruction_handler
	db	'cos~~sm',0x00
	dw	ARM_instruction_cossm-instruction_handler
	db	'cos~~sp',0x00
	dw	ARM_instruction_cossp-instruction_handler
	db	'cos~~sz',0x00
	dw	ARM_instruction_cossz-instruction_handler
	db	'cpsid.n',0xf4
	dw	ARM_instruction_cpsid-instruction_handler
	db	'cpsid.w',0xf2
	dw	ARM_instruction_cpsid-instruction_handler
	db	'cpsie.n',0xf4
	dw	ARM_instruction_cpsie-instruction_handler
	db	'cpsie.w',0xf2
	dw	ARM_instruction_cpsie-instruction_handler
	db	'cpy~~.n',0x04
	dw	ARM_instruction_cpy-instruction_handler
	db	'cpy~~.w',0x02
	dw	ARM_instruction_cpy-instruction_handler
	db	'crc32cb',0xf0
	dw	ARM_instruction_crc32cb-instruction_handler
	db	'crc32ch',0xf0
	dw	ARM_instruction_crc32ch-instruction_handler
	db	'crc32cw',0xf0
	dw	ARM_instruction_crc32cw-instruction_handler
	db	'crc32cx',0xf0
	dw	ARM_instruction_crc32cx-instruction_handler
	db	'display',0x00
	dw	display_directive-instruction_handler
	db	'dvf~~dm',0x00
	dw	ARM_instruction_dvfdm-instruction_handler
	db	'dvf~~dp',0x00
	dw	ARM_instruction_dvfdp-instruction_handler
	db	'dvf~~dz',0x00
	dw	ARM_instruction_dvfdz-instruction_handler
	db	'dvf~~em',0x00
	dw	ARM_instruction_dvfem-instruction_handler
	db	'dvf~~ep',0x00
	dw	ARM_instruction_dvfep-instruction_handler
	db	'dvf~~ez',0x00
	dw	ARM_instruction_dvfez-instruction_handler
	db	'dvf~~sm',0x00
	dw	ARM_instruction_dvfsm-instruction_handler
	db	'dvf~~sp',0x00
	dw	ARM_instruction_dvfsp-instruction_handler
	db	'dvf~~sz',0x00
	dw	ARM_instruction_dvfsz-instruction_handler
	db	'eor~~.n',0x04
	dw	ARM_instruction_eor-instruction_handler
	db	'eor~~.w',0x02
	dw	ARM_instruction_eor-instruction_handler
	db	'exp~~dm',0x00
	dw	ARM_instruction_expdm-instruction_handler
	db	'exp~~dp',0x00
	dw	ARM_instruction_expdp-instruction_handler
	db	'exp~~dz',0x00
	dw	ARM_instruction_expdz-instruction_handler
	db	'exp~~em',0x00
	dw	ARM_instruction_expem-instruction_handler
	db	'exp~~ep',0x00
	dw	ARM_instruction_expep-instruction_handler
	db	'exp~~ez',0x00
	dw	ARM_instruction_expez-instruction_handler
	db	'exp~~sm',0x00
	dw	ARM_instruction_expsm-instruction_handler
	db	'exp~~sp',0x00
	dw	ARM_instruction_expsp-instruction_handler
	db	'exp~~sz',0x00
	dw	ARM_instruction_expsz-instruction_handler
	db	'fabsd~~',0x00
	dw	ARM_instruction_fabsd-instruction_handler
	db	'fabss~~',0x00
	dw	ARM_instruction_fabss-instruction_handler
	db	'faddd~~',0x00
	dw	ARM_instruction_faddd-instruction_handler
	db	'fadds~~',0x00
	dw	ARM_instruction_fadds-instruction_handler
	db	'fcmpd~~',0x00
	dw	ARM_instruction_fcmpd-instruction_handler
	db	'fcmpezd',0xe0
	dw	ARM_instruction_fcmpezd-instruction_handler
	db	'fcmpezs',0xe0
	dw	ARM_instruction_fcmpezs-instruction_handler
	db	'fcmps~~',0x00
	dw	ARM_instruction_fcmps-instruction_handler
	db	'fconstd',0xe0
	dw	ARM_instruction_fconstd-instruction_handler
	db	'fconsts',0xe0
	dw	ARM_instruction_fconsts-instruction_handler
	db	'fcpyd~~',0x00
	dw	ARM_instruction_fcpyd-instruction_handler
	db	'fcpys~~',0x00
	dw	ARM_instruction_fcpys-instruction_handler
	db	'fcvtxn2',0xf0
	dw	ARM_instruction_fcvtxn2-instruction_handler
	db	'fdivd~~',0x00
	dw	ARM_instruction_fdivd-instruction_handler
	db	'fdivs~~',0x00
	dw	ARM_instruction_fdivs-instruction_handler
	db	'fdv~~dm',0x00
	dw	ARM_instruction_fdvdm-instruction_handler
	db	'fdv~~dp',0x00
	dw	ARM_instruction_fdvdp-instruction_handler
	db	'fdv~~dz',0x00
	dw	ARM_instruction_fdvdz-instruction_handler
	db	'fdv~~em',0x00
	dw	ARM_instruction_fdvem-instruction_handler
	db	'fdv~~ep',0x00
	dw	ARM_instruction_fdvep-instruction_handler
	db	'fdv~~ez',0x00
	dw	ARM_instruction_fdvez-instruction_handler
	db	'fdv~~sm',0x00
	dw	ARM_instruction_fdvsm-instruction_handler
	db	'fdv~~sp',0x00
	dw	ARM_instruction_fdvsp-instruction_handler
	db	'fdv~~sz',0x00
	dw	ARM_instruction_fdvsz-instruction_handler
	db	'fldmdbd',0xe0
	dw	ARM_instruction_fldmdbd-instruction_handler
	db	'fldmdbs',0xe0
	dw	ARM_instruction_fldmdbs-instruction_handler
	db	'fldmdbx',0xe0
	dw	ARM_instruction_fldmdbx-instruction_handler
	db	'fldmd~~',0x00
	dw	ARM_instruction_fldmd-instruction_handler
	db	'fldmead',0xe0
	dw	ARM_instruction_fldmead-instruction_handler
	db	'fldmeas',0xe0
	dw	ARM_instruction_fldmeas-instruction_handler
	db	'fldmeax',0xe0
	dw	ARM_instruction_fldmeax-instruction_handler
	db	'fldmfdd',0xe0
	dw	ARM_instruction_fldmfdd-instruction_handler
	db	'fldmfds',0xe0
	dw	ARM_instruction_fldmfds-instruction_handler
	db	'fldmfdx',0xe0
	dw	ARM_instruction_fldmfdx-instruction_handler
	db	'fldmiad',0xe0
	dw	ARM_instruction_fldmiad-instruction_handler
	db	'fldmias',0xe0
	dw	ARM_instruction_fldmias-instruction_handler
	db	'fldmiax',0xe0
	dw	ARM_instruction_fldmiax-instruction_handler
	db	'fldms~~',0x00
	dw	ARM_instruction_fldms-instruction_handler
	db	'fldmx~~',0x00
	dw	ARM_instruction_fldmx-instruction_handler
	db	'flt~~dm',0x00
	dw	ARM_instruction_fltdm-instruction_handler
	db	'flt~~dp',0x00
	dw	ARM_instruction_fltdp-instruction_handler
	db	'flt~~dz',0x00
	dw	ARM_instruction_fltdz-instruction_handler
	db	'flt~~em',0x00
	dw	ARM_instruction_fltem-instruction_handler
	db	'flt~~ep',0x00
	dw	ARM_instruction_fltep-instruction_handler
	db	'flt~~ez',0x00
	dw	ARM_instruction_fltez-instruction_handler
	db	'flt~~sm',0x00
	dw	ARM_instruction_fltsm-instruction_handler
	db	'flt~~sp',0x00
	dw	ARM_instruction_fltsp-instruction_handler
	db	'flt~~sz',0x00
	dw	ARM_instruction_fltsz-instruction_handler
	db	'fmacd~~',0x00
	dw	ARM_instruction_fmacd-instruction_handler
	db	'fmacs~~',0x00
	dw	ARM_instruction_fmacs-instruction_handler
	db	'fmaxnmp',0xf0
	dw	ARM_instruction_fmaxnmp-instruction_handler
	db	'fmaxnmv',0xf0
	dw	ARM_instruction_fmaxnmv-instruction_handler
	db	'fmdhr~~',0x00
	dw	ARM_instruction_fmdhr-instruction_handler
	db	'fmdlr~~',0x00
	dw	ARM_instruction_fmdlr-instruction_handler
	db	'fmdrr~~',0x00
	dw	ARM_instruction_fmdrr-instruction_handler
	db	'fminnmp',0xf0
	dw	ARM_instruction_fminnmp-instruction_handler
	db	'fminnmv',0xf0
	dw	ARM_instruction_fminnmv-instruction_handler
	db	'fml~~dm',0x00
	dw	ARM_instruction_fmldm-instruction_handler
	db	'fml~~dp',0x00
	dw	ARM_instruction_fmldp-instruction_handler
	db	'fml~~dz',0x00
	dw	ARM_instruction_fmldz-instruction_handler
	db	'fml~~em',0x00
	dw	ARM_instruction_fmlem-instruction_handler
	db	'fml~~ep',0x00
	dw	ARM_instruction_fmlep-instruction_handler
	db	'fml~~ez',0x00
	dw	ARM_instruction_fmlez-instruction_handler
	db	'fml~~sm',0x00
	dw	ARM_instruction_fmlsm-instruction_handler
	db	'fml~~sp',0x00
	dw	ARM_instruction_fmlsp-instruction_handler
	db	'fml~~sz',0x00
	dw	ARM_instruction_fmlsz-instruction_handler
	db	'fmrdh~~',0x00
	dw	ARM_instruction_fmrdh-instruction_handler
	db	'fmrdl~~',0x00
	dw	ARM_instruction_fmrdl-instruction_handler
	db	'fmrrd~~',0x00
	dw	ARM_instruction_fmrrd-instruction_handler
	db	'fmrrs~~',0x00
	dw	ARM_instruction_fmrrs-instruction_handler
	db	'fmscd~~',0x00
	dw	ARM_instruction_fmscd-instruction_handler
	db	'fmscs~~',0x00
	dw	ARM_instruction_fmscs-instruction_handler
	db	'fmsrr~~',0x00
	dw	ARM_instruction_fmsrr-instruction_handler
	db	'fmuld~~',0x00
	dw	ARM_instruction_fmuld-instruction_handler
	db	'fmuls~~',0x00
	dw	ARM_instruction_fmuls-instruction_handler
	db	'fnegd~~',0x00
	dw	ARM_instruction_fnegd-instruction_handler
	db	'fnegs~~',0x00
	dw	ARM_instruction_fnegs-instruction_handler
	db	'frd~~dm',0x00
	dw	ARM_instruction_frddm-instruction_handler
	db	'frd~~dp',0x00
	dw	ARM_instruction_frddp-instruction_handler
	db	'frd~~dz',0x00
	dw	ARM_instruction_frddz-instruction_handler
	db	'frd~~em',0x00
	dw	ARM_instruction_frdem-instruction_handler
	db	'frd~~ep',0x00
	dw	ARM_instruction_frdep-instruction_handler
	db	'frd~~ez',0x00
	dw	ARM_instruction_frdez-instruction_handler
	db	'frd~~sm',0x00
	dw	ARM_instruction_frdsm-instruction_handler
	db	'frd~~sp',0x00
	dw	ARM_instruction_frdsp-instruction_handler
	db	'frd~~sz',0x00
	dw	ARM_instruction_frdsz-instruction_handler
	db	'frsqrte',0xf0
	dw	ARM_instruction_frsqrte-instruction_handler
	db	'frsqrts',0xf0
	dw	ARM_instruction_frsqrts-instruction_handler
	db	'fstmdbd',0xe0
	dw	ARM_instruction_fstmdbd-instruction_handler
	db	'fstmdbs',0xe0
	dw	ARM_instruction_fstmdbs-instruction_handler
	db	'fstmdbx',0xe0
	dw	ARM_instruction_fstmdbx-instruction_handler
	db	'fstmd~~',0x00
	dw	ARM_instruction_fstmd-instruction_handler
	db	'fstmead',0xe0
	dw	ARM_instruction_fstmead-instruction_handler
	db	'fstmeas',0xe0
	dw	ARM_instruction_fstmeas-instruction_handler
	db	'fstmeax',0xe0
	dw	ARM_instruction_fstmeax-instruction_handler
	db	'fstmfdd',0xe0
	dw	ARM_instruction_fstmfdd-instruction_handler
	db	'fstmfds',0xe0
	dw	ARM_instruction_fstmfds-instruction_handler
	db	'fstmfdx',0xe0
	dw	ARM_instruction_fstmfdx-instruction_handler
	db	'fstmiad',0xe0
	dw	ARM_instruction_fstmiad-instruction_handler
	db	'fstmias',0xe0
	dw	ARM_instruction_fstmias-instruction_handler
	db	'fstmiax',0xe0
	dw	ARM_instruction_fstmiax-instruction_handler
	db	'fstms~~',0x00
	dw	ARM_instruction_fstms-instruction_handler
	db	'fstmx~~',0x00
	dw	ARM_instruction_fstmx-instruction_handler
	db	'fsubd~~',0x00
	dw	ARM_instruction_fsubd-instruction_handler
	db	'fsubs~~',0x00
	dw	ARM_instruction_fsubs-instruction_handler
	db	'ftosizd',0xe0
	dw	ARM_instruction_ftosizd-instruction_handler
	db	'ftosizs',0xe0
	dw	ARM_instruction_ftosizs-instruction_handler
	db	'ftouizd',0xe0
	dw	ARM_instruction_ftouizd-instruction_handler
	db	'ftouizs',0xe0
	dw	ARM_instruction_ftouizs-instruction_handler
	db	'ldaex~~',0x00
	dw	ARM_instruction_ldaex-instruction_handler
	db	'ldc2l~~',0x00
	dw	ARM_instruction_ldc2l-instruction_handler
	db	'ldmda~~',0x00
	dw	ARM_instruction_ldmda-instruction_handler
	db	'ldmdb~~',0x00
	dw	ARM_instruction_ldmdb-instruction_handler
	db	'ldmea~~',0x00
	dw	ARM_instruction_ldmea-instruction_handler
	db	'ldmed~~',0x00
	dw	ARM_instruction_ldmed-instruction_handler
	db	'ldmfa~~',0x00
	dw	ARM_instruction_ldmfa-instruction_handler
	db	'ldmfd.n',0xe4
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldmfd.w',0xe2
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldmfd~~',0x00
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldmia.n',0xe4
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldmia.w',0xe2
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldmia~~',0x00
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldmib~~',0x00
	dw	ARM_instruction_ldmib-instruction_handler
	db	'ldm~~.n',0x04
	dw	ARM_instruction_ldm-instruction_handler
	db	'ldm~~.w',0x02
	dw	ARM_instruction_ldm-instruction_handler
	db	'ldm~~da',0x00
	dw	ARM_instruction_ldmda-instruction_handler
	db	'ldm~~db',0x00
	dw	ARM_instruction_ldmdb-instruction_handler
	db	'ldm~~ea',0x00
	dw	ARM_instruction_ldmea-instruction_handler
	db	'ldm~~ed',0x00
	dw	ARM_instruction_ldmed-instruction_handler
	db	'ldm~~fa',0x00
	dw	ARM_instruction_ldmfa-instruction_handler
	db	'ldm~~fd',0x00
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldm~~ia',0x00
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldm~~ib',0x00
	dw	ARM_instruction_ldmib-instruction_handler
	db	'ldrbt~~',0x00
	dw	ARM_instruction_ldrbt-instruction_handler
	db	'ldrex~~',0x00
	dw	ARM_instruction_ldrex-instruction_handler
	db	'ldrht~~',0x00
	dw	ARM_instruction_ldrht-instruction_handler
	db	'ldrsb.n',0xe4
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldrsb.w',0xe2
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldrsb~~',0x00
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldrsh.n',0xe4
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldrsh.w',0xe2
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldrsh~~',0x00
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldr~~.n',0x04
	dw	ARM_instruction_ldr-instruction_handler
	db	'ldr~~.w',0x02
	dw	ARM_instruction_ldr-instruction_handler
	db	'ldr~~bt',0x00
	dw	ARM_instruction_ldrbt-instruction_handler
	db	'ldr~~ht',0x00
	dw	ARM_instruction_ldrht-instruction_handler
	db	'ldr~~sb',0x00
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldr~~sh',0x00
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'lfm~~ea',0x00
	dw	ARM_instruction_lfmea-instruction_handler
	db	'lfm~~fd',0x00
	dw	ARM_instruction_lfmfd-instruction_handler
	db	'lgn~~dm',0x00
	dw	ARM_instruction_lgndm-instruction_handler
	db	'lgn~~dp',0x00
	dw	ARM_instruction_lgndp-instruction_handler
	db	'lgn~~dz',0x00
	dw	ARM_instruction_lgndz-instruction_handler
	db	'lgn~~em',0x00
	dw	ARM_instruction_lgnem-instruction_handler
	db	'lgn~~ep',0x00
	dw	ARM_instruction_lgnep-instruction_handler
	db	'lgn~~ez',0x00
	dw	ARM_instruction_lgnez-instruction_handler
	db	'lgn~~sm',0x00
	dw	ARM_instruction_lgnsm-instruction_handler
	db	'lgn~~sp',0x00
	dw	ARM_instruction_lgnsp-instruction_handler
	db	'lgn~~sz',0x00
	dw	ARM_instruction_lgnsz-instruction_handler
	db	'log~~dm',0x00
	dw	ARM_instruction_logdm-instruction_handler
	db	'log~~dp',0x00
	dw	ARM_instruction_logdp-instruction_handler
	db	'log~~dz',0x00
	dw	ARM_instruction_logdz-instruction_handler
	db	'log~~em',0x00
	dw	ARM_instruction_logem-instruction_handler
	db	'log~~ep',0x00
	dw	ARM_instruction_logep-instruction_handler
	db	'log~~ez',0x00
	dw	ARM_instruction_logez-instruction_handler
	db	'log~~sm',0x00
	dw	ARM_instruction_logsm-instruction_handler
	db	'log~~sp',0x00
	dw	ARM_instruction_logsp-instruction_handler
	db	'log~~sz',0x00
	dw	ARM_instruction_logsz-instruction_handler
	db	'lsl~~.n',0x04
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsl~~.w',0x02
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsr~~.n',0x04
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsr~~.w',0x02
	dw	ARM_instruction_lsr-instruction_handler
	db	'mcrr2~~',0x00
	dw	ARM_instruction_mcrr2-instruction_handler
	db	'miabb~~',0x00
	dw	ARM_instruction_miabb-instruction_handler
	db	'miabt~~',0x00
	dw	ARM_instruction_miabt-instruction_handler
	db	'miaph~~',0x00
	dw	ARM_instruction_miaph-instruction_handler
	db	'miatb~~',0x00
	dw	ARM_instruction_miatb-instruction_handler
	db	'miatt~~',0x00
	dw	ARM_instruction_miatt-instruction_handler
	db	'mnf~~dm',0x00
	dw	ARM_instruction_mnfdm-instruction_handler
	db	'mnf~~dp',0x00
	dw	ARM_instruction_mnfdp-instruction_handler
	db	'mnf~~dz',0x00
	dw	ARM_instruction_mnfdz-instruction_handler
	db	'mnf~~em',0x00
	dw	ARM_instruction_mnfem-instruction_handler
	db	'mnf~~ep',0x00
	dw	ARM_instruction_mnfep-instruction_handler
	db	'mnf~~ez',0x00
	dw	ARM_instruction_mnfez-instruction_handler
	db	'mnf~~sm',0x00
	dw	ARM_instruction_mnfsm-instruction_handler
	db	'mnf~~sp',0x00
	dw	ARM_instruction_mnfsp-instruction_handler
	db	'mnf~~sz',0x00
	dw	ARM_instruction_mnfsz-instruction_handler
	db	'mov~~.n',0x04
	dw	ARM_instruction_mov-instruction_handler
	db	'mov~~.w',0x02
	dw	ARM_instruction_mov-instruction_handler
	db	'mrrc2~~',0x00
	dw	ARM_instruction_mrrc2-instruction_handler
	db	'muf~~dm',0x00
	dw	ARM_instruction_mufdm-instruction_handler
	db	'muf~~dp',0x00
	dw	ARM_instruction_mufdp-instruction_handler
	db	'muf~~dz',0x00
	dw	ARM_instruction_mufdz-instruction_handler
	db	'muf~~em',0x00
	dw	ARM_instruction_mufem-instruction_handler
	db	'muf~~ep',0x00
	dw	ARM_instruction_mufep-instruction_handler
	db	'muf~~ez',0x00
	dw	ARM_instruction_mufez-instruction_handler
	db	'muf~~sm',0x00
	dw	ARM_instruction_mufsm-instruction_handler
	db	'muf~~sp',0x00
	dw	ARM_instruction_mufsp-instruction_handler
	db	'muf~~sz',0x00
	dw	ARM_instruction_mufsz-instruction_handler
	db	'mul~~.n',0x04
	dw	ARM_instruction_mul-instruction_handler
	db	'mul~~.w',0x02
	dw	ARM_instruction_mul-instruction_handler
	db	'mvf~~dm',0x00
	dw	ARM_instruction_mvfdm-instruction_handler
	db	'mvf~~dp',0x00
	dw	ARM_instruction_mvfdp-instruction_handler
	db	'mvf~~dz',0x00
	dw	ARM_instruction_mvfdz-instruction_handler
	db	'mvf~~em',0x00
	dw	ARM_instruction_mvfem-instruction_handler
	db	'mvf~~ep',0x00
	dw	ARM_instruction_mvfep-instruction_handler
	db	'mvf~~ez',0x00
	dw	ARM_instruction_mvfez-instruction_handler
	db	'mvf~~sm',0x00
	dw	ARM_instruction_mvfsm-instruction_handler
	db	'mvf~~sp',0x00
	dw	ARM_instruction_mvfsp-instruction_handler
	db	'mvf~~sz',0x00
	dw	ARM_instruction_mvfsz-instruction_handler
	db	'mvn~~.n',0x04
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvn~~.w',0x02
	dw	ARM_instruction_mvn-instruction_handler
	db	'neg~~.n',0x04
	dw	ARM_instruction_neg-instruction_handler
	db	'neg~~.w',0x02
	dw	ARM_instruction_neg-instruction_handler
	db	'nop~~.n',0x04
	dw	ARM_instruction_nop-instruction_handler
	db	'nop~~.w',0x02
	dw	ARM_instruction_nop-instruction_handler
	db	'nrm~~dm',0x00
	dw	ARM_instruction_nrmdm-instruction_handler
	db	'nrm~~dp',0x00
	dw	ARM_instruction_nrmdp-instruction_handler
	db	'nrm~~dz',0x00
	dw	ARM_instruction_nrmdz-instruction_handler
	db	'nrm~~em',0x00
	dw	ARM_instruction_nrmem-instruction_handler
	db	'nrm~~ep',0x00
	dw	ARM_instruction_nrmep-instruction_handler
	db	'nrm~~ez',0x00
	dw	ARM_instruction_nrmez-instruction_handler
	db	'nrm~~sm',0x00
	dw	ARM_instruction_nrmsm-instruction_handler
	db	'nrm~~sp',0x00
	dw	ARM_instruction_nrmsp-instruction_handler
	db	'nrm~~sz',0x00
	dw	ARM_instruction_nrmsz-instruction_handler
	db	'orr~~.n',0x04
	dw	ARM_instruction_orr-instruction_handler
	db	'orr~~.w',0x02
	dw	ARM_instruction_orr-instruction_handler
	db	'pkhbt~~',0x00
	dw	ARM_instruction_pkhbt-instruction_handler
	db	'pkhtb~~',0x00
	dw	ARM_instruction_pkhtb-instruction_handler
	db	'pol~~dm',0x00
	dw	ARM_instruction_poldm-instruction_handler
	db	'pol~~dp',0x00
	dw	ARM_instruction_poldp-instruction_handler
	db	'pol~~dz',0x00
	dw	ARM_instruction_poldz-instruction_handler
	db	'pol~~em',0x00
	dw	ARM_instruction_polem-instruction_handler
	db	'pol~~ep',0x00
	dw	ARM_instruction_polep-instruction_handler
	db	'pol~~ez',0x00
	dw	ARM_instruction_polez-instruction_handler
	db	'pol~~sm',0x00
	dw	ARM_instruction_polsm-instruction_handler
	db	'pol~~sp',0x00
	dw	ARM_instruction_polsp-instruction_handler
	db	'pol~~sz',0x00
	dw	ARM_instruction_polsz-instruction_handler
	db	'pop~~.n',0x04
	dw	ARM_instruction_pop-instruction_handler
	db	'pop~~.w',0x02
	dw	ARM_instruction_pop-instruction_handler
	db	'pow~~dm',0x00
	dw	ARM_instruction_powdm-instruction_handler
	db	'pow~~dp',0x00
	dw	ARM_instruction_powdp-instruction_handler
	db	'pow~~dz',0x00
	dw	ARM_instruction_powdz-instruction_handler
	db	'pow~~em',0x00
	dw	ARM_instruction_powem-instruction_handler
	db	'pow~~ep',0x00
	dw	ARM_instruction_powep-instruction_handler
	db	'pow~~ez',0x00
	dw	ARM_instruction_powez-instruction_handler
	db	'pow~~sm',0x00
	dw	ARM_instruction_powsm-instruction_handler
	db	'pow~~sp',0x00
	dw	ARM_instruction_powsp-instruction_handler
	db	'pow~~sz',0x00
	dw	ARM_instruction_powsz-instruction_handler
	db	'qadd8~~',0x00
	dw	ARM_instruction_qadd8-instruction_handler
	db	'qdadd~~',0x00
	dw	ARM_instruction_qdadd-instruction_handler
	db	'qdsub~~',0x00
	dw	ARM_instruction_qdsub-instruction_handler
	db	'qsub8~~',0x00
	dw	ARM_instruction_qsub8-instruction_handler
	db	'raddhn2',0xf0
	dw	ARM_instruction_raddhn2-instruction_handler
	db	'rdf~~dm',0x00
	dw	ARM_instruction_rdfdm-instruction_handler
	db	'rdf~~dp',0x00
	dw	ARM_instruction_rdfdp-instruction_handler
	db	'rdf~~dz',0x00
	dw	ARM_instruction_rdfdz-instruction_handler
	db	'rdf~~em',0x00
	dw	ARM_instruction_rdfem-instruction_handler
	db	'rdf~~ep',0x00
	dw	ARM_instruction_rdfep-instruction_handler
	db	'rdf~~ez',0x00
	dw	ARM_instruction_rdfez-instruction_handler
	db	'rdf~~sm',0x00
	dw	ARM_instruction_rdfsm-instruction_handler
	db	'rdf~~sp',0x00
	dw	ARM_instruction_rdfsp-instruction_handler
	db	'rdf~~sz',0x00
	dw	ARM_instruction_rdfsz-instruction_handler
	db	'rev16.n',0xe4
	dw	ARM_instruction_rev16-instruction_handler
	db	'rev16.w',0xe2
	dw	ARM_instruction_rev16-instruction_handler
	db	'rev16~~',0x00
	dw	ARM_instruction_rev16-instruction_handler
	db	'revsh.n',0xe4
	dw	ARM_instruction_revsh-instruction_handler
	db	'revsh.w',0xe2
	dw	ARM_instruction_revsh-instruction_handler
	db	'revsh~~',0x00
	dw	ARM_instruction_revsh-instruction_handler
	db	'rev~~.n',0x04
	dw	ARM_instruction_rev-instruction_handler
	db	'rev~~.w',0x02
	dw	ARM_instruction_rev-instruction_handler
	db	'rmf~~dm',0x00
	dw	ARM_instruction_rmfdm-instruction_handler
	db	'rmf~~dp',0x00
	dw	ARM_instruction_rmfdp-instruction_handler
	db	'rmf~~dz',0x00
	dw	ARM_instruction_rmfdz-instruction_handler
	db	'rmf~~em',0x00
	dw	ARM_instruction_rmfem-instruction_handler
	db	'rmf~~ep',0x00
	dw	ARM_instruction_rmfep-instruction_handler
	db	'rmf~~ez',0x00
	dw	ARM_instruction_rmfez-instruction_handler
	db	'rmf~~sm',0x00
	dw	ARM_instruction_rmfsm-instruction_handler
	db	'rmf~~sp',0x00
	dw	ARM_instruction_rmfsp-instruction_handler
	db	'rmf~~sz',0x00
	dw	ARM_instruction_rmfsz-instruction_handler
	db	'rnd~~dm',0x00
	dw	ARM_instruction_rnddm-instruction_handler
	db	'rnd~~dp',0x00
	dw	ARM_instruction_rnddp-instruction_handler
	db	'rnd~~dz',0x00
	dw	ARM_instruction_rnddz-instruction_handler
	db	'rnd~~em',0x00
	dw	ARM_instruction_rndem-instruction_handler
	db	'rnd~~ep',0x00
	dw	ARM_instruction_rndep-instruction_handler
	db	'rnd~~ez',0x00
	dw	ARM_instruction_rndez-instruction_handler
	db	'rnd~~sm',0x00
	dw	ARM_instruction_rndsm-instruction_handler
	db	'rnd~~sp',0x00
	dw	ARM_instruction_rndsp-instruction_handler
	db	'rnd~~sz',0x00
	dw	ARM_instruction_rndsz-instruction_handler
	db	'ror~~.n',0x04
	dw	ARM_instruction_ror-instruction_handler
	db	'ror~~.w',0x02
	dw	ARM_instruction_ror-instruction_handler
	db	'rpw~~dm',0x00
	dw	ARM_instruction_rpwdm-instruction_handler
	db	'rpw~~dp',0x00
	dw	ARM_instruction_rpwdp-instruction_handler
	db	'rpw~~dz',0x00
	dw	ARM_instruction_rpwdz-instruction_handler
	db	'rpw~~em',0x00
	dw	ARM_instruction_rpwem-instruction_handler
	db	'rpw~~ep',0x00
	dw	ARM_instruction_rpwep-instruction_handler
	db	'rpw~~ez',0x00
	dw	ARM_instruction_rpwez-instruction_handler
	db	'rpw~~sm',0x00
	dw	ARM_instruction_rpwsm-instruction_handler
	db	'rpw~~sp',0x00
	dw	ARM_instruction_rpwsp-instruction_handler
	db	'rpw~~sz',0x00
	dw	ARM_instruction_rpwsz-instruction_handler
	db	'rsb~~.n',0x04
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsb~~.w',0x02
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsf~~dm',0x00
	dw	ARM_instruction_rsfdm-instruction_handler
	db	'rsf~~dp',0x00
	dw	ARM_instruction_rsfdp-instruction_handler
	db	'rsf~~dz',0x00
	dw	ARM_instruction_rsfdz-instruction_handler
	db	'rsf~~em',0x00
	dw	ARM_instruction_rsfem-instruction_handler
	db	'rsf~~ep',0x00
	dw	ARM_instruction_rsfep-instruction_handler
	db	'rsf~~ez',0x00
	dw	ARM_instruction_rsfez-instruction_handler
	db	'rsf~~sm',0x00
	dw	ARM_instruction_rsfsm-instruction_handler
	db	'rsf~~sp',0x00
	dw	ARM_instruction_rsfsp-instruction_handler
	db	'rsf~~sz',0x00
	dw	ARM_instruction_rsfsz-instruction_handler
	db	'rsubhn2',0xf0
	dw	ARM_instruction_rsubhn2-instruction_handler
	db	'sadd8~~',0x00
	dw	ARM_instruction_sadd8-instruction_handler
	db	'sbc~~.n',0x04
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbc~~.w',0x02
	dw	ARM_instruction_sbc-instruction_handler
	db	'section',0x00
	dw	ARM_section_directive-instruction_handler
	db	'segment',0x00
	dw	segment_directive-instruction_handler
	db	'sev~~.n',0x04
	dw	ARM_instruction_sev-instruction_handler
	db	'sev~~.w',0x02
	dw	ARM_instruction_sev-instruction_handler
	db	'sfm~~ea',0x00
	dw	ARM_instruction_sfmea-instruction_handler
	db	'sfm~~fd',0x00
	dw	ARM_instruction_sfmfd-instruction_handler
	db	'sha1su0',0xf0
	dw	ARM_instruction_sha1su0-instruction_handler
	db	'sha1su1',0xf0
	dw	ARM_instruction_sha1su1-instruction_handler
	db	'sha256h',0xf0
	dw	ARM_instruction_sha256h-instruction_handler
	db	'shadd16',0xe0
	dw	ARM_instruction_shadd16-instruction_handler
	db	'shasx~~',0x00
	dw	ARM_instruction_shasx-instruction_handler
	db	'shsax~~',0x00
	dw	ARM_instruction_shsax-instruction_handler
	db	'shsub16',0xe0
	dw	ARM_instruction_shsub16-instruction_handler
	db	'sin~~dm',0x00
	dw	ARM_instruction_sindm-instruction_handler
	db	'sin~~dp',0x00
	dw	ARM_instruction_sindp-instruction_handler
	db	'sin~~dz',0x00
	dw	ARM_instruction_sindz-instruction_handler
	db	'sin~~em',0x00
	dw	ARM_instruction_sinem-instruction_handler
	db	'sin~~ep',0x00
	dw	ARM_instruction_sinep-instruction_handler
	db	'sin~~ez',0x00
	dw	ARM_instruction_sinez-instruction_handler
	db	'sin~~sm',0x00
	dw	ARM_instruction_sinsm-instruction_handler
	db	'sin~~sp',0x00
	dw	ARM_instruction_sinsp-instruction_handler
	db	'sin~~sz',0x00
	dw	ARM_instruction_sinsz-instruction_handler
	db	'smlad~~',0x00
	dw	ARM_instruction_smlad-instruction_handler
	db	'smlalbb',0xe0
	dw	ARM_instruction_smlalbb-instruction_handler
	db	'smlalbt',0xe0
	dw	ARM_instruction_smlalbt-instruction_handler
	db	'smlaldx',0xe0
	dw	ARM_instruction_smlaldx-instruction_handler
	db	'smlaltb',0xe0
	dw	ARM_instruction_smlaltb-instruction_handler
	db	'smlaltt',0xe0
	dw	ARM_instruction_smlaltt-instruction_handler
	db	'smlal~~',0x00
	dw	ARM_instruction_smlal-instruction_handler
	db	'smlsd~~',0x00
	dw	ARM_instruction_smlsd-instruction_handler
	db	'smlsldx',0xe0
	dw	ARM_instruction_smlsldx-instruction_handler
	db	'smmla~~',0x00
	dw	ARM_instruction_smmla-instruction_handler
	db	'smmls~~',0x00
	dw	ARM_instruction_smmls-instruction_handler
	db	'smmul~~',0x00
	dw	ARM_instruction_smmul-instruction_handler
	db	'smuad~~',0x00
	dw	ARM_instruction_smuad-instruction_handler
	db	'smull~~',0x00
	dw	ARM_instruction_smull-instruction_handler
	db	'smusd~~',0x00
	dw	ARM_instruction_smusd-instruction_handler
	db	'sqdmlal',0xf0
	dw	ARM_instruction_sqdmlal-instruction_handler
	db	'sqdmlsl',0xf0
	dw	ARM_instruction_sqdmlsl-instruction_handler
	db	'sqdmulh',0xf0
	dw	ARM_instruction_sqdmulh-instruction_handler
	db	'sqdmull',0xf0
	dw	ARM_instruction_sqdmull-instruction_handler
	db	'sqrshrn',0xf0
	dw	ARM_instruction_sqrshrn-instruction_handler
	db	'sqshrn2',0xf0
	dw	ARM_instruction_sqshrn2-instruction_handler
	db	'sqshrun',0xf0
	dw	ARM_instruction_sqshrun-instruction_handler
	db	'sqt~~dm',0x00
	dw	ARM_instruction_sqtdm-instruction_handler
	db	'sqt~~dp',0x00
	dw	ARM_instruction_sqtdp-instruction_handler
	db	'sqt~~dz',0x00
	dw	ARM_instruction_sqtdz-instruction_handler
	db	'sqt~~em',0x00
	dw	ARM_instruction_sqtem-instruction_handler
	db	'sqt~~ep',0x00
	dw	ARM_instruction_sqtep-instruction_handler
	db	'sqt~~ez',0x00
	dw	ARM_instruction_sqtez-instruction_handler
	db	'sqt~~sm',0x00
	dw	ARM_instruction_sqtsm-instruction_handler
	db	'sqt~~sp',0x00
	dw	ARM_instruction_sqtsp-instruction_handler
	db	'sqt~~sz',0x00
	dw	ARM_instruction_sqtsz-instruction_handler
	db	'sqxtun2',0xf0
	dw	ARM_instruction_sqxtun2-instruction_handler
	db	'ssub8~~',0x00
	dw	ARM_instruction_ssub8-instruction_handler
	db	'stc2l~~',0x00
	dw	ARM_instruction_stc2l-instruction_handler
	db	'stlex~~',0x00
	dw	ARM_instruction_stlex-instruction_handler
	db	'stmda~~',0x00
	dw	ARM_instruction_stmda-instruction_handler
	db	'stmdb.n',0xe4
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stmdb.w',0xe2
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stmdb~~',0x00
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stmea~~',0x00
	dw	ARM_instruction_stmea-instruction_handler
	db	'stmed~~',0x00
	dw	ARM_instruction_stmed-instruction_handler
	db	'stmfa~~',0x00
	dw	ARM_instruction_stmfa-instruction_handler
	db	'stmfd.n',0xe4
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stmfd.w',0xe2
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stmfd~~',0x00
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stmia.n',0xe4
	dw	ARM_instruction_stmia-instruction_handler
	db	'stmia.w',0xe2
	dw	ARM_instruction_stmia-instruction_handler
	db	'stmia~~',0x00
	dw	ARM_instruction_stmia-instruction_handler
	db	'stmib~~',0x00
	dw	ARM_instruction_stmib-instruction_handler
	db	'stm~~.n',0x04
	dw	ARM_instruction_stm-instruction_handler
	db	'stm~~.w',0x02
	dw	ARM_instruction_stm-instruction_handler
	db	'stm~~da',0x00
	dw	ARM_instruction_stmda-instruction_handler
	db	'stm~~db',0x00
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stm~~ea',0x00
	dw	ARM_instruction_stmea-instruction_handler
	db	'stm~~ed',0x00
	dw	ARM_instruction_stmed-instruction_handler
	db	'stm~~fa',0x00
	dw	ARM_instruction_stmfa-instruction_handler
	db	'stm~~fd',0x00
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stm~~ia',0x00
	dw	ARM_instruction_stmia-instruction_handler
	db	'stm~~ib',0x00
	dw	ARM_instruction_stmib-instruction_handler
	db	'strbt~~',0x00
	dw	ARM_instruction_strbt-instruction_handler
	db	'strex~~',0x00
	dw	ARM_instruction_strex-instruction_handler
	db	'strht~~',0x00
	dw	ARM_instruction_strht-instruction_handler
	db	'str~~.n',0x04
	dw	ARM_instruction_str-instruction_handler
	db	'str~~.w',0x02
	dw	ARM_instruction_str-instruction_handler
	db	'str~~bt',0x00
	dw	ARM_instruction_strbt-instruction_handler
	db	'str~~ht',0x00
	dw	ARM_instruction_strht-instruction_handler
	db	'sub~~.n',0x04
	dw	ARM_instruction_sub-instruction_handler
	db	'sub~~.w',0x02
	dw	ARM_instruction_sub-instruction_handler
	db	'suf~~dm',0x00
	dw	ARM_instruction_sufdm-instruction_handler
	db	'suf~~dp',0x00
	dw	ARM_instruction_sufdp-instruction_handler
	db	'suf~~dz',0x00
	dw	ARM_instruction_sufdz-instruction_handler
	db	'suf~~em',0x00
	dw	ARM_instruction_sufem-instruction_handler
	db	'suf~~ep',0x00
	dw	ARM_instruction_sufep-instruction_handler
	db	'suf~~ez',0x00
	dw	ARM_instruction_sufez-instruction_handler
	db	'suf~~sm',0x00
	dw	ARM_instruction_sufsm-instruction_handler
	db	'suf~~sp',0x00
	dw	ARM_instruction_sufsp-instruction_handler
	db	'suf~~sz',0x00
	dw	ARM_instruction_sufsz-instruction_handler
	db	'svc~~.n',0x04
	dw	ARM_instruction_svc-instruction_handler
	db	'svc~~.w',0x02
	dw	ARM_instruction_svc-instruction_handler
	db	'swi~~.n',0x04
	dw	ARM_instruction_swi-instruction_handler
	db	'swi~~.w',0x02
	dw	ARM_instruction_swi-instruction_handler
	db	'sxtab16',0xe0
	dw	ARM_instruction_sxtab16-instruction_handler
	db	'sxtab~~',0x00
	dw	ARM_instruction_sxtab-instruction_handler
	db	'sxtah~~',0x00
	dw	ARM_instruction_sxtah-instruction_handler
	db	'tan~~dm',0x00
	dw	ARM_instruction_tandm-instruction_handler
	db	'tan~~dp',0x00
	dw	ARM_instruction_tandp-instruction_handler
	db	'tan~~dz',0x00
	dw	ARM_instruction_tandz-instruction_handler
	db	'tan~~em',0x00
	dw	ARM_instruction_tanem-instruction_handler
	db	'tan~~ep',0x00
	dw	ARM_instruction_tanep-instruction_handler
	db	'tan~~ez',0x00
	dw	ARM_instruction_tanez-instruction_handler
	db	'tan~~sm',0x00
	dw	ARM_instruction_tansm-instruction_handler
	db	'tan~~sp',0x00
	dw	ARM_instruction_tansp-instruction_handler
	db	'tan~~sz',0x00
	dw	ARM_instruction_tansz-instruction_handler
	db	'textrcb',0xe0
	dw	ARM_instruction_textrcb-instruction_handler
	db	'textrch',0xe0
	dw	ARM_instruction_textrch-instruction_handler
	db	'textrcw',0xe0
	dw	ARM_instruction_textrcw-instruction_handler
	db	'thumbee',0x00
	dw	ARM_thumbee_directive-instruction_handler
	db	'tmcrr~~',0x00
	dw	ARM_instruction_tmcrr-instruction_handler
	db	'tmrrc~~',0x00
	dw	ARM_instruction_tmrrc-instruction_handler
	db	'torcb~~',0x00
	dw	ARM_instruction_torcb-instruction_handler
	db	'torch~~',0x00
	dw	ARM_instruction_torch-instruction_handler
	db	'torcw~~',0x00
	dw	ARM_instruction_torcw-instruction_handler
	db	'torvscb',0xe0
	dw	ARM_instruction_torvscb-instruction_handler
	db	'torvsch',0xe0
	dw	ARM_instruction_torvsch-instruction_handler
	db	'torvscw',0xe0
	dw	ARM_instruction_torvscw-instruction_handler
	db	'tst~~.n',0x04
	dw	ARM_instruction_tst-instruction_handler
	db	'tst~~.w',0x02
	dw	ARM_instruction_tst-instruction_handler
	db	'uadd8~~',0x00
	dw	ARM_instruction_uadd8-instruction_handler
	db	'uhadd16',0xe0
	dw	ARM_instruction_uhadd16-instruction_handler
	db	'uhasx~~',0x00
	dw	ARM_instruction_uhasx-instruction_handler
	db	'uhsax~~',0x00
	dw	ARM_instruction_uhsax-instruction_handler
	db	'uhsub16',0xe0
	dw	ARM_instruction_uhsub16-instruction_handler
	db	'umaal~~',0x00
	dw	ARM_instruction_umaal-instruction_handler
	db	'umlal~~',0x00
	dw	ARM_instruction_umlal-instruction_handler
	db	'umull~~',0x00
	dw	ARM_instruction_umull-instruction_handler
	db	'und~~.n',0x04
	dw	ARM_instruction_und-instruction_handler
	db	'und~~.w',0x02
	dw	ARM_instruction_und-instruction_handler
	db	'uqadd16',0xe0
	dw	ARM_instruction_uqadd16-instruction_handler
	db	'uqasx~~',0x00
	dw	ARM_instruction_uqasx-instruction_handler
	db	'uqrshrn',0xf0
	dw	ARM_instruction_uqrshrn-instruction_handler
	db	'uqsax~~',0x00
	dw	ARM_instruction_uqsax-instruction_handler
	db	'uqshrn2',0xf0
	dw	ARM_instruction_uqshrn2-instruction_handler
	db	'uqsub16',0xe0
	dw	ARM_instruction_uqsub16-instruction_handler
	db	'urd~~dm',0x00
	dw	ARM_instruction_urddm-instruction_handler
	db	'urd~~dp',0x00
	dw	ARM_instruction_urddp-instruction_handler
	db	'urd~~dz',0x00
	dw	ARM_instruction_urddz-instruction_handler
	db	'urd~~em',0x00
	dw	ARM_instruction_urdem-instruction_handler
	db	'urd~~ep',0x00
	dw	ARM_instruction_urdep-instruction_handler
	db	'urd~~ez',0x00
	dw	ARM_instruction_urdez-instruction_handler
	db	'urd~~sm',0x00
	dw	ARM_instruction_urdsm-instruction_handler
	db	'urd~~sp',0x00
	dw	ARM_instruction_urdsp-instruction_handler
	db	'urd~~sz',0x00
	dw	ARM_instruction_urdsz-instruction_handler
	db	'ursqrte',0xf0
	dw	ARM_instruction_ursqrte-instruction_handler
	db	'usad8~~',0x00
	dw	ARM_instruction_usad8-instruction_handler
	db	'usub8~~',0x00
	dw	ARM_instruction_usub8-instruction_handler
	db	'uxtab16',0xe0
	dw	ARM_instruction_uxtab16-instruction_handler
	db	'uxtab~~',0x00
	dw	ARM_instruction_uxtab-instruction_handler
	db	'uxtah~~',0x00
	dw	ARM_instruction_uxtah-instruction_handler
	db	'vaba.s8',0xe0
	dw	ARM_instruction_vaba.s8-instruction_handler
	db	'vaba.u8',0xe0
	dw	ARM_instruction_vaba.u8-instruction_handler
	db	'vabd.s8',0xe0
	dw	ARM_instruction_vabd.s8-instruction_handler
	db	'vabd.u8',0xe0
	dw	ARM_instruction_vabd.u8-instruction_handler
	db	'vabs.s8',0xe0
	dw	ARM_instruction_vabs.s8-instruction_handler
	db	'vadd.i8',0xe0
	dw	ARM_instruction_vadd.i8-instruction_handler
	db	'vceq.i8',0xe0
	dw	ARM_instruction_vceq.i8-instruction_handler
	db	'vcge.s8',0xe0
	dw	ARM_instruction_vcge.s8-instruction_handler
	db	'vcge.u8',0xe0
	dw	ARM_instruction_vcge.u8-instruction_handler
	db	'vcgt.s8',0xe0
	dw	ARM_instruction_vcgt.s8-instruction_handler
	db	'vcgt.u8',0xe0
	dw	ARM_instruction_vcgt.u8-instruction_handler
	db	'vcle.s8',0xe0
	dw	ARM_instruction_vcle.s8-instruction_handler
	db	'vcle.u8',0xe0
	dw	ARM_instruction_vcle.u8-instruction_handler
	db	'vcls.s8',0xe0
	dw	ARM_instruction_vcls.s8-instruction_handler
	db	'vclt.s8',0xe0
	dw	ARM_instruction_vclt.s8-instruction_handler
	db	'vclt.u8',0xe0
	dw	ARM_instruction_vclt.u8-instruction_handler
	db	'vclz.i8',0xe0
	dw	ARM_instruction_vclz.i8-instruction_handler
	db	'vdup.16',0xe0
	dw	ARM_instruction_vdup.16-instruction_handler
	db	'vdup.32',0xe0
	dw	ARM_instruction_vdup.32-instruction_handler
	db	'vext.16',0xe0
	dw	ARM_instruction_vext.16-instruction_handler
	db	'vext.32',0xe0
	dw	ARM_instruction_vext.32-instruction_handler
	db	'vext.64',0xe0
	dw	ARM_instruction_vext.64-instruction_handler
	db	'virtual',0x00
	dw	virtual_directive-instruction_handler
	db	'vld1.16',0xe0
	dw	ARM_instruction_vld1.16-instruction_handler
	db	'vld1.32',0xe0
	dw	ARM_instruction_vld1.32-instruction_handler
	db	'vld1.64',0xe0
	dw	ARM_instruction_vld1.64-instruction_handler
	db	'vld2.16',0xe0
	dw	ARM_instruction_vld2.16-instruction_handler
	db	'vld2.32',0xe0
	dw	ARM_instruction_vld2.32-instruction_handler
	db	'vld3.16',0xe0
	dw	ARM_instruction_vld3.16-instruction_handler
	db	'vld3.32',0xe0
	dw	ARM_instruction_vld3.32-instruction_handler
	db	'vld4.16',0xe0
	dw	ARM_instruction_vld4.16-instruction_handler
	db	'vld4.32',0xe0
	dw	ARM_instruction_vld4.32-instruction_handler
	db	'vldm.32',0xe0
	dw	ARM_instruction_vldm.32-instruction_handler
	db	'vldm.64',0xe0
	dw	ARM_instruction_vldm.64-instruction_handler
	db	'vldr.32',0xe0
	dw	ARM_instruction_vldr.32-instruction_handler
	db	'vldr.64',0xe0
	dw	ARM_instruction_vldr.64-instruction_handler
	db	'vmax.s8',0xe0
	dw	ARM_instruction_vmax.s8-instruction_handler
	db	'vmax.u8',0xe0
	dw	ARM_instruction_vmax.u8-instruction_handler
	db	'vmin.s8',0xe0
	dw	ARM_instruction_vmin.s8-instruction_handler
	db	'vmin.u8',0xe0
	dw	ARM_instruction_vmin.u8-instruction_handler
	db	'vmla.i8',0xe0
	dw	ARM_instruction_vmla.i8-instruction_handler
	db	'vmla.s8',0xe0
	dw	ARM_instruction_vmla.s8-instruction_handler
	db	'vmla.u8',0xe0
	dw	ARM_instruction_vmla.u8-instruction_handler
	db	'vmls.i8',0xe0
	dw	ARM_instruction_vmls.i8-instruction_handler
	db	'vmls.s8',0xe0
	dw	ARM_instruction_vmls.s8-instruction_handler
	db	'vmls.u8',0xe0
	dw	ARM_instruction_vmls.u8-instruction_handler
	db	'vmov.16',0xe0
	dw	ARM_instruction_vmov.16-instruction_handler
	db	'vmov.32',0xe0
	dw	ARM_instruction_vmov.32-instruction_handler
	db	'vmov.i8',0xe0
	dw	ARM_instruction_vmov.i8-instruction_handler
	db	'vmov.s8',0xe0
	dw	ARM_instruction_vmov.s8-instruction_handler
	db	'vmov.u8',0xe0
	dw	ARM_instruction_vmov.u8-instruction_handler
	db	'vmul.i8',0xe0
	dw	ARM_instruction_vmul.i8-instruction_handler
	db	'vmul.p8',0xe0
	dw	ARM_instruction_vmul.p8-instruction_handler
	db	'vmul.s8',0xe0
	dw	ARM_instruction_vmul.s8-instruction_handler
	db	'vmul.u8',0xe0
	dw	ARM_instruction_vmul.u8-instruction_handler
	db	'vneg.s8',0xe0
	dw	ARM_instruction_vneg.s8-instruction_handler
	db	'vpush~~',0x00
	dw	ARM_instruction_vpush-instruction_handler
	db	'vshl.i8',0xe0
	dw	ARM_instruction_vshl.i8-instruction_handler
	db	'vshl.s8',0xe0
	dw	ARM_instruction_vshl.s8-instruction_handler
	db	'vshl.u8',0xe0
	dw	ARM_instruction_vshl.u8-instruction_handler
	db	'vshr.s8',0xe0
	dw	ARM_instruction_vshr.s8-instruction_handler
	db	'vshr.u8',0xe0
	dw	ARM_instruction_vshr.u8-instruction_handler
	db	'vsli.16',0xe0
	dw	ARM_instruction_vsli.16-instruction_handler
	db	'vsli.32',0xe0
	dw	ARM_instruction_vsli.32-instruction_handler
	db	'vsli.64',0xe0
	dw	ARM_instruction_vsli.64-instruction_handler
	db	'vsra.s8',0xe0
	dw	ARM_instruction_vsra.s8-instruction_handler
	db	'vsra.u8',0xe0
	dw	ARM_instruction_vsra.u8-instruction_handler
	db	'vsri.16',0xe0
	dw	ARM_instruction_vsri.16-instruction_handler
	db	'vsri.32',0xe0
	dw	ARM_instruction_vsri.32-instruction_handler
	db	'vsri.64',0xe0
	dw	ARM_instruction_vsri.64-instruction_handler
	db	'vst1.16',0xe0
	dw	ARM_instruction_vst1.16-instruction_handler
	db	'vst1.32',0xe0
	dw	ARM_instruction_vst1.32-instruction_handler
	db	'vst1.64',0xe0
	dw	ARM_instruction_vst1.64-instruction_handler
	db	'vst2.16',0xe0
	dw	ARM_instruction_vst2.16-instruction_handler
	db	'vst2.32',0xe0
	dw	ARM_instruction_vst2.32-instruction_handler
	db	'vst3.16',0xe0
	dw	ARM_instruction_vst3.16-instruction_handler
	db	'vst3.32',0xe0
	dw	ARM_instruction_vst3.32-instruction_handler
	db	'vst4.16',0xe0
	dw	ARM_instruction_vst4.16-instruction_handler
	db	'vst4.32',0xe0
	dw	ARM_instruction_vst4.32-instruction_handler
	db	'vstm.32',0xe0
	dw	ARM_instruction_vstm.32-instruction_handler
	db	'vstm.64',0xe0
	dw	ARM_instruction_vstm.64-instruction_handler
	db	'vstr.32',0xe0
	dw	ARM_instruction_vstr.32-instruction_handler
	db	'vstr.64',0xe0
	dw	ARM_instruction_vstr.64-instruction_handler
	db	'vsub.i8',0xe0
	dw	ARM_instruction_vsub.i8-instruction_handler
	db	'vtrn.16',0xe0
	dw	ARM_instruction_vtrn.16-instruction_handler
	db	'vtrn.32',0xe0
	dw	ARM_instruction_vtrn.32-instruction_handler
	db	'vtst.16',0xe0
	dw	ARM_instruction_vtst.16-instruction_handler
	db	'vtst.32',0xe0
	dw	ARM_instruction_vtst.32-instruction_handler
	db	'vuzp.16',0xe0
	dw	ARM_instruction_vuzp.16-instruction_handler
	db	'vuzp.32',0xe0
	dw	ARM_instruction_vuzp.32-instruction_handler
	db	'vzip.16',0xe0
	dw	ARM_instruction_vzip.16-instruction_handler
	db	'vzip.32',0xe0
	dw	ARM_instruction_vzip.32-instruction_handler
	db	'wabsb~~',0x00
	dw	ARM_instruction_wabsb-instruction_handler
	db	'wabsh~~',0x00
	dw	ARM_instruction_wabsh-instruction_handler
	db	'wabsw~~',0x00
	dw	ARM_instruction_wabsw-instruction_handler
	db	'waccb~~',0x00
	dw	ARM_instruction_waccb-instruction_handler
	db	'wacch~~',0x00
	dw	ARM_instruction_wacch-instruction_handler
	db	'waccw~~',0x00
	dw	ARM_instruction_waccw-instruction_handler
	db	'waddbss',0xe0
	dw	ARM_instruction_waddbss-instruction_handler
	db	'waddbus',0xe0
	dw	ARM_instruction_waddbus-instruction_handler
	db	'waddb~~',0x00
	dw	ARM_instruction_waddb-instruction_handler
	db	'waddhss',0xe0
	dw	ARM_instruction_waddhss-instruction_handler
	db	'waddhus',0xe0
	dw	ARM_instruction_waddhus-instruction_handler
	db	'waddh~~',0x00
	dw	ARM_instruction_waddh-instruction_handler
	db	'waddwss',0xe0
	dw	ARM_instruction_waddwss-instruction_handler
	db	'waddwus',0xe0
	dw	ARM_instruction_waddwus-instruction_handler
	db	'waddw~~',0x00
	dw	ARM_instruction_waddw-instruction_handler
	db	'waligni',0xe0
	dw	ARM_instruction_waligni-instruction_handler
	db	'wandn~~',0x00
	dw	ARM_instruction_wandn-instruction_handler
	db	'wavg2br',0xe0
	dw	ARM_instruction_wavg2br-instruction_handler
	db	'wavg2hr',0xe0
	dw	ARM_instruction_wavg2hr-instruction_handler
	db	'wavg4~~',0x00
	dw	ARM_instruction_wavg4-instruction_handler
	db	'wcmpeqb',0xe0
	dw	ARM_instruction_wcmpeqb-instruction_handler
	db	'wcmpeqh',0xe0
	dw	ARM_instruction_wcmpeqh-instruction_handler
	db	'wcmpeqw',0xe0
	dw	ARM_instruction_wcmpeqw-instruction_handler
	db	'wfe~~.n',0x04
	dw	ARM_instruction_wfe-instruction_handler
	db	'wfe~~.w',0x02
	dw	ARM_instruction_wfe-instruction_handler
	db	'wfi~~.n',0x04
	dw	ARM_instruction_wfi-instruction_handler
	db	'wfi~~.w',0x02
	dw	ARM_instruction_wfi-instruction_handler
	db	'wldrb~~',0x00
	dw	ARM_instruction_wldrb-instruction_handler
	db	'wldrd~~',0x00
	dw	ARM_instruction_wldrd-instruction_handler
	db	'wldrh~~',0x00
	dw	ARM_instruction_wldrh-instruction_handler
	db	'wldrw~~',0x00
	dw	ARM_instruction_wldrw-instruction_handler
	db	'wmacs~~',0x00
	dw	ARM_instruction_wmacs-instruction_handler
	db	'wmacu~~',0x00
	dw	ARM_instruction_wmacu-instruction_handler
	db	'wmaddsn',0xe0
	dw	ARM_instruction_wmaddsn-instruction_handler
	db	'wmaddsx',0xe0
	dw	ARM_instruction_wmaddsx-instruction_handler
	db	'wmaddun',0xe0
	dw	ARM_instruction_wmaddun-instruction_handler
	db	'wmaddux',0xe0
	dw	ARM_instruction_wmaddux-instruction_handler
	db	'wmiabbn',0xe0
	dw	ARM_instruction_wmiabbn-instruction_handler
	db	'wmiabtn',0xe0
	dw	ARM_instruction_wmiabtn-instruction_handler
	db	'wmiatbn',0xe0
	dw	ARM_instruction_wmiatbn-instruction_handler
	db	'wmiattn',0xe0
	dw	ARM_instruction_wmiattn-instruction_handler
	db	'wmiawbb',0xe0
	dw	ARM_instruction_wmiawbb-instruction_handler
	db	'wmiawbt',0xe0
	dw	ARM_instruction_wmiawbt-instruction_handler
	db	'wmiawtb',0xe0
	dw	ARM_instruction_wmiawtb-instruction_handler
	db	'wmiawtt',0xe0
	dw	ARM_instruction_wmiawtt-instruction_handler
	db	'wmulsmr',0xe0
	dw	ARM_instruction_wmulsmr-instruction_handler
	db	'wmulumr',0xe0
	dw	ARM_instruction_wmulumr-instruction_handler
	db	'wmulwsm',0xe0
	dw	ARM_instruction_wmulwsm-instruction_handler
	db	'wmulwum',0xe0
	dw	ARM_instruction_wmulwum-instruction_handler
	db	'wqmiabb',0xe0
	dw	ARM_instruction_wqmiabb-instruction_handler
	db	'wqmiabt',0xe0
	dw	ARM_instruction_wqmiabt-instruction_handler
	db	'wqmiatb',0xe0
	dw	ARM_instruction_wqmiatb-instruction_handler
	db	'wqmiatt',0xe0
	dw	ARM_instruction_wqmiatt-instruction_handler
	db	'wqmulmr',0xe0
	dw	ARM_instruction_wqmulmr-instruction_handler
	db	'wqmulwm',0xe0
	dw	ARM_instruction_wqmulwm-instruction_handler
	db	'wrord~~',0x00
	dw	ARM_instruction_wrord-instruction_handler
	db	'wrorh~~',0x00
	dw	ARM_instruction_wrorh-instruction_handler
	db	'wrorw~~',0x00
	dw	ARM_instruction_wrorw-instruction_handler
	db	'wsadb~~',0x00
	dw	ARM_instruction_wsadb-instruction_handler
	db	'wsadh~~',0x00
	dw	ARM_instruction_wsadh-instruction_handler
	db	'wslld~~',0x00
	dw	ARM_instruction_wslld-instruction_handler
	db	'wsllh~~',0x00
	dw	ARM_instruction_wsllh-instruction_handler
	db	'wsllw~~',0x00
	dw	ARM_instruction_wsllw-instruction_handler
	db	'wsrad~~',0x00
	dw	ARM_instruction_wsrad-instruction_handler
	db	'wsrah~~',0x00
	dw	ARM_instruction_wsrah-instruction_handler
	db	'wsraw~~',0x00
	dw	ARM_instruction_wsraw-instruction_handler
	db	'wsrld~~',0x00
	dw	ARM_instruction_wsrld-instruction_handler
	db	'wsrlh~~',0x00
	dw	ARM_instruction_wsrlh-instruction_handler
	db	'wsrlw~~',0x00
	dw	ARM_instruction_wsrlw-instruction_handler
	db	'wstrb~~',0x00
	dw	ARM_instruction_wstrb-instruction_handler
	db	'wstrd~~',0x00
	dw	ARM_instruction_wstrd-instruction_handler
	db	'wstrh~~',0x00
	dw	ARM_instruction_wstrh-instruction_handler
	db	'wstrw~~',0x00
	dw	ARM_instruction_wstrw-instruction_handler
	db	'wsubbss',0xe0
	dw	ARM_instruction_wsubbss-instruction_handler
	db	'wsubbus',0xe0
	dw	ARM_instruction_wsubbus-instruction_handler
	db	'wsubb~~',0x00
	dw	ARM_instruction_wsubb-instruction_handler
	db	'wsubhss',0xe0
	dw	ARM_instruction_wsubhss-instruction_handler
	db	'wsubhus',0xe0
	dw	ARM_instruction_wsubhus-instruction_handler
	db	'wsubh~~',0x00
	dw	ARM_instruction_wsubh-instruction_handler
	db	'wsubwss',0xe0
	dw	ARM_instruction_wsubwss-instruction_handler
	db	'wsubwus',0xe0
	dw	ARM_instruction_wsubwus-instruction_handler
	db	'wsubw~~',0x00
	dw	ARM_instruction_wsubw-instruction_handler
	db	'wzero~~',0x00
	dw	ARM_instruction_wzero-instruction_handler
	db	'yield.n',0xe4
	dw	ARM_instruction_yield-instruction_handler
	db	'yield.w',0xe2
	dw	ARM_instruction_yield-instruction_handler
	db	'yield~~',0x00
	dw	ARM_instruction_yield-instruction_handler
	db	0
instructions_8:
	db	'adcs~~.n',0x05
	dw	ARM_instruction_adc-instruction_handler
	db	'adcs~~.w',0x03
	dw	ARM_instruction_adc-instruction_handler
	db	'adc~~s.n',0x05
	dw	ARM_instruction_adc-instruction_handler
	db	'adc~~s.w',0x03
	dw	ARM_instruction_adc-instruction_handler
	db	'adds~~.n',0x05
	dw	ARM_instruction_add-instruction_handler
	db	'adds~~.w',0x03
	dw	ARM_instruction_add-instruction_handler
	db	'add~~s.n',0x05
	dw	ARM_instruction_add-instruction_handler
	db	'add~~s.w',0x03
	dw	ARM_instruction_add-instruction_handler
	db	'aesimc.8',0xf0
	dw	ARM_instruction_aesimc.8-instruction_handler
	db	'ands~~.n',0x05
	dw	ARM_instruction_and-instruction_handler
	db	'ands~~.w',0x03
	dw	ARM_instruction_and-instruction_handler
	db	'and~~s.n',0x05
	dw	ARM_instruction_and-instruction_handler
	db	'and~~s.w',0x03
	dw	ARM_instruction_and-instruction_handler
	db	'asrs~~.n',0x05
	dw	ARM_instruction_asr-instruction_handler
	db	'asrs~~.w',0x03
	dw	ARM_instruction_asr-instruction_handler
	db	'asr~~s.n',0x05
	dw	ARM_instruction_asr-instruction_handler
	db	'asr~~s.w',0x03
	dw	ARM_instruction_asr-instruction_handler
	db	'bics~~.n',0x05
	dw	ARM_instruction_bic-instruction_handler
	db	'bics~~.w',0x03
	dw	ARM_instruction_bic-instruction_handler
	db	'bic~~s.n',0x05
	dw	ARM_instruction_bic-instruction_handler
	db	'bic~~s.w',0x03
	dw	ARM_instruction_bic-instruction_handler
	db	'cfabsd~~',0x00
	dw	ARM_instruction_cfabsd-instruction_handler
	db	'cfabss~~',0x00
	dw	ARM_instruction_cfabss-instruction_handler
	db	'cfaddd~~',0x00
	dw	ARM_instruction_cfaddd-instruction_handler
	db	'cfadds~~',0x00
	dw	ARM_instruction_cfadds-instruction_handler
	db	'cfcmpd~~',0x00
	dw	ARM_instruction_cfcmpd-instruction_handler
	db	'cfcmps~~',0x00
	dw	ARM_instruction_cfcmps-instruction_handler
	db	'cfcpyd~~',0x00
	dw	ARM_instruction_cfcpyd-instruction_handler
	db	'cfcpys~~',0x00
	dw	ARM_instruction_cfcpys-instruction_handler
	db	'cfcvt32d',0xe0
	dw	ARM_instruction_cfcvt32d-instruction_handler
	db	'cfcvt32s',0xe0
	dw	ARM_instruction_cfcvt32s-instruction_handler
	db	'cfcvt64d',0xe0
	dw	ARM_instruction_cfcvt64d-instruction_handler
	db	'cfcvt64s',0xe0
	dw	ARM_instruction_cfcvt64s-instruction_handler
	db	'cfcvtd32',0xe0
	dw	ARM_instruction_cfcvtd32-instruction_handler
	db	'cfcvts32',0xe0
	dw	ARM_instruction_cfcvts32-instruction_handler
	db	'cfldrd~~',0x00
	dw	ARM_instruction_cfldrd-instruction_handler
	db	'cfldrs~~',0x00
	dw	ARM_instruction_cfldrs-instruction_handler
	db	'cfmadd32',0xe0
	dw	ARM_instruction_cfmadd32-instruction_handler
	db	'cfmsub32',0xe0
	dw	ARM_instruction_cfmsub32-instruction_handler
	db	'cfmuld~~',0x00
	dw	ARM_instruction_cfmuld-instruction_handler
	db	'cfmuls~~',0x00
	dw	ARM_instruction_cfmuls-instruction_handler
	db	'cfmv32ah',0xe0
	dw	ARM_instruction_cfmv32ah-instruction_handler
	db	'cfmv32al',0xe0
	dw	ARM_instruction_cfmv32al-instruction_handler
	db	'cfmv32am',0xe0
	dw	ARM_instruction_cfmv32am-instruction_handler
	db	'cfmv32sc',0xe0
	dw	ARM_instruction_cfmv32sc-instruction_handler
	db	'cfmv64hr',0xe0
	dw	ARM_instruction_cfmv64hr-instruction_handler
	db	'cfmv64lr',0xe0
	dw	ARM_instruction_cfmv64lr-instruction_handler
	db	'cfmvah32',0xe0
	dw	ARM_instruction_cfmvah32-instruction_handler
	db	'cfmval32',0xe0
	dw	ARM_instruction_cfmval32-instruction_handler
	db	'cfmvam32',0xe0
	dw	ARM_instruction_cfmvam32-instruction_handler
	db	'cfmvr64h',0xe0
	dw	ARM_instruction_cfmvr64h-instruction_handler
	db	'cfmvr64l',0xe0
	dw	ARM_instruction_cfmvr64l-instruction_handler
	db	'cfmvrs~~',0x00
	dw	ARM_instruction_cfmvrs-instruction_handler
	db	'cfmvsc32',0xe0
	dw	ARM_instruction_cfmvsc32-instruction_handler
	db	'cfmvsr~~',0x00
	dw	ARM_instruction_cfmvsr-instruction_handler
	db	'cfnegd~~',0x00
	dw	ARM_instruction_cfnegd-instruction_handler
	db	'cfnegs~~',0x00
	dw	ARM_instruction_cfnegs-instruction_handler
	db	'cfrshl32',0xe0
	dw	ARM_instruction_cfrshl32-instruction_handler
	db	'cfrshl64',0xe0
	dw	ARM_instruction_cfrshl64-instruction_handler
	db	'cfsh32~~',0x00
	dw	ARM_instruction_cfsh32-instruction_handler
	db	'cfsh64~~',0x00
	dw	ARM_instruction_cfsh64-instruction_handler
	db	'cfstrd~~',0x00
	dw	ARM_instruction_cfstrd-instruction_handler
	db	'cfstrs~~',0x00
	dw	ARM_instruction_cfstrs-instruction_handler
	db	'cfsubd~~',0x00
	dw	ARM_instruction_cfsubd-instruction_handler
	db	'cfsubs~~',0x00
	dw	ARM_instruction_cfsubs-instruction_handler
	db	'eors~~.n',0x05
	dw	ARM_instruction_eor-instruction_handler
	db	'eors~~.w',0x03
	dw	ARM_instruction_eor-instruction_handler
	db	'eor~~s.n',0x05
	dw	ARM_instruction_eor-instruction_handler
	db	'eor~~s.w',0x03
	dw	ARM_instruction_eor-instruction_handler
	db	'fcmped~~',0x00
	dw	ARM_instruction_fcmped-instruction_handler
	db	'fcmpes~~',0x00
	dw	ARM_instruction_fcmpes-instruction_handler
	db	'fcmpzd~~',0x00
	dw	ARM_instruction_fcmpzd-instruction_handler
	db	'fcmpzs~~',0x00
	dw	ARM_instruction_fcmpzs-instruction_handler
	db	'fcvtds~~',0x00
	dw	ARM_instruction_fcvtds-instruction_handler
	db	'fcvtsd~~',0x00
	dw	ARM_instruction_fcvtsd-instruction_handler
	db	'fmstat~~',0x00
	dw	ARM_instruction_fmstat-instruction_handler
	db	'fnmacd~~',0x00
	dw	ARM_instruction_fnmacd-instruction_handler
	db	'fnmacs~~',0x00
	dw	ARM_instruction_fnmacs-instruction_handler
	db	'fnmscd~~',0x00
	dw	ARM_instruction_fnmscd-instruction_handler
	db	'fnmscs~~',0x00
	dw	ARM_instruction_fnmscs-instruction_handler
	db	'fnmuld~~',0x00
	dw	ARM_instruction_fnmuld-instruction_handler
	db	'fnmuls~~',0x00
	dw	ARM_instruction_fnmuls-instruction_handler
	db	'fshtod~~',0x00
	dw	ARM_instruction_fshtod-instruction_handler
	db	'fshtos~~',0x00
	dw	ARM_instruction_fshtos-instruction_handler
	db	'fsitod~~',0x00
	dw	ARM_instruction_fsitod-instruction_handler
	db	'fsitos~~',0x00
	dw	ARM_instruction_fsitos-instruction_handler
	db	'fsltod~~',0x00
	dw	ARM_instruction_fsltod-instruction_handler
	db	'fsltos~~',0x00
	dw	ARM_instruction_fsltos-instruction_handler
	db	'fsqrtd~~',0x00
	dw	ARM_instruction_fsqrtd-instruction_handler
	db	'fsqrts~~',0x00
	dw	ARM_instruction_fsqrts-instruction_handler
	db	'ftoshd~~',0x00
	dw	ARM_instruction_ftoshd-instruction_handler
	db	'ftoshs~~',0x00
	dw	ARM_instruction_ftoshs-instruction_handler
	db	'ftosid~~',0x00
	dw	ARM_instruction_ftosid-instruction_handler
	db	'ftosis~~',0x00
	dw	ARM_instruction_ftosis-instruction_handler
	db	'ftosld~~',0x00
	dw	ARM_instruction_ftosld-instruction_handler
	db	'ftosls~~',0x00
	dw	ARM_instruction_ftosls-instruction_handler
	db	'ftouhd~~',0x00
	dw	ARM_instruction_ftouhd-instruction_handler
	db	'ftouhs~~',0x00
	dw	ARM_instruction_ftouhs-instruction_handler
	db	'ftouid~~',0x00
	dw	ARM_instruction_ftouid-instruction_handler
	db	'ftouis~~',0x00
	dw	ARM_instruction_ftouis-instruction_handler
	db	'ftould~~',0x00
	dw	ARM_instruction_ftould-instruction_handler
	db	'ftouls~~',0x00
	dw	ARM_instruction_ftouls-instruction_handler
	db	'fuhtod~~',0x00
	dw	ARM_instruction_fuhtod-instruction_handler
	db	'fuhtos~~',0x00
	dw	ARM_instruction_fuhtos-instruction_handler
	db	'fuitod~~',0x00
	dw	ARM_instruction_fuitod-instruction_handler
	db	'fuitos~~',0x00
	dw	ARM_instruction_fuitos-instruction_handler
	db	'fultod~~',0x00
	dw	ARM_instruction_fultod-instruction_handler
	db	'fultos~~',0x00
	dw	ARM_instruction_fultos-instruction_handler
	db	'ldaexb~~',0x00
	dw	ARM_instruction_ldaexb-instruction_handler
	db	'ldaexd~~',0x00
	dw	ARM_instruction_ldaexd-instruction_handler
	db	'ldaexh~~',0x00
	dw	ARM_instruction_ldaexh-instruction_handler
	db	'ldaex~~b',0x00
	dw	ARM_instruction_ldaexb-instruction_handler
	db	'ldaex~~d',0x00
	dw	ARM_instruction_ldaexd-instruction_handler
	db	'ldaex~~h',0x00
	dw	ARM_instruction_ldaexh-instruction_handler
	db	'ldrb~~.n',0x04
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldrb~~.w',0x02
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldrexb~~',0x00
	dw	ARM_instruction_ldrexb-instruction_handler
	db	'ldrexd~~',0x00
	dw	ARM_instruction_ldrexd-instruction_handler
	db	'ldrexh~~',0x00
	dw	ARM_instruction_ldrexh-instruction_handler
	db	'ldrh~~.n',0x04
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldrh~~.w',0x02
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldrsbt~~',0x00
	dw	ARM_instruction_ldrsbt-instruction_handler
	db	'ldrsht~~',0x00
	dw	ARM_instruction_ldrsht-instruction_handler
	db	'ldr~~b.n',0x04
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldr~~b.w',0x02
	dw	ARM_instruction_ldrb-instruction_handler
	db	'ldr~~h.n',0x04
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldr~~h.w',0x02
	dw	ARM_instruction_ldrh-instruction_handler
	db	'ldr~~sbt',0x00
	dw	ARM_instruction_ldrsbt-instruction_handler
	db	'ldr~~sht',0x00
	dw	ARM_instruction_ldrsht-instruction_handler
	db	'lsls~~.n',0x05
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsls~~.w',0x03
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsl~~s.n',0x05
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsl~~s.w',0x03
	dw	ARM_instruction_lsl-instruction_handler
	db	'lsrs~~.n',0x05
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsrs~~.w',0x03
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsr~~s.n',0x05
	dw	ARM_instruction_lsr-instruction_handler
	db	'lsr~~s.w',0x03
	dw	ARM_instruction_lsr-instruction_handler
	db	'movs~~.n',0x05
	dw	ARM_instruction_mov-instruction_handler
	db	'movs~~.w',0x03
	dw	ARM_instruction_mov-instruction_handler
	db	'mov~~s.n',0x05
	dw	ARM_instruction_mov-instruction_handler
	db	'mov~~s.w',0x03
	dw	ARM_instruction_mov-instruction_handler
	db	'muls~~.n',0x05
	dw	ARM_instruction_mul-instruction_handler
	db	'muls~~.w',0x03
	dw	ARM_instruction_mul-instruction_handler
	db	'mul~~s.n',0x05
	dw	ARM_instruction_mul-instruction_handler
	db	'mul~~s.w',0x03
	dw	ARM_instruction_mul-instruction_handler
	db	'mvns~~.n',0x05
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvns~~.w',0x03
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvn~~s.n',0x05
	dw	ARM_instruction_mvn-instruction_handler
	db	'mvn~~s.w',0x03
	dw	ARM_instruction_mvn-instruction_handler
	db	'negs~~.n',0x05
	dw	ARM_instruction_neg-instruction_handler
	db	'negs~~.w',0x03
	dw	ARM_instruction_neg-instruction_handler
	db	'neg~~s.n',0x05
	dw	ARM_instruction_neg-instruction_handler
	db	'neg~~s.w',0x03
	dw	ARM_instruction_neg-instruction_handler
	db	'orrs~~.n',0x05
	dw	ARM_instruction_orr-instruction_handler
	db	'orrs~~.w',0x03
	dw	ARM_instruction_orr-instruction_handler
	db	'orr~~s.n',0x05
	dw	ARM_instruction_orr-instruction_handler
	db	'orr~~s.w',0x03
	dw	ARM_instruction_orr-instruction_handler
	db	'push~~.n',0x04
	dw	ARM_instruction_push-instruction_handler
	db	'push~~.w',0x02
	dw	ARM_instruction_push-instruction_handler
	db	'qadd16~~',0x00
	dw	ARM_instruction_qadd16-instruction_handler
	db	'qaddsubx',0xe0
	dw	ARM_instruction_qaddsubx-instruction_handler
	db	'qsub16~~',0x00
	dw	ARM_instruction_qsub16-instruction_handler
	db	'qsubaddx',0xe0
	dw	ARM_instruction_qsubaddx-instruction_handler
	db	'rors~~.n',0x05
	dw	ARM_instruction_ror-instruction_handler
	db	'rors~~.w',0x03
	dw	ARM_instruction_ror-instruction_handler
	db	'ror~~s.n',0x05
	dw	ARM_instruction_ror-instruction_handler
	db	'ror~~s.w',0x03
	dw	ARM_instruction_ror-instruction_handler
	db	'rsbs~~.n',0x05
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsbs~~.w',0x03
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsb~~s.n',0x05
	dw	ARM_instruction_rsb-instruction_handler
	db	'rsb~~s.w',0x03
	dw	ARM_instruction_rsb-instruction_handler
	db	'sadd16~~',0x00
	dw	ARM_instruction_sadd16-instruction_handler
	db	'saddsubx',0xe0
	dw	ARM_instruction_saddsubx-instruction_handler
	db	'sbcs~~.n',0x05
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbcs~~.w',0x03
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbc~~s.n',0x05
	dw	ARM_instruction_sbc-instruction_handler
	db	'sbc~~s.w',0x03
	dw	ARM_instruction_sbc-instruction_handler
	db	'sevl~~.n',0x04
	dw	ARM_instruction_sevl-instruction_handler
	db	'sevl~~.w',0x02
	dw	ARM_instruction_sevl-instruction_handler
	db	'sha1c.32',0xf0
	dw	ARM_instruction_sha1c.32-instruction_handler
	db	'sha1h.32',0xf0
	dw	ARM_instruction_sha1h.32-instruction_handler
	db	'sha1m.32',0xf0
	dw	ARM_instruction_sha1m.32-instruction_handler
	db	'sha1p.32',0xf0
	dw	ARM_instruction_sha1p.32-instruction_handler
	db	'sha256h2',0xf0
	dw	ARM_instruction_sha256h2-instruction_handler
	db	'shadd8~~',0x00
	dw	ARM_instruction_shadd8-instruction_handler
	db	'shsub8~~',0x00
	dw	ARM_instruction_shsub8-instruction_handler
	db	'smlabb~~',0x00
	dw	ARM_instruction_smlabb-instruction_handler
	db	'smlabt~~',0x00
	dw	ARM_instruction_smlabt-instruction_handler
	db	'smladx~~',0x00
	dw	ARM_instruction_smladx-instruction_handler
	db	'smlald~~',0x00
	dw	ARM_instruction_smlald-instruction_handler
	db	'smlals~~',0x01
	dw	ARM_instruction_smlal-instruction_handler
	db	'smlal~~s',0x01
	dw	ARM_instruction_smlal-instruction_handler
	db	'smlatb~~',0x00
	dw	ARM_instruction_smlatb-instruction_handler
	db	'smlatt~~',0x00
	dw	ARM_instruction_smlatt-instruction_handler
	db	'smlawb~~',0x00
	dw	ARM_instruction_smlawb-instruction_handler
	db	'smlawt~~',0x00
	dw	ARM_instruction_smlawt-instruction_handler
	db	'smlsdx~~',0x00
	dw	ARM_instruction_smlsdx-instruction_handler
	db	'smlsld~~',0x00
	dw	ARM_instruction_smlsld-instruction_handler
	db	'smmlar~~',0x00
	dw	ARM_instruction_smmlar-instruction_handler
	db	'smmlsr~~',0x00
	dw	ARM_instruction_smmlsr-instruction_handler
	db	'smmulr~~',0x00
	dw	ARM_instruction_smmulr-instruction_handler
	db	'smuadx~~',0x00
	dw	ARM_instruction_smuadx-instruction_handler
	db	'smulbb~~',0x00
	dw	ARM_instruction_smulbb-instruction_handler
	db	'smulbt~~',0x00
	dw	ARM_instruction_smulbt-instruction_handler
	db	'smulls~~',0x01
	dw	ARM_instruction_smull-instruction_handler
	db	'smull~~s',0x01
	dw	ARM_instruction_smull-instruction_handler
	db	'smultb~~',0x00
	dw	ARM_instruction_smultb-instruction_handler
	db	'smultt~~',0x00
	dw	ARM_instruction_smultt-instruction_handler
	db	'smulwb~~',0x00
	dw	ARM_instruction_smulwb-instruction_handler
	db	'smulwt~~',0x00
	dw	ARM_instruction_smulwt-instruction_handler
	db	'smusdx~~',0x00
	dw	ARM_instruction_smusdx-instruction_handler
	db	'sqdmlal2',0xf0
	dw	ARM_instruction_sqdmlal2-instruction_handler
	db	'sqdmlsl2',0xf0
	dw	ARM_instruction_sqdmlsl2-instruction_handler
	db	'sqdmull2',0xf0
	dw	ARM_instruction_sqdmull2-instruction_handler
	db	'sqrdmulh',0xf0
	dw	ARM_instruction_sqrdmulh-instruction_handler
	db	'sqrshrn2',0xf0
	dw	ARM_instruction_sqrshrn2-instruction_handler
	db	'sqrshrun',0xf0
	dw	ARM_instruction_sqrshrun-instruction_handler
	db	'sqshrun2',0xf0
	dw	ARM_instruction_sqshrun2-instruction_handler
	db	'ssat16~~',0x00
	dw	ARM_instruction_ssat16-instruction_handler
	db	'ssub16~~',0x00
	dw	ARM_instruction_ssub16-instruction_handler
	db	'ssubaddx',0xe0
	dw	ARM_instruction_ssubaddx-instruction_handler
	db	'stlexb~~',0x00
	dw	ARM_instruction_stlexb-instruction_handler
	db	'stlexd~~',0x00
	dw	ARM_instruction_stlexd-instruction_handler
	db	'stlexh~~',0x00
	dw	ARM_instruction_stlexh-instruction_handler
	db	'stlex~~b',0x00
	dw	ARM_instruction_stlexb-instruction_handler
	db	'stlex~~d',0x00
	dw	ARM_instruction_stlexd-instruction_handler
	db	'stlex~~h',0x00
	dw	ARM_instruction_stlexh-instruction_handler
	db	'strb~~.n',0x04
	dw	ARM_instruction_strb-instruction_handler
	db	'strb~~.w',0x02
	dw	ARM_instruction_strb-instruction_handler
	db	'strexb~~',0x00
	dw	ARM_instruction_strexb-instruction_handler
	db	'strexd~~',0x00
	dw	ARM_instruction_strexd-instruction_handler
	db	'strexh~~',0x00
	dw	ARM_instruction_strexh-instruction_handler
	db	'strh~~.n',0x04
	dw	ARM_instruction_strh-instruction_handler
	db	'strh~~.w',0x02
	dw	ARM_instruction_strh-instruction_handler
	db	'str~~b.n',0x04
	dw	ARM_instruction_strb-instruction_handler
	db	'str~~b.w',0x02
	dw	ARM_instruction_strb-instruction_handler
	db	'str~~h.n',0x04
	dw	ARM_instruction_strh-instruction_handler
	db	'str~~h.w',0x02
	dw	ARM_instruction_strh-instruction_handler
	db	'subs~~.n',0x05
	dw	ARM_instruction_sub-instruction_handler
	db	'subs~~.w',0x03
	dw	ARM_instruction_sub-instruction_handler
	db	'sub~~s.n',0x05
	dw	ARM_instruction_sub-instruction_handler
	db	'sub~~s.w',0x03
	dw	ARM_instruction_sub-instruction_handler
	db	'sxtb16~~',0x00
	dw	ARM_instruction_sxtb16-instruction_handler
	db	'sxtb~~.n',0x04
	dw	ARM_instruction_sxtb-instruction_handler
	db	'sxtb~~.w',0x02
	dw	ARM_instruction_sxtb-instruction_handler
	db	'sxth~~.n',0x04
	dw	ARM_instruction_sxth-instruction_handler
	db	'sxth~~.w',0x02
	dw	ARM_instruction_sxth-instruction_handler
	db	'tandcb~~',0x00
	dw	ARM_instruction_tandcb-instruction_handler
	db	'tandch~~',0x00
	dw	ARM_instruction_tandch-instruction_handler
	db	'tandcw~~',0x00
	dw	ARM_instruction_tandcw-instruction_handler
	db	'tbcstb~~',0x00
	dw	ARM_instruction_tbcstb-instruction_handler
	db	'tbcsth~~',0x00
	dw	ARM_instruction_tbcsth-instruction_handler
	db	'tbcstw~~',0x00
	dw	ARM_instruction_tbcstw-instruction_handler
	db	'textrmsb',0xe0
	dw	ARM_instruction_textrmsb-instruction_handler
	db	'textrmsh',0xe0
	dw	ARM_instruction_textrmsh-instruction_handler
	db	'textrmsw',0xe0
	dw	ARM_instruction_textrmsw-instruction_handler
	db	'textrmub',0xe0
	dw	ARM_instruction_textrmub-instruction_handler
	db	'textrmuh',0xe0
	dw	ARM_instruction_textrmuh-instruction_handler
	db	'textrmuw',0xe0
	dw	ARM_instruction_textrmuw-instruction_handler
	db	'tinsrb~~',0x00
	dw	ARM_instruction_tinsrb-instruction_handler
	db	'tinsrh~~',0x00
	dw	ARM_instruction_tinsrh-instruction_handler
	db	'tinsrw~~',0x00
	dw	ARM_instruction_tinsrw-instruction_handler
	db	'tmiabb~~',0x00
	dw	ARM_instruction_tmiabb-instruction_handler
	db	'tmiabt~~',0x00
	dw	ARM_instruction_tmiabt-instruction_handler
	db	'tmiaph~~',0x00
	dw	ARM_instruction_tmiaph-instruction_handler
	db	'tmiatb~~',0x00
	dw	ARM_instruction_tmiatb-instruction_handler
	db	'tmiatt~~',0x00
	dw	ARM_instruction_tmiatt-instruction_handler
	db	'tmovmskb',0xe0
	dw	ARM_instruction_tmovmskb-instruction_handler
	db	'tmovmskh',0xe0
	dw	ARM_instruction_tmovmskh-instruction_handler
	db	'tmovmskw',0xe0
	dw	ARM_instruction_tmovmskw-instruction_handler
	db	'uadd16~~',0x00
	dw	ARM_instruction_uadd16-instruction_handler
	db	'uaddsubx',0xe0
	dw	ARM_instruction_uaddsubx-instruction_handler
	db	'uhadd8~~',0x00
	dw	ARM_instruction_uhadd8-instruction_handler
	db	'uhsub8~~',0x00
	dw	ARM_instruction_uhsub8-instruction_handler
	db	'umlals~~',0x01
	dw	ARM_instruction_umlal-instruction_handler
	db	'umlal~~s',0x01
	dw	ARM_instruction_umlal-instruction_handler
	db	'umulls~~',0x01
	dw	ARM_instruction_umull-instruction_handler
	db	'umull~~s',0x01
	dw	ARM_instruction_umull-instruction_handler
	db	'uqadd8~~',0x00
	dw	ARM_instruction_uqadd8-instruction_handler
	db	'uqrshrn2',0xf0
	dw	ARM_instruction_uqrshrn2-instruction_handler
	db	'uqsub8~~',0x00
	dw	ARM_instruction_uqsub8-instruction_handler
	db	'usada8~~',0x00
	dw	ARM_instruction_usada8-instruction_handler
	db	'usat16~~',0x00
	dw	ARM_instruction_usat16-instruction_handler
	db	'usub16~~',0x00
	dw	ARM_instruction_usub16-instruction_handler
	db	'usubaddx',0xe0
	dw	ARM_instruction_usubaddx-instruction_handler
	db	'uxtb16~~',0x00
	dw	ARM_instruction_uxtb16-instruction_handler
	db	'uxtb~~.n',0x04
	dw	ARM_instruction_uxtb-instruction_handler
	db	'uxtb~~.w',0x02
	dw	ARM_instruction_uxtb-instruction_handler
	db	'uxth~~.n',0x04
	dw	ARM_instruction_uxth-instruction_handler
	db	'uxth~~.w',0x02
	dw	ARM_instruction_uxth-instruction_handler
	db	'vaba.s16',0xe0
	dw	ARM_instruction_vaba.s16-instruction_handler
	db	'vaba.s32',0xe0
	dw	ARM_instruction_vaba.s32-instruction_handler
	db	'vaba.u16',0xe0
	dw	ARM_instruction_vaba.u16-instruction_handler
	db	'vaba.u32',0xe0
	dw	ARM_instruction_vaba.u32-instruction_handler
	db	'vabal.s8',0xe0
	dw	ARM_instruction_vabal.s8-instruction_handler
	db	'vabal.u8',0xe0
	dw	ARM_instruction_vabal.u8-instruction_handler
	db	'vabd.f32',0xe0
	dw	ARM_instruction_vabd.f32-instruction_handler
	db	'vabd.s16',0xe0
	dw	ARM_instruction_vabd.s16-instruction_handler
	db	'vabd.s32',0xe0
	dw	ARM_instruction_vabd.s32-instruction_handler
	db	'vabd.u16',0xe0
	dw	ARM_instruction_vabd.u16-instruction_handler
	db	'vabd.u32',0xe0
	dw	ARM_instruction_vabd.u32-instruction_handler
	db	'vabdl.s8',0xe0
	dw	ARM_instruction_vabdl.s8-instruction_handler
	db	'vabdl.u8',0xe0
	dw	ARM_instruction_vabdl.u8-instruction_handler
	db	'vabs.f32',0xe0
	dw	ARM_instruction_vabs.f32-instruction_handler
	db	'vabs.f64',0xe0
	dw	ARM_instruction_vabs.f64-instruction_handler
	db	'vabs.s16',0xe0
	dw	ARM_instruction_vabs.s16-instruction_handler
	db	'vabs.s32',0xe0
	dw	ARM_instruction_vabs.s32-instruction_handler
	db	'vadd.f32',0xe0
	dw	ARM_instruction_vadd.f32-instruction_handler
	db	'vadd.f64',0xe0
	dw	ARM_instruction_vadd.f64-instruction_handler
	db	'vadd.i16',0xe0
	dw	ARM_instruction_vadd.i16-instruction_handler
	db	'vadd.i32',0xe0
	dw	ARM_instruction_vadd.i32-instruction_handler
	db	'vadd.i64',0xe0
	dw	ARM_instruction_vadd.i64-instruction_handler
	db	'vaddl.s8',0xe0
	dw	ARM_instruction_vaddl.s8-instruction_handler
	db	'vaddl.u8',0xe0
	dw	ARM_instruction_vaddl.u8-instruction_handler
	db	'vaddw.s8',0xe0
	dw	ARM_instruction_vaddw.s8-instruction_handler
	db	'vaddw.u8',0xe0
	dw	ARM_instruction_vaddw.u8-instruction_handler
	db	'vand.i16',0xe0
	dw	ARM_instruction_vand.i16-instruction_handler
	db	'vand.i32',0xe0
	dw	ARM_instruction_vand.i32-instruction_handler
	db	'vbic.i16',0xe0
	dw	ARM_instruction_vbic.i16-instruction_handler
	db	'vbic.i32',0xe0
	dw	ARM_instruction_vbic.i32-instruction_handler
	db	'vceq.f32',0xe0
	dw	ARM_instruction_vceq.f32-instruction_handler
	db	'vceq.i16',0xe0
	dw	ARM_instruction_vceq.i16-instruction_handler
	db	'vceq.i32',0xe0
	dw	ARM_instruction_vceq.i32-instruction_handler
	db	'vcge.f32',0xe0
	dw	ARM_instruction_vcge.f32-instruction_handler
	db	'vcge.s16',0xe0
	dw	ARM_instruction_vcge.s16-instruction_handler
	db	'vcge.s32',0xe0
	dw	ARM_instruction_vcge.s32-instruction_handler
	db	'vcge.u16',0xe0
	dw	ARM_instruction_vcge.u16-instruction_handler
	db	'vcge.u32',0xe0
	dw	ARM_instruction_vcge.u32-instruction_handler
	db	'vcgt.f32',0xe0
	dw	ARM_instruction_vcgt.f32-instruction_handler
	db	'vcgt.s16',0xe0
	dw	ARM_instruction_vcgt.s16-instruction_handler
	db	'vcgt.s32',0xe0
	dw	ARM_instruction_vcgt.s32-instruction_handler
	db	'vcgt.u16',0xe0
	dw	ARM_instruction_vcgt.u16-instruction_handler
	db	'vcgt.u32',0xe0
	dw	ARM_instruction_vcgt.u32-instruction_handler
	db	'vcle.f32',0xe0
	dw	ARM_instruction_vcle.f32-instruction_handler
	db	'vcle.s16',0xe0
	dw	ARM_instruction_vcle.s16-instruction_handler
	db	'vcle.s32',0xe0
	dw	ARM_instruction_vcle.s32-instruction_handler
	db	'vcle.u16',0xe0
	dw	ARM_instruction_vcle.u16-instruction_handler
	db	'vcle.u32',0xe0
	dw	ARM_instruction_vcle.u32-instruction_handler
	db	'vcls.s16',0xe0
	dw	ARM_instruction_vcls.s16-instruction_handler
	db	'vcls.s32',0xe0
	dw	ARM_instruction_vcls.s32-instruction_handler
	db	'vclt.f32',0xe0
	dw	ARM_instruction_vclt.f32-instruction_handler
	db	'vclt.s16',0xe0
	dw	ARM_instruction_vclt.s16-instruction_handler
	db	'vclt.s32',0xe0
	dw	ARM_instruction_vclt.s32-instruction_handler
	db	'vclt.u16',0xe0
	dw	ARM_instruction_vclt.u16-instruction_handler
	db	'vclt.u32',0xe0
	dw	ARM_instruction_vclt.u32-instruction_handler
	db	'vclz.i16',0xe0
	dw	ARM_instruction_vclz.i16-instruction_handler
	db	'vclz.i32',0xe0
	dw	ARM_instruction_vclz.i32-instruction_handler
	db	'vcmp.f32',0xe0
	dw	ARM_instruction_vcmp.f32-instruction_handler
	db	'vcmp.f64',0xe0
	dw	ARM_instruction_vcmp.f64-instruction_handler
	db	'vcnt~~.8',0x00
	dw	ARM_instruction_vcnt.8-instruction_handler
	db	'vdiv.f32',0xe0
	dw	ARM_instruction_vdiv.f32-instruction_handler
	db	'vdiv.f64',0xe0
	dw	ARM_instruction_vdiv.f64-instruction_handler
	db	'vdup~~.8',0x00
	dw	ARM_instruction_vdup.8-instruction_handler
	db	'vext~~.8',0x00
	dw	ARM_instruction_vext.8-instruction_handler
	db	'vfma.f32',0xe0
	dw	ARM_instruction_vfma.f32-instruction_handler
	db	'vfma.f64',0xe0
	dw	ARM_instruction_vfma.f64-instruction_handler
	db	'vfms.f32',0xe0
	dw	ARM_instruction_vfms.f32-instruction_handler
	db	'vfms.f64',0xe0
	dw	ARM_instruction_vfms.f64-instruction_handler
	db	'vhadd.s8',0xe0
	dw	ARM_instruction_vhadd.s8-instruction_handler
	db	'vhadd.u8',0xe0
	dw	ARM_instruction_vhadd.u8-instruction_handler
	db	'vhsub.s8',0xe0
	dw	ARM_instruction_vhsub.s8-instruction_handler
	db	'vhsub.u8',0xe0
	dw	ARM_instruction_vhsub.u8-instruction_handler
	db	'vld1~~.8',0x00
	dw	ARM_instruction_vld1.8-instruction_handler
	db	'vld2~~.8',0x00
	dw	ARM_instruction_vld2.8-instruction_handler
	db	'vld3~~.8',0x00
	dw	ARM_instruction_vld3.8-instruction_handler
	db	'vld4~~.8',0x00
	dw	ARM_instruction_vld4.8-instruction_handler
	db	'vldmdb~~',0x00
	dw	ARM_instruction_vldmdb-instruction_handler
	db	'vldmea~~',0x00
	dw	ARM_instruction_vldmea-instruction_handler
	db	'vldmfd~~',0x00
	dw	ARM_instruction_vldmfd-instruction_handler
	db	'vldmia~~',0x00
	dw	ARM_instruction_vldmia-instruction_handler
	db	'vmax.f32',0xe0
	dw	ARM_instruction_vmax.f32-instruction_handler
	db	'vmax.s16',0xe0
	dw	ARM_instruction_vmax.s16-instruction_handler
	db	'vmax.s32',0xe0
	dw	ARM_instruction_vmax.s32-instruction_handler
	db	'vmax.u16',0xe0
	dw	ARM_instruction_vmax.u16-instruction_handler
	db	'vmax.u32',0xe0
	dw	ARM_instruction_vmax.u32-instruction_handler
	db	'vmin.f32',0xe0
	dw	ARM_instruction_vmin.f32-instruction_handler
	db	'vmin.s16',0xe0
	dw	ARM_instruction_vmin.s16-instruction_handler
	db	'vmin.s32',0xe0
	dw	ARM_instruction_vmin.s32-instruction_handler
	db	'vmin.u16',0xe0
	dw	ARM_instruction_vmin.u16-instruction_handler
	db	'vmin.u32',0xe0
	dw	ARM_instruction_vmin.u32-instruction_handler
	db	'vmla.f32',0xe0
	dw	ARM_instruction_vmla.f32-instruction_handler
	db	'vmla.f64',0xe0
	dw	ARM_instruction_vmla.f64-instruction_handler
	db	'vmla.i16',0xe0
	dw	ARM_instruction_vmla.i16-instruction_handler
	db	'vmla.i32',0xe0
	dw	ARM_instruction_vmla.i32-instruction_handler
	db	'vmla.s16',0xe0
	dw	ARM_instruction_vmla.s16-instruction_handler
	db	'vmla.s32',0xe0
	dw	ARM_instruction_vmla.s32-instruction_handler
	db	'vmla.u16',0xe0
	dw	ARM_instruction_vmla.u16-instruction_handler
	db	'vmla.u32',0xe0
	dw	ARM_instruction_vmla.u32-instruction_handler
	db	'vmlal.s8',0xe0
	dw	ARM_instruction_vmlal.s8-instruction_handler
	db	'vmlal.u8',0xe0
	dw	ARM_instruction_vmlal.u8-instruction_handler
	db	'vmls.f32',0xe0
	dw	ARM_instruction_vmls.f32-instruction_handler
	db	'vmls.f64',0xe0
	dw	ARM_instruction_vmls.f64-instruction_handler
	db	'vmls.i16',0xe0
	dw	ARM_instruction_vmls.i16-instruction_handler
	db	'vmls.i32',0xe0
	dw	ARM_instruction_vmls.i32-instruction_handler
	db	'vmls.s16',0xe0
	dw	ARM_instruction_vmls.s16-instruction_handler
	db	'vmls.s32',0xe0
	dw	ARM_instruction_vmls.s32-instruction_handler
	db	'vmls.u16',0xe0
	dw	ARM_instruction_vmls.u16-instruction_handler
	db	'vmls.u32',0xe0
	dw	ARM_instruction_vmls.u32-instruction_handler
	db	'vmlsl.s8',0xe0
	dw	ARM_instruction_vmlsl.s8-instruction_handler
	db	'vmlsl.u8',0xe0
	dw	ARM_instruction_vmlsl.u8-instruction_handler
	db	'vmov.f32',0xe0
	dw	ARM_instruction_vmov.f32-instruction_handler
	db	'vmov.f64',0xe0
	dw	ARM_instruction_vmov.f64-instruction_handler
	db	'vmov.i16',0xe0
	dw	ARM_instruction_vmov.i16-instruction_handler
	db	'vmov.i32',0xe0
	dw	ARM_instruction_vmov.i32-instruction_handler
	db	'vmov.i64',0xe0
	dw	ARM_instruction_vmov.i64-instruction_handler
	db	'vmov.s16',0xe0
	dw	ARM_instruction_vmov.s16-instruction_handler
	db	'vmov.u16',0xe0
	dw	ARM_instruction_vmov.u16-instruction_handler
	db	'vmovl.s8',0xe0
	dw	ARM_instruction_vmovl.s8-instruction_handler
	db	'vmovl.u8',0xe0
	dw	ARM_instruction_vmovl.u8-instruction_handler
	db	'vmovn.i8',0xe0
	dw	ARM_instruction_vmovn.i8-instruction_handler
	db	'vmov~~.8',0x00
	dw	ARM_instruction_vmov.8-instruction_handler
	db	'vmul.f32',0xe0
	dw	ARM_instruction_vmul.f32-instruction_handler
	db	'vmul.f64',0xe0
	dw	ARM_instruction_vmul.f64-instruction_handler
	db	'vmul.i16',0xe0
	dw	ARM_instruction_vmul.i16-instruction_handler
	db	'vmul.i32',0xe0
	dw	ARM_instruction_vmul.i32-instruction_handler
	db	'vmul.s16',0xe0
	dw	ARM_instruction_vmul.s16-instruction_handler
	db	'vmul.s32',0xe0
	dw	ARM_instruction_vmul.s32-instruction_handler
	db	'vmul.u16',0xe0
	dw	ARM_instruction_vmul.u16-instruction_handler
	db	'vmul.u32',0xe0
	dw	ARM_instruction_vmul.u32-instruction_handler
	db	'vmull.p8',0xe0
	dw	ARM_instruction_vmull.p8-instruction_handler
	db	'vmull.s8',0xe0
	dw	ARM_instruction_vmull.s8-instruction_handler
	db	'vmull.u8',0xe0
	dw	ARM_instruction_vmull.u8-instruction_handler
	db	'vmvn.i16',0xe0
	dw	ARM_instruction_vmvn.i16-instruction_handler
	db	'vmvn.i32',0xe0
	dw	ARM_instruction_vmvn.i32-instruction_handler
	db	'vneg.f32',0xe0
	dw	ARM_instruction_vneg.f32-instruction_handler
	db	'vneg.f64',0xe0
	dw	ARM_instruction_vneg.f64-instruction_handler
	db	'vneg.s16',0xe0
	dw	ARM_instruction_vneg.s16-instruction_handler
	db	'vneg.s32',0xe0
	dw	ARM_instruction_vneg.s32-instruction_handler
	db	'vorn.i16',0xe0
	dw	ARM_instruction_vorn.i16-instruction_handler
	db	'vorn.i32',0xe0
	dw	ARM_instruction_vorn.i32-instruction_handler
	db	'vorr.i16',0xe0
	dw	ARM_instruction_vorr.i16-instruction_handler
	db	'vorr.i32',0xe0
	dw	ARM_instruction_vorr.i32-instruction_handler
	db	'vpadd.i8',0xe0
	dw	ARM_instruction_vpadd.i8-instruction_handler
	db	'vpmax.s8',0xe0
	dw	ARM_instruction_vpmax.s8-instruction_handler
	db	'vpmax.u8',0xe0
	dw	ARM_instruction_vpmax.u8-instruction_handler
	db	'vpmin.s8',0xe0
	dw	ARM_instruction_vpmin.s8-instruction_handler
	db	'vpmin.u8',0xe0
	dw	ARM_instruction_vpmin.u8-instruction_handler
	db	'vqabs.s8',0xe0
	dw	ARM_instruction_vqabs.s8-instruction_handler
	db	'vqadd.s8',0xe0
	dw	ARM_instruction_vqadd.s8-instruction_handler
	db	'vqadd.u8',0xe0
	dw	ARM_instruction_vqadd.u8-instruction_handler
	db	'vqneg.s8',0xe0
	dw	ARM_instruction_vqneg.s8-instruction_handler
	db	'vqshl.s8',0xe0
	dw	ARM_instruction_vqshl.s8-instruction_handler
	db	'vqshl.u8',0xe0
	dw	ARM_instruction_vqshl.u8-instruction_handler
	db	'vqsub.s8',0xe0
	dw	ARM_instruction_vqsub.s8-instruction_handler
	db	'vqsub.u8',0xe0
	dw	ARM_instruction_vqsub.u8-instruction_handler
	db	'vrev16.8',0xe0
	dw	ARM_instruction_vrev16.8-instruction_handler
	db	'vrev32.8',0xe0
	dw	ARM_instruction_vrev32.8-instruction_handler
	db	'vrev64.8',0xe0
	dw	ARM_instruction_vrev64.8-instruction_handler
	db	'vrshl.s8',0xe0
	dw	ARM_instruction_vrshl.s8-instruction_handler
	db	'vrshl.u8',0xe0
	dw	ARM_instruction_vrshl.u8-instruction_handler
	db	'vrshr.s8',0xe0
	dw	ARM_instruction_vrshr.s8-instruction_handler
	db	'vrshr.u8',0xe0
	dw	ARM_instruction_vrshr.u8-instruction_handler
	db	'vrsra.s8',0xe0
	dw	ARM_instruction_vrsra.s8-instruction_handler
	db	'vrsra.u8',0xe0
	dw	ARM_instruction_vrsra.u8-instruction_handler
	db	'vshl.i16',0xe0
	dw	ARM_instruction_vshl.i16-instruction_handler
	db	'vshl.i32',0xe0
	dw	ARM_instruction_vshl.i32-instruction_handler
	db	'vshl.i64',0xe0
	dw	ARM_instruction_vshl.i64-instruction_handler
	db	'vshl.s16',0xe0
	dw	ARM_instruction_vshl.s16-instruction_handler
	db	'vshl.s32',0xe0
	dw	ARM_instruction_vshl.s32-instruction_handler
	db	'vshl.s64',0xe0
	dw	ARM_instruction_vshl.s64-instruction_handler
	db	'vshl.u16',0xe0
	dw	ARM_instruction_vshl.u16-instruction_handler
	db	'vshl.u32',0xe0
	dw	ARM_instruction_vshl.u32-instruction_handler
	db	'vshl.u64',0xe0
	dw	ARM_instruction_vshl.u64-instruction_handler
	db	'vshll.i8',0xe0
	dw	ARM_instruction_vshll.i8-instruction_handler
	db	'vshll.s8',0xe0
	dw	ARM_instruction_vshll.s8-instruction_handler
	db	'vshll.u8',0xe0
	dw	ARM_instruction_vshll.u8-instruction_handler
	db	'vshr.s16',0xe0
	dw	ARM_instruction_vshr.s16-instruction_handler
	db	'vshr.s32',0xe0
	dw	ARM_instruction_vshr.s32-instruction_handler
	db	'vshr.s64',0xe0
	dw	ARM_instruction_vshr.s64-instruction_handler
	db	'vshr.u16',0xe0
	dw	ARM_instruction_vshr.u16-instruction_handler
	db	'vshr.u32',0xe0
	dw	ARM_instruction_vshr.u32-instruction_handler
	db	'vshr.u64',0xe0
	dw	ARM_instruction_vshr.u64-instruction_handler
	db	'vsli~~.8',0x00
	dw	ARM_instruction_vsli.8-instruction_handler
	db	'vsra.s16',0xe0
	dw	ARM_instruction_vsra.s16-instruction_handler
	db	'vsra.s32',0xe0
	dw	ARM_instruction_vsra.s32-instruction_handler
	db	'vsra.s64',0xe0
	dw	ARM_instruction_vsra.s64-instruction_handler
	db	'vsra.u16',0xe0
	dw	ARM_instruction_vsra.u16-instruction_handler
	db	'vsra.u32',0xe0
	dw	ARM_instruction_vsra.u32-instruction_handler
	db	'vsra.u64',0xe0
	dw	ARM_instruction_vsra.u64-instruction_handler
	db	'vsri~~.8',0x00
	dw	ARM_instruction_vsri.8-instruction_handler
	db	'vst1~~.8',0x00
	dw	ARM_instruction_vst1.8-instruction_handler
	db	'vst2~~.8',0x00
	dw	ARM_instruction_vst2.8-instruction_handler
	db	'vst3~~.8',0x00
	dw	ARM_instruction_vst3.8-instruction_handler
	db	'vst4~~.8',0x00
	dw	ARM_instruction_vst4.8-instruction_handler
	db	'vstmdb~~',0x00
	dw	ARM_instruction_vstmdb-instruction_handler
	db	'vstmea~~',0x00
	dw	ARM_instruction_vstmea-instruction_handler
	db	'vstmfd~~',0x00
	dw	ARM_instruction_vstmfd-instruction_handler
	db	'vstmia~~',0x00
	dw	ARM_instruction_vstmia-instruction_handler
	db	'vsub.f32',0xe0
	dw	ARM_instruction_vsub.f32-instruction_handler
	db	'vsub.f64',0xe0
	dw	ARM_instruction_vsub.f64-instruction_handler
	db	'vsub.i16',0xe0
	dw	ARM_instruction_vsub.i16-instruction_handler
	db	'vsub.i32',0xe0
	dw	ARM_instruction_vsub.i32-instruction_handler
	db	'vsub.i64',0xe0
	dw	ARM_instruction_vsub.i64-instruction_handler
	db	'vsubl.s8',0xe0
	dw	ARM_instruction_vsubl.s8-instruction_handler
	db	'vsubl.u8',0xe0
	dw	ARM_instruction_vsubl.u8-instruction_handler
	db	'vsubw.s8',0xe0
	dw	ARM_instruction_vsubw.s8-instruction_handler
	db	'vsubw.u8',0xe0
	dw	ARM_instruction_vsubw.u8-instruction_handler
	db	'vtbl~~.8',0x00
	dw	ARM_instruction_vtbl.8-instruction_handler
	db	'vtbx~~.8',0x00
	dw	ARM_instruction_vtbx.8-instruction_handler
	db	'vtrn~~.8',0x00
	dw	ARM_instruction_vtrn.8-instruction_handler
	db	'vtst~~.8',0x00
	dw	ARM_instruction_vtst.8-instruction_handler
	db	'vuzp~~.8',0x00
	dw	ARM_instruction_vuzp.8-instruction_handler
	db	'vzip~~.8',0x00
	dw	ARM_instruction_vzip.8-instruction_handler
	db	'waddhc~~',0x00
	dw	ARM_instruction_waddhc-instruction_handler
	db	'waddwc~~',0x00
	dw	ARM_instruction_waddwc-instruction_handler
	db	'walignr0',0xe0
	dw	ARM_instruction_walignr0-instruction_handler
	db	'walignr1',0xe0
	dw	ARM_instruction_walignr1-instruction_handler
	db	'walignr2',0xe0
	dw	ARM_instruction_walignr2-instruction_handler
	db	'walignr3',0xe0
	dw	ARM_instruction_walignr3-instruction_handler
	db	'wavg2b~~',0x00
	dw	ARM_instruction_wavg2b-instruction_handler
	db	'wavg2h~~',0x00
	dw	ARM_instruction_wavg2h-instruction_handler
	db	'wavg4r~~',0x00
	dw	ARM_instruction_wavg4r-instruction_handler
	db	'wcmpgtsb',0xe0
	dw	ARM_instruction_wcmpgtsb-instruction_handler
	db	'wcmpgtsh',0xe0
	dw	ARM_instruction_wcmpgtsh-instruction_handler
	db	'wcmpgtsw',0xe0
	dw	ARM_instruction_wcmpgtsw-instruction_handler
	db	'wcmpgtub',0xe0
	dw	ARM_instruction_wcmpgtub-instruction_handler
	db	'wcmpgtuh',0xe0
	dw	ARM_instruction_wcmpgtuh-instruction_handler
	db	'wcmpgtuw',0xe0
	dw	ARM_instruction_wcmpgtuw-instruction_handler
	db	'wmacsz~~',0x00
	dw	ARM_instruction_wmacsz-instruction_handler
	db	'wmacuz~~',0x00
	dw	ARM_instruction_wmacuz-instruction_handler
	db	'wmadds~~',0x00
	dw	ARM_instruction_wmadds-instruction_handler
	db	'wmaddu~~',0x00
	dw	ARM_instruction_wmaddu-instruction_handler
	db	'wmaxsb~~',0x00
	dw	ARM_instruction_wmaxsb-instruction_handler
	db	'wmaxsh~~',0x00
	dw	ARM_instruction_wmaxsh-instruction_handler
	db	'wmaxsw~~',0x00
	dw	ARM_instruction_wmaxsw-instruction_handler
	db	'wmaxub~~',0x00
	dw	ARM_instruction_wmaxub-instruction_handler
	db	'wmaxuh~~',0x00
	dw	ARM_instruction_wmaxuh-instruction_handler
	db	'wmaxuw~~',0x00
	dw	ARM_instruction_wmaxuw-instruction_handler
	db	'wmerge~~',0x00
	dw	ARM_instruction_wmerge-instruction_handler
	db	'wmiabb~~',0x00
	dw	ARM_instruction_wmiabb-instruction_handler
	db	'wmiabt~~',0x00
	dw	ARM_instruction_wmiabt-instruction_handler
	db	'wmiatb~~',0x00
	dw	ARM_instruction_wmiatb-instruction_handler
	db	'wmiatt~~',0x00
	dw	ARM_instruction_wmiatt-instruction_handler
	db	'wmiawbbn',0xe0
	dw	ARM_instruction_wmiawbbn-instruction_handler
	db	'wmiawbtn',0xe0
	dw	ARM_instruction_wmiawbtn-instruction_handler
	db	'wmiawtbn',0xe0
	dw	ARM_instruction_wmiawtbn-instruction_handler
	db	'wmiawttn',0xe0
	dw	ARM_instruction_wmiawttn-instruction_handler
	db	'wminsb~~',0x00
	dw	ARM_instruction_wminsb-instruction_handler
	db	'wminsh~~',0x00
	dw	ARM_instruction_wminsh-instruction_handler
	db	'wminsw~~',0x00
	dw	ARM_instruction_wminsw-instruction_handler
	db	'wminub~~',0x00
	dw	ARM_instruction_wminub-instruction_handler
	db	'wminuh~~',0x00
	dw	ARM_instruction_wminuh-instruction_handler
	db	'wminuw~~',0x00
	dw	ARM_instruction_wminuw-instruction_handler
	db	'wmulsl~~',0x00
	dw	ARM_instruction_wmulsl-instruction_handler
	db	'wmulsm~~',0x00
	dw	ARM_instruction_wmulsm-instruction_handler
	db	'wmulul~~',0x00
	dw	ARM_instruction_wmulul-instruction_handler
	db	'wmulum~~',0x00
	dw	ARM_instruction_wmulum-instruction_handler
	db	'wmulwl~~',0x00
	dw	ARM_instruction_wmulwl-instruction_handler
	db	'wmulwsmr',0xe0
	dw	ARM_instruction_wmulwsmr-instruction_handler
	db	'wmulwumr',0xe0
	dw	ARM_instruction_wmulwumr-instruction_handler
	db	'wpackdss',0xe0
	dw	ARM_instruction_wpackdss-instruction_handler
	db	'wpackdus',0xe0
	dw	ARM_instruction_wpackdus-instruction_handler
	db	'wpackhss',0xe0
	dw	ARM_instruction_wpackhss-instruction_handler
	db	'wpackhus',0xe0
	dw	ARM_instruction_wpackhus-instruction_handler
	db	'wpackwss',0xe0
	dw	ARM_instruction_wpackwss-instruction_handler
	db	'wpackwus',0xe0
	dw	ARM_instruction_wpackwus-instruction_handler
	db	'wqmiabbn',0xe0
	dw	ARM_instruction_wqmiabbn-instruction_handler
	db	'wqmiabtn',0xe0
	dw	ARM_instruction_wqmiabtn-instruction_handler
	db	'wqmiatbn',0xe0
	dw	ARM_instruction_wqmiatbn-instruction_handler
	db	'wqmiattn',0xe0
	dw	ARM_instruction_wqmiattn-instruction_handler
	db	'wqmulm~~',0x00
	dw	ARM_instruction_wqmulm-instruction_handler
	db	'wqmulwmr',0xe0
	dw	ARM_instruction_wqmulwmr-instruction_handler
	db	'wrordg~~',0x00
	dw	ARM_instruction_wrordg-instruction_handler
	db	'wrorhg~~',0x00
	dw	ARM_instruction_wrorhg-instruction_handler
	db	'wrorwg~~',0x00
	dw	ARM_instruction_wrorwg-instruction_handler
	db	'wsadbz~~',0x00
	dw	ARM_instruction_wsadbz-instruction_handler
	db	'wsadhz~~',0x00
	dw	ARM_instruction_wsadhz-instruction_handler
	db	'wshufh~~',0x00
	dw	ARM_instruction_wshufh-instruction_handler
	db	'wslldg~~',0x00
	dw	ARM_instruction_wslldg-instruction_handler
	db	'wsllhg~~',0x00
	dw	ARM_instruction_wsllhg-instruction_handler
	db	'wsllwg~~',0x00
	dw	ARM_instruction_wsllwg-instruction_handler
	db	'wsradg~~',0x00
	dw	ARM_instruction_wsradg-instruction_handler
	db	'wsrahg~~',0x00
	dw	ARM_instruction_wsrahg-instruction_handler
	db	'wsrawg~~',0x00
	dw	ARM_instruction_wsrawg-instruction_handler
	db	'wsrldg~~',0x00
	dw	ARM_instruction_wsrldg-instruction_handler
	db	'wsrlhg~~',0x00
	dw	ARM_instruction_wsrlhg-instruction_handler
	db	'wsrlwg~~',0x00
	dw	ARM_instruction_wsrlwg-instruction_handler
	db	0
instructions_9:
	db	'cfabs32~~',0x00
	dw	ARM_instruction_cfabs32-instruction_handler
	db	'cfabs64~~',0x00
	dw	ARM_instruction_cfabs64-instruction_handler
	db	'cfadd32~~',0x00
	dw	ARM_instruction_cfadd32-instruction_handler
	db	'cfadd64~~',0x00
	dw	ARM_instruction_cfadd64-instruction_handler
	db	'cfcmp32~~',0x00
	dw	ARM_instruction_cfcmp32-instruction_handler
	db	'cfcmp64~~',0x00
	dw	ARM_instruction_cfcmp64-instruction_handler
	db	'cfcvtds~~',0x00
	dw	ARM_instruction_cfcvtds-instruction_handler
	db	'cfcvtsd~~',0x00
	dw	ARM_instruction_cfcvtsd-instruction_handler
	db	'cfldr32~~',0x00
	dw	ARM_instruction_cfldr32-instruction_handler
	db	'cfldr64~~',0x00
	dw	ARM_instruction_cfldr64-instruction_handler
	db	'cfmac32~~',0x00
	dw	ARM_instruction_cfmac32-instruction_handler
	db	'cfmadda32',0xe0
	dw	ARM_instruction_cfmadda32-instruction_handler
	db	'cfmsc32~~',0x00
	dw	ARM_instruction_cfmsc32-instruction_handler
	db	'cfmsuba32',0xe0
	dw	ARM_instruction_cfmsuba32-instruction_handler
	db	'cfmul32~~',0x00
	dw	ARM_instruction_cfmul32-instruction_handler
	db	'cfmul64~~',0x00
	dw	ARM_instruction_cfmul64-instruction_handler
	db	'cfmv32a~~',0x00
	dw	ARM_instruction_cfmv32a-instruction_handler
	db	'cfmv64a~~',0x00
	dw	ARM_instruction_cfmv64a-instruction_handler
	db	'cfmva32~~',0x00
	dw	ARM_instruction_cfmva32-instruction_handler
	db	'cfmva64~~',0x00
	dw	ARM_instruction_cfmva64-instruction_handler
	db	'cfmvdhr~~',0x00
	dw	ARM_instruction_cfmvdhr-instruction_handler
	db	'cfmvdlr~~',0x00
	dw	ARM_instruction_cfmvdlr-instruction_handler
	db	'cfmvrdh~~',0x00
	dw	ARM_instruction_cfmvrdh-instruction_handler
	db	'cfmvrdl~~',0x00
	dw	ARM_instruction_cfmvrdl-instruction_handler
	db	'cfneg32~~',0x00
	dw	ARM_instruction_cfneg32-instruction_handler
	db	'cfneg64~~',0x00
	dw	ARM_instruction_cfneg64-instruction_handler
	db	'cfstr32~~',0x00
	dw	ARM_instruction_cfstr32-instruction_handler
	db	'cfstr64~~',0x00
	dw	ARM_instruction_cfstr64-instruction_handler
	db	'cfsub32~~',0x00
	dw	ARM_instruction_cfsub32-instruction_handler
	db	'cfsub64~~',0x00
	dw	ARM_instruction_cfsub64-instruction_handler
	db	'fcmpezd~~',0x00
	dw	ARM_instruction_fcmpezd-instruction_handler
	db	'fcmpezs~~',0x00
	dw	ARM_instruction_fcmpezs-instruction_handler
	db	'fconstd~~',0x00
	dw	ARM_instruction_fconstd-instruction_handler
	db	'fconsts~~',0x00
	dw	ARM_instruction_fconsts-instruction_handler
	db	'fldmdbd~~',0x00
	dw	ARM_instruction_fldmdbd-instruction_handler
	db	'fldmdbs~~',0x00
	dw	ARM_instruction_fldmdbs-instruction_handler
	db	'fldmdbx~~',0x00
	dw	ARM_instruction_fldmdbx-instruction_handler
	db	'fldmead~~',0x00
	dw	ARM_instruction_fldmead-instruction_handler
	db	'fldmeas~~',0x00
	dw	ARM_instruction_fldmeas-instruction_handler
	db	'fldmeax~~',0x00
	dw	ARM_instruction_fldmeax-instruction_handler
	db	'fldmfdd~~',0x00
	dw	ARM_instruction_fldmfdd-instruction_handler
	db	'fldmfds~~',0x00
	dw	ARM_instruction_fldmfds-instruction_handler
	db	'fldmfdx~~',0x00
	dw	ARM_instruction_fldmfdx-instruction_handler
	db	'fldmiad~~',0x00
	dw	ARM_instruction_fldmiad-instruction_handler
	db	'fldmias~~',0x00
	dw	ARM_instruction_fldmias-instruction_handler
	db	'fldmiax~~',0x00
	dw	ARM_instruction_fldmiax-instruction_handler
	db	'fstmdbd~~',0x00
	dw	ARM_instruction_fstmdbd-instruction_handler
	db	'fstmdbs~~',0x00
	dw	ARM_instruction_fstmdbs-instruction_handler
	db	'fstmdbx~~',0x00
	dw	ARM_instruction_fstmdbx-instruction_handler
	db	'fstmead~~',0x00
	dw	ARM_instruction_fstmead-instruction_handler
	db	'fstmeas~~',0x00
	dw	ARM_instruction_fstmeas-instruction_handler
	db	'fstmeax~~',0x00
	dw	ARM_instruction_fstmeax-instruction_handler
	db	'fstmfdd~~',0x00
	dw	ARM_instruction_fstmfdd-instruction_handler
	db	'fstmfds~~',0x00
	dw	ARM_instruction_fstmfds-instruction_handler
	db	'fstmfdx~~',0x00
	dw	ARM_instruction_fstmfdx-instruction_handler
	db	'fstmiad~~',0x00
	dw	ARM_instruction_fstmiad-instruction_handler
	db	'fstmias~~',0x00
	dw	ARM_instruction_fstmias-instruction_handler
	db	'fstmiax~~',0x00
	dw	ARM_instruction_fstmiax-instruction_handler
	db	'ftosizd~~',0x00
	dw	ARM_instruction_ftosizd-instruction_handler
	db	'ftosizs~~',0x00
	dw	ARM_instruction_ftosizs-instruction_handler
	db	'ftouizd~~',0x00
	dw	ARM_instruction_ftouizd-instruction_handler
	db	'ftouizs~~',0x00
	dw	ARM_instruction_ftouizs-instruction_handler
	db	'ldmfd~~.n',0x04
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldmfd~~.w',0x02
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldmia~~.n',0x04
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldmia~~.w',0x02
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldm~~fd.n',0x04
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldm~~fd.w',0x02
	dw	ARM_instruction_ldmfd-instruction_handler
	db	'ldm~~ia.n',0x04
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldm~~ia.w',0x02
	dw	ARM_instruction_ldmia-instruction_handler
	db	'ldrsb~~.n',0x04
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldrsb~~.w',0x02
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldrsh~~.n',0x04
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldrsh~~.w',0x02
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldr~~sb.n',0x04
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldr~~sb.w',0x02
	dw	ARM_instruction_ldrsb-instruction_handler
	db	'ldr~~sh.n',0x04
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'ldr~~sh.w',0x02
	dw	ARM_instruction_ldrsh-instruction_handler
	db	'processor',0x00
	dw	ARM_processor_directive-instruction_handler
	db	'rev16~~.n',0x04
	dw	ARM_instruction_rev16-instruction_handler
	db	'rev16~~.w',0x02
	dw	ARM_instruction_rev16-instruction_handler
	db	'revsh~~.n',0x04
	dw	ARM_instruction_revsh-instruction_handler
	db	'revsh~~.w',0x02
	dw	ARM_instruction_revsh-instruction_handler
	db	'sha256su0',0xf0
	dw	ARM_instruction_sha256su0-instruction_handler
	db	'sha256su1',0xf0
	dw	ARM_instruction_sha256su1-instruction_handler
	db	'shadd16~~',0x00
	dw	ARM_instruction_shadd16-instruction_handler
	db	'shaddsubx',0xe0
	dw	ARM_instruction_shaddsubx-instruction_handler
	db	'shsub16~~',0x00
	dw	ARM_instruction_shsub16-instruction_handler
	db	'shsubaddx',0xe0
	dw	ARM_instruction_shsubaddx-instruction_handler
	db	'smlalbb~~',0x00
	dw	ARM_instruction_smlalbb-instruction_handler
	db	'smlalbt~~',0x00
	dw	ARM_instruction_smlalbt-instruction_handler
	db	'smlaldx~~',0x00
	dw	ARM_instruction_smlaldx-instruction_handler
	db	'smlaltb~~',0x00
	dw	ARM_instruction_smlaltb-instruction_handler
	db	'smlaltt~~',0x00
	dw	ARM_instruction_smlaltt-instruction_handler
	db	'smlsldx~~',0x00
	dw	ARM_instruction_smlsldx-instruction_handler
	db	'sqrshrun2',0xf0
	dw	ARM_instruction_sqrshrun2-instruction_handler
	db	'stmdb~~.n',0x04
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stmdb~~.w',0x02
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stmfd~~.n',0x04
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stmfd~~.w',0x02
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stmia~~.n',0x04
	dw	ARM_instruction_stmia-instruction_handler
	db	'stmia~~.w',0x02
	dw	ARM_instruction_stmia-instruction_handler
	db	'stm~~db.n',0x04
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stm~~db.w',0x02
	dw	ARM_instruction_stmdb-instruction_handler
	db	'stm~~fd.n',0x04
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stm~~fd.w',0x02
	dw	ARM_instruction_stmfd-instruction_handler
	db	'stm~~ia.n',0x04
	dw	ARM_instruction_stmia-instruction_handler
	db	'stm~~ia.w',0x02
	dw	ARM_instruction_stmia-instruction_handler
	db	'sxtab16~~',0x00
	dw	ARM_instruction_sxtab16-instruction_handler
	db	'textrcb~~',0x00
	dw	ARM_instruction_textrcb-instruction_handler
	db	'textrch~~',0x00
	dw	ARM_instruction_textrch-instruction_handler
	db	'textrcw~~',0x00
	dw	ARM_instruction_textrcw-instruction_handler
	db	'torvscb~~',0x00
	dw	ARM_instruction_torvscb-instruction_handler
	db	'torvsch~~',0x00
	dw	ARM_instruction_torvsch-instruction_handler
	db	'torvscw~~',0x00
	dw	ARM_instruction_torvscw-instruction_handler
	db	'uhadd16~~',0x00
	dw	ARM_instruction_uhadd16-instruction_handler
	db	'uhaddsubx',0xe0
	dw	ARM_instruction_uhaddsubx-instruction_handler
	db	'uhsub16~~',0x00
	dw	ARM_instruction_uhsub16-instruction_handler
	db	'uhsubaddx',0xe0
	dw	ARM_instruction_uhsubaddx-instruction_handler
	db	'uqadd16~~',0x00
	dw	ARM_instruction_uqadd16-instruction_handler
	db	'uqaddsubx',0xe0
	dw	ARM_instruction_uqaddsubx-instruction_handler
	db	'uqsub16~~',0x00
	dw	ARM_instruction_uqsub16-instruction_handler
	db	'uqsubaddx',0xe0
	dw	ARM_instruction_uqsubaddx-instruction_handler
	db	'uxtab16~~',0x00
	dw	ARM_instruction_uxtab16-instruction_handler
	db	'vabal.s16',0xe0
	dw	ARM_instruction_vabal.s16-instruction_handler
	db	'vabal.s32',0xe0
	dw	ARM_instruction_vabal.s32-instruction_handler
	db	'vabal.u16',0xe0
	dw	ARM_instruction_vabal.u16-instruction_handler
	db	'vabal.u32',0xe0
	dw	ARM_instruction_vabal.u32-instruction_handler
	db	'vaba~~.s8',0x00
	dw	ARM_instruction_vaba.s8-instruction_handler
	db	'vaba~~.u8',0x00
	dw	ARM_instruction_vaba.u8-instruction_handler
	db	'vabdl.s16',0xe0
	dw	ARM_instruction_vabdl.s16-instruction_handler
	db	'vabdl.s32',0xe0
	dw	ARM_instruction_vabdl.s32-instruction_handler
	db	'vabdl.u16',0xe0
	dw	ARM_instruction_vabdl.u16-instruction_handler
	db	'vabdl.u32',0xe0
	dw	ARM_instruction_vabdl.u32-instruction_handler
	db	'vabd~~.s8',0x00
	dw	ARM_instruction_vabd.s8-instruction_handler
	db	'vabd~~.u8',0x00
	dw	ARM_instruction_vabd.u8-instruction_handler
	db	'vabs~~.s8',0x00
	dw	ARM_instruction_vabs.s8-instruction_handler
	db	'vacge.f32',0xe0
	dw	ARM_instruction_vacge.f32-instruction_handler
	db	'vacgt.f32',0xe0
	dw	ARM_instruction_vacgt.f32-instruction_handler
	db	'vacle.f32',0xe0
	dw	ARM_instruction_vacle.f32-instruction_handler
	db	'vaclt.f32',0xe0
	dw	ARM_instruction_vaclt.f32-instruction_handler
	db	'vaddl.s16',0xe0
	dw	ARM_instruction_vaddl.s16-instruction_handler
	db	'vaddl.s32',0xe0
	dw	ARM_instruction_vaddl.s32-instruction_handler
	db	'vaddl.u16',0xe0
	dw	ARM_instruction_vaddl.u16-instruction_handler
	db	'vaddl.u32',0xe0
	dw	ARM_instruction_vaddl.u32-instruction_handler
	db	'vaddw.s16',0xe0
	dw	ARM_instruction_vaddw.s16-instruction_handler
	db	'vaddw.s32',0xe0
	dw	ARM_instruction_vaddw.s32-instruction_handler
	db	'vaddw.u16',0xe0
	dw	ARM_instruction_vaddw.u16-instruction_handler
	db	'vaddw.u32',0xe0
	dw	ARM_instruction_vaddw.u32-instruction_handler
	db	'vadd~~.i8',0x00
	dw	ARM_instruction_vadd.i8-instruction_handler
	db	'vceq~~.i8',0x00
	dw	ARM_instruction_vceq.i8-instruction_handler
	db	'vcge~~.s8',0x00
	dw	ARM_instruction_vcge.s8-instruction_handler
	db	'vcge~~.u8',0x00
	dw	ARM_instruction_vcge.u8-instruction_handler
	db	'vcgt~~.s8',0x00
	dw	ARM_instruction_vcgt.s8-instruction_handler
	db	'vcgt~~.u8',0x00
	dw	ARM_instruction_vcgt.u8-instruction_handler
	db	'vcle~~.s8',0x00
	dw	ARM_instruction_vcle.s8-instruction_handler
	db	'vcle~~.u8',0x00
	dw	ARM_instruction_vcle.u8-instruction_handler
	db	'vcls~~.s8',0x00
	dw	ARM_instruction_vcls.s8-instruction_handler
	db	'vclt~~.s8',0x00
	dw	ARM_instruction_vclt.s8-instruction_handler
	db	'vclt~~.u8',0x00
	dw	ARM_instruction_vclt.u8-instruction_handler
	db	'vclz~~.i8',0x00
	dw	ARM_instruction_vclz.i8-instruction_handler
	db	'vcmpe.f32',0xe0
	dw	ARM_instruction_vcmpe.f32-instruction_handler
	db	'vcmpe.f64',0xe0
	dw	ARM_instruction_vcmpe.f64-instruction_handler
	db	'vdup~~.16',0x00
	dw	ARM_instruction_vdup.16-instruction_handler
	db	'vdup~~.32',0x00
	dw	ARM_instruction_vdup.32-instruction_handler
	db	'vext~~.16',0x00
	dw	ARM_instruction_vext.16-instruction_handler
	db	'vext~~.32',0x00
	dw	ARM_instruction_vext.32-instruction_handler
	db	'vext~~.64',0x00
	dw	ARM_instruction_vext.64-instruction_handler
	db	'vfnma.f32',0xe0
	dw	ARM_instruction_vfnma.f32-instruction_handler
	db	'vfnma.f64',0xe0
	dw	ARM_instruction_vfnma.f64-instruction_handler
	db	'vfnms.f32',0xe0
	dw	ARM_instruction_vfnms.f32-instruction_handler
	db	'vfnms.f64',0xe0
	dw	ARM_instruction_vfnms.f64-instruction_handler
	db	'vhadd.s16',0xe0
	dw	ARM_instruction_vhadd.s16-instruction_handler
	db	'vhadd.s32',0xe0
	dw	ARM_instruction_vhadd.s32-instruction_handler
	db	'vhadd.u16',0xe0
	dw	ARM_instruction_vhadd.u16-instruction_handler
	db	'vhadd.u32',0xe0
	dw	ARM_instruction_vhadd.u32-instruction_handler
	db	'vhsub.s16',0xe0
	dw	ARM_instruction_vhsub.s16-instruction_handler
	db	'vhsub.s32',0xe0
	dw	ARM_instruction_vhsub.s32-instruction_handler
	db	'vhsub.u16',0xe0
	dw	ARM_instruction_vhsub.u16-instruction_handler
	db	'vhsub.u32',0xe0
	dw	ARM_instruction_vhsub.u32-instruction_handler
	db	'vld1~~.16',0x00
	dw	ARM_instruction_vld1.16-instruction_handler
	db	'vld1~~.32',0x00
	dw	ARM_instruction_vld1.32-instruction_handler
	db	'vld1~~.64',0x00
	dw	ARM_instruction_vld1.64-instruction_handler
	db	'vld2~~.16',0x00
	dw	ARM_instruction_vld2.16-instruction_handler
	db	'vld2~~.32',0x00
	dw	ARM_instruction_vld2.32-instruction_handler
	db	'vld3~~.16',0x00
	dw	ARM_instruction_vld3.16-instruction_handler
	db	'vld3~~.32',0x00
	dw	ARM_instruction_vld3.32-instruction_handler
	db	'vld4~~.16',0x00
	dw	ARM_instruction_vld4.16-instruction_handler
	db	'vld4~~.32',0x00
	dw	ARM_instruction_vld4.32-instruction_handler
	db	'vldmdb.32',0xe0
	dw	ARM_instruction_vldmdb.32-instruction_handler
	db	'vldmdb.64',0xe0
	dw	ARM_instruction_vldmdb.64-instruction_handler
	db	'vldmea.32',0xe0
	dw	ARM_instruction_vldmea.32-instruction_handler
	db	'vldmea.64',0xe0
	dw	ARM_instruction_vldmea.64-instruction_handler
	db	'vldmfd.32',0xe0
	dw	ARM_instruction_vldmfd.32-instruction_handler
	db	'vldmfd.64',0xe0
	dw	ARM_instruction_vldmfd.64-instruction_handler
	db	'vldmia.32',0xe0
	dw	ARM_instruction_vldmia.32-instruction_handler
	db	'vldmia.64',0xe0
	dw	ARM_instruction_vldmia.64-instruction_handler
	db	'vldm~~.32',0x00
	dw	ARM_instruction_vldm.32-instruction_handler
	db	'vldm~~.64',0x00
	dw	ARM_instruction_vldm.64-instruction_handler
	db	'vldr~~.32',0x00
	dw	ARM_instruction_vldr.32-instruction_handler
	db	'vldr~~.64',0x00
	dw	ARM_instruction_vldr.64-instruction_handler
	db	'vmax~~.s8',0x00
	dw	ARM_instruction_vmax.s8-instruction_handler
	db	'vmax~~.u8',0x00
	dw	ARM_instruction_vmax.u8-instruction_handler
	db	'vmin~~.s8',0x00
	dw	ARM_instruction_vmin.s8-instruction_handler
	db	'vmin~~.u8',0x00
	dw	ARM_instruction_vmin.u8-instruction_handler
	db	'vmlal.s16',0xe0
	dw	ARM_instruction_vmlal.s16-instruction_handler
	db	'vmlal.s32',0xe0
	dw	ARM_instruction_vmlal.s32-instruction_handler
	db	'vmlal.u16',0xe0
	dw	ARM_instruction_vmlal.u16-instruction_handler
	db	'vmlal.u32',0xe0
	dw	ARM_instruction_vmlal.u32-instruction_handler
	db	'vmla~~.i8',0x00
	dw	ARM_instruction_vmla.i8-instruction_handler
	db	'vmla~~.s8',0x00
	dw	ARM_instruction_vmla.s8-instruction_handler
	db	'vmla~~.u8',0x00
	dw	ARM_instruction_vmla.u8-instruction_handler
	db	'vmlsl.s16',0xe0
	dw	ARM_instruction_vmlsl.s16-instruction_handler
	db	'vmlsl.s32',0xe0
	dw	ARM_instruction_vmlsl.s32-instruction_handler
	db	'vmlsl.u16',0xe0
	dw	ARM_instruction_vmlsl.u16-instruction_handler
	db	'vmlsl.u32',0xe0
	dw	ARM_instruction_vmlsl.u32-instruction_handler
	db	'vmls~~.i8',0x00
	dw	ARM_instruction_vmls.i8-instruction_handler
	db	'vmls~~.s8',0x00
	dw	ARM_instruction_vmls.s8-instruction_handler
	db	'vmls~~.u8',0x00
	dw	ARM_instruction_vmls.u8-instruction_handler
	db	'vmovl.s16',0xe0
	dw	ARM_instruction_vmovl.s16-instruction_handler
	db	'vmovl.s32',0xe0
	dw	ARM_instruction_vmovl.s32-instruction_handler
	db	'vmovl.u16',0xe0
	dw	ARM_instruction_vmovl.u16-instruction_handler
	db	'vmovl.u32',0xe0
	dw	ARM_instruction_vmovl.u32-instruction_handler
	db	'vmovn.i16',0xe0
	dw	ARM_instruction_vmovn.i16-instruction_handler
	db	'vmovn.i32',0xe0
	dw	ARM_instruction_vmovn.i32-instruction_handler
	db	'vmov~~.16',0x00
	dw	ARM_instruction_vmov.16-instruction_handler
	db	'vmov~~.32',0x00
	dw	ARM_instruction_vmov.32-instruction_handler
	db	'vmov~~.i8',0x00
	dw	ARM_instruction_vmov.i8-instruction_handler
	db	'vmov~~.s8',0x00
	dw	ARM_instruction_vmov.s8-instruction_handler
	db	'vmov~~.u8',0x00
	dw	ARM_instruction_vmov.u8-instruction_handler
	db	'vmull.p64',0xf0
	dw	ARM_instruction_vmull.p64-instruction_handler
	db	'vmull.s16',0xe0
	dw	ARM_instruction_vmull.s16-instruction_handler
	db	'vmull.s32',0xe0
	dw	ARM_instruction_vmull.s32-instruction_handler
	db	'vmull.u16',0xe0
	dw	ARM_instruction_vmull.u16-instruction_handler
	db	'vmull.u32',0xe0
	dw	ARM_instruction_vmull.u32-instruction_handler
	db	'vmul~~.i8',0x00
	dw	ARM_instruction_vmul.i8-instruction_handler
	db	'vmul~~.p8',0x00
	dw	ARM_instruction_vmul.p8-instruction_handler
	db	'vmul~~.s8',0x00
	dw	ARM_instruction_vmul.s8-instruction_handler
	db	'vmul~~.u8',0x00
	dw	ARM_instruction_vmul.u8-instruction_handler
	db	'vneg~~.s8',0x00
	dw	ARM_instruction_vneg.s8-instruction_handler
	db	'vnmla.f32',0xe0
	dw	ARM_instruction_vnmla.f32-instruction_handler
	db	'vnmla.f64',0xe0
	dw	ARM_instruction_vnmla.f64-instruction_handler
	db	'vnmls.f32',0xe0
	dw	ARM_instruction_vnmls.f32-instruction_handler
	db	'vnmls.f64',0xe0
	dw	ARM_instruction_vnmls.f64-instruction_handler
	db	'vnmul.f32',0xe0
	dw	ARM_instruction_vnmul.f32-instruction_handler
	db	'vnmul.f64',0xe0
	dw	ARM_instruction_vnmul.f64-instruction_handler
	db	'vpadal.s8',0xe0
	dw	ARM_instruction_vpadal.s8-instruction_handler
	db	'vpadal.u8',0xe0
	dw	ARM_instruction_vpadal.u8-instruction_handler
	db	'vpadd.f32',0xe0
	dw	ARM_instruction_vpadd.f32-instruction_handler
	db	'vpadd.i16',0xe0
	dw	ARM_instruction_vpadd.i16-instruction_handler
	db	'vpadd.i32',0xe0
	dw	ARM_instruction_vpadd.i32-instruction_handler
	db	'vpaddl.s8',0xe0
	dw	ARM_instruction_vpaddl.s8-instruction_handler
	db	'vpaddl.u8',0xe0
	dw	ARM_instruction_vpaddl.u8-instruction_handler
	db	'vpmax.f32',0xe0
	dw	ARM_instruction_vpmax.f32-instruction_handler
	db	'vpmax.s16',0xe0
	dw	ARM_instruction_vpmax.s16-instruction_handler
	db	'vpmax.s32',0xe0
	dw	ARM_instruction_vpmax.s32-instruction_handler
	db	'vpmax.u16',0xe0
	dw	ARM_instruction_vpmax.u16-instruction_handler
	db	'vpmax.u32',0xe0
	dw	ARM_instruction_vpmax.u32-instruction_handler
	db	'vpmin.f32',0xe0
	dw	ARM_instruction_vpmin.f32-instruction_handler
	db	'vpmin.s16',0xe0
	dw	ARM_instruction_vpmin.s16-instruction_handler
	db	'vpmin.s32',0xe0
	dw	ARM_instruction_vpmin.s32-instruction_handler
	db	'vpmin.u16',0xe0
	dw	ARM_instruction_vpmin.u16-instruction_handler
	db	'vpmin.u32',0xe0
	dw	ARM_instruction_vpmin.u32-instruction_handler
	db	'vqabs.s16',0xe0
	dw	ARM_instruction_vqabs.s16-instruction_handler
	db	'vqabs.s32',0xe0
	dw	ARM_instruction_vqabs.s32-instruction_handler
	db	'vqadd.s16',0xe0
	dw	ARM_instruction_vqadd.s16-instruction_handler
	db	'vqadd.s32',0xe0
	dw	ARM_instruction_vqadd.s32-instruction_handler
	db	'vqadd.s64',0xe0
	dw	ARM_instruction_vqadd.s64-instruction_handler
	db	'vqadd.u16',0xe0
	dw	ARM_instruction_vqadd.u16-instruction_handler
	db	'vqadd.u32',0xe0
	dw	ARM_instruction_vqadd.u32-instruction_handler
	db	'vqadd.u64',0xe0
	dw	ARM_instruction_vqadd.u64-instruction_handler
	db	'vqneg.s16',0xe0
	dw	ARM_instruction_vqneg.s16-instruction_handler
	db	'vqneg.s32',0xe0
	dw	ARM_instruction_vqneg.s32-instruction_handler
	db	'vqrshl.s8',0xe0
	dw	ARM_instruction_vqrshl.s8-instruction_handler
	db	'vqrshl.u8',0xe0
	dw	ARM_instruction_vqrshl.u8-instruction_handler
	db	'vqshl.s16',0xe0
	dw	ARM_instruction_vqshl.s16-instruction_handler
	db	'vqshl.s32',0xe0
	dw	ARM_instruction_vqshl.s32-instruction_handler
	db	'vqshl.s64',0xe0
	dw	ARM_instruction_vqshl.s64-instruction_handler
	db	'vqshl.u16',0xe0
	dw	ARM_instruction_vqshl.u16-instruction_handler
	db	'vqshl.u32',0xe0
	dw	ARM_instruction_vqshl.u32-instruction_handler
	db	'vqshl.u64',0xe0
	dw	ARM_instruction_vqshl.u64-instruction_handler
	db	'vqshlu.s8',0xe0
	dw	ARM_instruction_vqshlu.s8-instruction_handler
	db	'vqsub.s16',0xe0
	dw	ARM_instruction_vqsub.s16-instruction_handler
	db	'vqsub.s32',0xe0
	dw	ARM_instruction_vqsub.s32-instruction_handler
	db	'vqsub.s64',0xe0
	dw	ARM_instruction_vqsub.s64-instruction_handler
	db	'vqsub.u16',0xe0
	dw	ARM_instruction_vqsub.u16-instruction_handler
	db	'vqsub.u32',0xe0
	dw	ARM_instruction_vqsub.u32-instruction_handler
	db	'vqsub.u64',0xe0
	dw	ARM_instruction_vqsub.u64-instruction_handler
	db	'vrev32.16',0xe0
	dw	ARM_instruction_vrev32.16-instruction_handler
	db	'vrev64.16',0xe0
	dw	ARM_instruction_vrev64.16-instruction_handler
	db	'vrev64.32',0xe0
	dw	ARM_instruction_vrev64.32-instruction_handler
	db	'vrhadd.s8',0xe0
	dw	ARM_instruction_vrhadd.s8-instruction_handler
	db	'vrhadd.u8',0xe0
	dw	ARM_instruction_vrhadd.u8-instruction_handler
	db	'vrshl.s16',0xe0
	dw	ARM_instruction_vrshl.s16-instruction_handler
	db	'vrshl.s32',0xe0
	dw	ARM_instruction_vrshl.s32-instruction_handler
	db	'vrshl.s64',0xe0
	dw	ARM_instruction_vrshl.s64-instruction_handler
	db	'vrshl.u16',0xe0
	dw	ARM_instruction_vrshl.u16-instruction_handler
	db	'vrshl.u32',0xe0
	dw	ARM_instruction_vrshl.u32-instruction_handler
	db	'vrshl.u64',0xe0
	dw	ARM_instruction_vrshl.u64-instruction_handler
	db	'vrshr.s16',0xe0
	dw	ARM_instruction_vrshr.s16-instruction_handler
	db	'vrshr.s32',0xe0
	dw	ARM_instruction_vrshr.s32-instruction_handler
	db	'vrshr.s64',0xe0
	dw	ARM_instruction_vrshr.s64-instruction_handler
	db	'vrshr.u16',0xe0
	dw	ARM_instruction_vrshr.u16-instruction_handler
	db	'vrshr.u32',0xe0
	dw	ARM_instruction_vrshr.u32-instruction_handler
	db	'vrshr.u64',0xe0
	dw	ARM_instruction_vrshr.u64-instruction_handler
	db	'vrsra.s16',0xe0
	dw	ARM_instruction_vrsra.s16-instruction_handler
	db	'vrsra.s32',0xe0
	dw	ARM_instruction_vrsra.s32-instruction_handler
	db	'vrsra.s64',0xe0
	dw	ARM_instruction_vrsra.s64-instruction_handler
	db	'vrsra.u16',0xe0
	dw	ARM_instruction_vrsra.u16-instruction_handler
	db	'vrsra.u32',0xe0
	dw	ARM_instruction_vrsra.u32-instruction_handler
	db	'vrsra.u64',0xe0
	dw	ARM_instruction_vrsra.u64-instruction_handler
	db	'vshll.i16',0xe0
	dw	ARM_instruction_vshll.i16-instruction_handler
	db	'vshll.i32',0xe0
	dw	ARM_instruction_vshll.i32-instruction_handler
	db	'vshll.s16',0xe0
	dw	ARM_instruction_vshll.s16-instruction_handler
	db	'vshll.s32',0xe0
	dw	ARM_instruction_vshll.s32-instruction_handler
	db	'vshll.u16',0xe0
	dw	ARM_instruction_vshll.u16-instruction_handler
	db	'vshll.u32',0xe0
	dw	ARM_instruction_vshll.u32-instruction_handler
	db	'vshl~~.i8',0x00
	dw	ARM_instruction_vshl.i8-instruction_handler
	db	'vshl~~.s8',0x00
	dw	ARM_instruction_vshl.s8-instruction_handler
	db	'vshl~~.u8',0x00
	dw	ARM_instruction_vshl.u8-instruction_handler
	db	'vshrn.i16',0xe0
	dw	ARM_instruction_vshrn.i16-instruction_handler
	db	'vshrn.i32',0xe0
	dw	ARM_instruction_vshrn.i32-instruction_handler
	db	'vshrn.i64',0xe0
	dw	ARM_instruction_vshrn.i64-instruction_handler
	db	'vshr~~.s8',0x00
	dw	ARM_instruction_vshr.s8-instruction_handler
	db	'vshr~~.u8',0x00
	dw	ARM_instruction_vshr.u8-instruction_handler
	db	'vsli~~.16',0x00
	dw	ARM_instruction_vsli.16-instruction_handler
	db	'vsli~~.32',0x00
	dw	ARM_instruction_vsli.32-instruction_handler
	db	'vsli~~.64',0x00
	dw	ARM_instruction_vsli.64-instruction_handler
	db	'vsqrt.f32',0xe0
	dw	ARM_instruction_vsqrt.f32-instruction_handler
	db	'vsqrt.f64',0xe0
	dw	ARM_instruction_vsqrt.f64-instruction_handler
	db	'vsra~~.s8',0x00
	dw	ARM_instruction_vsra.s8-instruction_handler
	db	'vsra~~.u8',0x00
	dw	ARM_instruction_vsra.u8-instruction_handler
	db	'vsri~~.16',0x00
	dw	ARM_instruction_vsri.16-instruction_handler
	db	'vsri~~.32',0x00
	dw	ARM_instruction_vsri.32-instruction_handler
	db	'vsri~~.64',0x00
	dw	ARM_instruction_vsri.64-instruction_handler
	db	'vst1~~.16',0x00
	dw	ARM_instruction_vst1.16-instruction_handler
	db	'vst1~~.32',0x00
	dw	ARM_instruction_vst1.32-instruction_handler
	db	'vst1~~.64',0x00
	dw	ARM_instruction_vst1.64-instruction_handler
	db	'vst2~~.16',0x00
	dw	ARM_instruction_vst2.16-instruction_handler
	db	'vst2~~.32',0x00
	dw	ARM_instruction_vst2.32-instruction_handler
	db	'vst3~~.16',0x00
	dw	ARM_instruction_vst3.16-instruction_handler
	db	'vst3~~.32',0x00
	dw	ARM_instruction_vst3.32-instruction_handler
	db	'vst4~~.16',0x00
	dw	ARM_instruction_vst4.16-instruction_handler
	db	'vst4~~.32',0x00
	dw	ARM_instruction_vst4.32-instruction_handler
	db	'vstmdb.32',0xe0
	dw	ARM_instruction_vstmdb.32-instruction_handler
	db	'vstmdb.64',0xe0
	dw	ARM_instruction_vstmdb.64-instruction_handler
	db	'vstmea.32',0xe0
	dw	ARM_instruction_vstmea.32-instruction_handler
	db	'vstmea.64',0xe0
	dw	ARM_instruction_vstmea.64-instruction_handler
	db	'vstmfd.32',0xe0
	dw	ARM_instruction_vstmfd.32-instruction_handler
	db	'vstmfd.64',0xe0
	dw	ARM_instruction_vstmfd.64-instruction_handler
	db	'vstmia.32',0xe0
	dw	ARM_instruction_vstmia.32-instruction_handler
	db	'vstmia.64',0xe0
	dw	ARM_instruction_vstmia.64-instruction_handler
	db	'vstm~~.32',0x00
	dw	ARM_instruction_vstm.32-instruction_handler
	db	'vstm~~.64',0x00
	dw	ARM_instruction_vstm.64-instruction_handler
	db	'vstr~~.32',0x00
	dw	ARM_instruction_vstr.32-instruction_handler
	db	'vstr~~.64',0x00
	dw	ARM_instruction_vstr.64-instruction_handler
	db	'vsubl.s16',0xe0
	dw	ARM_instruction_vsubl.s16-instruction_handler
	db	'vsubl.s32',0xe0
	dw	ARM_instruction_vsubl.s32-instruction_handler
	db	'vsubl.u16',0xe0
	dw	ARM_instruction_vsubl.u16-instruction_handler
	db	'vsubl.u32',0xe0
	dw	ARM_instruction_vsubl.u32-instruction_handler
	db	'vsubw.s16',0xe0
	dw	ARM_instruction_vsubw.s16-instruction_handler
	db	'vsubw.s32',0xe0
	dw	ARM_instruction_vsubw.s32-instruction_handler
	db	'vsubw.u16',0xe0
	dw	ARM_instruction_vsubw.u16-instruction_handler
	db	'vsubw.u32',0xe0
	dw	ARM_instruction_vsubw.u32-instruction_handler
	db	'vsub~~.i8',0x00
	dw	ARM_instruction_vsub.i8-instruction_handler
	db	'vtrn~~.16',0x00
	dw	ARM_instruction_vtrn.16-instruction_handler
	db	'vtrn~~.32',0x00
	dw	ARM_instruction_vtrn.32-instruction_handler
	db	'vtst~~.16',0x00
	dw	ARM_instruction_vtst.16-instruction_handler
	db	'vtst~~.32',0x00
	dw	ARM_instruction_vtst.32-instruction_handler
	db	'vuzp~~.16',0x00
	dw	ARM_instruction_vuzp.16-instruction_handler
	db	'vuzp~~.32',0x00
	dw	ARM_instruction_vuzp.32-instruction_handler
	db	'vzip~~.16',0x00
	dw	ARM_instruction_vzip.16-instruction_handler
	db	'vzip~~.32',0x00
	dw	ARM_instruction_vzip.32-instruction_handler
	db	'wabsdiffb',0xe0
	dw	ARM_instruction_wabsdiffb-instruction_handler
	db	'wabsdiffh',0xe0
	dw	ARM_instruction_wabsdiffh-instruction_handler
	db	'wabsdiffw',0xe0
	dw	ARM_instruction_wabsdiffw-instruction_handler
	db	'waddbss~~',0x00
	dw	ARM_instruction_waddbss-instruction_handler
	db	'waddbus~~',0x00
	dw	ARM_instruction_waddbus-instruction_handler
	db	'waddhss~~',0x00
	dw	ARM_instruction_waddhss-instruction_handler
	db	'waddhus~~',0x00
	dw	ARM_instruction_waddhus-instruction_handler
	db	'waddsubhx',0xe0
	dw	ARM_instruction_waddsubhx-instruction_handler
	db	'waddwss~~',0x00
	dw	ARM_instruction_waddwss-instruction_handler
	db	'waddwus~~',0x00
	dw	ARM_instruction_waddwus-instruction_handler
	db	'waligni~~',0x00
	dw	ARM_instruction_waligni-instruction_handler
	db	'wavg2br~~',0x00
	dw	ARM_instruction_wavg2br-instruction_handler
	db	'wavg2hr~~',0x00
	dw	ARM_instruction_wavg2hr-instruction_handler
	db	'wcmpeqb~~',0x00
	dw	ARM_instruction_wcmpeqb-instruction_handler
	db	'wcmpeqh~~',0x00
	dw	ARM_instruction_wcmpeqh-instruction_handler
	db	'wcmpeqw~~',0x00
	dw	ARM_instruction_wcmpeqw-instruction_handler
	db	'wmaddsn~~',0x00
	dw	ARM_instruction_wmaddsn-instruction_handler
	db	'wmaddsx~~',0x00
	dw	ARM_instruction_wmaddsx-instruction_handler
	db	'wmaddun~~',0x00
	dw	ARM_instruction_wmaddun-instruction_handler
	db	'wmaddux~~',0x00
	dw	ARM_instruction_wmaddux-instruction_handler
	db	'wmiabbn~~',0x00
	dw	ARM_instruction_wmiabbn-instruction_handler
	db	'wmiabtn~~',0x00
	dw	ARM_instruction_wmiabtn-instruction_handler
	db	'wmiatbn~~',0x00
	dw	ARM_instruction_wmiatbn-instruction_handler
	db	'wmiattn~~',0x00
	dw	ARM_instruction_wmiattn-instruction_handler
	db	'wmiawbb~~',0x00
	dw	ARM_instruction_wmiawbb-instruction_handler
	db	'wmiawbt~~',0x00
	dw	ARM_instruction_wmiawbt-instruction_handler
	db	'wmiawtb~~',0x00
	dw	ARM_instruction_wmiawtb-instruction_handler
	db	'wmiawtt~~',0x00
	dw	ARM_instruction_wmiawtt-instruction_handler
	db	'wmulsmr~~',0x00
	dw	ARM_instruction_wmulsmr-instruction_handler
	db	'wmulumr~~',0x00
	dw	ARM_instruction_wmulumr-instruction_handler
	db	'wmulwsm~~',0x00
	dw	ARM_instruction_wmulwsm-instruction_handler
	db	'wmulwum~~',0x00
	dw	ARM_instruction_wmulwum-instruction_handler
	db	'wqmiabb~~',0x00
	dw	ARM_instruction_wqmiabb-instruction_handler
	db	'wqmiabt~~',0x00
	dw	ARM_instruction_wqmiabt-instruction_handler
	db	'wqmiatb~~',0x00
	dw	ARM_instruction_wqmiatb-instruction_handler
	db	'wqmiatt~~',0x00
	dw	ARM_instruction_wqmiatt-instruction_handler
	db	'wqmulmr~~',0x00
	dw	ARM_instruction_wqmulmr-instruction_handler
	db	'wqmulwm~~',0x00
	dw	ARM_instruction_wqmulwm-instruction_handler
	db	'wsubaddhx',0xe0
	dw	ARM_instruction_wsubaddhx-instruction_handler
	db	'wsubbss~~',0x00
	dw	ARM_instruction_wsubbss-instruction_handler
	db	'wsubbus~~',0x00
	dw	ARM_instruction_wsubbus-instruction_handler
	db	'wsubhss~~',0x00
	dw	ARM_instruction_wsubhss-instruction_handler
	db	'wsubhus~~',0x00
	dw	ARM_instruction_wsubhus-instruction_handler
	db	'wsubwss~~',0x00
	dw	ARM_instruction_wsubwss-instruction_handler
	db	'wsubwus~~',0x00
	dw	ARM_instruction_wsubwus-instruction_handler
	db	'wunpckihb',0xe0
	dw	ARM_instruction_wunpckihb-instruction_handler
	db	'wunpckihh',0xe0
	dw	ARM_instruction_wunpckihh-instruction_handler
	db	'wunpckihw',0xe0
	dw	ARM_instruction_wunpckihw-instruction_handler
	db	'wunpckilb',0xe0
	dw	ARM_instruction_wunpckilb-instruction_handler
	db	'wunpckilh',0xe0
	dw	ARM_instruction_wunpckilh-instruction_handler
	db	'wunpckilw',0xe0
	dw	ARM_instruction_wunpckilw-instruction_handler
	db	'yield~~.n',0x04
	dw	ARM_instruction_yield-instruction_handler
	db	'yield~~.w',0x02
	dw	ARM_instruction_yield-instruction_handler
	db	0
instructions_10:
	db	'cfcvt32d~~',0x00
	dw	ARM_instruction_cfcvt32d-instruction_handler
	db	'cfcvt32s~~',0x00
	dw	ARM_instruction_cfcvt32s-instruction_handler
	db	'cfcvt64d~~',0x00
	dw	ARM_instruction_cfcvt64d-instruction_handler
	db	'cfcvt64s~~',0x00
	dw	ARM_instruction_cfcvt64s-instruction_handler
	db	'cfcvtd32~~',0x00
	dw	ARM_instruction_cfcvtd32-instruction_handler
	db	'cfcvts32~~',0x00
	dw	ARM_instruction_cfcvts32-instruction_handler
	db	'cfmadd32~~',0x00
	dw	ARM_instruction_cfmadd32-instruction_handler
	db	'cfmsub32~~',0x00
	dw	ARM_instruction_cfmsub32-instruction_handler
	db	'cfmv32ah~~',0x00
	dw	ARM_instruction_cfmv32ah-instruction_handler
	db	'cfmv32al~~',0x00
	dw	ARM_instruction_cfmv32al-instruction_handler
	db	'cfmv32am~~',0x00
	dw	ARM_instruction_cfmv32am-instruction_handler
	db	'cfmv32sc~~',0x00
	dw	ARM_instruction_cfmv32sc-instruction_handler
	db	'cfmv64hr~~',0x00
	dw	ARM_instruction_cfmv64hr-instruction_handler
	db	'cfmv64lr~~',0x00
	dw	ARM_instruction_cfmv64lr-instruction_handler
	db	'cfmvah32~~',0x00
	dw	ARM_instruction_cfmvah32-instruction_handler
	db	'cfmval32~~',0x00
	dw	ARM_instruction_cfmval32-instruction_handler
	db	'cfmvam32~~',0x00
	dw	ARM_instruction_cfmvam32-instruction_handler
	db	'cfmvr64h~~',0x00
	dw	ARM_instruction_cfmvr64h-instruction_handler
	db	'cfmvr64l~~',0x00
	dw	ARM_instruction_cfmvr64l-instruction_handler
	db	'cfmvsc32~~',0x00
	dw	ARM_instruction_cfmvsc32-instruction_handler
	db	'cfrshl32~~',0x00
	dw	ARM_instruction_cfrshl32-instruction_handler
	db	'cfrshl64~~',0x00
	dw	ARM_instruction_cfrshl64-instruction_handler
	db	'cftruncd32',0xe0
	dw	ARM_instruction_cftruncd32-instruction_handler
	db	'cftruncs32',0xe0
	dw	ARM_instruction_cftruncs32-instruction_handler
	db	'qaddsubx~~',0x00
	dw	ARM_instruction_qaddsubx-instruction_handler
	db	'qsubaddx~~',0x00
	dw	ARM_instruction_qsubaddx-instruction_handler
	db	'saddsubx~~',0x00
	dw	ARM_instruction_saddsubx-instruction_handler
	db	'sha1su0.32',0xf0
	dw	ARM_instruction_sha1su0.32-instruction_handler
	db	'sha1su1.32',0xf0
	dw	ARM_instruction_sha1su1.32-instruction_handler
	db	'sha256h.32',0xf0
	dw	ARM_instruction_sha256h.32-instruction_handler
	db	'ssubaddx~~',0x00
	dw	ARM_instruction_ssubaddx-instruction_handler
	db	'textrmsb~~',0x00
	dw	ARM_instruction_textrmsb-instruction_handler
	db	'textrmsh~~',0x00
	dw	ARM_instruction_textrmsh-instruction_handler
	db	'textrmsw~~',0x00
	dw	ARM_instruction_textrmsw-instruction_handler
	db	'textrmub~~',0x00
	dw	ARM_instruction_textrmub-instruction_handler
	db	'textrmuh~~',0x00
	dw	ARM_instruction_textrmuh-instruction_handler
	db	'textrmuw~~',0x00
	dw	ARM_instruction_textrmuw-instruction_handler
	db	'tmovmskb~~',0x00
	dw	ARM_instruction_tmovmskb-instruction_handler
	db	'tmovmskh~~',0x00
	dw	ARM_instruction_tmovmskh-instruction_handler
	db	'tmovmskw~~',0x00
	dw	ARM_instruction_tmovmskw-instruction_handler
	db	'uaddsubx~~',0x00
	dw	ARM_instruction_uaddsubx-instruction_handler
	db	'usubaddx~~',0x00
	dw	ARM_instruction_usubaddx-instruction_handler
	db	'vabal~~.s8',0x00
	dw	ARM_instruction_vabal.s8-instruction_handler
	db	'vabal~~.u8',0x00
	dw	ARM_instruction_vabal.u8-instruction_handler
	db	'vaba~~.s16',0x00
	dw	ARM_instruction_vaba.s16-instruction_handler
	db	'vaba~~.s32',0x00
	dw	ARM_instruction_vaba.s32-instruction_handler
	db	'vaba~~.u16',0x00
	dw	ARM_instruction_vaba.u16-instruction_handler
	db	'vaba~~.u32',0x00
	dw	ARM_instruction_vaba.u32-instruction_handler
	db	'vabdl~~.s8',0x00
	dw	ARM_instruction_vabdl.s8-instruction_handler
	db	'vabdl~~.u8',0x00
	dw	ARM_instruction_vabdl.u8-instruction_handler
	db	'vabd~~.f32',0x00
	dw	ARM_instruction_vabd.f32-instruction_handler
	db	'vabd~~.s16',0x00
	dw	ARM_instruction_vabd.s16-instruction_handler
	db	'vabd~~.s32',0x00
	dw	ARM_instruction_vabd.s32-instruction_handler
	db	'vabd~~.u16',0x00
	dw	ARM_instruction_vabd.u16-instruction_handler
	db	'vabd~~.u32',0x00
	dw	ARM_instruction_vabd.u32-instruction_handler
	db	'vabs~~.f32',0x00
	dw	ARM_instruction_vabs.f32-instruction_handler
	db	'vabs~~.f64',0x00
	dw	ARM_instruction_vabs.f64-instruction_handler
	db	'vabs~~.s16',0x00
	dw	ARM_instruction_vabs.s16-instruction_handler
	db	'vabs~~.s32',0x00
	dw	ARM_instruction_vabs.s32-instruction_handler
	db	'vaddhn.i16',0xe0
	dw	ARM_instruction_vaddhn.i16-instruction_handler
	db	'vaddhn.i32',0xe0
	dw	ARM_instruction_vaddhn.i32-instruction_handler
	db	'vaddhn.i64',0xe0
	dw	ARM_instruction_vaddhn.i64-instruction_handler
	db	'vaddl~~.s8',0x00
	dw	ARM_instruction_vaddl.s8-instruction_handler
	db	'vaddl~~.u8',0x00
	dw	ARM_instruction_vaddl.u8-instruction_handler
	db	'vaddw~~.s8',0x00
	dw	ARM_instruction_vaddw.s8-instruction_handler
	db	'vaddw~~.u8',0x00
	dw	ARM_instruction_vaddw.u8-instruction_handler
	db	'vadd~~.f32',0x00
	dw	ARM_instruction_vadd.f32-instruction_handler
	db	'vadd~~.f64',0x00
	dw	ARM_instruction_vadd.f64-instruction_handler
	db	'vadd~~.i16',0x00
	dw	ARM_instruction_vadd.i16-instruction_handler
	db	'vadd~~.i32',0x00
	dw	ARM_instruction_vadd.i32-instruction_handler
	db	'vadd~~.i64',0x00
	dw	ARM_instruction_vadd.i64-instruction_handler
	db	'vand~~.i16',0x00
	dw	ARM_instruction_vand.i16-instruction_handler
	db	'vand~~.i32',0x00
	dw	ARM_instruction_vand.i32-instruction_handler
	db	'vbic~~.i16',0x00
	dw	ARM_instruction_vbic.i16-instruction_handler
	db	'vbic~~.i32',0x00
	dw	ARM_instruction_vbic.i32-instruction_handler
	db	'vceq~~.f32',0x00
	dw	ARM_instruction_vceq.f32-instruction_handler
	db	'vceq~~.i16',0x00
	dw	ARM_instruction_vceq.i16-instruction_handler
	db	'vceq~~.i32',0x00
	dw	ARM_instruction_vceq.i32-instruction_handler
	db	'vcge~~.f32',0x00
	dw	ARM_instruction_vcge.f32-instruction_handler
	db	'vcge~~.s16',0x00
	dw	ARM_instruction_vcge.s16-instruction_handler
	db	'vcge~~.s32',0x00
	dw	ARM_instruction_vcge.s32-instruction_handler
	db	'vcge~~.u16',0x00
	dw	ARM_instruction_vcge.u16-instruction_handler
	db	'vcge~~.u32',0x00
	dw	ARM_instruction_vcge.u32-instruction_handler
	db	'vcgt~~.f32',0x00
	dw	ARM_instruction_vcgt.f32-instruction_handler
	db	'vcgt~~.s16',0x00
	dw	ARM_instruction_vcgt.s16-instruction_handler
	db	'vcgt~~.s32',0x00
	dw	ARM_instruction_vcgt.s32-instruction_handler
	db	'vcgt~~.u16',0x00
	dw	ARM_instruction_vcgt.u16-instruction_handler
	db	'vcgt~~.u32',0x00
	dw	ARM_instruction_vcgt.u32-instruction_handler
	db	'vcle~~.f32',0x00
	dw	ARM_instruction_vcle.f32-instruction_handler
	db	'vcle~~.s16',0x00
	dw	ARM_instruction_vcle.s16-instruction_handler
	db	'vcle~~.s32',0x00
	dw	ARM_instruction_vcle.s32-instruction_handler
	db	'vcle~~.u16',0x00
	dw	ARM_instruction_vcle.u16-instruction_handler
	db	'vcle~~.u32',0x00
	dw	ARM_instruction_vcle.u32-instruction_handler
	db	'vcls~~.s16',0x00
	dw	ARM_instruction_vcls.s16-instruction_handler
	db	'vcls~~.s32',0x00
	dw	ARM_instruction_vcls.s32-instruction_handler
	db	'vclt~~.f32',0x00
	dw	ARM_instruction_vclt.f32-instruction_handler
	db	'vclt~~.s16',0x00
	dw	ARM_instruction_vclt.s16-instruction_handler
	db	'vclt~~.s32',0x00
	dw	ARM_instruction_vclt.s32-instruction_handler
	db	'vclt~~.u16',0x00
	dw	ARM_instruction_vclt.u16-instruction_handler
	db	'vclt~~.u32',0x00
	dw	ARM_instruction_vclt.u32-instruction_handler
	db	'vclz~~.i16',0x00
	dw	ARM_instruction_vclz.i16-instruction_handler
	db	'vclz~~.i32',0x00
	dw	ARM_instruction_vclz.i32-instruction_handler
	db	'vcmp~~.f32',0x00
	dw	ARM_instruction_vcmp.f32-instruction_handler
	db	'vcmp~~.f64',0x00
	dw	ARM_instruction_vcmp.f64-instruction_handler
	db	'vdiv~~.f32',0x00
	dw	ARM_instruction_vdiv.f32-instruction_handler
	db	'vdiv~~.f64',0x00
	dw	ARM_instruction_vdiv.f64-instruction_handler
	db	'vfma~~.f32',0x00
	dw	ARM_instruction_vfma.f32-instruction_handler
	db	'vfma~~.f64',0x00
	dw	ARM_instruction_vfma.f64-instruction_handler
	db	'vfms~~.f32',0x00
	dw	ARM_instruction_vfms.f32-instruction_handler
	db	'vfms~~.f64',0x00
	dw	ARM_instruction_vfms.f64-instruction_handler
	db	'vhadd~~.s8',0x00
	dw	ARM_instruction_vhadd.s8-instruction_handler
	db	'vhadd~~.u8',0x00
	dw	ARM_instruction_vhadd.u8-instruction_handler
	db	'vhsub~~.s8',0x00
	dw	ARM_instruction_vhsub.s8-instruction_handler
	db	'vhsub~~.u8',0x00
	dw	ARM_instruction_vhsub.u8-instruction_handler
	db	'vmaxnm.f32',0xf0
	dw	ARM_instruction_vmaxnm.f32-instruction_handler
	db	'vmaxnm.f64',0xf0
	dw	ARM_instruction_vmaxnm.f64-instruction_handler
	db	'vmax~~.f32',0x00
	dw	ARM_instruction_vmax.f32-instruction_handler
	db	'vmax~~.s16',0x00
	dw	ARM_instruction_vmax.s16-instruction_handler
	db	'vmax~~.s32',0x00
	dw	ARM_instruction_vmax.s32-instruction_handler
	db	'vmax~~.u16',0x00
	dw	ARM_instruction_vmax.u16-instruction_handler
	db	'vmax~~.u32',0x00
	dw	ARM_instruction_vmax.u32-instruction_handler
	db	'vminnm.f32',0xf0
	dw	ARM_instruction_vminnm.f32-instruction_handler
	db	'vminnm.f64',0xf0
	dw	ARM_instruction_vminnm.f64-instruction_handler
	db	'vmin~~.f32',0x00
	dw	ARM_instruction_vmin.f32-instruction_handler
	db	'vmin~~.s16',0x00
	dw	ARM_instruction_vmin.s16-instruction_handler
	db	'vmin~~.s32',0x00
	dw	ARM_instruction_vmin.s32-instruction_handler
	db	'vmin~~.u16',0x00
	dw	ARM_instruction_vmin.u16-instruction_handler
	db	'vmin~~.u32',0x00
	dw	ARM_instruction_vmin.u32-instruction_handler
	db	'vmlal~~.s8',0x00
	dw	ARM_instruction_vmlal.s8-instruction_handler
	db	'vmlal~~.u8',0x00
	dw	ARM_instruction_vmlal.u8-instruction_handler
	db	'vmla~~.f32',0x00
	dw	ARM_instruction_vmla.f32-instruction_handler
	db	'vmla~~.f64',0x00
	dw	ARM_instruction_vmla.f64-instruction_handler
	db	'vmla~~.i16',0x00
	dw	ARM_instruction_vmla.i16-instruction_handler
	db	'vmla~~.i32',0x00
	dw	ARM_instruction_vmla.i32-instruction_handler
	db	'vmla~~.s16',0x00
	dw	ARM_instruction_vmla.s16-instruction_handler
	db	'vmla~~.s32',0x00
	dw	ARM_instruction_vmla.s32-instruction_handler
	db	'vmla~~.u16',0x00
	dw	ARM_instruction_vmla.u16-instruction_handler
	db	'vmla~~.u32',0x00
	dw	ARM_instruction_vmla.u32-instruction_handler
	db	'vmlsl~~.s8',0x00
	dw	ARM_instruction_vmlsl.s8-instruction_handler
	db	'vmlsl~~.u8',0x00
	dw	ARM_instruction_vmlsl.u8-instruction_handler
	db	'vmls~~.f32',0x00
	dw	ARM_instruction_vmls.f32-instruction_handler
	db	'vmls~~.f64',0x00
	dw	ARM_instruction_vmls.f64-instruction_handler
	db	'vmls~~.i16',0x00
	dw	ARM_instruction_vmls.i16-instruction_handler
	db	'vmls~~.i32',0x00
	dw	ARM_instruction_vmls.i32-instruction_handler
	db	'vmls~~.s16',0x00
	dw	ARM_instruction_vmls.s16-instruction_handler
	db	'vmls~~.s32',0x00
	dw	ARM_instruction_vmls.s32-instruction_handler
	db	'vmls~~.u16',0x00
	dw	ARM_instruction_vmls.u16-instruction_handler
	db	'vmls~~.u32',0x00
	dw	ARM_instruction_vmls.u32-instruction_handler
	db	'vmovl~~.s8',0x00
	dw	ARM_instruction_vmovl.s8-instruction_handler
	db	'vmovl~~.u8',0x00
	dw	ARM_instruction_vmovl.u8-instruction_handler
	db	'vmovn~~.i8',0x00
	dw	ARM_instruction_vmovn.i8-instruction_handler
	db	'vmov~~.f32',0x00
	dw	ARM_instruction_vmov.f32-instruction_handler
	db	'vmov~~.f64',0x00
	dw	ARM_instruction_vmov.f64-instruction_handler
	db	'vmov~~.i16',0x00
	dw	ARM_instruction_vmov.i16-instruction_handler
	db	'vmov~~.i32',0x00
	dw	ARM_instruction_vmov.i32-instruction_handler
	db	'vmov~~.i64',0x00
	dw	ARM_instruction_vmov.i64-instruction_handler
	db	'vmov~~.s16',0x00
	dw	ARM_instruction_vmov.s16-instruction_handler
	db	'vmov~~.u16',0x00
	dw	ARM_instruction_vmov.u16-instruction_handler
	db	'vmull~~.p8',0x00
	dw	ARM_instruction_vmull.p8-instruction_handler
	db	'vmull~~.s8',0x00
	dw	ARM_instruction_vmull.s8-instruction_handler
	db	'vmull~~.u8',0x00
	dw	ARM_instruction_vmull.u8-instruction_handler
	db	'vmul~~.f32',0x00
	dw	ARM_instruction_vmul.f32-instruction_handler
	db	'vmul~~.f64',0x00
	dw	ARM_instruction_vmul.f64-instruction_handler
	db	'vmul~~.i16',0x00
	dw	ARM_instruction_vmul.i16-instruction_handler
	db	'vmul~~.i32',0x00
	dw	ARM_instruction_vmul.i32-instruction_handler
	db	'vmul~~.s16',0x00
	dw	ARM_instruction_vmul.s16-instruction_handler
	db	'vmul~~.s32',0x00
	dw	ARM_instruction_vmul.s32-instruction_handler
	db	'vmul~~.u16',0x00
	dw	ARM_instruction_vmul.u16-instruction_handler
	db	'vmul~~.u32',0x00
	dw	ARM_instruction_vmul.u32-instruction_handler
	db	'vmvn~~.i16',0x00
	dw	ARM_instruction_vmvn.i16-instruction_handler
	db	'vmvn~~.i32',0x00
	dw	ARM_instruction_vmvn.i32-instruction_handler
	db	'vneg~~.f32',0x00
	dw	ARM_instruction_vneg.f32-instruction_handler
	db	'vneg~~.f64',0x00
	dw	ARM_instruction_vneg.f64-instruction_handler
	db	'vneg~~.s16',0x00
	dw	ARM_instruction_vneg.s16-instruction_handler
	db	'vneg~~.s32',0x00
	dw	ARM_instruction_vneg.s32-instruction_handler
	db	'vorn~~.i16',0x00
	dw	ARM_instruction_vorn.i16-instruction_handler
	db	'vorn~~.i32',0x00
	dw	ARM_instruction_vorn.i32-instruction_handler
	db	'vorr~~.i16',0x00
	dw	ARM_instruction_vorr.i16-instruction_handler
	db	'vorr~~.i32',0x00
	dw	ARM_instruction_vorr.i32-instruction_handler
	db	'vpadal.s16',0xe0
	dw	ARM_instruction_vpadal.s16-instruction_handler
	db	'vpadal.s32',0xe0
	dw	ARM_instruction_vpadal.s32-instruction_handler
	db	'vpadal.u16',0xe0
	dw	ARM_instruction_vpadal.u16-instruction_handler
	db	'vpadal.u32',0xe0
	dw	ARM_instruction_vpadal.u32-instruction_handler
	db	'vpaddl.s16',0xe0
	dw	ARM_instruction_vpaddl.s16-instruction_handler
	db	'vpaddl.s32',0xe0
	dw	ARM_instruction_vpaddl.s32-instruction_handler
	db	'vpaddl.u16',0xe0
	dw	ARM_instruction_vpaddl.u16-instruction_handler
	db	'vpaddl.u32',0xe0
	dw	ARM_instruction_vpaddl.u32-instruction_handler
	db	'vpadd~~.i8',0x00
	dw	ARM_instruction_vpadd.i8-instruction_handler
	db	'vpmax~~.s8',0x00
	dw	ARM_instruction_vpmax.s8-instruction_handler
	db	'vpmax~~.u8',0x00
	dw	ARM_instruction_vpmax.u8-instruction_handler
	db	'vpmin~~.s8',0x00
	dw	ARM_instruction_vpmin.s8-instruction_handler
	db	'vpmin~~.u8',0x00
	dw	ARM_instruction_vpmin.u8-instruction_handler
	db	'vqabs~~.s8',0x00
	dw	ARM_instruction_vqabs.s8-instruction_handler
	db	'vqadd~~.s8',0x00
	dw	ARM_instruction_vqadd.s8-instruction_handler
	db	'vqadd~~.u8',0x00
	dw	ARM_instruction_vqadd.u8-instruction_handler
	db	'vqmovn.s16',0xe0
	dw	ARM_instruction_vqmovn.s16-instruction_handler
	db	'vqmovn.s32',0xe0
	dw	ARM_instruction_vqmovn.s32-instruction_handler
	db	'vqmovn.s64',0xe0
	dw	ARM_instruction_vqmovn.s64-instruction_handler
	db	'vqmovn.u16',0xe0
	dw	ARM_instruction_vqmovn.u16-instruction_handler
	db	'vqmovn.u32',0xe0
	dw	ARM_instruction_vqmovn.u32-instruction_handler
	db	'vqmovn.u64',0xe0
	dw	ARM_instruction_vqmovn.u64-instruction_handler
	db	'vqneg~~.s8',0x00
	dw	ARM_instruction_vqneg.s8-instruction_handler
	db	'vqrshl.s16',0xe0
	dw	ARM_instruction_vqrshl.s16-instruction_handler
	db	'vqrshl.s32',0xe0
	dw	ARM_instruction_vqrshl.s32-instruction_handler
	db	'vqrshl.s64',0xe0
	dw	ARM_instruction_vqrshl.s64-instruction_handler
	db	'vqrshl.u16',0xe0
	dw	ARM_instruction_vqrshl.u16-instruction_handler
	db	'vqrshl.u32',0xe0
	dw	ARM_instruction_vqrshl.u32-instruction_handler
	db	'vqrshl.u64',0xe0
	dw	ARM_instruction_vqrshl.u64-instruction_handler
	db	'vqshlu.s16',0xe0
	dw	ARM_instruction_vqshlu.s16-instruction_handler
	db	'vqshlu.s32',0xe0
	dw	ARM_instruction_vqshlu.s32-instruction_handler
	db	'vqshlu.s64',0xe0
	dw	ARM_instruction_vqshlu.s64-instruction_handler
	db	'vqshl~~.s8',0x00
	dw	ARM_instruction_vqshl.s8-instruction_handler
	db	'vqshl~~.u8',0x00
	dw	ARM_instruction_vqshl.u8-instruction_handler
	db	'vqshrn.s16',0xe0
	dw	ARM_instruction_vqshrn.s16-instruction_handler
	db	'vqshrn.s32',0xe0
	dw	ARM_instruction_vqshrn.s32-instruction_handler
	db	'vqshrn.s64',0xe0
	dw	ARM_instruction_vqshrn.s64-instruction_handler
	db	'vqshrn.u16',0xe0
	dw	ARM_instruction_vqshrn.u16-instruction_handler
	db	'vqshrn.u32',0xe0
	dw	ARM_instruction_vqshrn.u32-instruction_handler
	db	'vqshrn.u64',0xe0
	dw	ARM_instruction_vqshrn.u64-instruction_handler
	db	'vqsub~~.s8',0x00
	dw	ARM_instruction_vqsub.s8-instruction_handler
	db	'vqsub~~.u8',0x00
	dw	ARM_instruction_vqsub.u8-instruction_handler
	db	'vrecpe.f32',0xe0
	dw	ARM_instruction_vrecpe.f32-instruction_handler
	db	'vrecpe.u32',0xe0
	dw	ARM_instruction_vrecpe.u32-instruction_handler
	db	'vrecps.f32',0xe0
	dw	ARM_instruction_vrecps.f32-instruction_handler
	db	'vrev16~~.8',0x00
	dw	ARM_instruction_vrev16.8-instruction_handler
	db	'vrev32~~.8',0x00
	dw	ARM_instruction_vrev32.8-instruction_handler
	db	'vrev64~~.8',0x00
	dw	ARM_instruction_vrev64.8-instruction_handler
	db	'vrhadd.s16',0xe0
	dw	ARM_instruction_vrhadd.s16-instruction_handler
	db	'vrhadd.s32',0xe0
	dw	ARM_instruction_vrhadd.s32-instruction_handler
	db	'vrhadd.u16',0xe0
	dw	ARM_instruction_vrhadd.u16-instruction_handler
	db	'vrhadd.u32',0xe0
	dw	ARM_instruction_vrhadd.u32-instruction_handler
	db	'vrshl~~.s8',0x00
	dw	ARM_instruction_vrshl.s8-instruction_handler
	db	'vrshl~~.u8',0x00
	dw	ARM_instruction_vrshl.u8-instruction_handler
	db	'vrshrn.i16',0xe0
	dw	ARM_instruction_vrshrn.i16-instruction_handler
	db	'vrshrn.i32',0xe0
	dw	ARM_instruction_vrshrn.i32-instruction_handler
	db	'vrshrn.i64',0xe0
	dw	ARM_instruction_vrshrn.i64-instruction_handler
	db	'vrshr~~.s8',0x00
	dw	ARM_instruction_vrshr.s8-instruction_handler
	db	'vrshr~~.u8',0x00
	dw	ARM_instruction_vrshr.u8-instruction_handler
	db	'vrsra~~.s8',0x00
	dw	ARM_instruction_vrsra.s8-instruction_handler
	db	'vrsra~~.u8',0x00
	dw	ARM_instruction_vrsra.u8-instruction_handler
	db	'vseleq.f32',0xf0
	dw	ARM_instruction_vseleq.f32-instruction_handler
	db	'vseleq.f64',0xf0
	dw	ARM_instruction_vseleq.f64-instruction_handler
	db	'vselge.f32',0xf0
	dw	ARM_instruction_vselge.f32-instruction_handler
	db	'vselge.f64',0xf0
	dw	ARM_instruction_vselge.f64-instruction_handler
	db	'vselgt.f32',0xf0
	dw	ARM_instruction_vselgt.f32-instruction_handler
	db	'vselgt.f64',0xf0
	dw	ARM_instruction_vselgt.f64-instruction_handler
	db	'vselvs.f32',0xf0
	dw	ARM_instruction_vselvs.f32-instruction_handler
	db	'vselvs.f64',0xf0
	dw	ARM_instruction_vselvs.f64-instruction_handler
	db	'vshll~~.i8',0x00
	dw	ARM_instruction_vshll.i8-instruction_handler
	db	'vshll~~.s8',0x00
	dw	ARM_instruction_vshll.s8-instruction_handler
	db	'vshll~~.u8',0x00
	dw	ARM_instruction_vshll.u8-instruction_handler
	db	'vshl~~.i16',0x00
	dw	ARM_instruction_vshl.i16-instruction_handler
	db	'vshl~~.i32',0x00
	dw	ARM_instruction_vshl.i32-instruction_handler
	db	'vshl~~.i64',0x00
	dw	ARM_instruction_vshl.i64-instruction_handler
	db	'vshl~~.s16',0x00
	dw	ARM_instruction_vshl.s16-instruction_handler
	db	'vshl~~.s32',0x00
	dw	ARM_instruction_vshl.s32-instruction_handler
	db	'vshl~~.s64',0x00
	dw	ARM_instruction_vshl.s64-instruction_handler
	db	'vshl~~.u16',0x00
	dw	ARM_instruction_vshl.u16-instruction_handler
	db	'vshl~~.u32',0x00
	dw	ARM_instruction_vshl.u32-instruction_handler
	db	'vshl~~.u64',0x00
	dw	ARM_instruction_vshl.u64-instruction_handler
	db	'vshr~~.s16',0x00
	dw	ARM_instruction_vshr.s16-instruction_handler
	db	'vshr~~.s32',0x00
	dw	ARM_instruction_vshr.s32-instruction_handler
	db	'vshr~~.s64',0x00
	dw	ARM_instruction_vshr.s64-instruction_handler
	db	'vshr~~.u16',0x00
	dw	ARM_instruction_vshr.u16-instruction_handler
	db	'vshr~~.u32',0x00
	dw	ARM_instruction_vshr.u32-instruction_handler
	db	'vshr~~.u64',0x00
	dw	ARM_instruction_vshr.u64-instruction_handler
	db	'vsra~~.s16',0x00
	dw	ARM_instruction_vsra.s16-instruction_handler
	db	'vsra~~.s32',0x00
	dw	ARM_instruction_vsra.s32-instruction_handler
	db	'vsra~~.s64',0x00
	dw	ARM_instruction_vsra.s64-instruction_handler
	db	'vsra~~.u16',0x00
	dw	ARM_instruction_vsra.u16-instruction_handler
	db	'vsra~~.u32',0x00
	dw	ARM_instruction_vsra.u32-instruction_handler
	db	'vsra~~.u64',0x00
	dw	ARM_instruction_vsra.u64-instruction_handler
	db	'vsubhn.i16',0xe0
	dw	ARM_instruction_vsubhn.i16-instruction_handler
	db	'vsubhn.i32',0xe0
	dw	ARM_instruction_vsubhn.i32-instruction_handler
	db	'vsubhn.i64',0xe0
	dw	ARM_instruction_vsubhn.i64-instruction_handler
	db	'vsubl~~.s8',0x00
	dw	ARM_instruction_vsubl.s8-instruction_handler
	db	'vsubl~~.u8',0x00
	dw	ARM_instruction_vsubl.u8-instruction_handler
	db	'vsubw~~.s8',0x00
	dw	ARM_instruction_vsubw.s8-instruction_handler
	db	'vsubw~~.u8',0x00
	dw	ARM_instruction_vsubw.u8-instruction_handler
	db	'vsub~~.f32',0x00
	dw	ARM_instruction_vsub.f32-instruction_handler
	db	'vsub~~.f64',0x00
	dw	ARM_instruction_vsub.f64-instruction_handler
	db	'vsub~~.i16',0x00
	dw	ARM_instruction_vsub.i16-instruction_handler
	db	'vsub~~.i32',0x00
	dw	ARM_instruction_vsub.i32-instruction_handler
	db	'vsub~~.i64',0x00
	dw	ARM_instruction_vsub.i64-instruction_handler
	db	'walignr0~~',0x00
	dw	ARM_instruction_walignr0-instruction_handler
	db	'walignr1~~',0x00
	dw	ARM_instruction_walignr1-instruction_handler
	db	'walignr2~~',0x00
	dw	ARM_instruction_walignr2-instruction_handler
	db	'walignr3~~',0x00
	dw	ARM_instruction_walignr3-instruction_handler
	db	'wcmpgtsb~~',0x00
	dw	ARM_instruction_wcmpgtsb-instruction_handler
	db	'wcmpgtsh~~',0x00
	dw	ARM_instruction_wcmpgtsh-instruction_handler
	db	'wcmpgtsw~~',0x00
	dw	ARM_instruction_wcmpgtsw-instruction_handler
	db	'wcmpgtub~~',0x00
	dw	ARM_instruction_wcmpgtub-instruction_handler
	db	'wcmpgtuh~~',0x00
	dw	ARM_instruction_wcmpgtuh-instruction_handler
	db	'wcmpgtuw~~',0x00
	dw	ARM_instruction_wcmpgtuw-instruction_handler
	db	'wmiawbbn~~',0x00
	dw	ARM_instruction_wmiawbbn-instruction_handler
	db	'wmiawbtn~~',0x00
	dw	ARM_instruction_wmiawbtn-instruction_handler
	db	'wmiawtbn~~',0x00
	dw	ARM_instruction_wmiawtbn-instruction_handler
	db	'wmiawttn~~',0x00
	dw	ARM_instruction_wmiawttn-instruction_handler
	db	'wmulwsmr~~',0x00
	dw	ARM_instruction_wmulwsmr-instruction_handler
	db	'wmulwumr~~',0x00
	dw	ARM_instruction_wmulwumr-instruction_handler
	db	'wpackdss~~',0x00
	dw	ARM_instruction_wpackdss-instruction_handler
	db	'wpackdus~~',0x00
	dw	ARM_instruction_wpackdus-instruction_handler
	db	'wpackhss~~',0x00
	dw	ARM_instruction_wpackhss-instruction_handler
	db	'wpackhus~~',0x00
	dw	ARM_instruction_wpackhus-instruction_handler
	db	'wpackwss~~',0x00
	dw	ARM_instruction_wpackwss-instruction_handler
	db	'wpackwus~~',0x00
	dw	ARM_instruction_wpackwus-instruction_handler
	db	'wqmiabbn~~',0x00
	dw	ARM_instruction_wqmiabbn-instruction_handler
	db	'wqmiabtn~~',0x00
	dw	ARM_instruction_wqmiabtn-instruction_handler
	db	'wqmiatbn~~',0x00
	dw	ARM_instruction_wqmiatbn-instruction_handler
	db	'wqmiattn~~',0x00
	dw	ARM_instruction_wqmiattn-instruction_handler
	db	'wqmulwmr~~',0x00
	dw	ARM_instruction_wqmulwmr-instruction_handler
	db	'wunpckehsb',0xe0
	dw	ARM_instruction_wunpckehsb-instruction_handler
	db	'wunpckehsh',0xe0
	dw	ARM_instruction_wunpckehsh-instruction_handler
	db	'wunpckehsw',0xe0
	dw	ARM_instruction_wunpckehsw-instruction_handler
	db	'wunpckehub',0xe0
	dw	ARM_instruction_wunpckehub-instruction_handler
	db	'wunpckehuh',0xe0
	dw	ARM_instruction_wunpckehuh-instruction_handler
	db	'wunpckehuw',0xe0
	dw	ARM_instruction_wunpckehuw-instruction_handler
	db	'wunpckelsb',0xe0
	dw	ARM_instruction_wunpckelsb-instruction_handler
	db	'wunpckelsh',0xe0
	dw	ARM_instruction_wunpckelsh-instruction_handler
	db	'wunpckelsw',0xe0
	dw	ARM_instruction_wunpckelsw-instruction_handler
	db	'wunpckelub',0xe0
	dw	ARM_instruction_wunpckelub-instruction_handler
	db	'wunpckeluh',0xe0
	dw	ARM_instruction_wunpckeluh-instruction_handler
	db	'wunpckeluw',0xe0
	dw	ARM_instruction_wunpckeluw-instruction_handler
	db	0
instructions_11:
	db	'cfmadda32~~',0x00
	dw	ARM_instruction_cfmadda32-instruction_handler
	db	'cfmsuba32~~',0x00
	dw	ARM_instruction_cfmsuba32-instruction_handler
	db	'coprocessor',0x00
	dw	ARM_coprocessor_directive-instruction_handler
	db	'sha256h2.32',0xf0
	dw	ARM_instruction_sha256h2.32-instruction_handler
	db	'shaddsubx~~',0x00
	dw	ARM_instruction_shaddsubx-instruction_handler
	db	'shsubaddx~~',0x00
	dw	ARM_instruction_shsubaddx-instruction_handler
	db	'uhaddsubx~~',0x00
	dw	ARM_instruction_uhaddsubx-instruction_handler
	db	'uhsubaddx~~',0x00
	dw	ARM_instruction_uhsubaddx-instruction_handler
	db	'uqaddsubx~~',0x00
	dw	ARM_instruction_uqaddsubx-instruction_handler
	db	'uqsubaddx~~',0x00
	dw	ARM_instruction_uqsubaddx-instruction_handler
	db	'vabal~~.s16',0x00
	dw	ARM_instruction_vabal.s16-instruction_handler
	db	'vabal~~.s32',0x00
	dw	ARM_instruction_vabal.s32-instruction_handler
	db	'vabal~~.u16',0x00
	dw	ARM_instruction_vabal.u16-instruction_handler
	db	'vabal~~.u32',0x00
	dw	ARM_instruction_vabal.u32-instruction_handler
	db	'vabdl~~.s16',0x00
	dw	ARM_instruction_vabdl.s16-instruction_handler
	db	'vabdl~~.s32',0x00
	dw	ARM_instruction_vabdl.s32-instruction_handler
	db	'vabdl~~.u16',0x00
	dw	ARM_instruction_vabdl.u16-instruction_handler
	db	'vabdl~~.u32',0x00
	dw	ARM_instruction_vabdl.u32-instruction_handler
	db	'vacge~~.f32',0x00
	dw	ARM_instruction_vacge.f32-instruction_handler
	db	'vacgt~~.f32',0x00
	dw	ARM_instruction_vacgt.f32-instruction_handler
	db	'vacle~~.f32',0x00
	dw	ARM_instruction_vacle.f32-instruction_handler
	db	'vaclt~~.f32',0x00
	dw	ARM_instruction_vaclt.f32-instruction_handler
	db	'vaddl~~.s16',0x00
	dw	ARM_instruction_vaddl.s16-instruction_handler
	db	'vaddl~~.s32',0x00
	dw	ARM_instruction_vaddl.s32-instruction_handler
	db	'vaddl~~.u16',0x00
	dw	ARM_instruction_vaddl.u16-instruction_handler
	db	'vaddl~~.u32',0x00
	dw	ARM_instruction_vaddl.u32-instruction_handler
	db	'vaddw~~.s16',0x00
	dw	ARM_instruction_vaddw.s16-instruction_handler
	db	'vaddw~~.s32',0x00
	dw	ARM_instruction_vaddw.s32-instruction_handler
	db	'vaddw~~.u16',0x00
	dw	ARM_instruction_vaddw.u16-instruction_handler
	db	'vaddw~~.u32',0x00
	dw	ARM_instruction_vaddw.u32-instruction_handler
	db	'vcmpe~~.f32',0x00
	dw	ARM_instruction_vcmpe.f32-instruction_handler
	db	'vcmpe~~.f64',0x00
	dw	ARM_instruction_vcmpe.f64-instruction_handler
	db	'vfnma~~.f32',0x00
	dw	ARM_instruction_vfnma.f32-instruction_handler
	db	'vfnma~~.f64',0x00
	dw	ARM_instruction_vfnma.f64-instruction_handler
	db	'vfnms~~.f32',0x00
	dw	ARM_instruction_vfnms.f32-instruction_handler
	db	'vfnms~~.f64',0x00
	dw	ARM_instruction_vfnms.f64-instruction_handler
	db	'vhadd~~.s16',0x00
	dw	ARM_instruction_vhadd.s16-instruction_handler
	db	'vhadd~~.s32',0x00
	dw	ARM_instruction_vhadd.s32-instruction_handler
	db	'vhadd~~.u16',0x00
	dw	ARM_instruction_vhadd.u16-instruction_handler
	db	'vhadd~~.u32',0x00
	dw	ARM_instruction_vhadd.u32-instruction_handler
	db	'vhsub~~.s16',0x00
	dw	ARM_instruction_vhsub.s16-instruction_handler
	db	'vhsub~~.s32',0x00
	dw	ARM_instruction_vhsub.s32-instruction_handler
	db	'vhsub~~.u16',0x00
	dw	ARM_instruction_vhsub.u16-instruction_handler
	db	'vhsub~~.u32',0x00
	dw	ARM_instruction_vhsub.u32-instruction_handler
	db	'vldmdb~~.32',0x00
	dw	ARM_instruction_vldmdb.32-instruction_handler
	db	'vldmdb~~.64',0x00
	dw	ARM_instruction_vldmdb.64-instruction_handler
	db	'vldmea~~.32',0x00
	dw	ARM_instruction_vldmea.32-instruction_handler
	db	'vldmea~~.64',0x00
	dw	ARM_instruction_vldmea.64-instruction_handler
	db	'vldmfd~~.32',0x00
	dw	ARM_instruction_vldmfd.32-instruction_handler
	db	'vldmfd~~.64',0x00
	dw	ARM_instruction_vldmfd.64-instruction_handler
	db	'vldmia~~.32',0x00
	dw	ARM_instruction_vldmia.32-instruction_handler
	db	'vldmia~~.64',0x00
	dw	ARM_instruction_vldmia.64-instruction_handler
	db	'vmlal~~.s16',0x00
	dw	ARM_instruction_vmlal.s16-instruction_handler
	db	'vmlal~~.s32',0x00
	dw	ARM_instruction_vmlal.s32-instruction_handler
	db	'vmlal~~.u16',0x00
	dw	ARM_instruction_vmlal.u16-instruction_handler
	db	'vmlal~~.u32',0x00
	dw	ARM_instruction_vmlal.u32-instruction_handler
	db	'vmlsl~~.s16',0x00
	dw	ARM_instruction_vmlsl.s16-instruction_handler
	db	'vmlsl~~.s32',0x00
	dw	ARM_instruction_vmlsl.s32-instruction_handler
	db	'vmlsl~~.u16',0x00
	dw	ARM_instruction_vmlsl.u16-instruction_handler
	db	'vmlsl~~.u32',0x00
	dw	ARM_instruction_vmlsl.u32-instruction_handler
	db	'vmovl~~.s16',0x00
	dw	ARM_instruction_vmovl.s16-instruction_handler
	db	'vmovl~~.s32',0x00
	dw	ARM_instruction_vmovl.s32-instruction_handler
	db	'vmovl~~.u16',0x00
	dw	ARM_instruction_vmovl.u16-instruction_handler
	db	'vmovl~~.u32',0x00
	dw	ARM_instruction_vmovl.u32-instruction_handler
	db	'vmovn~~.i16',0x00
	dw	ARM_instruction_vmovn.i16-instruction_handler
	db	'vmovn~~.i32',0x00
	dw	ARM_instruction_vmovn.i32-instruction_handler
	db	'vmull~~.s16',0x00
	dw	ARM_instruction_vmull.s16-instruction_handler
	db	'vmull~~.s32',0x00
	dw	ARM_instruction_vmull.s32-instruction_handler
	db	'vmull~~.u16',0x00
	dw	ARM_instruction_vmull.u16-instruction_handler
	db	'vmull~~.u32',0x00
	dw	ARM_instruction_vmull.u32-instruction_handler
	db	'vnmla~~.f32',0x00
	dw	ARM_instruction_vnmla.f32-instruction_handler
	db	'vnmla~~.f64',0x00
	dw	ARM_instruction_vnmla.f64-instruction_handler
	db	'vnmls~~.f32',0x00
	dw	ARM_instruction_vnmls.f32-instruction_handler
	db	'vnmls~~.f64',0x00
	dw	ARM_instruction_vnmls.f64-instruction_handler
	db	'vnmul~~.f32',0x00
	dw	ARM_instruction_vnmul.f32-instruction_handler
	db	'vnmul~~.f64',0x00
	dw	ARM_instruction_vnmul.f64-instruction_handler
	db	'vpadal~~.s8',0x00
	dw	ARM_instruction_vpadal.s8-instruction_handler
	db	'vpadal~~.u8',0x00
	dw	ARM_instruction_vpadal.u8-instruction_handler
	db	'vpaddl~~.s8',0x00
	dw	ARM_instruction_vpaddl.s8-instruction_handler
	db	'vpaddl~~.u8',0x00
	dw	ARM_instruction_vpaddl.u8-instruction_handler
	db	'vpadd~~.f32',0x00
	dw	ARM_instruction_vpadd.f32-instruction_handler
	db	'vpadd~~.i16',0x00
	dw	ARM_instruction_vpadd.i16-instruction_handler
	db	'vpadd~~.i32',0x00
	dw	ARM_instruction_vpadd.i32-instruction_handler
	db	'vpmax~~.f32',0x00
	dw	ARM_instruction_vpmax.f32-instruction_handler
	db	'vpmax~~.s16',0x00
	dw	ARM_instruction_vpmax.s16-instruction_handler
	db	'vpmax~~.s32',0x00
	dw	ARM_instruction_vpmax.s32-instruction_handler
	db	'vpmax~~.u16',0x00
	dw	ARM_instruction_vpmax.u16-instruction_handler
	db	'vpmax~~.u32',0x00
	dw	ARM_instruction_vpmax.u32-instruction_handler
	db	'vpmin~~.f32',0x00
	dw	ARM_instruction_vpmin.f32-instruction_handler
	db	'vpmin~~.s16',0x00
	dw	ARM_instruction_vpmin.s16-instruction_handler
	db	'vpmin~~.s32',0x00
	dw	ARM_instruction_vpmin.s32-instruction_handler
	db	'vpmin~~.u16',0x00
	dw	ARM_instruction_vpmin.u16-instruction_handler
	db	'vpmin~~.u32',0x00
	dw	ARM_instruction_vpmin.u32-instruction_handler
	db	'vqabs~~.s16',0x00
	dw	ARM_instruction_vqabs.s16-instruction_handler
	db	'vqabs~~.s32',0x00
	dw	ARM_instruction_vqabs.s32-instruction_handler
	db	'vqadd~~.s16',0x00
	dw	ARM_instruction_vqadd.s16-instruction_handler
	db	'vqadd~~.s32',0x00
	dw	ARM_instruction_vqadd.s32-instruction_handler
	db	'vqadd~~.s64',0x00
	dw	ARM_instruction_vqadd.s64-instruction_handler
	db	'vqadd~~.u16',0x00
	dw	ARM_instruction_vqadd.u16-instruction_handler
	db	'vqadd~~.u32',0x00
	dw	ARM_instruction_vqadd.u32-instruction_handler
	db	'vqadd~~.u64',0x00
	dw	ARM_instruction_vqadd.u64-instruction_handler
	db	'vqdmlal.s16',0xe0
	dw	ARM_instruction_vqdmlal.s16-instruction_handler
	db	'vqdmlal.s32',0xe0
	dw	ARM_instruction_vqdmlal.s32-instruction_handler
	db	'vqdmlsl.s16',0xe0
	dw	ARM_instruction_vqdmlsl.s16-instruction_handler
	db	'vqdmlsl.s32',0xe0
	dw	ARM_instruction_vqdmlsl.s32-instruction_handler
	db	'vqdmulh.s16',0xe0
	dw	ARM_instruction_vqdmulh.s16-instruction_handler
	db	'vqdmulh.s32',0xe0
	dw	ARM_instruction_vqdmulh.s32-instruction_handler
	db	'vqdmull.s16',0xe0
	dw	ARM_instruction_vqdmull.s16-instruction_handler
	db	'vqdmull.s32',0xe0
	dw	ARM_instruction_vqdmull.s32-instruction_handler
	db	'vqmovun.s16',0xe0
	dw	ARM_instruction_vqmovun.s16-instruction_handler
	db	'vqmovun.s32',0xe0
	dw	ARM_instruction_vqmovun.s32-instruction_handler
	db	'vqmovun.s64',0xe0
	dw	ARM_instruction_vqmovun.s64-instruction_handler
	db	'vqneg~~.s16',0x00
	dw	ARM_instruction_vqneg.s16-instruction_handler
	db	'vqneg~~.s32',0x00
	dw	ARM_instruction_vqneg.s32-instruction_handler
	db	'vqrshl~~.s8',0x00
	dw	ARM_instruction_vqrshl.s8-instruction_handler
	db	'vqrshl~~.u8',0x00
	dw	ARM_instruction_vqrshl.u8-instruction_handler
	db	'vqrshrn.s16',0xe0
	dw	ARM_instruction_vqrshrn.s16-instruction_handler
	db	'vqrshrn.s32',0xe0
	dw	ARM_instruction_vqrshrn.s32-instruction_handler
	db	'vqrshrn.s64',0xe0
	dw	ARM_instruction_vqrshrn.s64-instruction_handler
	db	'vqrshrn.u16',0xe0
	dw	ARM_instruction_vqrshrn.u16-instruction_handler
	db	'vqrshrn.u32',0xe0
	dw	ARM_instruction_vqrshrn.u32-instruction_handler
	db	'vqrshrn.u64',0xe0
	dw	ARM_instruction_vqrshrn.u64-instruction_handler
	db	'vqshlu~~.s8',0x00
	dw	ARM_instruction_vqshlu.s8-instruction_handler
	db	'vqshl~~.s16',0x00
	dw	ARM_instruction_vqshl.s16-instruction_handler
	db	'vqshl~~.s32',0x00
	dw	ARM_instruction_vqshl.s32-instruction_handler
	db	'vqshl~~.s64',0x00
	dw	ARM_instruction_vqshl.s64-instruction_handler
	db	'vqshl~~.u16',0x00
	dw	ARM_instruction_vqshl.u16-instruction_handler
	db	'vqshl~~.u32',0x00
	dw	ARM_instruction_vqshl.u32-instruction_handler
	db	'vqshl~~.u64',0x00
	dw	ARM_instruction_vqshl.u64-instruction_handler
	db	'vqshrun.s16',0xe0
	dw	ARM_instruction_vqshrun.s16-instruction_handler
	db	'vqshrun.s32',0xe0
	dw	ARM_instruction_vqshrun.s32-instruction_handler
	db	'vqshrun.s64',0xe0
	dw	ARM_instruction_vqshrun.s64-instruction_handler
	db	'vqsub~~.s16',0x00
	dw	ARM_instruction_vqsub.s16-instruction_handler
	db	'vqsub~~.s32',0x00
	dw	ARM_instruction_vqsub.s32-instruction_handler
	db	'vqsub~~.s64',0x00
	dw	ARM_instruction_vqsub.s64-instruction_handler
	db	'vqsub~~.u16',0x00
	dw	ARM_instruction_vqsub.u16-instruction_handler
	db	'vqsub~~.u32',0x00
	dw	ARM_instruction_vqsub.u32-instruction_handler
	db	'vqsub~~.u64',0x00
	dw	ARM_instruction_vqsub.u64-instruction_handler
	db	'vraddhn.i16',0xe0
	dw	ARM_instruction_vraddhn.i16-instruction_handler
	db	'vraddhn.i32',0xe0
	dw	ARM_instruction_vraddhn.i32-instruction_handler
	db	'vraddhn.i64',0xe0
	dw	ARM_instruction_vraddhn.i64-instruction_handler
	db	'vrev32~~.16',0x00
	dw	ARM_instruction_vrev32.16-instruction_handler
	db	'vrev64~~.16',0x00
	dw	ARM_instruction_vrev64.16-instruction_handler
	db	'vrev64~~.32',0x00
	dw	ARM_instruction_vrev64.32-instruction_handler
	db	'vrhadd~~.s8',0x00
	dw	ARM_instruction_vrhadd.s8-instruction_handler
	db	'vrhadd~~.u8',0x00
	dw	ARM_instruction_vrhadd.u8-instruction_handler
	db	'vrshl~~.s16',0x00
	dw	ARM_instruction_vrshl.s16-instruction_handler
	db	'vrshl~~.s32',0x00
	dw	ARM_instruction_vrshl.s32-instruction_handler
	db	'vrshl~~.s64',0x00
	dw	ARM_instruction_vrshl.s64-instruction_handler
	db	'vrshl~~.u16',0x00
	dw	ARM_instruction_vrshl.u16-instruction_handler
	db	'vrshl~~.u32',0x00
	dw	ARM_instruction_vrshl.u32-instruction_handler
	db	'vrshl~~.u64',0x00
	dw	ARM_instruction_vrshl.u64-instruction_handler
	db	'vrshr~~.s16',0x00
	dw	ARM_instruction_vrshr.s16-instruction_handler
	db	'vrshr~~.s32',0x00
	dw	ARM_instruction_vrshr.s32-instruction_handler
	db	'vrshr~~.s64',0x00
	dw	ARM_instruction_vrshr.s64-instruction_handler
	db	'vrshr~~.u16',0x00
	dw	ARM_instruction_vrshr.u16-instruction_handler
	db	'vrshr~~.u32',0x00
	dw	ARM_instruction_vrshr.u32-instruction_handler
	db	'vrshr~~.u64',0x00
	dw	ARM_instruction_vrshr.u64-instruction_handler
	db	'vrsqrte.f32',0xe0
	dw	ARM_instruction_vrsqrte.f32-instruction_handler
	db	'vrsqrte.u32',0xe0
	dw	ARM_instruction_vrsqrte.u32-instruction_handler
	db	'vrsqrts.f32',0xe0
	dw	ARM_instruction_vrsqrts.f32-instruction_handler
	db	'vrsra~~.s16',0x00
	dw	ARM_instruction_vrsra.s16-instruction_handler
	db	'vrsra~~.s32',0x00
	dw	ARM_instruction_vrsra.s32-instruction_handler
	db	'vrsra~~.s64',0x00
	dw	ARM_instruction_vrsra.s64-instruction_handler
	db	'vrsra~~.u16',0x00
	dw	ARM_instruction_vrsra.u16-instruction_handler
	db	'vrsra~~.u32',0x00
	dw	ARM_instruction_vrsra.u32-instruction_handler
	db	'vrsra~~.u64',0x00
	dw	ARM_instruction_vrsra.u64-instruction_handler
	db	'vrsubhn.i16',0xe0
	dw	ARM_instruction_vrsubhn.i16-instruction_handler
	db	'vrsubhn.i32',0xe0
	dw	ARM_instruction_vrsubhn.i32-instruction_handler
	db	'vrsubhn.i64',0xe0
	dw	ARM_instruction_vrsubhn.i64-instruction_handler
	db	'vshll~~.i16',0x00
	dw	ARM_instruction_vshll.i16-instruction_handler
	db	'vshll~~.i32',0x00
	dw	ARM_instruction_vshll.i32-instruction_handler
	db	'vshll~~.s16',0x00
	dw	ARM_instruction_vshll.s16-instruction_handler
	db	'vshll~~.s32',0x00
	dw	ARM_instruction_vshll.s32-instruction_handler
	db	'vshll~~.u16',0x00
	dw	ARM_instruction_vshll.u16-instruction_handler
	db	'vshll~~.u32',0x00
	dw	ARM_instruction_vshll.u32-instruction_handler
	db	'vshrn~~.i16',0x00
	dw	ARM_instruction_vshrn.i16-instruction_handler
	db	'vshrn~~.i32',0x00
	dw	ARM_instruction_vshrn.i32-instruction_handler
	db	'vshrn~~.i64',0x00
	dw	ARM_instruction_vshrn.i64-instruction_handler
	db	'vsqrt~~.f32',0x00
	dw	ARM_instruction_vsqrt.f32-instruction_handler
	db	'vsqrt~~.f64',0x00
	dw	ARM_instruction_vsqrt.f64-instruction_handler
	db	'vstmdb~~.32',0x00
	dw	ARM_instruction_vstmdb.32-instruction_handler
	db	'vstmdb~~.64',0x00
	dw	ARM_instruction_vstmdb.64-instruction_handler
	db	'vstmea~~.32',0x00
	dw	ARM_instruction_vstmea.32-instruction_handler
	db	'vstmea~~.64',0x00
	dw	ARM_instruction_vstmea.64-instruction_handler
	db	'vstmfd~~.32',0x00
	dw	ARM_instruction_vstmfd.32-instruction_handler
	db	'vstmfd~~.64',0x00
	dw	ARM_instruction_vstmfd.64-instruction_handler
	db	'vstmia~~.32',0x00
	dw	ARM_instruction_vstmia.32-instruction_handler
	db	'vstmia~~.64',0x00
	dw	ARM_instruction_vstmia.64-instruction_handler
	db	'vsubl~~.s16',0x00
	dw	ARM_instruction_vsubl.s16-instruction_handler
	db	'vsubl~~.s32',0x00
	dw	ARM_instruction_vsubl.s32-instruction_handler
	db	'vsubl~~.u16',0x00
	dw	ARM_instruction_vsubl.u16-instruction_handler
	db	'vsubl~~.u32',0x00
	dw	ARM_instruction_vsubl.u32-instruction_handler
	db	'vsubw~~.s16',0x00
	dw	ARM_instruction_vsubw.s16-instruction_handler
	db	'vsubw~~.s32',0x00
	dw	ARM_instruction_vsubw.s32-instruction_handler
	db	'vsubw~~.u16',0x00
	dw	ARM_instruction_vsubw.u16-instruction_handler
	db	'vsubw~~.u32',0x00
	dw	ARM_instruction_vsubw.u32-instruction_handler
	db	'wabsdiffb~~',0x00
	dw	ARM_instruction_wabsdiffb-instruction_handler
	db	'wabsdiffh~~',0x00
	dw	ARM_instruction_wabsdiffh-instruction_handler
	db	'wabsdiffw~~',0x00
	dw	ARM_instruction_wabsdiffw-instruction_handler
	db	'waddsubhx~~',0x00
	dw	ARM_instruction_waddsubhx-instruction_handler
	db	'wsubaddhx~~',0x00
	dw	ARM_instruction_wsubaddhx-instruction_handler
	db	'wunpckihb~~',0x00
	dw	ARM_instruction_wunpckihb-instruction_handler
	db	'wunpckihh~~',0x00
	dw	ARM_instruction_wunpckihh-instruction_handler
	db	'wunpckihw~~',0x00
	dw	ARM_instruction_wunpckihw-instruction_handler
	db	'wunpckilb~~',0x00
	dw	ARM_instruction_wunpckilb-instruction_handler
	db	'wunpckilh~~',0x00
	dw	ARM_instruction_wunpckilh-instruction_handler
	db	'wunpckilw~~',0x00
	dw	ARM_instruction_wunpckilw-instruction_handler
	db	0
instructions_12:
	db	'cftruncd32~~',0x00
	dw	ARM_instruction_cftruncd32-instruction_handler
	db	'cftruncs32~~',0x00
	dw	ARM_instruction_cftruncs32-instruction_handler
	db	'sha256su0.32',0xf0
	dw	ARM_instruction_sha256su0.32-instruction_handler
	db	'sha256su1.32',0xf0
	dw	ARM_instruction_sha256su1.32-instruction_handler
	db	'vaddhn~~.i16',0x00
	dw	ARM_instruction_vaddhn.i16-instruction_handler
	db	'vaddhn~~.i32',0x00
	dw	ARM_instruction_vaddhn.i32-instruction_handler
	db	'vaddhn~~.i64',0x00
	dw	ARM_instruction_vaddhn.i64-instruction_handler
	db	'vcvt.f16.f32',0xe0
	dw	ARM_instruction_vcvt.f16.f32-instruction_handler
	db	'vcvt.f32.f16',0xe0
	dw	ARM_instruction_vcvt.f32.f16-instruction_handler
	db	'vcvt.f32.f64',0xe0
	dw	ARM_instruction_vcvt.f32.f64-instruction_handler
	db	'vcvt.f32.s16',0xe0
	dw	ARM_instruction_vcvt.f32.s16-instruction_handler
	db	'vcvt.f32.s32',0xe0
	dw	ARM_instruction_vcvt.f32.s32-instruction_handler
	db	'vcvt.f32.u16',0xe0
	dw	ARM_instruction_vcvt.f32.u16-instruction_handler
	db	'vcvt.f32.u32',0xe0
	dw	ARM_instruction_vcvt.f32.u32-instruction_handler
	db	'vcvt.f64.f32',0xe0
	dw	ARM_instruction_vcvt.f64.f32-instruction_handler
	db	'vcvt.f64.s16',0xe0
	dw	ARM_instruction_vcvt.f64.s16-instruction_handler
	db	'vcvt.f64.s32',0xe0
	dw	ARM_instruction_vcvt.f64.s32-instruction_handler
	db	'vcvt.f64.u16',0xe0
	dw	ARM_instruction_vcvt.f64.u16-instruction_handler
	db	'vcvt.f64.u32',0xe0
	dw	ARM_instruction_vcvt.f64.u32-instruction_handler
	db	'vcvt.s16.f32',0xe0
	dw	ARM_instruction_vcvt.s16.f32-instruction_handler
	db	'vcvt.s16.f64',0xe0
	dw	ARM_instruction_vcvt.s16.f64-instruction_handler
	db	'vcvt.s32.f32',0xe0
	dw	ARM_instruction_vcvt.s32.f32-instruction_handler
	db	'vcvt.s32.f64',0xe0
	dw	ARM_instruction_vcvt.s32.f64-instruction_handler
	db	'vcvt.u16.f32',0xe0
	dw	ARM_instruction_vcvt.u16.f32-instruction_handler
	db	'vcvt.u16.f64',0xe0
	dw	ARM_instruction_vcvt.u16.f64-instruction_handler
	db	'vcvt.u32.f32',0xe0
	dw	ARM_instruction_vcvt.u32.f32-instruction_handler
	db	'vcvt.u32.f64',0xe0
	dw	ARM_instruction_vcvt.u32.f64-instruction_handler
	db	'vpadal~~.s16',0x00
	dw	ARM_instruction_vpadal.s16-instruction_handler
	db	'vpadal~~.s32',0x00
	dw	ARM_instruction_vpadal.s32-instruction_handler
	db	'vpadal~~.u16',0x00
	dw	ARM_instruction_vpadal.u16-instruction_handler
	db	'vpadal~~.u32',0x00
	dw	ARM_instruction_vpadal.u32-instruction_handler
	db	'vpaddl~~.s16',0x00
	dw	ARM_instruction_vpaddl.s16-instruction_handler
	db	'vpaddl~~.s32',0x00
	dw	ARM_instruction_vpaddl.s32-instruction_handler
	db	'vpaddl~~.u16',0x00
	dw	ARM_instruction_vpaddl.u16-instruction_handler
	db	'vpaddl~~.u32',0x00
	dw	ARM_instruction_vpaddl.u32-instruction_handler
	db	'vqmovn~~.s16',0x00
	dw	ARM_instruction_vqmovn.s16-instruction_handler
	db	'vqmovn~~.s32',0x00
	dw	ARM_instruction_vqmovn.s32-instruction_handler
	db	'vqmovn~~.s64',0x00
	dw	ARM_instruction_vqmovn.s64-instruction_handler
	db	'vqmovn~~.u16',0x00
	dw	ARM_instruction_vqmovn.u16-instruction_handler
	db	'vqmovn~~.u32',0x00
	dw	ARM_instruction_vqmovn.u32-instruction_handler
	db	'vqmovn~~.u64',0x00
	dw	ARM_instruction_vqmovn.u64-instruction_handler
	db	'vqrdmulh.s16',0xe0
	dw	ARM_instruction_vqrdmulh.s16-instruction_handler
	db	'vqrdmulh.s32',0xe0
	dw	ARM_instruction_vqrdmulh.s32-instruction_handler
	db	'vqrshl~~.s16',0x00
	dw	ARM_instruction_vqrshl.s16-instruction_handler
	db	'vqrshl~~.s32',0x00
	dw	ARM_instruction_vqrshl.s32-instruction_handler
	db	'vqrshl~~.s64',0x00
	dw	ARM_instruction_vqrshl.s64-instruction_handler
	db	'vqrshl~~.u16',0x00
	dw	ARM_instruction_vqrshl.u16-instruction_handler
	db	'vqrshl~~.u32',0x00
	dw	ARM_instruction_vqrshl.u32-instruction_handler
	db	'vqrshl~~.u64',0x00
	dw	ARM_instruction_vqrshl.u64-instruction_handler
	db	'vqrshrun.s16',0xe0
	dw	ARM_instruction_vqrshrun.s16-instruction_handler
	db	'vqrshrun.s32',0xe0
	dw	ARM_instruction_vqrshrun.s32-instruction_handler
	db	'vqrshrun.s64',0xe0
	dw	ARM_instruction_vqrshrun.s64-instruction_handler
	db	'vqshlu~~.s16',0x00
	dw	ARM_instruction_vqshlu.s16-instruction_handler
	db	'vqshlu~~.s32',0x00
	dw	ARM_instruction_vqshlu.s32-instruction_handler
	db	'vqshlu~~.s64',0x00
	dw	ARM_instruction_vqshlu.s64-instruction_handler
	db	'vqshrn~~.s16',0x00
	dw	ARM_instruction_vqshrn.s16-instruction_handler
	db	'vqshrn~~.s32',0x00
	dw	ARM_instruction_vqshrn.s32-instruction_handler
	db	'vqshrn~~.s64',0x00
	dw	ARM_instruction_vqshrn.s64-instruction_handler
	db	'vqshrn~~.u16',0x00
	dw	ARM_instruction_vqshrn.u16-instruction_handler
	db	'vqshrn~~.u32',0x00
	dw	ARM_instruction_vqshrn.u32-instruction_handler
	db	'vqshrn~~.u64',0x00
	dw	ARM_instruction_vqshrn.u64-instruction_handler
	db	'vrecpe~~.f32',0x00
	dw	ARM_instruction_vrecpe.f32-instruction_handler
	db	'vrecpe~~.u32',0x00
	dw	ARM_instruction_vrecpe.u32-instruction_handler
	db	'vrecps~~.f32',0x00
	dw	ARM_instruction_vrecps.f32-instruction_handler
	db	'vrhadd~~.s16',0x00
	dw	ARM_instruction_vrhadd.s16-instruction_handler
	db	'vrhadd~~.s32',0x00
	dw	ARM_instruction_vrhadd.s32-instruction_handler
	db	'vrhadd~~.u16',0x00
	dw	ARM_instruction_vrhadd.u16-instruction_handler
	db	'vrhadd~~.u32',0x00
	dw	ARM_instruction_vrhadd.u32-instruction_handler
	db	'vrshrn~~.i16',0x00
	dw	ARM_instruction_vrshrn.i16-instruction_handler
	db	'vrshrn~~.i32',0x00
	dw	ARM_instruction_vrshrn.i32-instruction_handler
	db	'vrshrn~~.i64',0x00
	dw	ARM_instruction_vrshrn.i64-instruction_handler
	db	'vsubhn~~.i16',0x00
	dw	ARM_instruction_vsubhn.i16-instruction_handler
	db	'vsubhn~~.i32',0x00
	dw	ARM_instruction_vsubhn.i32-instruction_handler
	db	'vsubhn~~.i64',0x00
	dw	ARM_instruction_vsubhn.i64-instruction_handler
	db	'wunpckehsb~~',0x00
	dw	ARM_instruction_wunpckehsb-instruction_handler
	db	'wunpckehsh~~',0x00
	dw	ARM_instruction_wunpckehsh-instruction_handler
	db	'wunpckehsw~~',0x00
	dw	ARM_instruction_wunpckehsw-instruction_handler
	db	'wunpckehub~~',0x00
	dw	ARM_instruction_wunpckehub-instruction_handler
	db	'wunpckehuh~~',0x00
	dw	ARM_instruction_wunpckehuh-instruction_handler
	db	'wunpckehuw~~',0x00
	dw	ARM_instruction_wunpckehuw-instruction_handler
	db	'wunpckelsb~~',0x00
	dw	ARM_instruction_wunpckelsb-instruction_handler
	db	'wunpckelsh~~',0x00
	dw	ARM_instruction_wunpckelsh-instruction_handler
	db	'wunpckelsw~~',0x00
	dw	ARM_instruction_wunpckelsw-instruction_handler
	db	'wunpckelub~~',0x00
	dw	ARM_instruction_wunpckelub-instruction_handler
	db	'wunpckeluh~~',0x00
	dw	ARM_instruction_wunpckeluh-instruction_handler
	db	'wunpckeluw~~',0x00
	dw	ARM_instruction_wunpckeluw-instruction_handler
	db	0
instructions_13:
	db	'vcvta.s32.f32',0xf0
	dw	ARM_instruction_vcvta.s32.f32-instruction_handler
	db	'vcvta.s32.f64',0xf0
	dw	ARM_instruction_vcvta.s32.f64-instruction_handler
	db	'vcvta.u32.f32',0xf0
	dw	ARM_instruction_vcvta.u32.f32-instruction_handler
	db	'vcvta.u32.f64',0xf0
	dw	ARM_instruction_vcvta.u32.f64-instruction_handler
	db	'vcvtb.f16.f32',0xe0
	dw	ARM_instruction_vcvtb.f16.f32-instruction_handler
	db	'vcvtb.f16.f64',0xe0
	dw	ARM_instruction_vcvtb.f16.f64-instruction_handler
	db	'vcvtb.f32.f16',0xe0
	dw	ARM_instruction_vcvtb.f32.f16-instruction_handler
	db	'vcvtb.f64.f16',0xe0
	dw	ARM_instruction_vcvtb.f64.f16-instruction_handler
	db	'vcvtm.s32.f32',0xf0
	dw	ARM_instruction_vcvtm.s32.f32-instruction_handler
	db	'vcvtm.s32.f64',0xf0
	dw	ARM_instruction_vcvtm.s32.f64-instruction_handler
	db	'vcvtm.u32.f32',0xf0
	dw	ARM_instruction_vcvtm.u32.f32-instruction_handler
	db	'vcvtm.u32.f64',0xf0
	dw	ARM_instruction_vcvtm.u32.f64-instruction_handler
	db	'vcvtn.s32.f32',0xf0
	dw	ARM_instruction_vcvtn.s32.f32-instruction_handler
	db	'vcvtn.s32.f64',0xf0
	dw	ARM_instruction_vcvtn.s32.f64-instruction_handler
	db	'vcvtn.u32.f32',0xf0
	dw	ARM_instruction_vcvtn.u32.f32-instruction_handler
	db	'vcvtn.u32.f64',0xf0
	dw	ARM_instruction_vcvtn.u32.f64-instruction_handler
	db	'vcvtp.s32.f32',0xf0
	dw	ARM_instruction_vcvtp.s32.f32-instruction_handler
	db	'vcvtp.s32.f64',0xf0
	dw	ARM_instruction_vcvtp.s32.f64-instruction_handler
	db	'vcvtp.u32.f32',0xf0
	dw	ARM_instruction_vcvtp.u32.f32-instruction_handler
	db	'vcvtp.u32.f64',0xf0
	dw	ARM_instruction_vcvtp.u32.f64-instruction_handler
	db	'vcvtr.s32.f32',0xe0
	dw	ARM_instruction_vcvtr.s32.f32-instruction_handler
	db	'vcvtr.s32.f64',0xe0
	dw	ARM_instruction_vcvtr.s32.f64-instruction_handler
	db	'vcvtr.u32.f32',0xe0
	dw	ARM_instruction_vcvtr.u32.f32-instruction_handler
	db	'vcvtr.u32.f64',0xe0
	dw	ARM_instruction_vcvtr.u32.f64-instruction_handler
	db	'vcvtt.f16.f32',0xe0
	dw	ARM_instruction_vcvtt.f16.f32-instruction_handler
	db	'vcvtt.f16.f64',0xe0
	dw	ARM_instruction_vcvtt.f16.f64-instruction_handler
	db	'vcvtt.f32.f16',0xe0
	dw	ARM_instruction_vcvtt.f32.f16-instruction_handler
	db	'vcvtt.f64.f16',0xe0
	dw	ARM_instruction_vcvtt.f64.f16-instruction_handler
	db	'vqdmlal~~.s16',0x00
	dw	ARM_instruction_vqdmlal.s16-instruction_handler
	db	'vqdmlal~~.s32',0x00
	dw	ARM_instruction_vqdmlal.s32-instruction_handler
	db	'vqdmlsl~~.s16',0x00
	dw	ARM_instruction_vqdmlsl.s16-instruction_handler
	db	'vqdmlsl~~.s32',0x00
	dw	ARM_instruction_vqdmlsl.s32-instruction_handler
	db	'vqdmulh~~.s16',0x00
	dw	ARM_instruction_vqdmulh.s16-instruction_handler
	db	'vqdmulh~~.s32',0x00
	dw	ARM_instruction_vqdmulh.s32-instruction_handler
	db	'vqdmull~~.s16',0x00
	dw	ARM_instruction_vqdmull.s16-instruction_handler
	db	'vqdmull~~.s32',0x00
	dw	ARM_instruction_vqdmull.s32-instruction_handler
	db	'vqmovun~~.s16',0x00
	dw	ARM_instruction_vqmovun.s16-instruction_handler
	db	'vqmovun~~.s32',0x00
	dw	ARM_instruction_vqmovun.s32-instruction_handler
	db	'vqmovun~~.s64',0x00
	dw	ARM_instruction_vqmovun.s64-instruction_handler
	db	'vqrshrn~~.s16',0x00
	dw	ARM_instruction_vqrshrn.s16-instruction_handler
	db	'vqrshrn~~.s32',0x00
	dw	ARM_instruction_vqrshrn.s32-instruction_handler
	db	'vqrshrn~~.s64',0x00
	dw	ARM_instruction_vqrshrn.s64-instruction_handler
	db	'vqrshrn~~.u16',0x00
	dw	ARM_instruction_vqrshrn.u16-instruction_handler
	db	'vqrshrn~~.u32',0x00
	dw	ARM_instruction_vqrshrn.u32-instruction_handler
	db	'vqrshrn~~.u64',0x00
	dw	ARM_instruction_vqrshrn.u64-instruction_handler
	db	'vqshrun~~.s16',0x00
	dw	ARM_instruction_vqshrun.s16-instruction_handler
	db	'vqshrun~~.s32',0x00
	dw	ARM_instruction_vqshrun.s32-instruction_handler
	db	'vqshrun~~.s64',0x00
	dw	ARM_instruction_vqshrun.s64-instruction_handler
	db	'vraddhn~~.i16',0x00
	dw	ARM_instruction_vraddhn.i16-instruction_handler
	db	'vraddhn~~.i32',0x00
	dw	ARM_instruction_vraddhn.i32-instruction_handler
	db	'vraddhn~~.i64',0x00
	dw	ARM_instruction_vraddhn.i64-instruction_handler
	db	'vrsqrte~~.f32',0x00
	dw	ARM_instruction_vrsqrte.f32-instruction_handler
	db	'vrsqrte~~.u32',0x00
	dw	ARM_instruction_vrsqrte.u32-instruction_handler
	db	'vrsqrts~~.f32',0x00
	dw	ARM_instruction_vrsqrts.f32-instruction_handler
	db	'vrsubhn~~.i16',0x00
	dw	ARM_instruction_vrsubhn.i16-instruction_handler
	db	'vrsubhn~~.i32',0x00
	dw	ARM_instruction_vrsubhn.i32-instruction_handler
	db	'vrsubhn~~.i64',0x00
	dw	ARM_instruction_vrsubhn.i64-instruction_handler
	db	0
instructions_14:
	db	'vcvt~~.f16.f32',0x00
	dw	ARM_instruction_vcvt.f16.f32-instruction_handler
	db	'vcvt~~.f32.f16',0x00
	dw	ARM_instruction_vcvt.f32.f16-instruction_handler
	db	'vcvt~~.f32.f64',0x00
	dw	ARM_instruction_vcvt.f32.f64-instruction_handler
	db	'vcvt~~.f32.s16',0x00
	dw	ARM_instruction_vcvt.f32.s16-instruction_handler
	db	'vcvt~~.f32.s32',0x00
	dw	ARM_instruction_vcvt.f32.s32-instruction_handler
	db	'vcvt~~.f32.u16',0x00
	dw	ARM_instruction_vcvt.f32.u16-instruction_handler
	db	'vcvt~~.f32.u32',0x00
	dw	ARM_instruction_vcvt.f32.u32-instruction_handler
	db	'vcvt~~.f64.f32',0x00
	dw	ARM_instruction_vcvt.f64.f32-instruction_handler
	db	'vcvt~~.f64.s16',0x00
	dw	ARM_instruction_vcvt.f64.s16-instruction_handler
	db	'vcvt~~.f64.s32',0x00
	dw	ARM_instruction_vcvt.f64.s32-instruction_handler
	db	'vcvt~~.f64.u16',0x00
	dw	ARM_instruction_vcvt.f64.u16-instruction_handler
	db	'vcvt~~.f64.u32',0x00
	dw	ARM_instruction_vcvt.f64.u32-instruction_handler
	db	'vcvt~~.s16.f32',0x00
	dw	ARM_instruction_vcvt.s16.f32-instruction_handler
	db	'vcvt~~.s16.f64',0x00
	dw	ARM_instruction_vcvt.s16.f64-instruction_handler
	db	'vcvt~~.s32.f32',0x00
	dw	ARM_instruction_vcvt.s32.f32-instruction_handler
	db	'vcvt~~.s32.f64',0x00
	dw	ARM_instruction_vcvt.s32.f64-instruction_handler
	db	'vcvt~~.u16.f32',0x00
	dw	ARM_instruction_vcvt.u16.f32-instruction_handler
	db	'vcvt~~.u16.f64',0x00
	dw	ARM_instruction_vcvt.u16.f64-instruction_handler
	db	'vcvt~~.u32.f32',0x00
	dw	ARM_instruction_vcvt.u32.f32-instruction_handler
	db	'vcvt~~.u32.f64',0x00
	dw	ARM_instruction_vcvt.u32.f64-instruction_handler
	db	'vqrdmulh~~.s16',0x00
	dw	ARM_instruction_vqrdmulh.s16-instruction_handler
	db	'vqrdmulh~~.s32',0x00
	dw	ARM_instruction_vqrdmulh.s32-instruction_handler
	db	'vqrshrun~~.s16',0x00
	dw	ARM_instruction_vqrshrun.s16-instruction_handler
	db	'vqrshrun~~.s32',0x00
	dw	ARM_instruction_vqrshrun.s32-instruction_handler
	db	'vqrshrun~~.s64',0x00
	dw	ARM_instruction_vqrshrun.s64-instruction_handler
	db	'vrinta.f32.f32',0xf0
	dw	ARM_instruction_vrinta.f32.f32-instruction_handler
	db	'vrinta.f64.f64',0xf0
	dw	ARM_instruction_vrinta.f64.f64-instruction_handler
	db	'vrintm.f32.f32',0xf0
	dw	ARM_instruction_vrintm.f32.f32-instruction_handler
	db	'vrintm.f64.f64',0xf0
	dw	ARM_instruction_vrintm.f64.f64-instruction_handler
	db	'vrintn.f32.f32',0xf0
	dw	ARM_instruction_vrintn.f32.f32-instruction_handler
	db	'vrintn.f64.f64',0xf0
	dw	ARM_instruction_vrintn.f64.f64-instruction_handler
	db	'vrintp.f32.f32',0xf0
	dw	ARM_instruction_vrintp.f32.f32-instruction_handler
	db	'vrintp.f64.f64',0xf0
	dw	ARM_instruction_vrintp.f64.f64-instruction_handler
	db	'vrintr.f32.f32',0xe0
	dw	ARM_instruction_vrintr.f32.f32-instruction_handler
	db	'vrintr.f64.f64',0xe0
	dw	ARM_instruction_vrintr.f64.f64-instruction_handler
	db	'vrintx.f32.f32',0xe0
	dw	ARM_instruction_vrintx.f32.f32-instruction_handler
	db	'vrintx.f64.f64',0xe0
	dw	ARM_instruction_vrintx.f64.f64-instruction_handler
	db	'vrintz.f32.f32',0xe0
	dw	ARM_instruction_vrintz.f32.f32-instruction_handler
	db	'vrintz.f64.f64',0xe0
	dw	ARM_instruction_vrintz.f64.f64-instruction_handler
	db	0
instructions_15:
	db	'vcvtb~~.f16.f32',0x00
	dw	ARM_instruction_vcvtb.f16.f32-instruction_handler
	db	'vcvtb~~.f16.f64',0x00
	dw	ARM_instruction_vcvtb.f16.f64-instruction_handler
	db	'vcvtb~~.f32.f16',0x00
	dw	ARM_instruction_vcvtb.f32.f16-instruction_handler
	db	'vcvtb~~.f64.f16',0x00
	dw	ARM_instruction_vcvtb.f64.f16-instruction_handler
	db	'vcvtr~~.s32.f32',0x00
	dw	ARM_instruction_vcvtr.s32.f32-instruction_handler
	db	'vcvtr~~.s32.f64',0x00
	dw	ARM_instruction_vcvtr.s32.f64-instruction_handler
	db	'vcvtr~~.u32.f32',0x00
	dw	ARM_instruction_vcvtr.u32.f32-instruction_handler
	db	'vcvtr~~.u32.f64',0x00
	dw	ARM_instruction_vcvtr.u32.f64-instruction_handler
	db	'vcvtt~~.f16.f32',0x00
	dw	ARM_instruction_vcvtt.f16.f32-instruction_handler
	db	'vcvtt~~.f16.f64',0x00
	dw	ARM_instruction_vcvtt.f16.f64-instruction_handler
	db	'vcvtt~~.f32.f16',0x00
	dw	ARM_instruction_vcvtt.f32.f16-instruction_handler
	db	'vcvtt~~.f64.f16',0x00
	dw	ARM_instruction_vcvtt.f64.f16-instruction_handler
	db	0
instructions_16:
	db	'vrintr~~.f32.f32',0x00
	dw	ARM_instruction_vrintr.f32.f32-instruction_handler
	db	'vrintr~~.f64.f64',0x00
	dw	ARM_instruction_vrintr.f64.f64-instruction_handler
	db	'vrintx~~.f32.f32',0x00
	dw	ARM_instruction_vrintx.f32.f32-instruction_handler
	db	'vrintx~~.f64.f64',0x00
	dw	ARM_instruction_vrintx.f64.f64-instruction_handler
	db	'vrintz~~.f32.f32',0x00
	dw	ARM_instruction_vrintz.f32.f32-instruction_handler
	db	'vrintz~~.f64.f64',0x00
	dw	ARM_instruction_vrintz.f64.f64-instruction_handler
	db	0
instructions_end:
