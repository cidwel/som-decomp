; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $60BD
control_parameters_60bd:
    .byte $00 ; default configuration byte for PPU register$2133
