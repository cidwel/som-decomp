; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $051C
consume_boss_byte35_request:
    sep #$20
    lda a:$0035,X
    beq consume_boss_byte35_request_c2052a
    stz a:$0035,X
    rep #$20
    sec
    rts
consume_boss_byte35_request_c2052a:
    rep #$20
    clc
    rts
