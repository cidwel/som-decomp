; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-transaction-finish.md.
.setcpu "65816"
.smart
.a8
.i16

bind_native_menu_list_row_to_active_hero_oam_marker = $70A3
publish_native_inventory_row_attribute_public_wrapper = $D0D275

.segment "CODE"
.org $7971
rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction:
    rep #$30
    lda a:$182A
    pha
    lda a:$186A
    sta a:$182C
    lda a:$186C
    sta a:$182A
    ldx a:$182C
    lda a:$1809
    .a16
    and #$00FF
    tay
    lda a:$180B
    .a16
    and #$00FF
    .i16
    cpy #$0003
    beq rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction_c07999
    dec
rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction_c07999:
    pha
    lda f:$7ECC00,X
    jsl f:publish_native_inventory_row_attribute_public_wrapper
    inx
    pla
    dec
    bne rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction_c07999
    .i16
    ldx #$18C0
    .i16
    ldy #$0000
    lda a:$180B
    .a16
    and #$00FF
rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction_c079b3:
    pha
    jsr bind_native_menu_list_row_to_active_hero_oam_marker
    txa
    clc
    .a16
    adc #$0010
    tax
    pla
    iny
    dec
    bne rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction_c079b3
    pla
    sta a:$182A
    rts
