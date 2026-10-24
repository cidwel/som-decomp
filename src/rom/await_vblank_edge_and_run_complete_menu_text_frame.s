; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_and_run_complete_native_menu_dialogue_frame = $D0D397

.segment "CODE"
.org $6943
await_vblank_edge_and_run_complete_menu_text_frame:
    sep #$20
await_vblank_edge_and_run_complete_menu_text_frame_c06945:
    lda a:$4212
    bmi await_vblank_edge_and_run_complete_menu_text_frame_c06945
await_vblank_edge_and_run_complete_menu_text_frame_c0694a:
    lda a:$4212
    bpl await_vblank_edge_and_run_complete_menu_text_frame_c0694a
    .a8
    lda #$08
    tsb $EC
    jsl f:prepare_and_run_complete_native_menu_dialogue_frame
    rep #$20
    rts
