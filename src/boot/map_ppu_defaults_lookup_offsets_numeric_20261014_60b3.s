; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $60B3
control_parameters_60b3:
    .byte $00 ; default configuration byte for PPU register$212E
