.setcpu "65816"
.segment "CODE"
.org $EF86
control_dcef86:
    ; backreference count 5, distance 180
    .byte $88, $B3
    ; backreference count 4, distance 96
    .byte $84, $5F
    ; literal count 1; following payload excluded
    .byte $00
