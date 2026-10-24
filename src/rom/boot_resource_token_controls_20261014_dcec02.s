.setcpu "65816"
.segment "CODE"
.org $EC02
control_dcec02:
    ; backreference count 3, distance 574
    .byte $82, $3D
    ; backreference count 4, distance 228
    .byte $84, $E3
    ; backreference count 6, distance 2
    .byte $8C, $01
    ; literal count 9; following payload excluded
    .byte $08
