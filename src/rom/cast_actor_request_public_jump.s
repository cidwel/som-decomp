; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-api.md.
.setcpu "65816"
.smart
.a8
.i16

cast_actor_request_preserving_cpu_context = $806F

.segment "CODE"
.org $800F
cast_actor_request_public_jump:
    jmp cast_actor_request_preserving_cpu_context
