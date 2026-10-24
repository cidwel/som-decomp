; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
refresh_native_shop_frame_graphics_icons_and_request_sound = $C76256

.segment "CODE"
.org $2C59
retreat_native_settings_palette_cursor:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $42,X
    .a8
    bit #$C0
    bne retreat_native_settings_palette_cursor_c02c75
    lda $43,X
    .a8
    bit #$40
    bne retreat_native_settings_palette_cursor_c02c75
    lda a:$A24E
    dec
    .a8
    and #$07
    sta a:$A24E
    jsl f:refresh_native_shop_frame_graphics_icons_and_request_sound
retreat_native_settings_palette_cursor_c02c75:
    rts
