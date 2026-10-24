; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_trail_sprite_object_long = $D3FD0D

.segment "CODE"
.org $480B
update_spell_entity_trail_family:
    jsl f:update_spell_entity_trail_sprite_object_long
    rts
