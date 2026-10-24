; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-direction.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FA1D
select_spell_entity_trail_turn_direction:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    lda a:$014C,X
    .a16
    and #$0003
    sta $01
    .a16
    and #$0001
    beq select_spell_entity_trail_turn_direction_d3fa49
    lda a:$0142,X
    cmp a:$0146,X
    bmi select_spell_entity_trail_turn_direction_d3fa3d
    bvs select_spell_entity_trail_turn_direction_d3fa44
    bra select_spell_entity_trail_turn_direction_d3fa3f
select_spell_entity_trail_turn_direction_d3fa3d:
    bvc select_spell_entity_trail_turn_direction_d3fa44
select_spell_entity_trail_turn_direction_d3fa3f:
    .a16
    lda #$0000
    bra select_spell_entity_trail_turn_direction_d3fa5f
select_spell_entity_trail_turn_direction_d3fa44:
    .a16
    lda #$0002
    bra select_spell_entity_trail_turn_direction_d3fa5f
select_spell_entity_trail_turn_direction_d3fa49:
    lda a:$0140,X
    cmp a:$0144,X
    bmi select_spell_entity_trail_turn_direction_d3fa55
    bvs select_spell_entity_trail_turn_direction_d3fa5c
    bra select_spell_entity_trail_turn_direction_d3fa57
select_spell_entity_trail_turn_direction_d3fa55:
    bvc select_spell_entity_trail_turn_direction_d3fa5c
select_spell_entity_trail_turn_direction_d3fa57:
    .a16
    lda #$0001
    bra select_spell_entity_trail_turn_direction_d3fa5f
select_spell_entity_trail_turn_direction_d3fa5c:
    .a16
    lda #$0003
select_spell_entity_trail_turn_direction_d3fa5f:
    asl $01
    asl $01
    ora $01
    sta a:$014C,X
    sep #$20
    pla
    pla
    plp
    pld
    rts
