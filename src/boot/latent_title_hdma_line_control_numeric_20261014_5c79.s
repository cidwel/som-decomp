; initial HDMA line-count/repeat control; template7E5C75, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C79
title_hdma_control_5c79:
    .byte $61 ; no transfer/RGB/tile/text payload
