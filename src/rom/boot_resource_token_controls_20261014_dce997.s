.setcpu "65816"
.segment "CODE"
.org $E997
control_dce997:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 30; following payload excluded
    .byte $1D
