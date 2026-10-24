.setcpu "65816"
.segment "CODE"
.org $EDC0
control_dcedc0:
    ; backreference count 3, distance 1012
    .byte $83, $F3
    ; literal count 1; following payload excluded
    .byte $00
