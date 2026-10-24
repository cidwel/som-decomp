; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-setup.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
mask_angle_and_derive_native_sine = $2A60
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $979F
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle:
    ldx $87
    lda a:$00B0,X
    sta $95
    lda a:$00B2,X
    jsr mask_angle_and_derive_native_sine
    sta $97
    ldx $87
    lda a:$00B2,X
    jsr derive_cosine_by_adding_quarter_turn
    sta $99
    lda $99
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sta $9B
    lda $97
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sta $9D
    lda $97
    eor $C7
    inc
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sta $9F
    lda $9B
    sta a:$02CD
    lda $9D
    sta a:$02CF
    lda $9F
    sta a:$02D1
    lda $9B
    sta a:$02D3
    rts
