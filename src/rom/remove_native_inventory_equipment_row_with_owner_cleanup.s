; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

compact_native_equipment_inventory_after_removed_slot = $7E12
mark_selected_native_ring_row_and_return_owner_or_special_descriptor = $794A
read_native_actor_equipment_field_and_restore_index_status = $7A54
resolve_native_rotated_inventory_selection_with_sparse_armor_slots = $7635
routine_c07589 = $7589
routine_c07598 = $7598
test_native_menu_item_protected_bit = $79F9

.segment "CODE"
.org $75AE
remove_native_inventory_equipment_row_with_owner_cleanup:
    rep #$30
    ldx a:$182A
    jsr read_native_actor_equipment_field_and_restore_index_status
    jsr test_native_menu_item_protected_bit
    bne routine_c07598
    sep #$20
    lda a:$180A
    jsr resolve_native_rotated_inventory_selection_with_sparse_armor_slots
    jsr mark_selected_native_ring_row_and_return_owner_or_special_descriptor
    .a8
    cmp #$FE
    bne remove_native_inventory_equipment_row_with_owner_cleanup_c075d0
    lda a:$185C
    jsr resolve_native_rotated_inventory_selection_with_sparse_armor_slots
remove_native_inventory_equipment_row_with_owner_cleanup_c075d0:
    ldx a:$182C
    rep #$20
    lda a:$186A
    clc
    .a16
    adc #$000B
    sta a:$1851
    jsr compact_native_equipment_inventory_after_removed_slot
    bra routine_c07589
