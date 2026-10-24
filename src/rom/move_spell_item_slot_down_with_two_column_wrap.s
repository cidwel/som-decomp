; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_saved_slot_rectangle_highlight = $C757D5
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC
routine_c02e3c = $2E3C

.segment "CODE"
.org $2DE2
move_spell_item_slot_down_with_two_column_wrap:
    lda a:$A20A
    .a8
    bit #$40
    beq move_spell_item_slot_down_with_two_column_wrap_c02e13
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq routine_c02e3c
    jsl f:clear_native_saved_slot_rectangle_highlight
    lda a:$A211
    .a8
    cmp #$06
    beq move_spell_item_slot_down_with_two_column_wrap_c02e06
    .a8
    cmp #$07
    beq move_spell_item_slot_down_with_two_column_wrap_c02e0a
    inc
    inc
    bra move_spell_item_slot_down_with_two_column_wrap_c02e0c
move_spell_item_slot_down_with_two_column_wrap_c02e06:
    .a8
    lda #$01
    bra move_spell_item_slot_down_with_two_column_wrap_c02e0c
move_spell_item_slot_down_with_two_column_wrap_c02e0a:
    .a8
    lda #$00
move_spell_item_slot_down_with_two_column_wrap_c02e0c:
    sta a:$A211
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
move_spell_item_slot_down_with_two_column_wrap_c02e13:
    rts
