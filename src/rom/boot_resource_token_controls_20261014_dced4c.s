.setcpu "65816"
.segment "CODE"
.org $ED4C
control_dced4c:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; backreference count 4, distance 608
    .byte $86, $5F
    ; literal count 8; following payload excluded
    .byte $07
