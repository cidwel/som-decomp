.setcpu "65816"
.segment "CODE"
.org $EA88
control_dcea88:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; backreference count 4, distance 504
    .byte $85, $F7
    ; literal count 14; following payload excluded
    .byte $0D
