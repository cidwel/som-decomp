; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $6083
control_parameters_6083:
    .byte $00 ; default configuration byte for PPU register$210A
