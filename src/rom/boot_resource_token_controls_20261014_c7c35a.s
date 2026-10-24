.setcpu "65816"
.segment "CODE"
.org $C35A
control_c7c35a:
    ; backreference count 3, distance 120
    .byte $80, $77
    ; literal count 1; following payload excluded
    .byte $00
