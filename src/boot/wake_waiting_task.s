; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_task_by_priority = $A8D6

.segment "CODE"
.org $AC69
wake_waiting_task:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    lda a:$0002,X
    .a8
    cmp #$04
    bne wake_waiting_task_aca8
    rep #$20
    txa
    .i16
    ldx #$00A2
wake_waiting_task_ac81:
    cmp a:$0000,X
    beq wake_waiting_task_ac96
    ldy a:$0000,X
    tyx
    bne wake_waiting_task_ac81
    tax
    sep #$20
    .a8
    lda #$80
    sta a:$0002,X
    bra wake_waiting_task_aca8
wake_waiting_task_ac96:
    tay
    lda a:$0000,Y
    sta a:$0000,X
    sep #$20
    .a8
    lda #$02
    sta a:$0002,Y
    tyx
    jsr enqueue_task_by_priority
wake_waiting_task_aca8:
    plb
    plp
    pld
    rts
