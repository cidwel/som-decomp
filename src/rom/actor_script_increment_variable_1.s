; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_script_variable_1 = $0169
write_actor_script_variable_1 = $01AE



.segment "CODE"
.org $05E4
actor_script_increment_variable_1:
    jsr read_actor_script_variable_1
    inc
    jsr write_actor_script_variable_1
    jmp advance_actor_script_1_bytes
