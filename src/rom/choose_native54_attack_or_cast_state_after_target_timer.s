; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

consume_native54_action_damage_and_initialize_auxiliary_recoil = $496C
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_boss_animation_and_reset_frame_cursor = $1394
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $4A63
choose_native54_attack_or_cast_state_after_target_timer:
    ldx $87
    jsr consume_native54_action_damage_and_initialize_auxiliary_recoil
    bcs choose_native54_attack_or_cast_state_after_target_timer_c24ad4
    lda a:$00AD,X
    cmp a:$002D,X
    bcc choose_native54_attack_or_cast_state_after_target_timer_c24ad4
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$00AD,X
    stz a:$0096,X
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    lda a:$0042,X
    beq choose_native54_attack_or_cast_state_after_target_timer_c24ac6
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    ldx $87
    .a16
    cmp #$0006
    bcc choose_native54_attack_or_cast_state_after_target_timer_c24ac6
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne choose_native54_attack_or_cast_state_after_target_timer_c24ac6
    ldx $87
    .a16
    lda #$0009
    sta a:$0094,X
    stz a:$00B4,X
    lda $89
    sec
    .a16
    sbc #$F800
    tay
    sep #$20
    lda a:$F811,Y
    sta a:$007A,X
    lda a:$F80D,Y
    sta a:$007B,X
    .a8
    lda #$44
    sta a:$F813,Y
    rep #$20
    clc
    rts
choose_native54_attack_or_cast_state_after_target_timer_c24ac6:
    ldx $87
    .a16
    lda #$0006
    sta a:$0094,X
    .a16
    lda #$0076
    jsr select_boss_animation_and_reset_frame_cursor
choose_native54_attack_or_cast_state_after_target_timer_c24ad4:
    clc
    rts
