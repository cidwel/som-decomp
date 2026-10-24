; initial HDMA line-count/repeat control; template7E5CC7, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CCA
title_hdma_control_5cca:
    .byte $08 ; no transfer/RGB/tile/text payload
