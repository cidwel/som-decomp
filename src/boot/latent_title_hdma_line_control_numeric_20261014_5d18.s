; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5D18
title_hdma_control_5d18:
    .byte $28 ; no transfer/RGB/tile/text payload
