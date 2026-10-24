.setcpu "65816"
.segment "CODE"
.org $EBD2
control_dcebd2:
    ; backreference count 6, distance 2
    .byte $8C, $01
    ; literal count 10; following payload excluded
    .byte $09
