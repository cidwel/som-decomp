; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_units = $3CB8

.segment "CODE"
.org $3D7D
release_spell_entity_heap_with_saved_bank:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr release_spell_entity_heap_units
    plb
    plp
    pld
    rts
