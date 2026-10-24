; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
publish_four_native_name_entry_cursor_corners = $C7503D
request_native_menu_change_or_confirm_preset_preserving_low_accumulator = $1BAA
reset_native_name_repeat_timer_on_new_direction = $324A

.segment "CODE"
.org $3221
move_native_name_cursor_right_and_publish_corners:
    jsr reset_native_name_repeat_timer_on_new_direction
    lda a:$A159
    clc
    .a8
    adc #$08
    .a8
    cmp #$E0
    bcc move_native_name_cursor_right_and_publish_corners_c03230
    .a8
    lda #$13
move_native_name_cursor_right_and_publish_corners_c03230:
    sta a:$A159
    jsl f:publish_four_native_name_entry_cursor_corners
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    .a8
    and #$0C
    bne move_native_name_cursor_right_and_publish_corners_c03243
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
move_native_name_cursor_right_and_publish_corners_c03243:
    rts
