.setcpu "65816"
.segment "CODE"
.org $ECDF
control_dcecdf:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 16; following payload excluded
    .byte $0F
