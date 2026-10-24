; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-signed-vectors.md.
.setcpu "65816"
.smart
.a8
.i16

scale_spell_entity_signed_angle_vector = $49EC

.segment "CODE"
.org $2EC9
scale_spell_entity_signed_angle_vector_long:
    jsr scale_spell_entity_signed_angle_vector
    rtl
