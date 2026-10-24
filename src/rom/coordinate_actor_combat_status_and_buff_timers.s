; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_death_and_low_status_timer = $3CA5
advance_status_damage_timer_and_apply_nonlethal_hp_loss = $3D5F
enqueue_generic_actor_status_notice = $C058AF
expire_combat_high_status_group_timer = $3D4D
expire_combat_low_status_group_timer = $3D1C
expire_combat_mixed_status_group_timer = $3D31
expire_four_combat_buff_pairs_and_enqueue_notice = $3D91
expire_party_mana_weapon_and_rebuild_attributes = $3C88

.segment "CODE"
.org $3C19
coordinate_actor_combat_status_and_buff_timers:
    dec a:$E1B9,X
    bne coordinate_actor_combat_status_and_buff_timers_c03c35
    lda a:$E191,X
    bpl coordinate_actor_combat_status_and_buff_timers_c03c35
    lda a:$E1FB,X
    bpl coordinate_actor_combat_status_and_buff_timers_c03c35
    .a8
    lda #$04
    ora a:$E1FA,X
    sta a:$E1FA,X
    .a8
    lda #$F1
    sta a:$E1E3,X
coordinate_actor_combat_status_and_buff_timers_c03c35:
    jsr advance_actor_death_and_low_status_timer
    lda a:$E1B9,X
    .a8
    and #$03
    bne coordinate_actor_combat_status_and_buff_timers_c03c87
    jsr expire_combat_low_status_group_timer
    jsr expire_combat_mixed_status_group_timer
    jsr expire_combat_high_status_group_timer
    jsr advance_status_damage_timer_and_apply_nonlethal_hp_loss
    jsr expire_four_combat_buff_pairs_and_enqueue_notice
    lda $81
    bne coordinate_actor_combat_status_and_buff_timers_c03c6c
    lda a:$CC79
    beq coordinate_actor_combat_status_and_buff_timers_c03c5f
    dec a:$CC79
    bne coordinate_actor_combat_status_and_buff_timers_c03c5f
    jsr expire_party_mana_weapon_and_rebuild_attributes
coordinate_actor_combat_status_and_buff_timers_c03c5f:
    lda a:$CC78
    beq coordinate_actor_combat_status_and_buff_timers_c03c6c
    dec a:$CC78
    bne coordinate_actor_combat_status_and_buff_timers_c03c6c
    jsr expire_party_mana_weapon_and_rebuild_attributes
coordinate_actor_combat_status_and_buff_timers_c03c6c:
    lda a:$E1B1,X
    .a8
    bit #$04
    beq coordinate_actor_combat_status_and_buff_timers_c03c87
    .a8
    and #$FB
    sta a:$E1B1,X
    rep #$20
    lda a:$E190,X
    sep #$20
    beq coordinate_actor_combat_status_and_buff_timers_c03c87
    jsl f:enqueue_generic_actor_status_notice
    ldx $85
coordinate_actor_combat_status_and_buff_timers_c03c87:
    rts
