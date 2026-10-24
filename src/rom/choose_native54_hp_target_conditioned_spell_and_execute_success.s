; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-cast.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B
compute_capped_boss_maximum_over_current_hp_ratio = $09B4
draw_boss_frame_random_number = $300B
prepare_boss_spell_targets = $396D
routine_01800f = $1800F

.segment "CODE"
.org $4812
choose_native54_hp_target_conditioned_spell_and_execute_success:
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcs choose_native54_hp_target_conditioned_spell_and_execute_success_c2483a
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0190,Y
    bne choose_native54_hp_target_conditioned_spell_and_execute_success_c24832
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    inc
    bra choose_native54_hp_target_conditioned_spell_and_execute_success_c24840
choose_native54_hp_target_conditioned_spell_and_execute_success_c24832:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bra choose_native54_hp_target_conditioned_spell_and_execute_success_c24840
choose_native54_hp_target_conditioned_spell_and_execute_success_c2483a:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
choose_native54_hp_target_conditioned_spell_and_execute_success_c24840:
    asl
    tax
    lda f:$C2485F,X
    ldx $87
    jsr prepare_boss_spell_targets
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne choose_native54_hp_target_conditioned_spell_and_execute_success_c2485e
    lda $87
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
choose_native54_hp_target_conditioned_spell_and_execute_success_c2485e:
    rts
