.setcpu "65816"
.segment "CODE"
.org $C3E0
control_c7c3e0:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; backreference count 3, distance 400
    .byte $81, $8F
    ; literal count 2; following payload excluded
    .byte $01
