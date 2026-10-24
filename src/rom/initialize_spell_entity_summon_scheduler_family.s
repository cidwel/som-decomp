; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-entity-summon-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d3ee5c = $D3EE5C

.segment "CODE"
.org $2BE8
initialize_spell_entity_summon_scheduler_family:
    jsl f:routine_d3ee5c
    rts
