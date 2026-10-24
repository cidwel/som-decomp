; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_trail_sprite_object = $F983

.segment "CODE"
.org $F97F
release_spell_entity_trail_sprite_object_long:
    jsr release_spell_entity_trail_sprite_object
    rtl
