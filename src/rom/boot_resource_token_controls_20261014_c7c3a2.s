.setcpu "65816"
.segment "CODE"
.org $C3A2
control_c7c3a2:
    ; backreference count 6, distance 64
    .byte $8C, $3F
    ; literal count 1; following payload excluded
    .byte $00
