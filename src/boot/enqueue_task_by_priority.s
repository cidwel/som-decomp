; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A8D6
enqueue_task_by_priority:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    lda a:$0003,X
    phx
    .i16
    ldx #$00A0
enqueue_task_by_priority_a8e6:
    stx $01
    ldy a:$0000,X
    beq enqueue_task_by_priority_a8f3
    tyx
    cmp a:$0003,X
    bcs enqueue_task_by_priority_a8e6
enqueue_task_by_priority_a8f3:
    rep #$20
    ldx $01
    lda a:$0000,X
    sta $01
    pla
    sta a:$0000,X
    tax
    lda $01
    sta a:$0000,X
    sep #$20
    pla
    pla
    plp
    pld
    rts
