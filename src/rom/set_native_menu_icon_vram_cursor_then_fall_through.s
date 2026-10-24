; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-upload.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C976
set_native_menu_icon_vram_cursor_then_fall_through:
    sta a:$180C
