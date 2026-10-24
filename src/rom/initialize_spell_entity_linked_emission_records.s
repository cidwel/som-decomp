; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48
allocate_spell_entity_heap_bytes = $3D29

.segment "CODE"
.org $43F1
initialize_spell_entity_linked_emission_records:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    .a16
    lda #$0000
    .i16
    ldx #$0060
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx a:$8432
    sep #$20
    .a8
    lda #$0F
    sta a:$0000,X
    .a8
    lda #$30
    sta a:$0030,X
    .a8
    lda #$E0
    sta a:$0032,X
    .i16
    ldx #$0100
    jsr allocate_spell_entity_heap_bytes
    rep #$20
    stx a:$8426
    txa
    clc
    .a16
    adc #$0004
    sta a:$8428
    tax
    .i16
    ldy #$003E
initialize_spell_entity_linked_emission_records_c14435:
    clc
    .a16
    adc #$0004
    sta a:$0000,X
    tax
    dey
    bne initialize_spell_entity_linked_emission_records_c14435
    stz a:$0000,X
    stz a:$842E
    .a16
    lda #$842E
    sta a:$8430
    stz a:$842A
    .a16
    lda #$842A
    sta a:$842C
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
