.setcpu "65816"
.segment "CODE"
.org $F507
control_dcf507:
    ; backreference count 16, distance 224
    .byte $8D, $DF
    ; literal count 30; following payload excluded
    .byte $1D
