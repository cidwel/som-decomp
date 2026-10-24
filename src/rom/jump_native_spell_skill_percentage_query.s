; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-spell-skill-percentage.md.
.setcpu "65816"
.smart
.a8
.i16

compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic = $419C

.segment "CODE"
.org $384B
jump_native_spell_skill_percentage_query:
    jmp compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic
