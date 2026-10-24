; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D
append_native_saved_slot_text_space_token = $5389
derive_selected_native_party_status_record_offset = $6A95
format_and_append_native_saved_slot_decimal_pair = $5AFC
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $69F8
append_native_party_status_magic_points_when_not_boy:
    lda f:$0019FE
    beq append_native_party_status_magic_points_when_not_boy_c76a2b
    .a8
    lda #$04
    jsr append_native_saved_slot_format_pair
    .i16
    ldy #$7B33
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsr derive_selected_native_party_status_record_offset
    phy
    .a8
    lda #$00
    xba
    lda a:$E186,Y
    tay
    jsr format_and_append_native_saved_slot_decimal_pair
    .a8
    lda #$C1
    sta a:$9C00,X
    inx
    jsr append_native_saved_slot_text_space_token
    ply
    .a8
    lda #$00
    xba
    lda a:$E187,Y
    tay
    jsr format_and_append_native_saved_slot_decimal_pair
append_native_party_status_magic_points_when_not_boy_c76a2b:
    jsr append_native_saved_slot_text_line_token
    rts
