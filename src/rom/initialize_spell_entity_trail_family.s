; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-init.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_trail_sprites_long = $D3F831

.segment "CODE"
.org $4801
initialize_spell_entity_trail_family:
    jsl f:initialize_spell_entity_trail_sprites_long
    rts
