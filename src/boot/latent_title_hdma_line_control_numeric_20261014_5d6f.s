; initial HDMA line-count/repeat control; template7E5D6C, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D6F
title_hdma_control_5d6f:
    .byte $0F ; no transfer/RGB/tile/text payload
