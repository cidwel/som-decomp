; initial HDMA line-count/repeat control; template7E5D86, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D86
title_hdma_control_5d86:
    .byte $78 ; no transfer/RGB/tile/text payload
