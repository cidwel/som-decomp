; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_actor_equipment_field_and_restore_index_status = $7A54
remove_native_inventory_equipment_row_with_owner_cleanup = $75AE
routine_c07598 = $7598
test_native_menu_item_protected_bit = $79F9

.segment "CODE"
.org $7561
test_native_previous_equipment_before_reassignment:
    rep #$30
    ldx a:$182A
    jsr read_native_actor_equipment_field_and_restore_index_status
    jsr test_native_menu_item_protected_bit
    bne routine_c07598
    jsr remove_native_inventory_equipment_row_with_owner_cleanup
