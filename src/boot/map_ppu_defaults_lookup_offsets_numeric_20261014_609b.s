; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $609B
control_parameters_609b:
    .byte $00 ; default configuration byte for PPU register$211A
