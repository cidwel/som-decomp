.setcpu "65816"
.segment "CODE"
.org $C35E
control_c7c35e:
    ; backreference count 3, distance 220
    .byte $80, $DB
    ; literal count 1; following payload excluded
    .byte $00
