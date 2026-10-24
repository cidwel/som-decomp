; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-groups.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_sprite_pointer_group = $395B

.segment "CODE"
.org $2EB9
release_spell_entity_sprite_pointer_group_long:
    jsr release_spell_entity_sprite_pointer_group
    rtl
