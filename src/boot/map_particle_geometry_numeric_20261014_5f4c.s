; Original sprite coordinate/attribute metadata, no pixel/tile payload.
.setcpu "65816"
.segment "RODATA"
.org $5F4C
particle_geometry_5f4c:
    .byte ($0B | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0B | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($03 | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($03 | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($10 | $00), ($00 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($08 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($10 | $00) ; x/y low6 + packed attributes high2
    .byte ($0F | $00), ($18 | $00) ; x/y low6 + packed attributes high2
    .byte ($10 | $00), ($20 | $00) ; x/y low6 + packed attributes high2
