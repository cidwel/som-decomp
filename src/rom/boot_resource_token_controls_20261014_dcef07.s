.setcpu "65816"
.segment "CODE"
.org $EF07
control_dcef07:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 17; following payload excluded
    .byte $10
