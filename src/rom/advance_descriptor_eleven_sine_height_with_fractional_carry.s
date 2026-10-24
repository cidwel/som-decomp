; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16

mask_angle_and_derive_native_sine = $2A60
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $8CFB
advance_descriptor_eleven_sine_height_with_fractional_carry:
    lda a:$035C
    clc
    .a16
    adc #$0008
    sta a:$035C
    jsr mask_angle_and_derive_native_sine
    sta $46
    .a16
    lda #$0010
    sta $4E
    jsr multiply_signed_words_to_double_word
    ldx $87
    lda $55
    .a16
    and #$FF00
    clc
    adc a:$0358
    sta a:$0064,X
    lda $57
    adc a:$035A
    sta a:$0066,X
    rts
