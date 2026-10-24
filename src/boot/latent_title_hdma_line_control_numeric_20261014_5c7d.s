; initial HDMA line-count/repeat control; template7E5C75, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C7D
title_hdma_control_5c7d:
    .byte $88 ; no transfer/RGB/tile/text payload
