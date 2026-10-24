.setcpu "65816"
.segment "CODE"
.org $EA32
control_dcea32:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; backreference count 3, distance 259
    .byte $81, $02
    ; literal count 13; following payload excluded
    .byte $0C
