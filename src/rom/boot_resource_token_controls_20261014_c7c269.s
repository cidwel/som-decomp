.setcpu "65816"
.segment "CODE"
.org $C269
control_c7c269:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; backreference count 14, distance 32
    .byte $AC, $1F
    ; literal count 1; following payload excluded
    .byte $00
