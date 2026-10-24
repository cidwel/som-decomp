.setcpu "65816"
.segment "CODE"
.org $F468
control_dcf468:
    ; backreference count 3, distance 202
    .byte $80, $C9
    ; literal count 6; following payload excluded
    .byte $05
