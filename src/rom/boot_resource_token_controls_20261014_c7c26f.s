.setcpu "65816"
.segment "CODE"
.org $C26F
control_c7c26f:
    ; backreference count 5, distance 128
    .byte $88, $7F
    ; literal count 12; following payload excluded
    .byte $0B
