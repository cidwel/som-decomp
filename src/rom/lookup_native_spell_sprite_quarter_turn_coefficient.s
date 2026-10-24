; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trigonometry.md.
.setcpu "65816"
.smart
.a8
.i16

lookup_native_spell_sprite_angle_coefficient = $48D9

.segment "CODE"
.org $4923
lookup_native_spell_sprite_quarter_turn_coefficient:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    clc
    .a8
    adc #$40
    jsr lookup_native_spell_sprite_angle_coefficient
    plb
    plp
    pld
    rts
