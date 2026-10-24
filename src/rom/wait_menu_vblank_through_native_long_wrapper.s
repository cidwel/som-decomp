; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

await_vblank_edge_and_run_complete_menu_text_frame = $6943

.segment "CODE"
.org $693F
wait_menu_vblank_through_native_long_wrapper:
    jsr await_vblank_edge_and_run_complete_menu_text_frame
    rtl
