.setcpu "65816"
.segment "CODE"
.org $C45D
control_c7c45d:
    ; backreference count 4, distance 32
    .byte $84, $1F
    ; literal count 1; following payload excluded
    .byte $00
