; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-oscillator.md.
.setcpu "65816"
.smart
.a8
.i16

mask_angle_and_derive_native_sine = $2A60
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $4865
publish_native54_cast_pose_sine_oscillator_and_auxiliary_control:
    .a16
    lda #$0014
    sta $99
    lda a:$0098,X
    .a16
    bit #$0040
    beq publish_native54_cast_pose_sine_oscillator_and_auxiliary_control_c24877
    .a16
    lda #$000C
    sta $99
publish_native54_cast_pose_sine_oscillator_and_auxiliary_control_c24877:
    lda a:$00B4,X
    jsr mask_angle_and_derive_native_sine
    sta $95
    ldx $87
    lda a:$00B4,X
    clc
    .a16
    adc #$0200
    jsr mask_angle_and_derive_native_sine
    sta $97
    lda $95
    sta $46
    .a16
    lda #$0003
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sec
    .a16
    sbc #$0008
    sta $95
    lda $97
    sta $46
    .a16
    lda #$0002
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sec
    sbc $99
    sta $97
    ldx $87
    lda a:$00B4,X
    clc
    .a16
    adc #$0040
    sta a:$00B4,X
    sep #$20
    lda $97
    sta a:$F811,Y
    lda $95
    sta a:$F80D,Y
    rep #$20
    lda a:$0096,X
    .a16
    and #$0003
    bne publish_native54_cast_pose_sine_oscillator_and_auxiliary_control_c248df
    sep #$20
    .a8
    lda #$44
    sta a:$F813,Y
    rep #$20
publish_native54_cast_pose_sine_oscillator_and_auxiliary_control_c248df:
    lda a:$0096,X
    .a16
    and #$0007
    bne publish_native54_cast_pose_sine_oscillator_and_auxiliary_control_c248f0
    sep #$20
    .a8
    lda #$44
    sta a:$F813,Y
    rep #$20
publish_native54_cast_pose_sine_oscillator_and_auxiliary_control_c248f0:
    rts
