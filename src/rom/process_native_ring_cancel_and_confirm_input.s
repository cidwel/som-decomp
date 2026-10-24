; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-selection-normal.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_menu_ring_frames_until_phase_zero = $68F1
clear_native_menu_ring_blink_bit_in_twelve_rows = $7908
clear_packed_menu_flag_then_open_native_ring = $68FF
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
dispatch_native_ring_action_and_settle_or_hide_selection = $68A7
persist_native_menu_category_row_and_equipment_rank = $C06B4C
poll_and_update_native_ring_until_confirm_and_cancel_are_released = $6896
request_native_menu_audio_2a = $D0CF18
request_native_menu_ring_open_and_build_selected_list = $6906
restore_native_menu_actor_saved_category = $6914
routine_c068e0 = $68E0
routine_d9fc90 = $D9FC90
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $67A8
process_native_ring_cancel_and_confirm_input:
    sep #$20
    lda a:$1804
    .a8
    bit #$08
    beq process_native_ring_cancel_and_confirm_input_c067bd
    lda a:$1801
    .a8
    bit #$40
    bne process_native_ring_cancel_and_confirm_input_c0680d
    .a8
    lda #$08
    trb a:$1804
process_native_ring_cancel_and_confirm_input_c067bd:
    rep #$30
    lda a:$1800
    .a16
    bit #$4000
    beq process_native_ring_cancel_and_confirm_input_c0680d
    jsl f:persist_native_menu_category_row_and_equipment_rank
    sep #$20
    .a8
    lda #$40
    bit a:$1803
    beq process_native_ring_cancel_and_confirm_input_c067e4
    trb a:$1803
    jsr clear_native_menu_ring_blink_bit_in_twelve_rows
    rep #$20
    stz a:$1800
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    bra process_native_ring_cancel_and_confirm_input_c06823
process_native_ring_cancel_and_confirm_input_c067e4:
    sep #$20
    lda a:$1803
    .a8
    bit #$88
    beq process_native_ring_cancel_and_confirm_input_c0680f
    jsl f:persist_native_menu_category_row_and_equipment_rank
    sep #$20
    lda a:$1803
    .a8
    bit #$08
    beq process_native_ring_cancel_and_confirm_input_c06804
    .a8
    lda #$C8
    trb a:$1803
    .a8
    lda #$02
    sta a:$1809
process_native_ring_cancel_and_confirm_input_c06804:
    jsr clear_packed_menu_flag_then_open_native_ring
    jsr advance_native_menu_ring_frames_until_phase_zero
    jsr poll_and_update_native_ring_until_confirm_and_cancel_are_released
process_native_ring_cancel_and_confirm_input_c0680d:
    bra process_native_ring_cancel_and_confirm_input_c06847
process_native_ring_cancel_and_confirm_input_c0680f:
    lda a:$1805
    cmp a:$1808
    beq process_native_ring_cancel_and_confirm_input_c0682f
    sta a:$1808
    jsr restore_native_menu_actor_saved_category
    jsr request_native_menu_ring_open_and_build_selected_list
    jsr advance_native_menu_ring_frames_until_phase_zero
process_native_ring_cancel_and_confirm_input_c06823:
    rep #$20
    jsr wait_vblank_before_polling_native_menu_input
    .a16
    and #$4000
    bne process_native_ring_cancel_and_confirm_input_c06823
    bra process_native_ring_cancel_and_confirm_input_c06847
process_native_ring_cancel_and_confirm_input_c0682f:
    rep #$20
    jsl f:request_native_menu_audio_2a
    .a16
    lda #$0006
    sta a:$1812
    .a16
    lda #$0001
    sta a:$1814
    jsr advance_native_menu_ring_frames_until_phase_zero
    stz a:$1826
process_native_ring_cancel_and_confirm_input_c06847:
    sep #$20
    lda a:$1806
    bne process_native_ring_cancel_and_confirm_input_c06894
    lda a:$1812
    bne process_native_ring_cancel_and_confirm_input_c06894
    rep #$20
    lda a:$1800
    .a16
    bit #$8000
    beq process_native_ring_cancel_and_confirm_input_c06894
    jsl f:persist_native_menu_category_row_and_equipment_rank
    sep #$20
    lda a:$1809
    dec
    bne dispatch_native_ring_action_and_settle_or_hide_selection
    .a8
    lda #$80
    bit a:$1803
    bne dispatch_native_ring_action_and_settle_or_hide_selection
    tsb a:$1803
    bra process_native_ring_cancel_and_confirm_input_c06887
    jsl f:routine_d9fc90
    bne process_native_ring_cancel_and_confirm_input_c06887
    sep #$20
    .a8
    lda #$02
    sta a:$1809
    .a8
    lda #$CA
    trb a:$1803
process_native_ring_cancel_and_confirm_input_c06887:
    jsr request_native_menu_ring_open_and_build_selected_list
    sep #$20
    .a8
    lda #$04
    tsb a:$1802
    jsr poll_and_update_native_ring_until_confirm_and_cancel_are_released
process_native_ring_cancel_and_confirm_input_c06894:
    bra routine_c068e0
