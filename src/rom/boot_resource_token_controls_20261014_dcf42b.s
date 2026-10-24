.setcpu "65816"
.segment "CODE"
.org $F42B
control_dcf42b:
    ; backreference count 16, distance 80
    .byte $8D, $4F
    ; literal count 1; following payload excluded
    .byte $00
