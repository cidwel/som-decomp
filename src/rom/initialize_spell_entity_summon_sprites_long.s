; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-summon-init.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_summon_sprites = $EE60

.segment "CODE"
.org $EE5C
initialize_spell_entity_summon_sprites_long:
    jsr initialize_spell_entity_summon_sprites
    rtl
