.setcpu "65816"
.segment "CODE"
.org $EF5B
control_dcef5b:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 3; following payload excluded
    .byte $02
