.setcpu "65816"
.segment "CODE"
.org $EEA9
control_dceea9:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 23; following payload excluded
    .byte $16
