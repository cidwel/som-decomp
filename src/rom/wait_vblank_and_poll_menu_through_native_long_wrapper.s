; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $695A
wait_vblank_and_poll_menu_through_native_long_wrapper:
    jsr wait_vblank_before_polling_native_menu_input
    rtl
