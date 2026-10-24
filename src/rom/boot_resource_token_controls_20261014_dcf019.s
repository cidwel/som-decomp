.setcpu "65816"
.segment "CODE"
.org $F019
control_dcf019:
    ; backreference count 12, distance 16
    .byte $A4, $0F
    ; literal count 6; following payload excluded
    .byte $05
