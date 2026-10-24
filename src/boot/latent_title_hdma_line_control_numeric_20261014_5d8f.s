; initial HDMA line-count/repeat control; template7E5D86, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D8F
title_hdma_control_5d8f:
    .byte $01 ; no transfer/RGB/tile/text payload
