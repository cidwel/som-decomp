.setcpu "65816"
.segment "CODE"
.org $EA78
control_dcea78:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 9; following payload excluded
    .byte $08
