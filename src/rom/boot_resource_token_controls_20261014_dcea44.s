.setcpu "65816"
.segment "CODE"
.org $EA44
control_dcea44:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 8; following payload excluded
    .byte $07
