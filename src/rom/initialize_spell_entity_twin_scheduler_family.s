; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-entity-initializer-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12c15 = $C12C15

.segment "CODE"
.org $2C06
initialize_spell_entity_twin_scheduler_family:
    jsl f:routine_c12c15
    rts
