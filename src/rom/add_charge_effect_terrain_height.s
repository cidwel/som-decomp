; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

read_charge_effect_terrain_height_preserving_actor = $C1D1

.segment "CODE"
.org $C171
add_charge_effect_terrain_height:
    jsr read_charge_effect_terrain_height_preserving_actor
    sep #$20
    clc
    adc a:$D006,Y
    sta a:$D006,Y
    .a8
    lda #$00
    sta a:$D007,Y
    rts
