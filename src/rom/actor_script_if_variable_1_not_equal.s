; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_2_bytes = $028D
read_actor_script_variable_1 = $0169
skip_actor_script_after_2_bytes = $021B

ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $1756
actor_script_if_variable_1_not_equal:
    jsr read_actor_script_variable_1
    ldx a:ACTOR_PROGRAM_PC,Y
    cmp f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    bne actor_script_if_variable_1_not_equal_c11767
    jsr skip_actor_script_after_2_bytes
    bra actor_script_if_variable_1_not_equal_c1176a
actor_script_if_variable_1_not_equal_c11767:
    jsr jump_actor_script_after_2_bytes
actor_script_if_variable_1_not_equal_c1176a:
    rts
