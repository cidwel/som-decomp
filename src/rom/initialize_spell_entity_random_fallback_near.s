; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-entity-initializer-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d3fd3f = $D3FD3F

.segment "CODE"
.org $4810
initialize_spell_entity_random_fallback_near:
    jsl f:routine_d3fd3f
    rts
