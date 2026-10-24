; initial DMA transfer mode ->descriptor0; genuine selectors0/1.
.setcpu "65816"
.segment "RODATA"
.org $5EB4
transfer_control_5eb4:
    .byte $01, $00
