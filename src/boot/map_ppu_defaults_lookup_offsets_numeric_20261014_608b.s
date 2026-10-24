; Original numeric control parameters, no actual colour/pixel payload.
.setcpu "65816"
.segment "RODATA"
.org $608B
control_parameters_608b:
    .byte $00 ; default configuration byte for PPU register$210E
