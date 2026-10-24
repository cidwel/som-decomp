; initial HDMA line-count/repeat control; template7E5D79, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D7C
title_hdma_control_5d7c:
    .byte $0F ; no transfer/RGB/tile/text payload
