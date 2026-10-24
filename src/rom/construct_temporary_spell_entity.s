; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-construction.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48
allocate_spell_entity_actor_slot = $2896
classify_spell_entity_facing = $397D
initialize_spell_entity_actor_pools = $280F
initialize_spell_entity_heap = $3BD3
initialize_spell_entity_linked_emission_records = $43F1
initialize_spell_entity_sprite_slots = $4161
install_spell_entity_irq_handler = $2EEC
prepare_spell_entity_script_buffer = $39A1
publish_spell_entity_record_or_dma_channel = $2997
release_spell_entity_heap_with_saved_bank = $3D7D

.segment "CODE"
.org $39CD
construct_temporary_spell_entity:
    phd
    php
    rep #$20
    phx
    .a16
    lda #$8438
    sec
    .a16
    sbc #$8200
    tax
    jsr initialize_spell_entity_heap
    jsr initialize_spell_entity_linked_emission_records
    jsr initialize_spell_entity_sprite_slots
    jsr initialize_spell_entity_actor_pools
    .a16
    lda #$0002
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
    jsr install_spell_entity_irq_handler
    jsr prepare_spell_entity_script_buffer
    sep #$20
    .i16
    ldx #$002E
    .a8
    lda #$00
    jsr allocate_and_fill_spell_entity_heap_bytes
    lda f:$000099
    .a8
    and #$08
    sta a:$0026,X
    ply
    lda a:$0170,Y
    .a8
    cmp #$0C
    beq construct_temporary_spell_entity_c13a44
    .a8
    cmp #$0D
    beq construct_temporary_spell_entity_c13a48
    .a8
    cmp #$24
    beq construct_temporary_spell_entity_c13a4c
    .a8
    cmp #$25
    beq construct_temporary_spell_entity_c13a50
    .a8
    cmp #$10
    beq construct_temporary_spell_entity_c13a54
    .a8
    cmp #$1F
    beq construct_temporary_spell_entity_c13a58
    .a8
    cmp #$28
    beq construct_temporary_spell_entity_c13a5c
    jsr release_spell_entity_heap_with_saved_bank
    .i16
    ldx #$0000
    bra construct_temporary_spell_entity_c13ac2
construct_temporary_spell_entity_c13a44:
    .a8
    lda #$00
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a48:
    .a8
    lda #$01
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a4c:
    .a8
    lda #$02
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a50:
    .a8
    lda #$03
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a54:
    .a8
    lda #$04
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a58:
    .a8
    lda #$05
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a5c:
    .a8
    lda #$06
    bra construct_temporary_spell_entity_c13a60
construct_temporary_spell_entity_c13a60:
    sta a:$0025,X
    jsr classify_spell_entity_facing
    sta a:$0024,X
    lda a:$0178,Y
    dec
    sta a:$0000,X
    inc a:$0027,X
    lda a:$0179,Y
    beq construct_temporary_spell_entity_c13a8b
    dec
    sta a:$0008,X
    inc a:$0027,X
    lda a:$017A,Y
    beq construct_temporary_spell_entity_c13a8b
    dec
    sta a:$0010,X
    inc a:$0027,X
construct_temporary_spell_entity_c13a8b:
    rep #$20
    lda a:$0020,Y
    sta a:$0022,X
    lda a:$0022,Y
    sta a:$0020,X
    tya
    sta a:$0028,X
    .i16
    ldy #$0014
    lda a:$0024,X
    .a16
    bit #$0080
    beq construct_temporary_spell_entity_c13aab
    .i16
    ldy #$FFEC
construct_temporary_spell_entity_c13aab:
    .a16
    bit #$0040
    beq construct_temporary_spell_entity_c13aba
    tya
    clc
    adc a:$0020,X
    sta a:$0020,X
    bra construct_temporary_spell_entity_c13ac2
construct_temporary_spell_entity_c13aba:
    tya
    clc
    adc a:$0022,X
    sta a:$0022,X
construct_temporary_spell_entity_c13ac2:
    plp
    pld
    rts
