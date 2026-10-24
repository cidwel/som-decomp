.setcpu "65816"
.segment "CODE"
.org $C48B
control_c7c48b:
    ; backreference count 29, distance 16
    .byte $E8, $0F
    ; literal count 6; following payload excluded
    .byte $05
