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
run_tests:
        stmia sp!, { r0-r12, lr }

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
                and r2, r10, r7, lsr #16  ; shift amount
                mov r3, #0
                mov r4, #0
                and r8, r10, r7, lsr #8   ; shift type
                and r9, r10, r7           ; opcode

                ; initialize CPSR for test
                and r10, r7, #0xf0000000
                msr CPSR_flg, r10

                ; initialize expected CPSR for test
                and r7, #0x0f000000
                mov r7, r7, lsl #4

                stmia sp!, { r11, r12 }
                bl _run_tests_single
                ldmdb sp!, { r11, r12 }
                subs r12, #1
                bne _run_tests_loop

        _run_tests_return:
                mov r0, #0
                mov r1, #0
                set_word r2, MEM_ROM + _finished_tests_text
                mov r3, #16
                bl draw_word

                ldmdb sp!, { r0-r12, lr }
                bx lr

_finished_tests_text:
        dw 'End ', 'of t', 'esti', 'ng  '

_run_tests_single:
_shift_operand:
        ; shift operand into r3
        set_word r11, MEM_ROM + _shift_switch
        add r11, r8, lsl #2
        ldr r11, [r11]

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

_do_operation:
        ; execute operation
        set_word r11, MEM_ROM + _opcode_switch
        add r11, r9, lsl #2
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

_test_check:
        ; get CPSR flags
        mrs r11, CPSR
        and r11, #0xf0000000

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
        stmia sp!, { lr }
        stmia sp!, { r7 }
        stmia sp!, { r6 }
        stmia sp!, { r5 }
        stmia sp!, { r4 }
        stmia sp!, { r3 }
        stmia sp!, { r2 }
        stmia sp!, { r1 }
        stmia sp!, { r0 }
        ; draw 'Failed test':
        mov r0, #0
        mov r1, #0
        set_word r2, MEM_ROM + _failed_text
        mov r3, #12
        bl draw_word

        ; draw opcode
        add r1, #8
        set_word r2, MEM_ROM + _opcode_text
        add r2, r9, lsl #2
        bl draw_word

        ; draw operands
        add r0, #8 * 4
        set_word r2, MEM_ROM + _op_text
        mov r3, #12
        ; some opcodes don't have a destination register
        and r4, r9, #0xc
        cmp r4, #0x8

        addeq r2, #4
        bl draw_word

        ; draw shift type
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
                ldmdb sp!, { r2 }
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
                ldmdb sp!, { r2 }
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
                ldmdb sp!, { r2 }
                bl draw_hex_value
                add r4, #1
                cmp r4, '4'
                ble _expected_loop

        ; draw expected CPSR
        add r1, #8
        mov r0, #0
        set_word r2, MEM_ROM + _cpsr_text
        mov r3, #4
        bl draw_word

        add r0, #5 * 8
        ldmdb sp!, { r2 }
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
                beq wait_until_keys_up

        ldmdb sp!, { lr }
        bx lr

_failed_text:
        dw 'Fail', 'ed t', 'est:'

_opcode_text:
        dw 'and ', 'eor ', 'sub ', 'rsb '
        dw 'add ', 'adc ', 'sbc ', 'rsc '
        dw 'tst ', 'teq ', 'cmp ', 'cmn '
        dw 'orr ', 'mov ', 'bic ', 'mvn '

_op_text:
        dw 'r4, ', 'r0, ', 'r1  ', '    '

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







