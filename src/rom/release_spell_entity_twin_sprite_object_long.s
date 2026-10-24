; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_twin_sprite_object = $2D38

.segment "CODE"
.org $2D34
release_spell_entity_twin_sprite_object_long:
    jsr release_spell_entity_twin_sprite_object
    rtl
