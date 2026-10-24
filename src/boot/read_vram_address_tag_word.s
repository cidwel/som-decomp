; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D6B3
read_vram_address_tag_word:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    .a16
    and #$FC00
    xba
    lsr
    lsr
    clc
    adc a:$032C
    tax
    lda a:$0000,X
    plb
    plp
    pld
    rts
