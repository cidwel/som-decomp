; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_saved_slot_rectangle_highlight = $C757D5
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC

.segment "CODE"
.org $2E14
move_spell_item_slot_left_with_last_slot_wrap:
    lda a:$A20A
    .a8
    bit #$40
    beq move_spell_item_slot_left_with_last_slot_wrap_c02e3c
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq move_spell_item_slot_left_with_last_slot_wrap_c02e3c
    jsl f:clear_native_saved_slot_rectangle_highlight
    lda a:$A211
    dec
    .a8
    cmp #$FF
    bne move_spell_item_slot_left_with_last_slot_wrap_c02e35
    lda a:$A200
    dec
move_spell_item_slot_left_with_last_slot_wrap_c02e35:
    sta a:$A211
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
move_spell_item_slot_left_with_last_slot_wrap_c02e3c:
    rts
