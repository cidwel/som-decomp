; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-sound-sprite-public-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

hide_spell_entity_sprite_oam_entry = $4090

.segment "CODE"
.org $2E8C
hide_burst_child_sprite_through_native_long_call_wrapper:
    jsr hide_spell_entity_sprite_oam_entry
    rtl
