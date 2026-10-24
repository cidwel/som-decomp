.setcpu "65816"
.segment "CODE"
.org $F6A0
control_dcf6a0:
    ; backreference count 4, distance 70
    .byte $81, $45
    ; literal count 2; following payload excluded
    .byte $01
