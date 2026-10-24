; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_entity_burst_sprite_object = $ED0D

.segment "CODE"
.org $ED09
update_spell_entity_burst_sprite_object_long:
    jsr update_spell_entity_burst_sprite_object
    rtl
