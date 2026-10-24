; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6093
control_parameters_6093:
    .byte $00 ; default configuration byte for PPU register$2112
