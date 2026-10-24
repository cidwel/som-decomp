; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-tiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6170
render_native_shop_item_tile_frame:
    .i16
    ldy #$0182
    .a8
    lda #$00
    xba
    lda a:$A24E
    rep #$20
    asl
    sta a:$A173
    asl
    asl
    asl
    asl
    sec
    sbc a:$A173
    tax
    sep #$20
    .a8
    lda #$07
    sta a:$A171
render_native_shop_item_tile_frame_c7618f:
    lda f:$C77169,X
    sec
    .a8
    sbc #$10
    asl
    clc
    .a8
    adc #$40
    sta a:$9000,Y
    sta a:$90C0,Y
    lda f:$C7716A,X
    .a8
    and #$E0
    .a8
    ora #$38
    sta a:$9001,Y
    .a8
    eor #$80
    sta a:$90C1,Y
    inx
    inx
    iny
    iny
    dec a:$A171
    bne render_native_shop_item_tile_frame_c7618f
    .a8
    lda #$08
    sta a:$A171
render_native_shop_item_tile_frame_c761be:
    lda f:$C77169,X
    sec
    .a8
    sbc #$10
    asl
    clc
    .a8
    adc #$40
    sta a:$9000,Y
    sta a:$90C0,Y
    lda f:$C7716A,X
    .a8
    and #$E0
    .a8
    ora #$38
    .a8
    eor #$40
    pha
    sta a:$9001,Y
    pla
    .a8
    eor #$80
    sta a:$90C1,Y
    dex
    dex
    iny
    iny
    dec a:$A171
    bne render_native_shop_item_tile_frame_c761be
    .a8
    lda #$00
    xba
    lda a:$A24E
    asl
    asl
    asl
    tax
    .i16
    ldy #$01C2
    lda f:$C77259,X
    sec
    .a8
    sbc #$10
    asl
    clc
    .a8
    adc #$40
    sta a:$9000,Y
    sta a:$901C,Y
    sta a:$9040,Y
    sta a:$905C,Y
    lda f:$C7725A,X
    .a8
    and #$E0
    .a8
    ora #$38
    sta a:$9001,Y
    .a8
    eor #$40
    sta a:$901D,Y
    .a8
    eor #$80
    sta a:$905D,Y
    .a8
    eor #$40
    sta a:$9041,Y
    rep #$20
    .i16
    ldx #$01C4
    .a16
    lda #$0002
    sta a:$A175
render_native_shop_item_tile_frame_c76235:
    .a16
    lda #$000D
    sta a:$A171
render_native_shop_item_tile_frame_c7623b:
    .a16
    lda #$3C3E
    sta a:$9000,X
    inx
    inx
    dec a:$A171
    bne render_native_shop_item_tile_frame_c7623b
    txa
    clc
    .a16
    adc #$0026
    tax
    dec a:$A175
    bne render_native_shop_item_tile_frame_c76235
    sep #$20
    rtl
