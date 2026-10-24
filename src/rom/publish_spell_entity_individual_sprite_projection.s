; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-projection.md.
.setcpu "65816"
.smart
.a8
.i16

project_spell_entity_sprite_record_to_oam = $3E9C

.segment "CODE"
.org $4118
publish_spell_entity_individual_sprite_projection:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr project_spell_entity_sprite_record_to_oam
    plb
    plp
    pld
    rts
