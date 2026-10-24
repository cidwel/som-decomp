.setcpu "65816"
.segment "CODE"
.org $C2B3
control_c7c2b3:
    ; backreference count 4, distance 256
    .byte $84, $FF
    ; literal count 3; following payload excluded
    .byte $02
