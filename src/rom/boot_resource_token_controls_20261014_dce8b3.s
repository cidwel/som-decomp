.setcpu "65816"
.segment "CODE"
.org $E8B3
control_dce8b3:
    ; backreference count 13, distance 16
    .byte $A8, $0F
    ; backreference count 9, distance 412
    .byte $99, $9B
    ; literal count 7; following payload excluded
    .byte $06
