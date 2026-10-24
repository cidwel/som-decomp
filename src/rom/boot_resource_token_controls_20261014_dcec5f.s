.setcpu "65816"
.segment "CODE"
.org $EC5F
control_dcec5f:
    ; backreference count 3, distance 248
    .byte $80, $F7
    ; literal count 1; following payload excluded
    .byte $00
