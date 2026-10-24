; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_ring_blink_bit_in_twelve_rows = $7908
equip_native_inventory_row_for_current_hero = $7527
mark_selected_native_ring_row_and_return_owner_or_special_descriptor = $794A
routine_c07275 = $7275

.segment "CODE"
.org $7504
retarget_native_selected_equipment_owner_or_apply_same_row:
    sep #$20
    lda a:$180A
    cmp a:$185C
    beq equip_native_inventory_row_for_current_hero
    sta a:$185C
    jsr clear_native_menu_ring_blink_bit_in_twelve_rows
    jsr mark_selected_native_ring_row_and_return_owner_or_special_descriptor
    sep #$20
    sta a:$185D
    jmp routine_c07275
