.setcpu "65816"
.segment "CODE"
.org $F54D
control_dcf54d:
    ; backreference count 33, distance 161
    .byte $9E, $A0
    ; backreference count 95, distance 1
    .byte $DC, $00
    ; literal count 16; following payload excluded
    .byte $0F
