.setcpu "65816"
.segment "CODE"
.org $C410
control_c7c410:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 3; following payload excluded
    .byte $02
