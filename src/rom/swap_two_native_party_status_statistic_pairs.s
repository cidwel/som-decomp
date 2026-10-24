; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $67A6
swap_two_native_party_status_statistic_pairs:
    ldx a:$A1EA
    ldy a:$A1EC
    stx a:$A1EC
    sty a:$A1EA
    ldx a:$A1EE
    ldy a:$A1F0
    stx a:$A1F0
    sty a:$A1EE
    rts
