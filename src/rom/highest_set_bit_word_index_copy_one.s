; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-bit-index-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2729
highest_set_bit_word_index_copy_one:
    phd
    php
    rep #$30
    txa
    .i16
    ldx #$0010
highest_set_bit_word_index_copy_one_c12731:
    asl
    bcs highest_set_bit_word_index_copy_one_c1273c
    dex
    bne highest_set_bit_word_index_copy_one_c12731
    .a16
    lda #$00FF
    bra highest_set_bit_word_index_copy_one_c1273e
highest_set_bit_word_index_copy_one_c1273c:
    txa
    dec
highest_set_bit_word_index_copy_one_c1273e:
    plp
    pld
    rts
