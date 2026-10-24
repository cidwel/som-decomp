.setcpu "65816"
.segment "CODE"
.org $F246
control_dcf246:
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 13, distance 1
    .byte $8A, $00
    ; literal count 3; following payload excluded
    .byte $02
