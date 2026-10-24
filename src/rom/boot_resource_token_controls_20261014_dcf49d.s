.setcpu "65816"
.segment "CODE"
.org $F49D
control_dcf49d:
    ; backreference count 3, distance 30
    .byte $80, $1D
    ; literal count 8; following payload excluded
    .byte $07
