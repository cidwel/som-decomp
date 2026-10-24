; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6077
control_parameters_6077:
    .byte $00 ; default configuration byte for PPU register$2102
