.setcpu "65816"
.segment "CODE"
.org $EE7D
control_dcee7d:
    ; backreference count 3, distance 240
    .byte $80, $EF
    ; literal count 3; following payload excluded
    .byte $02
