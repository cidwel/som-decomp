; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9027
wait_native7f_animation_then_change_phase_seed_and_matrix_offsets:
    ldx $87
    lda a:$009E,X
    bne wait_native7f_animation_then_change_phase_seed_and_matrix_offsets_c29049
    stz a:$0096,X
    inc a:$0094,X
    stz a:$0096,X
    .a16
    lda #$0112
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$000C
    sta a:$02D5
    .a16
    lda #$0006
    sta a:$02D7
wait_native7f_animation_then_change_phase_seed_and_matrix_offsets_c29049:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts
