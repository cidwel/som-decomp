; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6AA4
read_selected_native_party_status_excluding_low_two_bits:
    phx
    lda f:$0019FE
    xba
    .a16
    and #$FF00
    asl
    tax
    lda a:$E190,X
    plx
    .a16
    and #$FFFC
    rts
