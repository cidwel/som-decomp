.setcpu "65816"
.segment "CODE"
.org $E9EB
control_dce9eb:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 4; following payload excluded
    .byte $03
