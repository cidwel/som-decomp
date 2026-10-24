; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-slots.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_actor_slot = $2896
commit_spell_entity_register_shadows_and_recycle_transients = $45E0
drain_spell_entity_transfer_queue_to_ppu = $2A80
publish_spell_entity_linked_registers_to_ppu = $453C
publish_spell_entity_record_or_dma_channel = $2997
queue_spell_entity_oam_transfer = $412A
retire_completed_spell_entity_transfers = $2B80
service_pending_spell_entity_transfer_requests = $2A1E

.segment "CODE"
.org $2F5E
service_complete_spell_entity_irq:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    pha
    phx
    phy
    sep #$20
    lda f:$000021
    sta f:$00212C
    lda f:$000022
    sta f:$00212D
    lda f:$000029
    sta f:$002105
    lda a:$822A
    beq service_complete_spell_entity_irq_c12fdb
    lda a:$8230
    bne service_complete_spell_entity_irq_c12fd8
    lda f:$004210
    .a8
    lda #$00
    sta f:$0000EC
    .a8
    lda #$80
    sta f:$002100
    jsr service_pending_spell_entity_transfer_requests
    jsr drain_spell_entity_transfer_queue_to_ppu
    jsr publish_spell_entity_linked_registers_to_ppu
    .a8
    lda #$0F
    sta f:$002100
    jsr retire_completed_spell_entity_transfers
    jsr commit_spell_entity_register_shadows_and_recycle_transients
    jsr queue_spell_entity_oam_transfer
    .a8
    lda #$02
    jsr allocate_spell_entity_actor_slot
    stz a:$0004,X
    stz a:$000A,X
    rep #$20
    .a16
    lda #$0600
    sta a:$0002,X
    .a16
    lda #$0018
    sta a:$0005,X
    jsr publish_spell_entity_record_or_dma_channel
service_complete_spell_entity_irq_c12fd8:
    inc a:$8230
service_complete_spell_entity_irq_c12fdb:
    rep #$20
    ply
    plx
    pla
    plb
    plp
    pld
    rti
