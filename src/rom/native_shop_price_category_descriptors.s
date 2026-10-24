; Descending category ranges: event id, armor row, near price pointer.
.setcpu "65816"
.segment "CODE"
.org $FB84
native_shop_price_category_descriptors:
consumable_shop_prices = $FB9C
    .word 186, 0, consumable_shop_prices
armor_accessory_shop_prices = $FC08
    .word 165, 42, armor_accessory_shop_prices
armor_body_shop_prices = $FBDE
    .word 144, 21, armor_body_shop_prices
armor_head_shop_prices = $FBB4
    .word 123, 0, armor_head_shop_prices
