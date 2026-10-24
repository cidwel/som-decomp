; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5C9C
title_hdma_control_5c9c:
    .byte $1F ; no transfer/RGB/tile/text payload
