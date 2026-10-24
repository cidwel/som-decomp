.setcpu "65816"
.segment "CODE"
.org $F3B8
control_dcf3b8:
    ; backreference count 20, distance 28
    .byte $91, $1B
    ; literal count 43; following payload excluded
    .byte $2A
