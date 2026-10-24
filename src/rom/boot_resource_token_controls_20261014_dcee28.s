.setcpu "65816"
.segment "CODE"
.org $EE28
control_dcee28:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; literal count 1; following payload excluded
    .byte $00
