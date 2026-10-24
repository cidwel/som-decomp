; initial HDMA line-count/repeat control; template7E5C53, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C5B
title_hdma_control_5c5b:
    .byte $10 ; no transfer/RGB/tile/text payload
