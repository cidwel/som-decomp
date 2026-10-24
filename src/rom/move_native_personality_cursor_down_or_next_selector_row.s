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
.org $2F83
move_native_personality_cursor_down_or_next_selector_row:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq move_native_personality_cursor_down_or_next_selector_row_c02fc7
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
    lda a:$A212
    .a8
    bit #$20
    bne move_native_personality_cursor_down_or_next_selector_row_c02fb1
    lda a:$A136
    .a8
    cmp #$0F
    beq move_native_personality_cursor_down_or_next_selector_row_c02fa0
    clc
    .a8
    adc #$04
    .a8
    cmp #$10
    bcc move_native_personality_cursor_down_or_next_selector_row_c02fa1
move_native_personality_cursor_down_or_next_selector_row_c02fa0:
    inc
move_native_personality_cursor_down_or_next_selector_row_c02fa1:
    .a8
    and #$0F
    sta a:$A136
    jsl f:dispatch_native_name_page_party_icon_variant
    .a8
    lda #$04
    tsb a:$A20A
    bra move_native_personality_cursor_down_or_next_selector_row_c02fc7
move_native_personality_cursor_down_or_next_selector_row_c02fb1:
    lda a:$A211
    inc
    cmp a:$A200
    bne move_native_personality_cursor_down_or_next_selector_row_c02fbc
    .a8
    lda #$00
move_native_personality_cursor_down_or_next_selector_row_c02fbc:
    sta a:$A211
    jsl f:derive_native_personality_selector_cursor_coordinates
    jsl f:publish_four_native_name_entry_cursor_corners
move_native_personality_cursor_down_or_next_selector_row_c02fc7:
    rts
