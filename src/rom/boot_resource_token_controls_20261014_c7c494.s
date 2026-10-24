.setcpu "65816"
.segment "CODE"
.org $C494
control_c7c494:
    ; backreference count 10, distance 16
    .byte $9C, $0F
    ; literal count 3; following payload excluded
    .byte $02
