.setcpu "65816"
.segment "CODE"
.org $F29F
control_dcf29f:
    ; backreference count 7, distance 16
    .byte $84, $0F
    ; backreference count 5, distance 181
    .byte $82, $B4
    ; literal count 10; following payload excluded
    .byte $09
