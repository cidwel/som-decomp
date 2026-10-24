; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

cast_native59_weighted_random_spell = $86B3
cast_spell_public_jump = $C0001B
consume_native59_known_action_spell_or_report_unrecognized = $867A
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
draw_boss_frame_random_number = $300B
prepare_boss_spell_targets = $396D
prepare_native59_attack_and_allocate_target_linked_projectile = $86E4
routine_01800f = $1800F
select_farthest_active_living_party_actor_last_tie = $325A

.segment "CODE"
.org $85EB
execute_native59_variant_projectile_or_conditioned_spell:
    ldx $87
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$00AD,X
    jsr select_farthest_active_living_party_actor_last_tie
    ldx $87
    sta a:$00A9,X
    lda a:$0042,X
    bne execute_native59_variant_projectile_or_conditioned_spell_c2861f
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    bne execute_native59_variant_projectile_or_conditioned_spell_c28612
    jsr cast_native59_weighted_random_spell
    ldx $87
    dec a:$0094,X
    clc
    rts
execute_native59_variant_projectile_or_conditioned_spell_c28612:
    jsr prepare_native59_attack_and_allocate_target_linked_projectile
    ldx $87
    inc a:$00B6,X
    dec a:$0094,X
    clc
    rts
execute_native59_variant_projectile_or_conditioned_spell_c2861f:
    jsr consume_native59_known_action_spell_or_report_unrecognized
    bcs execute_native59_variant_projectile_or_conditioned_spell_c28642
    .a16
    and #$00FF
    .a16
    ora #$0000
    jsr prepare_boss_spell_targets
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne execute_native59_variant_projectile_or_conditioned_spell_c28673
    lda $87
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
    bra execute_native59_variant_projectile_or_conditioned_spell_c28673
execute_native59_variant_projectile_or_conditioned_spell_c28642:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bne execute_native59_variant_projectile_or_conditioned_spell_c28673
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    tax
    lda f:$C286AF,X
    .a16
    and #$00FF
    .a16
    ora #$0000
    ldx $87
    jsr prepare_boss_spell_targets
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne execute_native59_variant_projectile_or_conditioned_spell_c28673
    lda $87
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
execute_native59_variant_projectile_or_conditioned_spell_c28673:
    ldx $87
    dec a:$0094,X
    clc
    rts
