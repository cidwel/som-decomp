; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

derive_selected_native_party_status_record_offset = $6A95

.segment "CODE"
.org $6A7B
subtract_native_party_status_statistic_vectors_with_borrow:
    jsr derive_selected_native_party_status_record_offset
    .a8
    lda #$03
    .i16
    ldx #$0000
    sec
subtract_native_party_status_statistic_vectors_with_borrow_c76a84:
    xba
    lda a:$E17D,Y
    sbc a:$E18D,Y
    sta a:$A136,X
    iny
    inx
    xba
    dec
    bne subtract_native_party_status_statistic_vectors_with_borrow_c76a84
    rts
