; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_family_two_object = $FA6E

.segment "CODE"
.org $FA6A
update_spell_family_two_object_long:
    jsr update_spell_family_two_object
    rtl
