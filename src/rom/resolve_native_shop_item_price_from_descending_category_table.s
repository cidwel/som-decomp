; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-price-lookup.md.
.setcpu "65816"
.smart
.a8
.i16

adjust_menu_price_for_shop_and_inventory_modes = $C07CD4

.segment "CODE"
.org $7CA5
resolve_native_shop_item_price_from_descending_category_table:
    rep #$30
    .a16
    and #$00FF
    .i16
    ldx #$FB84
resolve_native_shop_item_price_from_descending_category_table_c07cad:
    cmp f:$D80000,X
    bcs resolve_native_shop_item_price_from_descending_category_table_c07cbb
    inx
    inx
    inx
    inx
    inx
    inx
    bra resolve_native_shop_item_price_from_descending_category_table_c07cad
resolve_native_shop_item_price_from_descending_category_table_c07cbb:
    sec
    sbc f:$D80000,X
    asl
    pha
    lda f:$D80004,X
    clc
    adc $01,S
    tax
    pla
    lda f:$D80000,X
    jsl f:adjust_menu_price_for_shop_and_inventory_modes
    rts
