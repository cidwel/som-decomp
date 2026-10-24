; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5FA6
particle_geometry_5fa6:
    .byte ($0D | $80), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0D | $80), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $80), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $80), ($17 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($00 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($08 | $00) ; x/y low6 + packed attributes high2
    .byte ($10 | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($0E | $00), ($20 | $00) ; x/y low6 + packed attributes high2
