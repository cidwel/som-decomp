.setcpu "65816"
.segment "CODE"
.org $ED1B
control_dced1b:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; backreference count 4, distance 1014
    .byte $87, $F5
    ; literal count 10; following payload excluded
    .byte $09
