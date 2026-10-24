; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_signed_double_words_to_quad_word = $2BC3
normalize_boss_displacement_to_signed_fixed_point = $2F61

.segment "CODE"
.org $3313
derive_boss_target_velocity_from_normalized_displacement:
    sta $3C
    lda a:$00A9,X
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0002,X
    sta $9D
    lda a:$0004,X
    sta $A1
    ldx $87
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $99
    jsr normalize_boss_displacement_to_signed_fixed_point
    lda $A5
    sta $46
    lda $A7
    sta $48
    lda $3C
    sta $50
    stz $4E
    jsr multiply_signed_double_words_to_quad_word
    lda $5A
    sta $95
    lda $A9
    sta $46
    lda $AB
    sta $48
    lda $3C
    sta $50
    stz $4E
    jsr multiply_signed_double_words_to_quad_word
    lda $5A
    sta $97
    ldx $87
    lda $95
    sta a:$003C,X
    lda $97
    sta a:$0040,X
    rts
