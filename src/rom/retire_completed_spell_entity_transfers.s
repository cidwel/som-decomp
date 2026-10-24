; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16

copy_native_entity_memory_bytes = $4761
release_spell_entity_heap_with_saved_bank = $3D7D
retire_spell_entity_actor_record = $2923

.segment "CODE"
.org $2B80
retire_completed_spell_entity_transfers:
    phd
    php
    rep #$20
    phb
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
    lda a:$821C
    beq retire_completed_spell_entity_transfers_c12bdf
    sta $01
    ldy a:$8214
retire_completed_spell_entity_transfers_c12b9b:
    phy
    ldx a:$0000,Y
    lda a:$000F,X
    .a16
    and #$0008
    beq retire_completed_spell_entity_transfers_c12bb3
    ldy a:$0002,X
    tyx
    jsr release_spell_entity_heap_with_saved_bank
    ply
    phy
    ldx a:$0000,Y
retire_completed_spell_entity_transfers_c12bb3:
    jsr retire_spell_entity_actor_record
    ply
    iny
    iny
    dec $01
    bne retire_completed_spell_entity_transfers_c12b9b
    lda a:$821C
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$8214
    tax
    lda a:$821A
    sec
    sbc a:$821C
    sta a:$821A
    asl
    ldy a:$8214
    jsr copy_native_entity_memory_bytes
    stz a:$821C
retire_completed_spell_entity_transfers_c12bdf:
    plb
    sep #$20
    pla
    pla
    pla
    plp
    pld
    rts
