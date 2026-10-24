; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_twin_family = $2C19

.segment "CODE"
.org $2C15
initialize_spell_entity_twin_family_long:
    jsr initialize_spell_entity_twin_family
    rtl
