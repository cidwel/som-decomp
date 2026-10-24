.setcpu "65816"
.segment "CODE"
.org $F782
control_dcf782:
    ; backreference count 16, distance 25
    .byte $8D, $18
    ; backreference count 7, distance 1
    .byte $84, $00
    ; literal count 16; following payload excluded
    .byte $0F
