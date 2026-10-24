; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_wram_source_for_native_menu_tile_dma = $25CC

.segment "CODE"
.org $23BA
upload_native_menu_assembled_text_tiles:
    rep #$20
    lda a:$A18C
    sta f:$002116
    .a16
    lda #$9400
    sta a:$A194
    sep #$20
    jsr select_wram_source_for_native_menu_tile_dma
    rts
