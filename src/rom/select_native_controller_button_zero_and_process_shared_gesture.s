; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
handle_native_controller_direction_and_unwind_nested_callback_frame = $314B
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC
request_native_menu_change_or_confirm_preset_preserving_low_accumulator = $1BAA

.segment "CODE"
.org $30B7
select_native_controller_button_zero_and_process_shared_gesture:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $42,X
    .a8
    and #$C0
    bne select_native_controller_button_zero_and_process_shared_gesture_c030fe
    lda $43,X
    .a8
    and #$C0
    .a8
    cmp #$40
    bne select_native_controller_button_zero_and_process_shared_gesture_c030fe
    .a8
    lda #$00
    pha
    xba
    lda a:$A1D8
    .a8
    cmp #$04
    bne select_native_controller_button_zero_and_process_shared_gesture_c030d7
    xba
    sta a:$A1D8
select_native_controller_button_zero_and_process_shared_gesture_c030d7:
    pla
    sta a:$A1D7
    cmp a:$A1D8
    bne select_native_controller_button_zero_and_process_shared_gesture_c030fe
    sta a:$A1D8
    pha
    .a8
    lda #$40
    bit a:$A212
    bne select_native_controller_button_zero_and_process_shared_gesture_c030f6
    tsb a:$A212
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
    pla
    sta a:$A211
    pha
select_native_controller_button_zero_and_process_shared_gesture_c030f6:
    pla
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
    jsr handle_native_controller_direction_and_unwind_nested_callback_frame
select_native_controller_button_zero_and_process_shared_gesture_c030fe:
    rts
