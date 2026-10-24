; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_family_two = $F92B

.segment "CODE"
.org $F927
initialize_spell_family_two_long:
    jsr initialize_spell_family_two
    rtl
