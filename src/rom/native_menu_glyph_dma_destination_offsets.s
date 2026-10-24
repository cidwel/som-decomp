.setcpu "65816"
.segment "CODE"
.org $CE53
.macro glyph_destination_pair first
    .byte first, first + $10
.endmacro
native_menu_glyph_dma_destination_offsets:
    glyph_destination_pair 8
    glyph_destination_pair 10
    glyph_destination_pair 12
    glyph_destination_pair 14
    glyph_destination_pair 32
