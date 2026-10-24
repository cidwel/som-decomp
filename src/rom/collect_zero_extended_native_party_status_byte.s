; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $67BF
collect_zero_extended_native_party_status_byte:
    lda a:$E180,Y
    sta a:$A1E0,X
    inx
    stz a:$A1E0,X
    inx
    iny
    rts
