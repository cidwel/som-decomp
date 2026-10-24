; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16

mask_angle_and_derive_native_sine = $2A60
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $776F
derive_descriptor_ten_positive_y_sine_offset_from_phase:
    lda a:$007E,X
    jsr mask_angle_and_derive_native_sine
    sta $46
    .a16
    lda #$0008
    sta $4E
    jsr multiply_signed_words_to_double_word
    ldx $87
    lda a:$035C
    clc
    adc $57
    sta a:$0032,X
    rts
