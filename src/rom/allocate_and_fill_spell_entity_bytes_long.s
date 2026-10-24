; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48

.segment "CODE"
.org $2E78
allocate_and_fill_spell_entity_bytes_long:
    jsr allocate_and_fill_spell_entity_heap_bytes
    rtl
