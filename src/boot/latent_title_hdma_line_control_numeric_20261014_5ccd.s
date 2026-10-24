; initial HDMA line-count/repeat control; template7E5CC7, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CCD
title_hdma_control_5ccd:
    .byte $61 ; no transfer/RGB/tile/text payload
