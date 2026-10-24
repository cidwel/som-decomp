.setcpu "65816"
.segment "CODE"
.org $F5A0
control_dcf5a0:
    ; backreference count 3, distance 3
    .byte $80, $02
    ; literal count 77; following payload excluded
    .byte $4C
