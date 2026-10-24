.setcpu "65816"
.segment "CODE"
.org $F42F
control_dcf42f:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 28; following payload excluded
    .byte $1B
