.setcpu "65816"
.segment "CODE"
.org $EC69
control_dcec69:
    ; backreference count 3, distance 128
    .byte $80, $7F
    ; literal count 16; following payload excluded
    .byte $0F
