; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5FB8
particle_geometry_5fb8:
    .byte ($0B | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0B | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0A | $80), ($11 | $00) ; x/y low6 + packed attributes high2
    .byte ($0A | $80), ($19 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($00 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($08 | $00) ; x/y low6 + packed attributes high2
    .byte ($10 | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($20 | $00) ; x/y low6 + packed attributes high2
