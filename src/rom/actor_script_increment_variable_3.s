; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_script_variable_3 = $0187
write_actor_script_variable_3 = $01DE



.segment "CODE"
.org $05F8
actor_script_increment_variable_3:
    jsr read_actor_script_variable_3
    inc
    jsr write_actor_script_variable_3
    jmp advance_actor_script_1_bytes
