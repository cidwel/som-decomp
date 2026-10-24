; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_heap_bytes = $3D29
fill_native_entity_memory_bytes = $4738

.segment "CODE"
.org $3BD3
initialize_spell_entity_heap:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    phx
    txy
    .i16
    ldx #$8200
    .a8
    lda #$00
    jsr fill_native_entity_memory_bytes
    plx
    jsr allocate_spell_entity_heap_bytes
    ldx a:$8238
    phx
    .i16
    ldx #$0038
    stx a:$8238
    .i16
    ldx #$125F
    jsr allocate_spell_entity_heap_bytes
    plx
    stx a:$8238
    plb
    plp
    pld
    rts
