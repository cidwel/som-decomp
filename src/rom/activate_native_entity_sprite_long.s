; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

activate_spell_entity_sprite_instance = $402F

.segment "CODE"
.org $2E80
activate_native_entity_sprite_long:
    jsr activate_spell_entity_sprite_instance
    rtl
