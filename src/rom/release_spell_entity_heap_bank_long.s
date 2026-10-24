; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_with_saved_bank = $3D7D

.segment "CODE"
.org $2E7C
release_spell_entity_heap_bank_long:
    jsr release_spell_entity_heap_with_saved_bank
    rtl
