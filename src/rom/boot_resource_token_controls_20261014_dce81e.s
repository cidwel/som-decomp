.setcpu "65816"
.segment "CODE"
.org $E81E
control_dce81e:
    ; backreference count 7, distance 32
    .byte $90, $1F
    ; literal count 7; following payload excluded
    .byte $06
