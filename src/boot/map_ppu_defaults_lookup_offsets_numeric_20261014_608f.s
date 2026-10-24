; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $608F
control_parameters_608f:
    .byte $00 ; default configuration byte for PPU register$2110
