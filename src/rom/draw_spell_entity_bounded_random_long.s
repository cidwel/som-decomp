; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_random_below_rejection_bound = $46C3

.segment "CODE"
.org $2ED1
draw_spell_entity_bounded_random_long:
    jsr draw_spell_entity_random_below_rejection_bound
    rtl
