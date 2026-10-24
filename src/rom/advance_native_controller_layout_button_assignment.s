; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c76e91 = $6E91

.segment "CODE"
.org $6E8B
advance_native_controller_layout_button_assignment:
    .a8
    lda #$01
    bra routine_c76e91
