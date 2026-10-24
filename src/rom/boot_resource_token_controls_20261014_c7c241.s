.setcpu "65816"
.segment "CODE"
.org $C241
control_c7c241:
    ; backreference count 3, distance 64
    .byte $80, $3F
    ; literal count 1; following payload excluded
    .byte $00
