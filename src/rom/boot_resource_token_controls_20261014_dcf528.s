.setcpu "65816"
.segment "CODE"
.org $F528
control_dcf528:
    ; backreference count 4, distance 216
    .byte $81, $D7
    ; backreference count 30, distance 1
    .byte $9B, $00
    ; literal count 32; following payload excluded
    .byte $1F
