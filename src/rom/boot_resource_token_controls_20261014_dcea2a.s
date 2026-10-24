.setcpu "65816"
.segment "CODE"
.org $EA2A
control_dcea2a:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 5; following payload excluded
    .byte $04
