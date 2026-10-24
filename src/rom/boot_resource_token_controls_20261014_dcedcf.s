.setcpu "65816"
.segment "CODE"
.org $EDCF
control_dcedcf:
    ; backreference count 9, distance 506
    .byte $99, $F9
    ; literal count 1; following payload excluded
    .byte $00
