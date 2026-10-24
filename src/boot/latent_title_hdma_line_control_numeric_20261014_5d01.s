; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D01
title_hdma_control_5d01:
    .byte $61 ; no transfer/RGB/tile/text payload
