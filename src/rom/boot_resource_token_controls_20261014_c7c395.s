.setcpu "65816"
.segment "CODE"
.org $C395
control_c7c395:
    ; backreference count 7, distance 64
    .byte $90, $3F
    ; literal count 10; following payload excluded
    .byte $09
