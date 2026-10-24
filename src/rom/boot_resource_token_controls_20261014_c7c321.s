.setcpu "65816"
.segment "CODE"
.org $C321
control_c7c321:
    ; backreference count 3, distance 230
    .byte $80, $E5
    ; literal count 3; following payload excluded
    .byte $02
