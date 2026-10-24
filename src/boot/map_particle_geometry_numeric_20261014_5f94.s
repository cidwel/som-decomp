; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5F94
particle_geometry_5f94:
    .byte ($0E | $80), ($11 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $80), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($14 | $80), ($11 | $00) ; x/y low6 + packed attributes high2
    .byte ($13 | $80), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($00 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($08 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($20 | $00) ; x/y low6 + packed attributes high2
