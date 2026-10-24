; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_family_two_long = $DCF927

.segment "CODE"
.org $2BF7
initialize_spell_scheduler_family_two:
    jsl f:initialize_spell_family_two_long
    rts
