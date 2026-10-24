; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
routine_c031cc = $31CC
routine_c031e1 = $31E1

.segment "CODE"
.org $31B6
delete_native_name_glyph_on_new_left_button:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda a:$A204,X
    .a8
    and #$20
    bne routine_c031e1
    bra routine_c031cc
