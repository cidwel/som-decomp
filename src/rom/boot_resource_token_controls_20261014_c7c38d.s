.setcpu "65816"
.segment "CODE"
.org $C38D
control_c7c38d:
    ; backreference count 3, distance 196
    .byte $80, $C3
    ; literal count 1; following payload excluded
    .byte $00
