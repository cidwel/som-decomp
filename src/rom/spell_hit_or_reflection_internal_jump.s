; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-reflection.md.
.setcpu "65816"
.smart
.a8
.i16

spell_hit_or_reflection_native_long_jump = $3866

.segment "CODE"
.org $383C
spell_hit_or_reflection_internal_jump:
    jmp spell_hit_or_reflection_native_long_jump
