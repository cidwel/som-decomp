.setcpu "65816"
.segment "CODE"
.org $E92D
control_dce92d:
    ; backreference count 6, distance 2
    .byte $8C, $01
    ; literal count 3; following payload excluded
    .byte $02
