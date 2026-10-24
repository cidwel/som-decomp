; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_cast_level_and_check_mp = $D04D9E

.segment "CODE"
.org $3862
cast_spell_native_long_jump:
    jml f:prepare_cast_level_and_check_mp
