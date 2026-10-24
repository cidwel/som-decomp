.setcpu "65816"
.segment "CODE"
.org $EA12
control_dcea12:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 21; following payload excluded
    .byte $14
