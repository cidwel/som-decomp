.setcpu "65816"
.segment "CODE"
.org $EC2D
control_dcec2d:
    ; backreference count 6, distance 502
    .byte $8D, $F5
    ; backreference count 8, distance 2
    .byte $94, $01
    ; literal count 19; following payload excluded
    .byte $12
