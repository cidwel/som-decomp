; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $805F
select_graphics_registration:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    lsr
    lsr
    sta $01
    lsr
    lsr
    ora $01
    .a8
    and #$07
    php
    sei
    xba
    .a8
    lda #$08
    xba
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sep #$20
    plp
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$0016
    sep #$20
    sta $01,S
    pla
    plp
    pld
    rts
