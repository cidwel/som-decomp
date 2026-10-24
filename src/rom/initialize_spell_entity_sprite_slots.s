; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48

.segment "CODE"
.org $4161
initialize_spell_entity_sprite_slots:
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
    .i16
    ldx #$0400
    .a16
    lda #$0000
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx a:$8424
    .i16
    ldy #$0010
initialize_spell_entity_sprite_slots_c1417d:
    .a16
    lda #$8000
    sta a:$0000,X
    clc
    txa
    .a16
    adc #$0020
    tax
    dey
    bne initialize_spell_entity_sprite_slots_c1417d
    plb
    plp
    pld
    rts
