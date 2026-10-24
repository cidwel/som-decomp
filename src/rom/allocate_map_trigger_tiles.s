; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clone_first_layer_trigger_tile = $2B517
clone_second_layer_trigger_tile = $2B55A

.segment "CODE"
.org $D037
allocate_map_trigger_tiles:
    sep #$30
    phb
    .a8
    lda #$7F
    pha
    plb
    lda $9C
    sta $12
    lda $9D
    sta $14
    stz $13
    stz $15
    rep #$30
    lda $C8
    sta $10
    .i16
    ldx #$0000
    stx $18
    txy
allocate_map_trigger_tiles_c0d056:
    lda ($10),Y
    .a16
    and #$00FF
    asl
    asl
    tax
    lda a:$B800,X
    bpl allocate_map_trigger_tiles_c0d067
    jsl f:clone_first_layer_trigger_tile
allocate_map_trigger_tiles_c0d067:
    iny
    cpy $12
    bcc allocate_map_trigger_tiles_c0d056
    lda $10
    clc
    .a16
    adc #$0080
    sta $10
    .i16
    ldy #$0000
    dec $14
    bne allocate_map_trigger_tiles_c0d056
    sep #$30
    lda $A0
    beq allocate_map_trigger_tiles_c0d0be
    lda $A0
    sta $12
    lda $A1
    sta $14
    stz $13
    stz $15
    rep #$30
    lda $CA
    sta $10
    .i16
    ldx #$0000
    stx $18
    txy
allocate_map_trigger_tiles_c0d099:
    lda ($10),Y
    .a16
    and #$00FF
    asl
    asl
    tax
    lda a:$BC00,X
    bpl allocate_map_trigger_tiles_c0d0aa
    jsl f:clone_second_layer_trigger_tile
allocate_map_trigger_tiles_c0d0aa:
    iny
    cpy $12
    bcc allocate_map_trigger_tiles_c0d099
    lda $10
    clc
    .a16
    adc #$0080
    sta $10
    .i16
    ldy #$0000
    dec $14
    bne allocate_map_trigger_tiles_c0d099
allocate_map_trigger_tiles_c0d0be:
    sep #$30
    plb
    rts
