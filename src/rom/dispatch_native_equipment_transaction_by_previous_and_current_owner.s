; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

classify_native_menu_row_owner_for_equipment_transaction = $74D2
locate_menu_category_inventory_and_equipment_spans = $D0C800
mark_selected_native_ring_row_and_return_owner_or_special_descriptor = $794A
resolve_native_rotated_inventory_selection_with_sparse_armor_slots = $7635

.segment "CODE"
.org $748A
dispatch_native_equipment_transaction_by_previous_and_current_owner:
    jsl f:locate_menu_category_inventory_and_equipment_spans
    rep #$30
    stx a:$186A
    sty a:$186C
    sta a:$1840
    phy
    lda a:$1808
    .a16
    and #$0003
    xba
    asl
    clc
    .a16
    adc #$E180
    clc
    adc $01,S
    sta a:$182A
    pla
    stx a:$1820
    lda a:$180A
    jsr resolve_native_rotated_inventory_selection_with_sparse_armor_slots
    sep #$30
    lda a:$185D
    jsr classify_native_menu_row_owner_for_equipment_transaction
    pha
    jsr mark_selected_native_ring_row_and_return_owner_or_special_descriptor
    jsr classify_native_menu_row_owner_for_equipment_transaction
    asl
    asl
    clc
    adc $01,S
    ply
    asl
    tax
    rep #$30
    jmp ($74E4,X)
