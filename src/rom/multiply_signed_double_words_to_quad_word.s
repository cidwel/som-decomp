; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_unsigned_double_words_in_software = $2B2F

.segment "CODE"
.org $2BC3
multiply_signed_double_words_to_quad_word:
    lda $48
    eor $50
    pha
    lda $48
    bpl multiply_signed_double_words_to_quad_word_c22bd9
    sec
    lda $C5
    sbc $46
    sta $46
    lda $C5
    sbc $48
    sta $48
multiply_signed_double_words_to_quad_word_c22bd9:
    lda $50
    bpl multiply_signed_double_words_to_quad_word_c22bea
    sec
    lda $C5
    sbc $4E
    sta $4E
    lda $C5
    sbc $50
    sta $50
multiply_signed_double_words_to_quad_word_c22bea:
    jsr multiply_unsigned_double_words_in_software
    pla
    bpl multiply_signed_double_words_to_quad_word_c22c09
    sec
    lda $C5
    sbc $56
    sta $56
    lda $C5
    sbc $58
    sta $58
    lda $C5
    sbc $5A
    sta $5A
    lda $C5
    sbc $5C
    sta $5C
multiply_signed_double_words_to_quad_word_c22c09:
    rts
