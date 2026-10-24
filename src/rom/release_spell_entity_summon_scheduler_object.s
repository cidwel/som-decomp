; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-entity-summon-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d3ee14 = $D3EE14

.segment "CODE"
.org $2BF2
release_spell_entity_summon_scheduler_object:
    jsl f:routine_d3ee14
    rts
