; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_script_variable_2 = $0179
write_actor_script_variable_2 = $01C7



.segment "CODE"
.org $0616
actor_script_decrement_variable_2:
    jsr read_actor_script_variable_2
    dec
    jsr write_actor_script_variable_2
    jmp advance_actor_script_1_bytes
