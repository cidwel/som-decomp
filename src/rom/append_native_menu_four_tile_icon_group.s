; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_grid_icon_tile_from_rom = $6D30

.segment "CODE"
.org $6D17
append_native_menu_four_tile_icon_group:
    jsr append_native_menu_grid_icon_tile_from_rom
    inc a:$A15A
    jsr append_native_menu_grid_icon_tile_from_rom
    dec a:$A15A
    inc a:$A159
    jsr append_native_menu_grid_icon_tile_from_rom
    inc a:$A15A
    jsr append_native_menu_grid_icon_tile_from_rom
    rts
