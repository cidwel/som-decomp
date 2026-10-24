; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

publish_spell_entity_individual_sprite_projection = $4118

.segment "CODE"
.org $2E84
publish_spell_frame_projection_long:
    jsr publish_spell_entity_individual_sprite_projection
    rtl
