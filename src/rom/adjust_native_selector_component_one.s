; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

adjust_native_three_component_selector_from_current_left_right = $2BBA

.segment "CODE"
.org $2BF4
adjust_native_selector_component_one:
    .i16
    ldy #$0001
    jsr adjust_native_three_component_selector_from_current_left_right
    rts
