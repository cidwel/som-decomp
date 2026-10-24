.setcpu "65816"
.segment "CODE"
.org $EFC8
control_dcefc8:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; backreference count 4, distance 30
    .byte $84, $1D
    ; literal count 18; following payload excluded
    .byte $11
