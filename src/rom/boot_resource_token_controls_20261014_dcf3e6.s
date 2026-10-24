.setcpu "65816"
.segment "CODE"
.org $F3E6
control_dcf3e6:
    ; backreference count 16, distance 239
    .byte $8D, $EE
    ; backreference count 17, distance 1
    .byte $8E, $00
    ; backreference count 48, distance 152
    .byte $AD, $97
    ; literal count 30; following payload excluded
    .byte $1D
