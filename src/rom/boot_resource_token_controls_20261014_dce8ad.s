.setcpu "65816"
.segment "CODE"
.org $E8AD
control_dce8ad:
    ; backreference count 12, distance 16
    .byte $A4, $0F
    ; literal count 3; following payload excluded
    .byte $02
