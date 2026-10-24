; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-groups.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_sprite_pointer_group = $392B

.segment "CODE"
.org $2EB5
allocate_spell_entity_sprite_pointer_group_long:
    jsr allocate_spell_entity_sprite_pointer_group
    rtl
