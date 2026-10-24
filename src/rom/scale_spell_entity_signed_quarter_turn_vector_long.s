; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-signed-vectors.md.
.setcpu "65816"
.smart
.a8
.i16

scale_spell_entity_signed_quarter_turn_vector = $4AA8

.segment "CODE"
.org $2ECD
scale_spell_entity_signed_quarter_turn_vector_long:
    jsr scale_spell_entity_signed_quarter_turn_vector
    rtl
