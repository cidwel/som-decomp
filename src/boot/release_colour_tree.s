; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6

.segment "CODE"
.org $A07B
release_colour_tree:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$008A
    jsr boot_b0d6
    plb
    plp
    pld
    rts
