.setcpu "65816"
.segment "CODE"
.org $C42B
control_c7c42b:
    ; backreference count 5, distance 604
    .byte $8A, $5B
    ; backreference count 8, distance 290
    .byte $95, $21
    ; literal count 16; following payload excluded
    .byte $0F
