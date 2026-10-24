; initial HDMA line-count/repeat control; template7E5D6C, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D72
title_hdma_control_5d72:
    .byte $08 ; no transfer/RGB/tile/text payload
