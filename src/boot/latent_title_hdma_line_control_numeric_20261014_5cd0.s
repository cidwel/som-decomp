; initial HDMA line-count/repeat control; template7E5CC7, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CD0
title_hdma_control_5cd0:
    .byte $1F ; no transfer/RGB/tile/text payload
