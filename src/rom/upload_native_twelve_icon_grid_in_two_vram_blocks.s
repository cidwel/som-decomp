; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-grid.md.
.setcpu "65816"
.smart
.a8
.i16

advance_menu_icon_palette_and_select_descriptor_tile = $C979
set_native_menu_icon_vram_cursor_then_fall_through = $C976

.segment "CODE"
.org $C94B
upload_native_twelve_icon_grid_in_two_vram_blocks:
    rep #$20
    .a16
    lda #$6E00
    jsr set_native_menu_icon_vram_cursor_then_fall_through
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    .a16
    lda #$7000
    jsr set_native_menu_icon_vram_cursor_then_fall_through
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    bra advance_menu_icon_palette_and_select_descriptor_tile
