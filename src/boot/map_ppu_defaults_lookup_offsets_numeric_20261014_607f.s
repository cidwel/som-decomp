; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $607F
control_parameters_607f:
    .byte $00 ; default configuration byte for PPU register$2108
