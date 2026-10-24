; initial HDMA line-count/repeat control; template7E5CFB, directmode2.
.setcpu "65816"
.segment "RODATA"
.org $5CFB
title_hdma_control_5cfb:
    .byte $0F ; no transfer/RGB/tile/text payload
