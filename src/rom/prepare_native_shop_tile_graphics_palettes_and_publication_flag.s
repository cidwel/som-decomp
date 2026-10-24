; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-publication.md.
.setcpu "65816"
.smart
.a8
.i16

copy_native_shop_item_tile_row_and_eight_background_rows = $6125
native_menu_glyph_grid_expansion_long_wrapper = $C02AFE
select_native_shop_two_palette_records_and_shared_color_word = $60D7

.segment "CODE"
.org $60C7
prepare_native_shop_tile_graphics_palettes_and_publication_flag:
    jsr copy_native_shop_item_tile_row_and_eight_background_rows
    jsl f:native_menu_glyph_grid_expansion_long_wrapper
    jsr select_native_shop_two_palette_records_and_shared_color_word
    .a8
    lda #$80
    tsb a:$A212
    rts
