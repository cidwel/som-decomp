; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-builder.md.
.setcpu "65816"
.smart
.a8
.i16

build_three_native_packed_equipment_rank_rows = $CFFA
clear_native_menu_descriptor_row_attributes = $D308

.segment "CODE"
.org $CFC1
dispatch_native_inventory_category_or_packed_equipment_rows:
    sep #$20
    lda a:$1847
    .a8
    cmp #$02
    bne dispatch_native_inventory_category_or_packed_equipment_rows_d0cfd4
    lda a:$1809
    beq dispatch_native_inventory_category_or_packed_equipment_rows_d0cfd4
    .a8
    cmp #$04
    bcs dispatch_native_inventory_category_or_packed_equipment_rows_d0cfd4
    rts
dispatch_native_inventory_category_or_packed_equipment_rows_d0cfd4:
    jsr clear_native_menu_descriptor_row_attributes
    rep #$30
    lda a:$1803
    .a16
    bit #$0080
    bne build_three_native_packed_equipment_rank_rows
    lda a:$1809
    .a16
    and #$00FF
    asl
    tax
    jmp ($CFEC,X)
