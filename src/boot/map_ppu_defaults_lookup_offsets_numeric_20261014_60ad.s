; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $60AD
control_parameters_60ad:
    .byte $00 ; default configuration byte for PPU register$212B
