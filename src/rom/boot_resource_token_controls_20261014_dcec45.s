.setcpu "65816"
.segment "CODE"
.org $EC45
control_dcec45:
    ; backreference count 3, distance 700
    .byte $82, $BB
    ; backreference count 6, distance 2
    .byte $8C, $01
    ; literal count 1; following payload excluded
    .byte $00
