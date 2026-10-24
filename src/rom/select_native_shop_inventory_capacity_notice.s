; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-purchase.md.
.setcpu "65816"
.smart
.a8
.i16

play_native_shop_error_then_display_selected_notice = $7B7D

.segment "CODE"
.org $7B12
select_native_shop_inventory_capacity_notice:
    .i16
    ldx #$FE49
    bra play_native_shop_error_then_display_selected_notice
