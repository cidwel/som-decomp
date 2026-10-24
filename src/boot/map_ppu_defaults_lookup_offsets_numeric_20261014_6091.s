; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6091
control_parameters_6091:
    .byte $00 ; default configuration byte for PPU register$2111
