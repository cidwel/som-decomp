; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_additive_random_generator = $38A0



.segment "CODE"
.org $3872
random_byte_with_preserved_direct_page:
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    jsr advance_additive_random_generator
    plp
    plb
    pld
    rtl
