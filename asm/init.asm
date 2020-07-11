include './lib/constants.inc'
include './lib/macros.inc'

; black as backdrop and white as second palette entry
mov r0, MEM_PALETTE
mov r1, #0
strh r1, [r0]
add r0, #2
mov r1, #0x7f00
orr r1, #0x00ff
strh r1, [r0]

; set to mode 4 rendering
mov r0, DISPCNT
set_half r1, DISPCNT_BGMODE4
strh r1, [r0]
