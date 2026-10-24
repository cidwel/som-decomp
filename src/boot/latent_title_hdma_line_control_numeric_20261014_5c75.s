; initial HDMA line-count/repeat control; template7E5C75, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C75
title_hdma_control_5c75:
    .byte $0F ; no transfer/RGB/tile/text payload
