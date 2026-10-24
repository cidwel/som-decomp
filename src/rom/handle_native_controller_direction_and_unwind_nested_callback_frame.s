; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_controller_layout_button_assignment = $C76E8B
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
request_native_menu_change_or_confirm_preset_preserving_low_accumulator = $1BAA
retreat_native_controller_layout_button_assignment_and_swap = $C76E8F

.segment "CODE"
.org $314B
handle_native_controller_direction_and_unwind_nested_callback_frame:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    phx
    lda $43,X
    cmp a:$A204,X
    beq handle_native_controller_direction_and_unwind_nested_callback_frame_c0317c
    ora $42,X
    .a8
    and #$C0
    beq handle_native_controller_direction_and_unwind_nested_callback_frame_c0317c
    lda $43,X
    .a8
    bit #$01
    beq handle_native_controller_direction_and_unwind_nested_callback_frame_c03169
    jsl f:advance_native_controller_layout_button_assignment
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
handle_native_controller_direction_and_unwind_nested_callback_frame_c03169:
    plx
    lda $43,X
    cmp a:$A204,X
    beq handle_native_controller_direction_and_unwind_nested_callback_frame_c0317c
    .a8
    bit #$02
    beq handle_native_controller_direction_and_unwind_nested_callback_frame_c0317c
    jsl f:retreat_native_controller_layout_button_assignment_and_swap
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
handle_native_controller_direction_and_unwind_nested_callback_frame_c0317c:
    plx
    rts
