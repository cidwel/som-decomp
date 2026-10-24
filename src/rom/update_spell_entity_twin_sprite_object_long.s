; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_twin_sprite_object = $2E06

.segment "CODE"
.org $2E02
update_spell_entity_twin_sprite_object_long:
    jsr update_spell_entity_twin_sprite_object
    rtl
