; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

mark_controller_and_request_numeric_boss_death_event = $0C11
wait_for_boss_death_controller_event_gates = $0B50

.segment "CODE"
.org $4AEA
finish_native54_death_and_request_literal_event:
    ldx $87
    jsr wait_for_boss_death_controller_event_gates
    bcc finish_native54_death_and_request_literal_event_c24afa
    ldx $87
    lda a:$0072,X
    jsr mark_controller_and_request_numeric_boss_death_event
    sec
finish_native54_death_and_request_literal_event_c24afa:
    rts
