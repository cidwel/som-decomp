; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_2_bytes = $012B
write_actor_script_variable_3 = $01DE

ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $16E5
actor_script_set_variable_3:
    ldx a:ACTOR_PROGRAM_PC,Y
    lda f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    .a8
    and #$0F
    jsr write_actor_script_variable_3
    jmp advance_actor_script_2_bytes
