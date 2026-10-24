.setcpu "65816"
.segment "CODE"
.org $E9D7
control_dce9d7:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 2; following payload excluded
    .byte $01
