; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16

flush_pending_spell_entity_transfers_synchronously = $2A5C
snapshot_spell_entity_pending_transfer_count = $2A4D

.segment "CODE"
.org $2A1E
service_pending_spell_entity_transfer_requests:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    php
    sei
    ldx a:$8212
    beq service_pending_spell_entity_transfer_requests_c12a42
    lda a:$821A
    beq service_pending_spell_entity_transfer_requests_c12a42
    lda a:$8210
    bne service_pending_spell_entity_transfer_requests_c12a3f
    jsr snapshot_spell_entity_pending_transfer_count
    bra service_pending_spell_entity_transfer_requests_c12a42
service_pending_spell_entity_transfer_requests_c12a3f:
    jsr flush_pending_spell_entity_transfers_synchronously
service_pending_spell_entity_transfer_requests_c12a42:
    inc a:$8230
    plp
    dec a:$8230
    plb
    plp
    pld
    rts
