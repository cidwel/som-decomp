; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-rows.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_descriptor_from_category_table = $D263
offset_armor_inventory_description_by_position = $D0D1FB
publish_native_inventory_owner_and_rotated_selection_attribute = $D279

.segment "CODE"
.org $D1CF
build_native_armor_inventory_descriptor_rows:
    .a16
    lda #$0063
    sta a:$182A
    .i16
    ldx #$0054
    stx a:$182C
    .a16
    lda #$0008
build_native_armor_inventory_descriptor_rows_d0d1de:
    pha
    lda f:$7ECC00,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq build_native_armor_inventory_descriptor_rows_d0d1f5
    jsl f:offset_armor_inventory_description_by_position
    jsr publish_native_inventory_owner_and_rotated_selection_attribute
    jsr append_native_menu_descriptor_from_category_table
build_native_armor_inventory_descriptor_rows_d0d1f5:
    inx
    pla
    dec
    bne build_native_armor_inventory_descriptor_rows_d0d1de
    rts
