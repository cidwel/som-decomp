; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6087
control_parameters_6087:
    .byte $00 ; default configuration byte for PPU register$210C
