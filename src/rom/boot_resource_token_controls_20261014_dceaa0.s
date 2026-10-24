.setcpu "65816"
.segment "CODE"
.org $EAA0
control_dceaa0:
    ; backreference count 8, distance 2
    .byte $94, $01
    ; literal count 22; following payload excluded
    .byte $15
