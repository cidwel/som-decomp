; initial HDMA line-count/repeat control; template7E5C53, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C61
title_hdma_control_5c61:
    .byte $01 ; no transfer/RGB/tile/text payload
