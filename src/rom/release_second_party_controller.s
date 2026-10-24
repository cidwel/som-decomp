; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

release_actor_controller_and_initialize_program = $BDA4

.segment "CODE"
.org $BD98
release_second_party_controller:
    rep #$10
    .i16
    ldx #$0200
    bra release_actor_controller_and_initialize_program
