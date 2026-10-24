; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-upgrade.md.
.setcpu "65816"
.smart
.a8
.i16

play_native_shop_error_then_display_selected_notice = $7B7D

.segment "CODE"
.org $7B84
select_native_upgrade_insufficient_money_notice:
    .i16
    ldx #$FE96
    bra play_native_shop_error_then_display_selected_notice
