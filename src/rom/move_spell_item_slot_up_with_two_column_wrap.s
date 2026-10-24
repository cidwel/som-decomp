; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_saved_slot_rectangle_highlight = $C757D5
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC

.segment "CODE"
.org $2DAD
move_spell_item_slot_up_with_two_column_wrap:
    lda a:$A20A
    .a8
    bit #$40
    beq move_spell_item_slot_up_with_two_column_wrap_c02de1
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq move_spell_item_slot_up_with_two_column_wrap_c02de1
    jsl f:clear_native_saved_slot_rectangle_highlight
    lda a:$A211
    beq move_spell_item_slot_up_with_two_column_wrap_c02dd6
    .a8
    cmp #$01
    beq move_spell_item_slot_up_with_two_column_wrap_c02dcf
    dec
    dec
    bra move_spell_item_slot_up_with_two_column_wrap_c02dda
move_spell_item_slot_up_with_two_column_wrap_c02dcf:
    lda a:$A200
    dec
    dec
    bra move_spell_item_slot_up_with_two_column_wrap_c02dda
move_spell_item_slot_up_with_two_column_wrap_c02dd6:
    lda a:$A200
    dec
move_spell_item_slot_up_with_two_column_wrap_c02dda:
    sta a:$A211
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
move_spell_item_slot_up_with_two_column_wrap_c02de1:
    rts
