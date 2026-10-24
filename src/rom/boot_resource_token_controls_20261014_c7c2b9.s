.setcpu "65816"
.segment "CODE"
.org $C2B9
control_c7c2b9:
    ; backreference count 7, distance 2
    .byte $90, $01
    ; literal count 1; following payload excluded
    .byte $00
