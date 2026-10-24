.setcpu "65816"
.segment "CODE"
.org $F687
control_dcf687:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 22; following payload excluded
    .byte $15
