; initial HDMA line-count/repeat control; template7E5C93, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CB0
title_hdma_control_5cb0:
    .byte $28 ; no transfer/RGB/tile/text payload
