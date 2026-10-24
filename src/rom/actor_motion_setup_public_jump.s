; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

set_actor_motion_and_clear_previous_effects = $8052

.segment "CODE"
.org $800C
actor_motion_setup_public_jump:
    jmp set_actor_motion_and_clear_previous_effects
