_run_test_single_t:
        ; no shift for multiply/load store instructions
        tst r9, #0x30
        bne _do_operation_no_shift_t

_shift_operand_t:
        ; shift operand into r3
        set_word r11, MEM_ROM + _shift_switch_t
        add r11, r8, lsl #2
        ldr r11, [r11]

        ; initialize CPSR for test
        msr CPSR_flg, r10

        set_word r7, MEM_ROM + _do_operation_t

        bx r11

        _shift_switch_t:
                dw MEM_ROM + _shift_lsl_t + 1
                dw MEM_ROM + _shift_lsr_t + 1
                dw MEM_ROM + _shift_asr_t + 1
                dw MEM_ROM + _shift_ror_t + 1

        code16
        align 2
        _shift_lsl_t:
                lsl r3, r2
                bx r7
        _shift_lsr_t:
                lsr r3, r2
                bx r7
        _shift_asr_t:
                asr r3, r2
                bx r7
        _shift_ror_t:
                ror r3, r2
                bx r7

code32
align 4
_do_operation_no_shift_t:
        tst r9, #0x20
        movne r12, _opcode_switch_load_store_t - _opcode_switch_t

        ; initialize CPSR for mul test
        msr CPSR_flg, r10

_do_operation_t:
        ; execute operation
        set_word r11, MEM_ROM + _opcode_switch_t
        add r11, r12  ; add potential offset for load/store instructions
        and r12, r9, #0x1f
        add r11, r12, lsl #2
        ldr r11, [r11]

        ; reset CPSR flags for ADC/SBC/RSC instructions
        mrs r7, CPSR
        cmp   r12, #0x5  ; ADC
        cmpne r12, #0x6  ; SBC
        cmpne r12, #0x7  ; RSC
        moveq r7, r10    ; initial CPSR flags
        msr CPSR_flg, r7

        set_word r12, MEM_ROM + _test_check
        mov r10, #0      ; used for ldrsh/ldrsb

        bx r11

        _opcode_switch_t:
                dw MEM_ROM + _opcode_and_t + 1, MEM_ROM + _opcode_eor_t + 1
                dw MEM_ROM + _opcode_sub_t + 1, 0xffffffff
                dw MEM_ROM + _opcode_add_t + 1, MEM_ROM + _opcode_adc_t + 1
                dw MEM_ROM + _opcode_sbc_t + 1, 0xffffffff
                dw MEM_ROM + _opcode_tst_t + 1, 0xffffffff
                dw MEM_ROM + _opcode_cmp_t + 1, MEM_ROM + _opcode_cmn_t + 1
                dw MEM_ROM + _opcode_orr_t + 1, MEM_ROM + _opcode_mov_t + 1
                dw MEM_ROM + _opcode_bic_t + 1, MEM_ROM + _opcode_mvn_t + 1
                dw MEM_ROM + _opcode_mul_t + 1, 0xffffffff
                ; no UMULL/SMULL/UMLAL/SMLAL instructions in THUMB mode
        _opcode_switch_load_store_t:
                dw MEM_ROM + _opcode_ldr_t + 1, MEM_ROM + _opcode_ldrh_t + 1
                dw MEM_ROM + _opcode_ldrsh_t + 1, MEM_ROM + _opcode_ldrb_t + 1
                dw MEM_ROM + _opcode_ldrsb_t + 1, MEM_ROM + _opcode_ldm_t + 1

        code16
        align 2
        _opcode_and_t:
                and r4, r3
                bx r12
        _opcode_eor_t:
                eor r4, r3
                bx r12
        _opcode_sub_t:
                sub r4, r3
                bx r12
        _opcode_add_t:
                add r4, r3
                bx r12
        _opcode_adc_t:
                adc r4, r3
                bx r12
        _opcode_sbc_t:
                sbc r4, r3
                bx r12
        _opcode_tst_t:
                tst r4, r3
                bx r12
        _opcode_cmp_t:
                cmp r4, r3
                bx r12
        _opcode_cmn_t:
                cmn r4, r3
                bx r12
        _opcode_orr_t:
                orr r4, r3
                bx r12
        _opcode_mov_t:
                ; there was no other way to actually do a mov instruction
                ; a mov instruction in THUMB mode is interpreted as a
                ; adds, Rd, Rm, #0 (direct addition) instruction,
                ; and will therefore not give an accurate result
                mov r11, r3
                mov r4, r11
                bx r12
        _opcode_bic_t:
                bic r4, r3
                bx r12
        _opcode_mvn_t:
                mvn r4, r3
                bx r12
        _opcode_mul_t:
                mul r4, r3
                bx r12

        _opcode_ldr_t:
                str r4, [r2]
                mov r4, r12  ; does not alter CPSR flags
                ldr r4, [r2]
                bx r12
        _opcode_ldrh_t:
                strh r4, [r2]
                mov r4, r12  ; does not alter CPSR flags
                ldrh r4, [r2]
                bx r12
        _opcode_ldrsh_t:
                ; I had to come up with a way to make a lo register hold 0 without changing
                ; CPSR flags...
                strh r4, [r2]
                mov r4, r10
                ldrsh r4, [r2, r4]
                bx r12
        _opcode_ldrb_t:
                strb r4, [r2]
                mov r4, r12  ; does not alter CPSR flags
                ldrb r4, [r2]
                bx r12
        _opcode_ldrsb_t:
                ; Again, I had to come up with a way to make a lo register hold 0 without changing
                ; CPSR flags...
                strb r4, [r2]
                mov r4, r10
                ldrsb r4, [r2, r4]
                bx r12
        _opcode_ldm_t:
                push { r3, r4 }
                mov r4, r12
                mov r3, r12  ; does not alter CPSR flags
                pop { r3, r4 }
                bx r12
