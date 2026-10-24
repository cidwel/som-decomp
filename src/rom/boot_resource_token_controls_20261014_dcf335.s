.setcpu "65816"
.segment "CODE"
.org $F335
control_dcf335:
    ; backreference count 7, distance 16
    .byte $84, $0F
    ; literal count 9; following payload excluded
    .byte $08
