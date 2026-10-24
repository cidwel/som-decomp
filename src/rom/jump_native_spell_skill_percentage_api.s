; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-spell-skill-percentage.md.
.setcpu "65816"
.smart
.a8
.i16

jump_native_spell_skill_percentage_query = $384B

.segment "CODE"
.org $0063
jump_native_spell_skill_percentage_api:
    jmp jump_native_spell_skill_percentage_query
