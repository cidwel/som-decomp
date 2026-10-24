; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
refresh_native_shop_frame_graphics_icons_and_request_sound = $C76256

.segment "CODE"
.org $2C76
decrease_selected_native_settings_icon_variant:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $42,X
    .a8
    bit #$C0
    bne decrease_selected_native_settings_icon_variant_c02c99
    lda $43,X
    .a8
    bit #$40
    bne decrease_selected_native_settings_icon_variant_c02c99
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    lda a:$A24F,X
    dec
    .a8
    and #$07
    sta a:$A24F,X
    jsl f:refresh_native_shop_frame_graphics_icons_and_request_sound
decrease_selected_native_settings_icon_variant_c02c99:
    rts
