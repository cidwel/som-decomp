; initial HDMA line-count/repeat control; template7E5CC7, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CD3
title_hdma_control_5cd3:
    .byte $88 ; no transfer/RGB/tile/text payload
