; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_heap_units = $3C04

.segment "CODE"
.org $3D29
allocate_spell_entity_heap_bytes:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    txa
    clc
    .a16
    adc #$003F
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    jsr allocate_spell_entity_heap_units
    plb
    plp
    pld
    rts
