; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $994D
release_low_colour_scene_template:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    plb
    plp
    pld
    rts
