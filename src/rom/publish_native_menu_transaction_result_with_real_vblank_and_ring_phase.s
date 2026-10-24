; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-transaction-finish.md.
.setcpu "65816"
.smart
.a8
.i16

await_vblank_edge_and_run_complete_menu_text_frame = $6943
clear_native_first_two_ring_rows_and_hide_hero_markers = $7922
clear_native_menu_ring_blink_bit_in_twelve_rows = $7908
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction = $7971

.segment "CODE"
.org $761A
publish_native_menu_transaction_result_with_real_vblank_and_ring_phase:
    sep #$20
    .a8
    lda #$04
    tsb a:$1802
    .a8
    lda #$02
    tsb a:$1803
    jsr clear_native_menu_ring_blink_bit_in_twelve_rows
    jsr clear_native_first_two_ring_rows_and_hide_hero_markers
    jsr rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction
    jsr await_vblank_edge_and_run_complete_menu_text_frame
    jmp dispatch_native_menu_ring_phase_from_original_jump_table
