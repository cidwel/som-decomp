.setcpu "65816"
.segment "CODE"
.org $C216
control_c7c216:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 7; following payload excluded
    .byte $06
