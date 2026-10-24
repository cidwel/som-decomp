; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_orbit_sprites_long = $D3F228

.segment "CODE"
.org $2EDD
initialize_spell_entity_orbit_family:
    jsl f:initialize_spell_entity_orbit_sprites_long
    rts
