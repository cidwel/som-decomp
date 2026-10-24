; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94

.segment "CODE"
.org $F34F
project_spell_entity_orbit_sprite_group:
    phd
    php
    rep #$30
    phb
    pha
    tsc
    tcd
    pla
    phx
    .a16
    and #$00FF
    .a16
    cmp #$0005
    bcs project_spell_entity_orbit_sprite_group_d3f390
    phx
    txy
    asl
    asl
    asl
    clc
    .a16
    adc #$FC42
    sec
    .a16
    sbc #$F800
    tax
    lda a:$0008,Y
    pha
    lda a:$000A,Y
    pha
    sep #$20
    .a8
    lda #$04
    sta $01
project_spell_entity_orbit_sprite_group_d3f37d:
    sty $02
    jsl f:project_packed_spell_entity_sprite_record_long
    ldy $02
    iny
    iny
    dec $01
    bne project_spell_entity_orbit_sprite_group_d3f37d
    ply
    ply
    plx
    rep #$20
project_spell_entity_orbit_sprite_group_d3f390:
    sep #$20
    pla
    pla
    pla
    plp
    pld
    rts
