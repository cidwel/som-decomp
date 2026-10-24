.setcpu "65816"
.segment "CODE"
.org $F481
control_dcf481:
    ; backreference count 5, distance 156
    .byte $82, $9B
    ; literal count 25; following payload excluded
    .byte $18
