; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-transfers.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_actor_slot = $2896
publish_spell_entity_record_or_dma_channel = $2997

.segment "CODE"
.org $4240
queue_spell_entity_sprite_slot_read:
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
    stx $01
    .a16
    lda #$0002
    jsr allocate_spell_entity_actor_slot
    .a16
    lda #$0020
    sta a:$0005,X
    lda $01
    sta a:$0002,X
    lda $01
    sec
    sbc a:$8424
    lsr
    sep #$20
    pha
    sta a:$000A,X
    .a8
    lda #$7E
    sta a:$0004,X
    .a8
    lda #$80
    sta a:$0000,X
    .a8
    lda #$3B
    sta a:$0001,X
    jsr publish_spell_entity_record_or_dma_channel
    ldx $01
    stz a:$0000,X
    stz a:$0001,X
    pla
    lsr
    lsr
    lsr
    lsr
    plb
    sta $02,S
    pla
    pla
    plp
    pld
    rts
