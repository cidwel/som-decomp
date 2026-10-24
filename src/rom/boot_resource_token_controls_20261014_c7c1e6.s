.setcpu "65816"
.segment "CODE"
.org $C1E6
control_c7c1e6:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 14; following payload excluded
    .byte $0D
