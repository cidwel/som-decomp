; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C710
select_vram_registration_slot:
    phd
    php
    rep #$30
    sep #$20
    lsr
    lsr
    .a8
    and #$03
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
    adc a:$02F4
    plp
    pld
    rts
