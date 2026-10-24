.setcpu "65816"
.segment "CODE"
.org $C245
control_c7c245:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 8; following payload excluded
    .byte $07
