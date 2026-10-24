.setcpu "65816"
.segment "CODE"
.org $E9F2
control_dce9f2:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 21; following payload excluded
    .byte $14
