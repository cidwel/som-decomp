.setcpu "65816"
.segment "CODE"
.org $C2F1
control_c7c2f1:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 1; following payload excluded
    .byte $00
