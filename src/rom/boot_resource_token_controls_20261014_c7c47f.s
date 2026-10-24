.setcpu "65816"
.segment "CODE"
.org $C47F
control_c7c47f:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; backreference count 3, distance 188
    .byte $80, $BB
    ; literal count 1; following payload excluded
    .byte $00
