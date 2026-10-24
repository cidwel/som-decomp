; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-rows.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_descriptor_from_category_table = $D263
locate_menu_category_inventory_and_equipment_spans = $D0C800
publish_native_inventory_owner_and_rotated_selection_attribute = $D279

.segment "CODE"
.org $D22F
build_native_category_inventory_descriptor_rows:
    rep #$30
    phy
    jsl f:locate_menu_category_inventory_and_equipment_spans
    stx a:$182C
    sty a:$182A
    sta a:$183C
    ply
    .a16
    lda #$000B
build_native_category_inventory_descriptor_rows_d0d243:
    pha
    lda f:$7ECC00,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq build_native_category_inventory_descriptor_rows_d0d25d
    .a16
    and #$003F
    jsr publish_native_inventory_owner_and_rotated_selection_attribute
    sec
    sbc a:$183C
    jsr append_native_menu_descriptor_from_category_table
build_native_category_inventory_descriptor_rows_d0d25d:
    inx
    pla
    dec
    bne build_native_category_inventory_descriptor_rows_d0d243
    rts
