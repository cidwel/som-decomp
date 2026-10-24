; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16

await_vblank_edge_and_run_complete_menu_text_frame = $6943
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8

.segment "CODE"
.org $68F1
advance_native_menu_ring_frames_until_phase_zero:
advance_native_menu_ring_frames_until_phase_zero_c068f1:
    jsr await_vblank_edge_and_run_complete_menu_text_frame
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    rep #$30
    lda a:$1812
    bne advance_native_menu_ring_frames_until_phase_zero_c068f1
    rts
