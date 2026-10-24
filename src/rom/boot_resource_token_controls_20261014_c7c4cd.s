.setcpu "65816"
.segment "CODE"
.org $C4CD
control_c7c4cd:
    ; backreference count 4, distance 540
    .byte $86, $1B
    ; literal count 1; following payload excluded
    .byte $00
