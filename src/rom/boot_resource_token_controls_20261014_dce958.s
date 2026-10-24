.setcpu "65816"
.segment "CODE"
.org $E958
control_dce958:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 20; following payload excluded
    .byte $13
