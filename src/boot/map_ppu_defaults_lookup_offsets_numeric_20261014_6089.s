; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6089
control_parameters_6089:
    .byte $00 ; default configuration byte for PPU register$210D
