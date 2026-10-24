.setcpu "65816"
.segment "CODE"
.org $C2D9
control_c7c2d9:
    ; backreference count 5, distance 32
    .byte $88, $1F
    ; literal count 15; following payload excluded
    .byte $0E
