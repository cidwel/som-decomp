; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_relative_operand = $0245

ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $02A0
jump_actor_script_after_4_bytes:
    ldx a:ACTOR_PROGRAM_PC,Y
    inx
    inx
    inx
    inx
    jsr jump_actor_script_relative_operand
    rts
