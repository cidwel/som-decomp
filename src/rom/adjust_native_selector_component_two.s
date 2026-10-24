; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c02bf7 = $2BF7

.segment "CODE"
.org $2BEF
adjust_native_selector_component_two:
    .i16
    ldy #$0002
    bra routine_c02bf7
