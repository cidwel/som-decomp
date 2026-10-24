.setcpu "65816"
.segment "CODE"
.org $EF40
control_dcef40:
    ; backreference count 3, distance 36
    .byte $80, $23
    ; literal count 1; following payload excluded
    .byte $00
