_run_test_single:
        ; no shift for multiply/load store instructions
        tst r9, #0x30
        bne _do_operation_no_shift

_shift_operand:
        ; shift operand into r3
        set_word r11, MEM_ROM + _shift_switch
        add r11, r8, lsl #2
        ldr r11, [r11]

        ; initialize CPSR for test
        msr CPSR_flg, r10

        bx r11

        _shift_switch:
                dw MEM_ROM + _shift_lsl
                dw MEM_ROM + _shift_lsr
                dw MEM_ROM + _shift_asr
                dw MEM_ROM + _shift_ror

        _shift_lsl:
                movs r3, r1, lsl r2
                b _do_operation
        _shift_lsr:
                movs r3, r1, lsr r2
                b _do_operation
        _shift_asr:
                movs r3, r1, asr r2
                b _do_operation
        _shift_ror:
                movs r3, r1, ror r2
                b _do_operation

_do_operation_no_shift:
        ; initialize CPSR for mul/load store tests
        tst r9, #0x20
        movne r12, _opcode_switch_load_store - _opcode_switch

        msr CPSR_flg, r10

_do_operation:
        ; execute operation
        set_word r11, MEM_ROM + _opcode_switch
        add r11, r12
        and r12, r9, #0x1f
        add r11, r12, lsl #2
        ldr r11, [r11]

        ; reset CPSR flags for ADC/SBC/RSC instructions
        mrs r7, CPSR
        cmp   r12, #0x5  ; ADC
        cmpne r12, #0x6  ; SBC
        cmpne r12, #0x7  ; RSC
        moveq r7, r10   ; initial CPSR flags
        msr CPSR_flg, r7

        bx r11

        _opcode_switch:
                dw MEM_ROM + _opcode_and, MEM_ROM + _opcode_eor
                dw MEM_ROM + _opcode_sub, MEM_ROM + _opcode_rsb
                dw MEM_ROM + _opcode_add, MEM_ROM + _opcode_adc
                dw MEM_ROM + _opcode_sbc, MEM_ROM + _opcode_rsc
                dw MEM_ROM + _opcode_tst, MEM_ROM + _opcode_teq
                dw MEM_ROM + _opcode_cmp, MEM_ROM + _opcode_cmn
                dw MEM_ROM + _opcode_orr, MEM_ROM + _opcode_mov
                dw MEM_ROM + _opcode_bic, MEM_ROM + _opcode_mvn
                dw MEM_ROM + _opcode_mul, MEM_ROM + _opcode_mla
                dw MEM_ROM + _opcode_umull, MEM_ROM + _opcode_umlal
                dw MEM_ROM + _opcode_smull, MEM_ROM + _opcode_smlal
        _opcode_switch_load_store:
                dw MEM_ROM + _opcode_ldr, MEM_ROM + _opcode_ldrh
                dw MEM_ROM + _opcode_ldrsh, MEM_ROM + _opcode_ldrb
                dw MEM_ROM + _opcode_ldrsb, MEM_ROM + _opcode_ldm
                dw MEM_ROM + _opcode_swp

        _opcode_and:
                ands r4, r0, r3
                b _test_check
        _opcode_eor:
                eors r4, r0, r3
                b _test_check
        _opcode_sub:
                subs r4, r0, r3
                b _test_check
        _opcode_rsb:
                rsbs r4, r0, r3
                b _test_check
        _opcode_add:
                adds r4, r0, r3
                b _test_check
        _opcode_adc:
                adcs r4, r0, r3
                b _test_check
        _opcode_sbc:
                sbcs r4, r0, r3
                b _test_check
        _opcode_rsc:
                rscs r4, r0, r3
                b _test_check
        _opcode_tst:
                tst r0, r3
                b _test_check
        _opcode_teq:
                teq r0, r3
                b _test_check
        _opcode_cmp:
                cmp r0, r3
                b _test_check
        _opcode_cmn:
                cmn r0, r3
                b _test_check
        _opcode_orr:
                orrs r4, r0, r3
                b _test_check
        _opcode_mov:
                movs r4, r3
                b _test_check
        _opcode_bic:
                bics r4, r0, r3
                b _test_check
        _opcode_mvn:
                mvns r4, r3
                b _test_check
        _opcode_mul:
                muls r3, r0, r1
                b _test_check
        _opcode_mla:
                mlas r3, r0, r1, r2
                b _test_check
        _opcode_umull:
                umulls r4, r3, r0, r1
                b _test_check
        _opcode_umlal:
                umlals r4, r3, r0, r1
                b _test_check
        _opcode_smull:
                smulls r4, r3, r0, r1
                b _test_check
        _opcode_smlal:
                smlals r4, r3, r0, r1
                b _test_check

        _opcode_ldr:
                str r4, [r2]
                mov r4, #0
                ldr r4, [r2]
                b _test_check
        _opcode_ldrh:
                strh r4, [r2]
                mov r4, #0
                ldrh r4, [r2]
                b _test_check
        _opcode_ldrsh:
                strh r4, [r2]
                mov r4, #0
                ldrsh r4, [r2]
                b _test_check
        _opcode_ldrb:
                strb r4, [r2]
                mov r4, #0
                ldrb r4, [r2]
                b _test_check
        _opcode_ldrsb:
                strb r4, [r2]
                mov r4, #0
                ldrsb r4, [r2]
                b _test_check
        _opcode_ldm:
                stmdb r2!, { r3, r4 }
                mov r4, #0
                mov r3, #0
                ldmia r2!, { r3, r4 }
                b _test_check
        _opcode_swp:
                str r4, [r2]
                swp r4, r3, [r2]
                ldr r3, [r2]
                b _test_check
