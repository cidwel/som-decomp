; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5C9F
title_hdma_control_5c9f:
    .byte $88 ; no transfer/RGB/tile/text payload
