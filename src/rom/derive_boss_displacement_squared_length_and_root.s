; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

derive_unsigned_double_word_integer_square_root = $2DF9
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $2FCC
derive_boss_displacement_squared_length_and_root:
    lda $A1
    sta $46
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $56
    sta $A5
    lda $58
    sta $A7
    lda $9D
    sta $46
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $56
    sta $AD
    lda $58
    sta $AF
    clc
    lda $A5
    adc $AD
    sta $A5
    lda $A7
    adc $AF
    sta $A7
    lda $A5
    sta $46
    lda $A7
    sta $48
    jsr derive_unsigned_double_word_integer_square_root
    lda $4E
    sta $AD
    rts
