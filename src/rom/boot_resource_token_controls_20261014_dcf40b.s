.setcpu "65816"
.segment "CODE"
.org $F40B
control_dcf40b:
    ; backreference count 4, distance 80
    .byte $81, $4F
    ; literal count 14; following payload excluded
    .byte $0D
