; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_orbit_sprite_object_long = $D3F4AF

.segment "CODE"
.org $2EE7
update_spell_entity_orbit_family:
    jsl f:update_spell_entity_orbit_sprite_object_long
    rts
