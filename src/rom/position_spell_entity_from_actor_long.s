; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

position_spell_entity_from_actor_coordinates = $38EA

.segment "CODE"
.org $2EB1
position_spell_entity_from_actor_long:
    jsr position_spell_entity_from_actor_coordinates
    rtl
