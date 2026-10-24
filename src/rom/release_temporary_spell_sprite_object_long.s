; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_temporary_spell_sprite_object = $EE18

.segment "CODE"
.org $EE14
release_temporary_spell_sprite_object_long:
    jsr release_temporary_spell_sprite_object
    rtl
