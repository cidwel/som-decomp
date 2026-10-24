; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-init.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_burst_sprites = $EA04

.segment "CODE"
.org $EA00
initialize_spell_entity_burst_sprites_long:
    jsr initialize_spell_entity_burst_sprites
    rtl
