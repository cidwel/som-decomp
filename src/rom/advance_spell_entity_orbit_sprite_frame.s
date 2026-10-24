; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

project_spell_entity_orbit_sprite_group = $F34F

.segment "CODE"
.org $F47C
advance_spell_entity_orbit_sprite_frame:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    stx $01
    lda a:$001A,X
    jsr project_spell_entity_orbit_sprite_group
    ldx $01
    ldy a:$001A,X
    clc
    rep #$20
    txa
    .a16
    adc #$000C
    tax
    sep #$20
    tya
    jsr project_spell_entity_orbit_sprite_group
    ldx $01
    inc a:$001A,X
    .a8
    lda #$06
    sta a:$0018,X
    pla
    pla
    plp
    pld
    rts
