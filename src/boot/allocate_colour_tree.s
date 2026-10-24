; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1

.segment "CODE"
.org $A061
allocate_colour_tree:
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
    ldx #$0600
    jsr allocate_and_fill_bytes
    stx a:$008A
    plb
    plp
    pld
    rts
