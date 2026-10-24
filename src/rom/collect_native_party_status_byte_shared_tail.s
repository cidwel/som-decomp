; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $67CF
collect_native_party_status_byte_shared_tail:
    lda a:$E180,Y
    sta a:$A1E0,X
    inx
    iny
    rts
