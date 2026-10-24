; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-upgrade.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_menu_ring_frames_until_phase_zero = $68F1
calculate_wrapped_native_menu_row_index = $C06BE2
clear_packed_menu_flag_then_open_native_ring = $68FF
confirm_native_shop_transaction_with_real_dialogue_and_controller = $7E30
deduct_native_shop_price_from_persistent_money = $7D0D
display_native_shop_message_wait_release_and_new_button_then_refresh = $7E95
play_native_purchase_sound_and_publish_numeric_window_twice = $7B00
query_native_item_slot_description_index_with_saved_context = $C06481
rebuild_actor_stats_public_jump = $C00036
resolve_selected_armor_inventory_row_and_description_id = $C07C4C
select_native_upgrade_insufficient_money_notice = $7B84
select_native_upgrade_maximum_level_notice = $7B90
select_native_upgrade_missing_orb_notice = $7B89
test_native_shop_money_against_selected_price = $7C86

.segment "CODE"
.org $7B95
upgrade_native_selected_weapon_with_orbs_money_and_equipped_hero_rebuild:
    jsr confirm_native_shop_transaction_with_real_dialogue_and_controller
    beq upgrade_native_selected_weapon_with_orbs_money_and_equipped_hero_rebuild_c07b9b
    rts
upgrade_native_selected_weapon_with_orbs_money_and_equipped_hero_rebuild_c07b9b:
    rep #$30
    jsl f:resolve_selected_armor_inventory_row_and_description_id
    sep #$20
    rep #$10
    lda f:$7ECFB0,X
    .a8
    cmp #$08
    bcs select_native_upgrade_maximum_level_notice
    cmp f:$7ECFB8,X
    bcs select_native_upgrade_missing_orb_notice
    rep #$30
    lda a:$1842
    .a16
    and #$00FF
    asl
    clc
    adc f:$D8FB82
    tax
    lda f:$D80000,X
    sta a:$1822
    jsr test_native_shop_money_against_selected_price
    .i16
    cpx #$0000
    bne select_native_upgrade_insufficient_money_notice
    sep #$30
    ldx a:$1843
    lda f:$7ECFB0,X
    inc
    sta f:$7ECFB0,X
    .a8
    lda #$02
    sta a:$19F0
    lda a:$1808
    sta a:$19F2
    rep #$10
    ldx a:$183E
    lda f:$7ECC00,X
    inc
    sta f:$7ECC00,X
    .a8
    bit #$C0
    beq upgrade_native_selected_weapon_with_orbs_money_and_equipped_hero_rebuild_c07c28
    rep #$20
    .a16
    and #$00C0
    pha
    txa
    sec
    .a16
    sbc #$0054
    tay
    jsl f:query_native_item_slot_description_index_with_saved_context
    sta a:$1839
    pla
    asl
    asl
    sec
    .a16
    sbc #$0100
    .a16
    and #$0300
    asl
    tax
    sep #$20
    lda a:$1839
    sta f:$7EE1E8,X
    jsl f:rebuild_actor_stats_public_jump
upgrade_native_selected_weapon_with_orbs_money_and_equipped_hero_rebuild_c07c28:
    jsr deduct_native_shop_price_from_persistent_money
    jsr play_native_purchase_sound_and_publish_numeric_window_twice
    sep #$20
    .a8
    lda #$80
    tsb a:$1804
    rep #$30
    .i16
    ldx #$FE7E
    jsr display_native_shop_message_wait_release_and_new_button_then_refresh
    jsl f:calculate_wrapped_native_menu_row_index
    sep #$20
    sta a:$1846
    jsr clear_packed_menu_flag_then_open_native_ring
    jmp advance_native_menu_ring_frames_until_phase_zero
