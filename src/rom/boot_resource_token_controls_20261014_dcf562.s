.setcpu "65816"
.segment "CODE"
.org $F562
control_dcf562:
    ; backreference count 16, distance 192
    .byte $8D, $BF
    ; literal count 32; following payload excluded
    .byte $1F
