.setcpu "65816"
.segment "CODE"
.org $C1F7
control_c7c1f7:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 2; following payload excluded
    .byte $01
