; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-setup.md.
.setcpu "65816"
.smart
.a8
.i16

mark_controller_and_request_numeric_boss_death_event = $0C11
wait_for_boss_death_controller_event_gates = $0B50

.segment "CODE"
.org $7C22
complete_native58_death_gate_and_numeric_event:
    ldx $87
    stz a:$003E,X
    jsr wait_for_boss_death_controller_event_gates
    bcc complete_native58_death_gate_and_numeric_event_c27c37
    ldx $87
    lda a:$0072,X
    beq complete_native58_death_gate_and_numeric_event_c27c36
    jsr mark_controller_and_request_numeric_boss_death_event
complete_native58_death_gate_and_numeric_event_c27c36:
    sec
complete_native58_death_gate_and_numeric_event_c27c37:
    rts
