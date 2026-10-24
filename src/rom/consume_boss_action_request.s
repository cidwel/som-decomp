; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte35_request = $051C

.segment "CODE"
.org $36B8
consume_boss_action_request:
    jsr consume_boss_byte35_request
    rts
