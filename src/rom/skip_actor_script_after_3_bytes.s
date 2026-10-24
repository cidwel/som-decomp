; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

skip_actor_script_relative_operand = $01F7

ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $0224
skip_actor_script_after_3_bytes:
    ldx a:ACTOR_PROGRAM_PC,Y
    inx
    inx
    inx
    jsr skip_actor_script_relative_operand
    rts
