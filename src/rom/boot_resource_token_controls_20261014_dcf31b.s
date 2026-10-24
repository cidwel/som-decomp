.setcpu "65816"
.segment "CODE"
.org $F31B
control_dcf31b:
    ; backreference count 16, distance 28
    .byte $8D, $1B
    ; literal count 11; following payload excluded
    .byte $0A
