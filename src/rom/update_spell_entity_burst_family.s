; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-init.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_burst_sprite_object_long = $D3ED09

.segment "CODE"
.org $2805
update_spell_entity_burst_family:
    jsl f:update_spell_entity_burst_sprite_object_long
    rts
