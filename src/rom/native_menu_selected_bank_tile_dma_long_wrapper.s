; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

transfer_native_menu_tiles_from_selected_bank = $25CE

.segment "CODE"
.org $2AEE
native_menu_selected_bank_tile_dma_long_wrapper:
    jsr transfer_native_menu_tiles_from_selected_bank
    rtl
