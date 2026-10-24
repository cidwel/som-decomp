; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5C99
title_hdma_control_5c99:
    .byte $61 ; no transfer/RGB/tile/text payload
