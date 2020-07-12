include './lib/constants.inc'
include './lib/macros.inc'

include './tests.inc'

;        For the tests we use the registers for the following:
;        r0 - r4: reserved for test
;        r5     : expected r3
;        r6     : expected r4
;        r7     : expected CPSR flags
;        r8     : shift type for test
;        r9     : opcode for test
;        r10    : initial CPSR flags
;        r11    : test address
;        r12    : test counter

align 4
code32
run_tests:
        stmdb sp!, { r0-r12, lr }

        ; init test counter and test
        set_word r11, MEM_ROM + tests
        ldmia r11!, { r12 }

        _run_tests_loop:
                ; report test number
                mov r0, #0
                mov r1, #0
                mov r2, r12
                bl draw_hex_value

                ; load test values
                ldmia r11!, { r0, r1, r5, r6, r7 }
                mov r10, #0xff

                and r2, r10, r7, lsr #8   ; shift amount
                mov r3, r1
                mov r4, r0
                and r8, r10, r7, lsr #16  ; shift type
                and r9, r10, r7           ; opcode
                and r10, r7, #0xf0000000

                ; in case of multiply instruction
                tst r9, #0x10
                orrne r2, r2, r8, lsl #24

                ; in case of load/store instruction
                ; set r2 to a word aligned address in the middle of iWRAM
                tst r9, #0x20
                movne r2, r2, lsl #2
                addne r2, MEM_IWRAM
                addne r2, #0x4000

                ; initialize expected CPSR for test
                and r7, #0x0f000000
                mov r7, r7, lsl #4

                stmdb sp!, { r11, r12 }

                ; we need r12 to be 0 for determining the switch table offset
                ; store r10 to have an extra register available after the test has started
                stmdb sp!, { r10 }
                mov r12, #0
                tst r9, #0x80
                bleq _run_test_single
                tst r9, #0x80
                blne _run_test_single_t
                ldmia sp!, { r11, r12 }
                subs r12, #1
                bne _run_tests_loop

        _run_tests_return:
                mov r0, #0
                mov r1, #0
                set_word r2, MEM_ROM + _finished_tests_text
                mov r3, #16
                bl draw_word

                ldmia sp!, { r0-r12, lr }
                bx lr

_finished_tests_text:
        dw 'End ', 'of t', 'esti', 'ng  '

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

        ; we use r10 here because we want to keep r12 0 for the switch case offset
        set_word r10, MEM_ROM + _do_operation_t

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
                bx r10
        _shift_lsr_t:
                lsr r3, r2
                bx r10
        _shift_asr_t:
                asr r3, r2
                bx r10
        _shift_ror_t:
                ror r3, r2
                bx r10

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

        set_word r12, MEM_ROM + _test_check
        mov r10, #0   ; used for ldrsh/ldrsb

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
                mul r3, r4
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

code32
align 4
_test_check:
        ; get CPSR flags
        mrs r11, CPSR
        and r11, #0xf0000000
        ; C flag is garbage for multiply instructions
        tst r9, #0x10
        andne r11, #0xd0000000

        ; get the initial CPSR values back for reporting
        ldmia sp!, { r10 }


        ; compare gotten vs expected
        cmp r3, r5
        bne _test_error ; shifted operand wrong

        cmp r4, r6
        bne _test_error ; output wrong

        cmp r11, r7
        bne _test_error ; cpsr flags wrong

        bx lr

