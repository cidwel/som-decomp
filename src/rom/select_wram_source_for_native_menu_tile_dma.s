; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $25CC
select_wram_source_for_native_menu_tile_dma:
    .a8
    lda #$7E
