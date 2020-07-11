include './macros.inc'
include './constants.inc'

SCREEN_WIDTH = 240

include './glyphs.inc'

draw_char:
        ; draw character r2 at (r0, r1) on the screen
        stmdb sp!, { r0-r7 }

        ; find VRAM coordinate
        mov r1, r1, lsl #8
        sub r1, r1, lsr #4
        add r0, r1

        ; mov r3, SCREEN_WIDTH
        ; mla r0, r1, r3, r0
        add r0, MEM_VRAM
        add r0, #8

        ; glyph memory location
        set_word r3, MEM_ROM + glyphs
        sub r2, #32
        add r3, r2, lsl #3  ; 8 bytes per character

        mov r6, #8  ; byte counter
        _draw_char_byte_loop:
                ; load glyph byte
                mov r5, #8  ; bit counter
                ldrb r4, [r3]
                add r3, #1
                _draw_char_bit_loop:
                        ; r7 holds the pixel values for 2 adjecent pixels
                        ; we do it this way because VRAM behaves in an odd way with byte writes
                        mov r7, #0
                        movs r4, r4, lsr #1
                        orrcs r7, #0x100
                        movs r4, r4, lsr #1
                        orrcs r7, #1

                        ; store the pixel values
                        strh r7, [r0]
                        sub r0, #2
                        subs r5, #2
                        bne _draw_char_bit_loop

                add r0, SCREEN_WIDTH + 8   ; next scanline (correct for character x)
                subs r6, #1                ; check if we are done
                bne _draw_char_byte_loop

        ldmia sp!, { r0-r7 }
        bx lr

draw_word:
        ; draw word at memory location r2 of length r3 > 0 at (r0, r1)

        stmdb sp!, { r0-r4, lr }

        mov r4, r2
        _draw_word_char_loop:
                ; get and draw char
                ldrb r2, [r4]
                bl draw_char

                ; data for next char
                add r4, #1
                add r0, #8    ; increment x
                subs r3, #1   ; decrement counter
                bne _draw_word_char_loop

        ldmia sp!, { r0-r4, lr }
        bx lr

draw_hex_value:
        ; draw hex value r2 at (r0, r1)

        stmdb sp!, { r0-r4, lr }
        mov r3, #8
        mov r4, r2
        _draw_hex_value_loop:
                ; get next hex value
                mov r2, r4, lsr #28
                mov r4, r4, lsl #4

                ; offset
                add r2, '0'
                cmp r2, '9'
                addgt r2, #7  ; ABCDEF characters are 8 ahead of 0123456789 characters
                bl draw_char

                add r0, #8    ; increment x
                subs r3, #1   ; decrement counter
                bne _draw_hex_value_loop

        ldmia sp!, { r0-r4, lr }
        bx lr




