; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_relative_operand = $0245

ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $0285
jump_actor_script_after_1_bytes:
    ldx a:ACTOR_PROGRAM_PC,Y
    inx
    jsr jump_actor_script_relative_operand
    rts
