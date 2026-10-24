; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_2_bytes = $028D
read_actor_script_variable_3 = $0187
skip_actor_script_after_2_bytes = $021B

ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $1780
actor_script_if_variable_3_not_equal:
    jsr read_actor_script_variable_3
    ldx a:ACTOR_PROGRAM_PC,Y
    cmp f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    bne actor_script_if_variable_3_not_equal_c11791
    jsr skip_actor_script_after_2_bytes
    bra actor_script_if_variable_3_not_equal_c11794
actor_script_if_variable_3_not_equal_c11791:
    jsr jump_actor_script_after_2_bytes
actor_script_if_variable_3_not_equal_c11794:
    rts
