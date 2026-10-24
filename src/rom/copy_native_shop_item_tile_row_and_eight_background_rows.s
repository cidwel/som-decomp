; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6125
copy_native_shop_item_tile_row_and_eight_background_rows:
    lda a:$A24E
    rep #$20
    .a16
    and #$00FF
    pha
    tax
    lda a:$A24F,X
    .a16
    and #$00FF
    xba
    lsr
    tax
    .i16
    ldy #$0000
    sep #$20
    .a8
    lda #$10
copy_native_shop_item_tile_row_and_eight_background_rows_c7613f:
    xba
    lda f:$D2D480,X
    sta a:$9000,Y
    inx
    iny
    xba
    dec
    bne copy_native_shop_item_tile_row_and_eight_background_rows_c7613f
    rep #$20
    pla
    xba
    lsr
    tax
    sep #$20
    .a8
    lda #$08
    sta a:$A176
copy_native_shop_item_tile_row_and_eight_background_rows_c7615a:
    .a8
    lda #$10
copy_native_shop_item_tile_row_and_eight_background_rows_c7615c:
    xba
    lda f:$D2D080,X
    sta a:$9000,Y
    inx
    iny
    xba
    dec
    bne copy_native_shop_item_tile_row_and_eight_background_rows_c7615c
    dec a:$A176
    bne copy_native_shop_item_tile_row_and_eight_background_rows_c7615a
    rts
