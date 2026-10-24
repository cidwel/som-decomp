.setcpu "65816"
.segment "CODE"
.org $F001
control_dcf001:
    ; backreference count 3, distance 188
    .byte $80, $BB
    ; literal count 13; following payload excluded
    .byte $0C
