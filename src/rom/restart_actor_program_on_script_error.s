; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

restart_actor_program = $263C

ACTOR_ID = $0180
ACTOR_COMMAND = $0140

.segment "CODE"
.org $0100
restart_actor_program_on_script_error:
    phy
    tyx
    lda a:ACTOR_ID,Y
    jsr restart_actor_program
    ply
    .a8
    lda #$00
    sta a:ACTOR_COMMAND,Y
    .a8
    lda #$00
    rts
