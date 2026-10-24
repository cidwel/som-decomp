; Numeric HDMA control records copied to05D0/05DB; scanline execution remains open.
.setcpu "65816"
main_palette_source = $0620
palette_snapshot_source = $DE02
.segment "CODE"
.org $F3C9
map_palette_color_hdma_records:
    .byte $7F
    .word main_palette_source
    .byte $20
    .word main_palette_source
    .byte $8F
    .word palette_snapshot_source
    .byte $00, $00
map_palette_address_hdma_records:
    .byte $7F, $10
    .byte $20, $10
    .byte $8F
    .repeat 15, color_index
        .byte color_index + 1
    .endrepeat
    .byte $00, $00
