; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D
append_seven_native_decimal_quantity_glyphs_with_leading_spaces = $54B0
convert_24_bit_dialogue_quantity_to_seven_digit_fields = $C754DB
derive_selected_native_party_status_record_offset = $6A95
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $6933
append_native_party_status_experience_quantity:
    .i16
    ldy #$7B39
    jsr select_bank_C7_and_copy_native_terminated_tokens
    phx
    jsr derive_selected_native_party_status_record_offset
    .i16
    ldx #$0000
    .a8
    lda #$04
append_native_party_status_experience_quantity_c76942:
    xba
    lda a:$E18D,Y
    sta a:$A136,X
    inx
    iny
    xba
    dec
    bne append_native_party_status_experience_quantity_c76942
    jsl f:convert_24_bit_dialogue_quantity_to_seven_digit_fields
    plx
    jsr append_seven_native_decimal_quantity_glyphs_with_leading_spaces
    jsr append_native_saved_slot_text_line_token
    rts
