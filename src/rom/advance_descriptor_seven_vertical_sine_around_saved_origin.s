; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16

mask_angle_and_derive_native_sine = $2A60
move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding = $0A47
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $73B7
advance_descriptor_seven_vertical_sine_around_saved_origin:
    lda a:$0358
    jsr mask_angle_and_derive_native_sine
    sta $46
    .a16
    lda #$0020
    sta $4E
    jsr multiply_signed_words_to_double_word
    ldx $87
    lda $57
    clc
    adc a:$035C
    sec
    sbc a:$0032,X
    sta a:$0040,X
    lda $C5
    jsr move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding
    lda a:$0358
    clc
    .a16
    adc #$0020
    sta a:$0358
    rts
