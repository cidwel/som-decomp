; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-init.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_trail_sprites = $F835

.segment "CODE"
.org $F831
initialize_spell_entity_trail_sprites_long:
    jsr initialize_spell_entity_trail_sprites
    rtl
