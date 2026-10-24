; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-event.md.
.setcpu "65816"
.smart
.a8
.i16

mark_first_nonzero_party_controller_slot_negative = $0C1B
routine_018000 = $18000

.segment "CODE"
.org $0C11
mark_controller_and_request_numeric_boss_death_event:
    pha
    jsr mark_first_nonzero_party_controller_slot_negative
    pla
    jsl f:routine_018000
    rts
