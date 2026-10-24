.setcpu "65816"
.segment "CODE"
.org $EF8C
control_dcef8c:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 1; following payload excluded
    .byte $00