_test_error:
        ; r11 still contains the CPSR we got
        stmdb sp!, { lr }
        stmdb sp!, { r7 }
        stmdb sp!, { r6 }
        stmdb sp!, { r5 }
        stmdb sp!, { r4 }
        stmdb sp!, { r3 }
        stmdb sp!, { r2 }
        stmdb sp!, { r1 }
        stmdb sp!, { r0 }
        ; draw 'Failed test':
        mov r0, #0
        mov r1, #0
        set_word r2, MEM_ROM + _failed_text
        mov r3, #12
        bl draw_word

        ; draw state
        set_word r2, MEM_ROM + _state_text
        tst r9, #0x80
        addne r2, #8
        add r0, #12 * 8
        mov r3, #8
        bl draw_word

        ; draw opcode
        ; store the "reduced" (stateless) opcode in r7
        and r7, r9, #0x1f

        mov r0, #0
        add r1, #8
        set_word r2, MEM_ROM + _opcode_text
        mov r3, #4

        ; load/store instructions are different yet again
        tst r9, #0x20
        addne r2, _opcode_load_store_text - _opcode_text
        addne r3, #8
        add r2, r7, lsl #2
        addne r2, r7, lsl #3
        bl draw_word

        ; we don't draw the operands for load store instructions either
        tst r9, #0x20
        bne _draw_input

        add r0, #8 * 4

        ; for multiply long instructions, the opcode is longer
        cmp r7, #18
        movge r2, 'l'
        blge draw_char
        cmp r7, #18
        addge r0, #2 * 8

        ; draw operands
        ; overshoot the operand location because we correct for it later when checking
        ; for multiply long instructions
        set_word r2, MEM_ROM + _op_text + 4
        mov r3, #12
        ; some opcodes don't have a destination register
        and r4, r7, #0xc
        cmp r4, #0x8
        addeq r2, #4

        ; multiply opcodes have different operands
        tst r7, #0x10
        addne r2, #4 * 4

        ; accumulate multiplies have an extra operand
        tstne r7, #0x1
        addne r3, #4

        ; non-long multiplies do not have the first operand
        cmp r7, #18
        sublt r2, #4
        addge r3, #4

        bl draw_word

        ; draw shift type
        ; multiply instructions have no shift
        cmp r7, #16
        bge _draw_input

        add r0, r3, lsl #3
        sub r0, #8
        set_word r2, MEM_ROM + _shift_text
        add r2, r8, lsl #2
        mov r3, #4
        bl draw_word

        add r0, #4 * 8
        mov r2, 'r'
        bl draw_char
        add r0, #8
        mov r2, '2'
        bl draw_char

        _draw_input:

        ; draw input text
        add r1, #8
        mov r0, #0
        set_word r2, MEM_ROM + _input_text
        mov r3, #6
        bl draw_word

        ; draw input
        mov r4, '0'
        _input_loop:
                add r1, #8
                mov r0, #16
                mov r2, 'r'
                bl draw_char
                add r0, #8
                mov r2, r4
                bl draw_char
                add r0, #32
                ldmia sp!, { r2 }
                bl draw_hex_value
                add r4, #1
                cmp r4, '2'
                ble _input_loop

        ; draw input CPSR
        add r1, #8
        mov r0, #16
        set_word r2, MEM_ROM + _cpsr_text
        mov r3, #4
        bl draw_word

        add r0, #5 * 8
        mov r2, r10
        bl draw_hex_value

        ; draw got text
        add r1, #8
        mov r0, #0
        set_word r2, MEM_ROM + _got_text
        mov r3, #4
        bl draw_word

        ; draw gotten values
        mov r4, '3'
        _got_loop:
                add r1, #8
                mov r0, #16
                mov r2, 'r'
                bl draw_char
                add r0, #8
                mov r2, r4
                bl draw_char
                add r0, #32
                ldmia sp!, { r2 }
                bl draw_hex_value
                add r4, #1
                cmp r4, '4'
                ble _got_loop

        ; draw gotten CPSR
        add r1, #8
        mov r0, #16
        set_word r2, MEM_ROM + _cpsr_text
        mov r3, #4
        bl draw_word

        add r0, #5 * 8
        mov r2, r11
        bl draw_hex_value

        ; draw Expected text
        add r1, #8
        mov r0, #0
        set_word r2, MEM_ROM + _expected_text
        mov r3, #9
        bl draw_word

        ; draw expected values
        mov r4, '3'
        _expected_loop:
                add r1, #8
                mov r0, #16
                mov r2, 'r'
                bl draw_char
                add r0, #8
                mov r2, r4
                bl draw_char
                add r0, #32
                ldmia sp!, { r2 }
                bl draw_hex_value
                add r4, #1
                cmp r4, '4'
                ble _expected_loop

        ; draw expected CPSR
        add r1, #8
        mov r0, #16
        set_word r2, MEM_ROM + _cpsr_text
        mov r3, #4
        bl draw_word

        add r0, #5 * 8
        ldmia sp!, { r2 }
        bl draw_hex_value

        set_word r0, KEYINPUT

        wait_until_keys_up:
                ldr r1, [r0]
                and r1, #0xff
                cmp r1, #0xff
                bne wait_until_keys_up

        wait_until_key_down:
                ldr r1, [r0]
                and r1, #0xff
                cmp r1, #0xff
                beq wait_until_key_down

        ldmia sp!, { lr }
        bx lr

_failed_text:
        dw 'Fail', 'ed t', 'est '

_state_text:
        dw 'ARM:', '    ', 'THUM', 'B:  '

_opcode_text:
        dw 'and ', 'eor ', 'sub ', 'rsb '
        dw 'add ', 'adc ', 'sbc ', 'rsc '
        dw 'tst ', 'teq ', 'cmp ', 'cmn '
        dw 'orr ', 'mov ', 'bic ', 'mvn '
        dw 'mul ', 'mla ', 'umul', 'umla'
        dw 'smul', 'smla'
_opcode_load_store_text:
        dw 'str/', 'ldr ', '    '
        dw 'strh', '/ldr', 'h   '
        dw 'strh', '/ldr', 'sh  '
        dw 'strb', '/ldr', 'b   '
        dw 'strb', '/ldr', 'sb  '
        dw 'stm/', 'ldm ', '    '
        dw 'swp ', '    ', '    '

_op_text:
        dw 'r4, ', 'r0, ', 'r1  ', '    '          ; for data processing
        dw 'r4, ', 'r3, ', 'r0, ', 'r1, ', 'r2  '  ; for multiply

_shift_text:
        dw 'lsl ', 'lsr ', 'asr ', 'ror '

_input_text:
        dw 'Inpu', 't:  '

_cpsr_text:
        dw 'CPSR'

_got_text:
        dw 'Got:'

_expected_text:
        dw 'Expe', 'cted', ':   '







