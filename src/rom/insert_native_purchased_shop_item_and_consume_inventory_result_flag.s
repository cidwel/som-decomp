; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-inventory-insert.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_event_inventory_command = $C00051

.segment "CODE"
.org $7D83
insert_native_purchased_shop_item_and_consume_inventory_result_flag:
    rep #$30
    .a16
    and #$00FF
    sec
    .a16
    sbc #$007B
    .a16
    cmp #$003F
    bcc insert_native_purchased_shop_item_and_consume_inventory_result_flag_c07d99
    sec
    .a16
    sbc #$003F
    clc
    .a16
    adc #$0040
insert_native_purchased_shop_item_and_consume_inventory_result_flag_c07d99:
    jsl f:jump_public_event_inventory_command
    sep #$20
    lda f:$7ECF0F
    pha
    .a8
    lda #$00
    sta f:$7ECF0F
    pla
    rep #$20
    .a16
    and #$00FF
    rts
