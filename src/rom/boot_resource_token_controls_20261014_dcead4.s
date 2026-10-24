.setcpu "65816"
.segment "CODE"
.org $EAD4
control_dcead4:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 30; following payload excluded
    .byte $1D
