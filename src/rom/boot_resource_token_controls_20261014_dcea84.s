.setcpu "65816"
.segment "CODE"
.org $EA84
control_dcea84:
    ; backreference count 7, distance 2
    .byte $90, $01
    ; literal count 1; following payload excluded
    .byte $00
