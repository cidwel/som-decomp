; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D
append_three_native_saved_slot_decimal_digits = $5A1E
derive_selected_native_party_status_record_offset = $6A95
format_five_native_saved_slot_decimal_digits_via_hardware_division = $5D17
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $69C2
append_native_party_status_current_and_maximum_hit_points:
    .a8
    lda #$04
    jsr append_native_saved_slot_format_pair
    .i16
    ldy #$7B2D
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsr derive_selected_native_party_status_record_offset
    phy
    rep #$20
    lda a:$E182,Y
    tay
    sep #$20
    jsr format_five_native_saved_slot_decimal_digits_via_hardware_division
    jsr append_three_native_saved_slot_decimal_digits
    .a8
    lda #$C1
    sta a:$9C00,X
    inx
    ply
    rep #$20
    lda a:$E184,Y
    tay
    sep #$20
    jsr format_five_native_saved_slot_decimal_digits_via_hardware_division
    jsr append_three_native_saved_slot_decimal_digits
    jsr append_native_saved_slot_text_line_token
    rts
