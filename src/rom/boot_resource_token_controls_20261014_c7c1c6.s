.setcpu "65816"
.segment "CODE"
.org $C1C6
control_c7c1c6:
    ; backreference count 31, distance 1
    .byte $F0, $00
    ; literal count 14; following payload excluded
    .byte $0D
