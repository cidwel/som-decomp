.setcpu "65816"
.segment "CODE"
.org $F022
control_dcf022:
    ; backreference count 4, distance 8
    .byte $84, $07
    ; literal count 4; following payload excluded
    .byte $03
