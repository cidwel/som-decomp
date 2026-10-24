; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_trail_sprite_object = $FD11

.segment "CODE"
.org $FD0D
update_spell_entity_trail_sprite_object_long:
    jsr update_spell_entity_trail_sprite_object
    rtl
