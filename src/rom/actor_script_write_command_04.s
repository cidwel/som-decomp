; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_and_yield = $0111

ACTOR_COMMAND = $0140

.segment "CODE"
.org $1DF8
actor_script_write_command_04:
    .a8
    lda #$04
    sta a:ACTOR_COMMAND,Y
    .a8
    lda #$01
    jmp advance_actor_script_and_yield
