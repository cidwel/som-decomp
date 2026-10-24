; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_orbit_sprites = $F22C

.segment "CODE"
.org $F228
initialize_spell_entity_orbit_sprites_long:
    jsr initialize_spell_entity_orbit_sprites
    rtl
