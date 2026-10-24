; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6

.segment "CODE"
.org $8363
release_auxiliary_graphics_buffers:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$0018
    jsr boot_b0d6
    ldx a:$001A
    jsr boot_b0d6
    plb
    plp
    pld
    rts
