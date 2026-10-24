; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CC16
set_timer_countdown:
    phd
    php
    rep #$30
    phb
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    tya
    sta a:$0002,X
    sep #$20
    xba
    sta $01
    .a8
    lda #$02
    sta a:$0000,X
    tya
    ora $01
    bne set_timer_countdown_cc3e
    .a8
    lda #$01
    sta a:$0000,X
set_timer_countdown_cc3e:
    plb
    pla
    plp
    pld
    rts
