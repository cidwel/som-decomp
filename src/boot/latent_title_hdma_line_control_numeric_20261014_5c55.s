; initial HDMA line-count/repeat control; template7E5C53, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C55
title_hdma_control_5c55:
    .byte $08 ; no transfer/RGB/tile/text payload
