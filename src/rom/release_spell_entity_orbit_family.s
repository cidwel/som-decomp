; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_orbit_sprite_object_long = $D3F306

.segment "CODE"
.org $2EE2
release_spell_entity_orbit_family:
    jsl f:release_spell_entity_orbit_sprite_object_long
    rts
