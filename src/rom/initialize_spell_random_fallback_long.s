; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_random_fallback = $FD43

.segment "CODE"
.org $FD3F
initialize_spell_random_fallback_long:
    jsr initialize_spell_random_fallback
    rtl
