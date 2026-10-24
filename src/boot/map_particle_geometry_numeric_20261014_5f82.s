; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5F82
particle_geometry_5f82:
    .byte ($0E | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($12 | $80), ($0F | $00) ; x/y low6 + packed attributes high2
    .byte ($10 | $80), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($00 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($08 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($20 | $00) ; x/y low6 + packed attributes high2
