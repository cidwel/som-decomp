.setcpu "65816"
.segment "CODE"
.org $C1D7
control_c7c1d7:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 12; following payload excluded
    .byte $0B
