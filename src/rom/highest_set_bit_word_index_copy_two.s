; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-bit-index-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $276F
highest_set_bit_word_index_copy_two:
    phd
    php
    rep #$30
    txa
    .i16
    ldx #$0010
highest_set_bit_word_index_copy_two_c12777:
    asl
    bcs highest_set_bit_word_index_copy_two_c12782
    dex
    bne highest_set_bit_word_index_copy_two_c12777
    .a16
    lda #$00FF
    bra highest_set_bit_word_index_copy_two_c12784
highest_set_bit_word_index_copy_two_c12782:
    txa
    dec
highest_set_bit_word_index_copy_two_c12784:
    plp
    pld
    rts
