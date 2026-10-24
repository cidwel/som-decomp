.setcpu "65816"
.segment "CODE"
.org $F4BE
control_dcf4be:
    ; backreference count 24, distance 160
    .byte $95, $9F
    ; literal count 29; following payload excluded
    .byte $1C
