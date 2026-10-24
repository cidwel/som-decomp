.setcpu "65816"
.segment "CODE"
.org $EEDF
control_dceedf:
    ; backreference count 3, distance 22
    .byte $80, $15
    ; literal count 7; following payload excluded
    .byte $06
