.setcpu "65816"
.segment "CODE"
.org $C3A6
control_c7c3a6:
    ; backreference count 5, distance 64
    .byte $88, $3F
    ; backreference count 6, distance 320
    .byte $8D, $3F
    ; literal count 14; following payload excluded
    .byte $0D
