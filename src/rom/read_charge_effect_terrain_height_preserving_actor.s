; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

read_charge_effect_terrain_height = $C1D7

.segment "CODE"
.org $C1D1
read_charge_effect_terrain_height_preserving_actor:
    phx
    jsr read_charge_effect_terrain_height
    plx
    rts
