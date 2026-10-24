; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3

.segment "CODE"
.org $2ED5
allocate_spell_entity_register_record_long:
    jsr allocate_spell_entity_register_record
    rtl
