.setcpu "65816"
.segment "CODE"
.org $C204
control_c7c204:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 15; following payload excluded
    .byte $0E
