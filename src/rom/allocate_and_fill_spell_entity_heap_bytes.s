; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_heap_bytes = $3D29
fill_native_entity_memory_bytes = $4738

.segment "CODE"
.org $3D48
allocate_and_fill_spell_entity_heap_bytes:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0003
    tcd
    tcs
    lda $04,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    sta $01
    stx $04
    jsr allocate_spell_entity_heap_bytes
    stx $02
    lda $01
    ldy $04
    jsr fill_native_entity_memory_bytes
    ldx $02
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0005
    tcs
    plp
    pld
    rts
