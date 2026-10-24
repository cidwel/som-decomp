; initial HDMA line-count/repeat control; template7E5D63, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5D65
title_hdma_control_5d65:
    .byte $0F ; no transfer/RGB/tile/text payload
