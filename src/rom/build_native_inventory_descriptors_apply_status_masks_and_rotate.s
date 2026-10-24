; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-builder.md.
.setcpu "65816"
.smart
.a8
.i16

apply_native_inventory_status_masks_public_wrapper = $D9FCBD
dispatch_native_inventory_category_or_packed_equipment_rows = $CFC1
rotate_native_menu_descriptor_rows_and_append_category_tail = $D319

.segment "CODE"
.org $CF9C
build_native_inventory_descriptors_apply_status_masks_and_rotate:
    sep #$30
    lda a:$1809
    asl
    tax
    rep #$30
    lda f:$D8FD60,X
    sta a:$1828
    .i16
    ldy #$1880
    jsr dispatch_native_inventory_category_or_packed_equipment_rows
    rep #$30
    .a16
    lda #$FFFF
    sta a:$0000,Y
    jsl f:apply_native_inventory_status_masks_public_wrapper
    jmp rotate_native_menu_descriptor_rows_and_append_category_tail
