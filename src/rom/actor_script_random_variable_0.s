; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_script_random_bounded_nibble = $16F4
advance_actor_script_2_bytes = $012B
write_actor_script_variable_0 = $0197



.segment "CODE"
.org $171D
actor_script_random_variable_0:
    jsr actor_script_random_bounded_nibble
    jsr write_actor_script_variable_0
    jmp advance_actor_script_2_bytes
