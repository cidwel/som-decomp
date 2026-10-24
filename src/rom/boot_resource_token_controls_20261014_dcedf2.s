.setcpu "65816"
.segment "CODE"
.org $EDF2
control_dcedf2:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 1; following payload excluded
    .byte $00
