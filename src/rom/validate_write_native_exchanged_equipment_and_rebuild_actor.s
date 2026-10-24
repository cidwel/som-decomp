; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-swap.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_native_equipped_actor_stats_and_cap_persistent_mana = $7A28
refresh_native_equipped_sprite_id_and_clear_pose_offsets = $7699
test_native_menu_item_eligibility_for_selected_hero = $C079C7
write_native_actor_equipment_field_with_weapon_palette_alias = $7A7D

.segment "CODE"
.org $781E
validate_write_native_exchanged_equipment_and_rebuild_actor:
    rep #$30
    phx
    pha
    pha
    txa
    lsr
    xba
    tay
    pla
    jsl f:test_native_menu_item_eligibility_for_selected_hero
    bne validate_write_native_exchanged_equipment_and_rebuild_actor_c0783e
    sep #$20
    lda a:$1809
    .a8
    cmp #$03
    beq validate_write_native_exchanged_equipment_and_rebuild_actor_c0783e
    rep #$30
    .a16
    lda #$0015
    sta $01,S
validate_write_native_exchanged_equipment_and_rebuild_actor_c0783e:
    rep #$30
    pla
    plx
    sep #$20
    .a8
    and #$7F
    jsr write_native_actor_equipment_field_with_weapon_palette_alias
    phx
    lda a:$1809
    .a8
    cmp #$03
    bne validate_write_native_exchanged_equipment_and_rebuild_actor_c0785b
    rep #$20
    txa
    .a16
    ora #$E180
    tax
    jsr refresh_native_equipped_sprite_id_and_clear_pose_offsets
validate_write_native_exchanged_equipment_and_rebuild_actor_c0785b:
    rep #$30
    pla
    .a16
    and #$0600
    tax
    jsr rebuild_native_equipped_actor_stats_and_cap_persistent_mana
    rts
