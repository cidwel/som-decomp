.setcpu "65816"
.segment "CODE"
.org $EE67
control_dcee67:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 3; following payload excluded
    .byte $02
