.setcpu "65816"
.segment "CODE"
.org $C4B4
control_c7c4b4:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 1; following payload excluded
    .byte $00
