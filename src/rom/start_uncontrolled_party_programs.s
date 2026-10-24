; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

start_uncontrolled_actor_program = $DE11

.segment "CODE"
.org $DE00
start_uncontrolled_party_programs:
    rep #$10
    .i16
    ldx #$0000
    jsr start_uncontrolled_actor_program
    .i16
    ldx #$0200
    jsr start_uncontrolled_actor_program
    .i16
    ldx #$0400
