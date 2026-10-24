.setcpu "65816"
.segment "CODE"
.org $EBFC
control_dcebfc:
    ; backreference count 8, distance 2
    .byte $94, $01
    ; literal count 3; following payload excluded
    .byte $02
