.setcpu "65816"
.segment "CODE"
.org $EAF5
control_dceaf5:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 10; following payload excluded
    .byte $09
