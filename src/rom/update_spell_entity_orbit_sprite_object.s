; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

advance_spell_entity_orbit_sprite_frame = $F47C
advance_spell_entity_orbit_state = $F398

.segment "CODE"
.org $F4B3
update_spell_entity_orbit_sprite_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stx $03
    dec a:$00E8,X
    bne update_spell_entity_orbit_sprite_object_d3f4c8
    jsr advance_spell_entity_orbit_state
update_spell_entity_orbit_sprite_object_d3f4c8:
    .a16
    lda #$0008
    sta $01
    ldx $03
update_spell_entity_orbit_sprite_object_d3f4cf:
    dec a:$0018,X
    bne update_spell_entity_orbit_sprite_object_d3f4d9
    phx
    jsr advance_spell_entity_orbit_sprite_frame
    plx
update_spell_entity_orbit_sprite_object_d3f4d9:
    clc
    txa
    .a16
    adc #$001C
    tax
    dec $01
    bne update_spell_entity_orbit_sprite_object_d3f4cf
    .a16
    lda #$00FF
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
