; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-bit-index-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $27B4
highest_set_bit_word_index_copy_three:
    phd
    php
    rep #$30
    txa
    .i16
    ldx #$0010
highest_set_bit_word_index_copy_three_c127bc:
    asl
    bcs highest_set_bit_word_index_copy_three_c127c7
    dex
    bne highest_set_bit_word_index_copy_three_c127bc
    .a16
    lda #$00FF
    bra highest_set_bit_word_index_copy_three_c127c9
highest_set_bit_word_index_copy_three_c127c7:
    txa
    dec
highest_set_bit_word_index_copy_three_c127c9:
    plp
    pld
    rts
