.setcpu "65816"
.segment "CODE"
.org $F3AD
control_dcf3ad:
    ; backreference count 72, distance 184
    .byte $C5, $B7
    ; literal count 8; following payload excluded
    .byte $07
