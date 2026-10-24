; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-rows.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_descriptor_from_category_table = $D263

.segment "CODE"
.org $D0FB
build_native_consumable_inventory_descriptor_rows:
    .i16
    ldx #$0000
    .a16
    lda #$000C
build_native_consumable_inventory_descriptor_rows_d0d101:
    pha
    lda f:$7ECC48,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq build_native_consumable_inventory_descriptor_rows_d0d119
    .a16
    and #$001F
    .a16
    cmp #$000D
    bcs build_native_consumable_inventory_descriptor_rows_d0d119
    jsr append_native_menu_descriptor_from_category_table
build_native_consumable_inventory_descriptor_rows_d0d119:
    inx
    pla
    dec
    bne build_native_consumable_inventory_descriptor_rows_d0d101
    lda a:$1873
    .a16
    and #$00FF
    sta a:$182E
    rts
