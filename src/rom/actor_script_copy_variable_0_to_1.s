; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_script_variable_0 = $015B
write_actor_script_variable_1 = $01AE



.segment "CODE"
.org $062A
actor_script_copy_variable_0_to_1:
    jsr read_actor_script_variable_0
    jsr write_actor_script_variable_1
    jmp advance_actor_script_1_bytes
