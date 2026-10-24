; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_native_long_jump = $3862

.segment "CODE"
.org $3803
cast_spell_public_jump_mirror:
    jmp cast_spell_native_long_jump
