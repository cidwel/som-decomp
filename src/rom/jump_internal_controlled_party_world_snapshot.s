; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-world-snapshot.md.
.setcpu "65816"
.smart
.a8
.i16

record_controller_selected_actor_position_guard = $3E35

.segment "CODE"
.org $385A
jump_internal_controlled_party_world_snapshot:
    jmp record_controller_selected_actor_position_guard
