; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9C2B
emit_ui_sprite_tile_grid:
    sep #$30
    stz $13
    .i8
    ldy #$00
    lda $08
    sta $0D
    lda $09
    sta $0E
    lda ($00),Y
    pha
    .a8
    and #$0F
    sta $0A
    sta $0C
    .a8
    cmp #$04
    bne emit_ui_sprite_tile_grid_c09c54
    lda $12
    sta $13
    asl
    .a8
    eor #$FF
    sec
    adc $09
    sta $09
    sta $0E
emit_ui_sprite_tile_grid_c09c54:
    pla
    lsr
    lsr
    lsr
    lsr
    sta $0B
    iny
    ldx $7C
emit_ui_sprite_tile_grid_c09c5e:
    rep #$20
    lda $08
    sta a:$0800,X
    lda ($00),Y
    sta a:$0802,X
    inx
    inx
    inx
    inx
    sep #$20
    iny
    iny
    lda $08
    clc
    .a8
    adc #$08
    sta $08
    lda $13
    beq emit_ui_sprite_tile_grid_c09c8f
    clc
    adc $09
    sta $09
    lda $0C
    .a8
    cmp #$03
    bne emit_ui_sprite_tile_grid_c09c8f
    lda $13
    clc
    adc $09
    sta $09
emit_ui_sprite_tile_grid_c09c8f:
    dec $0C
    bne emit_ui_sprite_tile_grid_c09c5e
    lda $0D
    sta $08
    lda $0A
    sta $0C
    lda $0E
    clc
    .a8
    adc #$08
    sta $0E
    sta $09
    dec $0B
    bne emit_ui_sprite_tile_grid_c09c5e
    stx $7C
    rts
