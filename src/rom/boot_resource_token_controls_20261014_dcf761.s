.setcpu "65816"
.segment "CODE"
.org $F761
control_dcf761:
    ; backreference count 4, distance 36
    .byte $81, $23
    ; literal count 12; following payload excluded
    .byte $0B
