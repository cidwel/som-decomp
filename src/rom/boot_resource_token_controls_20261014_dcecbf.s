.setcpu "65816"
.segment "CODE"
.org $ECBF
control_dcecbf:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 19; following payload excluded
    .byte $12
