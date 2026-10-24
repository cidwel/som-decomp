.setcpu "65816"
.segment "CODE"
.org $C440
control_c7c440:
    ; backreference count 4, distance 512
    .byte $85, $FF
    ; literal count 1; following payload excluded
    .byte $00
