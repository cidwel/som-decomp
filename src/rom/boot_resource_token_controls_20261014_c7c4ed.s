.setcpu "65816"
.segment "CODE"
.org $C4ED
control_c7c4ed:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 3; following payload excluded
    .byte $02
