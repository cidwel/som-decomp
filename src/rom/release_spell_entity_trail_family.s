; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_trail_sprite_object_long = $D3F97F

.segment "CODE"
.org $4806
release_spell_entity_trail_family:
    jsl f:release_spell_entity_trail_sprite_object_long
    rts
