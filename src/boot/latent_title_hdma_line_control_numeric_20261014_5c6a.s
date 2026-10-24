; initial HDMA line-count/repeat control; template7E5C64, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C6A
title_hdma_control_5c6a:
    .byte $1F ; no transfer/RGB/tile/text payload
