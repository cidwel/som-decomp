; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-upgrade.md.
.setcpu "65816"
.smart
.a8
.i16

play_native_shop_error_then_display_selected_notice = $7B7D

.segment "CODE"
.org $7B89
select_native_upgrade_missing_orb_notice:
    rep #$30
    .i16
    ldx #$FEB5
    bra play_native_shop_error_then_display_selected_notice
