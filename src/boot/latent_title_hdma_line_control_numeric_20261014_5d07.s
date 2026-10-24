; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D07
title_hdma_control_5d07:
    .byte $88 ; no transfer/RGB/tile/text payload
