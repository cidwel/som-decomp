; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $60AF
control_parameters_60af:
    .byte $00 ; default configuration byte for PPU register$212C
