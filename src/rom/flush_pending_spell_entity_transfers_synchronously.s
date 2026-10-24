; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16

drain_spell_entity_transfer_queue_to_ppu = $2A80
retire_completed_spell_entity_transfers = $2B80

.segment "CODE"
.org $2A5C
flush_pending_spell_entity_transfers_synchronously:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    sep #$20
    lda a:$821A
    sta a:$821C
    jsr drain_spell_entity_transfer_queue_to_ppu
    jsr retire_completed_spell_entity_transfers
    rep #$20
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
