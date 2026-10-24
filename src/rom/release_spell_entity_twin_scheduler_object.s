; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_twin_sprite_object_long = $C12D34

.segment "CODE"
.org $2C0B
release_spell_entity_twin_scheduler_object:
    jsl f:release_spell_entity_twin_sprite_object_long
    rts
