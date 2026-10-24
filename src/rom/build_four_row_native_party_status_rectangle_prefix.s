; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16

build_native_party_status_rectangle_shared_rows = $6B31

.segment "CODE"
.org $6B23
build_four_row_native_party_status_rectangle_prefix:
    sty a:$A173
    .i16
    ldy #$0004
    bra build_native_party_status_rectangle_shared_rows
