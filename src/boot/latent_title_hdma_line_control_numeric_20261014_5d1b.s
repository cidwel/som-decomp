; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D1B
title_hdma_control_5d1b:
    .byte $89 ; no transfer/RGB/tile/text payload
