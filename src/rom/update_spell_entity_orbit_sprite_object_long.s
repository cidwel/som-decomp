; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_orbit_sprite_object = $F4B3

.segment "CODE"
.org $F4AF
update_spell_entity_orbit_sprite_object_long:
    jsr update_spell_entity_orbit_sprite_object
    rtl
