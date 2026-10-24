; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_four_tile_icon_group = $6D17

.segment "CODE"
.org $5F13
append_two_native_menu_four_tile_icon_groups:
    jsr append_native_menu_four_tile_icon_group
    inc a:$A159
    dec a:$A15A
    jsr append_native_menu_four_tile_icon_group
    rts
