; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_family_two_object = $FA08

.segment "CODE"
.org $FA04
release_spell_family_two_object_long:
    jsr release_spell_family_two_object
    rtl
