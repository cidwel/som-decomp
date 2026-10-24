; initial HDMA line-count/repeat control; template7E5CC7, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CC7
title_hdma_control_5cc7:
    .byte $0F ; no transfer/RGB/tile/text payload
