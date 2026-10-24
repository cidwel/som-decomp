; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-frame-requests.md.
.setcpu "65816"
.smart
.a8
.i16

derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F

.segment "CODE"
.org $9499
move_native7f_up_two_pixels_until_unsigned_y_at_most0160:
    ldx $87
    lda a:$0032,X
    sec
    .a16
    sbc #$0002
    sta a:$0032,X
    .a16
    lda #$0160
    cmp a:$0032,X
    bcc move_native7f_up_two_pixels_until_unsigned_y_at_most0160_c294b9
    stz a:$0096,X
    .a16
    lda #$000B
    sta a:$0094,X
    stz a:$0096,X
move_native7f_up_two_pixels_until_unsigned_y_at_most0160_c294b9:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts
