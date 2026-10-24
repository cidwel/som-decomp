; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_burst_sprite_object = $EC03

.segment "CODE"
.org $EBFF
release_spell_entity_burst_sprite_object_long:
    jsr release_spell_entity_burst_sprite_object
    rtl
