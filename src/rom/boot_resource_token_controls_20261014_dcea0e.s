.setcpu "65816"
.segment "CODE"
.org $EA0E
control_dcea0e:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 1; following payload excluded
    .byte $00
