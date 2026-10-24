.setcpu "65816"
.segment "CODE"
.org $F6F2
control_dcf6f2:
    ; backreference count 3, distance 48
    .byte $80, $2F
    ; literal count 15; following payload excluded
    .byte $0E
