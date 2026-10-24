; Low distance-high-bit masks for the six compression shift selectors.
.setcpu "65816"
.segment "CODE"
.org $4C00
decompression_distance_masks:
    .byte $1F, $0F, $07, $03, $01, $00
