.setcpu "65816"
.segment "CODE"
.org $C265
control_c7c265:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 1; following payload excluded
    .byte $00
