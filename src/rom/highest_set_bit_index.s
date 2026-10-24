; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16




.segment "CODE"
.org $2710
highest_set_bit_index:
    phd
    php
    rep #$30
    txa
    .i16
    ldx #$0010
highest_set_bit_index_c12718:
    asl
    bcs highest_set_bit_index_c12723
    dex
    bne highest_set_bit_index_c12718
    .a16
    lda #$00FF
    bra highest_set_bit_index_c12725
highest_set_bit_index_c12723:
    txa
    dec
highest_set_bit_index_c12725:
    plp
    pld
    rts
