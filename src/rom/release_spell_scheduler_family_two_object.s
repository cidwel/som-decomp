; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_family_two_object_long = $DCFA04

.segment "CODE"
.org $2BFC
release_spell_scheduler_family_two_object:
    jsl f:release_spell_family_two_object_long
    rts
