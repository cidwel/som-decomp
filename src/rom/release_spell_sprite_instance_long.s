; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_sprite_instance = $40E5

.segment "CODE"
.org $2E88
release_spell_sprite_instance_long:
    jsr release_spell_entity_sprite_instance
    rtl
