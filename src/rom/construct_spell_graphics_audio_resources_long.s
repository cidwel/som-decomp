; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_entity_graphics_audio_resources = $37E7

.segment "CODE"
.org $2E90
construct_spell_graphics_audio_resources_long:
    jsr construct_spell_entity_graphics_audio_resources
    rtl
