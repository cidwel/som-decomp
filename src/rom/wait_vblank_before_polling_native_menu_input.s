; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

await_vblank_edge_and_run_complete_menu_text_frame = $6943

.segment "CODE"
.org $695E
wait_vblank_before_polling_native_menu_input:
    jsr await_vblank_edge_and_run_complete_menu_text_frame
