; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_2_bytes = $028D
read_actor_script_variable_0 = $015B
skip_actor_script_after_2_bytes = $021B

ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $1741
actor_script_if_variable_0_not_equal:
    jsr read_actor_script_variable_0
    ldx a:ACTOR_PROGRAM_PC,Y
    cmp f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    bne actor_script_if_variable_0_not_equal_c11752
    jsr skip_actor_script_after_2_bytes
    bra actor_script_if_variable_0_not_equal_c11755
actor_script_if_variable_0_not_equal_c11752:
    jsr jump_actor_script_after_2_bytes
actor_script_if_variable_0_not_equal_c11755:
    rts
