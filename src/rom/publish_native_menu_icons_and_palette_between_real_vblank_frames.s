; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-grid.md.
.setcpu "65816"
.smart
.a8
.i16

await_vblank_edge_and_run_complete_menu_text_frame = $6943
choose_native_icon_palette_page_from_menu_mode = $D0CB1F
publish_native_menu_icon_grid_or_equipment_preview = $D0C8FB

.segment "CODE"
.org $6977
publish_native_menu_icons_and_palette_between_real_vblank_frames:
    jsr await_vblank_edge_and_run_complete_menu_text_frame
    jsl f:publish_native_menu_icon_grid_or_equipment_preview
    jsr await_vblank_edge_and_run_complete_menu_text_frame
    jsl f:choose_native_icon_palette_page_from_menu_mode
    rts
