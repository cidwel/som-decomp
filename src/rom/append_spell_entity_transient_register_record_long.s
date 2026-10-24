; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

append_spell_entity_transient_register_record = $4514

.segment "CODE"
.org $2ED9
append_spell_entity_transient_register_record_long:
    jsr append_spell_entity_transient_register_record
    rtl
