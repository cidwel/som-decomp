; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-reflection.md.
.setcpu "65816"
.smart
.a8
.i16

spell_hit_or_reflection_internal_jump = $383C

.segment "CODE"
.org $0054
spell_hit_or_reflection_public_jump:
    jmp spell_hit_or_reflection_internal_jump
