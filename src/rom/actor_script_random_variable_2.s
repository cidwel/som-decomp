; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_script_random_bounded_nibble = $16F4
advance_actor_script_2_bytes = $012B
write_actor_script_variable_2 = $01C7



.segment "CODE"
.org $172F
actor_script_random_variable_2:
    jsr actor_script_random_bounded_nibble
    jsr write_actor_script_variable_2
    jmp advance_actor_script_2_bytes
