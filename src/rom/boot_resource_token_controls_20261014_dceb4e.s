.setcpu "65816"
.segment "CODE"
.org $EB4E
control_dceb4e:
    ; backreference count 7, distance 2
    .byte $90, $01
    ; literal count 8; following payload excluded
    .byte $07
