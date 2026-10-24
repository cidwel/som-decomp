; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-gate-clear.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AEBD
restore_native_pause_gate_and_return_when_pause_is_clear:
    plx
    pla
    pla
    pla
    plp
    pld
    rts
