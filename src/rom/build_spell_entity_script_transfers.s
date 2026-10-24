; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-construction.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_actor_slot = $2896
publish_spell_entity_record_or_dma_channel = $2997

.segment "CODE"
.org $302E
build_spell_entity_script_transfers:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    stx $03
    .a16
    and #$00FF
    sta $01
    tya
    sec
    .a16
    sbc #$F800
    tax
build_spell_entity_script_transfers_c13054:
    stx $05
    .a16
    lda #$0001
    jsr allocate_spell_entity_actor_slot
    txy
    ldx $05
    lda f:$DCF800,X
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$7000
    sta a:$000A,Y
    lda f:$DCF801,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq build_spell_entity_script_transfers_c130a5
    asl
    asl
    asl
    asl
    asl
    clc
    adc $03
    sta a:$0002,Y
    sep #$20
    lda f:$DCF802,X
    .a8
    and #$80
    beq build_spell_entity_script_transfers_c1309c
    .a8
    lda #$81
    sta a:$0000,Y
    .a8
    lda #$39
    sta a:$0001,Y
build_spell_entity_script_transfers_c1309c:
    .a8
    lda #$7E
    sta a:$0004,Y
    rep #$20
    bra build_spell_entity_script_transfers_c130b9
build_spell_entity_script_transfers_c130a5:
    .a16
    lda #$302C
    sta a:$0002,Y
    sep #$20
    .a8
    lda #$C1
    sta a:$0004,Y
    .a8
    lda #$09
    sta a:$0000,Y
    rep #$20
build_spell_entity_script_transfers_c130b9:
    lda f:$DCF802,X
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    asl
    sta a:$0005,Y
    tyx
    jsr publish_spell_entity_record_or_dma_channel
    ldx $05
    inx
    inx
    inx
    dec $01
    beq build_spell_entity_script_transfers_c130d8
    jmp build_spell_entity_script_transfers_c13054
build_spell_entity_script_transfers_c130d8:
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
