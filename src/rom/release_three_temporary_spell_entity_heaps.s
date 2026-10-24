; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-spell-entity-cleanup.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_with_saved_bank = $3D7D

.segment "CODE"
.org $284B
release_three_temporary_spell_entity_heaps:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx a:$8212
    jsr release_spell_entity_heap_with_saved_bank
    ldx a:$8214
    jsr release_spell_entity_heap_with_saved_bank
    ldx a:$8218
    jsr release_spell_entity_heap_with_saved_bank
    plb
    plp
    pld
    rts
