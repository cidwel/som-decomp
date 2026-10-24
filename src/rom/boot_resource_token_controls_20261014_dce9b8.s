.setcpu "65816"
.segment "CODE"
.org $E9B8
control_dce9b8:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 16; following payload excluded
    .byte $0F
