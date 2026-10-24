; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_script_variable_0 = $015B
write_actor_script_variable_0 = $0197



.segment "CODE"
.org $05DA
actor_script_increment_variable_0:
    jsr read_actor_script_variable_0
    inc
    jsr write_actor_script_variable_0
    jmp advance_actor_script_1_bytes
