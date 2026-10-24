.setcpu "65816"
.segment "CODE"
.org $F471
control_dcf471:
    ; backreference count 33, distance 241
    .byte $9E, $F0
    ; backreference count 63, distance 256
    .byte $BC, $FF
    ; backreference count 16, distance 1
    .byte $8D, $00
    ; literal count 9; following payload excluded
    .byte $08
