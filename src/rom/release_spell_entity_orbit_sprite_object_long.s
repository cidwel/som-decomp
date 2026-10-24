; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_orbit_sprite_object = $F30A

.segment "CODE"
.org $F306
release_spell_entity_orbit_sprite_object_long:
    jsr release_spell_entity_orbit_sprite_object
    rtl
