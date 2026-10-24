; initial HDMA line-count/repeat control; template7E5D79, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D7F
title_hdma_control_5d7f:
    .byte $08 ; no transfer/RGB/tile/text payload
