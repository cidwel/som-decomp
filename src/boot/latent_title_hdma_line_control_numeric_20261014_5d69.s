; initial HDMA line-count/repeat control; template7E5D63, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5D69
title_hdma_control_5d69:
    .byte $01 ; no transfer/RGB/tile/text payload
