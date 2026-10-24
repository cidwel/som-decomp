.setcpu "65816"
.segment "CODE"
.org $F4DE
control_dcf4de:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 3; following payload excluded
    .byte $02
