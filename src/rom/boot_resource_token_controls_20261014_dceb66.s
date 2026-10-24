.setcpu "65816"
.segment "CODE"
.org $EB66
control_dceb66:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 3; following payload excluded
    .byte $02
