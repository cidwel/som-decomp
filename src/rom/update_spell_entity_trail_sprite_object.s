; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

project_spell_entity_trail_sprite_frames = $F9B8

.segment "CODE"
.org $FD11
update_spell_entity_trail_sprite_object:
    phd
    php
    rep #$20
    dec a:$0152,X
    bne update_spell_entity_trail_sprite_object_d3fd29
    .a16
    lda #$0002
    sta a:$0152,X
    txy
    lda a:$0154,X
    asl
    tax
    jsr ($FD05,X)
update_spell_entity_trail_sprite_object_d3fd29:
    phx
    jsr project_spell_entity_trail_sprite_frames
    plx
    lda a:$0154,X
    .a16
    and #$0004
    beq update_spell_entity_trail_sprite_object_d3fd39
    .a16
    lda #$FFFF
update_spell_entity_trail_sprite_object_d3fd39:
    .a16
    eor #$FFFF
    plp
    pld
    rts
