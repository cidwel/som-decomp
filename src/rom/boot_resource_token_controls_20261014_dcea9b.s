.setcpu "65816"
.segment "CODE"
.org $EA9B
control_dcea9b:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 2; following payload excluded
    .byte $01
