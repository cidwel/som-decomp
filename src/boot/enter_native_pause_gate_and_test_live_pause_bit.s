; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-gate-clear.md.
.setcpu "65816"
.smart
.a8
.i16

restore_native_pause_gate_and_return_when_pause_is_clear = $AEBD
routine_7ea814 = $A814

.segment "CODE"
.org $AE37
enter_native_pause_gate_and_test_live_pause_bit:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    phx
    jsr routine_7ea814
    .a8
    and #$40
    beq restore_native_pause_gate_and_return_when_pause_is_clear
