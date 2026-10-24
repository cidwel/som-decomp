; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-tiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $626A
snapshot_native_shop_item_selection_records:
    lda a:$A222
    sta a:$A24E
    .i16
    ldx #$0000
    .a8
    lda #$10
snapshot_native_shop_item_selection_records_c76275:
    xba
    lda a:$A136,X
    sta a:$A23E,X
    inx
    xba
    dec
    bne snapshot_native_shop_item_selection_records_c76275
    .i16
    ldx #$0000
    .i16
    ldy #$0008
snapshot_native_shop_item_selection_records_c76287:
    lda a:$A223,X
    sta a:$A24F,X
    inx
    dey
    bne snapshot_native_shop_item_selection_records_c76287
    rtl
