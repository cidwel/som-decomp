; initial HDMA line-count/repeat control; template7E5D6C, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D75
title_hdma_control_5d75:
    .byte $01 ; no transfer/RGB/tile/text payload
