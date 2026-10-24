; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CC57
mark_timer_waiting:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .a8
    lda #$02
    sta a:$0000,X
    lda a:$0002,X
    ora a:$0003,X
    bne mark_timer_waiting_cc74
    .a8
    lda #$01
    sta a:$0000,X
mark_timer_waiting_cc74:
    plb
    plp
    pld
    rts
