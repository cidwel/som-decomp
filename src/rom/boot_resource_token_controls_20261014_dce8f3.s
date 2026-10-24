.setcpu "65816"
.segment "CODE"
.org $E8F3
control_dce8f3:
    ; backreference count 14, distance 16
    .byte $AC, $0F
    ; backreference count 7, distance 1
    .byte $90, $00
    ; literal count 9; following payload excluded
    .byte $08
