.setcpu "65816"
.segment "CODE"
.org $F60D
control_dcf60d:
    ; backreference count 3, distance 149
    .byte $80, $94
    ; backreference count 30, distance 1
    .byte $9B, $00
    ; literal count 4; following payload excluded
    .byte $03
