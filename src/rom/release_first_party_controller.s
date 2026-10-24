; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

release_actor_controller_and_initialize_program = $BDA4

.segment "CODE"
.org $BD91
release_first_party_controller:
    rep #$10
    .i16
    ldx #$0000
    bra release_actor_controller_and_initialize_program
