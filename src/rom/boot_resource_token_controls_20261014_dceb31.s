.setcpu "65816"
.segment "CODE"
.org $EB31
control_dceb31:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 11; following payload excluded
    .byte $0A
