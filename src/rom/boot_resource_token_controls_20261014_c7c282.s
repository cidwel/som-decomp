.setcpu "65816"
.segment "CODE"
.org $C282
control_c7c282:
    ; backreference count 5, distance 128
    .byte $88, $7F
    ; literal count 3; following payload excluded
    .byte $02
