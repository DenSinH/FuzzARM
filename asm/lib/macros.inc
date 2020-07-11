include './constants.inc'

macro set_word reg, value {
        mov reg, (value) and 0xff
        orr reg, (value) and 0xff00
        orr reg, (value) and 0xff0000
        orr reg, (value) and 0xff000000
}

macro set_half reg, value {
        mov reg, (value) and 0xff
        orr reg, (value) and 0xff00
}

macro do_dma from, to, length {
        stmdb sp!, \{ r0, r1 \}

        ; load SAD
        set_word r0, DMA3SAD
    if from in <r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, sp, lr, pc>
        mov r1, from
    else
        set_word r1, from
    end if
        str r1, [r0]

        add r0, \#4  ; DMA3DAD
        ; load to address into r1
        set_word r1, to
        str r1, [r0]

        add r0, \#4  ; DMA3CNT_L
        ; load dma length into DMA3CNT_L
        set_word r1, length
        strh r1, [r0]

        add r0, \#2  ; DMA3CNT_H
        ; start the DMA transfer
        set_word r1, DMACNT_H_32BIT_IMM
        strh r1, [r0]

        ldmia sp!, \{ r0, r1 \}
}