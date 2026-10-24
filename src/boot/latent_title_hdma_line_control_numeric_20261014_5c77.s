; initial HDMA line-count/repeat control; template7E5C75, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C77
title_hdma_control_5c77:
    .byte $08 ; no transfer/RGB/tile/text payload
