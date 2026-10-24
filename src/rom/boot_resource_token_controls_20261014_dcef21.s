.setcpu "65816"
.segment "CODE"
.org $EF21
control_dcef21:
    ; backreference count 3, distance 30
    .byte $80, $1D
    ; literal count 3; following payload excluded
    .byte $02
