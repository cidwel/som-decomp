; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

update_actor_combat_and_return_action_request = $3A79

.segment "CODE"
.org $3815
actor_combat_tick_internal_jump:
    jmp update_actor_combat_and_return_action_request
