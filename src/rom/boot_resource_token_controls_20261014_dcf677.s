.setcpu "65816"
.segment "CODE"
.org $F677
control_dcf677:
    ; backreference count 17, distance 32
    .byte $8E, $1F
    ; literal count 13; following payload excluded
    .byte $0C
