; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A12E
initialize_colour_decoder:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta a:$0002,X
    rep #$20
    tya
    sta a:$0000,X
    stz a:$0004,X
    stz a:$0006,X
    plb
    plp
    pld
    rts
