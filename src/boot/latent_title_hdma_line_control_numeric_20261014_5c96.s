; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5C96
title_hdma_control_5c96:
    .byte $08 ; no transfer/RGB/tile/text payload
