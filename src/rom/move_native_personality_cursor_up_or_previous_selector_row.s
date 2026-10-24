; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-movement.md.
.setcpu "65816"
.smart
.a8
.i16

compare_selected_pad_buttons_against_native_previous_buttons = $325A
derive_native_personality_selector_cursor_coordinates = $C76C45
dispatch_native_name_page_party_icon_variant = $C75217
publish_four_native_name_entry_cursor_corners = $C7503D
request_native_menu_change_or_confirm_preset_preserving_low_accumulator = $1BAA

.segment "CODE"
.org $2F41
move_native_personality_cursor_up_or_previous_selector_row:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq move_native_personality_cursor_up_or_previous_selector_row_c02f82
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
    lda a:$A212
    .a8
    bit #$20
    bne move_native_personality_cursor_up_or_previous_selector_row_c02f6b
    lda a:$A136
    beq move_native_personality_cursor_up_or_previous_selector_row_c02f5a
    sec
    .a8
    sbc #$04
    bcs move_native_personality_cursor_up_or_previous_selector_row_c02f5b
move_native_personality_cursor_up_or_previous_selector_row_c02f5a:
    dec
move_native_personality_cursor_up_or_previous_selector_row_c02f5b:
    .a8
    and #$0F
    sta a:$A136
    jsl f:dispatch_native_name_page_party_icon_variant
    .a8
    lda #$04
    tsb a:$A20A
    bra move_native_personality_cursor_up_or_previous_selector_row_c02f82
move_native_personality_cursor_up_or_previous_selector_row_c02f6b:
    lda a:$A211
    dec
    .a8
    cmp #$FF
    bne move_native_personality_cursor_up_or_previous_selector_row_c02f77
    lda a:$A200
    dec
move_native_personality_cursor_up_or_previous_selector_row_c02f77:
    sta a:$A211
    jsl f:derive_native_personality_selector_cursor_coordinates
    jsl f:publish_four_native_name_entry_cursor_corners
move_native_personality_cursor_up_or_previous_selector_row_c02f82:
    rts
