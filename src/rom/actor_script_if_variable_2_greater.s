; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_2_bytes = $028D
read_actor_script_variable_2 = $0179
skip_actor_script_after_2_bytes = $021B

ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $1817
actor_script_if_variable_2_greater:
    jsr read_actor_script_variable_2
    ldx a:ACTOR_PROGRAM_PC,Y
    cmp f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    beq actor_script_if_variable_2_greater_c11825
    bcs actor_script_if_variable_2_greater_c1182a
actor_script_if_variable_2_greater_c11825:
    jsr skip_actor_script_after_2_bytes
    bra actor_script_if_variable_2_greater_c1182d
actor_script_if_variable_2_greater_c1182a:
    jsr jump_actor_script_after_2_bytes
actor_script_if_variable_2_greater_c1182d:
    rts
