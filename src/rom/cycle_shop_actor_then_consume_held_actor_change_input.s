; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-selection-normal.md.
.setcpu "65816"
.smart
.a8
.i16

clear_packed_menu_flag_then_open_native_ring = $68FF
cycle_to_next_eligible_unbound_menu_actor = $6986
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
persist_native_menu_category_row_and_equipment_rank = $C06B4C
process_native_ring_cancel_and_confirm_input = $67A8
restore_native_menu_actor_saved_category = $6914
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $6775
cycle_shop_actor_then_consume_held_actor_change_input:
    sep #$30
    lda a:$1812
    bne process_native_ring_cancel_and_confirm_input
    lda a:$1800
    .a8
    bit #$40
    beq process_native_ring_cancel_and_confirm_input
    jsl f:persist_native_menu_category_row_and_equipment_rank
    jsr cycle_to_next_eligible_unbound_menu_actor
    beq process_native_ring_cancel_and_confirm_input
    jsr restore_native_menu_actor_saved_category
    jsr clear_packed_menu_flag_then_open_native_ring
    sep #$20
    .a8
    lda #$48
    trb a:$1803
cycle_shop_actor_then_consume_held_actor_change_input_c06799:
    jsr wait_vblank_before_polling_native_menu_input
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    sep #$20
    lda a:$1800
    .a8
    and #$40
    bne cycle_shop_actor_then_consume_held_actor_change_input_c06799
