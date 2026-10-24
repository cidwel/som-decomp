.setcpu "65816"
.segment "CODE"
.org $F5F0
control_dcf5f0:
    ; backreference count 5, distance 110
    .byte $82, $6D
    ; literal count 16; following payload excluded
    .byte $0F
