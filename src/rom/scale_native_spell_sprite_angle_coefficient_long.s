; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trigonometry.md.
.setcpu "65816"
.smart
.a8
.i16

scale_native_spell_sprite_angle_coefficient = $493A

.segment "CODE"
.org $2EC5
scale_native_spell_sprite_angle_coefficient_long:
    jsr scale_native_spell_sprite_angle_coefficient
    rtl
