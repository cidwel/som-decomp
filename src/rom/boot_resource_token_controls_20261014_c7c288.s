.setcpu "65816"
.segment "CODE"
.org $C288
control_c7c288:
    ; backreference count 5, distance 128
    .byte $88, $7F
    ; literal count 11; following payload excluded
    .byte $0A
