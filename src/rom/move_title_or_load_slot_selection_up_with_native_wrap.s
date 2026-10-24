; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_saved_slot_rectangle_highlight = $C757D5
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC

.segment "CODE"
.org $2CBE
move_title_or_load_slot_selection_up_with_native_wrap:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq move_title_or_load_slot_selection_up_with_native_wrap_c02cf2
    .a8
    and #$F0
    bne move_title_or_load_slot_selection_up_with_native_wrap_c02cf2
    lda f:$7EA202
    .a8
    cmp #$00
    bne move_title_or_load_slot_selection_up_with_native_wrap_c02cdb
    lda f:$7EA215
    inc
    beq move_title_or_load_slot_selection_up_with_native_wrap_c02cf2
move_title_or_load_slot_selection_up_with_native_wrap_c02cdb:
    jsl f:clear_native_saved_slot_rectangle_highlight
    lda a:$A211
    dec
    .a8
    cmp #$FF
    bne move_title_or_load_slot_selection_up_with_native_wrap_c02ceb
    lda a:$A200
    dec
move_title_or_load_slot_selection_up_with_native_wrap_c02ceb:
    sta a:$A211
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
move_title_or_load_slot_selection_up_with_native_wrap_c02cf2:
    rts
