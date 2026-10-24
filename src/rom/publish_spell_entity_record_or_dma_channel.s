; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-events.md.
.setcpu "65816"
.smart
.a8
.i16

find_highest_set_entity_flag_bit = $4720

.segment "CODE"
.org $2997
publish_spell_entity_record_or_dma_channel:
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
    .i16
    cpx #$0000
    bne publish_spell_entity_record_or_dma_channel_c129ad
    jmp publish_spell_entity_record_or_dma_channel_c12a18
publish_spell_entity_record_or_dma_channel_c129ad:
    stx $01
    lda a:$000F,X
    .a8
    cmp #$05
    beq publish_spell_entity_record_or_dma_channel_c129d2
    .a8
    ora #$80
    sta a:$000F,X
    rep #$20
    lda a:$821A
    asl
    clc
    adc a:$8214
    tax
    lda $01
    sta a:$0000,X
    sep #$20
    inc a:$821A
    bra publish_spell_entity_record_or_dma_channel_c12a18
publish_spell_entity_record_or_dma_channel_c129d2:
    lda a:$0009,X
    rep #$20
    .a16
    and #$00FF
    tax
    jsr find_highest_set_entity_flag_bit
    asl
    asl
    asl
    asl
    tax
    ldy $01
    lda a:$0000,Y
    sta f:$004370,X
    lda a:$0001,Y
    sta f:$004371,X
    lda a:$0004,Y
    sta f:$004374,X
    rep #$20
    lda a:$0002,Y
    sta f:$004372,X
    sep #$20
    lda a:$0009,Y
    ora a:$821E
    sta a:$821E
    lda a:$0009,Y
    .a8
    cmp #$80
    bne publish_spell_entity_record_or_dma_channel_c12a18
    sty a:$8228
publish_spell_entity_record_or_dma_channel_c12a18:
    plb
    pla
    pla
    plp
    pld
    rts
