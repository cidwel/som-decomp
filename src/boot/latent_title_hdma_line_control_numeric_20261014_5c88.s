; initial HDMA line-count/repeat control; template7E5C75, directmode0.
.setcpu "65816"
.segment "RODATA"
.org $5C88
title_hdma_control_5c88:
    .byte $89 ; no transfer/RGB/tile/text payload
