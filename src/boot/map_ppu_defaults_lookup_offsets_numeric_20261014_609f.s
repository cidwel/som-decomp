; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $609F
control_parameters_609f:
    .byte $00 ; default configuration byte for PPU register$2124
