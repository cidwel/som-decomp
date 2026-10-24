.setcpu "65816"
.segment "CODE"
.org $EBDF
control_dcebdf:
    ; backreference count 8, distance 2
    .byte $94, $01
    ; literal count 8; following payload excluded
    .byte $07
