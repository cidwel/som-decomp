; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-slots.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_actor_slot = $2896
publish_spell_entity_record_or_dma_channel = $2997

.segment "CODE"
.org $412A
queue_spell_entity_oam_transfer:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx a:$841E
    beq queue_spell_entity_oam_transfer_c1415d
    .a8
    lda #$FF
    xba
    .a8
    lda #$04
    jsr allocate_spell_entity_actor_slot
    .a8
    lda #$7E
    sta a:$0004,X
    rep #$20
    lda a:$841E
    sta a:$0002,X
    .a16
    lda #$0220
    sta a:$0005,X
    stz a:$000A,X
    sep #$20
    jsr publish_spell_entity_record_or_dma_channel
queue_spell_entity_oam_transfer_c1415d:
    plb
    plp
    pld
    rts
