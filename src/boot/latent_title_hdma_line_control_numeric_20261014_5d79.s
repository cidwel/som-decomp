; initial HDMA line-count/repeat control; template7E5D79, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D79
title_hdma_control_5d79:
    .byte $78 ; no transfer/RGB/tile/text payload
