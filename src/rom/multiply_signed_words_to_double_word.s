; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_unsigned_words_with_four_hardware_products = $2AC3

.segment "CODE"
.org $2B94
multiply_signed_words_to_double_word:
    lda $46
    eor $4E
    pha
    lda $46
    bpl multiply_signed_words_to_double_word_c22ba4
    sec
    lda $C5
    sbc $46
    sta $46
multiply_signed_words_to_double_word_c22ba4:
    lda $4E
    bpl multiply_signed_words_to_double_word_c22baf
    sec
    lda $C5
    sbc $4E
    sta $4E
multiply_signed_words_to_double_word_c22baf:
    jsr multiply_unsigned_words_with_four_hardware_products
    pla
    bpl multiply_signed_words_to_double_word_c22bc2
    sec
    lda $C5
    sbc $56
    sta $56
    lda $C5
    sbc $58
    sta $58
multiply_signed_words_to_double_word_c22bc2:
    rts
