; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $68E7
append_first_four_native_party_status_restriction_labels:
    rep #$20
    sta a:$A167
    .a16
    lda #$0010
    .i16
    ldy #$0000
    sty a:$A169
append_first_four_native_party_status_restriction_labels_c768f5:
    pha
    asl a:$A167
    bcc append_first_four_native_party_status_restriction_labels_c76911
    phy
    phx
    tya
    asl
    tax
    lda f:$C033D0,X
    tay
    plx
    sep #$20
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsr append_native_saved_slot_text_line_token
    rep #$20
    ply
append_first_four_native_party_status_restriction_labels_c76911:
    lda a:$A169
    .a16
    cmp #$0004
    beq append_first_four_native_party_status_restriction_labels_c7692f
    pla
    iny
    dec
    bne append_first_four_native_party_status_restriction_labels_c768f5
    ldy a:$A169
append_first_four_native_party_status_restriction_labels_c76921:
    sep #$20
    jsr append_native_saved_slot_text_line_token
    rep #$20
    iny
    .i16
    cpy #$0004
    bne append_first_four_native_party_status_restriction_labels_c76921
    pha
append_first_four_native_party_status_restriction_labels_c7692f:
    pla
    sep #$20
    rts
