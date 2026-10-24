; initial HDMA line-count/repeat control; template7E5CC7, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CE4
title_hdma_control_5ce4:
    .byte $28 ; no transfer/RGB/tile/text payload
