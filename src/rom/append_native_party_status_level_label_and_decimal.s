; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D
derive_selected_native_party_status_record_offset = $6A95
format_and_append_native_saved_slot_decimal_pair = $5AFC
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $6A2F
append_native_party_status_level_label_and_decimal:
    .a8
    lda #$04
    jsr append_native_saved_slot_format_pair
    .i16
    ldy #$7B24
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsr derive_selected_native_party_status_record_offset
    .a8
    lda #$00
    xba
    lda a:$E181,Y
    inc
    sta a:$A16E
    tay
    jsr format_and_append_native_saved_slot_decimal_pair
    jsr append_native_saved_slot_text_line_token
    rts
