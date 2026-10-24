.setcpu "65816"
.segment "CODE"
.org $EC84
control_dcec84:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 23; following payload excluded
    .byte $16
