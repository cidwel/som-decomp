; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

update_spell_family_two_object_long = $DCFA6A

.segment "CODE"
.org $2C01
update_spell_scheduler_family_two_object:
    jsl f:update_spell_family_two_object_long
    rts
