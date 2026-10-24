.setcpu "65816"
.segment "CODE"
.org $E9E4
control_dce9e4:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 4; following payload excluded
    .byte $03
