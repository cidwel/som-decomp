; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_external_actor_command_with_saved_context = $CB12

.segment "CODE"
.org $8003
actor_command_public_jump:
    jmp dispatch_external_actor_command_with_saved_context
