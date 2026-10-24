; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

resolve_native_rotated_inventory_selection_with_sparse_armor_slots = $7635

.segment "CODE"
.org $751F
resolve_previous_native_equipment_row_before_equip:
    rep #$30
    lda a:$185C
    jsr resolve_native_rotated_inventory_selection_with_sparse_armor_slots
