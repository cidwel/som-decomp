.setcpu "65816"
.segment "CODE"
.org $C261
control_c7c261:
    ; backreference count 9, distance 32
    .byte $98, $1F
    ; literal count 1; following payload excluded
    .byte $00
