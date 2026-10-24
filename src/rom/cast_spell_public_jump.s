; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump_mirror = $3803

.segment "CODE"
.org $001B
cast_spell_public_jump:
    jmp cast_spell_public_jump_mirror
