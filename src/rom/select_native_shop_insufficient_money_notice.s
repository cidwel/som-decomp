; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-purchase.md.
.setcpu "65816"
.smart
.a8
.i16

play_native_shop_error_then_display_selected_notice = $7B7D

.segment "CODE"
.org $7B0D
select_native_shop_insufficient_money_notice:
    .i16
    ldx #$FE2D
    bra play_native_shop_error_then_display_selected_notice
