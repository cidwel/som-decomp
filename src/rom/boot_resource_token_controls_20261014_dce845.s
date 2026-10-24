.setcpu "65816"
.segment "CODE"
.org $E845
control_dce845:
    ; backreference count 15, distance 15
    .byte $B0, $0E
    ; backreference count 14, distance 16
    .byte $AC, $0F
    ; literal count 7; following payload excluded
    .byte $06
