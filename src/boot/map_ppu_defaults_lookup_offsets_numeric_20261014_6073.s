; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6073
control_parameters_6073:
    .byte $8F ; default configuration byte for PPU register$2100
