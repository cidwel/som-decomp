.setcpu "65816"
.segment "CODE"
.org $C2EB
control_c7c2eb:
    ; backreference count 3, distance 220
    .byte $80, $DB
    ; backreference count 4, distance 286
    .byte $85, $1D
    ; literal count 1; following payload excluded
    .byte $00
