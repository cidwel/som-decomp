.setcpu "65816"
.segment "CODE"
.org $C389
control_c7c389:
    ; backreference count 4, distance 16
    .byte $84, $0F
    ; literal count 1; following payload excluded
    .byte $00
