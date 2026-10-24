; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-sale.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7B7A
select_native_shop_unsellable_item_notice:
    .i16
    ldx #$FE65
