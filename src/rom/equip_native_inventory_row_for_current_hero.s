; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

offset_armor_inventory_description_by_position = $D0D1FB
refresh_native_equipped_sprite_unless_modal_menu_context = $759E
remove_native_inventory_owner_and_return_owner_bits = $76CC
routine_c07598 = $7598
test_native_menu_item_eligibility_for_selected_hero = $C079C7
write_native_actor_equipment_field_with_weapon_palette_alias = $7A7D

.segment "CODE"
.org $7527
equip_native_inventory_row_for_current_hero:
    rep #$30
    ldx a:$182C
    lda f:$7ECC00,X
    .a16
    and #$003F
    ldy a:$1808
    jsl f:test_native_menu_item_eligibility_for_selected_hero
    beq routine_c07598
    rep #$30
    lda a:$1808
    jsr remove_native_inventory_owner_and_return_owner_bits
    sep #$20
    pha
    ldx a:$182C
    lda f:$7ECC00,X
    ora $01,S
    sta f:$7ECC00,X
    jsl f:offset_armor_inventory_description_by_position
    ldx a:$182A
    jsr write_native_actor_equipment_field_with_weapon_palette_alias
    pla
    bra refresh_native_equipped_sprite_unless_modal_menu_context
