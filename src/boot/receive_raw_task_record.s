; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

suspend_current_task = $A911

.segment "CODE"
.org $B2FB
receive_raw_task_record:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
receive_raw_task_record_b308:
    jsr suspend_current_task
    txa
    beq receive_raw_task_record_b308
    plb
    plp
    pld
    rts
