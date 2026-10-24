.setcpu "65816"
.segment "CODE"
.org $EFDF
control_dcefdf:
    ; backreference count 4, distance 118
    .byte $84, $75
    ; literal count 1; following payload excluded
    .byte $00
