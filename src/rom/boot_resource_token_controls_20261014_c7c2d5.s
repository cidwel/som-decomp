.setcpu "65816"
.segment "CODE"
.org $C2D5
control_c7c2d5:
    ; backreference count 3, distance 190
    .byte $80, $BD
    ; literal count 1; following payload excluded
    .byte $00
