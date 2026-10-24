; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_twin_sprite_object_long = $C12E02

.segment "CODE"
.org $2C10
update_spell_entity_twin_scheduler_object:
    jsl f:update_spell_entity_twin_sprite_object_long
    rts
