.setcpu "65816"
.segment "CODE"
.org $C2D1
control_c7c2d1:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 1; following payload excluded
    .byte $00
