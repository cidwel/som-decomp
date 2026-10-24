; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6099
control_parameters_6099:
    .byte $80 ; default configuration byte for PPU register$2115
