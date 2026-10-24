.setcpu "65816"
.segment "CODE"
.org $ED77
control_dced77:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 8; following payload excluded
    .byte $07
