.setcpu "65816"
.segment "CODE"
.org $EEE9
control_dceee9:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 21; following payload excluded
    .byte $14
