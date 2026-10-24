; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

decrement_native_shop_selector_unless_zero = $C762A5
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
increment_native_shop_selector_unless_thirty_one = $C76292

.segment "CODE"
.org $2BBA
adjust_native_three_component_selector_from_current_left_right:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    phx
    lda $43,X
    .a8
    and #$02
    beq adjust_native_three_component_selector_from_current_left_right_c02bc8
    jsl f:decrement_native_shop_selector_unless_zero
adjust_native_three_component_selector_from_current_left_right_c02bc8:
    plx
    lda $43,X
    .a8
    and #$01
    beq adjust_native_three_component_selector_from_current_left_right_c02bd8
    jsl f:increment_native_shop_selector_unless_thirty_one
    .a8
    lda #$80
    tsb a:$A212
adjust_native_three_component_selector_from_current_left_right_c02bd8:
    rts
