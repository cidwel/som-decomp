.setcpu "65816"
.segment "CODE"
.org $F2C5
control_dcf2c5:
    ; backreference count 130, distance 256
    .byte $FF, $FF
    ; backreference count 14, distance 1
    .byte $8B, $00
    ; literal count 15; following payload excluded
    .byte $0E
