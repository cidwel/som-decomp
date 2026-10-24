; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D04
title_hdma_control_5d04:
    .byte $1F ; no transfer/RGB/tile/text payload
