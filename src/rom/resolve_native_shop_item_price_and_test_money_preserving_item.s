; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-price-lookup.md.
.setcpu "65816"
.smart
.a8
.i16

resolve_native_shop_item_price_from_descending_category_table = $7CA5
test_native_shop_money_against_selected_price = $7C86

.segment "CODE"
.org $7C7B
resolve_native_shop_item_price_and_test_money_preserving_item:
    rep #$30
    pha
    jsr resolve_native_shop_item_price_from_descending_category_table
    jsr test_native_shop_money_against_selected_price
    pla
    rts
