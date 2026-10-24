; initial HDMA line-count/repeat control; template7E5D63, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5D67
title_hdma_control_5d67:
    .byte $08 ; no transfer/RGB/tile/text payload
