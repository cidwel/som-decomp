; initial HDMA line-count/repeat control; template7E5D63, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5D63
title_hdma_control_5d63:
    .byte $78 ; no transfer/RGB/tile/text payload
