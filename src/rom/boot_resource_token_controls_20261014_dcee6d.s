.setcpu "65816"
.segment "CODE"
.org $EE6D
control_dcee6d:
    ; backreference count 6, distance 64
    .byte $8C, $3F
    ; literal count 13; following payload excluded
    .byte $0C
