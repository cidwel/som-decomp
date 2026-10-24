.setcpu "65816"
.segment "CODE"
.org $ED8C
control_dced8c:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 1; following payload excluded
    .byte $00
