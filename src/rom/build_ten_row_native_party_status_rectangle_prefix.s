; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6B2B
build_ten_row_native_party_status_rectangle_prefix:
    sty a:$A173
    .i16
    ldy #$000A
