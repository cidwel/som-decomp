; initial DMA transfer mode ->descriptor0; genuine selectors3/4.
.setcpu "65816"
.segment "RODATA"
.org $5EB7
transfer_control_5eb7:
    .byte $00, $00
