; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48
allocate_spell_entity_heap_bytes = $3D29

.segment "CODE"
.org $280F
initialize_spell_entity_actor_pools:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$0200
    .a8
    lda #$00
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx a:$8212
    .a8
    lda #$00
    .i16
    ldx #$0060
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx a:$8214
    rep #$20
    clc
    txa
    .a16
    adc #$0040
    tax
    stx a:$8216
    .i16
    ldx #$00C0
    jsr allocate_spell_entity_heap_bytes
    stx a:$8218
    stz a:$821A
    plb
    plp
    pld
    rts
