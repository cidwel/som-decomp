.setcpu "65816"
.segment "CODE"
.org $ED0F
control_dced0f:
    ; backreference count 4, distance 1014
    .byte $87, $F5
    ; literal count 1; following payload excluded
    .byte $00
