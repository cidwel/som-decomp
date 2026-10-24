; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6085
control_parameters_6085:
    .byte $00 ; default configuration byte for PPU register$210B
