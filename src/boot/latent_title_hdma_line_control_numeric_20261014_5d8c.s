; initial HDMA line-count/repeat control; template7E5D86, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D8C
title_hdma_control_5d8c:
    .byte $08 ; no transfer/RGB/tile/text payload
