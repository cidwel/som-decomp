; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5C93
title_hdma_control_5c93:
    .byte $0F ; no transfer/RGB/tile/text payload
