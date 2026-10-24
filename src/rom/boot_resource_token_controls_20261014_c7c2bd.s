.setcpu "65816"
.segment "CODE"
.org $C2BD
control_c7c2bd:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 13; following payload excluded
    .byte $0C
