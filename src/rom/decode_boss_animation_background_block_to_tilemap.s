; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_boss_terrain_row_stride = $2AA6
prepare_boss_sprite_screen_position = $2005

.segment "CODE"
.org $1CCF
decode_boss_animation_background_block_to_tilemap:
    lda $6C
    .a16
    and #$FF00
    lsr
    lsr
    sta $72
    lda $6C
    .a16
    and #$00FF
    asl
    adc $72
    .a16
    adc #$BC00
    sta $7C
    sep #$20
    .a8
    lda #$C1
    sta $78
    .a8
    lda #$7F
    sta $7E
    lda $6E
    sta $46
    lda $6F
    sta $4E
    jsr multiply_boss_terrain_row_stride
    rep #$30
    ldx $87
    lda a:$0098,X
    .a16
    bit #$0004
    bne decode_boss_animation_background_block_to_tilemap_c21d18
    lda $6E
    .a16
    and #$00FF
    asl
    sta $72
    lda $56
    asl
    sta $74
    .a16
    lda #$0001
    bra decode_boss_animation_background_block_to_tilemap_c21d26
decode_boss_animation_background_block_to_tilemap_c21d18:
    lda $6E
    .a16
    and #$00FF
    sta $72
    lda $56
    sta $74
    .a16
    lda #$0002
decode_boss_animation_background_block_to_tilemap_c21d26:
    sta a:$0FAE
    lda a:$0098,X
    .a16
    and #$0004
    .a16
    eor #$0004
    tax
    lda a:$0FB0
    clc
    adc a:$0FB4
    sec
    sbc a:$00A8
    .a16
    eor #$FFFF
    inc
    sta a:$00B0,X
    sta a:$0FBE
    lda a:$00AA
    sta $95
    lda a:$00C2
    sec
    .a16
    sbc #$00E0
    cmp $95
    bcs decode_boss_animation_background_block_to_tilemap_c21d61
    lda a:$00AA
    sec
    sbc a:$00C2
    sta $95
decode_boss_animation_background_block_to_tilemap_c21d61:
    lda a:$0FB2
    clc
    adc a:$0FB6
    sec
    sbc $95
    sta a:$0FBC
    .a16
    eor #$FFFF
    inc
    sta a:$00B2,X
    ldx $87
    jsr prepare_boss_sprite_screen_position
    stz $95
    sep #$30
    lda [$76]
    bne decode_boss_animation_background_block_to_tilemap_c21db3
    inc $76
    bne decode_boss_animation_background_block_to_tilemap_c21d88
    inc $77
decode_boss_animation_background_block_to_tilemap_c21d88:
    .i8
    ldy #$00
decode_boss_animation_background_block_to_tilemap_c21d8a:
    lda [$76]
    inc $76
    bne decode_boss_animation_background_block_to_tilemap_c21d92
    inc $77
decode_boss_animation_background_block_to_tilemap_c21d92:
    sta [$7C],Y
    rep #$20
    dec $74
    sep #$20
    beq decode_boss_animation_background_block_to_tilemap_c21db0
    iny
    cpy $72
    bne decode_boss_animation_background_block_to_tilemap_c21d8a
    lda $7C
    clc
    .a8
    adc #$40
    sta $7C
    lda $7D
    .a8
    adc #$00
    sta $7D
    bra decode_boss_animation_background_block_to_tilemap_c21d88
decode_boss_animation_background_block_to_tilemap_c21db0:
    rep #$20
    rts
decode_boss_animation_background_block_to_tilemap_c21db3:
    inc $76
    bne decode_boss_animation_background_block_to_tilemap_c21db9
    inc $77
decode_boss_animation_background_block_to_tilemap_c21db9:
    .i8
    ldy #$00
decode_boss_animation_background_block_to_tilemap_c21dbb:
    lda [$76]
    sta $97
    inc $76
    bne decode_boss_animation_background_block_to_tilemap_c21dc5
    inc $77
decode_boss_animation_background_block_to_tilemap_c21dc5:
    .i8
    ldx #$08
    stx $98
decode_boss_animation_background_block_to_tilemap_c21dc9:
    asl $97
    bcc decode_boss_animation_background_block_to_tilemap_c21dd7
    lda [$76]
    inc $76
    bne decode_boss_animation_background_block_to_tilemap_c21dd9
    inc $77
    bra decode_boss_animation_background_block_to_tilemap_c21dd9
decode_boss_animation_background_block_to_tilemap_c21dd7:
    lda $96
decode_boss_animation_background_block_to_tilemap_c21dd9:
    ldx $95
    stx $96
    sta $95
    sta [$7C],Y
    rep #$20
    dec $74
    sep #$20
    beq decode_boss_animation_background_block_to_tilemap_c21e03
    iny
    cpy $72
    bne decode_boss_animation_background_block_to_tilemap_c21dfd
    .i8
    ldy #$00
    lda $7C
    clc
    .a8
    adc #$40
    sta $7C
    lda $7D
    .a8
    adc #$00
    sta $7D
decode_boss_animation_background_block_to_tilemap_c21dfd:
    dec $98
    bne decode_boss_animation_background_block_to_tilemap_c21dc9
    bra decode_boss_animation_background_block_to_tilemap_c21dbb
decode_boss_animation_background_block_to_tilemap_c21e03:
    rep #$20
    rts
