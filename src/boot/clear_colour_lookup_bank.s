; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_c37d = $C37D

.segment "CODE"
.org $8607
clear_colour_lookup_bank:
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
    lda #$00
    .i16
    ldx #$8000
    .i16
    ldy #$8000
    jsr boot_c37d
    plb
    plp
    pld
    rts
