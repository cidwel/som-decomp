; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5
routine_c75124 = $C75124
select_native_name_entry_tile_at_cursor = $C750E0

.segment "CODE"
.org $318E
append_selected_native_name_glyph:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda a:$A204,X
    .a8
    and #$80
    bne append_selected_native_name_glyph_c031b5
    lda a:$A1CC
    .a8
    cmp #$06
    beq append_selected_native_name_glyph_c031b5
    jsl f:select_native_name_entry_tile_at_cursor
    bcs append_selected_native_name_glyph_c031b5
    jsl f:routine_c75124
    inc a:$A157
    inc a:$A157
    inc a:$A1CC
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
append_selected_native_name_glyph_c031b5:
    rts
