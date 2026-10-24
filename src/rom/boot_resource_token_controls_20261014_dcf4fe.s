.setcpu "65816"
.segment "CODE"
.org $F4FE
control_dcf4fe:
    ; backreference count 43, distance 256
    .byte $A8, $FF
    ; literal count 6; following payload excluded
    .byte $05
