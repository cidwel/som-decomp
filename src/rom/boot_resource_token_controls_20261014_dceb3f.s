.setcpu "65816"
.segment "CODE"
.org $EB3F
control_dceb3f:
    ; backreference count 3, distance 8
    .byte $80, $07
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 6; following payload excluded
    .byte $05
