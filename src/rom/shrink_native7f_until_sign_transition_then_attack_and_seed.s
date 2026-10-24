; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
prepare_boss_loader_resource_expansion = $24C3
publish_native7f_actor_mask_to_party_and_collision_byte = $90E4
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $910E
shrink_native7f_until_sign_transition_then_attack_and_seed:
    ldx $87
    lda a:$00B0,X
    sec
    .a16
    sbc #$0040
    sta a:$00B0,X
    bpl shrink_native7f_until_sign_transition_then_attack_and_seed_c29153
    stz a:$0096,X
    .a16
    lda #$0117
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0080
    sta a:$00B0,X
    stz a:$0090,X
    stz a:$002B,X
    .a16
    lda #$000E
    sta a:$0094,X
    .a16
    lda #$001F
    jsr prepare_boss_loader_resource_expansion
    .a16
    lda #$0001
    sta a:$00B6,X
    .a16
    lda #$0071
    ldx $87
    jsl f:boss_attack_row_public_jump
    ldx $87
    jsr publish_native7f_actor_mask_to_party_and_collision_byte
    ldx $87
shrink_native7f_until_sign_transition_then_attack_and_seed_c29153:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts
