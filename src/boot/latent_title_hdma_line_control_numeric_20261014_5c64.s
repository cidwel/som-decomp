; initial HDMA line-count/repeat control; template7E5C64, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C64
title_hdma_control_5c64:
    .byte $0F ; no transfer/RGB/tile/text payload
