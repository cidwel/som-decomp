; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-engine.md.
.setcpu "65816"
.smart
.a8
.i16

execute_native_spell_entity_scheduler = $3B3C

.segment "CODE"
.org $0038
execute_native_spell_entity_scheduler_long:
    jsr execute_native_spell_entity_scheduler
    rtl
