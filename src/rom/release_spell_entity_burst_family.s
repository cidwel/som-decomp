; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-init.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_burst_sprite_object_long = $D3EBFF

.segment "CODE"
.org $280A
release_spell_entity_burst_family:
    jsl f:release_spell_entity_burst_sprite_object_long
    rts
