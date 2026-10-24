; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

transfer_native_menu_palette_from_selected_bank = $25FD

.segment "CODE"
.org $25F7
select_rom_source_for_native_menu_palette_dma:
    .a8
    lda #$C7
    bra transfer_native_menu_palette_from_selected_bank
