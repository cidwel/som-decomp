; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
dispatch_native_spell_or_item_detail_publication = $C76401
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5

.segment "CODE"
.org $2D6F
confirm_native_spell_item_selection_or_open_detail:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $43,X
    cmp a:$A204,X
    beq confirm_native_spell_item_selection_or_open_detail_c02dac
    .a8
    lda #$08
    bit a:$A212
    bne confirm_native_spell_item_selection_or_open_detail_c02da5
    tsb a:$A212
    .a8
    lda #$40
    and a:$A20A
    bne confirm_native_spell_item_selection_or_open_detail_c02dac
    lda a:$A202
    pha
    .a8
    lda #$06
    sta a:$A202
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
    pla
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    sta a:$A202
    .a8
    lda #$40
    tsb a:$A20A
    bra confirm_native_spell_item_selection_or_open_detail_c02dac
confirm_native_spell_item_selection_or_open_detail_c02da5:
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    jsl f:dispatch_native_spell_or_item_detail_publication
confirm_native_spell_item_selection_or_open_detail_c02dac:
    rts
