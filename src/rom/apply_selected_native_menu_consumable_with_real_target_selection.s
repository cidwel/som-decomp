; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-consumable-action.md.
.setcpu "65816"
.smart
.a8
.i16

apply_native_consumable_effect_public_alias = $C0002A
build_native_three_actor_menu_target_list_and_count = $D0DA60
change_native_consumable_quantity_and_compact_depleted_inventory = $C078C3
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags = $787E
handle_native_special_consumable_ownership_or_modal_error_notice = $727F
request_event_menu_loop_and_initialize_input_state = $692D
request_native_menu_audio_0d = $D0CF00
request_native_menu_audio_0e = $D0CF08
select_native_menu_target_with_controller_edges_and_real_vblank = $D0DB58

.segment "CODE"
.org $7212
apply_selected_native_menu_consumable_with_real_target_selection:
    sep #$30
    lda a:$1808
    sta a:$19F2
    ldx a:$1873
    lda f:$7ECC48,X
    .a8
    and #$1F
    sta a:$19F1
    .a8
    cmp #$06
    beq handle_native_special_consumable_ownership_or_modal_error_notice
    .a8
    cmp #$07
    beq handle_native_special_consumable_ownership_or_modal_error_notice
    sep #$30
    .a8
    lda #$00
    sta a:$1842
    jsl f:build_native_three_actor_menu_target_list_and_count
    beq apply_selected_native_menu_consumable_with_real_target_selection_c07271
    jsl f:select_native_menu_target_with_controller_edges_and_real_vblank
    bne apply_selected_native_menu_consumable_with_real_target_selection_c07275
    jsl f:request_native_menu_audio_0e
    jsr encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags
    rep #$30
    ldx a:$1822
    lda $00,X
    .a16
    and #$0E00
    tax
    lda a:$19F1
    jsl f:apply_native_consumable_effect_public_alias
    sep #$30
    lda a:$19F1
    .a8
    cmp #$08
    beq apply_selected_native_menu_consumable_with_real_target_selection_c07270
    .a8
    cmp #$09
    beq apply_selected_native_menu_consumable_with_real_target_selection_c07270
    ldx a:$1873
    .a8
    lda #$FF
    jsl f:change_native_consumable_quantity_and_compact_depleted_inventory
apply_selected_native_menu_consumable_with_real_target_selection_c07270:
    rts
apply_selected_native_menu_consumable_with_real_target_selection_c07271:
    jsl f:request_native_menu_audio_0d
apply_selected_native_menu_consumable_with_real_target_selection_c07275:
    sep #$20
    .a8
    lda #$10
    tsb a:$1804
    jmp request_event_menu_loop_and_initialize_input_state
