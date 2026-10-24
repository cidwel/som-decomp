.setcpu "65816"
.segment "CODE"
.org $EBAC
control_dcebac:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; literal count 35; following payload excluded
    .byte $22
