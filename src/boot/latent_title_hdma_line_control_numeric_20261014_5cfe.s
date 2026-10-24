; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CFE
title_hdma_control_5cfe:
    .byte $08 ; no transfer/RGB/tile/text payload
