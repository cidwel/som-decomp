; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-frame-requests.md.
.setcpu "65816"
.smart
.a8
.i16

derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
prepare_boss_loader_resource_expansion = $24C3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9463
shrink_native7f_scale_by_eight_then_enter_phase_fifteen:
    ldx $87
    lda a:$00B0,X
    sec
    .a16
    sbc #$0008
    sta a:$00B0,X
    bpl shrink_native7f_scale_by_eight_then_enter_phase_fifteen_c29494
    stz a:$0096,X
    .a16
    lda #$0080
    sta a:$00B0,X
    stz a:$002B,X
    .a16
    lda #$0117
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$000F
    sta a:$0094,X
    .a16
    lda #$0020
    jsr prepare_boss_loader_resource_expansion
    stz a:$00B6,X
    ldx $87
shrink_native7f_scale_by_eight_then_enter_phase_fifteen_c29494:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts
