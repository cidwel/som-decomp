; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6A95
derive_selected_native_party_status_record_offset:
    rep #$20
    lda f:$0019FE
    .a16
    and #$00FF
    xba
    asl
    tay
    sep #$20
    rts
