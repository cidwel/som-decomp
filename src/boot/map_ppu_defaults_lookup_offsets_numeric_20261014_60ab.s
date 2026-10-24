; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $60AB
control_parameters_60ab:
    .byte $00 ; default configuration byte for PPU register$212A
