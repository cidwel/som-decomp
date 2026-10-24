.setcpu "65816"
.segment "CODE"
.org $ED6A
control_dced6a:
    ; backreference count 4, distance 1016
    .byte $87, $F7
    ; literal count 10; following payload excluded
    .byte $09
