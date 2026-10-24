.setcpu "65816"
.segment "CODE"
.org $EBEA
control_dcebea:
    ; backreference count 10, distance 2
    .byte $9C, $01
    ; literal count 4; following payload excluded
    .byte $03
