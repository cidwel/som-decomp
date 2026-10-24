; initial HDMA line-count/repeat control; template7E5D86, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D89
title_hdma_control_5d89:
    .byte $0F ; no transfer/RGB/tile/text payload
