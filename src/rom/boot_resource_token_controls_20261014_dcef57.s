.setcpu "65816"
.segment "CODE"
.org $EF57
control_dcef57:
    ; backreference count 4, distance 128
    .byte $84, $7F
    ; literal count 1; following payload excluded
    .byte $00
