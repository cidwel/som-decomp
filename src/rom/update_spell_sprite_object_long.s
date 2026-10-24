; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-motion.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_sprite_object = $F15D

.segment "CODE"
.org $F159
update_spell_sprite_object_long:
    jsr update_spell_sprite_object
    rtl
