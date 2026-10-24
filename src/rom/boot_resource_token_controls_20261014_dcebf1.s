.setcpu "65816"
.segment "CODE"
.org $EBF1
control_dcebf1:
    ; backreference count 10, distance 32
    .byte $9C, $1F
    ; literal count 8; following payload excluded
    .byte $07
