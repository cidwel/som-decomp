; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

native_menu_selected_bank_tile_dma_long_wrapper = $C02AEE

.segment "CODE"
.org $5DF9
upload_native_party_page_tiles_and_three_palettes:
    rep #$20
    .a16
    lda #$4300
    sta f:$002116
    sep #$20
    .i16
    ldx #$0000
    stx a:$A194
    .i16
    ldx #$0100
    stx a:$A191
    .a8
    lda #$D5
    jsl f:native_menu_selected_bank_tile_dma_long_wrapper
    .i16
    ldx #$8000
    stx a:$A194
    .a8
    lda #$D5
    jsl f:native_menu_selected_bank_tile_dma_long_wrapper
    .i16
    ldx #$0000
    stx a:$A194
    .a8
    lda #$D6
    jsl f:native_menu_selected_bank_tile_dma_long_wrapper
    lda a:$A202
    .a8
    cmp #$07
    bne upload_native_party_page_tiles_and_three_palettes_c75e5f
    .i16
    ldx #$0200
    stx a:$A191
    .i16
    ldx #$FE00
    stx a:$A194
    .a8
    lda #$CC
    jsl f:native_menu_selected_bank_tile_dma_long_wrapper
    .a8
    lda #$C0
    sta f:$002121
    .i16
    ldy #$0080
    .i16
    ldx #$0000
upload_native_party_page_tiles_and_three_palettes_c75e53:
    lda f:$CCFD80,X
    sta f:$002122
    inx
    dey
    bne upload_native_party_page_tiles_and_three_palettes_c75e53
upload_native_party_page_tiles_and_three_palettes_c75e5f:
    .a8
    lda #$03
    sta a:$A175
    .a8
    lda #$90
    sta f:$002121
    .i16
    ldx #$0F00
    phb
    .a8
    lda #$C8
    pha
    plb
upload_native_party_page_tiles_and_three_palettes_c75e72:
    .i16
    ldy #$001E
    sta f:$002122
    sta f:$002122
upload_native_party_page_tiles_and_three_palettes_c75e7d:
    lda a:$1000,X
    sta f:$002122
    inx
    dey
    bne upload_native_party_page_tiles_and_three_palettes_c75e7d
    lda f:$7EA175
    dec
    sta f:$7EA175
    bne upload_native_party_page_tiles_and_three_palettes_c75e72
    plb
    rts
