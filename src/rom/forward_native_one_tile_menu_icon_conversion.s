; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-single-icon.md.
.setcpu "65816"
.smart
.a8
.i16

call_native_one_tile_menu_icon_conversion_long = $642E

.segment "CODE"
.org $640E
forward_native_one_tile_menu_icon_conversion:
    jmp call_native_one_tile_menu_icon_conversion_long
