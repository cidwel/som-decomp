; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D
append_seven_native_decimal_quantity_glyphs_with_leading_spaces = $54B0
convert_24_bit_dialogue_quantity_to_seven_digit_fields = $C754DB
select_bank_C7_and_copy_native_terminated_tokens = $6ABE
subtract_native_party_status_statistic_vectors_with_borrow = $6A7B

.segment "CODE"
.org $695B
append_native_party_status_remaining_experience_unless_level99:
    lda a:$A16E
    .a8
    cmp #$63
    beq append_native_party_status_remaining_experience_unless_level99_c76974
    .i16
    ldy #$7B41
    jsr select_bank_C7_and_copy_native_terminated_tokens
    phx
    jsr subtract_native_party_status_statistic_vectors_with_borrow
    jsl f:convert_24_bit_dialogue_quantity_to_seven_digit_fields
    plx
    jsr append_seven_native_decimal_quantity_glyphs_with_leading_spaces
append_native_party_status_remaining_experience_unless_level99_c76974:
    jsr append_native_saved_slot_text_line_token
    rts
