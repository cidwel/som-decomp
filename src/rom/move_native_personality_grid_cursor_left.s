; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-movement.md.
.setcpu "65816"
.smart
.a8
.i16

compare_selected_pad_buttons_against_native_previous_buttons = $325A
dispatch_native_name_page_party_icon_variant = $C75217
request_native_menu_change_or_confirm_preset_preserving_low_accumulator = $1BAA

.segment "CODE"
.org $2FC8
move_native_personality_grid_cursor_left:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq move_native_personality_grid_cursor_left_c02fe9
    lda a:$A212
    .a8
    bit #$20
    bne move_native_personality_grid_cursor_left_c02fe9
    lda a:$A136
    dec
    .a8
    and #$0F
    sta a:$A136
    jsl f:dispatch_native_name_page_party_icon_variant
    .a8
    lda #$04
    tsb a:$A20A
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
move_native_personality_grid_cursor_left_c02fe9:
    rts
