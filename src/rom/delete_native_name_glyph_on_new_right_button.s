; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

clear_and_publish_native_name_entry_tile_pair = $C75119
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
routine_c01baf = $1BAF
routine_c031b5 = $31B5

.segment "CODE"
.org $31C2
delete_native_name_glyph_on_new_right_button:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda a:$A204,X
    .a8
    and #$40
    bne delete_native_name_glyph_on_new_right_button_c031e1
    lda a:$A1CC
    beq routine_c031b5
    dec a:$A157
    dec a:$A157
    jsl f:clear_and_publish_native_name_entry_tile_pair
    dec a:$A1CC
    jsr routine_c01baf
delete_native_name_glyph_on_new_right_button_c031e1:
    rts
