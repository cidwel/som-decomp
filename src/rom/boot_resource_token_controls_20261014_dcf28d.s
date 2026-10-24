.setcpu "65816"
.segment "CODE"
.org $F28D
control_dcf28d:
    ; backreference count 34, distance 210
    .byte $9F, $D1
    ; backreference count 46, distance 1
    .byte $AB, $00
    ; backreference count 130, distance 226
    .byte $FF, $E1
    ; backreference count 30, distance 1
    .byte $9B, $00
    ; literal count 9; following payload excluded
    .byte $08
