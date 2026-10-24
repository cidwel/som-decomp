; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D

.segment "CODE"
.org $6A4F
append_selected_native_party_status_twelve_byte_name:
    .a8
    lda #$04
    jsr append_native_saved_slot_format_pair
    .a8
    lda #$00
    xba
    lda f:$0019FE
    asl
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tay
    .a8
    lda #$0C
append_selected_native_party_status_twelve_byte_name_c76a68:
    xba
    lda a:$CC00,Y
    beq append_selected_native_party_status_twelve_byte_name_c76a77
    sta a:$9C00,X
    inx
    iny
    xba
    dec
    bne append_selected_native_party_status_twelve_byte_name_c76a68
append_selected_native_party_status_twelve_byte_name_c76a77:
    jsr append_native_saved_slot_text_line_token
    rts
