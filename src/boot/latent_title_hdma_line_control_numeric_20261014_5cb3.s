; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CB3
title_hdma_control_5cb3:
    .byte $89 ; no transfer/RGB/tile/text payload
