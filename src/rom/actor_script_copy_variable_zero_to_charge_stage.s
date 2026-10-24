; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121
read_actor_script_variable_0 = $015B

.segment "CODE"
.org $1657
actor_script_copy_variable_zero_to_charge_stage:
    jsr read_actor_script_variable_0
    sta a:$019B,Y
    jmp advance_actor_script_1_bytes
