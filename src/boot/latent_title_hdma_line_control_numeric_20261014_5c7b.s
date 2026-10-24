; initial HDMA line-count/repeat control; template7E5C75, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C7B
title_hdma_control_5c7b:
    .byte $1F ; no transfer/RGB/tile/text payload
