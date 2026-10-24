.setcpu "65816"
.segment "CODE"
.org $EE63
control_dcee63:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; literal count 1; following payload excluded
    .byte $00
