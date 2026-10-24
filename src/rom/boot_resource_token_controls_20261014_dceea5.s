.setcpu "65816"
.segment "CODE"
.org $EEA5
control_dceea5:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 1; following payload excluded
    .byte $00
