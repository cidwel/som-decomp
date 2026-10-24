; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16

derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F

.segment "CODE"
.org $917F
advance_native7f_integer_y_and_change_phase_above_0160:
    ldx $87
    lda a:$0032,X
    clc
    .a16
    adc #$0002
    sta a:$0032,X
    .a16
    lda #$0160
    cmp a:$0032,X
    bcs advance_native7f_integer_y_and_change_phase_above_0160_c2919f
    stz a:$0096,X
    .a16
    lda #$000B
    sta a:$0094,X
    stz a:$0096,X
advance_native7f_integer_y_and_change_phase_above_0160_c2919f:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts
