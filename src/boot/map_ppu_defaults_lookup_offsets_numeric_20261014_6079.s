; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6079
control_parameters_6079:
    .byte $09 ; default configuration byte for PPU register$2105
