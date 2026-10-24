; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-publication.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_glyph_grid_to_two_bitplanes = $2169

.segment "CODE"
.org $2AFE
native_menu_glyph_grid_expansion_long_wrapper:
    jsr expand_native_menu_glyph_grid_to_two_bitplanes
    rtl
