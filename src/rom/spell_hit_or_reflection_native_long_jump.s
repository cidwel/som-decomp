; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-reflection.md.
.setcpu "65816"
.smart
.a8
.i16

resolve_complete_spell_hit_or_wall_reflection = $D04C82

.segment "CODE"
.org $3866
spell_hit_or_reflection_native_long_jump:
    jml f:resolve_complete_spell_hit_or_wall_reflection
