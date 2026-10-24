.setcpu "65816"
.segment "CODE"
.org $C237
control_c7c237:
    ; backreference count 4, distance 16
    .byte $84, $0F
    ; literal count 3; following payload excluded
    .byte $02
