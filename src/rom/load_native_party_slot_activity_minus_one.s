; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-page-callback.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6BB7
load_native_party_slot_activity_minus_one:
    rep #$20
    .a16
    and #$00FF
    xba
    asl
    tax
    sep #$20
    lda f:$7EE000,X
    dec
    rtl
