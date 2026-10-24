; initial HDMA line-count/repeat control; template7E5C64, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C6C
title_hdma_control_5c6c:
    .byte $08 ; no transfer/RGB/tile/text payload
