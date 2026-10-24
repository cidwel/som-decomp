; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trigonometry.md.
.setcpu "65816"
.smart
.a8
.i16

scale_native_spell_sprite_quarter_turn_coefficient = $4993

.segment "CODE"
.org $2EC1
scale_native_spell_sprite_quarter_turn_coefficient_long:
    jsr scale_native_spell_sprite_quarter_turn_coefficient
    rtl
