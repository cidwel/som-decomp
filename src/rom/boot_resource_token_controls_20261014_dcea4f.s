.setcpu "65816"
.segment "CODE"
.org $EA4F
control_dcea4f:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 9; following payload excluded
    .byte $08
