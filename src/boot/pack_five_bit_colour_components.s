; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8411
pack_five_bit_colour_components:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    lda a:$0000,X
    .a16
    and #$001F
    sta $01
    lda a:$0001,X
    .a16
    and #$001F
    asl
    asl
    asl
    asl
    asl
    ora $01
    sta $01
    lda a:$0002,X
    .a16
    and #$001F
    xba
    asl
    asl
    ora $01
    tax
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
