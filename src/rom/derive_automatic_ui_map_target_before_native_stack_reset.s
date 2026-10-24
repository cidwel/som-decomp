; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-motion-chain.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c081ed = $81ED

.segment "CODE"
.org $824E
derive_automatic_ui_map_target_before_native_stack_reset:
    jsr routine_c081ed
    sep #$20
    stz $E8
