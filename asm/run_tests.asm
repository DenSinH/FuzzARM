include './lib/constants.inc'
include './lib/macros.inc'

include './tests.inc'

;        For the tests we use the registers for the following:
;        r0 - r4: reserved for test
;        r5     : expected r3         / ???
;        r6     : expected r4         / ???
;        r7     : expected CPSR flags / ???
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
                stmdb sp!, { r5, r6, r7, r10 }
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

include './run_test_ARM.asm'
include './run_test_THUMB.asm'

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
        ldmia sp!, { r5, r6, r7, r10 }


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
        ; NOTE TO SELF: from here on out, we assume that the "reduced opcode" (&0x1f)
        ; can only be greater than #18 (dec) for multiplication instructions

        ; we use r6 and r5 to dump the text to eWRAM for people who are too lazy to interpret
        ; the screen by themselves

        ; we store the failed test data as follows:
        ; 1 word:  ['AAAA' OR 'TTTT'] for ARM or THUMB state
        ; 3 words: [opcode + shift] OR [multiplication opcode] OR [store opcode/load opcode]
        ; 1 word:  [initial r0]
        ; 1 word:  [initial r1]
        ; 1 word:  [initial r2]
        ; 1 word:  [initial CPSR]
        ; 1 word:  [gotten  r3]
        ; 1 word:  [gotten  r4]
        ; 1 word:  [gotten  CPSR]
        ; 1 word:  [expected r3]
        ; 1 word:  [expected r4]
        ; 1 word:  [expected CPSR]

_draw_failed_test:
        mov r6, MEM_EWRAM

        ; draw 'Failed test':
        mov r0, #0
        mov r1, #0
        set_word r2, MEM_ROM + _failed_text
        mov r3, #12
        bl draw_word

_draw_state:
        ; draw state
        set_word r2, MEM_ROM + _state_text
        tst r9, #0x80
        addne r2, #8
        ; write state to eWRAM
        movne r5, 'T'
        moveq r5, 'A'
        orr r5, r5, lsl #8
        orr r5, r5, lsl #16
        orr r5, r5, lsl #24
        str r5, [r6]
        add r6, #4

        add r0, #12 * 8
        mov r3, #8
        bl draw_word

_draw_opcode:
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

        ; write opcode to WRAM
        ldr r5, [r2]
        str r5, [r6]
        add r6, #4

        ; longer opcode for multiplication:
        cmp r7, #0x10
        bge _write_opcode_multiply

        ; longer opcode for load/store
        tstlt r9, #0x20
        bne _write_opcode_load_store

        _write_opcode_return:

        bl draw_word

        ; we don't draw the operands for load store instructions either
        tst r9, #0x20
        bne _draw_input

_draw_operands:
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

        ldr r5, [r2]
        str r5, [r6]
        add r6, #4

        mov r5, ' '
        orr r5, r5, lsl #8
        orr r5, r5, lsl #16

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

                ; write input value to eWRAM
                str r2, [r6]
                add r6, #4

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

        ; write init CPSR to eWRAM
        str r2, [r6]
        add r6, #4

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

                ; report to eWRAM
                str r2, [r6]
                add r6, #4

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

        ; report to eWRAM
        str r2, [r6]
        add r6, #4

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

                ; report to eWRAM
                str r2, [r6]
                add r6, #4

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

        ; report to eWRAM
        str r2, [r6]

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

_write_opcode_multiply:
        set_word r5, 'l   '
        ; set l to space for non multiply long instructions
        cmp r7, #18
        addlt r5, ' ' - 'l'

        str r5, [r6]
        add r6, #4
        ; set l to space if not done already
        addge r5, ' ' - 'l'
        str r5, [r6]
        add r6, #4

        b _write_opcode_return

_write_opcode_load_store:
        ldr r5, [r2, #4]
        str r5, [r6]
        add r6, #4
        ldr r5, [r2, #8]
        str r5, [r6]
        add r6, #4

        b _write_opcode_return







