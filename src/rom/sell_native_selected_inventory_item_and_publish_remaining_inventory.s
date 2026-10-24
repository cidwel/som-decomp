; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-sale.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_wrapped_native_menu_row_index = $C06BE2
confirm_native_shop_transaction_with_real_dialogue_and_controller = $7E30
credit_native_shop_price_and_cap_persistent_money = $7D34
locate_menu_category_inventory_and_equipment_spans = $D0C800
remove_native_sold_inventory_quantity_or_detach_equipment_and_compact = $7DB1
resolve_native_shop_item_price_from_descending_category_table = $7CA5
routine_c07af7 = $7AF7
routine_c07b0c = $7B0C
routine_d9fc90 = $D9FC90
select_native_shop_unsellable_item_notice = $7B7A

.segment "CODE"
.org $7B17
sell_native_selected_inventory_item_and_publish_remaining_inventory:
    jsr confirm_native_shop_transaction_with_real_dialogue_and_controller
    bne routine_c07b0c
    jsl f:locate_menu_category_inventory_and_equipment_spans
    rep #$30
    .i16
    cpx #$0054
    bne sell_native_selected_inventory_item_and_publish_remaining_inventory_c07b2a
    .i16
    ldx #$0048
sell_native_selected_inventory_item_and_publish_remaining_inventory_c07b2a:
    stx a:$1840
    sty a:$184F
    phx
    jsl f:calculate_wrapped_native_menu_row_index
    rep #$20
    .a16
    and #$00FF
    clc
    adc $01,S
    plx
    tax
    stx a:$183E
    sep #$20
    lda f:$7ECC00,X
    .a8
    and #$3F
    clc
    .a8
    adc #$7B
    .i16
    cpx #$0048
    bcc sell_native_selected_inventory_item_and_publish_remaining_inventory_c07b5b
    lda f:$7ECC00,X
    .a8
    and #$1F
    clc
    .a8
    adc #$BA
sell_native_selected_inventory_item_and_publish_remaining_inventory_c07b5b:
    rep #$30
    jsr resolve_native_shop_item_price_from_descending_category_table
    .a16
    cmp #$FFFF
    beq select_native_shop_unsellable_item_notice
    jsr remove_native_sold_inventory_quantity_or_detach_equipment_and_compact
    bne select_native_shop_unsellable_item_notice
    jsr credit_native_shop_price_and_cap_persistent_money
    jsl f:routine_d9fc90
    beq sell_native_selected_inventory_item_and_publish_remaining_inventory_c07b76
    jmp routine_c07af7
sell_native_selected_inventory_item_and_publish_remaining_inventory_c07b76:
    stz a:$1826
    rts
