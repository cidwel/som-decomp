.setcpu "65816"
.segment "CODE"
.org $EC28
control_dcec28:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 2; following payload excluded
    .byte $01
