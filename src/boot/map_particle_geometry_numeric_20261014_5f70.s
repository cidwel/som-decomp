; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5F70
particle_geometry_5f70:
    .byte ($0B | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0C | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $80), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0A | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($00 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($08 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($20 | $00) ; x/y low6 + packed attributes high2
