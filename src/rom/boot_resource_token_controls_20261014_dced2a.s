.setcpu "65816"
.segment "CODE"
.org $ED2A
control_dced2a:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; literal count 1; following payload excluded
    .byte $00
