; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_and_yield = $0111

ACTOR_COMMAND = $0140
ACTOR_COMMAND_DIRECTION = $0141
ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $1E02
actor_script_write_pose_command:
    .a8
    lda #$40
    sta a:ACTOR_COMMAND,Y
    ldx a:ACTOR_PROGRAM_PC,Y
    lda f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    sta a:ACTOR_COMMAND_DIRECTION,Y
    .a8
    lda #$02
    jmp advance_actor_script_and_yield
