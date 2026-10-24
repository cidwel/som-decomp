; initial HDMA line-count/repeat control; template7E5C53, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C59
title_hdma_control_5c59:
    .byte $17 ; no transfer/RGB/tile/text payload
