.setcpu "65816"
.segment "CODE"
.org $EB7E
control_dceb7e:
    ; backreference count 4, distance 500
    .byte $85, $F3
    ; literal count 8; following payload excluded
    .byte $07
