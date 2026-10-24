; initial Bbus register ->descriptor1; genuine selectors3/4.
.setcpu "65816"
.segment "RODATA"
.org $5EC1
transfer_control_5ec1:
    .byte $04, $2C
