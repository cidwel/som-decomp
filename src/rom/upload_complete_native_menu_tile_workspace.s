; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_wram_source_for_native_menu_tile_dma = $25CC

.segment "CODE"
.org $25AD
upload_complete_native_menu_tile_workspace:
    rep #$20
    .a16
    lda #$5800
    sta f:$002116
    .a16
    lda #$0800
    sta a:$A191
    .a16
    lda #$9000
    sta a:$A194
    sep #$20
    jsr select_wram_source_for_native_menu_tile_dma
    rts
