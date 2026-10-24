; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6BA5
divide_native_status_field_and_return_hardware_quotient:
    sty a:$4204
    sta a:$4206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    ldy a:$4214
    rts
