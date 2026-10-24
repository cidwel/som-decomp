; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

mirror_random_byte_jump = $3800



.segment "CODE"
.org $0018
public_random_byte_jump:
    jmp mirror_random_byte_jump
