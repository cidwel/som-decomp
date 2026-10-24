.setcpu "65816"
.segment "CODE"
.org $ECA2
control_dceca2:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 14; following payload excluded
    .byte $0D
