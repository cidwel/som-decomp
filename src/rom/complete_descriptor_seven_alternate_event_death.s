; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

advance_alternate_boss_death_callback_effects_and_event_gates = $0BCE

.segment "CODE"
.org $72FF
complete_descriptor_seven_alternate_event_death:
    jsr advance_alternate_boss_death_callback_effects_and_event_gates
    rts
