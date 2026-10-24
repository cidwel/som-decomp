; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $60B7
control_parameters_60b7:
    .byte $30 ; default configuration byte for PPU register$2130
