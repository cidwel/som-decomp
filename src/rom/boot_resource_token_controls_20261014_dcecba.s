.setcpu "65816"
.segment "CODE"
.org $ECBA
control_dcecba:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 2; following payload excluded
    .byte $01
