; initial HDMA line-count/repeat control; template7E5C53, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C53
title_hdma_control_5c53:
    .byte $0F ; no transfer/RGB/tile/text payload
